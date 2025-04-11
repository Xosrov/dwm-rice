#!/bin/sh

# Prints network usage.

case $BLOCK_BUTTON in
    3) notify-send "Network module" "\- Shows total network usage." ;;
esac

# Get the first network interface
interface=$(ip route | head -n 1 | grep default | awk '{print $5}')

if [ -n "$interface" ]; then
    # Network usage
    rx_bytes=$(cat /sys/class/net/$interface/statistics/rx_bytes)
    tx_bytes=$(cat /sys/class/net/$interface/statistics/tx_bytes)
    rx_mb=$(echo "$rx_bytes / 1024 / 1024" | bc)
    tx_mb=$(echo "$tx_bytes / 1024 / 1024" | bc)
else
    # No network interface found
    network_info=" No network"
fi

# Icons and formatting
echo "^c#B0F9FF^  RX:${rx_mb}MB    TX:${tx_mb}MB"

