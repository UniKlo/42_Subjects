<?php
if ($_POST["login"] && $_POST["oldpw"] && $_POST["newpw"] && $_POST["submit"] === "OK") 
{
	$dir_path = "./htdocs/private";
    $fil_path = $dir_path."/passwd";
    $account = unserialize(file_get_contents($fil_path));
    if ($account) 
    {
		$save = false;
        foreach ($account as $key => $val) 
        {
            if ($val["login"] === $_POST["login"] && 
                $val["passwd"] === hash("whirlpool", $_POST["oldpw"])) 
            {
				$save = true;
				$account[$key]["passwd"] = hash("whirlpool", $_POST["newpw"]);
				file_put_contents($fil_path, serialize($account));
                echo "Password is set.\n";
                echo "<html><body><a href='./landing.html'>Go to homepage</a></body></html>\n";
                break;
			}
		}
		if (!$save)
            echo "ERROR\n";
    }
    else
        echo "ERROR: account does not exist\n";
}
else 
    echo "ERROR: pls fill up the form\n";
?>