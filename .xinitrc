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

# clock and battery in menubar
while true; do
    #battery = acpi -b | awk 'sub(/,/,"") { print $4 }'
    battery="$(acpi -b | awk 'sub(/,/,"") {print "Battery", $4}')"
    xsetroot -name "${battery%?} | $( date +"%Y-%m-%d %I:%M %p" )"
    #xsetroot -name "$(acpi -b | awk 'sub(/,/,"") {print "Battery", $4}')%? | $( date +"%Y-%m-%d %I:%M %p" )"
  sleep 15s
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

# gtk theme
# export GTK2_RC_FILES="$HOME/.gtkrc-2.0"

# start dwm
exec /usr/bin/dwm
