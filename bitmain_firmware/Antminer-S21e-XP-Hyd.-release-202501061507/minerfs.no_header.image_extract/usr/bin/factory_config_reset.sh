#!/bin/sh

echo "starting recovery factoary"
/etc/init.d/S50dropbear stop
killall -s 9 S71monitorcg
sleep 3
/etc/init.d/S70cgminer stop

cd /config/
rm_files=`ls /config/ | grep -wv mac | grep -wv sn`
rm -rf $rm_files

sync

echo "recovery factory complete, rebooting"
sleep 90
reboot -f
