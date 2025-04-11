#!/bin/sh

# Prints the current brightness level or 🔅 if very low.

case $BLOCK_BUTTON in
    4) brightnessctl set +1% ;;
    5) brightnessctl set 1%- ;;
    3) notify-send "Brightness module" "\- Shows brightness level.
- Scroll to change brightness." ;;
    6) setsid -f "$TERMINAL" -e "$EDITOR" "$0" ;;
esac

brightness="$(brightnessctl get)"
max_brightness="$(brightnessctl max)"
brightness_percent=$((brightness * 100 / max_brightness))

case 1 in
    $((brightness_percent >= 70)) ) icon=" " ;;
    $((brightness_percent >= 30)) ) icon="● " ;;
    * ) icon="○ " ;;
esac

echo "^c#FEFA6F^$icon $brightness_percent%"

