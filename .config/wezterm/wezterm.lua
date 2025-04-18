-- Pull in the wezterm API
local wezterm = require 'wezterm'

-- This will hold the configuration
local config = wezterm.config_builder()

-- This is where you actually apply your config choices
config.enable_tab_bar = false
config.window_padding = {
    left = 8,
    right = 8,
    top = 8,
    bottom = 8
}

-- For exampoe, changing the colourscheme:
config.color_scheme = 'Catppuccin Mocha'

-- And finally, return the configuration to wezterm
return config
