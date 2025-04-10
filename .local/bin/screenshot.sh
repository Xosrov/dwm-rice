#!/bin/sh
scrot -s -e 'xclip -selection clipboard -t image/png -i $f' ~/Pictures/Screenshots/scrot_%b%d-%H_%M_%S.png
