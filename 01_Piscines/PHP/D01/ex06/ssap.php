#!/usr/bin/env php
<?php
unset($argv[0]);
$arr = array();
foreach ($argv as $v)
{
    $arr = array_filter(explode(" ", $v));
    foreach ($arr as $v2)
        $arr2[] = $v2;
}
sort($arr2);
foreach ($arr2 as $v)
    echo $v."\n";

?>