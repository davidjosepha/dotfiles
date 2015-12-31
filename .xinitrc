#!/bin/sh
#
# ~/.xinitrc
#

if [ -d /etc/X11/xinit/xinitrc.d ]; then
  for f in /etc/X11/xinit/xinitrc.d/*; do
    [ -x "$f" ] && . "$f"
  done
  unset f
fi

[[ -f ~/.Xresources ]] && xrdb -merge ~/.Xresources

# status bar
while true; do
  nowplaying=$(mpc -f "Now Playing: %artist% - %title%" | egrep Now\ Playing: | awk 'sub(/Now Playing:/,"") { print $N, "   |   " }' | tr '[:lower:]' '[:upper:]')

  vol=$(amixer sget Master | egrep Front\ Right: | awk -F "[][]" '{ print "VOL", $2, "   |   " }')
  battery=$(acpi -b | awk '{print "BAT", $NF, "   |   "}')

  xsetroot -name "${nowplaying}${vol}${battery}$(date +"%^a %d %^b %Y %l:%M:%S %p")"
  sleep .01s
done &

# turn off screen blanking
xset dpms 0 0 0
xset -dpms s off

# MPD scrobbling daemon
mpdcron &

# laptop keys
xbindkeys &

# set wallpaper
~/.fehbg

# window dropshadow
compton -b -e .3 --vsync opengl

# this helps with full screen games
wmname LG3D

# start dwm
exec /usr/bin/dwm
