<?php
session_start();
require_once("logout.php");

if ($_SESSION["logged_in_user"])
{
    echo "Welcome" . $_SESSION["logged_in_user"] . "\n";
    echo "<html><body><a href='./'>To view your cart</a></body></html>\n";;
    echo "<html><body><a href='./pw_modify.html'>To change your password</a></body></html>\n";
    echo "<html><body><form method='get'>
    <input type='hidden' name='logout.php'>
    <input type='submit'>
</form></body></html>\n";

}
else
    echo "Not login ERROR\n";
?>