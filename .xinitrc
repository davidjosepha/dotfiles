#!/bin/sh
#
# ~/.xinitrc
#
# Executed by startx (run your window manager from here)

if [ -d /etc/X11/xinit/xinitrc.d ]; then
  for f in /etc/X11/xinit/xinitrc.d/*; do
    [ -x "$f" ] && . "$f"
  done
  unset f
fi

[[ -f ~/.Xresources ]] && xrdb -merge ~/.Xresources

# clock in menubar
while true; do
  xsetroot -name "$( date +"%Y-%m-%d %I:%M %p" )"
  sleep 1s
done &

# turn off screen blanking
xset dpms 0 0 0
xset -dpms s off

# MPD daemon start (if no other user instance exists)
#[ ! -s ~/.mpd/pid ] && mpd
#[[ -z $(pgrep -xU $UID mpdas) ]] && mpdas &
mpdcron &

# audio mixer
# xterm -name alsamixer -e alsamixer &

# keybinder (audio keys)
#xterm -name xbindkeys -e xbindkeys &

# set wallpaper
~/.fehbg

# start album art daemon
exec ~/scripts/albumart/albumartd.sh &

# window dropshadow
compton -c -b -e .4

# this helps with full screen games
wmname LG3D

# gtk theme
# export GTK2_RC_FILES="$HOME/.gtkrc-2.0"

# start dwm
exec /usr/bin/dwm

# start openbox
#tint2 &
#exec openbox-session
