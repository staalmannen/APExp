/*
 * A REXX wrapper to deal with IBM Visual Age's ilib tool to:
 * 1) make it look a bit like a UNIX ar command,
 * 2) prevent it from going into interactive mode,
 * 3) handle the -+ argument tag for library editing
 */

parse arg library modules

'@echo off'
do i=1 to words( modules )
	'ilib /NOBACKUP /NOIGNORECASE /QUIET' library '-+' word( modules, 1 ) ';'
end
