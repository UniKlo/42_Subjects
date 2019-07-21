#!/usr/bin/env php
<?php
if ($argc !== 2)
	exit();
$input = get_input(fopen("php://stdin", "r"));
$line = $input["line"];
$user = $input["user"];
ksort($user);
switch ($argv[1]) {
	case "average":
		$total = 0;
		$count = 0;
		foreach ($line as $val) {
			$noteur = $val[2];
			$note = $val[1];
			if ($noteur !== "moulinette" && $note !== "") {
				$total += $note;
				$count++;
			}
		}
		echo ($total / $count) . "\n";
		break;
	case "average_user":
	case "moulinette_variance":
		foreach ($line as $val) {
			$person = $val[0];
			$note = $val[1];
			$noteur = $val[2];
			if ($note !== "" && $noteur !== "moulinette") {
				$user[$person]["total"] += $note;
				$user[$person]["count"] += 1;
			} else if ($noteur === "moulinette") {
				$user[$person]["mul"] = $note;
			}
		}
		if ($argv[1] === "average_user") {
			foreach ($user as $key => $val) {
				echo $key . ":" . ($val["total"] / $val["count"]) . "\n";
			}
		} else if ($argv[1] === "moulinette_variance") {
			foreach ($user as $key => $val) {
				echo $key . ":" . (($val["total"] / $val["count"]) - $val["mul"]) . "\n";
			}
		}
		break;
}
function get_input($stdin) {
	$ret = [
		"line" => [],
		"user" => []
	];
	fgets($stdin);
	while ($stdin && !feof($stdin)) {
		$arr_input_r = explode(";", fgets($stdin));
		if (sizeof($arr_input_r) === 4) {
			$ret["line"][] = $arr_input_r;
			if (!array_key_exists($arr_input_r[0], $ret["user"])) {
				$ret["user"][$arr_input_r[0]] = [];
				$ret["user"][$arr_input_r[0]]["total"] = 0;
				$ret["user"][$arr_input_r[0]]["count"] = 0;
				$ret["user"][$arr_input_r[0]]["mul"] = 0;
			}
		}
	}
	return $ret;
}
?>