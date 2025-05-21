-- Pull in the wezterm API
local wezterm = require 'wezterm'
local act = wezterm.action

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

config.scrollback_lines = 10000

config.keys = { -- Close the tab
{
    key = 'w',
    mods = 'CTRL|SHIFT',
    action = act.CloseCurrentTab {
        confirm = true
    }
}, -- Open a new tab
{
    key = 't',
    mods = 'CTRL|SHIFT',
    action = act.SpawnTab('CurrentPaneDomain')
}, -- Split the current pane vertically
{
    key = 'd',
    mods = 'CTRL|SHIFT',
    action = act.SplitVertical {
        domain = 'CurrentPaneDomain'
    }
}, -- Split the current pane horizontally
{
    key = 's',
    mods = 'CTRL|SHIFT',
    action = act.SplitHorizontal {
        domain = 'CurrentPaneDomain'
    }
}, {
    key = 'K',
    mods = 'CTRL|SHIFT',
    action = act.Multiple {act.ClearScrollback 'ScrollbackAndViewport', act.SendKey {
        key = 'L',
        mods = 'CTRL'
    }}
}}

-- Changing the colourscheme:
config.color_scheme = 'Catppuccin Mocha'

-- And finally, return the configuration to wezterm
return config
