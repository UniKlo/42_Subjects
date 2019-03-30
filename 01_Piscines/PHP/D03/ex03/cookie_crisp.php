<?php
if ($_GET['action'] && $_GET['name'])
{
	$c_func = $_GET['action'];
	$c_name = $_GET['name'];
	switch ($c_func)
	{
		case 'set':
			if ($_GET['value']) setcookie($c_name, $_GET['value'], time() + 3600); break;
			//vaild in an hour
		case 'get': 
			if ($_COOKIE[$c_name]) echo ($_COOKIE[$c_name] . "\n"); break;
		case 'del':
			setcookie($c_name, "", time() - 3600); break;
			//vaild in an hour ago
		case 'all': print_r($_COOKIE); break;
	}
}
?>