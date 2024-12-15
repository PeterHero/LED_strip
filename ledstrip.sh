#!/bin/sh
set -eu

MAC="98:D3:51:F9:28:75"

# connect pair bluetooth device

# check if paired
if ! bluetoothctl info $MAC | grep "Paired: yes" >/dev/null 2>&1 ; then
    # connect to bluetooth
    exit 1
fi

# bind device

if ! ls /dev/rfcomm0 >/dev/null 2>&1 ; then
    sudo rfcomm bind 0 $MAC
    sudo chmod o+rw /dev/rfcomm0
fi

echo "$1"
echo "$1" > /dev/rfcomm0

# write commands to the device
