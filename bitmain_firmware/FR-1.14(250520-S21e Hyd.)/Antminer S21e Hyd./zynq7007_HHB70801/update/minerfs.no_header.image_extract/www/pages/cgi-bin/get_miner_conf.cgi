echo
echo
if [ ! -f /config/cgminer.conf ] ; then
    cp /config/cgminer.conf.factory /config/cgminer.conf
fi

hhb56=true
third_line=$(awk 'NR==3' /usr/bin/compile_time)
if [[ "$third_line" == "Release" ]]; then
    miner_type=`cat /usr/bin/compile_time  | sed -n '2p'`
    filter=`echo $miner_type | grep HHB56`
    if [[ -z $filter ]]; then
        hhb56=false
    fi

    if [[ "$miner_type" == "Antminer S19 XP Hyd." ]] || 
    [[ "$miner_type" == "Antminer S21 Hyd." ]] || 
    [[ "$miner_type" == "Antminer S21 XP Hyd." ]] || 
    [[ "$miner_type" == "Antminer S21e XP Hyd." ]] || 
    [[ "$miner_type" == "Antminer S21+ Hyd." ]] || 
    [[ "$miner_type" == "Antminer S21e Hyd." ]] || 
    [[ "$miner_type" == "Antminer U3S21EXPH" ]] || 
    [[ "$miner_type" == "Antminer S19 XP+ Hyd." ]] || 
    [[ "$hhb56" == "true" ]]; then
        jq '{pools,"bitmain-fan-ctrl","bitmain-fan-pwm", "bitmain-work-mode", "bitmain-hashrate-percent", "bitmain-user-ip-cat"}' /config/cgminer.conf
    else
        jq '{pools,"bitmain-fan-ctrl","bitmain-fan-pwm", "bitmain-work-mode", "bitmain-hashrate-percent"}' /config/cgminer.conf
    fi
else
    cat /config/cgminer.conf
fi