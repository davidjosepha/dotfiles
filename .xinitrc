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
  xsetroot -name "$( date +"%F %R" )"
  sleep 15s
done &

# MPD daemon start (if no other user instance exists)
[ ! -s ~/.mpd/pid ] && mpd
[[ -z $(pgrep -xU $UID mpdas) ]] && mpdas &

# audio mixer
# xterm -name alsamixer -e alsamixer &

# keybinder (audio keys)
#xterm -name xbindkeys -e xbindkeys &

# set wallpaper
eval `cat ~/.fehbg`

# window dropshadow
compton -c -b

# start dwm
exec /usr/bin/dwm
