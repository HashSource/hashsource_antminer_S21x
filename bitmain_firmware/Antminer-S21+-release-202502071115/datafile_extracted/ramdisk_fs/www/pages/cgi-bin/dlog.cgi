#!/bin/sh -e

log_path="/nvdata/log/debug"

n=$(find $log_path -type f | wc -l)
echo ""

if [ -d '/nvdata' ] && [ $n -gt 0 ];then
    log_list=$(ls $log_path | cut -d"_" -f2 | cut -d"." -f1 | xargs -I {} echo "\"/{}\"," | sed "s/-/\//2")
    log_list=${log_list%,}
    echo "{\"dlog\": true, \"log_list\": [${log_list}]}"
else
    echo "{\"dlog\": false}"
fi
