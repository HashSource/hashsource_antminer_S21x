echo
echo
#dmesg
echo -e "\n"
echo "===========================================Miner log==========================================="
ant_fmtype=`sed -n 3p /usr/bin/compile_time`
if [ "$ant_fmtype"x == "Release"x ]; then
    log_path="/nvdata/log/user"
else
    log_path="/nvdata/log/debug"
fi

file_num=$((`cat /proc/uptime | cut -d" " -f1 | cut -d"." -f1`/86400 + 2))
last_line=$(grep -Hno "commit version:" `find $log_path -type f | sort | tail -n $file_num` | tail -n 1)
file_name=`echo $last_line | cut -d":" -f1`
line_num=`echo $last_line | cut -d":" -f2`

display="off"
find $log_path -type f | sort | while read file; do
    if [ "$display"x == "on"x ]; then
        cat $file
    fi
	if [ "$file"x == "$file_name"x ]; then
        tail -n +${line_num} $file
        display="on"
    fi
done