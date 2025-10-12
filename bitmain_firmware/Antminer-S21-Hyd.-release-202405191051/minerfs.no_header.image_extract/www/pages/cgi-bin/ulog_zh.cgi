echo
echo
#dmesg
echo -e "\n"
echo "===========================================用户日志==========================================="
logfiles=`ls -r /tmp/user_zh.log*`
for logfile in $logfiles;
do
    cat $logfile | sed '/^$/d'
done