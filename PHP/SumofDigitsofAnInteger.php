<?php
$num = 23498;
$sum = 0; $rem = 0;
for($i=0; $i<=strlen($num); $i++) {
    $rem = $num%10;
    $sum = $sum +$rem;
    $num=$num/10;;
}
echo "Sum of Digits 23498 is $sum";
?>