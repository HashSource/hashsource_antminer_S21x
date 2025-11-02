#!/bin/sh -e

function cgi_get_POST_vars() {
    [ "${CONTENT_TYPE}" != "application/x-www-form-urlencoded" ] &&
        echo "Warning: you should probably use MIME type " \
            "application/x-www-form-urlencoded!" 1>&2
    [ -z "$QUERY_STRING_POST" \
        -a "$REQUEST_METHOD" = "POST" -a ! -z "$CONTENT_LENGTH" ] &&
        read -n $CONTENT_LENGTH QUERY_STRING_POST
    return
}

cgi_get_POST_vars

log_path="/nvdata/log/debug"

log_file_earliest="/2221-01/01"
log_file_lastest="/1960-01/01"
log_file_list=""

for log_dir in $(echo $QUERY_STRING_POST | jq -r ".[]"); do
    file_name=${log_dir#/}
    log_file_list=${log_file_list}" "${file_name/\//-}".log"
    file=$(echo $log_path | cut -d"/" -f4)"_"${file_name/\//-}".log"
    if [ ! -f "$log_path""/""$file" ]; then
        echo "{\"stats\":\"error\",\"code\":\"L001\",\"msg\":\"Log file not found!\"}"
        return 0
    fi

    earliest=${log_file_earliest//\//}
    earliest_num=${earliest//-/}
    lastest=${log_file_lastest//\//}
    lastest_num=${lastest//-/}

    log_time=${log_dir//\//}
    log_time_num=${log_time//-/}

    if [ $log_time_num -lt $earliest_num ]; then
        log_file_earliest=$log_dir
    fi

    if [ $log_time_num -gt $lastest_num ]; then
        log_file_lastest=$log_dir
    fi
done

if [ "$log_file_earliest"x == "/2221-01/01"x ]; then
    echo "{\"stats\":\"error\",\"code\":\"L002\",\"msg\":\"Null request data!\"}"
    return 0
fi

if [ "$log_file_earliest"x == "$log_file_lastest"x ]; then
    log_tar_name="antminer_log"${log_file_earliest//\//-}".tar"
else
    log_file_earliest=${log_file_earliest//\//-}
    log_file_lastest=${log_file_lastest//\//-}
    log_tar_name="antminer_log_"${log_file_earliest/-/}"_"${log_file_lastest/-/}".tar"
fi

echo ${log_tar_name}${log_file_list} > /tmp/miner_act
sync

echo "{\"stats\":\"success\",\"code\":\"L000\",\"msg\":\""${log_tar_name}"\"}"

sleep 3s
