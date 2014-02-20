#!/usr/bin/python2

import os
import shutil
import commands
import sys

# Name of current album
album = commands.getoutput("mpc --format %artist%+%album% | head -n 1")
if os.path.exists("/tmp/nowplaying"):
    nowplaying = open("/tmp/nowplaying").read()
    if album is not None and nowplaying == album:
        sys.exit()

def copycover(currentalbum, src, dest):
    if os.path.exists(src + "front.jpg"):
        shutil.copy(src + "front.jpg", dest)
    elif os.path.exists(src + "front.png"):
        shutil.copy(src + "front.png", dest)

filename = "/data/audio/" + os.path.dirname(commands.getoutput("mpc --format %file% | head -n 1")) + "/"
copycover(album, filename, "/tmp/cover")
open("/tmp/nowplaying", "w").write(album)

#if album != "":
#    filename = "/data/audio/" + os.path.dirname(commands.getoutput("mpc --format %file% | head -n 1")) + "/"
#    cover = "/tmp/cover"
#    if os.path.exists("/tmp/nowplaying") and os.path.exists("/tmp/cover"):
#        nowplaying = open("/tmp/nowplaying").read()
#        if nowplaying == album:
#            pass
#        else:
#            copycover(album, filename, cover)
#            open("/tmp/nowplaying", "w").write(album)
#    else:
#        copycover(album, filename, cover)
#        open("/tmp/nowplaying", "w").write(album)
