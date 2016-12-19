<?php 
$cookieLife=1200;
session_start();
setcookie(session_name(),session_id(),time()+$cookieLife);
ini_set("session.gc_maxlifetime", "18000");
//set the session variable's value
//$_SESSION['cart'] = "";
if (!isset($_SESSION['cart'])){
	$_SESSION['cart'] = "";
}
?>
<!DOCTYPE html>
<html lang="en">
	<head>
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.2/jquery.min.js"></script>
		
		<script type="text/javascript">
		function queryDB() {
		
		  var xmlHttp;
		  try {
			// Firefox, Opera 8.0+, Safari
			xmlHttp=new XMLHttpRequest();
		  } catch (e) {
		  // Internet Explorer of several flavors
			try {
			  xmlHttp=new ActiveXObject("Msxml2.XMLHTTP");
			} catch (e) {
			  try {
				xmlHttp=new ActiveXObject("Microsoft.XMLHTTP");
			  } catch (e) {
			  // or nothing works.  Punt.
				alert("Your browser does not support AJAX!");
				return false;
			  }
			}
		  }xmlHttp.onreadystatechange = function() {
					if (xmlHttp.readyState == 4 && xmlHttp.status == 200) {					
						document.getElementById("txtHint").innerHTML = xmlHttp.responseText;
					}
				};
				var searchVal = document.getElementById("search").name;
				var search = document.getElementById("search").value;
				var table = "table";
				var tableVal = "Fruit";
				xmlHttp.open("GET","query.php?"+searchVal+"="+search+"&"+table+"="+tableVal,true);//+selectVal+"="+select+"&"+ffromVal+"="+ffrom+"&"+,true);
				xmlHttp.send();
				
		}
		
		function goTo(){
			window.location.href="veg.php";
		}
		function goToCart(){
			window.location.href="cart.php";
		}
		function addToCart(x){
			var itemQuantity = document.getElementById(x).value;
			var itemName = document.getElementById(x).name;
			var itemId = x;
			alert(itemQuantity +" "+ itemName + " added to cart.");
			$.post('addToCart.php', {id: itemId, quantity: itemQuantity});
		}
		</script>
		<meta charset="utf-8">
		<meta http-equiv="X-UA-Compatible" content="IE=edge"/>
		<!--meta name="viewport" content="width=device-width, inital-scale=1"-->
		<meta name="description" content="">
		<meta name="author" content="Jared Middleton Josh Wendland Chris Hodgson Connor Quinn">
		
		<title>Shopping For Fruit</title>
		<link href="bootstrap/css/bootstrap.min.css" rel="stylesheet">
		<link href="catalog.css" rel="stylesheet">

	
		<style type="text/css"> 
		.container-fluid { 
				padding-top: 20px; 
				padding-bottom: 20px;}
		</style>
	</head>
	
	<body onload="queryDB()">
	<nav class="navbar navbar-inverse navbar-fixed-top">
		<!-- color in bootstrap.min.css @ navbar-inverse-->
		<div class="container">
			<div class="navbar-header">
				<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
					<span class="icon-bar"></span>
					<span class="icon-bar"></span>
					<span class="icon-bar"></span>
				</button>
				<a class="navbar-brand" href="index.html"> Home </a>
			</div>
			
			<div id="navbar" class="collapse navbar-collapse">
				<ul class="nav navbar-nav">
				
					<li><a href="shop.html">Shop</a></li>
					<li><a href="providers.html">Providers</a></li>
					<li><a href="about.html">About Us</a></li>

				</ul>
			</div>
		</div>
	</nav>
	<div class="container">
		<div class="starter-template">
			<div class="container-fluid bg-1 text-center" id="header">
				
				<br/><br/><br/>
				<h1>Mean Greens</h1>
			</div>
			<div class="container-fluid bg-1 text-center">
				<div class="col-sm-3"></div>
				<div class="col-sm-3"><button class="btn" onclick="goTo()"value="Vegetables" action="veg.html" >Vegetables</button></div>
				<div class="col-sm-3"><button class="btn" value="Fruit" action="fruit.html" disabled>Fruit</button><!--<p><a href="fruit.html">Fruit</a></p--></div>
			</div>
			<div class="container-fluid bg-1 text-center">
				<div class="col-sm-3"></div>
				<form>
					<input type="text" name="search" id="search"/>
					<input type="Button" value="Search" onclick="queryDB()">
					<br/>
					<input type="Button" class="cart" style="float: right;" value="View Cart" onclick="goToCart()">
				</form>
			</div>
			<!--WHERE <textarea style="width:250px; height: 20px" name="search" id="search"  maxlength="200" value="" ></textarea-->
                        
			<!--  -->
			<div id="txtHint">
			</div>
		</div>
	</div>
	
	<footer class="container-fluid bg-4 text-center">
	&copy;  Mean Greens 2016; 555-555-5523; 2001 Privateers Rd, Victoria, BC
	</footer>
	</body>
</html>
