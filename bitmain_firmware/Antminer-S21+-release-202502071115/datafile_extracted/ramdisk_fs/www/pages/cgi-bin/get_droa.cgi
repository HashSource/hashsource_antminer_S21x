if [ -f /nvdata/log/droa/droa*.log ]
then
    echo "==============================Bitmain Miner DROA log========================================="
    droalog=`cat /nvdata/log/droa/droa*.log`
    echo "$droalog"
else
    echo "None"
fi

