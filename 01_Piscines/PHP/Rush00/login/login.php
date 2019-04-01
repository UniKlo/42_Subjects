<?php
session_start();
require_once("auth.php");
require_once("create.php");
// to check exiting user
echo"<!DOCTYPE html>
<html lang='en'>
	<head>
		<meta charset='UTF-8' />
		<title>Dog Wash</title>
		<link href='../css/header.css' rel='stylesheet' type='text/css' />
		<link href='../css/styles.css' rel='stylesheet' type='text/css' />
	</head>
	<body>
		<ul>
			<li><a href='../index.php'><img src='https://github.com/hirenpateldotnex/rush00_src/blob/master/logo.png?raw=true'></a></li>
			<li><a href='../shop/shop.php'>SHOP</a></li>
		</ul>
		<br>";
if ($_POST["submit"])
{
	if ($_POST["login"] &&
		$_POST["passwd"] &&
		auth($_POST["login"], $_POST["passwd"])) 
	{
		$_SESSION["logged_in_user"] = $_POST["login"];
		echo"<section class='container'>
		<a href='../shop/shop.php'>
		<img style='width: 100%;height: auto;max-width: 100%;' src='https://github.com/hirenpateldotnex/rush00_src/blob/master/hero.png?raw=true'>
		</a>
  		</section>";
	} 
	else 
	{
		$_SESSION["logged_in_user"] = "";
		echo "<h1>User : ".$_POST["login"] . " does not exist</h1>";
		echo "<h1><a href='./login.html'>Pls Register</a></h1>\n";
	}
}
//to register
if ($_POST["login"] &&
	$_POST["passwd"] &&
	$_POST["register"])
	create($_POST["login"], $_POST["passwd"]);
?>




<footer>
    <p>Made by <b>Hiren</b>  & <b>Khloe</b></p>
</footer>
</body>
</html>