#!/bin/bash
clear

echo
echo "c0d3r zip password-cracker v1.0"
echo -n "Zip File Name: "
read fname

# check for no response  
if [ -z $fname ];then
     echo
     echo "You did not enter a zip name."
     exit
fi

echo
echo -n "Dictionary File Name(passowords, wordlists)."
read lname

# check for no response  
if [ -z $lname ];then
     echo
     echo "You did not enter a Dictionary File Name(passowords, wordlists)"
     exit
fi

echo
echo "You can see the result on Terminal. Starting Cacking Password of $fname. "
echo
read -p "Press <enter> to continue."
python unzip.py -f %fname -d %lname
