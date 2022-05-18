/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "rofi", "-show", "drun", "-show-icons", NULL };
static const char *termcmd[]  = { "alacritty", NULL };
	/* custom commands */
	static const char *ranger[]	= { "alacritty", "-e", "ranger", NULL };
	static const char *btop[]	= { "alacritty", "-t", "btop", "-e", "btop", NULL };
//	static const char *webcmd[]	= { "firefox", NULL };
	/* Volume control */
	static const char *upvol[]	= { "pamixer", "-i", "5", NULL };
	static const char *downvol[]	= { "pamixer", "-d", "5", NULL };
	static const char *mutevol[]	= { "pamixer", "-t", NULL };
	/* Backlight control */
	static const char *uplight[]	= { "brightnessctl", "s", "+5%", NULL };
	static const char *downlight[]	= { "brightnessctl", "s", "5%-", NULL };
	/* Screenshots with Scrotre */
	static const char *scrot[]		= { "scrotre", "-C", NULL };
	static const char *scrot_save[]		= { "scrotre", "/home/andrei/Изображения/Screenshots/%Y-%m-%d-%H%M%S_$wx$h_scrotre.png", NULL };
	static const char *scrot_sel[]		= { "scrotre", "-sC", NULL };
	static const char *scrot_sel_save[]	= { "scrotre", "-s", "/home/andrei/Изображения/Screenshots/%Y-%m-%d-%H%M%S_$wx$h_scrotre.png", NULL };
	/* MPRIS control */
	static const char *plause[]	= { "playerctl", "play-pause", NULL };
	static const char *plop[]	= { "playerctl", "stop", NULL };
	static const char *plev[]	= { "playerctl", "previous", NULL };
	static const char *plext[]	= { "playerctl", "next", NULL };

#include <X11/XF86keysym.h>
#include "focusurgent.c"
#include "movestack.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY,	                XK_Return, spawn,          {.v = termcmd } },
//	{ MODKEY,                       XK_b,      togglebar,      {0} },
		/* vi keys */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
//	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
//	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
		/* arrow keys */
	{ MODKEY,                       XK_Down,   focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Up,     focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_Left,   setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_Right,  setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Down,   movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Up,     movestack,      {.i = -1 } },
	
	{ MODKEY|ShiftMask,             XK_s,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,	                XK_q,      killclient,     {0} },
//	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
//	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
//	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_m,      setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
//	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
//	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
//	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
//	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
		/* Volume control */
	{ 0,				XF86XK_AudioRaiseVolume,  spawn,          {.v = upvol   } },
	{ 0,				XF86XK_AudioLowerVolume,  spawn,          {.v = downvol } },
	{ 0,				XF86XK_AudioMute, 	  spawn,          {.v = mutevol } },
		/* Backlight control */
	{ 0,				XF86XK_MonBrightnessUp,   spawn,          {.v = uplight } },
	{ 0,				XF86XK_MonBrightnessDown, spawn,        {.v = downlight } },
		/* Scrotre */
	{ 0,				XK_Print,	spawn,		{.v = scrot          } },
	{ ShiftMask,			XK_Print,	spawn,		{.v = scrot_save     } },
	{ ControlMask,			XK_Print,	spawn,		{.v = scrot_sel      } },
	{ ControlMask|ShiftMask,	XK_Print,	spawn,		{.v = scrot_sel_save } },
		/* MPRIS control */
	{ 0,				XF86XK_AudioPlay,	spawn,	{.v = plause } },
	{ 0,				XF86XK_AudioStop,	spawn,	{.v = plop   } },
	{ 0,				XF86XK_AudioPrev,	spawn,	{.v = plev   } },
	{ 0,				XF86XK_AudioNext,	spawn,	{.v = plext  } },
		/* Custom commands */
	{ MODKEY,                       XK_f,		spawn,          {.v = ranger } },
	{ ShiftMask|ControlMask,        XK_Escape,	spawn,          {.v = btop   } },
//	{ MODKEY,			XK_w,		spawn,		{.v = webcmd } },
//	{ MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
//	{ MODKEY,                       XK_equal,  setgaps,        {.i = +5 } },
//	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },

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
	{ MODKEY,	                XK_a,      focusurgent,    {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
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
