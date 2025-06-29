## DWM Rice

Combination of full DWM desktop with rice and dots.

Inspired from [catppuccin-dots](https://github.com/clarks03/catppuccin-dots), and others I don't remember unfortunately :<

## Prerequisites

Full list of requisites for everything

## OpenSUSE Tumbleweed (X11)

fonts?
Kitty (terminal)
Zathura (pdf)
Catppuccin (theme)

```bash
sudo zypper in clang make
sudo zypper in libX11-devel libXft-devel libXinerama-devel fribidi-devel libXrandr-devel imlib2-devel
sudo zypper in dunst kitty picom rofi wezterm zathura
sudo cp src/dwm/dwm.desktop /usr/share/xsessions/
sudo zypper in libnotify-tools calcurse xdotool scrot
cp -r .config/ ~/
cp -r .screenlayout/ ~/
cp -r .local/ ~
cp -r wallpapers/ ~
cp .Xresources ~/
```

Install JetBrains Mono Nerd fonts from https://www.nerdfonts.com/font-downloads
- Move .ttfs to ~/.fonts/
- Run fc-cache -fv

same for https://fonts.google.com/noto/specimen/Noto+Sans

Change fonts using the `pango-list` tool if you cant find your font

### Post-Setup

```bash
sudo zypper in chromium git-core fish gtk2-engine-murrine nemo sassc arandr brightnessctl
sudo chch -s $(which fish)
cd themes/Catppuccin-GTK-Theme/themes && bash install.sh --tweaks macchiato -c dark -t yellow
sudo zypper in lxappearance autorandr
# need this helper script
gsettings set org.cinnamon.desktop.default-applications.terminal exec open-wezterm-here.sh
# pick one from ls /usr/share/applications/
# query with  xdg-mime query default "inode/directory"
xdg-mime default nemo.desktop "inode/directory"
```

- Configure theme with lxappearance to Catpuccin for example
- Configure default xrandr configs (for example `autorandr --save mobile` for single-monitor usecase)
- Install copyq from https://github.com/hluk/CopyQ/releases
- Add ~/.local/bin to path: `fish_add_path /home/amiryazdi/.local/bin/`

#### Organizational
```bash
sudo zypper in opi tailscale
sudo systemctl enable tailscaled
opi install vscode teams
```

Configure /etc/hostname