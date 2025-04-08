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
```

Install JetBrains Mono Nerd fonts from https://www.nerdfonts.com/font-downloads
- Move .ttfs to ~/.fonts/
- Run fc-cache -fv

same for https://fonts.google.com/noto/specimen/Noto+Sans

Change fonts using the `pango-list` tool if you cant find your font

### Post-Setup

```bash
sudo zypper in chromium git-core fish gtk2-engine-murrine nemo sassc arandr
sudo chch -s $(which fish)
cd themes/Catppuccin-GTK-Theme/themes && bash install.sh --tweaks macchiato -c dark -t teal
sudo zypper in lxappearance
```

- Configure theme with lxappearance to Catpuccin for example
- Install copyq from https://github.com/hluk/CopyQ/releases

#### Organizational
```bash
sudo zypper in opi tailscale
sudo systemctl enable tailscaled
opi install vscode teams
```

Configure /etc/hostname