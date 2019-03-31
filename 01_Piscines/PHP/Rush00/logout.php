<?php
session_start();
$name = $_SESSION["logged_in_user"];
$_SESSION["logged_in_user"] = "";
echo $name. " is logged out";
?>