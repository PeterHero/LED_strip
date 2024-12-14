#!/bin/sh
set -eu

MAC="98:D3:51:F9:28:75"

# connect pair bluetooth device

# check if paired
bluetoothctl info $MAC | grep "Paired"

# bind device
sudo rfcomm bind 0 $MAC
sudo chmod o+rw /dev/rfcomm0

# write commands to the device
