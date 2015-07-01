/* See LICENSE file for copyright and license details. */

#define HINC  7
#define HJMP  90*HINC
#define VINC  13 
#define VJMP  26*VINC
#define W1    599
#define W2    W1+HJMP
#define W3    W2+HJMP
#define H1    312
#define H2    H1+VJMP
#define H3    H2+VJMP
#define L1    20
#define L2    L1+HJMP
#define L3    L2+HJMP
#define T1    51
#define T2    T1+VJMP
#define T3    T2+VJMP

/* appearance */
static const char font[] = "Inconsolata LGC Bold 8";
static const char dmenufont[] = "Inconsolata LGC:style=Bold:pixelsize=10:antialias=true:hinting=true";
static const char normbordercolor[] = "#1D1D1D";
static const char normbgcolor[]     = "#1D1D1D";
static const char normfgcolor[]     = "#cccccc";
static const char selbordercolor[]  = "#e3e4e6";
static const char selbgcolor[]      = "#e3e4e6";
static const char selfgcolor[]      = "#404040";
static const unsigned int borderpx  = 7;        /* border pixel of windows */
static const unsigned int snap      = 7;        /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */
static const int barpadding         = 10;

/* tagging */
static const char *tags[] = { "А", "Б", "В", "Г", "Д", "Е", "Ж", "З", "И" };

static const Rule rules[] = {
 /* class        instance  title  tags  x    y   w     h   float  monitor */
  { NULL,        NULL,     NULL,  0,    L1,  T1, 0,    0,  True,  -1 },
  { "Conky",     NULL,     NULL,  0,    0,   0,  0,    0,  True,  -1 },
  /* minor */
  { "URxvt",     NULL,     NULL,  0,    L1,  T1, W1,  H1,  True,  -1 },
  /* major */
  { "Dwb",       NULL,     NULL,  0,    L2,  T1, W2, 979,  True,  -1 },
  { "Filezilla", NULL,     NULL,  0,    L2,  T1, W2, 979,  True,  -1 },
  { "Firefox",   NULL,     NULL,  0,    L2,  T1, W2, 979,  True,  -1 },
  { "Gimp",      NULL,     NULL,  0,    0,   0,  0,    0,  True,  -1 },
  { "Steam",     NULL,     NULL,  0,    L2,  T1, W2, 979,  True,  -1 },
};

/* layout(s) */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "><>",      NULL },    /* no layout function means floating behavior */
  /*{ "[]=",      tile },*/    /* first entry is default */
  /*{ "[M]",      monocle },*/
};

/* key definitions */
#define MODKEY Mod1Mask
#define WINKEY Mod2Mask
#define TAGKEYS(KEY,TAG) \
  { MODKEY,                        KEY,    view,          {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask,            KEY,    toggleview,    {.ui = 1 << TAG} }, \
  { MODKEY|ShiftMask,              KEY,    tag,           {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask|ShiftMask,  KEY,    toggletag,     {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run",
                                  "-fn", dmenufont,
                                  "-nb", normbgcolor,
                                  "-nf", normfgcolor,
                                  "-sb", selbgcolor,
                                  "-sf", selfgcolor,
                                  "-h", "25",
                                  NULL };
static const char *termcmd[]  = { "urxvt", NULL };
static const char *xkbdvorakcmd[]  = { "setxkbmap", "dvorak", NULL };
static const char *xkbrucmd[]  = { "setxkbmap", "rua", NULL };

static Key keys[] = {
  /* modifier                     key        function        argument */
  { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
  { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
  { ControlMask,                  XK_semicolon, spawn,       {.v = xkbrucmd } },
  { ControlMask,                  XK_Cyrillic_ya, spawn,     {.v = xkbdvorakcmd } },
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
  { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
  { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
  { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
  { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
  { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
  { MODKEY,                       XK_Down,   moveresize,     {.v = (int []){ 0, VINC, 0, 0 }}},
  { MODKEY,                       XK_Up,     moveresize,     {.v = (int []){ 0, -VINC, 0, 0 }}},
  { MODKEY,                       XK_Right,  moveresize,     {.v = (int []){ HINC, 0, 0, 0 }}},
  { MODKEY,                       XK_Left,   moveresize,     {.v = (int []){ -HINC, 0, 0, 0 }}},
  { MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = (int []){ 0, 0, 0, VINC }}},
  { MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = (int []){ 0, 0, 0, -VINC }}},
  { MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = (int []){ 0, 0, HINC, 0 }}},
  { MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = (int []){ 0, 0, -HINC, 0 }}},
  { MODKEY|ShiftMask|ControlMask, XK_Down,   moveresize,     {.v = (int []){ 0, 338, 0, 0 }}},
  { MODKEY|ShiftMask|ControlMask, XK_Up,     moveresize,     {.v = (int []){ 0, -338, 0, 0 }}},
  { MODKEY|ShiftMask|ControlMask, XK_Right,  moveresize,     {.v = (int []){ 630, 0, 0, 0 }}},
  { MODKEY|ShiftMask|ControlMask, XK_Left,   moveresize,     {.v = (int []){ -630, 0, 0, 0 }}},
  { MODKEY|ShiftMask|ControlMask, XK_j,      moveresize,     {.v = (int []){ 0, 0, 0, 338 }}},
  { MODKEY|ShiftMask|ControlMask, XK_k,      moveresize,     {.v = (int []){ 0, 0, 0, -338 }}},
  { MODKEY|ShiftMask|ControlMask, XK_l,      moveresize,     {.v = (int []){ 0, 0, 630, 0 }}},
  { MODKEY|ShiftMask|ControlMask, XK_h,      moveresize,     {.v = (int []){ 0, 0, -630, 0 }}},
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

