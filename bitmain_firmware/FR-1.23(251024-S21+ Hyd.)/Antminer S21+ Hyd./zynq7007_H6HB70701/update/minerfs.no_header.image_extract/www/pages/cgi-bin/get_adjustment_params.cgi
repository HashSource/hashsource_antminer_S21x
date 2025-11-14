echo
echo
if [ -f /etc/topol.conf ]
then
    hashrate_percent_min=$(jq -r '.config[0].adjust_strategy.hashrate_percent_min // 65' /etc/topol.conf)
    hashrate_percent_max=$(jq -r '.config[0].adjust_strategy.hashrate_percent_max // 100' /etc/topol.conf)

    chip_temp_threshold_min=$(jq -r '.config[0].adjust_strategy.chip_temp_threshold_min // 80' /etc/topol.conf)
    chip_temp_threshold_max=$(jq -r '.config[0].adjust_strategy.chip_temp_threshold_max // 98' /etc/topol.conf)

    drop_freq_scale_slider_min=$(jq -r '.config[0].adjust_strategy.drop_freq_scale_slider_min // 80' /etc/topol.conf)
    drop_freq_scale_slider_max=$(jq -r '.config[0].adjust_strategy.drop_freq_scale_slider_max // 100' /etc/topol.conf)
else
    hashrate_percent_min=65
    hashrate_percent_max=100
    chip_temp_threshold_min=80
    chip_temp_threshold_max=98
    drop_freq_scale_slider_min=80
    drop_freq_scale_slider_max=100
fi

echo "{
    \"hashrate_percent_min\": \"$hashrate_percent_min\", \"hashrate_percent_max\": \"$hashrate_percent_max\",
    \"chip_temp_threshold_min\": \"$chip_temp_threshold_min\", \"chip_temp_threshold_max\": \"$chip_temp_threshold_max\",
    \"drop_freq_scale_slider_min\": \"$drop_freq_scale_slider_min\", \"drop_freq_scale_slider_max\": \"$drop_freq_scale_slider_max\"}"
