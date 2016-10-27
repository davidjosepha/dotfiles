# Lines configured by zsh-newuser-install
HISTFILE=~/.histfile
HISTSIZE=1000
SAVEHIST=1000
bindkey -v
# End of lines configured by zsh-newuser-install
# The following lines were added by compinstall
zstyle :compinstall filename '/home/david/.zshrc'

autoload -Uz compinit
compinit
# End of lines added by compinstall

alias chmodgw='sudo chmod -R ugo+rwX,o-w'
alias git-locate='git ls-files | grep'
alias ls='ls -h --color=auto -N'
alias screenfetch='screenfetch -c 04,00'
alias scrot='scrot ~/ss/%Y-%m-%d-%H%M%S.png'
alias suvim='sudo -E vim'
alias steamdep='ldd ~/.local/share/Steam/ubuntu12_32/steamclient.so'
alias genpw='read -s PASS; echo $PASS | sha256sum | hex2ascii; echo'

export EDITOR=vim
export GOPATH=$HOME/go
export PATH=$GOPATH/bin:$HOME/bin:$PATH
export PS1='@%m %1~ $ '
export STEAM_RUNTIME=0

source /usr/share/doc/pkgfile/command-not-found.zsh

# Colored man pages: http://linuxtidbits.wordpress.com/2009/03/23/less-colors-for-man-pages/
# Less Colors for Man Pages
export LESS_TERMCAP_mb=$'\E[01;31m'       # begin blinking
export LESS_TERMCAP_md=$'\E[01;38;5;74m'  # begin bold
export LESS_TERMCAP_me=$'\E[0m'           # end mode
export LESS_TERMCAP_se=$'\E[0m'           # end standout-mode
export LESS_TERMCAP_so=$'\E[38;5;016m\E[48;5;220m'    # begin standout-mode - info box
export LESS_TERMCAP_ue=$'\E[0m'           # end underline
export LESS_TERMCAP_us=$'\E[04;38;5;146m' # begin underline

# webm
screengrab() {
    ffmpeg -f x11grab -s 1920x1080 -r 60 -i :0.0 -q:v 0 -vcodec huffyuv ~/grab.mkv
    ffmpeg -threads 8 -i ~/grab.mkv -crf 10 -b:v 3M ~/grab.webm
}
