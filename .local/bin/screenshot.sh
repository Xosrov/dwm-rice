#!/bin/sh
scrot -s -e 'xclip -selection clipboard -t image/png -i $f' ~/Pictures/Screenshots/scrot-%b%d-%H:%M:%S.png
