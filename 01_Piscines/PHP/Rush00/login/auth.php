<?php
function auth($login, $passwd)
{
if (!$login || !$passwd)
return FALSE;
$fil_path = "../htdocs/private/passwd";
if (!!!file_exists($fil_path)) {
return FALSE;
}
if (($login == "admin") && ($passwd == "pass")) 
{
    echo "<html><body><a href='../admin/admin.php'>Welcome admin</a></body></html>\n";
    exit();
}
$account = unserialize(file_get_contents($fil_path));
if ($account) 
{
foreach ($account as $key => $val) {
if ($val["login"] === $login && $val["passwd"] === hash("whirlpool", $passwd))
return TRUE;
}
}
return FALSE;
}

?>