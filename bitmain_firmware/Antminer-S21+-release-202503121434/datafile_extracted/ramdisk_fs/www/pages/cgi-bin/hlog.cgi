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
find $log_path -type f | sort | xargs -I {} cat {}