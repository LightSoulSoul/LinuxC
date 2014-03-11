#!/bin/bash
#4.4.sh

echo "welcome to use AUTOUSB"
echo "do you want load usb[y/n]?"
read ANSWER

if [ $ANSWER = "Y" -o $ANSWER = "y" ]
	then mount -t vfat /dev/sda1 /mnt/usb
	echo "do you want copy
