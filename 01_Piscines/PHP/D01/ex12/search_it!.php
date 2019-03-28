#!/usr/bin/php
<?php
if ($argc > 2)
{
    for ($i = 2; $i < $argc; $i++)
    {
        $set = explode(":", $argv[$i]);
        if (count($set) != 2)
        {
            echo "Syntax Error\n";
            exit(0); 
        }
        if (strcmp($set[0], $argv[1]) == 0)
            $ret = $set[1];
    }
    if(isset($ret))
        echo $ret;
}
else
    echo "Incorrect Parameters\n";
?>
