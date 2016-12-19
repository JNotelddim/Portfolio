<?php
session_start();
if(isset($_POST['id']){
	if(isset($_SESSION['cart'])){
		$_SESSION['test'] = "monkies";
		echo "test";
		if ($_POST['id'] == "ALL"){
			$cart = unserialize($_SESSION['cart']);
			foreach ($cart as $item){
				unset($item);
			}
			$_SESSION['cart'] = serialize($cart);
		} else {
			$cart = unserialize($_SESSION['cart']);
			unset($cart[$_POST['id']]);
			$_SESSION['cart'] = serialize($cart);
		}
	}
}
?>
