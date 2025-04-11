#!/bin/sh

# Prints memory and CPU usage.

case $BLOCK_BUTTON in
    3) notify-send "Util module" "\- Shows memory and CPU usage." ;;
esac

# Memory usage
mem_usage=$(free -h | awk '/^Mem/ { print $3"/"$2 }' | sed s/i//g)

# CPU usage
cpu_usage=$(top -bn1 | grep "Cpu(s)" | awk '{print $2 + $4"%"}')

# Icons and formatting
echo "^c#FFA1F5^  $mem_usage    $cpu_usage"
