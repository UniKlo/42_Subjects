<?php
require_once("auth.php");
require_once("create.php");
session_start();
// to check exiting user
if ($_POST["submit"])
{
	if ($_POST["login"] &&
		$_POST["passwd"] &&
		auth($_POST["login"], $_POST["passwd"])) 
	{
		$_SESSION["logged_in_user"] = $_POST["login"];
		echo "LOGIN SUCCESSFULLY\n";
		echo "<html><body><a href='../landing.html'>TO SHOP</a></body></html>\n";
	} 
	else 
	{
		$_SESSION["logged_in_user"] = "";
		echo $_POST["login"] . " does not exist.\n";
		echo "<html><body><a href='./login.html'>Pls Register</a></body></html>\n";
	}
}
//to register
if ($_POST["login"] &&
	$_POST["passwd"] &&
	$_POST["register"])
	create($_POST["login"], $_POST["passwd"]);
?>
