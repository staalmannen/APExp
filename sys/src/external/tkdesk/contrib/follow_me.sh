
#
# Here's some handy shell functions (works in Bash) and aliases
# that 1) let TkDesk follow you around as you change dirs in an
# xterm (rxvt, whatever), and B) sets the window title of the
# xterm to reflect the current dir, etc.
#
# It also includes support for pushd (pd) and popd.
#
# You could source this file from your .bashrc (for example).
#
# Note that in order for the cd-tkdesk command to work, the TkDesk
# server must be activated (from the TkDesk options pulldown menu).
# 
# Enjoy,
#
#	J. Chris Coppick
#

function _cd () {
   \cd "$@"
   Xtitle
   /usr/local/bin/cd-tkdesk $PWD
}

function _pushd () {
   \pushd "$@"
   Xtitle
   /usr/local/bin/cd-tkdesk $PWD
}

function _popd () {
   \popd "$@"
   Xtitle
   /usr/local/bin/cd-tkdesk $PWD
}

function Xtitle () {
   # if [ -n "$DISPLAY" ] ; then
      case "$TERM" in
	 *xterm)
	    WHOAMI=`whoami`
	    echo -n "]2;$WHOAMI@$HOSTNAME:  $PWD"
	    ;;
      esac
   # fi
}

# Set XTerm title...
Xtitle

#
# Aliases...
#
alias cd=_cd
alias pushd=_pushd
alias popd=_popd
alias pd=pushd
alias pd2='pushd +2'
alias pd3='pushd +3'
alias pd4='pushd +4'
alias pd5='pushd +5'

