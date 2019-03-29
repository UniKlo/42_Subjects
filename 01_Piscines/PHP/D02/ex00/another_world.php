#!/usr/bin/php
<?php
if ($argc == 2)
{
    $str = trim(preg_replace('/\t/', '', $argv[1]));
    $str = trim(preg_replace('/\s+/', ' ', $str));
	echo "$str\n";
}
?>