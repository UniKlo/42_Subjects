<?php
function cookie_crisp($c_func, $c_name)
{
	switch ($c_func)
	{
		case 'set':
			if ($c_name) setcookie($c_name, $c_name, time() + 3600); break;
			//vaild in an hour
		case 'get': 
			if ($_COOKIE[$c_name]) echo ($_COOKIE[$c_name] . "\n"); break;
		case 'del':
			setcookie($c_name, "", time() - 3600); break;
			//vailded an hour ago
		case 'all': print_r($_COOKIE); break;
	}
}
?>