echo
echo
#dmesg
echo -e "\n"
echo "===========================================User Log==========================================="
logfiles=`ls -r /tmp/user_en.log*`
for logfile in $logfiles;
do
    cat $logfile | sed '/^$/d'
done