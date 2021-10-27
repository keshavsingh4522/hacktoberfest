<?php
function test()
{
    static $a = 0;
    echo $a;echo "<br>";
    $a++;
}
test();
test();
test();
?>