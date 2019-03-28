#!/usr/bin/env php
<?php 
while(1) 
{
    echo "Enter a number: ";
    $number = trim(fgets(STDIN));
    if (feof(STDIN)){
        echo "\n";
        exit();
    }
    if (is_numeric($number)) {
        $one = 1;
        $ret = $number & $one;     
        if($ret == 1) { 
            echo "The number ".$number." is odd\n";} 
        else{ 
            echo "The number ".$number." is even\n";}
    } 
    else {
        echo "'$number' is NOT numeric\n";
    }
}   
?> 