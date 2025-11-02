echo

hashrate_percent_min=100
hashrate_percent_max=100
hashrate_percent_support='true'

if [ -f /etc/topol.json ]
then
    hashrate_percent_support=`cat /etc/topol.json | jq -r .strategy.freq_level_mode`
    if [ x$hashrate_percent_support != x"true" ] && [ x$hashrate_percent_support != x"false" ]; then
        hashrate_percent_support='false'
    fi

    hashrate_percent_min=`cat /etc/topol.json | jq -r .strategy.freq_level_min`
    if [ $hashrate_percent_min == "null" ]; then
        hashrate_percent_support='false'
    fi
else
    hashrate_percent_support='false'
fi

echo "{\"hashrate_percent_support\": $hashrate_percent_support, \"hashrate_percent_min\": $hashrate_percent_min, \"hashrate_percent_max\": $hashrate_percent_max}"
