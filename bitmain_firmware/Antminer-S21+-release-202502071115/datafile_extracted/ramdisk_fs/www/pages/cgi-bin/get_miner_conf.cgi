echo
echo
if [ ! -f /config/cminer.json ] ; then
    cp /config/cminer.json.factory /config/cminer.json
fi
cat /config/cminer.json
