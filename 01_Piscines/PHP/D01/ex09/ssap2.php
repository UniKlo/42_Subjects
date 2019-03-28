#!/usr/bin/php
<?PHP
function sort_arr($arrin)
{
	unset($arrin[0]);
	$arr = array();
	foreach ($arrin as $v)
	{
		$split = array_filter(explode(" ", $v));
		foreach ($split as $v2)
			$arr[] = $v2;
	}
	sort($arr);
	return ($arr);
}

function new_sort($x, $y)
{
	$i = 0;
	$a = strtolower($x);
	$b = strtolower($y);
	$comp = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\"
		012345678!#$%&'()*+,-./:;<=>?@[\]^_`{|}~";
	while (($i < strlen($a) || ($i < strlen($b))))
	{
		$posa = strpos($comp, $a[$i]);
		$posb = strpos($comp, $b[$i]);
		if ($posa < $posb)
			return (-1);
		else if ($posa > $posb)
			return (1);
		else
			$i++;
	}
}

if ($argc > 1)
{
	$oldsort = sort_arr($argv);
	usort($oldsort, "new_sort");
	foreach ($oldsort as $v2)
		echo ("$v2\n");
/*
// case INsensitive
// alphabetical order first
// then numbers
// then finally all the other characters
 */
}
?>
