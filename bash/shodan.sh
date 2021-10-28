#!/bin/bash

okegreen='\033[92m'
white='\e[1;37m'
red='\e[1;31m'
yellow='\e[1;33m'
myip=`shodan myip`

clear
echo -e "$red"
echo -e " _______  __   __  _______  ______   _______  __    _ "
echo -e "|       ||  | |  ||       ||      | |   _   ||  |  | |"
echo -e "|  _____||  |_|  ||   _   ||  _    ||  |_|  ||   |_| |"
echo -e "| |_____ |       ||  | |  || | |   ||       ||       |"
echo -e "|_____  ||       ||  |_|  || |_|   ||       ||  _    |"
echo -e " _____| ||   _   ||       ||       ||   _   || | |   |"
echo -e "|_______||__| |__||_______||______| |__| |__||_|  |__|"
echo -e "$white"
echo -e "               Your IP :$okegreen $myip"
echo -e "$white"
echo -e "$yellow  [1]$okegreen==----==$red[$white Scan IPs, Hostnames, ports"
echo -e "$yellow  [2]$okegreen==----==$red[$white Scan Specific Host"
echo -e "$white"
echo -e ""
read -p "  ~ Select : " act;
if [ $act == '1' ]
then
    read -p "  ~ Search : " query;
    shodan search --fields ip_str,port,hostnames $query
elif [ $act == '2' ]
then
    read -p "  ~ IP : " ip;
    shodan host $ip
else
    exit
fi
