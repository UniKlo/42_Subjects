<!DOCTYPE html>
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
		<br>
<?php
if ($_POST["logout"])
{
    $name = $_SESSION["logged_in_user"];
    if ($name)
    {
        $_SESSION["logged_in_user"] = "";
        
        echo "<h1>".$name." is logged out</h1><br \>";
    }
    else
    {
        echo "<h1>Please sign in first</h1?<br />";
    }
}
?>
      <h1>ADMIN</h1>
      <br><h1>
      <a href="admin_users_page.php">Edit Users</a>
      <br>
      <a href="admin_items_page.php">Edit Items</a>
      <br>
      <a href="admin_orders_page.php">Edit Orders</a>
      <br></h1>
      <footer>
    <p>Made by <b>Hiren</b>  & <b>Khloe</b></p>
</footer>
</body>
</html>