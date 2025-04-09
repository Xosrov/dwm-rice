#!/bin/sh
xrandr --output eDP-1 --off
xrandr --output DP-4 --primary --mode 2560x1440 --pos 0x0 --rate 59.95 \
       --output DP-3-2 --mode 2560x1440 --pos 2560x0 --rate 59.95
