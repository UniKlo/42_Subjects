<?php
if ($_POST["login"] && $_POST["passwd"] && $_POST["submit"] === "OK") 
{
	$dir_path = "../htdocs/private";
	$fil_path = $dir_path . "/passwd";
	if (!file_exists($dir_path))
	{
		mkdir("../htdocs");
		mkdir($dir_path);
	}
	if (!file_exists($fil_path))
		file_put_contents($fil_path, null);
	$account = unserialize(file_get_contents($fil_path));
	if ($account)
	{
		$has_user = false;
		foreach ($account as $key => $val) {
			if ($val["login"] === $_POST["login"])
				$has_user = true;
		}
	}
	if ($has_user)
		echo "ERROR\n";		
	else 
	{
		$user["login"] = $_POST["login"];
		$user["passwd"] = hash("whirlpool", $_POST["passwd"]);
		$account[] = $user;
		file_put_contents($fil_path, serialize($account));
		echo "OK\n";
	}
} 
else
	echo "ERROR\n";
?>