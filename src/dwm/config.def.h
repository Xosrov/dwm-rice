/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft  = 0;   /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const unsigned int gappih    = 5;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 5;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const double activeopacity   = 0.95f;    /* Window opacity when it's focused (0 <= opacity <= 1) */
static const double inactiveopacity = 0.90f;     /* Window opacity when it's inactive (0 <= opacity <= 1) */
static const int user_bh            = 12;        /* 2 is the default spacing around the bar's font */
static const char *fonts[]          = { "Noto Sans:size=10:style=Bold", "JetBrainsMono Nerd Font:size=10", "Noto Color Emoji:size=10" };
static const char dmenufont[]       = "JetBrainsMono Nerd Font:size=10";
static char normbgcolor[]           = "#1e1e2e";  // base background
static char normbordercolor[]       = "#45475a";  // muted border
static char normfgcolor[]           = "#cdd6f4";  // base foreground
static char selfgcolor[]            = "#1e1e2e";  // inverse for selection
static char selbordercolor[]        = "#f9e2af";  // yellow border
static char selbgcolor[]            = "#f9e2af";  // yellow background
static char statusbgcolor[]         = "#1e1e2e";
static char statusfgcolor[]         = "#cdd6f4";
static char tagsnormbgcolor[]       = "#1e1e2e";
static char tagsnormfgcolor[]       = "#cdd6f4";
static char tagsselbgcolor[]        = "#f9e2af";
static char tagsselfgcolor[]        = "#1e1e2e";
static char tagsemptynormbgcolor[]  = "#45475a";
static char tagsemptynormfgcolor[]  = "#cdd6f4";
static char tagsemptyselbgcolor[]   = "#f9e2af";
static char tagsemptyselfgcolor[]   = "#1e1e2e";
static char infonormbgcolor[]       = "#1e1e2e";
static char infonormfgcolor[]       = "#cdd6f4";
static char infoselbgcolor[]        = "#f9e2af";
static char infoselfgcolor[]        = "#1e1e2e";
static char *colors[][3]      = {
    /*                       fg              bg               border */
    [SchemeNorm]         = { normfgcolor,    normbgcolor,     normbordercolor },
    [SchemeSel]          = { selfgcolor,     selbgcolor,      selbordercolor  },
    [SchemeStatus]       = { statusfgcolor,  statusbgcolor,   "#000000" },
    [SchemeTagsSel]      = { tagsselfgcolor, tagsselbgcolor,  "#000000" },
    [SchemeTagsNorm]     = { tagsnormfgcolor,tagsnormbgcolor, "#000000" },
    [SchemeTagsEmptyNorm]= { tagsemptynormfgcolor, tagsemptynormbgcolor, "#000000" },
    [SchemeTagsEmptySel] = { tagsemptyselfgcolor, tagsemptyselbgcolor, "#000000" },
    [SchemeInfoSel]      = { infoselfgcolor, infoselbgcolor,  "#000000" },
    [SchemeInfoNorm]     = { infonormfgcolor,infonormbgcolor, "#000000" },
};

static const char *const autostart[] = {
    "/home/amiryazdi/.screenlayout/monitor.sh", NULL,                  /* monitor layout & resolution */
    "/home/amiryazdi/.local/bin/dwm-catppuccin.sh", NULL,              /* colourscheme (catppuccin) */ 
    "xset", "r", "rate", "400", "30", NULL,                            /* Keyboard repeat rate */
    "picom", "--mark-ovredir-focused", "--use-ewmh-active-win", NULL,  /* Setting a compositor */
    "dunst", NULL,                                                     /* Setting a notification daemon */
    "xhost", "+si:localuser:amiryazdi", NULL,                          /* This should make it so clicking Discord links works */
    "dwmblocks", NULL,                                                 /* dwmblocks (status) */
    "copyq", NULL,                                                     /* Copyq start */
    NULL                                                               /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
    /* xprop(1):
     *    WM_CLASS(STRING) = instance, class
     *    WM_NAME(STRING) = title
     */
    /* class     instance  title           tags mask  isfloating  isterminal  noswallow focusopacity unfocusopacity monitor */
    { "St",      NULL,     NULL,           0,         0,          1,           0,        0.95,        0.88,       -1 },
    { "org.wezfurlong.wezterm", NULL, NULL,0,         0,          1,           0,        0.95,        0.88,       -1 },
    { "copyq",   NULL,     NULL,           0,         1,          0,           1,        0.80,        0.75,       -1 },
    { NULL,      NULL,     "Event Tester", 0,         0,          0,           1,        1,           1,          -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int attachbelow = 1;    /* 1 means attach after the currently active window */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "[M]",      monocle },
    { "[@]",      spiral },
    { "[\\]",     dwindle },
    { "H[]",      deck },
    { "TTT",      bstack },
    { "===",      bstackhoriz },
    { "HHH",      grid },
    { "###",      nrowgrid },
    { "---",      horizgrid },
    { ":::",      gaplessgrid },
    { "|M|",      centeredmaster },
    { ">M>",      centeredfloatingmaster },
    { "><>",      NULL },    /* no layout function means floating behavior */
    { NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "/home/amiryazdi/.config/rofi/launchers/type-2/launcher.sh", NULL };
static const char *termcmd[]  = { "wezterm", "start", "--always-new-process", NULL };
static const char *powermenucmd[] = {"/home/amiryazdi/.config/rofi/powermenu/type-2/powermenu.sh", NULL };
//sound controls
static const char *upvol[]   = { "pactl", "set-sink-volume", "0", "+5%",     NULL };
static const char *downvol[] = { "pactl", "set-sink-volume", "0", "-5%",     NULL };
static const char *mutevol[] = { "pactl", "set-sink-mute",   "0", "toggle",  NULL };
// brightness controls
static const char *brupcmd[]   = { "brightnessctl", "set", "5%+", NULL };
static const char *brdowncmd[] = { "brightnessctl", "set", "5%-", NULL };

#include "movestack.c"
#include <X11/XF86keysym.h>

static const Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_p,  spawn,              {.v = dmenucmd } },
    { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
    { 0,                            XK_Print,  spawn,          SHCMD("screenshot.sh") },
    { MODKEY|ShiftMask,             XK_p,      spawn,          {.v = powermenucmd } },
    { 0,                            XF86XK_AudioLowerVolume,   spawn, {.v = downvol } },
    { 0,                            XF86XK_AudioMute,          spawn, {.v = mutevol } },
    { 0,                            XF86XK_AudioRaiseVolume,   spawn, {.v = upvol   } },
    { 0,                            XF86XK_MonBrightnessUp,    spawn, {.v = brupcmd} },
    { 0,                            XF86XK_MonBrightnessDown,  spawn, {.v = brdowncmd} },
    { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY|ShiftMask,             XK_j,      focusstack,     {.i = +1 } },
    { MODKEY|ShiftMask,             XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_s,      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_j,      setcfact,       {.f = +0.25} },
    { MODKEY,                       XK_k,      setcfact,       {.f = -0.25} },
    { MODKEY|ControlMask,           XK_j,      movestack,      {.i = +1 } },
    { MODKEY|ControlMask,           XK_k,      movestack,      {.i = -1 } },
    { MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
    { MODKEY,                       XK_Return, zoom,           {0} },
    { MODKEY|Mod4Mask,              XK_u,      incrgaps,       {.i = +1 } },
    { MODKEY|Mod4Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
    { MODKEY|Mod4Mask,              XK_i,      incrigaps,      {.i = +1 } },
    { MODKEY|Mod4Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
    { MODKEY|Mod4Mask,              XK_o,      incrogaps,      {.i = +1 } },
    { MODKEY|Mod4Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
    { MODKEY|Mod4Mask,              XK_6,      incrihgaps,     {.i = +1 } },
    { MODKEY|Mod4Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
    { MODKEY|Mod4Mask,              XK_7,      incrivgaps,     {.i = +1 } },
    { MODKEY|Mod4Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
    { MODKEY|Mod4Mask,              XK_8,      incrohgaps,     {.i = +1 } },
    { MODKEY|Mod4Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
    { MODKEY|Mod4Mask,              XK_9,      incrovgaps,     {.i = +1 } },
    { MODKEY|Mod4Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
    { MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
    { MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, // default
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[1]} }, // monocle
    { MODKEY,                       XK_space,  setlayout,      {0} }, // toggle
    // all others
    { MODKEY|ControlMask,           XK_q,      setlayout,      {.v = &layouts[2]} }, // spiral
    { MODKEY|ControlMask,           XK_w,      setlayout,      {.v = &layouts[3]} }, // dwindle
    { MODKEY|ControlMask,           XK_e,      setlayout,      {.v = &layouts[4]} }, // deck
    { MODKEY|ControlMask,           XK_r,      setlayout,      {.v = &layouts[5]} }, // bstack
    { MODKEY|ControlMask,           XK_a,      setlayout,      {.v = &layouts[6]} }, // bstackhoriz
    { MODKEY|ControlMask,           XK_s,      setlayout,      {.v = &layouts[7]} }, // grid
    { MODKEY|ControlMask,           XK_d,      setlayout,      {.v = &layouts[8]} }, // nrowgrid
    { MODKEY|ControlMask,           XK_f,      setlayout,      {.v = &layouts[9]} }, // horizgrid
    { MODKEY|ControlMask,           XK_z,      setlayout,      {.v = &layouts[10]}}, // gaplessgrid
    { MODKEY|ControlMask,           XK_x,      setlayout,      {.v = &layouts[11]}}, // centeredmaster
    { MODKEY|ControlMask,           XK_c,      setlayout,      {.v = &layouts[12]}}, // centeredfloatingmaster

    { MODKEY|ShiftMask,             XK_r,      togglefloating, {0} },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    { MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },
    { MODKEY|ShiftMask,             XK_a,      changefocusopacity,   {.f = +0.005}},
    { MODKEY|ShiftMask,             XK_s,      changefocusopacity,   {.f = -0.005}},
    { MODKEY|ShiftMask,             XK_z,      changeunfocusopacity, {.f = +0.005}},
    { MODKEY|ShiftMask,             XK_x,      changeunfocusopacity, {.f = -0.005}},
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
    { ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
    { ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
    { ClkStatusText,        0,              Button4,        sigstatusbar,   {.i = 4} },
    { ClkStatusText,        0,              Button5,        sigstatusbar,   {.i = 5} },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
