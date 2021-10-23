<?php
	
function get_ip(){if (isset($_SERVER['HTTP_CF_CONNECTING_IP']))return $_SERVER['HTTP_CF_CONNECTING_IP'];return $_SERVER['REMOTE_ADDR'];}
echo $ip=get_ip();
?>