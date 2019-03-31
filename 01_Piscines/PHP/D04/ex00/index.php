<?php
session_start();
if ($_GET["submit"] === "OK") {
  if ($_SESSION["ligin"] !== "")
    $_SESSION["login"] = $_GET["login"];
  if ($_SESSION["passwd"] !== "")
    $_SESSION["passwd"] = $_GET["passwd"];
}
?>
<html>
<head>
<title>ex00</title>
</head>
<body>
	<form name="index.php" action="index.php" method="GET">
	Username: <input type="text" name="login" value="<?php echo $_SESSION['login']; ?>"/>
	<br />
	Password: <input type="password" name="passwd" value="<?php echo $_SESSION['passwd']; ?>" />
	<br />
  <input type="submit" name="submit" value="OK" />
	</form>
</body></html>