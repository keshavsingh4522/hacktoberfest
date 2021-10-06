<?php
$number  = 5;
$power = 3;
$result = 1;
$p=$power;
while($power>=1)
{
    $result=$result*$number;
    $power--;
}
echo "$number raises the power $p = $result";
?>