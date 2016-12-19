<?php
session_start();
if(!isset($_SESSION['cart'])){
	$cart=array();
	$cart[$_POST['id']] = intval($_POST['quantity']);
	$_SESSION['cart'] = serialize($cart);
} else {
	$cart = unserialize($_SESSION['cart']);
	if (isset($_POST['id']) and isset($_POST['quantity'])){
		if(isset($cart[$_POST['id']])){
			$cart[$_POST['id']] += intval($_POST['quantity']);
		} else {
			$cart[$_POST['id']] = intval($_POST['quantity']);
		}
		$_SESSION['cart'] = serialize($cart);
	}
}
?>