#!/usr/bin/php
<?php

date_default_timezone_set("Europe/Paris");
function ft_exit($str)
{
	echo "$str";
	exit();
}

function check_day_of_week($str)
{
	switch (strtolower($str))
	{
		case "lundi": return ("Mon");
		case "mardi": return ("Tue");
		case "mercredi": return ("Wed");
		case "jeudi": return ("Thur");
		case "vendredi": return ("Fri");
		case "samedi": return ("Sat");
		case "dimanche": return ("Sun");
	}
	ft_exit("Wrong Format");
}

function check_month($str)
{
	switch (strtolower($str))
	{
		case "janvier": return ("01");
		case "fevrier": return ("02");
		case "mars": return ("03");
		case "avril": return ("04");
		case "mai": return ("05");
		case "juin": return ("06");
		case "juillet": return ("07");
		case "aout": return ("08");
		case "septembre": return ("09");
		case "octobre": return ("10");
		case "novembre": return ("11");
		case "decembre": return ("12");
	}
	ft_exit("Wrong Format");
}


$arr = array_filter(explode(" ", $argv[1]));
if ($argc != 2 || count($arr) != 5)
    ft_exit("Wrong Format");

check_day_of_week($arr[0]);
$day = $arr[1];
$month = check_month($arr[2]);
$year = $arr[3];
$time = $arr[4];

$date = array($month, $day, $year);
$date = join('/', $date);
$date = array($date, $time);
$ret= strtotime(join(' ', $date));

echo "$ret\n";
?>