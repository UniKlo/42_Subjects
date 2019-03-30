<?php
// reference: http://php.net/manual/en/features.http-auth.php
$user = $_SERVER['PHP_AUTH_USER'];
$pass = $_SERVER['PHP_AUTH_PW'];
if (($user == "zaz") && ($pass == "jaimelespetitsponeys")) {
	$img_name = "../img/42.png";
	$img = file_get_contents($img_name);
	$img_b64 = "data:image/png;base64," . base64_encode($img);
	echo "<html><body>Hello Zaz<br />\n<img src='" . $img_b64 . "'>\n</body></html>\n";
} else {
	header('WWW-Authenticate: Basic realm="Member area"');
	echo "<html><body>That area is accessible for members only</body></html>\n";
	exit;
}
?>