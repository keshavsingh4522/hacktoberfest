<?php
$num1 = 10;
$num2 = 15;
echo "Number 1 = $num1 <br>";
echo "Number 2 = $num2 <br>";
while($num2 != 0) {
    $t = $num1 % $num2;
    $num1 = $num2;
    $num2 = $t;
}
echo "<br>The Greater Common Divisor is $num1";
?>