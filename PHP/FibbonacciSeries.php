<?php
$n = 8;
$first = 0;
$second = 1;
echo "Fibbonacci Series \n";
echo $first." ".$second." ";
for($i=2; $i<$n; $i++) {
    $third = $first + $second;
    echo $third.' ';
    $first = $second;
    $second = $third;
}
?>