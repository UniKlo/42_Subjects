<?php
	session_start();
	// require_once("logout.php");
	$user = $_SESSION["logged_in_user"];
	?>
<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="UTF-8" />
		<title>Dog WASH</title>
		<link href="css/header.css" rel="stylesheet" type="text/css" />
		<link href="css/styles.css" rel="stylesheet" type="text/css" />
	</head>
	<body>
		<ul>
			<li><a href="index.php"><img src="https://github.com/hirenpateldotnex/rush00_src/blob/master/logo.png?raw=true"></a></li>
			<li><a href="shop/shop.php">SHOP</a></li>
			<?php
				if ($_SESSION["logged_in_user"])
				{
					echo "<li><a href='login/pw_modify.html'>". $user ."'s Account</a></li>";
				}
				else
				{
					echo "<li><a href='login/login.html'>SIGN IN</a></li>";
				}
				?>
		</ul>
		<br>
		<a href='shop/shop.php'>
		<img style='width: 100%;height: auto;max-width: 100%;' src='https://github.com/hirenpateldotnex/rush00_src/blob/master/hero.png?raw=true'>
		</a>
		<footer>
			<p>Made by <b>Hiren</b>  & <b>Khloe</b></p>
		</footer>
	</body>
</html>