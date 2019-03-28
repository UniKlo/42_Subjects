#!/usr/bin/php
<?php
if ($argc == 2)
{
    preg_match('/\s*([+-]\d+)\s*([\+\-\*\/\%])\s*([+-]\d+)\s*/', $argv[1], $arr);
    if (count($arr) != 4 ||is_nan($arr[1]) || is_nan($arr[3]))
    {
        echo "Incorrect Input\n";
        exit(0);
    }
    $a = $arr[1];
    $b = $arr[3];
    $op = $arr[2];
    switch ($op)
	{
    case '+':
        echo ($a + $b . "\n");
        break;
    case '-':
        echo ($a - $b . "\n");
        break;
    case '*':
        echo ($a * $b . "\n");
        break;
    case '/':
        echo ($a / $b . "\n");
        break;
    case '%':
        echo ($a % $b . "\n");
        break;
    }
}
else 
    echo "Incorrect Parameters\n";

?>