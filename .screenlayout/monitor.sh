#!/bin/sh

update_displays() {
    autorandr --change
    # setting the wallpaper
    wall=~/wallpapers/wallpaper.jpg
    feh --bg-fill $wall
}

# initial setup
update_displays

udevadm monitor -u --subsystem-match=drm | while read -r line; do
    if echo "$line" | grep -q "change"; then
        echo "Display change detected"
        update_displays
    fi
done