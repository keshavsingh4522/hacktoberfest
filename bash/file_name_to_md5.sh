#! /bin/bash

#Change every file name in directory to first 8 characters of that file's MD5 sum:

md5sum * |
    while read -r sum filename; do
        sum=$(echo $sum | cut -c 1-8)
        mv "$filename" "$sum"
    done
