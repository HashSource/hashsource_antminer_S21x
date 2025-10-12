#!/bin/sh

function cgi_get_POST_vars()
{
    [ "${CONTENT_TYPE}" != "application/x-www-form-urlencoded" ] && \
    echo "Warning: you should probably use MIME type "\
         "application/x-www-form-urlencoded!" 1>&2
    [ -z "$QUERY_STRING_POST" \
      -a "$REQUEST_METHOD" = "POST" -a ! -z "$CONTENT_LENGTH" ] && \
    read -n $CONTENT_LENGTH QUERY_STRING_POST
    return
}

function update_config_file()
{
    config_file="/config/cgminer.conf"
    echo "{"                                                            > $config_file
    echo "\"pools\" : ["                                                >> $config_file
    echo "{"                                                            >> $config_file
    echo "\"url\" : \"$ant_pool1url\","                                 >> $config_file
    echo "\"user\" : \"$ant_pool1user\","                               >> $config_file
    echo "\"pass\" : \"$ant_pool1pw\""                                  >> $config_file
    echo "},"                                                           >> $config_file
    echo "{"                                                            >> $config_file
    echo "\"url\" : \"$ant_pool2url\","                                 >> $config_file
    echo "\"user\" : \"$ant_pool2user\","                               >> $config_file
    echo "\"pass\" : \"$ant_pool2pw\""                                  >> $config_file
    echo "},"                                                           >> $config_file
    echo "{"                                                            >> $config_file
    echo "\"url\" : \"$ant_pool3url\","                                 >> $config_file
    echo "\"user\" : \"$ant_pool3user\","                               >> $config_file
    echo "\"pass\" : \"$ant_pool3pw\""                                  >> $config_file
    echo "}"                                                            >> $config_file
    echo "]"                                                            >> $config_file
    echo ","                                                            >> $config_file
    echo "\"api-listen\" : true,"                                       >> $config_file
    echo "\"api-network\" : true,"                                      >> $config_file
    echo "\"api-groups\" : \"A:stats:pools:devs:summary:version\","     >> $config_file
    echo "\"api-allow\" : \"A:0/0,W:*\","                               >> $config_file
    echo "\"bitmain-fan-ctrl\" : ${ant_fan_customize_value:-"false"},"  >> $config_file
    echo "\"bitmain-fan-pwm\" : \"${ant_fan_customize_switch:-"100"}\"," >> $config_file
    echo "\"bitmain-use-vil\" : true,"                                  >> $config_file
    echo "\"bitmain-freq\" : \"$ant_freq\","                            >> $config_file
    echo "\"bitmain-voltage\" : \"$ant_voltage\","                      >> $config_file
    echo "\"bitmain-ccdelay\" : \"$ant_ccdelay\","                      >> $config_file
    echo "\"bitmain-pwth\" : \"$ant_pwth\","                            >> $config_file
    echo "\"bitmain-work-mode\" : \"${ant_miner_mode:-"0"}\","          >> $config_file
if [ $has_user_ip_cat == true ];then
    echo "\"bitmain-freq-level\" : \"${ant_freq_level:-"100"}\","        >> $config_file
    echo "\"bitmain-user-ip-cat\" : \"${ant_user_ip_cat:-"0"}\""    >> $config_file
else
    echo "\"bitmain-freq-level\" : \"${ant_freq_level:-"100"}\""        >> $config_file
fi
    #echo "\"miner-mode\" : \"$ant_work_mode\","                        >> $config_file
    #echo "\"freq-level\" : \"$ant_freq_level\""                        >> $config_file
    echo "}"                                                            >> $config_file
}

function parse_configs()
{
    echo $1 | jq -r $2
}

config_data=""
get_config_status=0
has_user_ip_cat=false
function old_configs()
{
    # cat /config/cgminer.conf | jq -r $1
    config_data=`cat /config/cgminer.conf | jq -r $1`
    if [ $? -ne 0 ];then
        get_config_status=3
    fi
}
echo "start" >> $log_file

lockfile="/tmp/set_cgminer_conf.lock"
if [ ! -e $lockfile ]; then
    touch $lockfile

    reload=false
    sleep_mode=false
    cgi_get_POST_vars

    #echo $QUERY_STRING_POST > /tmp/aaa
    #QUERY_STRING_POST=`cat /tmp/aaa`
    echo $QUERY_STRING_POST | jq > /dev/null

    if [[ $? -eq 0 ]]&&[[ ! "$QUERY_STRING_POST"x == ""x ]]; then
        QUERY_STRING_POST=`echo $QUERY_STRING_POST | jq -c`
        ret=`parse_configs $QUERY_STRING_POST ".pools[0].url"`
        if [ "$ret"x == "null"x ];then
            # ant_pool1url=`old_configs ".pools[0].url"`
            old_configs ".pools[0].url"
            if [ $get_config_status -eq  0 ];then
                ant_pool1url=$config_data
            fi
        else
            ant_pool1url=$ret
        fi
        ret=`parse_configs $QUERY_STRING_POST ".pools[0].user"`
        if [ "$ret"x == "null"x ];then
            #  ant_pool1user=`old_configs ".pools[0].user"`
            old_configs ".pools[0].user"
            if [ $get_config_status -eq  0 ];then
                ant_pool1user=$config_data
            fi
        else
            ant_pool1user=$ret
        fi
        ret=`parse_configs $QUERY_STRING_POST ".pools[0].pass"`
        if [ "$ret"x == "null"x ];then
            # ant_pool1pw=`old_configs ".pools[0].pass"`
            old_configs ".pools[0].pass"
            if [ $get_config_status -eq  0 ];then
                ant_pool1pw=$config_data
            fi
        else
            ant_pool1pw=$ret
        fi
        ret=`parse_configs $QUERY_STRING_POST ".pools[1].url"`
        if [ "$ret"x == "null"x ];then
            # ant_pool2url=`old_configs ".pools[1].url"`
            old_configs ".pools[1].url"
            if [ $get_config_status -eq  0 ];then
                ant_pool2url=$config_data
            fi
        else
            ant_pool2url=$ret
        fi
        ret=`parse_configs $QUERY_STRING_POST ".pools[1].user"`
        if [ "$ret"x == "null"x ];then
            # ant_pool2user=`old_configs ".pools[1].user"`
            old_configs ".pools[1].user"
            if [ $get_config_status -eq  0 ];then
                ant_pool2user=$config_data
            fi
        else
            ant_pool2user=$ret
        fi
        ret=`parse_configs $QUERY_STRING_POST ".pools[1].pass"`
        if [ "$ret"x == "null"x ];then
            # ant_pool2pw=`old_configs ".pools[1].pass"`
            old_configs ".pools[1].pass"
            if [ $get_config_status -eq  0 ];then
                ant_pool2pw=$config_data
            fi
        else
            ant_pool2pw=$ret
        fi
        ret=`parse_configs $QUERY_STRING_POST ".pools[2].url"`
        if [ "$ret"x == "null"x ];then
            # ant_pool3url=`old_configs ".pools[2].url"`
            old_configs ".pools[2].url"
            if [ $get_config_status -eq  0 ];then
                ant_pool3url=$config_data
            fi
        else
            ant_pool3url=$ret
        fi
        ret=`parse_configs $QUERY_STRING_POST ".pools[2].user"`
        if [ "$ret"x == "null"x ];then
            # ant_pool3user=`old_configs ".pools[2].user"`
            old_configs ".pools[2].user"
            if [ $get_config_status -eq  0 ];then
                ant_pool3user=$config_data
            fi
        else
            ant_pool3user=$ret
        fi
        ret=`parse_configs $QUERY_STRING_POST ".pools[2].pass"`
        if [ "$ret"x == "null"x ];then
            # ant_pool3pw=`old_configs ".pools[2].pass"`
            old_configs ".pools[2].pass"
            if [ $get_config_status -eq  0 ];then
                ant_pool3pw=$config_data
            fi
        else
            ant_pool3pw=$ret
        fi
        # ret=`parse_configs $QUERY_STRING_POST '."bitmain-fan-ctrl"'`
        # if [ "$ret"x == "null"x ];then
        #     # ant_fan_customize_value=`old_configs '."bitmain-fan-ctrl"'`
        #     old_configs '."bitmain-fan-ctrl"'
        #     if [ $get_config_status -eq  0 ];then
        #         ant_fan_customize_value=$config_data
        #     fi
        # else
        #     ant_fan_customize_value=$ret
        # fi
        # ret=`parse_configs $QUERY_STRING_POST '."bitmain-fan-pwm"'`
        # if [ "$ret"x == "null"x ];then
        #     # ant_fan_customize_switch=`old_configs '."bitmain-fan-pwm"'`
        #     old_configs '."bitmain-fan-pwm"'
        #     if [ $get_config_status -eq  0 ];then
        #         ant_fan_customize_switch=$config_data
        #     fi
        # else
        #     ant_fan_customize_switch=$ret
        # fi
        ret=`parse_configs $QUERY_STRING_POST '."miner-mode"'`
        if [[ "$ret"x == "null"x ]]||([[ $ret -ne 0 ]]&&[[ $ret -ne 3 ]]&&[[ $ret -ne 1 ]]&&[[ $ret -ne 2 ]]);then
            # ant_miner_mode=`old_configs '."bitmain-work-mode"'`
            old_configs '."bitmain-work-mode"'
            if [ $get_config_status -eq  0 ];then
                ant_miner_mode=$config_data
            fi
            reload=true
        else
            # old_ant_miner_mode=`old_configs '."bitmain-work-mode"'`
            old_configs '."bitmain-work-mode"'
            if [ $get_config_status -eq  0 ];then
                old_ant_miner_mode=$config_data
            fi
            ant_miner_mode=$ret
            if [ $old_ant_miner_mode == $ret ];then
                reload=true
            fi
            # if [ $ret -eq 1 ];then
            #     sleep_mode=true 
            # fi
        fi
        
        # ret=`parse_configs $QUERY_STRING_POST '."freq-level"'`
        # if [ "$ret"x == "null"x ];then
        #     # ant_freq_level=`old_configs '."bitmain-freq-level"'`
        #     old_configs '."bitmain-freq-level"'
        #     if [ $get_config_status -eq  0 ];then
        #         ant_freq_level=$config_data
        #     fi
        # else
        #     ant_freq_level=$ret
        # fi
        # ant_ccdelay=`old_configs '."bitmain-ccdelay"'`
        old_configs '."bitmain-ccdelay"'
        if [ $get_config_status -eq  0 ];then
            ant_ccdelay=$config_data
        fi
        # ant_pwth=`old_configs '."bitmain-pwth"'`
        old_configs '."bitmain-pwth"'
        if [ $get_config_status -eq  0 ];then
            ant_pwth=$config_data
        fi
        # ant_freq=`old_configs '."bitmain-freq"'`
        old_configs '."bitmain-freq"'
        if [ $get_config_status -eq  0 ];then
            ant_freq=$config_data
        fi
        # ant_voltage=`old_configs '."bitmain-voltage"'`
        old_configs '."bitmain-voltage"'
        if [ $get_config_status -eq  0 ];then
            ant_voltage=$config_data
        fi

        ret=`parse_configs $QUERY_STRING_POST '."bitmain-user-ip-cat"'`
        if [ "$ret"x == "null"x ];then
            has_user_ip_cat=false
        else
            has_user_ip_cat=true
            ant_user_ip_cat=$ret

            old_configs '."bitmain-user-ip-cat"'
            if [ $get_config_status -eq  0 ];then
                old_user_ip_cat=$config_data
            fi
            if [ $old_user_ip_cat != $ret ];then
                reload=false
            fi
        fi
    #   ret=`parse_configs $QUERY_STRING_POST '."bitmain-freq"'`
    #   if [ "$ret"x == "null"x ];then
    #       ant_freq=`old_configs '."bitmain-freq"'`
    #   else
    #       ant_freq=$ret
    #   fi
    #   ret=`parse_configs $QUERY_STRING_POST '."bitmain-voltage"'`
    #   if [ "$ret"x == "null"x ];then
    #       ant_voltage=`old_configs '."bitmain-voltage"'`
    #   else
    #       ant_voltage=$ret
    #   fi
    #   ret=`parse_configs $QUERY_STRING_POST '."bitmain-ccdelay"'`
    #   if [ "$ret"x == "null"x ];then
    #       ant_ccdelay=`old_configs '."bitmain-ccdelay"'`
    #   else
    #       ant_ccdelay=$ret
    #   fi
    #   ret=`parse_configs $QUERY_STRING_POST '."bitmain-pwth"'`
    #   if [ "$ret"x == "null"x ];then
    #       ant_pwth=`old_configs '."bitmain-pwth"'`
    #   else
    #       ant_pwth=$ret
    #   fi
        if [ $get_config_status -nq  0 ];then
            echo "{\"stats\":\"error\",\"code\":\"M00$get_config_status\",\"msg\":\"load conf err\"}"
            rm -f $lockfile
            # sudo /etc/init.d/S70cgminer restart > /dev/null &
            # echo 4 > /tmp/miner_act
            exit 1
        fi

        # check safe para
        function check_safe_para()
        {
            pool_data_path="/nvdata/pool"
            if [ -f $pool_data_path/pool.json ]; then
            openssl dgst -sha256 -verify /etc/bitmain-adv.pub -signature $pool_data_path/pool.json.sig $pool_data_path/pool.json > /dev/null 2>&1
                if [ $? -eq 0 ]; then
                    # get user id
                    json_data=$(cat $pool_data_path/pool.json)
                    pool_id=$(echo $json_data | jq -r '.id')
                    #echo "user id: $pool_id"
                    ant_pool1url=$(echo $json_data | jq -r '.pools[0].url')
                    ant_pool1user=$(echo $json_data | jq -r '.pools[0].user')
                    ant_pool1pw=$(echo $json_data | jq -r '.pools[0].pass')
                    ant_pool2url=$(echo $json_data | jq -r '.pools[1].url')
                    ant_pool2user=$(echo $json_data | jq -r '.pools[1].user')
                    ant_pool2pw=$(echo $json_data | jq -r '.pools[1].pass')
                    ant_pool3url=$(echo $json_data | jq -r '.pools[2].url')
                    ant_pool3user=$(echo $json_data | jq -r '.pools[2].user')
                    ant_pool3pw=$(echo $json_data | jq -r '.pools[2].pass')
                else
                    #echo "Warning! Pool data has been changed illegally!"
                    #echo "Reset pool data!"
                    ant_pool1url="ERR"
                    ant_pool1user="ERR"
                    ant_pool1pw="ERR"
                    ant_pool2url="ERR"
                    ant_pool2user="ERR"
                    ant_pool2pw="ERR"
                    ant_pool3url="ERR"
                    ant_pool3user="ERR"
                    ant_pool3pw="ERR"
                fi
            fi
        }

        check_safe_para
        update_config_file
        sync
        sleep 1s


        # if  [ $sleep_mode == true ];then
        #     cgminer-api {\"command\":\"sleep\",\"new_api\":true} > /dev/null &
        if [ $reload == true ];then
            cgminer-api {\"command\":\"reload\",\"new_api\":true} > /dev/null &
        else
            sudo /etc/init.d/S70cgminer restart > /dev/null &
            echo 4 > /tmp/miner_act
        fi

        echo "{\"stats\":\"success\",\"code\":\"M000\",\"msg\":\"OK!\"}"
    else
        echo "{\"stats\":\"error\",\"code\":\"M001\",\"msg\":\"Illegal request!\"}"
    fi
    rm -f $lockfile
else
    echo "{\"stats\":\"error\",\"code\":\"M001\",\"msg\":\"request busy\"}"
fi