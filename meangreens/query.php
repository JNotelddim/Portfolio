<?php
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
   
   //Get input from the HTML form
   $search=$_GET['search'];
   $table=$_GET['table'];
   
   if ($table == "Fruit"){
		$imgFolder = "fruits";
   } else {
	   $imgFolder = "veggies";
   }
   //Declare regex expression and replacement string
   $regex = '/select|drop|insert|create|update|delete|alter|grant|revoke|load|show|;/i';
   $replace = ' ';
   $search = preg_replace($regex, $replace, $search);
   $search = strtoupper(urldecode(basename(strip_tags($search))));
   
   //Only include WHERE when WHERE has user input
	if ($search == NULL){//Product_Id, Img, Item, Price, Provider_ID 
		$query = mysqli_query($LinkID, "SELECT v.Produce_Id, v.Img, v.Item, v.Price, p.Name, v.Quantity
		FROM $table v, Provider p WHERE p.Provider_ID = v.Provider_ID"); 
		echo mysqli_error($LinkID);
	}else{
		$query = mysqli_query($LinkID, "SELECT v.Produce_Id, v.Img, v.Item, v.Price, p.Name, v.Quantity
		FROM $table v, Provider p WHERE p.Provider_ID = v.Provider_ID AND (UPPER(v.Item) LIKE '%$search%' OR UPPER(p.Name) LIKE '%$search%' )");
		echo mysqli_error($LinkID);
	}
	
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
			print "<img src= \"$imgFolder/$x[1]\" alt=\"photo\">";
			print "<h3>$x[2]</h3>";
			print "<p>$$x[3]/unit</p>";
			print "<input type=\"number\" id=$x[0] name=$x[2] min=\"0\" style=\"width: 50px\">";
			print "<img src=\"cart3.jpg\" onclick=addToCart($x[0]) alt = \"cart\">";
			print "<p><a href=\"providers.html\">$x[4]</a></p>";
			print "</div>";
			$i++;
			if ($i%3 == 2){
					print"</div>";
			}
		}
   }
?>