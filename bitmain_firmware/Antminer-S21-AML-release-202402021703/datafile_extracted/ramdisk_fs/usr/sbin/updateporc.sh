#!/bin/sh 

subtype=""
function getalltype() {
    FILE=$1
    if [ -f $FILE ];then
        type_result=`/www/pages/cgi-bin/miner_type.cgi`
        miner_type=`echo $type_result | jq ".miner_type"`
        miner_type=`echo $miner_type | sed 's/\"//g'`
        subtype=`echo $type_result | jq ".subtype"`
        subtype=`echo $subtype | sed 's/\"//g'`
        return 0
    else
        return 44
    fi
}

pemSel=/etc/bitmain.pub
function spliteFile(){
    if [ -d /tmp/tmpfw ]; then
        rm /tmp/tmpfw -rf
    fi
    mkdir -p /tmp/tmpfw
    /usr/bin/FileParser -s "$subtype" $1 ${pemSel}
    res=$?
    if [ $res -ne 0 ]; then
        echo "BMU CHECK FAILED!"
    fi
    return $res
}

function checkFile(){
    cd /tmp/tmpfw
    if [ ! -f miner.pem ]; then
        echo "Cannot Find Miner!"
        return 1
    fi
    if [ ! -f miner.pem.sig ]; then
        echo "Cannot Find Miner Signature"
        return 2
    fi
    openssl dgst -sha256 -verify ${pemSel} -signature miner.pem.sig miner.pem > /dev/null
    res=$?
    if [ $res -ne 0 ]; then
        echo "Check Miner Signature Failed!"
        return 3
    fi

    srcFile="BOOT.bin devicetree.dtb uImage minerfs.image.gz update.image.gz crl.tar.gz miner.btm.tar.gz datafile"
    for file in ${srcFile};
    do
        sigFile="${file}.sig"
        if [ -f ${file} ]; then
            if [ ! -f ${sigFile} ]; then
                echo "Cannot Find ${sigFile} !"
                return 1
            else
                openssl dgst -sha256 -verify miner.pem -signature ${sigFile} ${file}  > /dev/null
                res=$?
                if [ $res -ne 0 ]; then
                    echo "Check ${file} Signature Failed!"
                    return 2
                fi
            fi
        fi
    done
}

function writeToNand(){
    cd /tmp/tmpfw/
  
    if [ -f datafile ]; then
        echo "write boot.img to mtd4 (amlogic a113d)"
        flash_eraseall /dev/mtd4 >/dev/null
        nandwrite -p -s 0x0 /dev/mtd4 datafile >/dev/null
    fi
    
    sleep 3
    sync
    echo "----------write all update files over---------------"
}


srcFile=$1

# Split Update File
if [ -z ${srcFile} ]; then
	echo "Wrong Param"
	return 9
fi

getalltype $srcFile
res=$?
if [ $res -ne 0 ]; then
    echo "getalltype error! res=$res"
    return $res
fi

spliteFile ${srcFile}
res=$?
if [ $res -ne 0 ]; then
	echo "Splite Bmu Failed! res=$res"
	return $res
fi

#Check Splited Data
checkFile
res=$?
if [ $res -ne 0 ]; then
    echo "Check Data Failed! res=$res"
    return $res
fi

#Write datafile(boot.img)  To Nand
writeToNand
if [ $res -ne 0 ]; then
    return $res
fi
