<?php
session_start();
$cart = unserialize($_SESSION['cart']);

// Connect to the MySQL server.
	//require ("../include.php");   

$LinkID = mysqli_connect("localhost", "c199grp08", "#TEC257");	
    // Die if no connect
    if (!$LinkID) {
       die('Could not connect: ' . mysqli_error($LinkID));
    }
	
   // Choose the DB and run a query.
   mysqli_select_db($LinkID, "C199grp08DB");
   echo mysqli_error($LinkID);
   print_r($_SESSION);
   print_r($cart);
   $test = "";
	if(!empty($cart)){
		
		$products = "fd.Produce_Id IN (";
		foreach ($cart as $id => $quantity){
			$test .= $id.",";
			$products .= $id.",";
		}
		$products .= ",0)";
		$test .= "0";
		//$products = "fd.Produce_Id = 'NONE')";
	} else {
		$products = "0";
		$test = "0";
	}
   //Declare regex expression and replacement string
   $regex = '/select|drop|insert|create|update|delete|alter|grant|revoke|load|show|;/i';
   $replace = ' ';
   $products = preg_replace($regex, $replace, $products);
   $products = strtoupper(urldecode(basename(strip_tags($products))));
   
   // build the query:
   //echo "<br/>"; print($test);
	$query = mysqli_query($LinkID, "SELECT v.Produce_Id, v.Img, v.Item, v.Price, p.Name, v.Quantity FROM Vegetable v, Provider p WHERE p.Provider_ID=v.Provider_ID AND v.Produce_Id IN ($test)");
	$query2 = mysqli_query($LinkID, "SELECT f.Produce_Id, f.Img, f.Item, f.Price, p.Name, f.Quantity FROM Fruit f, Provider p WHERE p.Provider_ID=f.Provider_ID AND f.Produce_Id IN ($test)");
	echo mysqli_error($LinkID);
	
	// Display the results.
   if ($query) {
	  $i = 0;
    // Print the rest of the rows.	
		while ($x=mysqli_fetch_row($query)) {
			if ($i%3 == 0 && $i != 0){
					print"<div id=\"row\">";
			}
			
			echo mysqli_error($LinkID);//echo mysql_errno($LinkID).":".mysql_error($LinkID);
			//print_r ($x);
			print "<div class='col-sm-3' id=\"catalogItem";
			switch ($i%3){
				case 0:
					print "L\">";
					break;
				case 1:
					print "C\">";
					break;
				case 2:
					print "R\">";
					break;
			}
			$id = $x[0];
			print "<img src= \"veggies/$x[1]\" alt=\"$x[2]\">";
			print "<h3>$x[2]</h3>";
			print "<p>$$x[3] * $cart[$id] units</p>";
			/*print "<input type=\"number\" id=$x[0] name=$x[2] min=\"0\" style=\"width: 50px\">";
			print "<img src=\"cart3.jpg\" onclick=addToCart($x[0]) alt = \"cart\">";*/
			print "<p><a href=\"providers.html\">$x[4]</a></p>";
			print "<input type='Button' value='Remove from Cart' onclick='removeItem($x[0])'>";
			print "</div>";
			$i++;
			if ($i%3 == 2){
				
					print"<div id=\"row\">";
			}
		}
		while ($x=mysqli_fetch_row($query2)) {
			if ($i%3 == 0 && $i != 0){
					print"<div id=\"row\">";
			}
			
			echo mysqli_error($LinkID);//echo mysql_errno($LinkID).":".mysql_error($LinkID);
			//print_r ($x);
			print "<div class='col-sm-3' id=\"catalogItem";
			switch ($i%3){
				case 0:
					print "L\">";
					break;
				case 1:
					print "C\">";
					break;
				case 2:
					print "R\">";
					break;
			}
			$id = $x[0];
			print "<img src= \"fruits/$x[1]\" alt=\"$x[2]\">";
			print "<h3>$x[2]</h3>";
			print "<p id=$x[0] name=$x[2]>$$x[3] * $cart[$id] units</p>";
			/*print "<input type=\"number\" id=$x[0] name=$x[2] min=\"0\" style=\"width: 50px\">";
			print "<img src=\"cart3.jpg\" onclick=addToCart($x[0]) alt = \"cart\">";*/
			print "<p><a href=\"providers.html\">$x[4]</a></p>";
			print "<input type='Button'  value='Remove from Cart' onclick='removeItem($x[0])'>";
			print "</div>";
			$i++;
			if ($i%3 == 2){
					print"</div>"; //added / to div
			}
		}
   }
?>