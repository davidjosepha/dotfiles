/* See LICENSE file for copyright and license details. */

/* appearance */
//static const char font[]            = "-*-terminus-medium-r-*-*-10-*-*-*-*-*-*-*";
static const char font[] = "Terminus 8";
static const char dmenufont[] = "Terminus:Clear:size=8:antialias=true:hinting=true";
static const char normbordercolor[] = "#1D1D1D";
static const char normbgcolor[]     = "#101010";
static const char normfgcolor[]     = "#cccccc";
static const char selbordercolor[]  = "#404750";
static const char selbgcolor[]      = "#404750";
static const char selfgcolor[]      = "#dddddd";
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int snap      = 6;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "α", "β", "γ", "δ", "ε", "ζ", "η", "θ", "ι" };

static const Rule rules[] = {
	/* class        instance    title    tags    x     y     w     h        floating   monitor */
	{ NULL,         NULL,       NULL,    0,      12,   26,   0,    0,       True,      -1 },
	{ "URxvt",      NULL,       NULL,    0,      12,   26,   618,  360,     True,      -1 },
	{ "Conky",      NULL,       NULL,    0,      0,    0,    0,    0,       True,      -1 },
    /* right 2/3s */
	{ "Dwb",        NULL,       NULL,    0,      648,  26,   1252, 1036,    True,      -1 },
	{ "Filezilla",  NULL,       NULL,    0,      648,  26,   1252, 1036,    True,      -1 },
	{ "Firefox",    NULL,       NULL,    0,      648,  26,   1252, 1036,    True,      -1 },
	{ "Gimp",       NULL,       NULL,    0,      0,    0,    0,    0,       True,      -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	/*{ "[]=",      tile },*/    /* first entry is default */
	/*{ "[M]",      monocle },*/
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

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "urxvt", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
  /*{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },*/
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    { MODKEY,                       XK_Down,   moveresize,     {.v = (int []){ 0, 12, 0, 0 }}},
    { MODKEY,                       XK_Up,     moveresize,     {.v = (int []){ 0, -12, 0, 0 }}},
    { MODKEY,                       XK_Right,  moveresize,     {.v = (int []){ 12, 0, 0, 0 }}},
    { MODKEY,                       XK_Left,   moveresize,     {.v = (int []){ -12, 0, 0, 0 }}},
    { MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = (int []){ 0, 0, 0, 12 }}},
    { MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = (int []){ 0, 0, 0, -12 }}},
    { MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = (int []){ 0, 0, 12, 0 }}},
    { MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = (int []){ 0, 0, -12, 0 }}},
    { MODKEY|ShiftMask|ControlMask, XK_Down,   moveresize,     {.v = (int []){ 0, 0, 0, 372 }}},
    { MODKEY|ShiftMask|ControlMask, XK_Up,     moveresize,     {.v = (int []){ 0, 0, 0, -372 }}},
    { MODKEY|ShiftMask|ControlMask, XK_Right,  moveresize,     {.v = (int []){ 636, 0, 0, 0 }}},
    { MODKEY|ShiftMask|ControlMask, XK_Left,   moveresize,     {.v = (int []){ -636, 0, 0, 0 }}},
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
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
  /*{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },*/
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

