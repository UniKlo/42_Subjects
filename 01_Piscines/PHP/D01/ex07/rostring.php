#!/usr/bin/env php
<?php
if ($argc > 1)
{
    $arr = preg_split('/\s+/', $argv[1]);
    for ($i = 1; $i < count($arr); $i++)
        echo $arr[$i] . ' ';
    echo $arr[0] . "\n";
}
?>