#!/usr/bin/env bash
#  ____         ____
# | __ )  __ _ / ___|___  _ __
# |  _ \ / _` | |   / _ \| '_ \
# | |_) | (_| | |__| (_) | | | |   --= A Shell BASIC-to-C converter =--
# |____/ \__,_|\____\___/|_| |_|
#
# Peter van Eerten - March 2009/March 2024. License: MIT License.
#
#---------------------------------------------------------------------------------------------------------------------
# CREDITS to all people of the BaCon forum. Without them BaCon would not be as it is now.
#---------------------------------------------------------------------------------------------------------------------
#
# This script should work with the following shells:
#
#   - Bourne Again Shell (BASH) 4.0 or higher
#   - Kornshell releases 2012 or later
#   - ZShell (ZSH) 4.x or higher
#
#---------------------------------------------------------------------------------------------------------------------
# GLOBAL INITIALIZATIONS
#---------------------------------------------------------------------------------------------------------------------

# Are we using BASH?
if [[ -n ${BASH} ]]
then
    if [[ ${BASH_VERSINFO[0]}$((${BASH_VERSINFO[1]}+0)) -lt 40 ]]
    then
        echo "System error: this is BASH version ${BASH_VERSION}. BaCon needs BASH 4.0 or higher to run!"
        exit 1
    fi
    # Set the extended globbing option in BASH
    shopt -s extglob
else
    # Check Kornshell version
    if [[ ${KSH_VERSION} = +(*MIRBSD*) || -n ${ZSH_NAME} ]]
    then
        alias echo="print -R"
    else
        ulimit -s unlimited
    fi

    # If run with Zshell then emulate KSH
    if [[ -n $ZSH_NAME ]]
    then
        if [[ ${ZSH_VERSION%%.*} -lt 4 ]]
        then
	    echo "System error: this is ZShell version ${ZSH_VERSION}. BaCon needs ZShell 4.x or higher to run!"
	    exit 1
        else
	    emulate ksh
        fi
    fi
fi

# Unset grep options
unset GREP_OPTIONS

# Version of BACON
typeset -rx g_VERSION="4.8"

# Our numerical environment is POSIX
export LC_NUMERIC="POSIX"

# Find coretools
if [[ -z `command -v cat` || -z `command -v rm` || -z `command -v tr` || -z `command -v touch` || -z `command -v uname` || -z `command -v head` || -z `command -v pwd` ]]
then
    echo "System error: 'cat', 'rm', 'tr', 'touch', 'uname', 'head' or 'pwd' not found on this system!"
    exit 1
fi

# Solaris
if [[ $(uname) = +(*SunOS*) ]]
then
    g_LDFLAGS="-lnsl -lsocket"
fi

# Haiku
if [[ $(uname) = +(*Haiku*) ]]
then
    g_LDFLAGS="-lbsd -lnetwork"
fi

# musl C
if [[ -n `command -v objdump` ]]
then
    if [[ $(objdump -p `command -v cat` | grep NEEDED) = +(*musl*) ]]
    then
        g_LDFLAGS="${g_LDFLAGS} -lfts"
    fi
fi

# Global constant for miniparsing
typeset -rx g_PARSEVAR=`echo -e "\001"`

# Global to define '$', '%' and '#'-replacement
typeset -rx g_STRINGSIGN="__b2c__string_var"
typeset -rx g_LONGSIGN="__b2c__long_var"
typeset -rx g_FLOATSIGN="__b2c__float_var"

# Global to define '"'-symbol
typeset -rx g_DQUOTESIGN=`echo -e "\042"`

# Global to define '''-symbol
typeset -rx g_SQUOTESIGN=`echo -e "\047"`

# Global to define CRLF combination
typeset -rx g_CRLF=`echo -e "\015\012"`

# Global to define TAB
typeset -rx g_TAB=`echo -e "\011"`

# Remember the original field separator
typeset -rx g_ORGIFS="${IFS}"

# Needed to prevent accidental variable names using C keywords
typeset -rx g_C_KEYWORDS="asm|auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|inline|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while|y0|y1|yn|y0f|y1f|ynf|y0l|y1l|ynl"

# Associative vars to keep track of BaCon variables
typeset -A g_ALL_MAIN_VARS g_ALL_FUNC_VARS g_SEMANTIC_OPENCLOSE g_SEMANTIC_MEMFREE g_MACRO_STRINGS

#-------------------------------------------------------$1 = variable name, $2 = function name

function Get_Var
{
    typeset VAR RECORD

    # In case of array assignments: exit
    if [[ ${1} = +(*\{*) || $(echo ${1}) = +(* *) ]]
    then
        return
    fi

    # Get rid of assignment notation
    if [[ ${1} = +(*\=*) ]]
    then
        VAR=$(echo ${1%%=*})
    else
        VAR=$(echo ${1})
    fi

    # Get rid of '*' sign in variable name
    VAR=${VAR//\*/}

    # Get rid of '&' sign in variable name
    VAR=${VAR//&/}

    # Get rid of '.' sign within variable name
    if [[ "${VAR//./}" != "${VAR}" ]]
    then
        RECORD=${VAR%%.*}
        VAR=${VAR##*.}
    else
        RECORD=${g_RECORDVAR}
    fi
    RECORD="${RECORD%%\[*}"

    # If there is a record name then add a "."
    if [[ -n $RECORD ]]
    then
        RECORD="${RECORD}."
    fi

    # Get rid of array notation
    if [[ ${VAR} = +(*\[*) ]]
    then
        VAR=${VAR%%\[*}
    fi

    # Get rid of brackets in case of function pointer or assoc var
    if [[ ${VAR} = +(*\(*) ]]
    then
        VAR=$(echo ${VAR%%\(*})
    fi

    # Get rid of type signs
    VAR=${VAR//\$/$g_STRINGSIGN}
    VAR=${VAR//\#/$g_FLOATSIGN}
    VAR=${VAR//\%/$g_LONGSIGN}

    # If plain text, skip. Also skip '}' to avoid eval clash.
    if [[ -n ${VAR} && "${VAR%%\(*}" != +(*${g_DQUOTESIGN}*) && "${VAR%%\(*}" != +(*\}*) ]]
    then
        # Always lookup type in MAIN
        echo ${g_ALL_MAIN_VARS[${RECORD}${VAR}]}

        # Lookup type in function if given
        if [[ -n ${2} && -z ${g_ALL_MAIN_VARS[${RECORD}${VAR}]} ]]
        then
            echo ${g_ALL_FUNC_VARS[${RECORD}${VAR}___${2}]}
        fi
    fi
}

function Save_Main_Var
{
    typeset STR TYPE NR VAR

    # Make sure the asterisk is attached to type
    if [[ ${1} = +(\**) ]]
    then
        STR=$(echo ${1//\*/})
        let NR=${#1}-${#STR}
        TYPE="$2"
        until [[ ${NR} -eq 0 ]]
        do
            TYPE="${TYPE}*"
            ((NR-=1))
        done
    else
        STR="$1"
        TYPE="$2"
    fi

    # Get rid of assignment notation
    if [[ ${STR} = +(*=*) ]]
    then
        STR=$(echo ${STR%%=*})
    else
        STR=$(echo ${STR})
    fi

    # Get rid of array notation
    if [[ ${STR} = +(*\[*\]*) ]]
    then
        STR=${STR%%\[*}
    fi

    if [[ -n ${g_RECORDVAR} ]]
    then
	if [[ -n ${STR} ]]
	then
	    VAR="${g_RECORDVAR%%\[*}.${STR}"
	else
	    VAR="${g_RECORDVAR%%\[*}"
	fi
    else
        VAR="${STR}"
    fi

    g_ALL_MAIN_VARS[${VAR}]=${TYPE}
}

function Save_Func_Var
{
    typeset STR TYPE NR VAR

    # If there is a function pointer, skip this function
    if [[ ${1} = +(\(*\)*) ]]
    then
        return
    fi

    # Make sure the asterisk is attached to type
    if [[ ${1} = +(\**) ]]
    then
        STR=$(echo ${1//\*/})
        let NR=${#1}-${#STR}
        TYPE="$3"
        until [[ ${NR} -eq 0 ]]
        do
            TYPE="${TYPE}*"
            ((NR-=1))
        done
    else
        STR="$1"
        TYPE="$3"
    fi

    # Get rid of assignment notation
    if [[ "${STR}" = +(*=*) ]]
    then
        STR=$(echo ${STR%%=*})
    else
        STR=$(echo ${STR})
    fi

    # Get rid of array notation
    if [[ ${STR} = +(*\[*\]*) ]]
    then
        STR=${STR%%\[*}
    fi

    if [[ -n ${g_RECORDVAR} ]]
    then
        VAR="${g_RECORDVAR%%\[*}.${STR}___${2}"
    else
        VAR="${STR}___${2}"
    fi

    g_ALL_FUNC_VARS[${VAR}]=${TYPE}
}

function Debug_Vars
{
    typeset i

    if [[ ${#g_ALL_MAIN_VARS[@]} -gt 0 ]]
    then
        for i in ${!g_ALL_MAIN_VARS[@]}
        do
            i=${i//_____/.}
            echo -n "${g_ALL_MAIN_VARS[$i]}:MAIN:${i} " >&2
        done
        echo
    fi

    if [[ ${#g_ALL_FUNC_VARS[@]} -gt 0 ]]
    then
        for i in ${!g_ALL_FUNC_VARS[@]}
        do
            i=${i//_____/.}
            echo -n "${g_ALL_FUNC_VARS[$i]}:${i##*___}:${i%%___*} " >&2
        done
        echo
    fi
}

# This function registers variables. $1 = var to be declared, $2 type of var
function Register_Numeric
{
    if [[ -z $(Get_Var ${1} ${g_FUNCNAME}) ]]
    then
        # Variable may not be class, array member, record, assoc, or pointer
        if [[ ${1} != +(*::*) && ${1} != +(*\[*\]*) && ${1} != +(*.*) && ${1} != +(*\(*\)*) && ${1} != +(*\-\>*) ]]
        then
            if [[ $g_OPTION_EXPLICIT = "1" || $g_OPTION_EXPLICIT = "TRUE" ]]
            then
	        echo -e "\nSyntax error: OPTION EXPLICIT forces explicit variable declaration at line $g_COUNTER in file '$g_CURFILE'!"
                exit 1
            fi
            if [[ ${2} != "default" ]]
            then
	        echo "${2} ${1} = 0;" >> $g_HFILE
                Save_Main_Var "${1}" "${2}"
            else
	        if [[ "${1}" = +(*${g_FLOATSIGN}) ]]
	        then
                    echo "double ${1} = 0.0;" >> $g_HFILE
                    Save_Main_Var "${1}" "double"
                elif [[ "${1}" = +(*${g_LONGSIGN}) ]]
                then
                    echo "long ${1} = 0;" >> $g_HFILE
                    Save_Main_Var "${1}" "long"
                else
                    echo "${g_VARTYPE} ${1} = 0;" >> $g_HFILE
                    Save_Main_Var "${1}" "${g_VARTYPE}"
                fi
            fi
        fi
    fi
}

function Register_Pointer
{
    if [[ -z $(Get_Var ${1} ${g_FUNCNAME}) ]]
    then
        # Variable may not be record, nor pointer
        if [[ "${1}" != +(*.*) && "${1}" != +(*\-\>*) ]]
        then
            if [[ $g_OPTION_EXPLICIT = "1" || $g_OPTION_EXPLICIT = "TRUE" ]]
            then
	        echo -e "\nSyntax error: OPTION EXPLICIT forces explicit variable declaration at line $g_COUNTER in file '$g_CURFILE'!"
                exit 1
            fi
            echo "${2} ${1} = NULL;" >> $g_HFILE
            Save_Main_Var "${1}" "${2}"
        fi
    fi
}

#-----------------------------------------------------------

function Trim
{
    typeset TRIMMED=${1}

    while [[ ${TRIMMED} = ' '* ]]
    do
       TRIMMED="${TRIMMED## }"
    done
    while [[ ${TRIMMED} = *' ' ]]
    do
       TRIMMED="${TRIMMED%% }"
    done

    echo "${TRIMMED}"
}

#-----------------------------------------------------------
# Find BaCon keywords but they may not be enclosed within
#    doublequotes.

function Lexer
{
    typeset STRING DATA CHUNK POS=0 COUNT=1

    if [[ ${2} =~ "\"" ]]
    then
        STRING=${2//\\\\/__}
        STRING=${STRING//\\\"/__}
        until [[ $((${#COUNT}%2)) = 0 ]]
        do
            DATA=${STRING:${POS}}
            CHUNK="${DATA%%${1}*}"
            ((POS=${POS}+${#CHUNK}))

            DATA=${STRING:0:${POS}}
            COUNT=${DATA//[^\"]}
            ((POS+=1))
        done
        ((POS-=1))
    else
        CHUNK=${2%%${1}*}
        POS=${#CHUNK}
    fi

    if [[ ${POS} -eq ${#2} ]]
    then
        POS=""
    fi
    echo ${POS}
}

#-----------------------------------------------------------
# Mini parser to obtain chunk of text separated by comma. The comma in function arguments is ignored.
# This function will attach the last ")" in case of a function and then jump out.

function Mini_Parser
{
    # Local variables
    typeset LINE TOKEN LEN CHAR
    typeset -i IN_STRING IN_FUNC ESCAPED

    let ESCAPED=0
    let IN_STRING=0
    let IN_FUNC=0

    LINE=$(echo ${1// /${g_PARSEVAR}})
    TOKEN=
    LEN=${#LINE}

    # Get the characters
    until [[ $LEN -eq 0 || $IN_FUNC -lt 0 ]]
    do
        if [[ -n ${2} ]]
        then
	    CHAR="${LINE:0:3}"
            case $CHAR in
                ${2})
		    if [[ $IN_STRING -eq 0 && $IN_FUNC -eq 0 ]]
		    then
                        if [[ ${#TOKEN} -gt 0 ]]
                        then
                            break
                        fi
		    fi;;
            esac
        fi
	CHAR="${LINE:0:1}"
	case $CHAR in
	    ","|";")
		if [[ $IN_STRING -eq 0 && $IN_FUNC -eq 0 ]]
		then
                    if [[ ${#TOKEN} -gt 0 ]]
                    then
                        break
                    fi
		fi;;
	    "\\")
		if [[ $ESCAPED -eq 0 ]]
		then
		    ESCAPED=1
		else
		    ESCAPED=0
		fi;;
	    "\"")
		if [[ $ESCAPED -eq 0 ]]
		then
		    if [[ $IN_STRING -eq 0 ]]
		    then
			IN_STRING=1
		    else
			IN_STRING=0
		    fi
		fi
		ESCAPED=0;;
	    "(")
		if [[ $IN_STRING -eq 0 ]]
		then
		    ((IN_FUNC=$IN_FUNC+1))
		fi
		ESCAPED=0;;
	    ")")
		if [[ $IN_STRING -eq 0 ]]
		then
		    ((IN_FUNC=$IN_FUNC-1))
		fi
		ESCAPED=0;;
	    *)
		ESCAPED=0;;
	esac
	# Convert back to space
	if [[ "${CHAR}" = "${g_PARSEVAR}" ]]
	then
	    TOKEN="${TOKEN} "
	else
	    TOKEN="${TOKEN}${CHAR}"
	fi
	let LEN=${#LINE}-1
	LINE="${LINE: -$LEN}"
    done

    if [[ $IN_FUNC -lt 0 ]]
    then
	let LEN=${#TOKEN}-1
	TOKEN="${TOKEN:0:${LEN}}"
    fi

    echo "${TOKEN}"
}

#-----------------------------------------------------------

function Check_String_Type
{
    typeset VAR TYPE

    VAR=$(Trim "${1}")

    # Get rid of casting in array indicators
    VAR="${VAR//\(uint64_t\)/}"

    # Remove part after '(' in case of function or assoc array
    while [[ ${VAR:0:1} = "(" ]]
    do
        VAR=${VAR:1}
    done
    VAR=$(echo ${VAR%%\(*})

    # It contains double quotes or ends with '$' symbol (Parse_Equation)
    if [[ "${VAR}" = +(*${g_DQUOTESIGN}*) || "${VAR}" = +(*$) ]]
    then
	echo 1
    else
        # Check variable registration
	TYPE=$(Get_Var "${VAR}" ${g_FUNCNAME})
    
        if [[ -n ${TYPE} ]]
        then
            if [[ ${TYPE} = +(*char\**|*STRING*) ]]
            then
                echo 1
            else
                echo 0
            fi
        elif [[ "${VAR}" = +(*${g_STRINGSIGN}*) && "${VAR}" != +(*__b2c_array*) ]]
	then
	    echo 1
	else
	    echo 0
	fi
    fi
}

#-----------------------------------------------------------$1=source $2=destination $3=memsize

function Assign_To_String
{
    typeset INDEX

    if [[ "${2}" = +(*\(*\)) ]]
    then
        INDEX=${2#*\(}
        echo "__b2c__hash_add_str(__b2c__assoc_${2%%\(*}, ${1}, ${INDEX%\)*});" >> $g_CFILE
        echo "__b2c__STRFREE(${1}); ${1} = NULL;" >> $g_CFILE
        # Check for relations
        Relate_Recurse "${2%%\(*}" "${INDEX}" "${2}" "-1"
    elif [[ $(Check_String_Type ${2}) -eq 1 ]]
    then
        if [[ ${2} = +(*${g_STRINGSIGN}*) ]]
        then
            echo "${2} = __b2c_Copy_String(${2}, ${1});" >> $g_CFILE
            echo "__b2c__STRFREE(${1}); ${1} = NULL;" >> $g_CFILE
        else
            echo "__b2c__STRFREE(${2}); ${2} = ${1};" >> $g_CFILE
        fi
    else
        echo "memcpy((void*)(${2}), (void*)${1}, ${3}); free(${1});" >> $g_CFILE
    fi
}

#-----------------------------------------------------------$1=source $2=destination $3=ASCII or nr

function Assign_To_Number
{
    typeset CHECK STR

    # Get the type
    if [[ "${2}" = +(*\(*\)) ]]
    then
        CHECK=$(Get_Var __b2c__assoc_${2} ${g_FUNCNAME})
    else
        CHECK=$(Get_Var ${2} ${g_FUNCNAME})
    fi

    # Now see if we have an assoc or a normal variable
    if [[ "${2}" = +(*\(*\)) ]]
    then
        STR=${2#*\(}
        if [[ ${3} -eq 1 ]]
        then
            if [[ "$CHECK" = +(*double*) || "$CHECK" = +(*float*) || "$CHECK" = +(*FLOATING*) ]]
            then
                echo "__b2c__assoc_${2%%\(*}_eval = atof(${1});" >> $g_CFILE
	    elif [[ "$CHECK" = +(*long*) || "$CHECK" = +(*NUMBER*) ]]
	    then
	        echo "__b2c__assoc_${2%%\(*}_eval = atol(${1});" >> $g_CFILE
	    else
	        echo "__b2c__assoc_${2%%\(*}_eval = atoi(${1});" >> $g_CFILE
	    fi
            echo "free(${1}); ${1} = NULL;" >> $g_CFILE
        else
	    echo "__b2c__assoc_${2%%\(*}_eval = (${CHECK})(${1});" >> $g_CFILE
        fi
        echo "__b2c__hash_add(__b2c__assoc_${2%%\(*}, &__b2c__assoc_${2%%\(*}_eval, ${STR%\)*});" >> $g_CFILE
	# Check for relations
	Relate_Recurse "${2%%\(*}" "${STR}" "${2}" "-1"
    else
        if [[ ${3} -eq 1 ]]
        then
	    if [[ "$CHECK" = +(*double*) || "$CHECK" = +(*float*) || "$CHECK" = +(*FLOATING*) ]]
	    then
                echo "${2} = atof(${1});" >> $g_CFILE
	    elif [[ "$CHECK" = +(*long*) || "$CHECK" = +(*NUMBER*) ]]
	    then
	        echo "${2} = atol(${1});" >> $g_CFILE
	    else
	        echo "${2} = atoi(${1});" >> $g_CFILE
	    fi
            echo "free(${1}); ${1} = NULL;" >> $g_CFILE
        else
            echo "${2} = (${CHECK})(${1});" >> $g_CFILE
        fi
    fi
}

#----------------------------------------------------------- $2 = stdout or stderr

function Print_Element
{
    # If argument 1 does not contain an actual string
    if [[ ${1} = "stdout" || ${1} = "stderr" ]]
    then
        return
    fi

    # Check if var is string var
    if [[ $(Check_String_Type ${1}) -eq 1 ]]
    then
        echo "__b2c__assign = (char*)${1}; if(__b2c__assign != NULL) { fputs(__b2c__assign, ${2}); }" >> $g_CFILE
    else
	echo "fputs(STR${g_STRINGSIGN}(${1}), ${2});" >> $g_CFILE
    fi
}

#----------------------------------------------------------- $2 = stdout or stderr

function Handle_Print
{
    typeset FORMAT EXP LEN TOKEN TO CHECK SIZE POS ARGS=${1}

    # If no argument, do nothing
    if [[ "${ARGS}" != "PRINT" && "${ARGS}" != "EPRINT" ]]
    then
        # Get the arguments
        POS=$(Lexer " SIZE " "${ARGS}")
        if [[ -n ${POS} ]]
        then
            SIZE=$(Trim "${ARGS:$((${POS}+6))}")
            ARGS=$(Trim "${ARGS:0:${POS}}")
        else
            SIZE=${g_BUFFER_SIZE}
        fi
        POS=$(Lexer " TO " "${ARGS}")
        if [[ -n ${POS} ]]
        then
            TO=$(Trim "${ARGS:$((${POS}+4))}")
            ARGS=$(Trim "${ARGS:0:${POS}}")
        fi
        POS=$(Lexer " FORMAT " "${ARGS}")
        if [[ -n ${POS} ]]
        then
            FORMAT=$(Trim "${ARGS:$((${POS}+8))}")
            ARGS=$(Trim "${ARGS:0:${POS}}")
        fi
        EXP=${ARGS}
        if [[ -n $FORMAT ]]
        then
            if [[ -n $TO ]]
            then
                # Check if string is declared
                if [[ "${TO}" = +(*${g_STRINGSIGN}) ]]
	        then
                    Register_Pointer "${TO}" "char*"
                elif [[ "${TO}" != +(*${g_STRINGSIGN}\(*\)) ]]
                then
	            echo -e "\nSyntax error: variable for PRINT at line $g_COUNTER in file '$g_CURFILE' must be string!"
	            exit 1
	        fi
                if [[ "${TO}" = +(*\(*\)) ]]
                then
                    INDEX=${TO#*\(}
                    echo "snprintf(__b2c__hash_realloc_str_value(__b2c__assoc_${TO%%\(*}, ${SIZE}+1, ${INDEX%\)*}), ${SIZE}+1, ${FORMAT}, ${EXP});" >> $g_CFILE
                    Relate_Recurse "${TO%%\(*}" "${INDEX}" "${TO}" "-1"
                else
                    echo "${TO} = (char*)__b2c_str_realloc(${TO}, (${SIZE}+1)*sizeof(char));" >> $g_CFILE
                    echo "snprintf(${TO}, ${SIZE}+1, ${FORMAT}, ${EXP}); __b2c__SETLEN(${TO}, strlen(${TO}));" >> $g_CFILE
                fi
	    else
		echo "fprintf(${2}, ${FORMAT%%;*}, ${EXP});" >> $g_CFILE
	    fi
	else
            # Start miniparser
            while [[ -n ${EXP} ]]
            do
                TOKEN=$(Mini_Parser "${EXP}")
	        Print_Element "${TOKEN}" "${2}"
                EXP="${EXP:${#TOKEN}+1}"
            done
            # If line ends with ';' then skip newline
	    if [[ -n $(echo ${1##*;}) ]]
	    then
		echo "fputs(\"\n\", ${2});" >> $g_CFILE
            else
                echo "fflush(${2});" >> $g_CFILE
	    fi
	fi
    else
	echo "fputs(\"\n\", ${2});" >> $g_CFILE
    fi
}

#-----------------------------------------------------------

function Handle_Input
{
    # Local variables
    typeset CHECK VAR STR EXP TOKEN

    # Check if we have an argument at all
    if [[ "$1" = "INPUT" ]]
    then
	echo -e "\nSyntax error: empty INPUT at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    EXP="${1}"

    # Start miniparser to see if we need to print something
    while [[ -n ${EXP} ]]
    do
        TOKEN=$(Mini_Parser "${EXP}")
        EXP="${EXP:${#TOKEN}+1}"
        if [[ -n ${EXP} ]]
        then
	    Print_Element "${TOKEN}" "stdout"
        fi
    done
    echo "fflush(stdout);" >> $g_CFILE

    # Remove spaces in variable
    VAR=$(echo ${TOKEN})

    # Check if string is declared
    if [[ "${VAR}" = +(*${g_STRINGSIGN}) ]]
    then
        Register_Pointer "${VAR}" "char*"
    else 
        Register_Numeric "${VAR}" "default"
    fi

    # Translate function to C function
    echo "__b2c__input(__LINE__, __FILE__, &__b2c__assign, ${g_OPTION_INPUT});" >> $g_CFILE

    if [[ $(Check_String_Type ${VAR}) -eq 1 ]]
    then
        Assign_To_String "__b2c__assign" "${VAR}"
    else
        Assign_To_Number "__b2c__assign" "${VAR}" 1
    fi
}

#-----------------------------------------------------------

function Handle_For
{
    # Local variables
    typeset FROM TO IN VAR STEP POS ARGS=${1}

    # Check if TO is available
    if [[ "${1}" != +(* TO *) && "${1}" != +(* DOWNTO *) && "${1}" != +(* IN *) ]]
    then
	echo -e "\nSyntax error: missing IN/TO/DOWNTO in FOR statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # What kind of FOR are we dealing with
    if [[ "${1}" = +(* TO *) || "${1}" = +(* DOWNTO *) ]]
    then
        # Get the arguments
        POS=$(Lexer " STEP " "${ARGS}")
        if [[ -n ${POS} ]]
        then
            STEP=$(Trim "${ARGS:$((${POS}+6))}")
            ARGS=$(Trim "${ARGS:0:${POS}}")
        else
            STEP=1
        fi
        POS=$(Lexer " TO " "${ARGS}")
        if [[ -n ${POS} ]]
        then
            TO=$(Trim "${ARGS:$((${POS}+4))}")
            ARGS=$(Trim "${ARGS:0:${POS}}")
        fi
        POS=$(Lexer " DOWNTO " "${ARGS}")
        if [[ -n ${POS} ]]
        then
            TO=$(Trim "${ARGS:$((${POS}+8))}")
            ARGS=$(Trim "${ARGS:0:${POS}}")
            STEP="-${STEP}"
        fi
        POS=$(Lexer "=" "${ARGS}")
        FROM=$(Trim "${ARGS:$((${POS}+1))}")
        VAR=$(Trim "${ARGS:0:${POS}}")
    else
        # Get the arguments
        POS=$(Lexer " STEP " "${ARGS}")
        if [[ -n ${POS} ]]
        then
            STEP=$(Trim "${ARGS:$((${POS}+6))}")
            ARGS=$(Trim "${ARGS:0:${POS}}")
        else
	    STEP="__b2c__option_delim"
        fi
        POS=$(Lexer " IN " "${ARGS}")
        IN=$(Trim "${ARGS:$((${POS}+4))}")
        VAR=$(Trim "${ARGS:0:${POS}}")
        # Define help variables
        if [[ -n $g_FUNCNAME ]]
        then
	    if [[ ${g_STRINGARGS} != +(*__b2c__forin_${VAR}_ptr*) ]]
	    then
                g_STRINGARGS="${g_STRINGARGS} int __b2c__forin_${VAR}_ptr = 0;"
                Save_Func_Var "__b2c__forin_${VAR}_ptr" "${g_FUNCNAME}" "int"
                g_STRINGARGS="${g_STRINGARGS} char* __b2c__forin_${VAR}_string = NULL;"
                Save_Func_Var "__b2c__forin_${VAR}_string" "${g_FUNCNAME}" "char*"
                g_STRINGARGS="${g_STRINGARGS} char* __b2c__forin_${VAR}_string_org = NULL;"
                Save_Func_Var "__b2c__forin_${VAR}_string_org" "${g_FUNCNAME}" "char*"
                g_STRINGARGS="${g_STRINGARGS} char* __b2c__forin_${VAR}_step = NULL;"
                Save_Func_Var "__b2c__forin_${VAR}_step" "${g_FUNCNAME}" "char*"
                g_STRINGARRAYS="${g_STRINGARRAYS} __b2c__STRFREE(__b2c__forin_${VAR}_string); __b2c__forin_${VAR}_string = NULL;"
                g_STRINGARRAYS="${g_STRINGARRAYS} __b2c__STRFREE(__b2c__forin_${VAR}_step); __b2c__forin_${VAR}_step = NULL;"
            fi
        else
            if [[ -z $(Get_Var __b2c__forin_${VAR}_ptr) ]]
	    then
                echo "int __b2c__forin_${VAR}_ptr = 0;" >> $g_HFILE
                Save_Main_Var "__b2c__forin_${VAR}_ptr" "int"
                echo "char *__b2c__forin_${VAR}_string = NULL;" >> $g_HFILE
                Save_Main_Var "__b2c__forin_${VAR}_string" "char*"
                echo "char *__b2c__forin_${VAR}_string_org = NULL;" >> $g_HFILE
                Save_Main_Var "__b2c__forin_${VAR}_string_org" "char*"
                echo "char *__b2c__forin_${VAR}_step = NULL;" >> $g_HFILE
                Save_Main_Var "__b2c__forin_${VAR}_step" "char*"
            fi
        fi
    fi

    # Check if string is declared
    if [[ "${VAR}" = +(*${g_STRINGSIGN}) ]]
    then
        Register_Pointer "${VAR}" "char*"
    # Not a string?
    elif [[ $FROM$TO$STEP = +(*[0-9]*.*[0-9]*) || $(Get_Var ${STEP#*-} ${g_FUNCNAME}) = +(*double*|*float*|*FLOATING*) ]]
    then
        Register_Numeric "${VAR}" "double"
    else 
        Register_Numeric "${VAR}" "default"
    fi

    # Check type of var, string?
    if [[ $(Check_String_Type ${VAR}) -eq 1 ]]
    then
        echo "__b2c__forin_${VAR}_string = __b2c_Copy_String(__b2c__forin_${VAR}_string, ${IN}); __b2c__forin_${VAR}_string_org = __b2c__forin_${VAR}_string;" >> $g_CFILE
        echo "__b2c__forin_${VAR}_step = __b2c_Copy_String(__b2c__forin_${VAR}_step, ${STEP});" >> $g_CFILE
        echo "__b2c__forin_${VAR}_ptr = __b2c__for_amount(__b2c__forin_${VAR}_string, __b2c__forin_${VAR}_step);" >> $g_CFILE
        echo "for(; __b2c__forin_${VAR}_ptr > 0; __b2c__forin_${VAR}_ptr--) { __b2c__for_item(&__b2c__forin_${VAR}_string_org, __b2c__forin_${VAR}_step, &${VAR});" >> $g_CFILE
    # Var is numeric
    else
        # Translate function to C function
        if [[ "${STEP}" = +(*-*) ]]
        then
	    echo "for($VAR=$FROM; $VAR >= $TO; $VAR+=$STEP){" >> $g_CFILE
        else
	    echo "for($VAR=$FROM; $VAR <= $TO; $VAR+=$STEP){" >> $g_CFILE
        fi
    fi
}

#-----------------------------------------------------------

function Handle_While
{
    # Check if DO is available
    if [[ "$1" != +(* DO) ]]
    then
        Parse_Equation "${1}"
    else
        Parse_Equation "${1% *}"
    fi
    echo "while(${g_EQUATION}){" >> $g_CFILE
}

#-----------------------------------------------------------
# $1: name of ASSOC variable
# $2: name of index
# $3: actual value to assign
# $4: recursion level

function Relate_Recurse
{
    typeset CTR REL LVL

    # Check endless recursion
    LVL=${4}; ((LVL+=1))
    if [[ $LVL -gt $g_RELATE_CTR ]]
    then
	echo -e "\nSyntax error: endless recursion in RELATE statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Now add relation
    CTR=0

    while [[ $CTR -lt $g_RELATE_CTR ]]
    do
	if [[ ${g_RELATE[${CTR}]} = +(${1}*) ]]
	then
	    REL=${g_RELATE[${CTR}]##* }
	    if [[ "${REL}" = +(*${g_STRINGSIGN}*) ]]
	    then
                echo "__b2c__hash_add_str(__b2c__assoc_${REL}, ${3}, ${2%\)*});" >> $g_CFILE
	    else
                echo "__b2c__assoc_${REL}_eval = ${3}; __b2c__hash_add(__b2c__assoc_${REL}, &__b2c__assoc_${REL}_eval, ${2%\)*});" >> $g_CFILE
	    fi
	    Relate_Recurse "${REL}" "${2}" "${3}" "${LVL}"
	fi
	((CTR+=1))
    done
}

#-----------------------------------------------------------

function Handle_Let
{
    # Local variables
    typeset VAR TYPE TMP STR ARG PTR CHAR ESCAPED IN_STRING LINE IN_FUNC
    typeset -i POS LEN

    # Start miniparser to find last unquoted '='
    POS=0
    LEN=${#1}
    LINE="$1"

    # Get the characters
    until [[ $LEN -eq 0 ]]
    do
	CHAR="${LINE:0:1}"
	case $CHAR in
	    "\\")
		if [[ $ESCAPED -eq 1 ]]
		then
		    ESCAPED=0
                else
		    ESCAPED=1
                fi;;
	    "\"")
		if [[ $ESCAPED -eq 0 ]]
		then
		    if [[ $IN_STRING -eq 0 ]]
		    then
			IN_STRING=1
		    else
			IN_STRING=0
		    fi
		fi
		ESCAPED=0;;
	    "(")
		if [[ $IN_STRING -eq 0 ]]
		then
		    ((IN_FUNC=$IN_FUNC+1))
		fi
		ESCAPED=0;;
	    ")")
		if [[ $IN_STRING -eq 0 ]]
		then
		    ((IN_FUNC=$IN_FUNC-1))
		fi
		ESCAPED=0;;
	    "=")
		if [[ $IN_STRING -eq 0 && $IN_FUNC -eq 0 ]]
		then
		    let POS=${#1}-${LEN}
		fi
		ESCAPED=0;;
	    *)
		ESCAPED=0;;
	esac
	let LEN=${#LINE}-1
	LINE="${LINE: -$LEN}"
    done

    # Check if there is an assignment at all, if not exit
    if [[ ${POS} -eq 0 ]]
    then
        if [[ $g_IGNORE_PARSE = "0" || $g_IGNORE_PARSE = "FALSE" ]]
        then
            echo "$1;" >> $g_CFILE
            return
        else
	    echo -e "\nSyntax error: could not parse line $g_COUNTER in file '$g_CURFILE': \"${1}\""
	    exit 1
        fi
    fi

    # Get the variablename without surrounding spaces
    VAR=$(echo ${1:0:${POS}})
    ((POS+=1))
    TMP="${1:${POS}}"

    # Check for MEMORY allocation
    if [[ ${TMP} = +(*MEMORY*\(*) || ${TMP} = +(*BLOAD*\(*) ]]
    then
	g_SEMANTIC_MEMFREE[${VAR}]="'${VAR}' at line $g_COUNTER in file '$g_CURFILE'"
    fi

    # Check if var is string var, exclude RECORD elements
    if [[ "${VAR}" = +(*${g_STRINGSIGN}) && $g_DYNAMICARRAYS != +(* ${VAR}@${g_FUNCNAME} *) ]]
    then
        Register_Pointer "${VAR}" "char*"
    elif [[ "$VAR" != +(*=*) && "$VAR" != +(*\-\>*) ]]
    then
        if [[ ${TMP} = +(*[0-9].[0-9]*) && "$TMP" != +(*$g_DQUOTESIGN*) ]]
        then
            Register_Numeric "${VAR//[+\-\*\/% ]/}" "double"
        else
            Register_Numeric "${VAR//[+\-\*\/% ]/}" "default"
        fi
    fi

    # Check if there is associative array assignment
    if [[ "${VAR}" = +(*\(*\)) ]]
    then
        TMP=$(Trim "${TMP}")
        if [[ "${VAR}" = +(*\(\)) ]]
        then
            if [[ "${VAR%%\(*}" = +(*${g_STRINGSIGN}*) ]]
            then
                echo "__b2c__hash_dup_str(__b2c__assoc_${TMP%%\(*}, __b2c__assoc_${VAR%%\(*});" >> $g_CFILE
            else
                echo "__b2c__hash_dup(__b2c__assoc_${TMP%%\(*}, __b2c__assoc_${VAR%%\(*});" >> $g_CFILE
            fi
        else
	    STR=${VAR#*\(}
	    if [[ "${VAR%%\(*}" = +(*${g_STRINGSIGN}*) ]]
	    then
                echo "__b2c__hash_add_str(__b2c__assoc_${VAR%%\(*}, ${TMP}, ${STR%\)*});" >> $g_CFILE
	    else
                echo "__b2c__assoc_${VAR%%\(*}_eval = ${TMP}; __b2c__hash_add(__b2c__assoc_${VAR%%\(*}, &__b2c__assoc_${VAR%%\(*}_eval, ${STR%\)*});" >> $g_CFILE
	    fi
	    # Check for relations
	    Relate_Recurse "${VAR%%\(*}" "${STR}" "${TMP}" "-1"
        fi

    # Is there an array variable without subscript (dynamic array) -> assignment to STATIC returned arrays
    elif [[ "${VAR}" != +(*\[*\]*) && $g_DYNAMICARRAYS = +(* ${VAR}@${g_FUNCNAME} *) ]]
    then
	if [[ "${VAR}" = +(*${g_STRINGSIGN}*) ]]
        then
            echo "__b2c__free_str_array_members(&${VAR}, ${g_OPTION_BASE}, ${VAR}__b2c_array);" >> $g_CFILE
        fi
        echo "free($VAR);" >> $g_CFILE
	echo "${g_WITHVAR}${1};" >> $g_CFILE

    # Do we have a STRING variable or STRING array?
    elif [[ $(Check_String_Type ${VAR}) -eq 1 && ${VAR} = +(*${g_STRINGSIGN}*) ]]
    then
        TYPE=$(Get_Var ${VAR} ${g_FUNCNAME})
        # Check if it is some variable directly assigned
        if [[ $TYPE = +(*const*) ]]
        then
            echo "${g_WITHVAR}${VAR} = (char*)__b2c__strdup((const char*)${TMP});" >> $g_CFILE
	    if [[ -n ${g_FUNCNAME} ]]
            then
	        Save_Func_Var "${VAR}" "${g_FUNCNAME}" "${TYPE##*const }"
            else
                Save_Main_Var "${VAR}" "${TYPE##*const }"
            fi
        else
            # Memory optimizations for string functions
            if [[ ${TMP// /} = +(CONCAT${g_STRINGSIGN}*|MID${g_STRINGSIGN}*|APPEND${g_STRINGSIGN}*|CHOP${g_STRINGSIGN}*) ]]
            then
                STR=${TMP%%\(*}
                let LEN=${#STR}+1
                echo "${g_WITHVAR}${VAR} = F_${STR// /}(${g_WITHVAR}${VAR},${TMP:${LEN}};" >> $g_CFILE
            else
                echo "${g_WITHVAR}${VAR} = __b2c_Copy_String(${g_WITHVAR}${VAR}, (char*)${TMP});" >> $g_CFILE
            fi
        fi
	# Also check if string var already is used for IMPORT, if so, perform dlopen again
        PTR="${VAR//[[:punct:]]/}"
        if [[ -n $(Get_Var __b2c__dlopen__pointer_$PTR) ]]
	then
	    echo "__b2c__dlopen__pointer_$PTR = dlopen($VAR, RTLD_LAZY); if(__b2c__dlopen__pointer_$PTR == NULL)" >> $g_CFILE
	    echo "{ if(__b2c__trap){ERROR = 3; if(!__b2c__catch_set) RUNTIMEERROR(\"IMPORT\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO; } }" >> $g_CFILE
	fi
	# Check for array member in RECORD
	if [[ ${VAR} = +(*\.*) && ${VAR%%.*} = +(*\[*\]*) && -n ${g_FUNCNAME} && -z $(Get_Var ${VAR}) ]]
	then
	    if [[ ${g_LOCALSTRINGS} != "${VAR}" && ${VAR#*.} != +(*\[*\]*) ]]
	    then
		g_LOCALSTRINGS="$VAR $g_LOCALSTRINGS"
	    fi
	fi
    # Pointer type
    elif [[ ${VAR} = +(*\-\>*) ]]
    then
	echo "${g_WITHVAR}${1};" >> $g_CFILE
    # Pointer to string
    elif [[ "${VAR}" != +(*${g_STRINGSIGN}) && ${TMP} = +(*${g_STRINGSIGN}) ]]
    then
        TYPE=$(Get_Var ${VAR} ${g_FUNCNAME})
        echo "${g_WITHVAR}${VAR}=(${TYPE})(${TMP});" >> $g_CFILE
    # Numeric or foreign type
    else
        TYPE=$(Get_Var ${VAR} ${g_FUNCNAME})
        TYPE=${TYPE//static/}
        # Cast the expression to type of variable, divide symbol needs extra cast
        if [[ ${TYPE} = +(*float*|*double*|*FLOATING*) && ${TYPE} != +(*\**) ]]
        then
            # FIXME: the '/' sign in string literals (if they occur) now also is converted, but should not happen
            echo "${g_WITHVAR}${VAR}=(${TYPE})(${TMP//\///(${TYPE})});" >> $g_CFILE
        elif [[ ${VAR} = +(*\[*\]*) && ${TYPE} = +(*\**) ]]
        then
	    echo "${g_WITHVAR}${1};" >> $g_CFILE
        # If var is pointer then skip casting
        elif [[ -n ${TYPE} && $VAR != +(\**) ]]
        then
            echo "${g_WITHVAR}${VAR}=(${TYPE})(${TMP});" >> $g_CFILE
        # Other type
        else
	    echo "${g_WITHVAR}${1};" >> $g_CFILE
        fi
    fi
}

#-----------------------------------------------------------

function Handle_Open
{
    # Local variables
    typeset VAR MODE HANDLE FROM CHECK POS ARGS=${1}

    # Check if FOR is available
    if [[ "${1}" != +(* FOR *) ]]
    then
	echo -e "\nSyntax error: missing FOR in OPEN statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Check if AS is available
    if [[ "${1}" != +(* AS *) ]]
    then
	echo -e "\nSyntax error: missing AS in OPEN statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " AS " "${ARGS}")
    HANDLE=$(Trim "${ARGS:$((${POS}+4))}")
    ARGS=$(Trim "${ARGS:0:${POS}}")
    POS=$(Lexer " FROM " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        FROM=$(Trim "${ARGS:$((${POS}+6))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    else
	FROM="NULL"
    fi
    POS=$(Lexer " FOR " "${ARGS}")
    MODE=$(Trim "${ARGS:$((${POS}+5))}")
    VAR=$(Trim "${ARGS:0:${POS}}")

    # Check if var is string var
    if [[ "${HANDLE}" = +(*${g_STRINGSIGN}) && ${MODE} != "MEMORY" ]]
    then
	echo -e "\nSyntax error: variable for OPEN at line ${g_COUNTER} in file '${g_CURFILE}' cannot be string!"
	exit 1
    fi

    # Check for OPEN/CLOSE pair
    g_SEMANTIC_OPENCLOSE[${HANDLE}]="'${HANDLE}' at line $g_COUNTER in file '$g_CURFILE'"

    # Check if variable was declared
    if [[ "$HANDLE" != +(*.*) ]]
    then
        CHECK=$(Get_Var ${HANDLE} ${g_FUNCNAME})
    else
        CHECK="1"
    fi
    if [[ -z $CHECK ]]
    then
        if [[ ${MODE} = "DIRECTORY" ]]
        then
            Register_Pointer "${HANDLE}" "DIR*"
        elif [[ $MODE = "MEMORY" ]]
        then
            Register_Pointer "${HANDLE}" "char*"
        elif [[ $MODE = "NETWORK" || $MODE = "SERVER" || $MODE = "UDP" || $MODE = "DEVICE" ]]
        then
            Register_Numeric "${HANDLE}" "uintptr_t"
        else
            Register_Pointer "${HANDLE}" "FILE*"
        fi
    fi

    # Convert to C syntax
    case $MODE in
	@(READING) )
	    echo "$HANDLE = fopen((const char*)${VAR}, \"r\");" >> $g_CFILE
	    echo "if($HANDLE == NULL){if(__b2c__trap){ERROR = 2; if(!__b2c__catch_set) RUNTIMEERROR(\"OPEN FOR READING\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE;;
	@(WRITING) )
	    echo "$HANDLE = fopen((const char*)${VAR}, \"w\");" >> $g_CFILE
	    echo "if($HANDLE == NULL){if(__b2c__trap){ERROR = 2; if(!__b2c__catch_set) RUNTIMEERROR(\"OPEN FOR WRITING\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE;;
	@(APPENDING) )
	    echo "$HANDLE = fopen((const char*)${VAR}, \"a\");" >> $g_CFILE
	    echo "if($HANDLE == NULL){if(__b2c__trap){ERROR = 2; if(!__b2c__catch_set) RUNTIMEERROR(\"OPEN FOR APPENDING\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE;;
	@(READWRITE) )
	    echo "$HANDLE = fopen((const char*)${VAR}, \"r+\");" >> $g_CFILE
	    echo "if($HANDLE == NULL){if(__b2c__trap){ERROR = 2; if(!__b2c__catch_set) RUNTIMEERROR(\"OPEN FOR READWRITE\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE;;
	@(DIRECTORY) )
	    echo "$HANDLE = opendir(${VAR});" >> $g_CFILE
	    echo "if($HANDLE == NULL){if(__b2c__trap){ERROR = 2; if(!__b2c__catch_set) RUNTIMEERROR(\"OPEN FOR DIRECTORY\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE;;
	@(MEMORY) )
            if [[ -z $(Get_Var __b2c_mem_$HANDLE ${g_FUNCNAME}) ]]
	    then
	        echo "long __b2c_mem_${HANDLE} = 0;" >> $g_HFILE
                Save_Main_Var "__b2c_mem_${HANDLE}" "long"
            fi
            if [[ "${HANDLE}" = +(*${g_STRINGSIGN}*) ]]
            then
	        echo "__b2c__STRFREE(${HANDLE});" >> $g_CFILE
            fi
            echo "$HANDLE = (char*)${VAR}; __b2c_mem_$HANDLE = (uintptr_t)${VAR};" >> $g_CFILE
	    echo "if(__b2c__trap){if(!__b2c__memory__check($HANDLE, sizeof(__b2c__MEMTYPE))) {ERROR=1; if(!__b2c__catch_set) RUNTIMEERROR(\"OPEN FOR MEMORY\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE;;
        @(NETWORK) )
	    # Network code
            echo "ERROR = __b2c__network_init((uintptr_t*)&${HANDLE}, ${VAR}, ${FROM}, ${g_SOCKTYPE}, ${g_OPTION_SOCKET}, \"${g_NETWORKTYPE}\", ${g_MULTICAST_TTL}, ${g_SCTP_STREAMS}, __b2c__capeer, __b2c__cacerts);" >> $g_CFILE
            echo "if(ERROR && __b2c__trap){ if(!__b2c__catch_set) RUNTIMEERROR(\"OPEN FOR NETWORK\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO; }" >> $g_CFILE
            ;;
	@(SERVER) )
	    # Network code
            echo "ERROR = __b2c__server_init((uintptr_t*)&${HANDLE}, ${VAR}, ${g_SOCKTYPE}, ${g_OPTION_SOCKET}, ${g_SCTP_STREAMS});" >> $g_CFILE
            echo "if(ERROR && __b2c__trap){ if(!__b2c__catch_set) RUNTIMEERROR(\"OPEN FOR SERVER\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO; }" >> $g_CFILE
            ;;
	@(DEVICE) )
	    echo "$HANDLE = open(${VAR}, __b2c__option_open, S_IRUSR|S_IWUSR);" >> $g_CFILE
	    echo "if($HANDLE < 0){if(__b2c__trap){ERROR = 32; if(!__b2c__catch_set) RUNTIMEERROR(\"OPEN FOR DEVICE\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE;;
    esac
    if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
    then
        g_CATCH_USED=1
    fi
}

#-----------------------------------------------------------

function Handle_Readln
{
    # Local variables
    typeset VAR FROM POS ARGS=${1}

    # Check if FROM is available
    if [[ "$1" != +(* FROM *) ]]
    then
	echo -e "\nSyntax error: missing FROM in READLN statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " FROM " "${ARGS}")
    FROM=$(Trim "${ARGS:$((${POS}+6))}")
    VAR=$(Trim "${ARGS:0:${POS}}")

    # Check if var is string var
    if [[ $(Check_String_Type ${VAR}) -eq 0 ]]
    then
	echo -e "\nSyntax error: variable for READLN at line $g_COUNTER in file '$g_CURFILE' must be string!"
	exit 1
    fi

    # Check if string variable
    if [[ "${VAR}" = +(*${g_STRINGSIGN}) ]]
    then
        Register_Pointer "${VAR}" "char*"
    fi

    # Translate function to C function
    echo "__b2c__readln(&__b2c__assign, ${FROM});" >> $g_CFILE
    Assign_To_String "__b2c__assign" "${VAR}"
}

#-----------------------------------------------------------

function Handle_Writeln
{
    # Local variables
    typeset VAR TO TOKEN ORG POS ARGS=${1}

    # Check if TO is available
    if [[ "$1" != +(* TO *) ]]
    then
	echo -e "\nSyntax error: missing TO in WRITELN statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi
    # Get the arguments
    POS=$(Lexer " TO " "${ARGS}")
    TO=$(Trim "${ARGS:$((${POS}+4))}")
    VAR=$(Trim "${ARGS:0:${POS}}")
    ORG="${VAR}"
    # Start miniparser to see if we need to print something
    while [[ -n ${VAR} ]]
    do
        TOKEN=$(Mini_Parser "${VAR}")
        Print_Element "${TOKEN}" "${TO}"
        VAR="${VAR:${#TOKEN}+1}"
    done

    # If line ends with ';' then skip newline
    if [[ -n $(echo ${ORG##*;}) ]]
    then
	echo "fputs(\"\n\", ${TO});" >> $g_CFILE
    else
        echo "fflush($TO);" >> $g_CFILE
    fi
}

#-----------------------------------------------------------

function Handle_Getbyte
{
    # Local variables
    typeset VAR FROM SIZE CHECK CHUNK TO POS ARGS=${1}

    # Check if FROM is available
    if [[ "$1" != +(* FROM *) ]]
    then
	echo -e "\nSyntax error: missing FROM in GETBYTE statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " SIZE " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        SIZE=$(Trim "${ARGS:$((${POS}+6))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " CHUNK " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        CHUNK=$(Trim "${ARGS:$((${POS}+7))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " FROM " "${ARGS}")
    FROM=$(Trim "${ARGS:$((${POS}+6))}")
    VAR=$(Trim "${ARGS:0:${POS}}")

    # Ensure backwards compatibility
    if [[ -n ${SIZE} ]]
    then
        if [[ -z $CHUNK ]]
        then
            CHUNK=$SIZE
	    SIZE="__b2c__counter"
        fi
    else
        if [[ -z $CHUNK ]]
        then
            CHUNK=1
        fi
	SIZE="__b2c__counter"
    fi

    # Variable may not be array, these should be defined with DECLARE
    if [[ -n $SIZE && "$SIZE" != "__b2c__counter" ]]
    then
        Register_Numeric "${SIZE}" "default"
    fi

    # Type of file descriptor
    CHECK=$(Get_Var ${FROM} ${g_FUNCNAME})

    # Translate function to C function
    echo "if(__b2c__trap){if(!__b2c__memory__check((char*)${VAR}, sizeof(__b2c__MEMTYPE))) {ERROR=1; if(!__b2c__catch_set) RUNTIMEERROR(\"GETBYTE\", ${g_COUNTER}, \"${g_CURFILE}\", ERROR); else if(!setjmp(__b2c__jump)) goto ${g_CATCHGOTO};} }" >> $g_CFILE
    if [[ $CHECK = +(*int*) ]]
    then
        echo "if((${SIZE} = read(${FROM}, (void*)(${VAR}), ${CHUNK})) < 0)" >> $g_CFILE
        echo "{if(__b2c__trap){ERROR = 34; if(!__b2c__catch_set) RUNTIMEERROR(\"GETBYTE\", ${g_COUNTER}, \"${g_CURFILE}\", ERROR); else if(!setjmp(__b2c__jump)) goto ${g_CATCHGOTO};} }" >> $g_CFILE
    else
        echo "${SIZE} = fread((void*)(${VAR}), sizeof(__b2c__MEMTYPE), ${CHUNK}, ${FROM});" >> $g_CFILE
    fi
    if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
    then
        g_CATCH_USED=1
    fi
}

#-----------------------------------------------------------

function Handle_Putbyte
{
    # Local variables
    typeset VAR TO SIZE CHECK CHUNK POS ARGS=${1}

    # Check if TO is available
    if [[ "$1" != +(* TO *) ]]
    then
	echo -e "\nSyntax error: missing TO in PUTBYTE statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " SIZE " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        SIZE=$(Trim "${ARGS:$((${POS}+6))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " CHUNK " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        CHUNK=$(Trim "${ARGS:$((${POS}+7))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " TO " "${ARGS}")
    TO=$(Trim "${ARGS:$((${POS}+4))}")
    VAR=$(Trim "${ARGS:0:${POS}}")
 
    # Ensure backwards compatibility
    if [[ -n ${SIZE} ]]
    then
        if [[ -z $CHUNK ]]
        then
            CHUNK=$SIZE
	    SIZE="__b2c__counter"
        fi
    else
        if [[ -z $CHUNK ]]
        then
            CHUNK=1
        fi
	SIZE="__b2c__counter"
    fi

    # Variable may not be array, these should be defined with DECLARE
    if [[ -n $SIZE && "$SIZE" != "__b2c__counter" ]]
    then
        Register_Numeric "${SIZE}" "default"
    fi

    # Type of file descriptor
    CHECK=$(Get_Var ${TO} ${g_FUNCNAME})

    # Translate function to C function
    echo "if(__b2c__trap){if(!__b2c__memory__check((char*)${VAR}, sizeof(__b2c__MEMTYPE))) {ERROR=1; if(!__b2c__catch_set) RUNTIMEERROR(\"PUTBYTE\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
    if [[ $CHECK = +(*int*) ]]
    then
        echo "if(($SIZE = write(${TO}, (void*)(${VAR}), $CHUNK)) < 0)" >> $g_CFILE
        echo "{if(__b2c__trap){ERROR = 34; if(!__b2c__catch_set) RUNTIMEERROR(\"PUTBYTE\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
    else
        echo "$SIZE = fwrite((void*)(${VAR}), sizeof(__b2c__MEMTYPE), $CHUNK, $TO); fflush($TO);" >> $g_CFILE
    fi
    if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
    then
        g_CATCH_USED=1
    fi
}

#-----------------------------------------------------------

function Handle_Getfile
{
    # Local variables
    typeset VAR FROM SIZE POS FTYPE CHECK ARGS=${1}

    # Check if FROM is available
    if [[ "$1" != +(* FROM *) ]]
    then
	echo -e "\nSyntax error: missing FROM in GETFILE statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " FTYPE " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        FTYPE=$(Trim "${ARGS:$((${POS}+7))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " FROM " "${ARGS}")
    FROM=$(Trim "${ARGS:$((${POS}+6))}")
    VAR=$(Trim "${ARGS:0:${POS}}")

    # Check if var is string var
    if [[ $(Check_String_Type ${VAR}) -eq 0 ]]
    then
	echo -e "\nSyntax error: variable for GETFILE at line $g_COUNTER in file '$g_CURFILE' must be string!"
	exit 1
    fi

    # Check if string is declared
    if [[ "${VAR}" = +(*${g_STRINGSIGN}) ]]
    then
        Register_Pointer "${VAR}" "char*"
    fi

    # Check if FTYPE var is declared
    if [[ -n ${FTYPE} ]]
    then
        Register_Numeric "${FTYPE}" "default"
        CHECK=$(Get_Var ${FTYPE} ${g_FUNCNAME})
    fi

    # Translate statement to C function
    echo "__b2c__getfile(__LINE__, __FILE__, &__b2c__assign, ${FROM}, &__b2c__counter);" >> $g_CFILE
    Assign_To_String "__b2c__assign" "${VAR}"
    if [[ -n ${FTYPE} ]]
    then
        echo "${FTYPE} = (${CHECK})__b2c__counter;" >> $g_CFILE
    fi
}

#-----------------------------------------------------------

function Handle_Receive
{
    # Local variables
    typeset VAR FROM CHUNK SIZE POS ARGS=${1}

    # Check if FROM is available
    if [[ "$1" != +(* FROM *) ]]
    then
	echo -e "\nSyntax error: missing FROM in RECEIVE statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " SIZE " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        SIZE=$(Trim "${ARGS:$((${POS}+6))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " CHUNK " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        CHUNK=$(Trim "${ARGS:$((${POS}+7))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    else
        if [[ ${g_OPTION_TLS} = +(1*|TRUE*) ]]
        then
	    CHUNK=32768
        else
	    CHUNK=$g_BUFFER_SIZE
        fi
    fi
    POS=$(Lexer " FROM " "${ARGS}")
    FROM=$(Trim "${ARGS:$((${POS}+6))}")
    VAR=$(Trim "${ARGS:0:${POS}}")

    # Variable may not be array, these should be defined with DECLARE
    if [[ -n $SIZE ]]
    then
        Register_Numeric "${SIZE}" "default"
    else
	SIZE="__b2c__counter"
    fi

    # Check if string variable, and if so, if declared
    if [[ "${VAR}" = +(*${g_STRINGSIGN}) ]]
    then
        Register_Pointer "${VAR}" "char*"
    fi

    # Translate function to C function
    echo "__b2c__assign = (char*)calloc(($CHUNK+1), sizeof(char));" >> $g_CFILE
    if [[ ${g_NETWORKTYPE} = "SCTP" ]]
    then
	echo "if(($SIZE = sctp_recvmsg($FROM, (void*)__b2c__assign, $CHUNK, 0, 0, 0, 0)) < 0) {" >> $g_CFILE
    else
        # Receive from SSL socket if option was set
        if [[ ${g_OPTION_TLS} = +(1*|TRUE*) ]]
        then
            echo "if(${FROM} > 0) { $SIZE = SSL_read((SSL*)${FROM}, (void*)__b2c__assign, $CHUNK); } if($SIZE <= 0) { fprintf(stderr, \"SSL READ error in line ${g_COUNTER}: %s\n\", ERR_error_string(SSL_get_error((SSL*)${FROM}, ${SIZE}), NULL));" >> $g_CFILE
        else
            echo "if(($SIZE = recv($FROM, (void*)__b2c__assign, $CHUNK, 0)) < 0) {" >> $g_CFILE
        fi
    fi
    echo "if(__b2c__trap){ERROR = 14; if(!__b2c__catch_set) RUNTIMEERROR(\"RECEIVE\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO; } }" >> $g_CFILE

    Assign_To_String "__b2c__assign" "${VAR}" "${SIZE}"

    if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
    then
        g_CATCH_USED=1
    fi
}

#-----------------------------------------------------------

function Handle_Send
{
    # Local variables
    typeset VAR TO CHUNK SIZE POS ARGS=${1}

    # Check if TO is available
    if [[ "$1" != +(* TO *) ]]
    then
	echo -e "\nSyntax error: missing TO in SEND statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " SIZE " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        SIZE=$(Trim "${ARGS:$((${POS}+6))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " CHUNK " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        CHUNK=$(Trim "${ARGS:$((${POS}+7))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " TO " "${ARGS}")
    TO=$(Trim "${ARGS:$((${POS}+4))}")
    VAR=$(Trim "${ARGS:0:${POS}}")

    if [[ -z ${CHUNK} ]]
    then
	CHUNK="__b2c__len($VAR)"
    fi

    # Variable may not be array, these should be defined with DECLARE
    if [[ -n $SIZE ]]
    then
        Register_Numeric "${SIZE}" "default"
    else
	SIZE="__b2c__counter"
    fi

    # Translate function to C function
    if [[ ${g_NETWORKTYPE} = "SCTP" ]]
    then
        echo "if(($SIZE = sctp_sendmsg($TO, (void*)($VAR), $CHUNK, NULL, 0, 0, 0, 0, 0, 0)) < 0) {" >> $g_CFILE
    else
        # Send to SSL socket if option was set
        if [[ ${g_OPTION_TLS} = +(1*|TRUE*) ]]
        then
            echo "$SIZE = SSL_write((SSL*)${TO}, (const void*)($VAR), $CHUNK); if($SIZE <= 0) { fprintf(stderr, \"SSL WRITE error: %s\n\", ERR_error_string(SSL_get_error((SSL*)${TO}, ${SIZE}), NULL));" >> $g_CFILE
        else
            echo "if(($SIZE = send($TO, (void*)($VAR), $CHUNK, 0)) < 0) {" >> $g_CFILE
        fi
    fi
    echo "if(__b2c__trap){ERROR = 15; if(!__b2c__catch_set) RUNTIMEERROR(\"SEND\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
    if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
    then
        g_CATCH_USED=1
    fi
}

#-----------------------------------------------------------

function Handle_Getline
{
    # Local variables
    typeset VAR FROM POS ARGS=${1}

    # Check if FROM is available
    if [[ "$1" != +(* FROM *) ]]
    then
	echo -e "\nSyntax error: missing FROM in GETLINE statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " FROM " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        FROM=$(Trim "${ARGS:$((${POS}+6))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    TO=$(Trim "${ARGS:$((${POS}+6))}")
    VAR=$(Trim "${ARGS:0:${POS}}")

    # Check if var is string var
    if [[ $(Check_String_Type ${VAR}) -eq 0 ]]
    then
	echo -e "\nSyntax error: variable for GETLINE at line $g_COUNTER in file '$g_CURFILE' must be string!"
	exit 1
    fi

    # Check if string variable, and if so, if declared
    if [[ "${VAR}" = +(*${g_STRINGSIGN}) ]]
    then
        Register_Pointer "${VAR}" "char*"
    fi

    # Translate to C function
    echo "__b2c__assign = __b2c__getline(&${FROM});" >> $g_CFILE
    Assign_To_String "__b2c__assign" "${VAR}"
}

#-----------------------------------------------------------

function Handle_Putline
{
    # Local variables
    typeset VAR TO TOKEN POS ARGS=${1}

    # Check if TO is available
    if [[ "$1" != +(* TO *) ]]
    then
	echo -e "\nSyntax error: missing TO in PUTLINE statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " TO " "${ARGS}")
    TO=$(Trim "${ARGS:$((${POS}+4))}")
    VAR=$(Trim "${ARGS:0:${POS}}")
    
    # Start miniparser to see if we need to print something
    while [[ -n ${VAR} ]]
    do
        TOKEN=$(Mini_Parser "${VAR}")
	# Check if var is string var
	if [[ $(Check_String_Type ${TOKEN}) -eq 1 ]]
	then
	    echo "strcat(${TO}, $TOKEN); ${TO}+=strlen($TOKEN);" >> $g_CFILE
	else
	    echo "strcat(${TO}, STR${g_STRINGSIGN}($TOKEN)); ${TO}+=strlen(STR${g_STRINGSIGN}($TOKEN));" >> $g_CFILE
	fi
        VAR="${VAR:${#TOKEN}+1}"
    done

    echo "strcat(${TO}, \"\n\"); ${TO}+=1;" >> $g_CFILE
}

#-----------------------------------------------------------

function Handle_Import
{
    # Local variables
    typeset SYM LIB TOKEN PTR TYPE ALIAS TYPE POS ARGS=${1}

    # Check if FROM is available
    if [[ "$1" != +(* FROM *) ]]
    then
	echo -e "\nSyntax error: missing FROM in IMPORT statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Check if TYPE is available
    if [[ "$1" != +(* TYPE *) ]]
    then
	echo -e "\nSyntax error: missing TYPE in IMPORT statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " ALIAS " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        ALIAS=$(Trim "${ARGS:$((${POS}+7))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
	g_IMPORTED="$ALIAS $g_IMPORTED"
    fi
    POS=$(Lexer " TYPE " "${ARGS}")
    TYPE=$(Trim "${ARGS:$((${POS}+6))}")
    ARGS=$(Trim "${ARGS:0:${POS}}")
    POS=$(Lexer " FROM " "${ARGS}")
    LIB=$(Trim "${ARGS:$((${POS}+6))}")
    ARGS=$(Trim "${ARGS:0:${POS}}")
    SYM=$(Trim "${ARGS//\"/}")

    # Separate symbol and args
    if [[ "${SYM}" = +(*\(*\)*) ]]
    then
        TOKEN=$(Trim "${SYM##*\(}")
        TOKEN=${TOKEN%\)*}
        SYM=$(Trim "${SYM%\(*}")
    fi

    # If library is libm or libc, skip dlopen as we're linking with those anyway
    if [[ $LIB != +(*libc.so*) && $LIB != +(*libm.so*) ]]
    then
        # Link flags
	if [[ $(uname) != "OSF1" && $(uname) != +(*BSD*) && $(uname) != +(*Haiku*) && ${g_LDFLAGS} != +(*-ldl*) ]]
        then
            g_LDFLAGS="${g_LDFLAGS} -ldl"
        fi

	# Create name from libname
        PTR="${LIB//[[:punct:]]/}"

	# Check if variable was declared
	if [[ -z $(Get_Var __b2c__dlopen__pointer_$PTR ${g_FUNCNAME}) ]]
	then
            if [[ -n $g_FUNCNAME ]]
            then
	        g_STRINGARGS="${g_STRINGARGS} static void *__b2c__dlopen__pointer_$PTR = NULL;"
                Save_Func_Var "__b2c__dlopen__pointer_${PTR}" "${g_FUNCNAME}" "void*"
            else
	        echo "void* __b2c__dlopen__pointer_$PTR = NULL;" >> $g_HFILE
                Save_Main_Var "__b2c__dlopen__pointer_${PTR}" "void*"
            fi
	fi
	echo "if(__b2c__dlopen__pointer_$PTR == NULL){__b2c__dlopen__pointer_$PTR = dlopen($LIB, RTLD_LAZY); if(__b2c__dlopen__pointer_$PTR == NULL) {" >> $g_CFILE
	echo "if(__b2c__trap){ERROR = 3; if(!__b2c__catch_set) RUNTIMEERROR(\"IMPORT\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} } }" >> $g_CFILE

        # Create prototype
        if [[ $LIB != "NULL" ]]
        then
	    echo "$TYPE (*${SYM})(${TOKEN});" >> $g_HFILE
	    echo "*(${TYPE}**) (&${SYM}) = (${TYPE}*)dlsym(__b2c__dlopen__pointer_$PTR, \"${SYM}\");" >> $g_CFILE
	    echo "if(${SYM} == NULL) {if(__b2c__trap){ERROR = 4; if(!__b2c__catch_set) RUNTIMEERROR(\"IMPORT\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
        else
	    echo "$TYPE (*$ALIAS)(${TOKEN});" >> $g_HFILE
	    echo "*(${TYPE}**) (&$ALIAS) = (${TYPE}*)dlsym(__b2c__dlopen__pointer_$PTR, \"${SYM}\");" >> $g_CFILE
	    echo "if($ALIAS == NULL) {if(__b2c__trap){ERROR = 4; if(!__b2c__catch_set) RUNTIMEERROR(\"IMPORT\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
        fi
    fi

    # Make symbol known to parser
    if [[ $LIB != "NULL" ]]
    then
	if [[ -n $g_IMPORTED && " ${g_IMPORTED} " = +(* ${SYM} *) ]]
	then
            if [[ $g_SEMANTIC -eq 0 ]]
            then
	        echo -e "\nWARNING: duplicate symbol '${SYM}' at line $g_COUNTER in file '$g_CURFILE'!"
            fi
	else
	    g_IMPORTED="${SYM} $g_IMPORTED"
	fi
	if [[ -n $ALIAS ]]
	then
	    echo "#define $ALIAS ${SYM}" >> $g_HFILE
	fi
    fi

    # Announce runtime error usage
    if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
    then
        g_CATCH_USED=1
    fi
}

#-----------------------------------------------------------
# $1 = TYPE - $2 = VAR - $3 = ARRAY - $4 = static - $5 = is_local

function Normal_Dyn_Array
{
    typeset i j TYPE NR OLD TMP_ARR IDX END ORG_TYPE AM GLOBAL=

    for i in $2
    do
        TYPE="$1"
        g_DYNAMICARRAYS="${g_DYNAMICARRAYS} ${i}@${g_FUNCNAME} "

	# Initialize strings
	if [[ "${TYPE}" = +(*STRING*|*char\*) || "${i}" = +(*${g_STRINGSIGN}*) ]]
	then
            if [[ ${3%%\(*} = +(*,*) ]]
            then
	        echo -e "\nSyntax error: string array cannot have more than one dimension line $g_COUNTER in file '$g_CURFILE'!"
	        exit 1
            fi
            if [[ $5 -eq 1 ]]
            then
                echo "$TYPE* $i = { NULL };" >> $g_CFILE
                Save_Func_Var "${i}" "${g_FUNCNAME}" "${TYPE}"
                g_STRINGARGS="$g_STRINGARGS long ${i}__b2c_array;"
                Save_Func_Var "${i}__b2c_array" "${g_FUNCNAME}" "long"
                if [[ $4 -eq 0 ]]
                then
                    g_STRINGARRAYS="$g_STRINGARRAYS __b2c__free_str_array_members(&${i}, ${g_OPTION_BASE}, ${i}__b2c_array);"
		    g_LOCALSTRINGS="$g_LOCALSTRINGS ${i}"
                fi
            else
                echo "$TYPE* $i = { NULL };" >> $g_HFILE
                Save_Main_Var "${i}" "${TYPE}"
	        echo "long ${i}__b2c_array;" >> $g_HFILE
                Save_Main_Var "${i}__b2c_array" "long"
                if [[ $4 -eq 0 ]]
                then
                    g_GLOBALARRAYS="${g_GLOBALARRAYS} free(${i});"
                fi
            fi
	    echo "$i = (${TYPE}*)calloc(${3}+$g_OPTION_BASE, sizeof(${TYPE}));" >> $g_CFILE
            echo "${i}__b2c_array = ${3};" >> $g_CFILE
        else
            ORG_TYPE="${TYPE}"
            # Count elements
            NR=0
            for j in $3                
            do
                ((NR+=1))
                TYPE="${TYPE}*"
            done

            # Declare top most dimension
            if [[ $5 -eq 1 ]]
            then
                echo "$TYPE $i = { NULL };" >> $g_CFILE
                Save_Func_Var "${i}" "${g_FUNCNAME}" "${ORG_TYPE}"
                g_STRINGARGS="$g_STRINGARGS long ${i}__b2c_array;"
                Save_Func_Var "${i}__b2c_array" "${g_FUNCNAME}" "long"
                if [[ $4 -eq 0 ]]
                then
		    g_LOCALSTRINGS="$g_LOCALSTRINGS ${i}"
                else
                    AM=`echo ${TYPE} | tr -d -c "\*" | wc -c`
                    g_STATICARRAYS="$g_STATICARRAYS ${i}:${AM}"
                fi
            else
                echo "$TYPE $i = { NULL };" >> $g_HFILE
                Save_Main_Var "${i}" "${ORG_TYPE}"
	        echo "long ${i}__b2c_array;" >> $g_HFILE
                Save_Main_Var "${i}__b2c_array" "long"
                if [[ ${NR} -eq 1 ]]
                then
                    g_GLOBALARRAYS="${g_GLOBALARRAYS} free(${i});"
                fi
            fi
            echo "${i}__b2c_array = ${3%%,*};" >> $g_CFILE
            echo "$i = (${TYPE})calloc((size_t)${3%%,*}+$g_OPTION_BASE, sizeof(${TYPE%\**}));" >> $g_CFILE

            # Proceed with other dimensions in array
            if [[ $NR -gt 1 ]]
            then
                OLD=${3%% *}
                TMP_ARR=${3#* }
                NR=0
                IDX="$i"
                END=

                # Construct array initialization
                for j in $TMP_ARR
                do
                    ((NR+=1))
                    if [[ $5 -eq 1 ]]
                    then
                        g_STRINGARGS="$g_STRINGARGS int __b2c_${i}${NR};"
                    else
                        echo "int __b2c_${i}${NR};" >> $g_HFILE
                    fi
                    IDX="$IDX[__b2c_${i}${NR}]"
                    echo "for(__b2c_${i}${NR} = 0; __b2c_${i}${NR} < $OLD+$g_OPTION_BASE; __b2c_${i}${NR}++){" >> $g_CFILE
                    TYPE="${TYPE%\**}"
                    echo "${IDX} = (${TYPE})calloc((size_t)${j}+$g_OPTION_BASE, sizeof(${TYPE%\**}));" >> $g_CFILE
                    END="$END }"
                    OLD="$j"
                done
                echo ${END} >> $g_CFILE
                TYPE="${TYPE%\**}"

                # De-initialize array members in case of FUNCTION
                if [[ $NR -gt 0 ]]
                then
                    NR=1
                    END=
                    for j in ${3% *}
                    do
                        if [[ $4 -eq 0 ]]
                        then
                            if [[ $5 -eq 1 ]]
                            then
                                g_STRINGARRAYS="$g_STRINGARRAYS for(__b2c_${i}${NR} = 0; __b2c_${i}${NR} < $j+$g_OPTION_BASE; __b2c_${i}${NR}++){"
                            else
                                g_GLOBALARRAYS="$g_GLOBALARRAYS for(__b2c_${i}${NR} = 0; __b2c_${i}${NR} < $j+$g_OPTION_BASE; __b2c_${i}${NR}++){"
                            fi
                            END="${END} __b2c__STRFREE(${IDX}); }"
                            IDX="${IDX%\[*}"
                            ((NR+=1))
                        fi
                    done
                    if [[ $4 -eq 0 ]]
                    then
                        if [[ $5 -eq 1 ]]
                        then
                            g_STRINGARRAYS="$g_STRINGARRAYS $END"
                        else
                            g_GLOBALARRAYS="$g_GLOBALARRAYS $END free(${i});"
                        fi
                    fi
                fi
            fi
        fi
    done
}

#-----------------------------------------------------------

function Assoc_Array
{
    typeset i

    for i in ${1//,/ }
    do
        # Check if name not already global
        if [[ -n ${g_FUNCNAME} && -n $(Get_Var __b2c__assoc_${i}) ]]
        then
            echo -e "\nSyntax error: associative array '${i}' in LOCAL statement at line $g_COUNTER in file '$g_CURFILE' was defined previously!"
            exit 1
        fi

        if [[ -n ${3} ]]
        then
            echo "${2} __b2c__assoc_${i}_eval;" >> $g_CFILE
            Save_Func_Var "__b2c__assoc_${i}" "${g_FUNCNAME}" "${2}"
            g_STRINGARRAYS="$g_STRINGARRAYS __b2c__hash_clear(__b2c__assoc_${i}); free(__b2c__assoc_${i}); __b2c__assoc_${i} = NULL;"
        else
            echo "${2} __b2c__assoc_${i}_eval;" >> $g_HFILE
            Save_Main_Var "__b2c__assoc_${i}" "${2}"
            g_GLOBALARRAYS="$g_GLOBALARRAYS __b2c__hash_clear(__b2c__assoc_${i}); free(__b2c__assoc_${i}); __b2c__assoc_${i} = NULL;"
        fi
        echo "__b2c__htable *__b2c__assoc_${i}, *__b2c__assoc_${i}_orig;" >> $g_HFILE
        echo "__b2c__assoc_${i} = __b2c__hash_new();" >> $g_CFILE

        echo "${2} __b2c__assoc_${i}_func(const char *key){void *result; result = __b2c__hash_find_value(__b2c__assoc_${i}, key);" >> $g_HFILE
        if [[ ${i} = +(*${g_STRINGSIGN}*) || ${2} = +(*STRING*) || ${2} = +(*char\**) ]]
        then
            echo "if(result == NULL) { return(NULL); } return((${2})result); }" >> $g_HFILE
        else
            echo "if(result == NULL) { return(0); } return(*($2*)result); }" >> $g_HFILE
        fi
        echo "#define ${i}(...) __b2c__assoc_${i}_func(__b2c__KEYCOLLECT(__VA_ARGS__))" >> $g_HFILE
    done
}

#-----------------------------------------------------------

function Binary_Tree
{
    typeset TYPE i

    for i in ${1//,/ }
    do
        # Check if name not already global
        if [[ -n ${g_FUNCNAME} && -n $(Get_Var __b2c__tree_${i}) ]]
        then
            echo -e "\nSyntax error: tree variable '${i}' in LOCAL statement at line $g_COUNTER in file '$g_CURFILE' was defined previously!"
            exit 1
        fi
        # Determine binary tree type
        if [[ "${2}" = +(STRING|*char\*) ]]
        then
	    TYPE="__b2c__sortstr2:char*"
        elif [[ ${2} = +(*double*) || ${2} = +(*FLOATING*) ]]
        then
            TYPE="__b2c__sortnrd:double"
        elif [[ ${2} = +(*float*) ]]
        then
            TYPE="__b2c__sortnrf:float"
        elif [[ ${2} = +(*long*) || ${2} = +(*NUMBER*) ]]
        then
            TYPE="__b2c__sortnrl:long"
        elif [[ ${2} = +(*int*) ]]
        then
            TYPE="__b2c__sortnri:int"
        elif [[ ${2} = +(*short*) ]]
        then
            TYPE="__b2c__sortnrs:short"
        elif [[ ${2} = +(*char*) ]]
        then
            TYPE="__b2c__sortnrc:char"
        else
	    echo -e "\nSyntax error: unsupported TREE type at line $g_COUNTER in file '$g_CURFILE'!"
	    exit 1
        fi
        # Declare tree variables
        if [[ -n ${3} ]]
        then
            echo "void* ${i} = NULL;" >> $g_CFILE
            Save_Func_Var "__b2c__tree_${i}" "${g_FUNCNAME}" "${TYPE}"
        else
            echo "void* ${i} = NULL;" >> $g_HFILE
            Save_Main_Var "__b2c__tree_${i}" "${TYPE}"
        fi
    done
}

#-----------------------------------------------------------

function Handle_Declare
{
    # Local variables
    typeset VAR TYPE CHECK NEW VALUE OPTION ARRAY i PTR TOKEN
    typeset -i CTR

    if [[ -n $g_RECORDNAME ]]
    then
	echo -e "\nSyntax error: DECLARE/GLOBAL cannot be used within a RECORD at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    #  Check on a GLOBAL RECORD
    if [[ "$1" = +(*RECORD *) ]]
    then
	# Translate to C typedef struct
	g_RECORDNAME="RECORD_${g_COUNTER}"
	echo "typedef struct {" >> $g_HFILE
	g_RECORDVAR=${1#* }
	if [[ $g_RECORDVAR = +(* ARRAY *) ]]
	then
	    g_RECORDARRAY=${g_RECORDVAR#* ARRAY }
	    g_RECORDVAR="${g_RECORDVAR%% ARRAY *}[$g_RECORDARRAY]"
	fi
	# Store current function name
	if [[ -n $g_FUNCNAME ]]
	then
	    g_RECORDCACHE=$g_FUNCNAME
	    g_FUNCNAME=
	fi
    else
	# Get the variablename and type
	if [[ "$1" = +(* TYPE *) ]]
	then
            VAR=$(Trim "${1%% TYPE *}")
	    TYPE=$(Trim "${1##* TYPE }")
	    if [[ ${TYPE} = +(* ARRAY *) ]]
	    then
		ARRAY=${TYPE##* ARRAY }
		TYPE=${TYPE%% ARRAY *}
	    fi
	elif [[ "$1" = +(* ASSOC *) ]]
	then
	    VAR=$(Trim "${1%% ASSOC *}")
	    TYPE=$(Trim "${1##* ASSOC }")
	elif [[ "$1" = +(* TREE *) ]]
	then
	    VAR=$(Trim "${1%% TREE *}")
	    TYPE=$(Trim "${1##* TREE }")
	else
	    if [[ "${1}" = +(* ARRAY *) ]]
	    then
		ARRAY=${1##* ARRAY }
	        VAR=$(Trim "${1%% ARRAY *}")
            else
	        VAR=$(Trim "${1}")
	    fi
            # This construction needed for KSH93
	    if [[ "${VAR//${g_STRINGSIGN}/}" != "${VAR}" ]]
	    then
	        TYPE="char*"
	    elif [[ "${VAR//${g_FLOATSIGN}/}" != "${VAR}" ]]
	    then
	        TYPE="double"
	    else
	        TYPE="${g_VARTYPE}"
	    fi
        fi
        # Check if variable was already declared - no record and not a function pointer?
        if [[ "$VAR" != +(*.*) && "$VAR" != +(\(*) ]]
        then
            IFS=","
	    for i in ${VAR// /}
            do
                # Check for C keywords
                if [[ "${i%%=*}" = +(${g_C_KEYWORDS}) ]]
                then
	            echo -e "\nSyntax error: variable '${i}' in DECLARE/GLOBAL statement at line $g_COUNTER in file '$g_CURFILE' is a C keyword or function!"
	            exit 1
                fi
                # Previous definitions
                if [[ -n $(Get_Var "${i%%=*}") ]]
                then
	            echo -e "\nSyntax error: variable '${i}' in DECLARE/GLOBAL statement at line $g_COUNTER in file '$g_CURFILE' was defined previously!"
	            exit 1
                fi
            done
            IFS="${g_ORGIFS}"
        fi

	# Check for associative array
	if [[ "${1}" = +(* ASSOC *) ]]
	then
            Assoc_Array "${VAR}" "${TYPE}"

	# Check for binary tree
	elif [[ "${1}" = +(* TREE *) ]]
	then
            Binary_Tree "${VAR}" "${TYPE}"

        #  Check for dynamic array declaration
	elif [[ -n ${ARRAY} ]]
	then
            Normal_Dyn_Array "$TYPE" "${VAR//,/ }" "$ARRAY" 0 0

        # Check if it is a known type, if not BaCon has to use external .h file
        elif [[ ${TYPE%%\**} != +(DIR|FILE|*short|*int|*long|*float|*double|*char|void|STRING|NUMBER|FLOATING) ]]
        then
	    if [[ "$VAR" = +(*=*) ]]
	    then
	        echo "$TYPE $VAR;" >> $g_HFILE
		Save_Main_Var "${VAR}" "${TYPE}"
	    else
		for i in ${VAR//,/ }
		do
	            echo "$TYPE $i;" >> $g_HFILE
		    Save_Main_Var "${i}" "${TYPE}"
		done
	    fi

	# Check if var is string var
	elif [[ ( "${VAR}" = +(*${g_STRINGSIGN}*) || "${TYPE}" = +(STRING|char\*) ) && "${VAR}" != +(*=*) ]]
	then
	    for i in ${VAR//,/ }
	    do
                if [[ -z $(Get_Var ${i}) ]]
	        then
		    if [[ "${i}" = +(*\[*\]*) ]]
		    then
			echo "char *${i//]/+$g_OPTION_BASE]} = { NULL };" >> $g_HFILE
                        # Save type
                        Save_Main_Var "${i}" "char*"
                    elif [[ ${i} = +(*\(*\)*) ]]
                    then
                        # Function pointer
		        echo "$TYPE $i;" >> $g_HFILE
                        i=`echo ${i%%\)*} | tr -d "\052"`
                        Save_Main_Var "${i##*\(}" "void*"
		    else
			echo "char *$i = NULL;" >> $g_HFILE
                        Save_Main_Var "${i}" "char*"
		    fi
	        fi
	    done

        # Var is string array assignment
	elif [[ ( "${VAR}" = +(*${g_STRINGSIGN}*) || "${TYPE}" = +(*STRING*|*char\**) ) && "${VAR}" = +(*=*) ]]
        then
            if [[ -z $(Get_Var ${VAR}) ]]
	    then
		if [[ "${VAR}" = +(*\[*\]*) && "${VAR}" = +(*=*) ]]
		then
		    if [[ "${VAR}" = +(*\[*\]*\]*) ]]
		    then
		        echo -e "\nSyntax error: multidimensional stringarrays at line $g_COUNTER in file '$g_CURFILE' are not supported!"
		        exit 1
		    fi
		    # Determine elements to declare array
                    VALUE=`echo ${VAR} | tr -d -c "," | wc -c`
                    ((VALUE+=1))
		    echo "char *${VAR%%\[*}[$VALUE + $g_OPTION_BASE] = { NULL };" >> $g_HFILE
                    # Save type
                    Save_Main_Var "${VAR}" "char*"
		    # Copy elements
		    CTR=$g_OPTION_BASE
		    ARRAY=${VAR#*\{}
		    while [[ -n ${ARRAY} ]]
		    do
                        TOKEN=$(Mini_Parser "${ARRAY%\}*}")
			echo "${VAR%%\[*}[${CTR}] = __b2c_Copy_String(${VAR%%\[*}[${CTR}], ${TOKEN});" >> $g_CFILE
                        ARRAY="${ARRAY:${#TOKEN}+1}"
			((CTR+=1))
		    done
                else
                    while [[ -n ${VAR} ]]
                    do
                        TOKEN=$(Mini_Parser "${VAR}")
		        echo "char *${TOKEN%%=*} = NULL;" >> $g_HFILE
			echo "${TOKEN%%=*} = __b2c_Copy_String(${TOKEN%%=*}, ${TOKEN#*=});" >> $g_CFILE
                        Save_Main_Var "${TOKEN%%=*}" "char*"
                        VAR="${VAR:${#TOKEN}+1}"
                    done
                fi
            fi
	# Assume char assignment or number
	else
	    if [[ "$VAR" = +(*\[*\]*) && "$VAR" != +(*=*) ]]
	    then
                IFS=","
		for i in ${VAR// /}
		do
		    echo "$TYPE ${i//]/+$g_OPTION_BASE]} = { 0 };" >> $g_HFILE
                    # Save type
                    Save_Main_Var "${i}" "${TYPE}"
		done
                IFS="${g_ORGIFS}"
	    elif [[ "$VAR" = +(*\[*\]*) && "$VAR" = +(*=*) ]]
            then
                # Numeric array assignment
                echo "$TYPE ${VAR%%\{*} {" >> $g_HFILE
                OPTION=$g_OPTION_BASE
                CTR=`echo ${VAR} | tr -d -c "[" | wc -c`
                if [[ ${OPTION} -gt 0 && $CTR -gt 1 ]]
                then
	            echo -e "\nWARNING: OPTION BASE has no impact on multidimensional array '${VAR%%\[*}' in DECLARE/GLOBAL statement at line $g_COUNTER in file '$g_CURFILE'!"
                fi
                while [[ ${OPTION} -gt 0 && $CTR -eq 1 ]]
                do
                    echo " 0, " >> $g_HFILE
                    ((OPTION-=1))
                done
	        echo "${VAR#*\{};" >> $g_HFILE
                Save_Main_Var "${VAR%%\[*}" "${TYPE}"
            elif [[ ${VAR} = +(*\(*\)*) ]]
            then
                # Function pointer
		echo "$TYPE $VAR;" >> $g_HFILE
                VAR=`echo ${VAR%%\)*} | tr -d "\052"`
                Save_Main_Var "${VAR##*\(}" "void*"
	    else
                IFS=","
                for i in ${VAR// /}
                do
                    if [[ "$i" = +(*=*) ]]
                    then
		        echo "$TYPE $i;" >> $g_HFILE
                    elif [[ "$TYPE" = +(*\*) || "$i" = +(\**) ]]
                    then
		        echo "$TYPE ${i} = NULL;" >> $g_HFILE
                    else
		        echo "$TYPE ${i} = 0;" >> $g_HFILE
                    fi
                    Save_Main_Var "${i}" "${TYPE}"
                done
                IFS="${g_ORGIFS}"
            fi
	fi
    fi
}

#-----------------------------------------------------------

function Handle_Local
{
    # Local variables
    typeset VAR TYPE DIM DIM2 NEW VALUE i OPTION ARRAY STATIC PTR TOKEN
    typeset -i CTR

    # Get the variablename and type
    if [[ "$1" = +(* TYPE *) ]]
    then
	VAR=$(Trim "${1%% TYPE *}")
	TYPE=$(Trim "${1##* TYPE }")
	if [[ ${TYPE} = +(* ARRAY *) ]]
	then
	    ARRAY=${TYPE##* ARRAY }
	    TYPE=${TYPE%% ARRAY *}
	fi
    elif [[ "$1" = +(* ASSOC *) ]]
    then
	VAR=$(Trim "${1%% ASSOC *}")
	TYPE=$(Trim "${1##* ASSOC }")
    elif [[ "$1" = +(* TREE *) ]]
    then
	VAR=$(Trim "${1%% TREE *}")
	TYPE=$(Trim "${1##* TREE }")
    else
	if [[ "${1}" = +(* ARRAY *) ]]
	then
	    ARRAY=${1##* ARRAY }
	    VAR=$(Trim "${1%% ARRAY *}")
        else
	    VAR=$(Trim "${1}")
	fi
        # This construction needed for KSH93
	if [[ "${VAR//${g_STRINGSIGN}/}" != "${VAR}" ]]
	then
	    TYPE="char*"
	elif [[ "${VAR//${g_FLOATSIGN}/}" != "${VAR}" ]]
	then
	    TYPE="double"
	else
	    TYPE="${g_VARTYPE}"
	fi
    fi

    # Check if variable was already declared - no record and not function pointer?
    if [[ "$VAR" != +(*.*) && "$VAR" != +(\(*) ]]
    then
        IFS=","
	for i in ${VAR// /}
        do
            # Check for C keywords
            if [[ "${i%%=*}" = +(${g_C_KEYWORDS}) ]]
            then
	        echo -e "\nSyntax error: variable '${i}' in LOCAL statement at line $g_COUNTER in file '$g_CURFILE' is a C keyword or function!"
	        exit 1
            fi
            # Previous definitions
            if [[ -n $(Get_Var "${i%%=*}" ${g_FUNCNAME}) ]]
            then
	        echo -e "\nSyntax error: variable '${i}' in LOCAL statement at line $g_COUNTER in file '$g_CURFILE' was defined previously!"
	        exit 1
            fi
        done
        IFS="${g_ORGIFS}"
    fi

    # Check for associative array
    if [[ "${1}" = +(* ASSOC *) ]]
    then
        Assoc_Array "${VAR}" "${TYPE}" "${g_FUNCNAME}"

	# Check for binary tree
    elif [[ "${1}" = +(* TREE *) ]]
    then
        Binary_Tree "${VAR}" "${TYPE}" "${g_FUNCNAME}"

    # Check for dynamic array declaration
    elif [[ -n ${ARRAY} ]]
    then
        if [[ $ARRAY = +(*STATIC*) ]]
        then
            STATIC=1
	    ARRAY=`echo ${ARRAY%% STATIC*} | tr "," " "`
        else
            STATIC=0
	    ARRAY="${ARRAY//,/ }"
        fi
        if [[ -n $g_FUNCNAME ]]
        then
            Normal_Dyn_Array "$TYPE" "${VAR//,/ }" "$ARRAY" $STATIC 1
        else
            Normal_Dyn_Array "$TYPE" "${VAR//,/ }" "$ARRAY" $STATIC 0
        fi

    # Check if it is a known type, if not BaCon has to use external .h file
    elif [[ ${TYPE%%\**} != +(DIR|FILE|*int|*short|*long|*float|*double|*char|void|STRING|NUMBER|FLOATING) && -z $g_RECORDNAME ]]
    then
	if [[ "$VAR" = +(*=*) ]]
	then
	    echo "$TYPE $VAR;" >> $g_CFILE
	    if [[ -z ${g_FUNCNAME} ]]
	    then
		Save_Main_Var "${VAR}" "${TYPE}"
	    else
		Save_Func_Var "${VAR}" "${g_FUNCNAME}" "${TYPE}"
	    fi
	else
	    for i in ${VAR//,/ }
	    do
		if [[ -z ${g_FUNCNAME} ]]
		then
	            echo "$TYPE $i;" >> $g_HFILE
		    Save_Main_Var "${i}" "${TYPE}"
		else
	            echo "$TYPE $i;" >> $g_CFILE
		    Save_Func_Var "${i}" "${g_FUNCNAME}" "${TYPE}"
		fi
	    done
	fi

    # Check if var is string var
    elif [[ ( "${TYPE}" = +(STRING|*char\*) || "${VAR}" = +(*${g_STRINGSIGN}*) ) && "${VAR}" != +(*=*) && "${VAR}" != +(*\[*${g_STRINGSIGN}\]*) ]]
    then
	for i in ${VAR//,/ }
	do
            if [[ -z $(Get_Var ${i} ${g_FUNCNAME}) ]]
	    then
		# Check on multidimensional stringarrays
		if [[ "${i}" = +(*\[*\]*\]*) ]]
		then
		    echo -e "\nSyntax error: multidimensional stringarrays at line $g_COUNTER in file '$g_CURFILE' are not supported!"
		    exit 1
		fi
		# Are we in a function?
		if [[ -n $g_FUNCNAME ]]
		then
		    if [[ -n $g_RECORDNAME ]]
		    then
			if [[ "${i}" = +(*\[*\]*) ]]
			then
			    echo "char *${i//]/+$g_OPTION_BASE]};" >> $g_CFILE
			    DIM=${i##*\[}; DIM=${DIM%%\]*}
                            if [[ "${g_RECORDVAR}" = +(*\[*\]*) ]]
                            then
				if [[ -n ${g_RECORDARRAY} ]]
				then
				    DIM2="__b2c_record_${g_RECORDNAME%_*}"
				else
				    DIM2=${g_RECORDVAR##*\[}; DIM2=${DIM2%%\]*}
				fi
                                g_RECORDEND_BODY="${g_RECORDEND_BODY} for(__b2c__counter=0; __b2c__counter<$DIM2; __b2c__counter++){for(__b2c__ctr=0; __b2c__ctr<$DIM; __b2c__ctr++) ${g_RECORDVAR%%\[*}[__b2c__counter].${i%%\[*}[__b2c__ctr]=NULL;}"
			        g_STRINGARRAYS="$g_STRINGARRAYS for(__b2c__counter=0; __b2c__counter<$DIM2; __b2c__counter++){for(__b2c__ctr=0; __b2c__ctr<$DIM; __b2c__ctr++) { __b2c__STRFREE(${g_RECORDVAR%%\[*}[__b2c__counter].${i%%\[*}[__b2c__ctr]);} }"
                            else
                                g_RECORDEND_BODY="${g_RECORDEND_BODY} for(__b2c__ctr=0; __b2c__ctr<$DIM; __b2c__ctr++) $g_RECORDVAR.${i%%\[*}[__b2c__ctr] = NULL;"
			        g_STRINGARRAYS="$g_STRINGARRAYS __b2c__free_str_array_members(&$g_RECORDVAR.${i%%\[*}, ${g_OPTION_BASE}, ${DIM}); }"
                            fi
			else
			    echo "char *$i;" >> $g_CFILE
			    # Pointer var should not be initialized
			    if [[ "${i}" = +(*${g_STRINGSIGN}*) && "${g_RECORDVAR}" != +(*\[*\]*) && -z ${g_RECORDARRAY} ]]
			    then
                                g_RECORDEND_BODY="${g_RECORDEND_BODY} $g_RECORDVAR.$i = NULL;"
			        g_LOCALSTRINGS="$g_LOCALSTRINGS ${g_RECORDVAR}.${i}"
                            fi
			fi
                        Save_Func_Var "${i}" "${g_FUNCNAME}" "char*"
		    else
			if [[ "${i}" = +(*\[*\]*) ]]
			then
			    echo "char *${i//]/+$g_OPTION_BASE]} = { NULL };" >> $g_CFILE
			    DIM=${i##*\[}; DIM=${DIM%%\]*}
			    g_STRINGARRAYS="$g_STRINGARRAYS for(__b2c__ctr=0; __b2c__ctr<$DIM; __b2c__ctr++) { __b2c__STRFREE(${g_WITHVAR}${i%%\[*}[__b2c__ctr]); }"
			    # Save type
                            Save_Func_Var "${i}" "${g_FUNCNAME}" "char*"
                        elif [[ ${i} = +(*\(*\)*) ]]
                        then
                            # Function pointer
		            echo "$TYPE $i;" >> $g_CFILE
                            i=`echo ${i%%\)*} | tr -d "\052"`
                            Save_Func_Var "${i##*\(}" "${g_FUNCNAME}" "void*"
			else
			    echo "char *$i = NULL;" >> $g_CFILE
                            Save_Func_Var "${i}" "${g_FUNCNAME}" "char*"
                            # Defined as string?
			    if [[ "${i}" = +(*${g_STRINGSIGN}*) ]]
			    then
				g_LOCALSTRINGS="$g_LOCALSTRINGS ${i}"
                            fi
			fi
		    fi
		# We are in the mainprogram
		else
		    if [[ -n $g_RECORDNAME ]]
		    then
			if [[ "${i}" = +(*\[*\]*) ]]
			then
			    echo "char *${i//]/+$g_OPTION_BASE]};" >> $g_HFILE
                        else
			    echo "char *$i;" >> $g_HFILE
			    # Pointer var should not be initialized
			    if [[ "${i}" = +(*${g_STRINGSIGN}*) && "${g_RECORDVAR}" != +(*\[*\]*) && -z ${g_RECORDARRAY} ]]
			    then
                                g_RECORDEND_BODY="${g_RECORDEND_BODY} $g_RECORDVAR.$i = NULL;"
                            fi
                        fi
                        Save_Main_Var "${i}" "char*"
		    else
			if [[ "${i}" = +(*\[*\]*) ]]
			then
			    echo "char *${i//]/+$g_OPTION_BASE]} = { NULL };" >> $g_HFILE
			    # Save type
                            Save_Main_Var "${i}" "char*"
                        elif [[ ${i} = +(*\(*\)*) ]]
                        then
                            # Function pointer
		            echo "$TYPE $i;" >> $g_HFILE
                            i=`echo ${i%%\)*} | tr -d "\052"`
                            Save_Main_Var "${i##*\(}" "void*"
			else
			    echo "char *$i = NULL;" >> $g_HFILE
                            Save_Main_Var "${i}" "char*"
			fi
		    fi
		fi
	    fi
	done
    elif [[ ( "${VAR}" = +(*${g_STRINGSIGN}*) || "${TYPE}" = +(*STRING*|*char\**) ) && "${VAR}" = +(*=*) ]]
    then
        if [[ -n $g_FUNCNAME ]]
	then
            if [[ -z $(Get_Var ${VAR}) ]]
	    then
		if [[ "${VAR}" = +(*\[*\]*\]*) ]]
		then
		    echo -e "\nSyntax error: multidimensional stringarrays at line $g_COUNTER in file '$g_CURFILE' are not supported!"
		    exit 1
		fi
		if [[ "${VAR}" = +(*\[*\]*) && "${VAR}" = +(*=*) ]]
		then
		    # Determine elements to declare array
                    VALUE=`echo ${VAR} | tr -d -c "," | wc -c`
                    ((VALUE+=1))
		    echo "static char *${VAR%%\[*}[$VALUE + $g_OPTION_BASE] = { NULL };" >> $g_CFILE
		    # Set dimension needed for SORT
                    if [[ -n ${g_RECORDVAR} ]]
                    then
		        echo -e "\nSyntax error: C does not allow initialization of an array within a struct at line $g_COUNTER in file '$g_CURFILE'!"
		        exit 1
                    fi
                    # Save type
                    Save_Func_Var "${VAR}" "${g_FUNCNAME}" "char*"
		    # Copy elements
		    CTR=$g_OPTION_BASE
		    ARRAY=${VAR#*\{}
		    while [[ -n ${ARRAY} ]]
		    do
                        TOKEN=$(Mini_Parser "${ARRAY%\}*}")
			echo "${VAR%%\[*}[${CTR}] = __b2c_Copy_String(${VAR%%\[*}[${CTR}], ${TOKEN});" >> $g_CFILE
                        ARRAY="${ARRAY:${#TOKEN}+1}"
			((CTR+=1))
		    done
                else
                    while [[ -n ${VAR} ]]
                    do
                        TOKEN=$(Mini_Parser "${VAR}")
		        echo "static char *${TOKEN%%=*} = NULL;" >> $g_CFILE
			echo "${TOKEN%%=*} = __b2c_Copy_String(${TOKEN%%=*}, ${TOKEN#*=});" >> $g_CFILE
                        Save_Func_Var "${TOKEN%%=*}" "${g_FUNCNAME}" "char*"
                        VAR="${VAR:${#TOKEN}+1}"
                    done
                fi
            fi
        else
            if [[ -z $(Get_Var ${VAR}) ]]
	    then
		if [[ "${VAR}" = +(*\[*\]*\]*) ]]
		then
		    echo -e "\nSyntax error: multidimensional stringarrays at line $g_COUNTER in file '$g_CURFILE' are not supported!"
		    exit 1
		fi
		if [[ "${VAR}" = +(*\[*\]*) && "${VAR}" = +(*=*) ]]
		then
		    # Determine elements to declare array
                    VALUE=`echo ${VAR} | tr -d -c "," | wc -c`
                    ((VALUE+=1))
		    echo "char *${VAR%%\[*}[$VALUE + $g_OPTION_BASE] = { NULL };" >> $g_HFILE
		    # Set dimension needed for SORT
                    if [[ -n ${g_RECORDVAR} ]]
                    then
		        echo -e "\nSyntax error: C does not allow initialization of an array within a struct at line $g_COUNTER in file '$g_CURFILE'!"
		        exit 1
                    fi
                    # Save type
                    Save_Main_Var "${VAR}" "char*"
		    # Copy elements
		    CTR=$g_OPTION_BASE
		    ARRAY=${VAR#*\{}
		    while [[ -n ${ARRAY} ]]
		    do
                        TOKEN=$(Mini_Parser "${ARRAY%\}*}")
			echo "${VAR%%\[*}[${CTR}] = __b2c_Copy_String(${VAR%%\[*}[${CTR}], ${TOKEN});" >> $g_CFILE
                        ARRAY="${ARRAY:${#TOKEN}+1}"
			((CTR+=1))
		    done
                else
                    while [[ -n ${VAR} ]]
                    do
                        TOKEN=$(Mini_Parser "${VAR}")
		        echo "char *${TOKEN%%=*} = NULL;" >> $g_HFILE
			echo "${TOKEN%%=*} = __b2c_Copy_String(${TOKEN%%=*}, ${TOKEN#*=});" >> $g_CFILE
                        Save_Main_Var "${TOKEN%%=*}" "char*"
                        VAR="${VAR:${#TOKEN}+1}"
                    done
                fi
            fi
        fi
    # Assume number or complicated type
    else
	if [[ -n $g_FUNCNAME ]]
	then
	    if [[ "$VAR" = +(*\[*\]*) && "$VAR" != +(*=*) ]]
	    then
                IFS=","
		for i in ${VAR// /}
		do
                    if [[ -z $g_RECORDNAME ]]
                    then
			echo "$TYPE ${i//]/+$g_OPTION_BASE]} = { 0 };" >> $g_CFILE
                    else
			echo "$TYPE ${i//]/+$g_OPTION_BASE]};" >> $g_CFILE
                    fi
                    Save_Func_Var "${i}" "${g_FUNCNAME}" "${TYPE}"
		done
                IFS="${g_ORGIFS}"
	    elif [[ "$VAR" = +(*\[*\]*) && "$VAR" = +(*=*) ]]
            then
                # Numeric array assignment
                echo "$TYPE ${VAR%%\{*} {" >> $g_CFILE
                OPTION=$g_OPTION_BASE
                CTR=`echo ${VAR} | tr -d -c "[" | wc -c` ; PTR=
                if [[ ${OPTION} -gt 0 && $CTR -gt 1 ]]
                then
	            echo -e "\nWARNING: OPTION BASE has no impact on multidimensional array '${VAR%%\[*}' in LOCAL statement at line $g_COUNTER in file '$g_CURFILE'!"
                fi
                while [[ ${OPTION} -gt 0 && $CTR -eq 1 ]]
                do
                    echo " 0, " >> $g_CFILE
                    ((OPTION-=1))
                done
	        echo "${VAR#*\{};" >> $g_CFILE
                if [[ -n ${g_RECORDVAR} ]]
                then
		    echo -e "\nSyntax error: C does not allow initialization of an array within a struct at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
                fi
                Save_Func_Var "${VAR}" "${g_FUNCNAME}" "${TYPE}"
            elif [[ ${VAR} = +(*\(*\)*) ]]
            then
                # Function pointer
		echo "$TYPE $VAR;" >> $g_CFILE
                VAR=`echo ${VAR%%\)*} | tr -d "\052"`
                Save_Func_Var "${VAR##*\(}" "${g_FUNCNAME}" "void*"
	    else
                IFS=","
                for i in ${VAR// /}
                do
                    if [[ "$i" = +(*=*) || -n ${g_RECORDVAR} ]]
                    then
		        echo "$TYPE $i;" >> $g_CFILE
                    elif [[ "$TYPE" = +(*\*) || "$i" = +(\**) ]]
                    then
		        echo "$TYPE ${i} = NULL;" >> $g_CFILE
                    else
		        echo "$TYPE ${i} = 0;" >> $g_CFILE
                    fi
                    Save_Func_Var "${i}" "${g_FUNCNAME}" "${TYPE}"
                done
                IFS="${g_ORGIFS}"
	    fi
	else
	    if [[ "$VAR" = +(*\[*\]*) && "$VAR" != +(*=*) ]]
	    then
                IFS=","
		for i in ${VAR// /}
		do
                    if [[ -z $g_RECORDNAME ]]
                    then
			echo "$TYPE ${i//]/+$g_OPTION_BASE]} = { 0 };" >> $g_HFILE
                    else
			echo "$TYPE ${i//]/+$g_OPTION_BASE]};" >> $g_HFILE
                    fi
                    Save_Main_Var "${i}" "${TYPE}"
		done
                IFS="${g_ORGIFS}"
	    elif [[ "$VAR" = +(*\[*\]*) && "$VAR" = +(*=*) ]]
            then
                # Numeric array assignment
                echo "$TYPE ${VAR%%\{*} {" >> $g_HFILE
                OPTION=$g_OPTION_BASE
                CTR=`echo ${VAR} | tr -d -c "[" | wc -c` ; PTR=
                if [[ ${OPTION} -gt 0 && $CTR -gt 1 ]]
                then
	            echo -e "\nWARNING: OPTION BASE has no impact on multidimensional array '${VAR%%\[*}' in LOCAL statement at line $g_COUNTER in file '$g_CURFILE'!"
                fi
                while [[ ${OPTION} -gt 0 && $CTR -eq 1 ]]
                do
                    echo " 0, " >> $g_HFILE
                    ((OPTION-=1))
                done
	        echo "${VAR#*\{};" >> $g_HFILE
                if [[ -n ${g_RECORDVAR} ]]
                then
		    echo -e "\nSyntax error: C does not allow initialization of an array within a struct at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
                fi
                Save_Main_Var "${VAR}" "${TYPE}"
            elif [[ ${VAR} = +(*\(*\)*) ]]
            then
                # Function pointer
		echo "$TYPE $VAR;" >> $g_HFILE
                VAR=`echo ${VAR%%\)*} | tr -d "\052"`
                Save_Main_Var "${VAR##*\(}" "void*"
            else
                IFS=","
                for i in ${VAR// /}
                do
                    if [[ "$i" = +(*=*) || -n ${g_RECORDVAR} ]]
                    then
		        echo "$TYPE $i;" >> $g_HFILE
                    elif [[ "$TYPE" = +(*\*) || "$i" = +(\**) ]]
                    then
		        echo "$TYPE ${i} = NULL;" >> $g_HFILE
                    else
		        echo "$TYPE ${i} = 0;" >> $g_HFILE
                    fi
                    Save_Main_Var "${i}" "${TYPE}"
                done
                IFS="${g_ORGIFS}"
	    fi
	fi
    fi
}

#-----------------------------------------------------------

function Handle_Read
{
    # Local variables
    typeset CHECK STR ITEM

    # Check if we have an argument at all
    if [[ "$1" = "READ" ]]
    then
	echo -e "\nSyntax error: empty READ at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    for ITEM in ${1//,/ }
    do
	# Check if string variable, and if so, if declared
	if [[ "${ITEM}" = +(*${g_STRINGSIGN}) ]]
	then
            Register_Pointer "${ITEM}" "char*"
	    CHECK="char*"
        else
            Register_Numeric "${ITEM}" "default"
            CHECK=$(Get_Var ${ITEM} ${g_FUNCNAME})
	fi

        # Check type of var, string?
	if [[ $(Check_String_Type ${ITEM}) -eq 1 ]]
	then
	    # Convert to C
	    echo "__b2c__assign = __b2c_Copy_String(NULL, __b2c__stringarray[__b2c__stringarray_ptr]); __b2c__stringarray_ptr++;" >> $g_CFILE
            Assign_To_String "__b2c__assign" "${ITEM}"
        else
            Assign_To_Number "__b2c__floatarray[__b2c__floatarray_ptr]" "${ITEM}" 0
	    echo "__b2c__floatarray_ptr++;" >> $g_CFILE
        fi
    done
}

#-----------------------------------------------------------

function Handle_Endfunction
{
    typeset TFIL

    # Check if we're in a FUNCTION
    if [[ -z $g_FUNCNAME ]]
    then
        echo -e "\nSyntax error: ENDFUNC(TION) outside FUNCTION at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Check if return was found
    if [[ -z $g_FUNCTYPE ]]
    then
	echo -e "\nSyntax error: function '$g_FUNCNAME' was defined without returning a value or string!"
	exit 1
    fi

    # Put prototype to header file
    if [[ ${g_PROTOTYPE} != +(*::*) ]]
    then
        echo "$g_FUNCTYPE ${g_PROTOTYPE};" >> $g_HFILE
    fi
    g_PROTOTYPE=

    TFIL=${g_CURFILE##*/}
    # Now setup function in main program
    echo "/* Created with Shell BaCon $g_VERSION - (c) Peter van Eerten - MIT License */" > ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    echo "#undef __b2c__exitval" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    echo "#define __b2c__exitval 0" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    if [[ $g_ORIGFUNCNAME != +(*\(*\)*) ]]
    then
	echo "$g_FUNCTYPE $g_ORIGFUNCNAME(void) {" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    else
	echo "$g_FUNCTYPE $g_ORIGFUNCNAME {" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    fi

    # Add function body
    echo "${g_STRINGARGS}" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    cat $g_CFILE >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    if [[ $g_CATCH_USED -eq 1 ]]
    then
        echo "__B2C__PROGRAM__EXIT: ;" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    fi

    # Make sure pointers are always reset
    echo "__b2c__catch_set = __b2c__catch_set_backup;" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h

    # Make sure the function always returns something
    if [[ $g_FUNCTYPE = +(*char\*|*STRING) ]]
    then
	echo "return (NULL);}" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    elif [[ $g_FUNCTYPE = +(*char|*short|*int|*long|*double|*float|*NUMBER|*FLOATING) ]]
    then
	echo "return(0);}" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    else
	echo "}" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    fi

    # Include header file
    if [[ ${g_INCLUDE_FILES} != +(*${TFIL%.*}.$g_FUNCNAME.h*) ]]
    then
	g_INCLUDE_FILES="$g_INCLUDE_FILES ${TFIL%.*}.$g_FUNCNAME.h"
    fi

    # Add to total filelist
    g_TMP_FILES="$g_TMP_FILES ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h"

    # Delete temp funcfile
    rm $g_CFILE

    # Restore mainfile
    g_CFILE=$g_COPY_CFILE

    # Restore CATCH routine
    g_CATCHGOTO="$g_ORIGCATCHGOTO"
    g_CATCH_USED=${g_ORIGCATCH_USED}

    # Clear function variables
    g_ORIGFUNCNAME=
    g_FUNCNAME=
    g_FUNCTYPE=
    g_LOCALSTRINGS=
    g_STRINGARRAYS=
    g_STRINGARGS=
}

#-----------------------------------------------------------

function Handle_Return
{
    # Local variables
    typeset TYPE STR LEN ARG=${1}
    typeset -i CTR

    # Check if we have an argument at all, if not, we return from a GOSUB
    if [[ "${1}" = "RETURN" ]]
    then
	echo "if(__b2c__gosub_buffer_ptr >= 0) longjmp(__b2c__gosub_buffer[__b2c__gosub_buffer_ptr], 1);" >> $g_CFILE
	return
    fi

    TYPE=${g_FUNCTYPE}
    if [[ -z ${TYPE} ]]
    then
        TYPE=$(Get_Var ${1%%\(*} ${g_FUNCNAME})
    fi

    # Check type of returned var, is it a string?
    if [[ $(Check_String_Type ${1}) -eq 1 || ${g_FUNCTYPE} = +(*char\*|*STRING) || ${g_FUNCNAME} = +(*${g_STRINGSIGN}) ]]
    then
        # Dynamic array or array created by SPLIT or LOOKUP
        if [[ ${g_DYNAMICARRAYS} = +(* ${1}@${g_FUNCNAME} *) ]]
        then
	    g_FUNCTYPE="char**"
        # We return a string
        else
	    g_FUNCTYPE="char*"
	    echo "__b2c__assign = __b2c__return(${ARG});" >> $g_CFILE
	    ARG="__b2c__assign"
        fi

    # Assume variable, check if declared before
    elif [[ -n $TYPE ]]
    then
        if [[ ${ARG} = +(*\[*\]*) ]]
        then
            CTR=`echo ${ARG} | tr -d -c "[" | wc -c`
            until [[ $CTR -eq 0 ]]
            do
                if [[ ${TYPE} = +(*\*) ]]
                then
		    let LEN=${#TYPE}-1
		    TYPE="${TYPE:0:$LEN}"
                fi
                let CTR=${CTR}-1
            done
        else
            for STR in $g_STATICARRAYS
            do
                if [[ $STR = +(*${ARG}*) ]]
                then
                    CTR=${STR##*:}
                    until [[ $CTR -eq 0 ]]
                    do
                        TYPE="${TYPE}*"
                        let CTR=${CTR}-1
                    done
                fi
            done
        fi
	g_FUNCTYPE="${TYPE}"

    # Not declared, assume actual value
    else
        if [[ "${1}" = +(*${g_LONGSIGN}) || ${g_FUNCNAME} = +(*${g_LONGSIGN}) ]]
        then
	    g_FUNCTYPE="long"
        elif [[ "${1}" = +(*.*) || "${1}" = +(*${g_FLOATSIGN}) || ${g_FUNCNAME} = +(*${g_FLOATSIGN}) ]]
        then
	    g_FUNCTYPE="double"
        else
	    g_FUNCTYPE="${g_VARTYPE}"
        fi
    fi

    # Free strings variables if there are any
    echo "${g_STRINGARRAYS}" >> $g_CFILE
    for STR in $g_LOCALSTRINGS
    do
        echo "__b2c__STRFREE($STR);" >> $g_CFILE
    done

    # The actual return value
    echo "__b2c__catch_set = __b2c__catch_set_backup;" >> $g_CFILE
    echo "return(${ARG});" >> $g_CFILE
}

#-----------------------------------------------------------

function Handle_Push
{
    # Check if we have an argument at all
    if [[ "$1" = "PUSH" ]]
    then
	echo -e "\nSyntax error: empty PUSH at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Cleanup at exit
    if [[ $g_GLOBALARRAYS != +(*__b2c__stack*) ]]
    then
        g_GLOBALARRAYS="$g_GLOBALARRAYS __b2c__free_str_array_members(&__b2c__stack, ${g_OPTION_BASE}, SP); free(__b2c__stack);"
    fi

    # Store result as string
    echo "__b2c__stack = (char**)realloc(__b2c__stack, (SP+1)*sizeof(char*));" >> $g_CFILE
    if [[ $(Check_String_Type ${1}) -eq 1 ]]
    then
        echo "__b2c__stack[SP] = __b2c_Copy_String(NULL, ${1});" >> $g_CFILE
    else
        echo "__b2c__stack[SP] = calloc(${g_MAX_DIGITS}, sizeof(char)); snprintf(__b2c__stack[SP], ${g_MAX_DIGITS}-1, \"%g\", (double)(${1}));" >> $g_CFILE
    fi

    # Increase stackpointer
    echo "SP++;" >> $g_CFILE
}

#-----------------------------------------------------------

function Handle_Pull
{
    # Argument must be a variable
    if [[ "$1" = +(![a-zA-Z]) ]]
    then
	echo -e "\nSyntax error: argument in PULL statement at line $g_COUNTER in file '$g_CURFILE' is not a variable!"
	exit 1
    fi

    # Check if string is declared
    if [[ "${1}" = +(*${g_STRINGSIGN}) ]]
    then
        Register_Pointer "${1}" "char*"
    # Not a string?
    else
        Register_Numeric "${1}" "default"
    fi

    # Decrease stackpointer again
    echo "SP--; if(SP >= 0) {" >> $g_CFILE

    # Now see if we have a assoc or a normal variable
    if [[ $(Check_String_Type ${1}) -eq 1 ]]
    then
        Assign_To_String "__b2c__stack[SP]" "${1}"
    else
        Assign_To_Number "__b2c__stack[SP]" "${1}" 1
    fi
    echo "} else { SP = 0; }" >> $g_CFILE
}

#-----------------------------------------------------------

function Handle_SubFunc
{
    typeset TOKEN LEN CHAR DIM ARR CHECK SIZE POS TYPE ORG NO_ARGS ARGS=${1}

    # Check argument
    if [[ $(echo ${1}) = "SUB" || $(echo ${1}) = "FUNCTION" ]]
    then
	echo -e "\nSyntax error: empty SUB/FUNCTION at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Check if we are in a sub already
    if [[ -n $g_FUNCNAME ]]
    then
	echo -e "\nSyntax error: cannot define a SUB/FUNCTION within a SUB/FUNCTION at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the functype
    if [[ ${ARGS} = +(*\(*\)*) ]]
    then
        NO_ARGS="${ARGS##*\)}"
    else
        NO_ARGS=${ARGS}
    fi
    POS=$(Lexer " TYPE " "${NO_ARGS}")
    if [[ -n ${POS} ]]
    then
        g_FUNCTYPE=$(Trim "${NO_ARGS:$((${POS}+6))}")
        ARGS=${ARGS%\)*}")"
    fi
    ORG=${ARGS}

    # Get the funcname
    if [[ ${ARGS} = +(*\(*\)*) ]]
    then
        if [[ -z ${ZSH_NAME} ]]
        then
            POS=$(Lexer "\(" "${ARGS}")
        else
            POS=$(Lexer "(" "${ARGS}")
        fi
    else
        POS=$(Lexer " TYPE " "${ARGS}")
    fi
    if [[ -n ${POS} ]]
    then
        g_ORIGFUNCNAME=$(Trim "${ARGS:0:$((${POS}+1))}")
        g_PROTOTYPE=$g_ORIGFUNCNAME
        ARGS=$(Trim "${ARGS:0:${POS}}")
    else
        g_ORIGFUNCNAME="${ARGS}("
        g_PROTOTYPE=$g_ORIGFUNCNAME
        POS=${#ARGS}
    fi
    g_FUNCNAME=$(Trim "${ARGS:0:${POS}}")

    # In case of C++ classes
    if [[ $g_FUNCNAME = +(*::*) ]]
    then
        g_FUNCNAME=$(echo ${g_FUNCNAME} | tr ":" "_")
    fi

    # Check if name exists
    if [[ " ${g_IMPORTED} " = +(* ${g_FUNCNAME} *) ]]
    then
	echo -e "\nSyntax error: duplicate SUB or FUNCTION name at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Start miniparser to duplicate string arguments, convert spaces
    ARGS=$(Trim "${ORG#*\(}")

    # If there are no arguments to the function at all
    if [[ ${ARGS} != +(*\)) || -z $(echo ${ARGS%%\)*}) ]]
    then
	g_ORIGFUNCNAME="${g_ORIGFUNCNAME} void)"
	g_PROTOTYPE="${g_PROTOTYPE} void)"
    else
        while [[ -n ${ARGS} ]]
        do
	    # Get the arguments
            TOKEN=$(Mini_Parser "${ARGS}")
            ARGS="${ARGS:${#TOKEN}+1}"

	    if [[ $TOKEN = +(*VAR *) ]]
	    then
	        TOKEN=$(echo ${TOKEN//\)/})
		if [[ $ARGS = +(*,*) ]]
		then
		    echo -e "\nSyntax error: variable argument list cannot be followed by other arguments at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		elif [[ $g_PROTOTYPE = +(*,*) ]]
		then
		    echo -e "\nSyntax error: variable argument list cannot be preceded by other arguments at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		fi
                POS=$(Lexer " SIZE " "${TOKEN}")
		if [[ -z "${POS}" ]]
		then
		    echo -e "\nSyntax error: variable argument list lacks SIZE argument at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		fi
                SIZE=$(Trim "${TOKEN:$((${POS}+6))}")
                TOKEN=$(Trim "${TOKEN:0:${POS}}")
                POS=$(Lexer " TYPE " "${TOKEN}")
                if [[ -n ${POS} ]]
                then
                    TYPE=$(Trim "${TOKEN:$((${POS}+6))}")
                    TOKEN=$(Trim "${TOKEN:0:${POS}}")
                else
                    TYPE="long"
                fi
                POS=$(Lexer "VAR " "${TOKEN}")
                ARR=$(Trim "${TOKEN:$((${POS}+4))}")
		# These are in the function header, and do not exist yet - no need to check with Get_Var
		g_STRINGARGS="$g_STRINGARGS long ${SIZE};"
		Save_Func_Var ${SIZE} "${g_FUNCNAME}" "long"
		if [[ $(Check_String_Type ${ARR}) -eq 1 || "${TYPE}" = +(*STRING*|*char\*) ]]
		then
		    Save_Func_Var ${ARR} "${g_FUNCNAME}" "char*"
		    g_STRINGARGS="$g_STRINGARGS long __b2c__var_$ARR = $g_OPTION_BASE; va_list __b2c__ap; char **${ARR} = NULL; $ARR = (char **)calloc(__b2c__arg_tot+$g_OPTION_BASE, sizeof(char*));"
		    g_STRINGARGS="$g_STRINGARGS ${SIZE} = __b2c__arg_tot; va_start(__b2c__ap, __b2c__arg_tot); while (__b2c__arg_tot)"
                    g_STRINGARGS="$g_STRINGARGS { ${ARR}[__b2c__var_$ARR] = __b2c_Copy_String(${ARR}[__b2c__var_$ARR], va_arg(__b2c__ap, char*)); if(${ARR}[__b2c__var_$ARR] == NULL) { break; } __b2c__var_$ARR++; __b2c__arg_tot--; } va_end(__b2c__ap);"
		    g_PROTOTYPE="__${g_PROTOTYPE}int, ..."
		    g_ORIGFUNCNAME="${g_ORIGFUNCNAME}int __b2c__arg_tot, ..."
		    g_STRINGARRAYS="$g_STRINGARRAYS __b2c__free_str_array_members(&${ARR}, ${g_OPTION_BASE}, ${SIZE}); free($ARR);"
                    echo "#define ${g_FUNCNAME}(...) __${g_FUNCNAME}(sizeof((const char*[]) {__VA_ARGS__}) / sizeof(char*), (char*)__VA_ARGS__)" >> $g_HFILE
                else
                    # The var_args API always uses double when type actually is float. Prevent compile warnings.
		    if [[ "${ARR}" = +(*${g_FLOATSIGN}*) || ${TYPE} = "float" ]]
		    then
                        TYPE="double"
                    fi
                    Save_Func_Var ${ARR} "${g_FUNCNAME}" "${TYPE}*"
                    g_STRINGARGS="$g_STRINGARGS long __b2c__var_$ARR = $g_OPTION_BASE; va_list __b2c__ap; ${TYPE} *${ARR}; $ARR = (${TYPE}*)calloc(__b2c__arg_tot+$g_OPTION_BASE, sizeof(${TYPE}));"
		    g_STRINGARGS="$g_STRINGARGS ${SIZE} = __b2c__arg_tot; va_start(__b2c__ap, __b2c__arg_tot); while (__b2c__arg_tot)"
                    g_STRINGARGS="$g_STRINGARGS { ${ARR}[__b2c__var_$ARR] = (${TYPE})va_arg(__b2c__ap, ${TYPE}); __b2c__var_$ARR++; __b2c__arg_tot--; } va_end(__b2c__ap);"
		    g_PROTOTYPE="__${g_PROTOTYPE}int, ..."
		    g_ORIGFUNCNAME="${g_ORIGFUNCNAME}int __b2c__arg_tot, ..."
		    g_STRINGARRAYS="$g_STRINGARRAYS free($ARR);"
                    echo "#define ${g_FUNCNAME}(...) __${g_FUNCNAME}(sizeof((const ${TYPE}[]) {__VA_ARGS__}) / sizeof(${TYPE}), (${TYPE})__VA_ARGS__)" >> $g_HFILE
                fi
		# Add macro in case of VAR argument
		g_ORIGFUNCNAME="__${g_ORIGFUNCNAME}"
	    elif [[ ${TOKEN} = +(*STRING *) || ${TOKEN} = +(*char\* *) || ${TOKEN} = +(*${g_STRINGSIGN}*) ]]
	    then
                # Remove ')' when this is the last argument
                if [[ -z ${ARGS} ]]
                then
                    TOKEN=$(echo ${TOKEN%\)*})
                fi
                TOKEN=$(Trim "${TOKEN}")
		# Add type if it is missing
		if [[ ${TOKEN} != +(* *) ]]
		then
		    TOKEN="char* ${TOKEN}"
		fi
                # Check if already declared
                if [[ "${TOKEN##* }" = +(${g_C_KEYWORDS}) ]]
                then
	            echo -e "\nSyntax error: variable '${TOKEN##* }' in SUB/FUNCTION statement at line $g_COUNTER in file '$g_CURFILE' is a C keyword or function!"
	            exit 1
                elif [[ -z $(Get_Var ${TOKEN##* } ${g_FUNCNAME}) ]]
	        then
		    Save_Func_Var "${TOKEN##* }" "${g_FUNCNAME}" "${TOKEN% *}"
                else
                    if [[ $g_SEMANTIC -eq 0 ]]
                    then
	                echo -e "\nWARNING: variable '${TOKEN##* }' in function header at line $g_COUNTER in file '$g_CURFILE' was defined previously!"
                    fi
	        fi
		DIM=${TOKEN##*\[}; ARR=${TOKEN##* }
		if [[ $TOKEN != +(*${g_STRINGSIGN}*) && $TOKEN = +(*\[*\]*) ]]
		then
		    g_ORIGFUNCNAME="$g_ORIGFUNCNAME char *__b2c_${ARR%%\[*}[${DIM%%\]*}+$g_OPTION_BASE]"
		    g_STRINGARGS="$g_STRINGARGS char** ${ARR%%\[*} = __b2c_${ARR%%\[*};"
		    g_PROTOTYPE="$g_PROTOTYPE ${TOKEN}"
		elif [[ $TOKEN != +(*${g_STRINGSIGN}*) ]]
		then
		    g_ORIGFUNCNAME="$g_ORIGFUNCNAME ${TOKEN% *} __b2c_${TOKEN##* }"
		    g_STRINGARGS="$g_STRINGARGS ${TOKEN% *} ${TOKEN##* } = __b2c_${TOKEN##* };"
		    g_PROTOTYPE="$g_PROTOTYPE ${TOKEN}"
		elif [[ $TOKEN = +(*\[*\]*) ]]
		then
		    if [[ -z ${DIM%%\]*} ]]
		    then
			g_ORIGFUNCNAME="$g_ORIGFUNCNAME ${TOKEN}"
			g_PROTOTYPE="$g_PROTOTYPE ${TOKEN}"
		    else
			g_ORIGFUNCNAME="$g_ORIGFUNCNAME char *__b2c_${ARR%%\[*}[${DIM%%\]*}+$g_OPTION_BASE]"
			g_STRINGARGS="$g_STRINGARGS char *${ARR%%\[*}[${DIM%%\]*}+$g_OPTION_BASE] = { NULL };"
			g_STRINGARGS="$g_STRINGARGS for(__b2c__ctr=0; __b2c__ctr<${DIM%%\]*}+$g_OPTION_BASE; __b2c__ctr++){if(__b2c_${ARR%%\[*}[__b2c__ctr]!=NULL) ${ARR%%\[*}[__b2c__ctr] = __b2c_Copy_String(${ARR%%\[*}[__b2c__ctr], __b2c_${ARR%%\[*}[__b2c__ctr]); }"
			g_STRINGARRAYS="$g_STRINGARRAYS for(__b2c__ctr=0; __b2c__ctr<${DIM%%\]*}+$g_OPTION_BASE; __b2c__ctr++) { __b2c__STRFREE(${ARR%%\[*}[__b2c__ctr]); }"
			g_PROTOTYPE="$g_PROTOTYPE char *__b2c_${TOKEN##* }"
		    fi
		else
		    g_ORIGFUNCNAME="$g_ORIGFUNCNAME char *__b2c_${TOKEN##* }"
		    g_STRINGARGS="$g_STRINGARGS char*${TOKEN##* } = NULL; ${TOKEN##* } = __b2c_Copy_String(${TOKEN##* }, __b2c_${TOKEN##* });"
		    g_LOCALSTRINGS="$g_LOCALSTRINGS ${TOKEN##* }"
		    g_PROTOTYPE="$g_PROTOTYPE ${TOKEN}"
		fi
	    else
                # Remove ')' when this is the last argument
                if [[ -z ${ARGS} ]]
                then
                    TOKEN=$(echo ${TOKEN%\)*})
                fi
                TOKEN=$(Trim "${TOKEN}")
		# Add type if it is missing
		if [[ ${TOKEN} != +(* *) && ${TOKEN} != +(DIR*|FILE*|int*|short*|long*|float*|double*|char*|void*|STRING*|NUMBER*|FLOATING*) ]]
		then
		    if [[ ${TOKEN} = +(*${g_FLOATSIGN}) ]]
		    then
			TOKEN="double ${TOKEN}"
		    else
			TOKEN="${g_VARTYPE} ${TOKEN}"
		    fi
                fi
                # Check if already declared
                if [[ "${TOKEN##* }" = +(${g_C_KEYWORDS}) ]]
                then
	            echo -e "\nSyntax error: variable '${TOKEN##* }' in SUB/FUNCTION statement at line $g_COUNTER in file '$g_CURFILE' is a C keyword or function!"
	            exit 1
                elif [[ -z $(Get_Var ${TOKEN##* } ${g_FUNCNAME}) ]]
	        then
		    Save_Func_Var "${TOKEN##* }" "${g_FUNCNAME}" "${TOKEN% *}"
                else
                    if [[ $g_SEMANTIC -eq 0 ]]
                    then
	                echo -e "\nWARNING: variable '${TOKEN##* }' in function header at line $g_COUNTER in file '$g_CURFILE' was defined previously!"
                    fi
	        fi
		if [[ $TOKEN = +(*\[*\]*\]*) ]]
		then
		    echo -e "\nSyntax error: cannot pass multidimensional numeric array at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		elif [[ $TOKEN = +(*\[\]*) ]]
		then
		    g_ORIGFUNCNAME="$g_ORIGFUNCNAME ${TOKEN}"
		elif [[ $TOKEN = +(*\[*\]*) ]]
		then
		    DIM=${TOKEN##*\[}; ARR=${TOKEN##* }
		    g_ORIGFUNCNAME="$g_ORIGFUNCNAME ${TOKEN%% *} __b2c_${ARR%%\[*}[${DIM%%\]*}+$g_OPTION_BASE]"
		    g_STRINGARGS="$g_STRINGARGS ${TOKEN%% *} ${ARR%%\[*}[${DIM%%\]*}+$g_OPTION_BASE] = { 0 };"
                    g_STRINGARGS="$g_STRINGARGS memmove(${ARR%%\[*}, __b2c_${ARR%%\[*}, (${DIM%%\]*}+$g_OPTION_BASE)*sizeof(${TOKEN%% *}));"
		else
		    g_ORIGFUNCNAME="$g_ORIGFUNCNAME ${TOKEN}"
		fi
		g_PROTOTYPE="$g_PROTOTYPE ${TOKEN}"
	    fi
	    if [[ -n ${ARGS} ]]
	    then
		g_ORIGFUNCNAME="${g_ORIGFUNCNAME},"
		g_PROTOTYPE="${g_PROTOTYPE},"
	    else
		g_ORIGFUNCNAME="${g_ORIGFUNCNAME})"
		g_PROTOTYPE="${g_PROTOTYPE})"
	    fi
        done
    fi

    # Make symbol known to parser
    g_IMPORTED="$g_FUNCNAME $g_IMPORTED"

    # Save CATCH routine
    g_ORIGCATCHGOTO="$g_CATCHGOTO"
    g_ORIGCATCH_USED=${g_CATCH_USED}
    g_CATCHGOTO="__B2C__PROGRAM__EXIT"
    g_CATCH_USED=0
    g_STRINGARGS="$g_STRINGARGS __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;"
    
    # Switch to header file
    g_COPY_CFILE=$g_CFILE
    g_COPY_COUNTER=$g_COUNTER
    g_CFILE=${g_CFILE%.*}.${g_FUNCNAME}.tmp

    touch $g_CFILE
}

#-----------------------------------------------------------

function Handle_Endsub
{
    typeset STR TFIL i TYPE

    # Check if we're in a SUB
    if [[ -z $g_FUNCNAME ]]
    then
	echo -e "\nSyntax error: ENDSUB outside SUB at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Put prototype to header file
    if [[ ${g_PROTOTYPE} != +(*::*) ]]
    then
        echo "void ${g_PROTOTYPE};" >> $g_HFILE
    fi
    g_PROTOTYPE=

    # Get original function name
    TFIL=${g_CURFILE##*/}
    echo "/* Created with Shell BaCon $g_VERSION - (c) Peter van Eerten - MIT License */" > ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    echo "#undef __b2c__exitval" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    echo "#define __b2c__exitval" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    if [[ "$g_ORIGFUNCNAME" = +(* \(*\)*) ]]
    then
	echo "void ${g_ORIGFUNCNAME} {" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    elif [[ "$g_ORIGFUNCNAME" = +(*\(*\)*) ]]
    then
	echo "void ${g_ORIGFUNCNAME} {" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    else
	echo "void ${g_FUNCNAME}(void) {" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    fi

    # Finalize sub
    echo "${g_STRINGARGS}" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    cat $g_CFILE >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h

    # Free strings variables if there are any
    echo "${g_STRINGARRAYS}" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    for STR in $g_LOCALSTRINGS
    do
	echo "__b2c__STRFREE(${STR});" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    done
    if [[ $g_CATCH_USED -eq 1 ]]
    then
        echo "__B2C__PROGRAM__EXIT: ;" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    fi
    echo "__b2c__catch_set = __b2c__catch_set_backup;" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h
    echo "}" >> ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h

    # Include header file
    if [[ ${g_INCLUDE_FILES} != +(*${TFIL%.*}.$g_FUNCNAME.h*) ]]
    then
	g_INCLUDE_FILES="$g_INCLUDE_FILES ${TFIL%.*}.$g_FUNCNAME.h"
    fi

    # Add to total filelist
    g_TMP_FILES="$g_TMP_FILES ${g_TEMPDIR}/${TFIL%.*}.$g_FUNCNAME.h"

    # Delete temp funcfile
    rm $g_CFILE

    # Restore mainfile
    g_CFILE=$g_COPY_CFILE

    # Restore CATCH routine
    g_CATCHGOTO="$g_ORIGCATCHGOTO"
    g_CATCH_USED=${g_ORIGCATCH_USED}

    # Reset variables
    g_ORIGFUNCNAME=
    g_FUNCNAME=
    g_LOCALSTRINGS=
    g_STRINGARRAYS=
    g_STRINGARGS=
}

#-----------------------------------------------------------

function Handle_Deffn
{
    typeset VAR STR POS ARGS=${1}

    # Check if we have an argument at all
    if [[ "$1" = "DEF" ]]
    then
	echo -e "\nSyntax error: empty DEF FN at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Translate to C macro
    POS=$(Lexer "=" "${ARGS}")
    if [[ -n ${POS} ]]
    then
        STR=$(Trim "${ARGS:$((${POS}+1))}")
        VAR=$(Trim "${ARGS:0:${POS}}")
        VAR=$(echo ${VAR#* })
    else
        VAR=$(Trim "${ARGS:3}")
    fi
    echo "#define ${VAR} (${STR})" >> $g_HFILE

    # Needed in TOKENIZE to determine amount of intermediate strings
    if [[ $(echo ${VAR%%\(*}) = +(*${g_STRINGSIGN}) ]]
    then
        g_MACRO_STRINGS[${VAR%%\(*}]="${STR}"
    fi

    # Make symbol known to parser
    g_IMPORTED="${VAR%%\(*} $g_IMPORTED"
}

#-----------------------------------------------------------

function Handle_Const
{
    typeset VAR STR POS ARGS=${1}

    # Check if we have an argument at all
    if [[ "$1" = "CONST" ]]
    then
	echo -e "\nSyntax error: empty CONST at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Translate to C macro
    POS=$(Lexer "=" "${ARGS}")
    if [[ -n ${POS} ]]
    then
        STR=$(Trim "${ARGS:$((${POS}+1))}")
        VAR=$(Trim "${ARGS:0:${POS}}")
    else
        VAR=$(Trim "${ARGS:0}")
    fi
    echo "#define ${VAR} (${STR})" >> $g_HFILE

    # Needed in TOKENIZE to determine amount of intermediate strings
    if [[ ${VAR} = +(*${g_STRINGSIGN}) ]]
    then
        g_MACRO_STRINGS[${VAR}]="${STR}"
    fi
}

#-----------------------------------------------------------

function Handle_Seek
{
    typeset FILE OFFSET WHENCE POS ARGS=${1}

    # Check if TO is available
    if [[ "$1" != +(* OFFSET *) ]]
    then
	echo -e "\nSyntax error: missing OFFSET in SEEK statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " WHENCE " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        WHENCE=$(Trim "${ARGS:$((${POS}+8))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " OFFSET " "${ARGS}")
    OFFSET=$(Trim "${ARGS:$((${POS}+8))}")
    FILE=$(Trim "${ARGS:0:${POS}}")

    # Convert to C function
    case $WHENCE in
	+(START) )
	    echo "fseek($FILE, $OFFSET, SEEK_SET);" >> $g_CFILE;;
	+(CURRENT) )
	    echo "fseek($FILE, $OFFSET, SEEK_CUR);" >> $g_CFILE;;
	+(END) )
	    echo "fseek($FILE, $OFFSET, SEEK_END);" >> $g_CFILE;;
	*)
	    echo "fseek($FILE, $OFFSET, SEEK_SET);" >> $g_CFILE;;
    esac
}

#-----------------------------------------------------------

function Handle_Copy
{
    typeset FROM TO SIZE POS ARGS=${1}

    # Check if TO is available
    if [[ "$1" != +(* TO *) ]]
    then
	echo -e "\nSyntax error: missing TO in COPY statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " SIZE " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        SIZE=$(Trim "${ARGS:$((${POS}+6))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " TO " "${ARGS}")
    TO=$(Trim "${ARGS:$((${POS}+4))}")
    FROM=$(Trim "${ARGS:0:${POS}}")

    # Translate to C function
    if [[ -z $SIZE ]]
    then
        echo "if(__b2c__copy(${FROM}, ${TO})){ if(__b2c__trap){ ERROR = 2; if(!__b2c__catch_set) RUNTIMEERROR(\"COPY\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
    else
	echo "if (__b2c__trap){if(!__b2c__memory__check((char*)${TO}, sizeof(__b2c__MEMTYPE)*${SIZE})) {ERROR=1; if(!__b2c__catch_set) RUNTIMEERROR(\"COPY\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
        if [[ ${FROM} = +(*${g_STRINGSIGN}*) ]]
        then
            echo "__b2c__free_str_array_members(&${TO}, ${g_OPTION_BASE}, ${SIZE});" >> $g_CFILE
            echo "if(${FROM}[__b2c__ctr+$g_OPTION_BASE]!=NULL) ${TO}[__b2c__ctr+$g_OPTION_BASE]=strdup(${FROM}[__b2c__ctr+$g_OPTION_BASE]);}" >> $g_CFILE
        else
            echo "memmove((void*)${TO}, (void*)${FROM}, sizeof(__b2c__MEMTYPE)*${SIZE});" >> $g_CFILE
        fi
    fi
    if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
    then
        g_CATCH_USED=1
    fi
}

#-----------------------------------------------------------

function Handle_Rename
{
    typeset FROM TO POS ARGS=${1}

    # Check if TO is available
    if [[ "$1" != +(* TO *) ]]
    then
	echo -e "\nSyntax error: missing TO in RENAME statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the filename and copyname
    POS=$(Lexer " TO " "${ARGS}")
    TO=$(Trim "${ARGS:$((${POS}+4))}")
    FROM=$(Trim "${ARGS:0:${POS}}")

    # Translate to C function
    echo "if(rename($FROM, $TO) < 0) {if(__b2c__trap){ERROR = 9; if(!__b2c__catch_set) RUNTIMEERROR(\"RENAME\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
    if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
    then
        g_CATCH_USED=1
    fi
}

#-----------------------------------------------------------

function Handle_Color
{
    typeset TO FROM BFG COL

    # Check syntax
    if [[ "$1" = +(*RESET*) && "${1}" != +(* TO *) ]]
    then
	echo "fputs(\"\033[0m\", stdout); fflush(stdout);" >> $g_CFILE
    elif [[ "$1" = +(*INTENSE*) && "${1}" != +(* TO *) ]]
    then
	echo "fputs(\"\033[1m\", stdout); fflush(stdout);" >> $g_CFILE
    elif [[ "$1" = +(*INVERSE*) && "${1}" != +(* TO *) ]]
    then
	echo "fputs(\"\033[7m\", stdout); fflush(stdout);" >> $g_CFILE
    elif [[ "$1" = +(*NORMAL*) && "${1}" != +(* TO *) ]]
    then
	echo "fputs(\"\033[22m\", stdout); fflush(stdout);" >> $g_CFILE
    elif [[ "$1" != +(* TO *) ]]
    then
	echo -e "\nSyntax error: missing TO in COLOR statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    else
	# Get the target and colorname
	FROM=$(echo ${1%% TO *})
	case $FROM in
	    FG)
		BFG=3;;
	    BG)
		BFG=4;;
	    [01])
		((BFG=${FROM}+3));;
	    *)
		BFG=${FROM};;
	esac
	TO=$(echo ${1##* TO })
        if [[ ${TO} = +(*INTENSE*) ]]
        then
	    echo "fputs(\"\033[1m\", stdout); fflush(stdout);" >> $g_CFILE
            TO=$(echo ${TO//INTENSE/})
        fi
        if [[ ${TO} = +(*NORMAL*) ]]
        then
	    echo "fputs(\"\033[22m\", stdout); fflush(stdout);" >> $g_CFILE
            TO=$(echo ${TO//NORMAL/})
        fi
        case ${TO} in
	    BLACK)
		COL=0;;
	    RED)
		COL=1;;
	    GREEN)
		COL=2;;
	    YELLOW)
		COL=3;;
	    BLUE)
		COL=4;;
	    MAGENTA)
		COL=5;;
	    CYAN)
		COL=6;;
	    WHITE)
		COL=7;;
	    *)
		COL=${TO};;
	esac

	# Now select color
	echo "fprintf(stdout,\"\033[%ld%ldm\", (long)${BFG}, (long)${COL}); fflush(stdout);" >> $g_CFILE
    fi
}

#-----------------------------------------------------------

function Handle_Type
{
    typeset OFFSET=0 CFG TYPE

    # Check syntax
    if [[ "${1}" != +(*SET *) && "${1}" != +(*UNSET *) && "${1}" != +(*RESET*) ]]
    then
	echo -e "\nSyntax error: missing SET/UNSET/RESET in TYPE statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Check action
    if [[ "${1}" = +(*RESET*) ]]
    then
        echo "fputs(\"\033[23m\033[24m\033[25m\033[27m\033[29m\", stdout); fflush(stdout);" >> $g_CFILE
    else
        if [[ "${1}" = +(UNSET *) ]]
        then
            OFFSET=20
        fi
        if [[ "${1}" = +(*BOLD*) ]]
        then
            ((CFG=1+${OFFSET}))
            TYPE="${TYPE}\033[${CFG}m"
        fi
        if [[ "${1}" = +(*ITALIC*) ]]
        then
            ((CFG=3+${OFFSET}))
            TYPE="${TYPE}\033[${CFG}m"
        fi
        if [[ "${1}" = +(*UNDERLINE*) ]]
        then
            ((CFG=4+${OFFSET}))
            TYPE="${TYPE}\033[${CFG}m"
        fi
        if [[ "${1}" = +(*BLINK*) ]]
        then
            ((CFG=5+${OFFSET}))
            TYPE="${TYPE}\033[${CFG}m"
        fi
        if [[ "${1}" = +(*INVERSE*) ]]
        then
            ((CFG=7+${OFFSET}))
            TYPE="${TYPE}\033[${CFG}m"
        fi
        if [[ "${1}" = +(*STRIKE*) ]]
        then
            ((CFG=9+${OFFSET}))
            TYPE="${TYPE}\033[${CFG}m"
        fi
        if [[ -z ${TYPE} ]]
        then
	    echo -e "\nSyntax error: argument in TYPE statement not recognized at line $g_COUNTER in file '$g_CURFILE'!"
	    exit 1
        fi
        # Now set the type
        echo "fputs(\"${TYPE}\", stdout); fflush(stdout);" >> $g_CFILE
    fi
}

#-----------------------------------------------------------

function Handle_Gotoxy
{
    typeset ARG TOKEN

    # Check if we have an argument at all
    if [[ "$1" = "GOTOXY" ]]
    then
	echo -e "\nSyntax error: empty GOTOXY at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the target and colorname
    if [[ "$1" = +(*,*) ]]
    then
        TOKEN=$(Mini_Parser "${1}")
        ARG="${1:${#TOKEN}+1}"
    else
	echo -e "\nSyntax error: missing coordinate in GOTOXY at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Translate to C
    echo "fprintf(stdout, \"\033[%ld;%ldH\",(long)(${ARG}),(long)(${TOKEN}));fflush(stdout);" >> $g_CFILE
}

#-----------------------------------------------------------

function Handle_Split
{
    typeset SOURCE BY="__b2c__option_delim" TO SIZE POS ARGS=${1}
    typeset -i STATIC=0

    # Check if TO is available
    if [[ "$1" != +(* TO *) ]]
    then
	echo -e "\nSyntax error: missing TO in SPLIT statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " STATIC" "${ARGS}")
    if [[ -n ${POS} ]]
    then
        STATIC=1
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " SIZE " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        SIZE=$(Trim "${ARGS:$((${POS}+6))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " TO " "${ARGS}")
    TO=$(Trim "${ARGS:$((${POS}+4))}")
    ARGS=$(Trim "${ARGS:0:${POS}}")
    POS=$(Lexer " BY " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        BY=$(Trim "${ARGS:$((${POS}+4))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    SOURCE=$(Trim "${ARGS}")

    # Check type of var, string?
    if [[ $(Check_String_Type ${TO}) -eq 0 ]]
    then
	echo -e "\nSyntax error: variable ${TO} in SPLIT statement must be string at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Register numeric
    if [[ -n ${SIZE} ]]
    then
        Register_Numeric "${SIZE}" "default"
    fi

    # Translate to C code
    if [[ -n $g_FUNCNAME ]]
    then
        if [[ -z $(Get_Var ${TO} ${g_FUNCNAME}) ]]
	then
            g_DYNAMICARRAYS="${g_DYNAMICARRAYS} ${TO}@${g_FUNCNAME} "
	    g_STRINGARGS="$g_STRINGARGS char **${TO} = NULL; long ${TO}__b2c_array = 0;"
            Save_Func_Var "${TO}" "$g_FUNCNAME" "char*"
            Save_Func_Var "${TO}__b2c_array" "$g_FUNCNAME" "long"
	fi
    else
        if [[ -z $(Get_Var ${TO}) ]]
	then
            g_DYNAMICARRAYS="${g_DYNAMICARRAYS} ${TO}@${g_FUNCNAME} "
	    echo "char **$TO = NULL; long ${TO}__b2c_array = 0;" >> $g_HFILE
            Save_Main_Var "${TO}" "char*"
            Save_Main_Var "${TO}__b2c_array" "long"
	fi
    fi

    # Run the SPLIT code
    if [[ $(Check_String_Type ${BY}) -eq 1 || ${BY} = "__b2c__option_delim" ]]
    then
        echo "__b2c__split_by(&${TO}, ${g_OPTION_BASE}, &${TO}__b2c_array, ${SOURCE}, ${BY});" >> $g_CFILE
    else
        echo "__b2c__split_with(&${TO}, ${g_OPTION_BASE}, &${TO}__b2c_array, ${SOURCE}, ${BY});" >> $g_CFILE
    fi
    if [[ -n ${SIZE} ]]
    then
        echo "${SIZE} = ${TO}__b2c_array;" >> $g_CFILE
    fi

    # Add declared array to array list if we are in a function
    if [[ $STATIC -eq 0 ]]
    then
        if [[ -n $g_FUNCNAME && $g_STRINGARRAYS != +(*${TO}*) ]]
        then
            g_STRINGARRAYS="$g_STRINGARRAYS __b2c__free_str_array_members(&${TO}, ${g_OPTION_BASE}, ${TO}__b2c_array);"
            g_LOCALSTRINGS="$g_LOCALSTRINGS $TO"
        elif [[ -z $g_FUNCNAME && $g_GLOBALARRAYS != +(*${TO}*) ]]
        then
            g_GLOBALARRAYS="$g_GLOBALARRAYS __b2c__free_str_array_members(&${TO}, ${g_OPTION_BASE}, ${TO}__b2c_array); free(${TO});"
        fi
    fi
}

#-----------------------------------------------------------

function Handle_Join
{
    typeset SOURCE BY TO SIZE TYPE POS ARGS=${1}

    # Check if TO is available
    if [[ "$1" != +(* TO *) ]]
    then
	echo -e "\nSyntax error: missing TO in JOIN statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " SIZE " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        SIZE=$(Trim "${ARGS:$((${POS}+6))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " TO " "${ARGS}")
    TO=$(Trim "${ARGS:$((${POS}+4))}")
    ARGS=$(Trim "${ARGS:0:${POS}}")
    POS=$(Lexer " BY " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        BY=$(Trim "${ARGS:$((${POS}+4))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    else
	BY="__b2c_EMPTYSTRING"
    fi
    SOURCE=$(Trim "${ARGS}")

    # Determine size if not provided
    if [[ -z ${SIZE} ]]
    then
        if [[ $g_DYNAMICARRAYS = +(* ${SOURCE}@${g_FUNCNAME} *) ]]
        then
            SIZE="${SOURCE}__b2c_array"
        else
	    TYPE=$(Get_Var "${SOURCE}" ${g_FUNCNAME})
            SIZE="(sizeof(${SOURCE})/sizeof(${TYPE})-${g_OPTION_BASE})"
        fi
    fi

    # Check type of var, string?
    if [[ $(Check_String_Type ${TO}) -eq 0 ]]
    then
	echo -e "\nSyntax error: variable ${TO} in JOIN statement must be string at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    else
        if [[ "${TO}" = +(*${g_STRINGSIGN}) ]]
	then
            Register_Pointer "${TO}" "char*"
	fi
    fi

    # Translate function to C function
    echo "__b2c__join(&__b2c__assign, ${SOURCE}, ${g_OPTION_BASE}, ${SIZE}, ${BY});" >> $g_CFILE
    Assign_To_String "__b2c__assign" "${TO}"
}

#-----------------------------------------------------------

function Handle_Sort
{
    typeset SOURCE SIZE TYPE POS DOWN="" ARGS=${1}

    # Check if we have an argument at all
    if [[ "$1" = "SORT" ]]
    then
	echo -e "\nSyntax error: empty SORT at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " DOWN" "${ARGS}")
    if [[ -n ${POS} ]]
    then
        DOWN="_down"
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " SIZE " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        SIZE=$(Trim "${ARGS:$((${POS}+6))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    SOURCE=$(Trim "$ARGS")

    # Determine data type
    TYPE=$(Get_Var "__b2c__assoc_${SOURCE}" ${g_FUNCNAME})
    if [[ -n $TYPE ]]
    then
        if [[ ${TYPE} = +(*char\**|*STRING*) ]]
        then
            echo "__b2c__assoc_sort(&__b2c__assoc_${SOURCE}, 0, __b2c__sortstr${DOWN});" >> $g_CFILE
	elif [[ $TYPE = +(*double*) || $TYPE = +(*FLOATING*) ]]
	then
            echo "__b2c__assoc_sort(&__b2c__assoc_${SOURCE}, 1, __b2c__sortnrd_wrap${DOWN});" >> $g_CFILE
	elif [[ $TYPE = +(*float*) ]]
	then
            echo "__b2c__assoc_sort(&__b2c__assoc_${SOURCE}, 2, __b2c__sortnrf_wrap${DOWN});" >> $g_CFILE
	elif [[ $TYPE = +(*long*) || $TYPE = +(*NUMBER*) ]]
	then
            echo "__b2c__assoc_sort(&__b2c__assoc_${SOURCE}, 3, __b2c__sortnrl_wrap${DOWN});" >> $g_CFILE
	elif [[ $TYPE = +(*int*) ]]
	then
            echo "__b2c__assoc_sort(&__b2c__assoc_${SOURCE}, 4, __b2c__sortnri_wrap${DOWN});" >> $g_CFILE
	elif [[ $TYPE = +(*short*) ]]
	then
            echo "__b2c__assoc_sort(&__b2c__assoc_${SOURCE}, 5, __b2c__sortnrs_wrap${DOWN});" >> $g_CFILE
        elif [[ $TYPE = +(*char*) ]]
        then
            echo "__b2c__assoc_sort(&__b2c__assoc_${SOURCE}, 6, __b2c__sortnrc_wrap${DOWN});" >> $g_CFILE
        else
	    echo -e "\nSyntax error: unsupported associative array type in SORT at line $g_COUNTER in file '$g_CURFILE'!"
	    exit 1
	fi
    else
        TYPE=$(Get_Var ${SOURCE} ${g_FUNCNAME})
        if [[ -n $TYPE ]]
        then
            if [[ -z $SIZE ]]
            then
                if [[ $g_DYNAMICARRAYS = +(* ${SOURCE}@${g_FUNCNAME} *) ]]
                then
                    SIZE="${SOURCE}__b2c_array"
                else
                    SIZE="(sizeof(${SOURCE})/sizeof(${TYPE})-${g_OPTION_BASE})"
                fi
            fi
        else
            echo -e "\nSyntax error: unknown array '${SOURCE}' in SORT at line $g_COUNTER in file '$g_CURFILE'!"
            exit 1
        fi

        # Check size
        echo "if((${SIZE}-${g_OPTION_BASE}) < 0) {if(__b2c__trap){ERROR=36; if(!__b2c__catch_set) RUNTIMEERROR(\"SORT\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
        if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
        then
            g_CATCH_USED=1
        fi

        # Determine type
        if [[ "${SOURCE}" = +(*${g_STRINGSIGN}) ]]
        then
	    echo "qsort(&$SOURCE[$g_OPTION_BASE], ${SIZE}, sizeof(char*), __b2c__sortstr$DOWN);" >> $g_CFILE
        elif [[ $TYPE = +(*double*) || $TYPE = +(*FLOATING*) ]]
        then
	    echo "qsort(&$SOURCE[$g_OPTION_BASE], ${SIZE}, sizeof(double), __b2c__sortnrd$DOWN);" >> $g_CFILE
        elif [[ $TYPE = +(*float*) ]]
        then
	    echo "qsort(&$SOURCE[$g_OPTION_BASE], ${SIZE}, sizeof(float), __b2c__sortnrf$DOWN);" >> $g_CFILE
        elif [[ $TYPE = +(*long*) ||  $TYPE = +(*NUMBER*) ]]
        then
	    echo "qsort(&$SOURCE[$g_OPTION_BASE], ${SIZE}, sizeof(long), __b2c__sortnrl$DOWN);" >> $g_CFILE
        elif [[ $TYPE = +(*int*) ]]
        then
	    echo "qsort(&$SOURCE[$g_OPTION_BASE], ${SIZE}, sizeof(int), __b2c__sortnri$DOWN);" >> $g_CFILE
        elif [[ $TYPE = +(*short*) ]]
        then
	    echo "qsort(&$SOURCE[$g_OPTION_BASE], ${SIZE}, sizeof(short), __b2c__sortnrs$DOWN);" >> $g_CFILE
        elif [[ $TYPE = +(*char*) ]]
        then
	    echo "qsort(&$SOURCE[$g_OPTION_BASE], ${SIZE}, sizeof(char), __b2c__sortnrc$DOWN);" >> $g_CFILE
        else
	    echo -e "\nSyntax error: unsupported array type in SORT at line $g_COUNTER in file '$g_CURFILE'!"
	    exit 1
        fi
    fi
}

#-----------------------------------------------------------

function Handle_Alias
{
    typeset VAR TO ARGS=${1}

    # Check if TO is available
    if [[ "$1" != +(* TO *) ]]
    then
	echo -e "\nSyntax error: missing TO in ALIAS statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " TO " "${ARGS}")
    TO=$(Trim "${ARGS:$((${POS}+4))}" | tr -d "\042")
    VAR=$(Trim "${ARGS:0:${POS}}" | tr -d "\042")

    echo "#define ${TO} ${VAR}" >> $g_HFILE
    g_IMPORTED="${TO} ${g_IMPORTED}"
}

#-----------------------------------------------------------

function Handle_Lookup
{
    typeset SOURCE TO TYPE POS SIZE="" DOWN="" ARGS=${1}
    typeset -i STATIC=0 SORT=0

    # Check if TO is available
    if [[ "$1" != +(* TO *) ]]
    then
	echo -e "\nSyntax error: missing TO in LOOKUP statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " STATIC" "${ARGS}")
    if [[ -n ${POS} ]]
    then
        STATIC=1
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " DOWN" "${ARGS}")
    if [[ -n ${POS} ]]
    then
        DOWN="_down"
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " SORT" "${ARGS}")
    if [[ -n ${POS} ]]
    then
        SORT=1
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " SIZE " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        SIZE=$(Trim "${ARGS:$((${POS}+6))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " TO " "${ARGS}")
    TO=$(Trim "${ARGS:$((${POS}+4))}")
    SOURCE=$(Trim "${ARGS:0:${POS}}")

    # Check type of var, string?
    if [[ $(Check_String_Type ${TO}) -eq 0 ]]
    then
	echo -e "\nSyntax error: variable ${TO} in LOOKUP statement must be string at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Register numeric var
    if [[ -n ${SIZE} ]]
    then
         Register_Numeric "${SIZE}" "default"
    fi

    # Translate to C code
    if [[ -n $g_FUNCNAME ]]
    then
        if [[ -z $(Get_Var ${TO} ${g_FUNCNAME}) ]]
	then
            g_DYNAMICARRAYS="${g_DYNAMICARRAYS} ${TO}@${g_FUNCNAME} "
	    g_STRINGARGS="$g_STRINGARGS char **$TO = { NULL }; long ${TO}__b2c_array = 0;" 
            Save_Func_Var "${TO}" "$g_FUNCNAME" "char*"
            Save_Func_Var "${TO}__b2c_array" "$g_FUNCNAME" "long"
	fi
    else
        if [[ -z $(Get_Var ${TO}) ]]
	then
            g_DYNAMICARRAYS="${g_DYNAMICARRAYS} ${TO}@${g_FUNCNAME} "
	    echo "char **$TO = { NULL }; long ${TO}__b2c_array = 0;" >> $g_HFILE
            Save_Main_Var "${TO}" "char*"
            Save_Main_Var "${TO}__b2c_array" "long"
	fi
    fi

    # Run the LOOKUP code
    if [[ ${SORT} -eq 0 ]]
    then
        echo "${TO}__b2c_array = __b2c__lookup_by_order(__b2c__assoc_${SOURCE}, &${TO}, ${TO}__b2c_array, $g_OPTION_BASE);" >> $g_CFILE
    else
        TYPE=$(Get_Var __b2c__assoc_${SOURCE} ${g_FUNCNAME})
        if [[ ${TYPE} = +(*char\**|*STRING*) ]]
        then
            echo "${TO}__b2c_array = __b2c__lookup_by_sort(__b2c__assoc_${SOURCE}, &${TO}, ${TO}__b2c_array, $g_OPTION_BASE, 0, __b2c__sortstr${DOWN});" >> $g_CFILE
	elif [[ $TYPE = +(*double*) || $TYPE = +(*FLOATING*) ]]
	then
            echo "${TO}__b2c_array = __b2c__lookup_by_sort(__b2c__assoc_${SOURCE}, &${TO}, ${TO}__b2c_array, $g_OPTION_BASE, 1, __b2c__sortnrd_wrap${DOWN});" >> $g_CFILE
	elif [[ $TYPE = +(*float*) ]]
	then
            echo "${TO}__b2c_array = __b2c__lookup_by_sort(__b2c__assoc_${SOURCE}, &${TO}, ${TO}__b2c_array, $g_OPTION_BASE, 2, __b2c__sortnrf_wrap${DOWN});" >> $g_CFILE
	elif [[ $TYPE = +(*long*) || $TYPE = +(*NUMBER*) ]]
	then
            echo "${TO}__b2c_array = __b2c__lookup_by_sort(__b2c__assoc_${SOURCE}, &${TO}, ${TO}__b2c_array, $g_OPTION_BASE, 3, __b2c__sortnrl_wrap${DOWN});" >> $g_CFILE
	elif [[ $TYPE = +(*int*) ]]
	then
            echo "${TO}__b2c_array = __b2c__lookup_by_sort(__b2c__assoc_${SOURCE}, &${TO}, ${TO}__b2c_array, $g_OPTION_BASE, 4, __b2c__sortnri_wrap${DOWN});" >> $g_CFILE
	elif [[ $TYPE = +(*short*) ]]
	then
            echo "${TO}__b2c_array = __b2c__lookup_by_sort(__b2c__assoc_${SOURCE}, &${TO}, ${TO}__b2c_array, $g_OPTION_BASE, 5, __b2c__sortnrs_wrap${DOWN});" >> $g_CFILE
        elif [[ $TYPE = +(*char*) ]]
        then
            echo "${TO}__b2c_array = __b2c__lookup_by_sort(__b2c__assoc_${SOURCE}, &${TO}, ${TO}__b2c_array, $g_OPTION_BASE, 6, __b2c__sortnrc_wrap${DOWN});" >> $g_CFILE
        else
	    echo -e "\nSyntax error: unsupported array type in LOOKUP at line $g_COUNTER in file '$g_CURFILE'!"
	    exit 1
	fi
    fi
    if [[ -n ${SIZE} ]]
    then
        echo "${SIZE} = ${TO}__b2c_array;" >> $g_CFILE
    fi

    # Add declared array to array list if we are in a function
    if [[ $STATIC -eq 0 ]]
    then
        if [[ -n $g_FUNCNAME && $g_STRINGARRAYS != +(*${TO}__b2c_array*) ]]
        then
            g_STRINGARRAYS="$g_STRINGARRAYS __b2c__free_str_array_members(&${TO}, ${g_OPTION_BASE}, ${TO}__b2c_array);"
            g_LOCALSTRINGS="$g_LOCALSTRINGS $TO"
        elif [[ -z $g_FUNCNAME && $g_GLOBALARRAYS != +(*${TO}__b2c_array*) ]]
        then
            g_GLOBALARRAYS="$g_GLOBALARRAYS __b2c__free_str_array_members(&${TO}, ${g_OPTION_BASE}, ${TO}__b2c_array); free(${TO});"
        fi
    fi
}

#-----------------------------------------------------------

function Handle_Relate
{
    typeset SOURCE TO STR POS ARGS=${1}

    # Check if TO is available
    if [[ "$1" != +(* TO *) ]]
    then
	echo -e "\nSyntax error: missing TO in RELATE statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " TO " "${ARGS}")
    TO=$(Trim "${ARGS:$((${POS}+4))}")
    SOURCE=$(Trim "${ARGS:0:${POS}}" | tr "," " ")

    # Check if variable is declared as ASSOC
    if [[ -z $(Get_Var __b2c__assoc_${SOURCE})$(Get_Var __b2c__assoc_${SOURCE} ${g_FUNCNAME}) ]]
    then
	echo -e "\nSyntax error: variable '$SOURCE' not declared as ASSOC in RELATE statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Assign relations
    for STR in ${TO}
    do
        if [[ -z $(Get_Var __b2c__assoc_${STR})$(Get_Var __b2c__assoc_${STR} ${g_FUNCNAME}) ]]
	then
	    echo -e "\nSyntax error: variable '$STR' not declared as ASSOC in RELATE statement at line $g_COUNTER in file '$g_CURFILE'!"
	    exit 1
	fi
	g_RELATE[${g_RELATE_CTR}]="$SOURCE ${STR}"
	((g_RELATE_CTR+=1))
    done
}

#-----------------------------------------------------------

function Handle_Data
{
    typeset TOKEN ARGS=${1}

    # Check if we have an argument at all
    if [[ "$1" = "DATA" ]]
    then
	echo -e "\nSyntax error: empty DATA at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Start miniparser to see if we need to print something
    while [[ -n ${ARGS} ]]
    do
        TOKEN=$(Mini_Parser "${ARGS}")
	if [[ "${TOKEN}" = +(*${g_DQUOTESIGN}*) ]]
	then
	    echo -n "${TOKEN}, " >> $STRINGARRAYFILE
            ((g_CCTR+=1))
	else
	    echo -n "${TOKEN}, " >> $FLOATARRAYFILE
            ((g_FCTR+=1))
	fi
        ARGS="${ARGS:${#TOKEN}+1}"
    done

    # Align properly
    if [[ "${TOKEN}" = +(*${g_DQUOTESIGN}*) ]]
    then
	echo >> $STRINGARRAYFILE
    else
        echo >> $FLOATARRAYFILE
    fi
}

#-----------------------------------------------------------

function Handle_Redim
{
    typeset VAR TO CHECK TYPE POS ARGS=${1}

    # Check if TO is available
    if [[ "$1" != +(* TO *) ]]
    then
	echo -e "\nSyntax error: missing TO in REDIM statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the variable and resize
    POS=$(Lexer " TO " "${ARGS}")
    TO=$(Trim "${ARGS:$((${POS}+4))}")
    VAR=$(Trim "${ARGS:0:${POS}}")

    CHECK=$(Get_Var ${VAR} ${g_FUNCNAME})
    if [[ -z $CHECK && $(Check_String_Type ${VAR}) -eq 0 ]]
    then
	echo -e "\nSyntax error: cannot REDIM array which is not declared previously at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Delete old data from strings if new size is smaller
    if [[ $(Check_String_Type ${VAR}) -eq 1 ]]
    then
	echo "if(${TO} < ${VAR}__b2c_array) {for(__b2c__ctr=${TO}; __b2c__ctr<${VAR}__b2c_array; __b2c__ctr++) {__b2c__STRFREE($VAR[__b2c__ctr+$g_OPTION_BASE]);} }" >> $g_CFILE
        CHECK="char*"
    fi

    # Realloc
    TYPE=${CHECK}
    echo "${VAR} = (${TYPE}*)realloc(${VAR}, (${TO}+$g_OPTION_BASE)*sizeof(${TYPE}));" >> $g_CFILE

    # Re-initialize records if new area is bigger
    if [[ ${CHECK} = +(*_type) || ${CHECK} = +(*_TYPE) ]]
    then
	echo "if(__b2c_record_${VAR##*.} < ${TO}) { for(__b2c__ctr=__b2c_record_${VAR##*.}+$g_OPTION_BASE; __b2c__ctr<${TO}+$g_OPTION_BASE; __b2c__ctr++) memset(&$VAR[__b2c__ctr], 0, sizeof($CHECK));}" >> $g_CFILE
        echo "__b2c_record_${VAR##*.} = $TO;" >> $g_CFILE

    # Re-initialize strings if new area is bigger
    else
        if [[ $(Check_String_Type ${VAR}) -eq 1 ]]
        then
	    echo "if(${TO}>${VAR}__b2c_array) {for(__b2c__ctr=${VAR}__b2c_array; __b2c__ctr<${TO}; __b2c__ctr++) $VAR[__b2c__ctr+$g_OPTION_BASE] = (char*)calloc(1, sizeof(char));}" >> $g_CFILE
        fi
        echo "${VAR}__b2c_array = $TO;" >> $g_CFILE
    fi
}

#-----------------------------------------------------------

function Handle_Swap
{
    typeset VAR TO CHECK TYPE

    # Check if we have an argument at all
    if [[ "$1" = "SWAP" ]]
    then
	echo -e "\nSyntax error: empty SWAP at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the variable names without spaces
    VAR=`echo ${1%%,*} | tr -d "\040"`
    TO=`echo ${1##*,} | tr -d "\040"`

    # Perform universal swap
    if [[ $(Check_String_Type ${VAR}) -eq 1 && $(Check_String_Type ${TO}) -eq 0 ]]
    then
        echo "__b2c__assign = calloc(${g_MAX_DIGITS}+1, sizeof(char)); if (floor (${TO}) == ${TO}) { __b2c__ctr = snprintf(__b2c__assign, ${g_MAX_DIGITS}, \"%ld\", (long) ${TO}); }" >> $g_CFILE
        echo "else { __b2c__ctr = snprintf (__b2c__assign, ${g_MAX_DIGITS}, \"%g\", (double) ${TO}); } ${TO} = VAL(${VAR}); ${VAR} = __b2c_Copy_String(${VAR}, __b2c__assign); free(__b2c__assign);" >> $g_CFILE
    elif [[ $(Check_String_Type ${VAR}) -eq 0 && $(Check_String_Type ${TO}) -eq 1 ]]
    then
        echo "__b2c__assign = calloc(${g_MAX_DIGITS}+1, sizeof(char)); if (floor (${VAR}) == ${VAR}) { __b2c__ctr = snprintf(__b2c__assign, ${g_MAX_DIGITS}, \"%ld\", (long) ${VAR}); }" >> $g_CFILE
        echo "else { __b2c__ctr = snprintf (__b2c__assign, ${g_MAX_DIGITS}, \"%g\", (double) ${VAR}); } ${VAR} = VAL(${TO}); ${TO} = __b2c_Copy_String(${TO}, __b2c__assign); free(__b2c__assign);" >> $g_CFILE
    else
        # Determine type
        if [[ $(Check_String_Type ${VAR}) -eq 1 ]]
        then
            TYPE="char*"
        else
            CHECK=$(Get_Var ${VAR} ${g_FUNCNAME})
            if [[ -z $CHECK ]]
            then
	        echo -e "\nSyntax error: cannot determine type of variables in SWAP at line $g_COUNTER in file '$g_CURFILE'!"
	        exit 1
            fi
            # Leave one dimension out to exchange array variables
            TYPE=${CHECK%%\**}
        fi

        # Declare temp variable
        if [[ -n $g_FUNCNAME ]]
        then
            if [[ -z $(Get_Var __b2c__${VAR%%\[*}_swap ${g_FUNCNAME}) ]]
            then
	        g_STRINGARGS="$g_STRINGARGS ${TYPE} __b2c__${VAR%%\[*}_swap;"
                Save_Func_Var "__b2c__${VAR%%\[*}_swap" "${g_FUNCNAME}" "${TYPE}"
            fi
        else
            if [[ -z $(Get_Var __b2c__${VAR%%\[*}_swap) ]]
            then
                echo "${TYPE} __b2c__${VAR%%\[*}_swap;" >> $g_HFILE
                Save_Main_Var "__b2c__${VAR%%\[*}_swap" "${TYPE}"
            fi
        fi
        echo "__b2c__${VAR%%\[*}_swap = ${VAR}; ${VAR} = ${TO}; ${TO} = __b2c__${VAR%%\[*}_swap;" >> $g_CFILE
    fi
}

#-----------------------------------------------------------

function Handle_Setserial
{
    typeset DESC WHICH VALUE PARAM="0"
    typeset -i NOT=0

    # Check if a mode is available
    if [[ "$1" != +(* IMODE *) && "$1" != +(* OMODE *) && "$1" != +(* CMODE *) && "$1" != +(* LMODE *) && "$1" != +(* OTHER *) && "$1" != +(* SPEED *) ]]
    then
	echo -e "\nSyntax error: no mode specified in SETSERIAL statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    DESC=${1%% *}

    # Get the setting
    if [[ ${1} = +(* OTHER *) ]]
    then
        VALUE=${1##* OTHER }
    elif [[ ${1} = +(* SPEED *) ]]
    then
        VALUE=${1##* SPEED }
    else
        VALUE=${1##*MODE }
    fi

    case $1 in
        +(*IMODE*) )
            WHICH=0
            ;;
        +(*OMODE*) )
            WHICH=1
            ;;
        +(*CMODE*) )
            WHICH=2
            ;;
        +(*LMODE*) )
            WHICH=3
            ;;
        +(*OTHER*) )
            WHICH=4
            PARAM=${VALUE%=*}
            VALUE=${VALUE#*=}
            ;;
        +(*SPEED*) )
            WHICH=5
            ;;
    esac
    if [[ $VALUE = +(*~*) ]]
    then
        NOT=1
    fi

    echo "ERROR = __b2c_setserial(${DESC}, ${WHICH}, ${PARAM}, ${VALUE}, ${NOT});" >> $g_CFILE
    echo "if(ERROR && __b2c__trap){ if(!__b2c__catch_set) RUNTIMEERROR(\"SETSERIAL\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO; }" >> $g_CFILE

    if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
    then
        g_CATCH_USED=1
    fi
}

#-----------------------------------------------------------

function Handle_Call
{
    typeset ARG CHECK STR VAR

    # Check if we have an argument at all
    if [[ "$1" = "CALL" ]]
    then
	echo -e "\nSyntax error: empty CALL at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Make sure to set function syntax
    if [[ "${1%% TO*}" != +(*\(*\)*) ]]
    then
        if [[ "${1}" = +(* TO *) ]]
        then
            ARG="${1%% TO*}() TO ${1##* TO }"
        else
            ARG="${1}()"
        fi
    else
        ARG="${1}"
    fi

    # Just call, no assignment
    if [[ "${ARG}" != +(* TO *) ]]
    then
        echo "${ARG};" >> $g_CFILE
    else
        VAR="${ARG##*TO }"
        # Check if string is declared
        if [[ "${VAR}" = +(*${g_STRINGSIGN}) ]]
        then
            Register_Pointer "${VAR}" "char*"
        # Not a string?
        else
            Register_Numeric "${VAR}" "default"
        fi

        # String variable?
	if [[ $(Check_String_Type ${VAR}) -eq 1 ]]
	then
            echo "__b2c__assign = ${ARG%% TO*};" >> $g_CFILE
            Assign_To_String "__b2c__assign" "${VAR}"
        else
            Assign_To_Number "${ARG%% TO*}" "${VAR}" 0
	fi
    fi
}

#-----------------------------------------------------------

function Handle_Run
{
    # Local variables
    typeset ARG CHAR TOKEN LINE
    typeset -i LEN ESCAPED IN_STRING

    # Check if we have an argument at all
    if [[ "$1" = "RUN" ]]
    then
	echo -e "\nSyntax error: empty RUN at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Start miniparser to find separate arguments
    let ESCAPED=0
    let IN_STRING=0

    if [[ ${1:0:1} = ${g_DQUOTESIGN} ]]
    then
        # Skip first doublequote
        let LEN=${#1}-1
        # Replace spaces
        LINE=$(echo ${1// /${g_PARSEVAR}})
        # Line start on character after doublequote
        LINE="${LINE: -$LEN}"

        ARG="\""

        # Get the characters
        until [[ $LEN -eq 1 ]]
        do
	    CHAR="${LINE:0:1}"
	    case $CHAR in
	        "\\")
		    if [[ $ESCAPED -eq 1 ]]
		    then
		        ESCAPED=0
                    else
		        ESCAPED=1
		        CHAR=
                    fi;;
	        "\"")
		    if [[ $ESCAPED -eq 1 ]]
		    then
		        if [[ $IN_STRING -eq 0 ]]
		        then
			    IN_STRING=1
		        else
			    IN_STRING=0
		        fi
		        CHAR=
		    fi
		    ESCAPED=0;;
	        ${g_PARSEVAR})
		    if [[ $IN_STRING -eq 0 ]]
		    then
		        ARG="$ARG\",\""
		        CHAR=
		    fi
		    ESCAPED=0;;
	        *)
		    ESCAPED=0;;
	    esac
	    # Convert back to space
	    if [[ "${CHAR}" = "${g_PARSEVAR}" ]]
	    then
	        ARG="${ARG} "
	    else
	        ARG="${ARG}${CHAR}"
	    fi
	    let LEN=${#LINE}-1
	    LINE="${LINE: -$LEN}"
        done
        ARG="${ARG}\""

        # Get first token
        TOKEN=$(Mini_Parser "${ARG}")
        echo "execlp($TOKEN,$ARG, NULL); fflush(stdout);" >> $g_CFILE
    else
        echo "execlp($1, $1, NULL); fflush(stdout);" >> $g_CFILE
    fi
}

#-----------------------------------------------------------

function Handle_Save
{
    typeset VAR TO SIZE=0 TOKEN POS ARGS=${2}

    # Check if we have an argument at all
    if [[ "${ARGS}" != +(* TO *) ]]
    then
	echo -e "\nSyntax error: SAVE/BSAVE/APPEND/BAPPEND without TO at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " SIZE " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        SIZE=$(Trim "${ARGS:$((${POS}+6))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " TO " "${ARGS}")
    TO=$(Trim "${ARGS:$((${POS}+4))}")
    VAR=$(Trim "${ARGS:0:${POS}}")

    # How to open the file
    echo "ERROR = __b2c__save(${1}, ${SIZE}, ${TO}, ${VAR}, NULL);" >> $g_CFILE
    echo "if(ERROR && __b2c__trap) { if(!__b2c__catch_set) RUNTIMEERROR(\"SAVE/BSAVE/APPEND/BAPPEND\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO; }" >> $g_CFILE
    if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
    then
        g_CATCH_USED=1
    fi
}

#-----------------------------------------------------------

function Handle_Map
{
    typeset SOURCE BY TO SIZE TYPE i POS ARGS=${1}
    typeset -i STATIC=0

    # Check if we have an argument at all
    if [[ "$1" = "MAP" ]]
    then
	echo -e "\nSyntax error: empty MAP at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi
    
    # Check if BY is available
    if [[ "$1" != +(* BY *) ]]
    then
	echo -e "\nSyntax error: missing BY in MAP statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Check if TO is available
    if [[ "$1" != +(* TO *) ]]
    then
	echo -e "\nSyntax error: missing TO in MAP statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " STATIC" "${ARGS}")
    if [[ -n ${POS} ]]
    then
        STATIC=1
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " SIZE " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        SIZE=$(Trim "${ARGS:$((${POS}+6))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " TO " "${ARGS}")
    TO=$(Trim "${ARGS:$((${POS}+4))}")
    ARGS=$(Trim "${ARGS:0:${POS}}")
    POS=$(Lexer " BY " "${ARGS}")
    BY=$(Trim "${ARGS:$((${POS}+4))}")
    SOURCE=$(Trim "${ARGS:0:${POS}}")

    # Determine size if not provided
    if [[ -z ${SIZE} ]]
    then
        if [[ $g_DYNAMICARRAYS = +(* ${SOURCE%%,*}@${g_FUNCNAME} *) ]]
        then
            SIZE="${SOURCE%%,*}__b2c_array"
        else
	    TYPE=$(Get_Var "${SOURCE%%,*}" ${g_FUNCNAME})
            SIZE="(sizeof(${SOURCE%%,*})/sizeof(${TYPE})-${g_OPTION_BASE})"
        fi
    fi
        
    # Remove doublequotes from BY
    BY=$(echo ${BY} | tr -d "\042")

    # Make sure to get the type right
    SOURCE=${SOURCE// /}
    TYPE="long"

    if [[ $(Check_String_Type ${BY}) -eq 1 ]]
    then
        TYPE="char*"
    else
        for i in ${SOURCE//,/ }
        do
	    if [[ $(Get_Var ${i} ${g_FUNCNAME}) = +(*double*|*FLOATING*) ]]
	    then
	        TYPE="double"
	        break
	    fi
        done
    fi

    # Declare target array
    if [[ -z $(Get_Var ${TO} ${g_FUNCNAME}) ]]
    then
        if [[ $g_OPTION_EXPLICIT = "1" || $g_OPTION_EXPLICIT = "TRUE" ]]
        then
	    echo -e "\nSyntax error: OPTION EXPLICIT forces explicit variable declaration at line $g_COUNTER in file '$g_CURFILE'!"
            exit 1
        fi
	if [[ -n $g_FUNCNAME ]]
	then
            g_DYNAMICARRAYS="${g_DYNAMICARRAYS} ${TO}@${g_FUNCNAME} "
            echo "${TYPE}* $TO; long ${TO}__b2c_array;" >> $g_CFILE
            Save_Func_Var "${TO}" "$g_FUNCNAME" "${TYPE}*"
            Save_Func_Var "${TO}__b2c_array" "$g_FUNCNAME" "long"
	else
            g_DYNAMICARRAYS="${g_DYNAMICARRAYS} ${TO}@${g_FUNCNAME} "
            echo "${TYPE}* $TO; long ${TO}__b2c_array;" >> $g_HFILE
            Save_Main_Var "${TO}" "${TYPE}*"
            Save_Main_Var "${TO}__b2c_array" "long"
	fi
        echo "$TO = (${TYPE}*)calloc((size_t)($SIZE+$g_OPTION_BASE), sizeof(${TYPE}));" >> $g_CFILE
        echo "${TO}__b2c_array = ${SIZE};" >> $g_CFILE

        # Cleanup local array members
	if [[ $STATIC -eq 0 ]]
	then
            if [[ ${TYPE} = "char*" ]]
            then
	        if [[ -n $g_FUNCNAME ]]
                then
                    g_STRINGARRAYS="$g_STRINGARRAYS __b2c__free_str_array_members(&${TO}, ${g_OPTION_BASE}, ${SIZE});"
                else
                    g_GLOBALARRAYS="$g_GLOBALARRAYS free(${TO});"
                fi
            fi
	    g_LOCALSTRINGS="$g_LOCALSTRINGS $TO"
	fi
    fi

    # Create the C code
    echo "for(__b2c__ctr=$g_OPTION_BASE; __b2c__ctr<${SIZE}+$g_OPTION_BASE; __b2c__ctr++){" >> $g_CFILE
    if [[ ${TYPE} = "char*" ]]
    then
        echo "${TO}[__b2c__ctr] = __b2c_Copy_String(${TO}[__b2c__ctr], ${BY}(${SOURCE//,/[__b2c__ctr],}[__b2c__ctr])); }" >> $g_CFILE
    else
        echo "${TO}[__b2c__ctr] = ${BY}(${SOURCE//,/[__b2c__ctr],}[__b2c__ctr]); }" >> $g_CFILE
    fi
}

#-----------------------------------------------------------

function Handle_Tree
{
    typeset TREE NODE TYPE FUNC POS UNIQ ARGS=${1}

    # Check if NODE is available
    if [[ "$1" != +(* NODE *) && "$1" != +(* ADD *) ]]
    then
	echo -e "\nSyntax error: missing NODE/ADD in TREE statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " TYPE " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        TYPE=$(Trim "${ARGS:$((${POS}+6))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    if [[ ${ARGS} = +(* NODE *) ]]
    then
        POS=$(Lexer " NODE " "${ARGS}")
        NODE=$(Trim "${ARGS:$((${POS}+6))}")
    else
        POS=$(Lexer " ADD " "${ARGS}")
        NODE=$(Trim "${ARGS:$((${POS}+5))}")
    fi
    TREE=$(Trim "${ARGS:0:${POS}}")

    if [[ -z ${TYPE} ]]
    then
        FUNC=$(Get_Var "__b2c__tree_${TREE}" ${g_FUNCNAME})
        TYPE=${FUNC#*:}
    fi
    if [[ ${TYPE} = +(*char\**) ]]
    then
        echo "__b2c__assign = __b2c_Copy_String(NULL, ${NODE}); __b2c__tree_add((void*)__b2c__assign, &${TREE}, ${FUNC%:*});" >> $g_CFILE
    else
        UNIQ="__b2c__${SYM}_${g_COUNTER}_${RANDOM}"
        echo "${TYPE} *${UNIQ} = (${TYPE}*)malloc(sizeof($TYPE)); *${UNIQ} = (${TYPE})${NODE}; __b2c__tree_add((void*)${UNIQ}, &${TREE}, ${FUNC%:*});" >> $g_CFILE
    fi

    if [[ -n $g_FUNCNAME ]]
    then
        if [[ ${g_STRINGARRAYS} != +(*__b2c__binary_tree_free\(${TREE},*) ]]
        then
            g_STRINGARRAYS="$g_STRINGARRAYS __b2c__binary_tree_free(${TREE}, ${FUNC%:*});"
        fi
    else
        if [[ ${g_GLOBALARRAYS} != +(*__b2c__binary_tree_free\(${TREE},*) ]]
        then
            g_GLOBALARRAYS="$g_GLOBALARRAYS __b2c__binary_tree_free(${TREE}, ${FUNC%:*});"
        fi
    fi
}

#-----------------------------------------------------------

function Handle_Collect
{
    typeset SOURCE TO FUNC TYPE POS NR SIZE="" ARGS=${1}
    typeset -i STATIC=0

    # Check if TO is available
    if [[ "$1" != +(* TO *) ]]
    then
	echo -e "\nSyntax error: missing TO in COLLECT statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " STATIC" "${ARGS}")
    if [[ -n ${POS} ]]
    then
        STATIC=1
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " SIZE " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        SIZE=$(Trim "${ARGS:$((${POS}+6))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " TO " "${ARGS}")
    TO=$(Trim "${ARGS:$((${POS}+4))}")
    SOURCE=$(Trim "${ARGS:0:${POS}}")

    # Register numeric var
    if [[ -n ${SIZE} ]]
    then
         Register_Numeric "${SIZE}" "default"
    fi

    # Get the type
    FUNC=$(Get_Var "__b2c__tree_${SOURCE}" ${g_FUNCNAME})
    TYPE=${FUNC#*:}

    # Translate to C code
    if [[ -n $g_FUNCNAME ]]
    then
        if [[ -z $(Get_Var ${TO} ${g_FUNCNAME}) ]]
	then
            g_DYNAMICARRAYS="${g_DYNAMICARRAYS} ${TO}@${g_FUNCNAME} "
	    g_STRINGARGS="$g_STRINGARGS ${TYPE}* ${TO} = { NULL }; long ${TO}__b2c_array = $g_OPTION_BASE;" 
            Save_Func_Var "${TO}" "$g_FUNCNAME" "${TYPE}*"
            Save_Func_Var "${TO}__b2c_array" "$g_FUNCNAME" "long"
	fi
    else
        if [[ -z $(Get_Var ${TO}) ]]
	then
            g_DYNAMICARRAYS="${g_DYNAMICARRAYS} ${TO}@${g_FUNCNAME} "
	    echo "${TYPE}* $TO = { NULL }; long ${TO}__b2c_array = $g_OPTION_BASE;" >> $g_HFILE
            Save_Main_Var "${TO}" "${TYPE}*"
            Save_Main_Var "${TO}__b2c_array" "long"
        fi
    fi

    # Run the COLLECT code
    case ${TYPE} in
        "char*"|"STRING")
            NR=0;;
        "double"|"FLOATING")
            NR=1;;
        "float")
            NR=2;;
        "long"|"NUMBER")
            NR=3;;
        "int")
            NR=4;;
        "short")
            NR=5;;
        "char")
            NR=6;;
    esac
    echo "${TO}__b2c_array = __b2c__collect(${SOURCE}, (void***)&${TO}, $g_OPTION_BASE, ${NR});" >> $g_CFILE
    if [[ -n ${SIZE} ]]
    then
        echo "${SIZE} = ${TO}__b2c_array;" >> $g_CFILE
    fi

    # Add declared array to array list if we are in a function
    if [[ $STATIC -eq 0 ]]
    then
        if [[ -n $g_FUNCNAME && $g_STRINGARRAYS != +(*\(${TO}\)*) ]]
        then
            g_STRINGARRAYS="$g_STRINGARRAYS free(${TO});"
        elif [[ -z $g_FUNCNAME && $g_GLOBALARRAYS != +(*\(${TO}\)*) ]]
        then
            g_GLOBALARRAYS="$g_GLOBALARRAYS free(${TO});"
        fi
    fi
}

#-----------------------------------------------------------

function Handle_Parse
{
    typeset SOURCE BY="__b2c__option_delim" TO SIZE POS WITH ARGS=${1}
    typeset -i STATIC=0

    # Check if WITH is available
    if [[ "$1" != +(* WITH *) ]]
    then
	echo -e "\nSyntax error: missing WITH in PARSE statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi
    
    # Check if TO is available
    if [[ "$1" != +(* TO *) ]]
    then
	echo -e "\nSyntax error: missing TO in PARSE statement at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Get the arguments
    POS=$(Lexer " STATIC" "${ARGS}")
    if [[ -n ${POS} ]]
    then
        STATIC=1
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " SIZE " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        SIZE=$(Trim "${ARGS:$((${POS}+6))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " TO " "${ARGS}")
    TO=$(Trim "${ARGS:$((${POS}+4))}")
    ARGS=$(Trim "${ARGS:0:${POS}}")
    POS=$(Lexer " BY " "${ARGS}")
    if [[ -n ${POS} ]]
    then
        BY=$(Trim "${ARGS:$((${POS}+4))}")
        ARGS=$(Trim "${ARGS:0:${POS}}")
    fi
    POS=$(Lexer " WITH " "${ARGS}")
    WITH=$(Trim "${ARGS:$((${POS}+6))}")
    ARGS=$(Trim "${ARGS:0:${POS}}")
    SOURCE=$(Trim "${ARGS}")

    # Check type of var, string?
    if [[ $(Check_String_Type ${TO}) -eq 0 ]]
    then
	echo -e "\nSyntax error: variable ${TO} in PARSE statement must be string at line $g_COUNTER in file '$g_CURFILE'!"
	exit 1
    fi

    # Register numeric
    if [[ -n ${SIZE} ]]
    then
        Register_Numeric "${SIZE}" "default"
    fi

    # Translate to C code
    if [[ -n $g_FUNCNAME ]]
    then
        if [[ -z $(Get_Var ${TO} ${g_FUNCNAME}) ]]
	then
            g_DYNAMICARRAYS="${g_DYNAMICARRAYS} ${TO}@${g_FUNCNAME} "
	    g_STRINGARGS="$g_STRINGARGS char **${TO} = NULL; long ${TO}__b2c_array = 0;"
            Save_Func_Var "${TO}" "$g_FUNCNAME" "char*"
            Save_Func_Var "${TO}__b2c_array" "$g_FUNCNAME" "long"
	fi
    else
        if [[ -z $(Get_Var ${TO}) ]]
	then
            g_DYNAMICARRAYS="${g_DYNAMICARRAYS} ${TO}@${g_FUNCNAME} "
	    echo "char **$TO = NULL; long ${TO}__b2c_array = 0;" >> $g_HFILE
            Save_Main_Var "${TO}" "char*"
            Save_Main_Var "${TO}__b2c_array" "long"
	fi
    fi

    # Run the PARSE code
    echo "__b2c__parse(&${TO}, ${g_OPTION_BASE}, &${TO}__b2c_array, ${SOURCE}, ${WITH}, ${BY});" >> $g_CFILE

    if [[ -n ${SIZE} ]]
    then
        echo "${SIZE} = ${TO}__b2c_array;" >> $g_CFILE
    fi

    # Add declared array to array list if we are in a function
    if [[ $STATIC -eq 0 ]]
    then
        if [[ -n $g_FUNCNAME && $g_STRINGARRAYS != +(*${TO}*) ]]
        then
            g_STRINGARRAYS="$g_STRINGARRAYS __b2c__free_str_array_members(&${TO}, ${g_OPTION_BASE}, ${TO}__b2c_array);"
            g_LOCALSTRINGS="$g_LOCALSTRINGS $TO"
        elif [[ -z $g_FUNCNAME && $g_GLOBALARRAYS != +(*${TO}*) ]]
        then
            g_GLOBALARRAYS="$g_GLOBALARRAYS __b2c__free_str_array_members(&${TO}, ${g_OPTION_BASE}, ${TO}__b2c_array); free(${TO});"
        fi
    fi
}

#-----------------------------------------------------------
#
# Simple parser to tokenize line.
#
# Each line should begin with a statement.
# The rest of the line may contain functions, these are
#   converted using C macros.
#
#-----------------------------------------------------------

function Parse_Line
{
    typeset FOUND SYM INC COPY_COUNTER COPY_CURFILE STATEMENT CHECK FLINES TXT ARGS=${1}
    typeset LEN SEQ TOTAL EXP THEN LINE TO_PARSE NEWFEED TRC_BACKUP TOKEN POS UNIQ

    if [[ -z ${1} ]]
    then
        return
    fi

    # Get statement without spaces
    if [[ ${1} != +(*\*/) ]]
    then
        STATEMENT=$(echo ${1%% *})
    else
        STATEMENT=$(echo ${1})
    fi

    # See if we need to pass C code
    if [[ $g_USE_C -eq 1 ]]
    then
	if [[ ${@} = +(ENDUSEC|END USEC) ]]
	then
	    let g_USE_C=0
	elif [[ ${@} = +(ENDENUM|END ENUM) ]]
	then
	    let g_USE_C=0
            echo "};" >> $g_CFILE
	else
	    echo "${1}" >> $g_CFILE
	fi
    elif [[ $g_USE_H -eq 1 ]]
    then
	if [[ ${@} = +(ENDUSEH|END USEH) ]]
	then
	    let g_USE_H=0
	elif [[ ${@} = +(ENDENUM|END ENUM) || ${@} = +(ENDCLASS|END CLASS) ]]
	then
	    let g_USE_H=0
            echo "};" >> $g_HFILE
	else
	    echo "${1}" >> $g_HFILE
	fi
    elif [[ "$STATEMENT" = +(*\*/) ]]
    then
        let g_COMMENT=0
    elif [[ "$STATEMENT" = +(*/\**) ]]
    then
        let g_COMMENT=1
    elif [[ ${g_COMMENT} -eq 0 ]]
    then
	case "${STATEMENT}" in
	    "USEC")
		let g_USE_C=1;;
	    "USEH")
		let g_USE_H=1;;
	    "CLASS")
		let g_USE_H=1
                echo "class ${1#* } {" >> $g_HFILE;;
	    "PRINT")
		Handle_Print "${1#* }" "stdout";;
	    "EPRINT")
		Handle_Print "${1#* }" "stderr";;
	    "INPUT")
		Handle_Input "${1#* }";;
	    "FOR")
                ((g_LOOPCTR+=1))
		Handle_For "${1#* }";;
	    "NEXT")
		echo "}" >> $g_CFILE
                if [[ $g_LOOPCTR -gt 0 && $g_OPTION_BREAK = +(1*|TRUE*) ]]
                then
                    ((g_LOOPCTR-=1))
                    if [[ $g_LOOPCTR -gt 0 ]]
                    then
                        echo "if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }" >> $g_CFILE
                    fi
                fi;;
	    "IF")
		# Check if THEN is available
		if [[ "${1}" != +(* THEN*) ]]
		then
		    echo -e "\nSyntax error: missing THEN in IF statement at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
                    POS=$(Lexer " THEN" "${ARGS}")
                    THEN=$(Trim "${ARGS:$((${POS}+5))}")
                    SYM=$(Trim "${ARGS:0:${POS}}")
                    EXP=$(Trim "${SYM#*IF }")
		    # Translate function to C function
                    Parse_Equation "${EXP}"
		    echo "if(${g_EQUATION}){" >> $g_CFILE
		    if [[ -n ${THEN} ]]
		    then
                        TRC_BACKUP=${g_TRACE}
                        g_TRACE=0
			Tokenize "${THEN}"
                        g_TRACE=${TRC_BACKUP}
                        echo "}" >> $g_CFILE
		    fi
		fi;;
	    "ELIF")
		# Check if THEN is available
		if [[ "${1}" != +(* THEN*) ]]
		then
		    echo -e "\nSyntax error: missing THEN in ELIF statement at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
                    POS=$(Lexer " THEN" "${ARGS}")
                    THEN=$(Trim "${ARGS:$((${POS}+5))}")
                    SYM=$(Trim "${ARGS:0:${POS}}")
                    EXP=$(Trim "${SYM#*ELIF }")
		    # Translate function to C function
                    Parse_Equation "${EXP}"
		    if [[ -n ${THEN} ]]
		    then
                        if [[ $g_TRACE -eq 1 ]]
                        then
                            g_TRACE_PREFIX="RUNTIMEDEBUG($g_CURFILE, $g_COUNTER, \"$(echo ${1} | tr '\042\134' '\047\057')\")"
                            echo "else if(!(${g_TRACE_PREFIX})){ ; }" >> $g_CFILE
                        fi
		        echo "else if(${g_EQUATION}){" >> $g_CFILE
			Tokenize "${THEN}"
                        echo "}" >> $g_CFILE
                    else
                        if [[ $g_TRACE -eq 1 ]]
                        then
                            g_TRACE_PREFIX="RUNTIMEDEBUG($g_CURFILE, $g_COUNTER, \"ELIF $(echo ${EXP} | tr '\042\134' '\047\057')\")"
                            echo "} else if(!(${g_TRACE_PREFIX})){ ;" >> $g_CFILE
                        fi
                        echo "} else if(${g_EQUATION}){" >> $g_CFILE
                        g_TRACE_PREFIX=""
		    fi
		fi;;
	    "ELSE")
                EXP=$(Trim "${1##*ELSE}")
		if [[ -n ${EXP} ]]
		then
                    if [[ $g_TRACE -eq 1 ]]
                    then
                        g_TRACE_PREFIX="RUNTIMEDEBUG($g_CURFILE, $g_COUNTER, \"$(echo ${1} | tr '\042\134' '\047\057')\")"
                        echo "else if(!(${g_TRACE_PREFIX})){ ; }" >> $g_CFILE
                    fi
                    echo "else {" >> $g_CFILE
		    Tokenize "${EXP}"
                    echo "}" >> $g_CFILE
                else
                    if [[ $g_TRACE -eq 1 ]]
                    then
                        g_TRACE_PREFIX="RUNTIMEDEBUG($g_CURFILE, $g_COUNTER, \"ELSE\")"
                        echo "} else if(!(${g_TRACE_PREFIX})){ ;" >> $g_CFILE
                    fi
                    echo "} else {" >> $g_CFILE
                    g_TRACE_PREFIX=""
		fi;;
	    "FI")
		echo "}" >> $g_CFILE;;
	    "DOTIMES")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty DOTIMES at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    echo "long __do_times_${g_DOTIMES} = 0;" >> $g_HFILE
		    echo "for(__do_times_${g_DOTIMES} = 0; __do_times_${g_DOTIMES} < ${1#* }; __do_times_${g_DOTIMES}++) { _ = __do_times_${g_DOTIMES}+1;" >> $g_CFILE
		    ((g_DOTIMES+=1))
		fi;;
	    "DO")
		echo "{" >> $g_CFILE;;
	    "DONE")
		echo "}" >> $g_CFILE;;
	    "WHILE")
                ((g_LOOPCTR+=1))
		Handle_While "${1#* }";;
	    "WEND")
		echo "}" >> $g_CFILE
                if [[ $g_LOOPCTR -gt 0 ]]
                then
                    ((g_LOOPCTR-=1))
                    if [[ $g_LOOPCTR -gt 0 && $g_OPTION_BREAK = +(1*|TRUE*) ]]
                    then
                        echo "if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }" >> $g_CFILE
                    fi
                fi;;
	    "BREAK")
                # Check argument
                if [[ $g_OPTION_BREAK = +(1*|TRUE*) ]]
                then
		    if [[ "${1%% *}" != "${1#* }" && ${1#* } != "0" ]]
		    then
                        echo "__b2c__break_ctr = ${1#* }-1; __b2c__break_flag = 1;" >> $g_CFILE
                    fi
		    echo "break;" >> $g_CFILE
                else
		    echo -e "\nSyntax error: use of BREAK at line $g_COUNTER in file '$g_CURFILE' was disabled!"
		    exit 1
                fi;;
            "CONTINUE")
                # Check argument
		if [[ "${1%% *}" != "${1#* }" && ${1#* } != "0" ]]
		then
                    echo "__b2c__break_ctr = ${1#* }-1; __b2c__break_flag = 2;" >> $g_CFILE
                fi
                if [[ ${1#* } -gt 1 ]]
                then
		    echo "break;" >> $g_CFILE
                else
		    echo "continue;" >> $g_CFILE
                fi;;
	    "REPEAT")
                ((g_LOOPCTR+=1))
		echo "do{" >> $g_CFILE;;
	    "UNTIL")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty UNTIL at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    # Convert to legal C code
                    Parse_Equation "${1#* }"
		    echo "} while(!(${g_EQUATION}));" >> $g_CFILE
                    if [[ $g_LOOPCTR -gt 0 && $g_OPTION_BREAK = +(1*|TRUE*) ]]
                    then
                        ((g_LOOPCTR-=1))
                        if [[ $g_LOOPCTR -gt 0 ]]
                        then
                            echo "if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }" >> $g_CFILE
                        fi
                    fi
		fi;;
	    "LET")
		Handle_Let "${1#* }";;
	    +(\'*) )
                ;;
	    "SYSTEM")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty SYSTEM at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    echo "SYSTEM (${1#* });" >> $g_CFILE
		fi;;
	    "SLEEP")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty SLEEP at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    echo "usleep(${1#* }*1000);" >> $g_CFILE
		fi;;
	    "OPEN")
		Handle_Open "${1#* }";;
	    "CLOSE")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty CLOSE at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
                    EXP=$(echo ${1#*CLOSE })
		    if [[ "$EXP" = +(FILE *) ]]
		    then
                        EXP=${EXP#* }
                        while [[ -n ${EXP} ]]
                        do
                            TOKEN=$(Mini_Parser "${EXP}")
			    echo "fclose(${TOKEN});" >> $g_CFILE
                            EXP="${EXP:${#TOKEN}+1}"
			    TOKEN=$(echo ${TOKEN})
			    unset g_SEMANTIC_OPENCLOSE[${TOKEN}]
                        done
		    elif [[ "$EXP" = +(DIRECTORY *) ]]
		    then
                        EXP=${EXP#* }
                        while [[ -n ${EXP} ]]
                        do
                            TOKEN=$(Mini_Parser "${EXP}")
			    echo "closedir(${TOKEN});" >> $g_CFILE
                            EXP="${EXP:${#TOKEN}+1}"
			    TOKEN=$(echo ${TOKEN})
			    unset g_SEMANTIC_OPENCLOSE[${TOKEN}]
                        done
		    elif [[ "$EXP" = +(MEMORY *) ]]
		    then
                        EXP=${EXP#* }
                        while [[ -n ${EXP} ]]
                        do
                            TOKEN=$(Mini_Parser "${EXP}")
			    echo "${TOKEN} = NULL;" >> $g_CFILE
                            EXP="${EXP:${#TOKEN}+1}"
			    TOKEN=$(echo ${TOKEN})
			    unset g_SEMANTIC_OPENCLOSE[${TOKEN}]
                        done
		    elif [[ "$EXP" = +(LIBRARY *) ]]
		    then
                        EXP=${EXP#* }
                        while [[ -n ${EXP} ]]
                        do
                            TOKEN=$(Mini_Parser "${EXP}")
			    echo "if(__b2c__dlopen__pointer_${TOKEN//[[:punct:]]/} != NULL) {dlclose(__b2c__dlopen__pointer_${TOKEN//[[:punct:]]/}); __b2c__dlopen__pointer_${TOKEN//[[:punct:]]/} = NULL;}" >> $g_CFILE
                            EXP="${EXP:${#TOKEN}+1}"
			    TOKEN=$(echo ${TOKEN})
                        done
		    elif [[ "$EXP" = +(NETWORK *) || "$EXP" = +(SERVER *) || "$EXP" = +(UDP *) || "${EXP}" = +(DEVICE *) ]]
		    then
                        EXP=${EXP#* }
                        while [[ -n ${EXP} ]]
                        do
                            TOKEN=$(Mini_Parser "${EXP}")
                            # Close SSL socket if option was set
                            if [[ ${g_OPTION_TLS} = +(1*|TRUE*) ]]
                            then
                                if [[ ${g_LIB_TLS} != +(*gnutls*) ]]
                                then
                                    echo "SSL_CTX_free(SSL_get_SSL_CTX((SSL*)${TOKEN}));" >> $g_CFILE
                                else
                                    echo "SSL_CTX_free(((SSL*)${TOKEN})->ctx);" >> $g_CFILE
                                fi
                                echo "SSL_shutdown((SSL*)${TOKEN});" >> $g_CFILE
                                echo "SSL_free((SSL*)${TOKEN});" >> $g_CFILE
                                if [[ ${g_LIB_TLS} = +(*gnutls*) ]]
                                then
				    echo "gnutls_global_deinit();" >> $g_CFILE
                                fi
                            else
                                echo "shutdown((uintptr_t)${TOKEN}, SHUT_RDWR);" >> $g_CFILE
                                echo "close((uintptr_t)${TOKEN});" >> $g_CFILE
                            fi
                            EXP="${EXP:${#TOKEN}+1}"
			    TOKEN=$(echo ${TOKEN})
			    unset g_SEMANTIC_OPENCLOSE[${TOKEN}]
                        done
		    else
			echo -e "\nSyntax error: erronuous CLOSE argument at line $g_COUNTER in file '$g_CURFILE'!"
			exit 1
		    fi
		fi;;
	    "REWIND")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty REWIND at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    echo "rewind(${1#* });" >> $g_CFILE
		fi;;
	    "MEMREWIND")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty MEMREWIND at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    echo "${1#* } = (char*)__b2c_mem_${1#* };" >> $g_CFILE
		fi;;
	    "SEEK")
		Handle_Seek "${1#* }";;
	    "READLN")
		Handle_Readln "${1#* }";;
	    "WRITELN")
		Handle_Writeln "${1#* }";;
	    "GETBYTE")
		Handle_Getbyte "${1#* }";;
	    "PUTBYTE")
		Handle_Putbyte "${1#* }";;
	    "GETFILE")
		Handle_Getfile "${1#* }";;
	    "GETLINE")
		Handle_Getline "${1#* }";;
	    "PUTLINE")
		Handle_Putline "${1#* }";;
	    "END"|"ENDIF"|"ENDSUB"|"ENDWITH"|"ENDFORK"|"ENDRECORD"|"ENDSELECT"|"ENDFUNCTION"|"ENDFUNC")
		EXP=${1#*END }
		if [[ "${EXP}" = +(*IF*) ]]
		then
		    echo "}" >> $g_CFILE
		elif [[ "${EXP}" = +(*RECORD*) ]]
		then
		    if [[ -n $g_FUNCNAME ]]
		    then
			echo "} $g_RECORDNAME;" >> $g_CFILE
			echo "typedef $g_RECORDNAME ${g_RECORDNAME%_*}_type;" >> $g_CFILE
			if [[ -n $g_RECORDARRAY ]]
			then
			    echo "$g_RECORDNAME *${g_RECORDVAR%%\[*} = ($g_RECORDNAME*)calloc(${g_RECORDARRAY}+${g_OPTION_BASE}, sizeof($g_RECORDNAME));" >> $g_CFILE
			    g_LOCALSTRINGS="$g_LOCALSTRINGS ${g_RECORDVAR%%\[*}"
			    g_RECORDEND_BODY="long __b2c_record_${g_RECORDNAME%_*} = ${g_RECORDARRAY}+${g_OPTION_BASE}; ${g_RECORDEND_BODY}"
			else
			    echo "$g_RECORDNAME ${g_RECORDVAR//]/+${g_OPTION_BASE}]} = { 0 } ;" >> $g_CFILE
			fi
		    else
			echo "} $g_RECORDNAME;" >> $g_HFILE
			echo "typedef $g_RECORDNAME ${g_RECORDNAME%_*}_type;" >> $g_HFILE
			if [[ -n $g_RECORDARRAY ]]
			then
			    echo "$g_RECORDNAME *${g_RECORDVAR%%\[*};" >> $g_HFILE
			    echo "${g_RECORDVAR%%\[*} = ($g_RECORDNAME*)calloc(${g_RECORDARRAY}+${g_OPTION_BASE}, sizeof($g_RECORDNAME));" >> $g_CFILE
                            g_GLOBALARRAYS="$g_GLOBALARRAYS free(${g_RECORDVAR%%\[*});"
			    echo "long __b2c_record_${g_RECORDNAME%_*};" >> $g_HFILE
			    g_RECORDEND_BODY="${g_RECORDEND_BODY} __b2c_record_${g_RECORDNAME%_*} = ${g_RECORDARRAY}+${g_OPTION_BASE};"
			else
			    echo "$g_RECORDNAME ${g_RECORDVAR//]/+${g_OPTION_BASE}]} = { 0 } ;" >> $g_HFILE
			fi
                        echo $g_RECORDEND_HEADER >> $g_HFILE
		    fi
		    echo $g_RECORDEND_BODY >> $g_CFILE
		    g_RECORDNAME=
		    g_RECORDVAR=
		    g_RECORDEND_BODY=
                    g_RECORDEND_HEADER=
		    g_RECORDARRAY=
		    # Restore function name if GLOBAL was used
		    if [[ -n $g_RECORDCACHE ]]
		    then
			g_FUNCNAME=$g_RECORDCACHE
			g_RECORDCACHE=
		    fi
		elif [[ "${EXP}" = +(*FUNC*) || "${EXP}" = +(*FUNCTION*) ]]
		then
		    Handle_Endfunction
		elif [[ "${EXP}" = +(*SUB*) ]]
		then
		    Handle_Endsub
		elif [[ "${EXP}" = +(*WITH*) ]]
		then
		    g_WITHVAR=
		elif [[ "${EXP}" = +(*SELECT*) ]]
		then
		    if [[ $g_SELECTVAR_CTR -eq 0 ]]
		    then
			echo -e "\nSyntax error: invalid END SELECT at line $g_COUNTER in file '$g_CURFILE'!"
			exit 1
		    else
			echo "}" >> $g_CFILE
			g_SELECTVAR[$g_SELECTVAR_CTR]=
			g_IN_CASE[$g_SELECTVAR_CTR]=
			g_CASE_FALL=
			g_CASE_CONT=
			((g_SELECTVAR_CTR-=1))
		    fi
		elif [[ "${EXP}" = +(*FORK*) ]]
		then
                    if [[ $g_DEBUG -eq 1 ]]
                    then
                        echo "__b2c_str_realloc_debug_string();" >> $g_CFILE
                        echo "__b2c_mempool_realloc_debug();" >> $g_CFILE
                    fi
		    echo "__b2c_str_free();" >> $g_CFILE
                    if [[ -n ${1##*FORK} ]]
		    then
			echo "_exit(${1##*FORK});" >> $g_CFILE
		    else
			echo "_exit(EXIT_SUCCESS);" >> $g_CFILE
		    fi
		elif [[ "${EXP}" != "END" ]]
		then
                    if [[ $g_DEBUG -eq 1 ]]
                    then
                        echo "__b2c_str_realloc_debug_string();" >> $g_CFILE
                        echo "__b2c_mempool_realloc_debug();" >> $g_CFILE
                    fi
		    echo "exit(${1#* });" >> $g_CFILE
		else
                    if [[ $g_DEBUG -eq 1 ]]
                    then
                        echo "__b2c_str_realloc_debug_string();" >> $g_CFILE
                        echo "__b2c_mempool_realloc_debug();" >> $g_CFILE
                    fi
		    echo "exit(EXIT_SUCCESS);" >> $g_CFILE
		fi;;
	    "SUB")
		Handle_SubFunc "${1#* }";;
	    "CALL")
		Handle_Call "${1#* }";;
	    "FUNCTION"|"FUNC")
		Handle_SubFunc "${1#* }";;
	    "RETURN")
		Handle_Return "${1#* }";;
	    "IMPORT")
		Handle_Import "${1#* }";;
	    "DECLARE")
		Handle_Declare "${1#* }";;
	    "GLOBAL")
		Handle_Declare "${1#* }";;
	    "LOCAL")
		Handle_Local "${1#* }";;
	    "DATA")
		Handle_Data "${1#* }";;
	    "RESTORE")
                if [[ "${1%% *}" = "${1#* }" ]]
                then
		    echo "__b2c__floatarray_ptr = 0;" >> $g_CFILE
		    echo "__b2c__stringarray_ptr = 0;" >> $g_CFILE
                else
		    echo "__b2c__floatarray_ptr = __b2c__label_floatarray_${1#* };" >> $g_CFILE
		    echo "__b2c__stringarray_ptr = __b2c__label_stringarray_${1#* };" >> $g_CFILE
                fi;;
	    "READ")
		Handle_Read "${1#* }";;
	    "PUSH")
		Handle_Push "${1#* }";;
	    "PULL")
		Handle_Pull "${1#* }";;
	    "SEED")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty SEED at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    echo "srandom((unsigned int)${1#* });" >> $g_CFILE
		fi;;
	    "DEF")
		Handle_Deffn "${1#* }";;
	    "CONST")
		Handle_Const "${1#* }";;
	    "INCLUDE")
		# Get rid of doublequotes if they are there
		INC=`echo ${1#* } | tr -d "\042"`
		# See if there are arguments - equation adapted for KSH93
		if [[ ${INC//,/} != ${INC} ]]
		then
                    EXP=$(echo ${INC#*,} | tr "," " " | tr -d "${g_STRINGSIGN}")
		    INC=${INC%%,*}
		    TO_PARSE=0
		else
		    TO_PARSE=2
		fi
                # Check file extension
                if [[ ${INC} != +(*.bac) ]]
                then
                    INC="${INC}.bac"
                fi
		# Check argument
		if [[ ! -f ${INC%%,*} || "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSystem error: missing file '${INC%%,*}' for INCLUDE at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    # Clear current terminal line
		    echo -e -n "\r\033[2K"
		    # Check if the C Preprocessor needs to run
		    if [[ $g_CPP -eq 1 ]]
		    then
			if [[ -n `command -v cpp 2>/dev/null` ]]
			then
                            echo -n "Preprocessing '${INC}'... "
                            # Change next line marker to overcome C preprocessor interpretation
                            while read -r LINE; do if [[ ${LINE} = +(\#*) ]]; then echo "${LINE}"; else echo "@${LINE}@"; fi; done < $INC > $INC.tmp
                            cpp -w -P $INC.tmp $INC.cpp
                            # Restore the next line marker
                            while read -r LINE; do LINE="${LINE:1}"; echo "${LINE%@*}"; done < $INC.cpp > $INC.bac2
			    g_TMP_FILES="$g_TMP_FILES ${INC}.cpp ${INC}.tmp $INC.bac2"
			    NEWFEED="${INC}.bac2"
                            echo "done."
			else
			    echo "System error: the C Preprocessor 'cpp' not found on this system! Exiting..."
			    exit 1
			fi
		    else
			NEWFEED=${INC}
		    fi
	            g_TMP_FILES="$g_TMP_FILES ${INC}"
		    # Start walking through program
		    COPY_COUNTER=$g_COUNTER
		    g_COUNTER=1
		    # Assign new file
		    COPY_CURFILE=$g_CURFILE
		    # Set current filename
		    g_CURFILE=${NEWFEED}
                    # Detect if this is a Windows file
                    if [[ `head -1 ${NEWFEED}` = +(*${g_CRLF}) ]]
                    then
                        echo "System error: Windows file detected! Remove non-Unix CR line separators first. Exiting..."
                        exit 1
                    fi
		    while read -r LINE || [[ -n $LINE ]]
		    do
			# See if we need to enable flag
			for SYM in ${EXP}
			do
			    if [[ $TO_PARSE -eq 0 && "${LINE#* }" = +(${SYM%${g_STRINGSIGN}*}*) && "${LINE}" = +(*SUB*|*FUNCTION*) || "${LINE}" = +(*INCLUDE) ]]
			    then
				TO_PARSE=1
				break
			    fi
			done
			# Line is not empty?
			if [[ -n "$LINE" && $TO_PARSE -gt 0 ]]
			then
			    if [[ $g_QUIET -eq 0 ]]
			    then
				echo -e -n "\rConverting '${INC}'... ${g_COUNTER}\033[0K"
			    fi
			    if [[ "$LINE" = +(* \\) && "$LINE" != +(${g_SQUOTESIGN}*) ]]
			    then
				let LEN="${#LINE}"-2
				SEQ="${LINE:0:$LEN}"
				TOTAL=$TOTAL$SEQ
                            else
				TOTAL="${TOTAL}${LINE}"
				if [[ "${TOTAL}" != +(${g_SQUOTESIGN}*) ]]
				then
                                    if [[ ${g_DEBUG} -eq 1 ]]
                                    then
                                        echo "/* line $g_COUNTER \"${NEWFEED}\" */" >> $g_CFILE
                                        echo "/* line $g_COUNTER \"${NEWFEED}\" */" >> $g_HFILE
                                    else
                                        echo "#line $g_COUNTER \"${NEWFEED}\"" >> $g_CFILE
                                        echo "#line $g_COUNTER \"${NEWFEED}\"" >> $g_HFILE
                                    fi
				    Tokenize "${TOTAL}"
				fi
				TOTAL=
			    fi
			fi
			# See if we need to stop parsing
			if [[ $TO_PARSE -eq 1 && "${LINE}" = +(*END*) && "${LINE}" = +(*SUB*|*FUNCTION*) ]]
			then
			    TO_PARSE=0
			fi
			# Increase line number
			((g_COUNTER+=1))
		    done < $NEWFEED
                    # Save total amount of lines
                    ((g_TOTAL_LINES+=$g_COUNTER-1))
		    # Restore original counter
		    g_COUNTER=$COPY_COUNTER
		    # Restore original file
		    g_CURFILE=$COPY_CURFILE
                    # Set DATA array indexes correctly
                    echo "__b2c__stringarray_ptr = ${g_CCTR};" >> $g_CFILE
                    echo "__b2c__floatarray_ptr = ${g_FCTR};" >> $g_CFILE
		fi;;
	    "POKE")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty POKE at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
                    EXP=${1#* }
                    if [[ ${EXP} = +(* SIZE *) ]]
                    then
		        SYM=${EXP##* SIZE }
                        EXP=${EXP% SIZE *}
                        TOKEN=$(Mini_Parser "${EXP}")
                        EXP="${EXP:${#TOKEN}+1}"
		        echo "if (__b2c__trap){if(!__b2c__memory__check((char*)${TOKEN}, (${SYM})*sizeof(__b2c__MEMTYPE))) {ERROR=1; if(!__b2c__catch_set) RUNTIMEERROR(\"POKE\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
		        echo "memset((void*)(__b2c__MEMTYPE*)(${TOKEN}), ${EXP}, (${SYM})*sizeof(__b2c__MEMTYPE));" >> $g_CFILE
                    else
                        TOKEN=$(Mini_Parser "${EXP}")
                        EXP="${EXP:${#TOKEN}+1}"
		        echo "if (__b2c__trap){if(!__b2c__memory__check((char*)${TOKEN}, sizeof(__b2c__MEMTYPE))) {ERROR=1; if(!__b2c__catch_set) RUNTIMEERROR(\"POKE\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
		        echo "*(__b2c__MEMTYPE*)(${TOKEN}) = (__b2c__MEMTYPE)(${EXP});" >> $g_CFILE
                    fi
                    if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
                    then
                        g_CATCH_USED=1
                    fi
		fi;;
	    "RESIZE")
	    	# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty RESIZE at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    SYM=${1#* }
		    EXP=${SYM%% TO *}
                    CHECK=$(Get_Var ${EXP//./} ${g_FUNCNAME})
                    echo "if(__b2c__trap) {if(!__b2c__memory__check((char*)${EXP}, sizeof(__b2c__MEMTYPE))) {ERROR=1; if(!__b2c__catch_set) RUNTIMEERROR(\"RESIZE\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
                    echo "${EXP} = (${CHECK})realloc((void*)${EXP}, sizeof(__b2c__MEMTYPE)*(${SYM##* TO }+1));" >> $g_CFILE
                    echo "if(__b2c__trap) {if((void*)${EXP} == NULL) {ERROR=6; if(!__b2c__catch_set) RUNTIMEERROR(\"RESIZE\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
                    if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
                    then
                        g_CATCH_USED=1
                    fi
		fi;;
	    "COPY")
		Handle_Copy "${1#* }";;
	    "DELETE")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty DELETE at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    # Translate to C function
		    if [[ "${1#* }" = +(*FILE*) ]]
		    then
			echo "if (unlink(${1#*FILE })==-1){if(__b2c__trap){ERROR = 7;if(!__b2c__catch_set) RUNTIMEERROR(\"DELETE\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
                        if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
                        then
                            g_CATCH_USED=1
                        fi
		    elif [[ "${1#* }" = +(*DIRECTORY*) ]]
		    then
		        echo "if (rmdir(${1#*DIRECTORY }) == -1){if(__b2c__trap){ERROR = 20;if(!__b2c__catch_set) RUNTIMEERROR(\"DELETE\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
                        if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
                        then
                            g_CATCH_USED=1
                        fi
		    elif [[ "${1#* }" = +(*RECURSIVE*) ]]
		    then
			echo "__b2c__rmrecursive(__LINE__, __FILE__, ${1#*RECURSIVE });" >> $g_CFILE
		    elif [[ "${1#* }" = +(*FROM*) ]]
		    then
                        POS=$(Lexer " FROM " "${ARGS}")
                        SYM=$(Trim "${ARGS:$((${POS}+6))}")
                        ARGS=$(Trim "${ARGS:0:${POS}}")
                        EXP=$(Trim "${ARGS##*DELETE }")
                        CHECK=$(Get_Var __b2c__tree_"${SYM}" ${g_FUNCNAME})
                        UNIQ="__b2c__${SYM}_${g_COUNTER}_${RANDOM}"
                        if [[ ${CHECK#:*} = +(*char\**) ]]
                        then
                            echo "char *${UNIQ} = ${EXP}; __b2c__assign2 = tfind((void*)${UNIQ}, &${SYM}, ${CHECK%:*}); if(__b2c__assign2) { __b2c__assign = *__b2c__assign2; tdelete((void*)${UNIQ}, &${SYM}, ${CHECK%:*}); __b2c__STRFREE(__b2c__assign); }" >> $g_CFILE
                        else
                            echo "${CHECK#*:} *${UNIQ} = (${CHECK#*:}*)malloc(sizeof(${CHECK#*:})); *${UNIQ} = (${CHECK#*:})${EXP}; __b2c__assign2 = tfind((void*)${UNIQ}, &${SYM}, ${CHECK%:*}); if(__b2c__assign2) { __b2c__assign = *__b2c__assign2; tdelete((void*)${UNIQ}, &${SYM}, ${CHECK%:*}); free(__b2c__assign); } free(${UNIQ});" >> $g_CFILE
                        fi
		    else
			echo "\nERROR: erronuous argument for DELETE at line $g_COUNTER in file '$g_CURFILE'!"
			exit 1
		    fi
		fi;;
	    "RENAME")
		Handle_Rename "${1#* }";;
	    "MAKEDIR")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty MAKEDIR at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    # Translate to C function
                    echo "ERROR = __b2c__makedir(${1#* }); if(ERROR && __b2c__trap) { if(!__b2c__catch_set) RUNTIMEERROR(\"MAKEDIR\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO; }" >> $g_CFILE
                    if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
                    then
                        g_CATCH_USED=1
                    fi
		fi;;
	    "CHANGEDIR")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty CHANGEDIR at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    # Translate to C function
		    echo "if (${1#* } == NULL || chdir(${1#* }) == -1){if(__b2c__trap) {ERROR = 22;if(!__b2c__catch_set) RUNTIMEERROR(\"CHANGEDIR\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
                    if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
                    then
                        g_CATCH_USED=1
                    fi
		fi;;
	    "FREE")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty FREE at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    # Associative record member
		    if [[ "${1}" = +(*[a-zA-Z]\(*\)) ]]
		    then
                        EXP=`echo ${1#* }`
                        # Start miniparser
                        while [[ -n ${EXP} ]]
                        do
                            TOKEN=`echo $(Mini_Parser "${EXP}")`
                            TXT=${TOKEN%?}
                            echo "__b2c__hash_del(__b2c__assoc_${TOKEN%%\(*}, ${TXT#*\(});" >> $g_CFILE
                            EXP="${EXP:${#TOKEN}+1}"
                        done
		    else
                        EXP=$(echo ${1#* })
                        IFS=","
	                for i in ${EXP// /}
                        do
                            if [[ -n $(Get_Var __b2c__assoc_${i})$(Get_Var __b2c__assoc_${i} ${g_FUNCNAME}) ]]
			    then
                                echo "__b2c__hash_clear(__b2c__assoc_${i});" >> $g_CFILE
			    else
				EXP=${i// /}
				echo "if(__b2c__trap){if(!__b2c__memory__check((char *)${EXP}, sizeof(__b2c__MEMTYPE)))" >> $g_CFILE
				echo "{ERROR=1; if(!__b2c__catch_set) RUNTIMEERROR(\"FREE\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} } free((void*)${EXP});" >> $g_CFILE
				unset g_SEMANTIC_MEMFREE[${EXP}]
			    fi
                        done
                        IFS="${g_ORGIFS}"
                        if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
                        then
                            g_CATCH_USED=1
                        fi
		    fi
		fi;;
	    "ON")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty ON at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		elif [[ "${1}" != +(* GOTO *) && "${1}" != +(* CALL *) ]]
		then
		    echo -e "\nSyntax error: ON without CALL/GOTO at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    SYM=${1#* }
		    if [[ "${1}" = +(* GOTO *) ]]
                    then
                        EXP=${1##* GOTO }
		        echo "switch(${SYM%GOTO *}){" >> $g_CFILE
                    else
                        EXP=${1##* CALL }
		        echo "switch(${SYM%CALL *}){" >> $g_CFILE
                    fi
		    # Convert to C 'switch' statement
		    let SEQ=1
                    while [[ -n ${EXP} ]]
                    do
                        TOKEN=$(Mini_Parser "${EXP}")
		        if [[ "${1}" = +(* GOTO *) ]]
                        then
			    echo "case ${SEQ}: goto ${TOKEN}; break;" >> $g_CFILE
                        else
                            if [[ ${TOKEN} != +(*\(*\)) ]]
                            then
                                echo "case ${SEQ}: ${TOKEN}(); break;" >> $g_CFILE
                            else
			        echo "case ${SEQ}: ${TOKEN}; break;" >> $g_CFILE
                            fi
                        fi
                        EXP="${EXP:${#TOKEN}+1}"
			((SEQ+=1))
                    done
		    echo "}" >> $g_CFILE
		fi;;
	    "GOTO")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty GOTO at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    # Translate to C label
		    echo "goto ${1#* };" >> $g_CFILE
		fi;;
	    "GOSUB")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty GOSUB at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    # Translate to C label
		    echo "__b2c__gosub_buffer_ptr++; if (__b2c__gosub_buffer_ptr >= $g_MAX_RBUFFERS) {ERROR=31; if(!__b2c__catch_set) RUNTIMEERROR(\"GOSUB\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;}" >> $g_CFILE
		    echo "if(!setjmp(__b2c__gosub_buffer[__b2c__gosub_buffer_ptr])) goto ${1#* };" >> $g_CFILE
		    echo "__b2c__gosub_buffer_ptr--; if(__b2c__gosub_buffer_ptr < -1) __b2c__gosub_buffer_ptr = -1;" >> $g_CFILE
                    if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
                    then
                        g_CATCH_USED=1
                    fi
		fi;;
	    "LABEL")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty LABEL at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    # Translate to C label
		    echo "${1#* }:" >> $g_CFILE
		    echo ";" >> $g_CFILE
                    # Needed for RESTORE
                    echo "#undef __b2c__label_floatarray_${1#* }" >> $g_HFILE
                    echo "#define __b2c__label_floatarray_${1#* } $g_FCTR" >> $g_HFILE
                    echo "#undef __b2c__label_stringarray_${1#* }" >> $g_HFILE
                    echo "#define __b2c__label_stringarray_${1#* } $g_CCTR" >> $g_HFILE
		fi;;
	    "TRAP")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty TRAP at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    if [[ "${1#* }" = "LOCAL" ]]
		    then
			echo "/* Error catching is enabled */" >> $g_CFILE
			echo "__b2c__trap = 1;" >> $g_CFILE
			echo "signal(SIGILL, __b2c__catch_signal);" >> $g_CFILE
			echo "signal(SIGABRT, __b2c__catch_signal);" >> $g_CFILE
			echo "signal(SIGFPE, __b2c__catch_signal);" >> $g_CFILE
			echo "signal(SIGSEGV, __b2c__catch_signal);" >> $g_CFILE
		    elif [[ "${1#* }" = "SYSTEM" ]]
		    then
			echo "/* Error catching is disabled */" >> $g_CFILE
			echo "__b2c__trap = 0;" >> $g_CFILE
			echo "signal(SIGILL, SIG_DFL);" >> $g_CFILE
			echo "signal(SIGABRT, SIG_DFL);" >> $g_CFILE
			echo "signal(SIGFPE, SIG_DFL);" >> $g_CFILE
			echo "signal(SIGSEGV, SIG_DFL);" >> $g_CFILE
		    else
			echo -e "\nSyntax error: invalid argument for TRAP at line $g_COUNTER in file '$g_CURFILE'!"
			exit 1
		    fi
		fi;;
	    "CATCH")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty CATCH at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		elif [[ "${1#* }" = +(*GOTO*) ]]
		then
		    echo "__b2c__catch_set = 1;" >> $g_CFILE
		    g_CATCHGOTO="${1##* GOTO }"
		elif [[ "${1#* }" = +(*ERROR*) ]]
		then
		    echo "__b2c__error_callback = &${1##* ERROR };" >> $g_CFILE
		elif [[ "${1#* }" = +(*RESET*) ]]
		then
		    echo "__b2c__catch_set = 0;" >> $g_CFILE
		    g_CATCHGOTO="__B2C__PROGRAM__EXIT"
		else
		    echo -e "\nSyntax error: CATCH without GOTO or RESET at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		fi;;
	    "RESUME")
		echo "longjmp(__b2c__jump, 1);" >> $g_CFILE;;
	    "CLEAR")
		echo "fprintf(stdout,\"\033[2J\"); fprintf(stdout,\"\033[0;0f\"); fflush(stdout);" >> $g_CFILE;;
	    "COLOR")
		Handle_Color "${1#* }";;
	    "TYPE")
		Handle_Type "${1#* }";;
	    "SCREEN")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty SCREEN at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    if [[ "${1#* }" = "SAVE" ]]
		    then
		        echo "fprintf(stdout,\"\033[?47h\"); fflush(stdout);" >> $g_CFILE
                    elif [[ "${1#* }" = "RESTORE" ]]
                    then
		        echo "fprintf(stdout,\"\033[?47l\"); fflush(stdout);" >> $g_CFILE
		    else
			echo -e "\nSyntax error: invalid argument for SCREEN at line $g_COUNTER in file '$g_CURFILE'!"
			exit 1
		    fi
                fi;;
	    "GOTOXY")
		Handle_Gotoxy "${1#* }";;
	    "RECEIVE")
		Handle_Receive "${1#* }";;
	    "SEND")
		Handle_Send "${1#* }";;
	    "RECORD")
	    	# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty RECORD at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		elif [[ -n $g_RECORDNAME ]]
		then
		    echo -e "\nSyntax error: cannot define a record within a record!"
		    exit 1
		else
		    # Determine name
		    g_RECORDVAR=${1#* }
		    if [[ $g_RECORDVAR = +(* ARRAY *) ]]
		    then
			g_RECORDARRAY=${g_RECORDVAR#* ARRAY }
			g_RECORDVAR="${g_RECORDVAR%% ARRAY *}[$g_RECORDARRAY]"
		    fi
		    # Translate to C typedef struct
		    if [[ -n $g_FUNCNAME ]]
		    then
			g_RECORDNAME="${g_RECORDVAR%%\[*}_TYPE"
			echo "typedef struct {" >> $g_CFILE
                        Save_Func_Var "" "${g_FUNCNAME}" "$g_RECORDNAME"
		    else
			g_RECORDNAME="${g_RECORDVAR%%\[*}_TYPE"
			echo "typedef struct {" >> $g_HFILE
			Save_Main_Var "" "$g_RECORDNAME"
		    fi
		fi;;
	    "WITH")
	    	# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty WITH at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		elif [[ -n $g_RECORDNAME ]]
		then
		    echo -e "\nSyntax error: cannot define a WITH within a WITH!"
		    exit 1
		else
		    g_WITHVAR=${1#* }
		fi;;
	    "SPLIT")
		Handle_Split "${1#* }";;
	    "JOIN")
		Handle_Join "${1#* }";;
	    "SELECT")
	    	# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty SELECT at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    ((g_SELECTVAR_CTR+=1))
		    if [[ $(Check_String_Type "${1#* }") -eq 1 ]]
		    then
                        g_SELECTVAR[$g_SELECTVAR_CTR]="__b2c__select_${g_COUNTER}${g_STRINGSIGN}"
		        if [[ -n $g_FUNCNAME ]]
                        then
                            g_STRINGARGS="${g_STRINGARGS} char *${g_SELECTVAR[$g_SELECTVAR_CTR]} = NULL;"
		            g_LOCALSTRINGS="$g_LOCALSTRINGS ${g_SELECTVAR[$g_SELECTVAR_CTR]}"
                        else
                            echo "char *${g_SELECTVAR[$g_SELECTVAR_CTR]} = NULL;" >> $g_HFILE
                        fi
                        echo "${g_SELECTVAR[$g_SELECTVAR_CTR]} = __b2c_Copy_String(${g_SELECTVAR[$g_SELECTVAR_CTR]}, ${1#* });" >> $g_CFILE
                    else
                        g_SELECTVAR[$g_SELECTVAR_CTR]="__b2c__select_${g_COUNTER}"
                        echo "double ${g_SELECTVAR[$g_SELECTVAR_CTR]} = 0;" >> $g_HFILE
                        echo "${g_SELECTVAR[$g_SELECTVAR_CTR]} = (double)${1#* };" >> $g_CFILE
                    fi
		    g_IN_CASE[$g_SELECTVAR_CTR]=
		    g_CASE_FALL=
		    g_CASE_CONT=
		fi;;
	    "CASE")
	    	# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo "\nSyntax error: empty CASE at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
                    # In processing of next CASE statements
		    if [[ ${g_IN_CASE[$g_SELECTVAR_CTR]} -eq 1 ]]
		    then
                        g_CASE_CONT="} else "
                    fi
                    # Create IF
		    if [[ $(Check_String_Type ${g_SELECTVAR[$g_SELECTVAR_CTR]}) -eq 1 ]]
		    then
			# Get expression without ;
			if [[ -z ${1##*;} ]]
			then
			    let LEN="${#1}"-1; EXP="${1:0:$LEN}"
			    g_CASE_FALL="${g_CASE_FALL} !__b2c__strcmp(${g_SELECTVAR[$g_SELECTVAR_CTR]}, ${EXP#* }) ||"
			else
                            EXP=${1#* }
	                    # Start miniparser
                            while [[ -n ${EXP} ]]
                            do
                                SYM=$(Mini_Parser "${EXP}")
		                g_CASE_FALL="${g_CASE_FALL} !__b2c__strcmp(${g_SELECTVAR[$g_SELECTVAR_CTR]}, ${SYM})"
                                EXP="${EXP:${#SYM}+1}"
                                if [[ -n ${EXP} ]]
                                then
                                    g_CASE_FALL="${g_CASE_FALL} ||"
                                fi
                            done
			    echo "${g_CASE_CONT} if (${g_CASE_FALL}){" >> $g_CFILE
			    g_IN_CASE[$g_SELECTVAR_CTR]=1
			    g_CASE_FALL=
			fi
		    else
			# Get expression without ;
			if [[ -z ${1##*;} ]]
			then
			    let LEN="${#1}"-1; EXP="${1:0:$LEN}"
                            g_CASE_FALL="${g_CASE_FALL} (${g_SELECTVAR[$g_SELECTVAR_CTR]}) == (${EXP#* }) ||"
			else
                            EXP=${1#* }
	                    # Start miniparser
                            while [[ -n ${EXP} ]]
                            do
                                SYM=$(Mini_Parser "${EXP}")
                                g_CASE_FALL="${g_CASE_FALL} (${g_SELECTVAR[$g_SELECTVAR_CTR]}) == (${SYM})"
                                EXP="${EXP:${#SYM}+1}"
                                if [[ -n ${EXP} ]]
                                then
                                    g_CASE_FALL="${g_CASE_FALL} ||"
                                fi
                            done
			    echo "${g_CASE_CONT} if (${g_CASE_FALL}){" >> $g_CFILE
			    g_IN_CASE[$g_SELECTVAR_CTR]=1
			    g_CASE_FALL=
			fi
		    fi
		fi;;
	    "DEFAULT")
		if [[ -n ${g_IN_CASE[$g_SELECTVAR_CTR]} ]]
		then
		    echo "} else {" >> $g_CFILE
		else
		    echo -e "\nSyntax error: cannot use DEFAULT without previous CASE at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		fi
		g_IN_CASE[$g_SELECTVAR_CTR]=
		g_CASE_FALL=;;
	    "SETENVIRON")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty SETENVIRON at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    # Resolve this with C macro
		    echo "SETENVIRON(${1#* });" >> $g_CFILE
		fi;;
	    "SORT")
		Handle_Sort "${1#* }";;
	    "STOP")
		# Check argument
		if [[ $(echo ${1%% *}) = $(echo ${1}) ]]
		then
		    echo "kill(getpid(), SIGSTOP);" >> $g_CFILE
                else
                    EXP=$(echo ${1#* } | tr -d "\042")
		    echo "kill(getpid(), ${EXP});" >> $g_CFILE
                fi
		;;
	    "TRACE")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty TRACE at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    if [[ "${1#* }" = +(*MONITOR*) ]]
                    then
			g_TRACE=1
	                echo "fprintf(stderr, \"File '${g_CURFILE}' line %d: TRACE ON - press <SPACE> to execute the program step by step, <ESC> to exit.\n\", $g_COUNTER);" >> $g_CFILE
                        g_MONITOR=
                        for SYM in `echo "${1#*MONITOR }" | tr -d '\054'`
                        do
			    if [[ $(Check_String_Type ${SYM}) -eq 1 ]]
			    then
                                EXP=${SYM//$g_STRINGSIGN/\$}
                                g_MONITOR="${g_MONITOR} && (${SYM} == NULL ? fprintf(stderr, \"MONITOR: ${EXP} = NULL\n\") : fprintf(stderr, \"${EXP} = %s\n\", ${SYM}) )"
                            else
                                EXP=${SYM//$g_FLOATSIGN/\#}
                                EXP=${EXP//$g_LONGSIGN/\%}
	                        g_MONITOR="${g_MONITOR} && fprintf(stderr, \"MONITOR: ${EXP} = %s\n\", __b2c__str(${SYM}))"
                            fi
                        done
		    elif [[ "${1#* }" = +(*ON*) ]]
		    then
			g_TRACE=1
	                echo "fprintf(stderr, \"File '${g_CURFILE}' line %d: TRACE ON - press <SPACE> to execute the program step by step, <ESC> to exit.\n\", $g_COUNTER);" >> $g_CFILE
		    elif [[ "${1#* }" = +(*OFF*) ]]
		    then
                        g_MONITOR=
			g_TRACE=0
		    fi
		fi;;
	    "OPTION")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty OPTION at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    if [[ "${1#* }" = +(*BASE*) ]]
		    then
			if [[ "${1##*BASE }" = +([0123456789]*) ]]
			then
			    g_OPTION_BASE=$(echo ${1##*BASE })
			else
			    echo -e "\nSyntax error: invalid argument to OPTION BASE at line $g_COUNTER in file '$g_CURFILE'!"
			    exit 1
			fi
		    elif [[ "${1#* }" = +(*COMPARE*) ]]
		    then
			if [[ "${1##*COMPARE }" = +([01]*|TRUE*|FALSE*) ]]
			then
			    echo "__b2c__option_compare = $(echo ${1##*COMPARE });" >> $g_CFILE
                            echo "#undef __b2c__STRCMP" >> $g_CFILE
                            if [[ "${1##*COMPARE }" = +(1*|TRUE*) ]]
                            then
                                echo "#define __b2c__STRCMP __b2c__strcasecmp" >> $g_CFILE
                            else
                                echo "#define __b2c__STRCMP __b2c__strcmp" >> $g_CFILE
                            fi
			else
			    echo -e "\nSyntax error: invalid argument to OPTION COMPARE at line $g_COUNTER in file '$g_CURFILE'!"
			    exit 1
			fi
		    elif [[ "${1#* }" = +(*QUOTED*) ]]
		    then
			if [[ "${1##*QUOTED }" = +([01]*|TRUE*|FALSE*) ]]
			then
			    echo "__b2c__option_quoted = $(echo ${1##*QUOTED });" >> $g_CFILE
			else
			    echo -e "\nSyntax error: invalid argument to OPTION QUOTED at line $g_COUNTER in file '$g_CURFILE'!"
			    exit 1
			fi
		    elif [[ "${1#* }" = +(*UTF8*) ]]
		    then
			if [[ "${1##*UTF8 }" = +([01]*|TRUE*|FALSE*) ]]
			then
			    echo "__b2c__option_utf8 = $(echo ${1##*UTF8 });" >> $g_CFILE
			else
			    echo -e "\nSyntax error: invalid argument to OPTION UTF8 at line $g_COUNTER in file '$g_CURFILE'!"
			    exit 1
			fi
		    elif [[ "${1#* }" = +(*TLS*) ]]
		    then
			if [[ "${1##*TLS }" = +([01]*|TRUE*|FALSE*) ]]
			then
                            if [[ "${1##*TLS }" = +(1*|TRUE*) ]]
                            then
			        g_OPTION_TLS=1
	                        echo "__b2c__option_tls = 1;" >> $g_CFILE
                                g_INC_TLS="#include <openssl/ssl.h>\n#include <openssl/err.h>"
                                g_LIB_TLS=$(pkg-config --libs openssl)
                            else
			        g_OPTION_TLS=0
	                        echo "__b2c__option_tls = 0;" >> $g_CFILE
                            fi
			else
			    echo -e "\nSyntax error: invalid argument to OPTION TLS at line $g_COUNTER in file '$g_CURFILE'!"
			    exit 1
			fi
		    elif [[ "${1#* }" = +(*EVAL*) ]]
		    then
			if [[ "${1##*EVAL }" = +([01]*|TRUE*|FALSE*) ]]
			then
                            g_CCFLAGS="${g_CCFLAGS} $(pkg-config --cflags libmatheval)"
                            g_LDFLAGS="${g_LDFLAGS} $(pkg-config --libs libmatheval)"
			    g_OPTION_EVAL=1
			else
			    echo -e "\nSyntax error: invalid argument to OPTION EVAL at line $g_COUNTER in file '$g_CURFILE'!"
			    exit 1
			fi
                    elif [[ "${1#* }" = +(*PROPER*) ]]
		    then
			if [[ "${1##*PROPER }" = +([01]*|TRUE*|FALSE*) ]]
			then
			    echo "__b2c__option_proper = $(echo ${1##*PROPER });" >> $g_CFILE
			else
			    echo -e "\nSyntax error: invalid argument to OPTION PROPER at line $g_COUNTER in file '$g_CURFILE'!"
			    exit 1
			fi
		    elif [[ "${1#* }" = +(*ERROR*) ]]
		    then
			if [[ "${1##*ERROR }" = +([01]*|TRUE*|FALSE*) ]]
			then
			    echo "__b2c__option_error = $(echo ${1##*ERROR });" >> $g_CFILE
			else
			    echo -e "\nSyntax error: invalid argument to OPTION ERROR at line $g_COUNTER in file '$g_CURFILE'!"
			    exit 1
			fi
		    elif [[ "${1#* }" = +(*DELIM*) ]]
		    then
                        echo "__b2c__option_delim = $(echo ${1##*DELIM});" >> $g_CFILE
		    elif [[ "${1#* }" = +(*INPUT*) ]]
		    then
                        g_OPTION_INPUT=$(echo ${1##*INPUT})
		    elif [[ "${1#* }" = +(*DQ*) ]]
		    then
                        echo "__b2c__option_dq = $(echo ${1##*DQ})&255;" >> $g_CFILE
		    elif [[ "${1#* }" = +(*NO_C_ESC*) ]]
		    then
                        g_OPTION_DISABLE_C_ESCAPE=$(echo ${1##*NO_C_ESC})
                    elif [[ "${1#* }" = +(*ESC*) ]]
		    then
                        echo "__b2c__option_esc = $(echo ${1##*ESC})&255;" >> $g_CFILE
                    elif [[ "${1#* }" = +(*SOCKET*) ]]
		    then
			if [[ "${1##*SOCKET }" = +([0123456789]*) ]]
			then
			    g_OPTION_SOCKET=$(echo ${1##*SOCKET })
			else
			    echo -e "\nSyntax error: invalid argument to OPTION SOCKET at line $g_COUNTER in file '$g_CURFILE'!"
			    exit 1
			fi
		    elif [[ "${1#* }" = +(*BREAK*) ]]
		    then
			if [[ "${1##*BREAK }" = +([01]*|TRUE*|FALSE*) ]]
			then
			    g_OPTION_BREAK=$(echo ${1##*BREAK })
			else
			    echo -e "\nSyntax error: invalid argument to OPTION BREAK at line $g_COUNTER in file '$g_CURFILE'!"
			    exit 1
			fi
                    elif [[ "${1#* }" = +(*MEMSTREAM*) ]]
		    then
			if [[ "${1##*MEMSTREAM }" = +([01]*|TRUE*|FALSE*) ]]
			then
			    echo "__b2c__option_memstream = $(echo ${1##*MEMSTREAM });" >> $g_CFILE
			else
			    echo -e "\nSyntax error: invalid argument to OPTION MEMSTREAM at line $g_COUNTER in file '$g_CURFILE'!"
			    exit 1
			fi
                    elif [[ "${1#* }" = +(*MEMTYPE*) ]]
		    then
                        echo "#undef __b2c__MEMTYPE" >> $g_CFILE
                        echo "#define __b2c__MEMTYPE $(echo ${1##*MEMTYPE })" >> $g_CFILE
                    elif [[ "${1#* }" = +(*PRIORITY*) ]]
		    then
                        g_PRIORITY=$(echo ${1##*PRIORITY })
                    elif [[ "${1#* }" = +(*COLLAPSE*) ]]
		    then
			if [[ "${1##*COLLAPSE }" = +([01]*|TRUE*|FALSE*) ]]
			then
			    echo "__b2c__collapse = $(echo ${1##*COLLAPSE });" >> $g_CFILE
			else
			    echo -e "\nSyntax error: invalid argument to OPTION COLLAPSE at line $g_COUNTER in file '$g_CURFILE'!"
			    exit 1
			fi
                    elif [[ "${1#* }" = +(*DEVICE*) ]]
		    then
			echo "__b2c__option_open = ($(echo ${1##*DEVICE }));" >> $g_CFILE
                    elif [[ "${1#* }" = +(*STARTPOINT*) ]]
		    then
			if [[ "${1##*STARTPOINT }" = +([01]*|TRUE*|FALSE*) ]]
			then
			    echo "__b2c__option_startpoint = $(echo ${1##*STARTPOINT });" >> $g_CFILE
			else
			    echo -e "\nSyntax error: invalid argument to OPTION STARTPOINT at line $g_COUNTER in file '$g_CURFILE'!"
			    exit 1
			fi
                    elif [[ "${1#* }" = +(*INTERNATIONAL*) ]]
		    then
			if [[ "${1##*INTERNATIONAL }" = +(1*|TRUE*) ]]
			then
			    echo "#include <libintl.h>" >> $g_HFILE
                            echo "setlocale(LC_ALL, \"\");" >> $g_CFILE
			    echo "if(bindtextdomain(\"${g_SOURCEFILE%.*}\",\"/usr/share/locale\")==NULL){if(__b2c__trap){ERROR = 6;if(!__b2c__catch_set) RUNTIMEERROR(\"OPTION INTERNATIONAL\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
			    echo "if(textdomain(\"${g_SOURCEFILE%.*}\")==NULL){if(__b2c__trap){ERROR = 6; if(!__b2c__catch_set) RUNTIMEERROR(\"OPTION INTERNATIONAL\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
                            if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
                            then
                                g_CATCH_USED=1
                            fi
			else
			    echo -e "\nSyntax error: invalid argument to OPTION INTERNATIONAL at line $g_COUNTER in file '$g_CURFILE'!"
			    exit 1
			fi
                    elif [[ "${1#* }" = +(*NETWORK*) ]]
		    then
                        case "${1##*NETWORK }" in
                            *TCP*)
                                g_NETWORKTYPE="TCP"
                                g_SOCKTYPE="SOCK_STREAM"
                                ;;
                            *UDP*)
                                g_NETWORKTYPE="UDP"
                                g_SOCKTYPE="SOCK_DGRAM"
                                ;;
                            *BROADCAST*)
                                g_NETWORKTYPE="BROADCAST"
                                g_SOCKTYPE="SOCK_DGRAM"
                                ;;
                            *MULTICAST*)
                                g_NETWORKTYPE="MULTICAST"
                                g_SOCKTYPE="SOCK_DGRAM"
				if [[ "${1##*MULTICAST }" = +([0123456789]) ]]
				then
				    g_MULTICAST_TTL="${1##*MULTICAST }"
				fi
                                ;;
                            *SCTP*)
                                g_INCFILES="${g_INCFILES} <netinet/sctp.h>"
			        echo "struct sctp_initmsg __b2c__initmsg;" >> $g_HFILE
                                g_NETWORKTYPE="SCTP"
                                g_SOCKTYPE="SOCK_STREAM"
                                g_LDFLAGS="${g_LDFLAGS} -lsctp"
				if [[ "${1##*SCTP }" = +([0123456789]) ]]
				then
				    g_SCTP_STREAMS="${1##*SCTP }"
				fi
                                ;;
                            *)
			        echo -e "\nSyntax error: invalid argument to OPTION SOCKET at line $g_COUNTER in file '$g_CURFILE'!"
			        exit 1
                                ;;
			esac
                    elif [[ "${1#* }" = +(*PARSE*) ]]
		    then
			if [[ "${1##*PARSE }" = +([01]*|TRUE*|FALSE*) ]]
			then
                            g_IGNORE_PARSE=$(echo ${1##*PARSE })
			else
			    echo -e "\nSyntax error: invalid argument to OPTION PARSE at line $g_COUNTER in file '$g_CURFILE'!"
			    exit 1
                        fi
                    elif [[ "${1#* }" = +(*EXPLICIT*) ]]
		    then
			if [[ "${1##*EXPLICIT }" = +([01]*|TRUE*|FALSE*) ]]
			then
			    g_OPTION_EXPLICIT=$(echo ${1##*EXPLICIT })
			else
			    echo -e "\nSyntax error: invalid argument to OPTION EXPLICIT at line $g_COUNTER in file '$g_CURFILE'!"
			    exit 1
			fi
                    elif [[ "${1#* }" = +(*VARTYPE*) ]]
		    then
                        g_VARTYPE=$(echo ${1##*VARTYPE })
		    else
			echo -e "\nSyntax error: argument to OPTION at line $g_COUNTER in file '$g_CURFILE' not recognized!"
			exit 1
		    fi
		fi;;
	    "PROTO")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty PROTO at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    SYM=`echo ${1#* } | tr -d "\042"`
		    # Check if ALIAS is there
		    if [[ $SYM = +(* ALIAS *) ]]
		    then
			echo "#define ${SYM##* ALIAS } ${SYM%% ALIAS *}" >> $g_HFILE
			g_IMPORTED="${SYM##* ALIAS } $g_IMPORTED"
			g_IMPORTED="${SYM%% ALIAS *} $g_IMPORTED"
		    elif [[ $SYM = +(* TYPE *) ]]
		    then
			echo "${SYM##* TYPE } ${SYM%% TYPE *};" >> $g_HFILE
		    else
			g_IMPORTED="${SYM//,/ } $g_IMPORTED"
		    fi
		fi;;
	    "INCR")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty INCR at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
                    # Get left side
                    TOKEN=$(Mini_Parser "${1}")
                    # Get right side
                    EXP="${1:${#TOKEN}+1}"
                    if [[ ${#EXP} -eq 0 ]]
                    then
                        EXP="1"
                    fi
                    TOKEN=${TOKEN#* }
		    # Check if there is associative array assignment
		    if [[ "${TOKEN}" = +(*[a-zA-Z]\(*\)) ]]
		    then
			INC=${TOKEN#*\(}
                        echo "__b2c__assoc_${TOKEN%%\(*}_eval = ${TOKEN} + (${EXP}); __b2c__hash_add(__b2c__assoc_${TOKEN%%\(*}, &__b2c__assoc_${TOKEN%%\(*}_eval, ${INC%\)*});" >> $g_CFILE
			# Check for relations
			Relate_Recurse "${TOKEN%%\(*}" "${INC}" "${TOKEN}+(${EXP})" "-1"
		    else
                        # Regular number
                        if [[ ${EXP} = +(*[0-9].[0-9]*) ]] 
                        then
                            Register_Numeric "${TOKEN}" "double"
                        else
                            Register_Numeric "${TOKEN}" "default"
	                fi
			echo "${TOKEN} = ${TOKEN} + (${EXP});" >> $g_CFILE
		    fi
		fi;;
	    "DECR")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty DECR at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
                    # Get left side
                    TOKEN=$(Mini_Parser "${1}")
                    # Get right side
                    EXP="${1:${#TOKEN}+1}"
                    if [[ ${#EXP} -eq 0 ]]
                    then
                        EXP="1"
                    fi
                    TOKEN=${TOKEN#* }
		    # Check if there is associative array assignment
		    if [[ "${TOKEN}" = +(*[a-zA-Z]\(*\)) ]]
		    then
			INC=${TOKEN#*\(}
                        echo "__b2c__assoc_${TOKEN%%\(*}_eval = ${TOKEN} - (${EXP}); __b2c__hash_add(__b2c__assoc_${TOKEN%%\(*}, &__b2c__assoc_${TOKEN%%\(*}_eval, ${INC%\)*});" >> $g_CFILE
			# Check for relations
			Relate_Recurse "${TOKEN%%\(*}" "${INC}" "${TOKEN}+(${EXP})" "-1"
		    else
                        # Regular number
                        if [[ ${EXP} = +(*[0-9].[0-9]*) ]] 
                        then
                            Register_Numeric "${TOKEN}" "double"
                        else
                            Register_Numeric "${TOKEN}" "default"
	                fi
			echo "${TOKEN} = ${TOKEN} - (${EXP});" >> $g_CFILE
		    fi
		fi;;
	    "ALARM")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty ALARM at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    EXP=${1#* }
                    echo "__b2c__alarm((void*)(uintptr_t)(&${EXP%,*}), ${EXP#*,});" >> $g_CFILE
		fi;;
	    "SIGNAL")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty SIGNAL at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    EXP=${1#* }
		    if [[ ${EXP} = +(*,*) ]]
		    then
                        if [[ ${EXP%,*} = +(*SIG_DFL*) || ${EXP%,*} = +(*SIG_IGN*) ]]
                        then
                            echo "__b2c__signal((void*)(uintptr_t)${EXP%,*}, ${EXP#*,});" >> $g_CFILE
                        else
                            echo "__b2c__signal((void*)(uintptr_t)(&${EXP%,*}), ${EXP#*,});" >> $g_CFILE
                        fi
		    else
			echo -e "\nSyntax error: missing argument in SIGNAL at line $g_COUNTER in file '$g_CURFILE'!"
			exit 1
		    fi
		fi;;
	    "CURSOR")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty CURSOR at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
                    EXP=1
		    if [[ "${1#* }" = +(*OFF*) ]]
		    then
			echo "fprintf(stdout,\"\033[?25l\"); fflush(stdout);" >> $g_CFILE
		    elif [[ "${1#* }" = +(*ON*) ]]
		    then
			echo "fprintf(stdout,\"\033[?25h\"); fflush(stdout);" >> $g_CFILE
            	    elif [[ "${1#* }" = +(*UP*) ]]
		    then
                        if [[ ${1##*UP } != +(*UP*) ]]
                        then
                            EXP=${1##*UP }
                        fi
			echo "fprintf(stdout,\"\033[%ldA\", (long)${EXP}); fflush(stdout);" >> $g_CFILE
		    elif [[ "${1#* }" = +(*DOWN*) ]]
		    then
                        if [[ ${1##*DOWN } != +(*DOWN*) ]]
                        then
                            EXP=${1##*DOWN }
                        fi
			echo "fprintf(stdout,\"\033[%ldB\", (long)${EXP}); fflush(stdout);" >> $g_CFILE
		    elif [[ "${1#* }" = +(*FORWARD*) ]]
		    then
                        if [[ ${1##*FORWARD } != +(*FORWARD*) ]]
                        then
                            EXP=${1##*FORWARD }
                        fi
			echo "fprintf(stdout,\"\033[%ldC\", (long)${EXP}); fflush(stdout);" >> $g_CFILE
		    elif [[ "${1#* }" = +(*BACK*) ]]
		    then
                        if [[ ${1##*BACK } != +(*BACK*) ]]
                        then
                            EXP=${1##*BACK }
                        fi
			echo "fprintf(stdout,\"\033[%ldD\", (long)${EXP}); fflush(stdout);" >> $g_CFILE
		    fi
		fi;;
            "SCROLL")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty SCROLL at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
                    EXP=1
		    if [[ "${1#* }" = +(*UP*) ]]
		    then
                        if [[ ${1##*UP } != +(*UP*) ]]
                        then
                            EXP=${1##*UP }
                        fi
			echo "fprintf(stdout,\"\033[%ldS\", (long)${EXP}); fflush(stdout);" >> $g_CFILE
		    elif [[ "${1#* }" = +(*DOWN*) ]]
		    then
                        if [[ ${1##*DOWN } != +(*DOWN*) ]]
                        then
                            EXP=${1##*DOWN }
                        fi
			echo "fprintf(stdout,\"\033[%ldT\", (long)${EXP}); fflush(stdout);" >> $g_CFILE
		    fi
		fi;;
	    "ALIAS")
		Handle_Alias "${1#* }";;
	    "LOOKUP")
		Handle_Lookup "${1#* }";;
	    "RELATE")
		Handle_Relate "${1#* }";;
	    "TEXTDOMAIN")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty TEXTDOMAIN at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    EXP=${1#* }
		    if [[ ${EXP} = +(*,*) ]]
		    then
			echo "if(bindtextdomain(${EXP})==NULL){if(__b2c__trap){ERROR = 6;if(!__b2c__catch_set) RUNTIMEERROR(\"TEXTDOMAIN\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
			echo "if(textdomain(${EXP%,*})==NULL){if(__b2c__trap){ERROR = 6; if(!__b2c__catch_set) RUNTIMEERROR(\"TEXTDOMAIN\", $g_COUNTER, \"$g_CURFILE\", ERROR); else if(!setjmp(__b2c__jump)) goto $g_CATCHGOTO;} }" >> $g_CFILE
                        if [[ ${g_CATCHGOTO} = "__B2C__PROGRAM__EXIT" ]]
                        then
                            g_CATCH_USED=1
                        fi
		    else
			echo -e "\nSyntax error: missing argument in TEXTDOMAIN at line $g_COUNTER in file '$g_CURFILE'!"
			exit 1
		    fi
		fi;;
	    "REDIM")
		Handle_Redim "${1#* }";;
            "EXIT")
		if [[ -z $g_FUNCNAME ]]
		then
		    echo -e "\nSyntax error: EXIT not in FUNCTION or SUB at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		fi
		# Free strings variables if there are any
		echo "${g_STRINGARRAYS}" >> $g_CFILE
		for EXP in $g_LOCALSTRINGS
		do
		    echo "__b2c__STRFREE($EXP);" >> $g_CFILE
		done
		echo "__b2c__catch_set = __b2c__catch_set_backup;" >> $g_CFILE
		# The actual exit
		if [[ "${g_FUNCNAME}" = +(*${g_STRINGSIGN}*) ]]
		then
		    echo "return(NULL);" >> $g_CFILE
		else
		    echo "return __b2c__exitval;" >> $g_CFILE
		fi;;
	    "PRAGMA")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty PRAGMA at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
		    if [[ "${1#* }" = +(*OPTIONS*) ]]
		    then
                        g_CCFLAGS="$g_CCFLAGS ${1##*OPTIONS }"
		    elif [[ "${1#* }" = +(*COMPILER*) ]]
		    then
                        g_CCNAME="${1##*COMPILER }"
	            elif [[ "${1#* }" = +(*FRAMEWORK*) ]] 
                    then
			g_LDFLAGS="$g_LDFLAGS -framework ${1##*FRAMEWORK }"
                    elif [[ "${1#* }" = +(*RE*) ]]
		    then
                        g_PRAGMA_REGEX=$(echo ${1##*RE })
                        if [[ $g_PRAGMA_REGEX != +(* LDFLAGS *) ]]
                        then
                            EXP=${g_PRAGMA_REGEX%% *}
                            if [[ $EXP = +(*tre*) ]]
                            then
                                g_LDFLAGS="$g_LDFLAGS $(pkg-config --libs tre)"
                            elif [[ $EXP = +(*pcre*) ]]
                            then
                                g_LDFLAGS="$g_LDFLAGS $(pkg-config --libs libpcreposix)"
                            elif [[ $EXP = +(*onig*) ]]
                            then
                                g_LDFLAGS="$g_LDFLAGS $(pkg-config --libs oniguruma)"
                            fi
                        else
                            EXP=${g_PRAGMA_REGEX##* LDFLAGS }
                            g_LDFLAGS="${EXP} $g_LDFLAGS"
                        fi
                    elif [[ "${1#* }" = +(*TLS*) ]]
		    then
                        g_LIB_TLS=$(echo ${1##*TLS })
			g_OPTION_TLS=1
	                echo "__b2c__option_tls = 1;" >> $g_CFILE
                        if [[ $g_LIB_TLS != +(* LDFLAGS *) ]]
                        then
                            EXP=${g_LIB_TLS%% *}
                            if [[ $EXP = +(*openssl*) ]]
                            then
                                g_LIB_TLS=$(pkg-config --libs openssl)
                                g_INC_TLS="#include <openssl/ssl.h>\n#include <openssl/err.h>"
                            elif [[ $EXP = +(*gnutls*) ]]
                            then
                                g_LIB_TLS="$(pkg-config --libs gnutls) -lgnutls-openssl"
                                g_INC_TLS="#include <gnutls/openssl.h>"
                            elif [[ $EXP = +(*wolfssl*) ]]
                            then
                                g_LIB_TLS=$(pkg-config --libs wolfssl)
                                g_INC_TLS="#include <wolfssl/options.h>\n#include <wolfssl/openssl/ssl.h>"
                            fi
                        else
                            g_INC_TLS="${g_LIB_TLS%% LDFLAGS *}"
                            g_LIB_TLS="${g_LIB_TLS##* LDFLAGS }"
                        fi
                    elif [[ "${1#* }" = +(*LDFLAGS*) ]]
		    then
                        if [[ ${1##*LDFLAGS } = +(*pkg-config*) ]]
                        then
                            g_LDFLAGS="${1##*LDFLAGS } $g_LDFLAGS"
                        else
                            FOUND=0
                            for SYM in ${1##*LDFLAGS }
                            do
                                if [[ ${SYM} = "TRUE" ]]
                                then
                                    FOUND=1
                                    break
                                elif [[ ${SYM} = +(-*) || ${SYM} = +(*.a) ]]
                                then
                                    EXP="${EXP} ${SYM}"
                                else
                                    EXP="${EXP} -l${SYM}"
                                fi
                            done
                            if [[ ${FOUND} -eq 1 ]]
                            then
                                g_LDFLAGS="${EXP} ${g_LDFLAGS}"
                            else
                                g_LDFLAGS="${g_LDFLAGS} ${EXP}"
                            fi
                        fi
		    elif [[ "${1#* }" = +(*INCLUDE*) ]]
		    then
                        for EXP in ${1##*INCLUDE }
                        do
                            if [[ ${EXP:0:1} = "/" || ${EXP:0:2} = "./" ]]
                            then
                                g_PRAGMA_INCLUDE="${g_PRAGMA_INCLUDE}\n#include \"${EXP}\""
                            elif [[ ${EXP:0:1} = "<" ]]
                            then
                                g_PRAGMA_INCLUDE="${g_PRAGMA_INCLUDE}\n#include ${EXP}"
                            else
                                g_PRAGMA_INCLUDE="${g_PRAGMA_INCLUDE}\n#include \"`pwd`/${EXP}\""
                            fi
                        done
		    else
                        echo "#pragma ${1##*PRAGMA }" >> $g_CFILE
		    fi
		fi;;
	    "SWAP")
		Handle_Swap "${1#* }";;
	    "SETSERIAL")
		Handle_Setserial "${1#* }";;
	    "ENUM")
                if [[ -z $g_FUNCNAME ]]
                then
                    echo "enum {" >> $g_HFILE
		    let g_USE_H=1
                else
                    echo "enum {" >> $g_CFILE
		    let g_USE_C=1
                fi;;
	    "RUN")
		Handle_Run "${1#* }";;
	    "SAVE")
		Handle_Save "0" "${1#* }";;
	    "BSAVE")
		Handle_Save "1" "${1#* }";;
	    "APPEND")
                TOKEN="${1#* }"
                if [[ ${TOKEN} != +(* TO *) && ${TOKEN} = +(*,*) ]]
                then
                    echo "${TOKEN%%,*} = F_CONCAT${g_STRINGSIGN}(${TOKEN%%,*}, ${TOKEN});" >> $g_CFILE
                else
		    Handle_Save "2" "${TOKEN}"
                fi;;
	    "BAPPEND")
		Handle_Save "3" "${1#* }";;
	    "MAP")
		Handle_Map "${1#* }";;
            "RESET")
                echo "fprintf(stdout,\"\033c\"); fflush(stdout);" >> $g_CFILE
                ;;
	    "CERTIFICATE")
		# Check argument
		if [[ "${1%% *}" = "${1#* }" ]]
		then
		    echo -e "\nSyntax error: empty CERTIFICATE at line $g_COUNTER in file '$g_CURFILE'!"
		    exit 1
		else
                    EXP=${1#* }
                    TOKEN=$(Mini_Parser "${EXP}")
                    echo "#undef __b2c__caprivate" >> $g_CFILE
                    echo "#define __b2c__caprivate ${TOKEN}" >> $g_CFILE
                    EXP="${EXP:${#TOKEN}+1}"
                    TOKEN=$(Mini_Parser "${EXP}")
                    echo "#undef __b2c__caserver" >> $g_CFILE
                    echo "#define __b2c__caserver ${TOKEN}" >> $g_CFILE
                fi;;
	    "TREE")
		Handle_Tree "${1#* }";;
	    "COLLECT")
		Handle_Collect "${1#* }";;
	    "PARSE")
		Handle_Parse "${1#* }";;
            "GETKEY")
                echo "__b2c__getch();" >> $g_CFILE
                ;;
	    *)
                EXP="${1%%\(*}"
                SYM="${1%% *}"
		# Check on imported symbols first
                if [[ " ${g_IMPORTED} " = +(* "${EXP}" *) || " ${g_IMPORTED} " = +(* "${SYM}" *) ]]
                then
                    # Check if there are () - ending with ) - KSH93 construction
                    if [[ $(echo ${1}) != +(*\)) ]]
		    then
			echo "${EXP}();" >> $g_CFILE
		    else
			echo "${EXP}(${1#*\(};" >> $g_CFILE
		    fi
                else
		    Handle_Let "$1"
                fi;;
	esac
    fi
}

#-----------------------------------------------------------

function Pre_Tokenize_Functions
{
    typeset DATA IS_ESCAPED IS_STRING TOKEN CHAR ARG SRC SOURCE TYPE VARS INTOKEN FIRST DELIM VALS UNIQ POS
    typeset -i LEN NR

    # These are exceptions for small letter statements
    DATA=$(Trim "${1}")
    if [[ ${g_LOWERCASE} -eq 1 ]]
    then
        if [[ ${DATA} = +(const *) && $g_USE_C -eq 0 && $g_USE_H -eq 0 ]]
        then
            DATA="CONST ${DATA:6}"
        fi
        if [[ ${DATA} = +(* static) && $g_USE_C -eq 0 && $g_USE_H -eq 0 ]]
        then
            DATA="${DATA:0:${#DATA}-7} STATIC"
        fi
    fi

    # Check on replacing '\'-symbol
    if [[ $g_OPTION_DISABLE_C_ESCAPE = +(1*|TRUE*) ]]
    then
        POS=0
        TOKEN=
        until [[ ${POS} -eq ${#DATA} ]]
        do
	    CHAR="${DATA:${POS}:1}"
	    case $CHAR in
	        \\)
                    if [[ $IS_STRING -eq 1 ]]
		    then
                        TOKEN="${TOKEN}\\"
		    fi;;
	        \")
		    if [[ $IS_STRING -eq 0 ]]
		    then
			IS_STRING=1
		    else
			IS_STRING=0
		    fi;;
            esac
	    TOKEN="${TOKEN}${CHAR}"
            ((POS+=1))
        done
        DATA="${TOKEN// /${g_PARSEVAR}}"
    else
        DATA="${DATA// /${g_PARSEVAR}}"
    fi

    # Check if one of these conversion time functions are there - the OR's are needed for KSH93
    if [[ ${DATA} = +(*TYPEOF\$*|*SOURCE\$*|*OBTAIN\$*|*IIF\(*) || ${DATA} = +(*IIF\$\(*|*FIND\(*|*EVAL\(*|*VERIFY\(*) || ${DATA} = +(|*REM*|*LOOP*|*COIL\$*|*UBOUND\(*) || ${DATA} = +(*INVERT\(*|*INDEX*|*[^a-zA-Z0-9_]int\(*) ]]
    then
        IS_ESCAPED=0
        IS_STRING=0
        TOKEN=
        NR=1
        LEN=${#DATA}
        until [[ $LEN -eq 0 ]]
        do
	    if [[ $IS_STRING -eq 0 ]]
	    then
                CHAR="${DATA:0:7}"
	        if [[ "${CHAR}" = "TYPEOF$" ]]
                then
                    ARG=${DATA%%\)*}
                    let LEN=${#DATA}-${#ARG}-1
		    TOKEN="${TOKEN}\"$(Get_Var ${ARG##*\(} ${g_FUNCNAME})\""
                    if [[ ${LEN} -eq 0 ]]
                    then
                        break
                    fi
	            DATA="${DATA: -$LEN}"
	        elif [[ "${CHAR}" = "SOURCE$" ]]
	        then
		    if [[ ! -f $SRCARRAYFILE ]]
		    then 
			SRC=$(od -An -tu1 -v $g_SOURCEFILE)
			for i in ${SRC}
			do
			    SOURCE="$SOURCE${i},"
			done
			echo "char SOURCE${g_STRINGSIGN}[]={ ${SOURCE%?},0 };" > $SRCARRAYFILE
		    fi
                elif [[ "${CHAR}" = "OBTAIN$" ]]
                then
                    ARG=${DATA#*\(}
                    INTOKEN=$(Mini_Parser "${ARG}")
                    INTOKEN=${INTOKEN//\$/$g_STRINGSIGN}
                    INTOKEN=${INTOKEN//\#/$g_FLOATSIGN}
                    INTOKEN=${INTOKEN//\%/$g_LONGSIGN}
                    TYPE=$(Get_Var __b2c__assoc_${INTOKEN%\)*} ${g_FUNCNAME})
                    echo "#undef __b2c__obtain_type_${INTOKEN%\)*}" >> $g_CFILE
                    case ${TYPE} in
                        "char*"|"STRING")
                            echo "#define __b2c__obtain_type_${INTOKEN%\)*} 0" >> $g_CFILE
                            ;;
                        "double"|"FLOATING")
                            echo "#define __b2c__obtain_type_${INTOKEN%\)*} 1" >> $g_CFILE
                            ;;
                        "float")
                            echo "#define __b2c__obtain_type_${INTOKEN%\)*} 2" >> $g_CFILE
                            ;;
                        "long"|"NUMBER")
                            echo "#define __b2c__obtain_type_${INTOKEN%\)*} 3" >> $g_CFILE
                            ;;
                        "int")
                            echo "#define __b2c__obtain_type_${INTOKEN%\)*} 4" >> $g_CFILE
                            ;;
                        "short")
                            echo "#define __b2c__obtain_type_${INTOKEN%\)*} 5" >> $g_CFILE
                            ;;
                        "char")
                            echo "#define __b2c__obtain_type_${INTOKEN%\)*} 6" >> $g_CFILE
                            ;;
                        *)
                            echo "#define __b2c__obtain_type_${INTOKEN%\)*} -1" >> $g_CFILE
                            ;;
                    esac
                    TOKEN="${TOKEN}OBTAIN\$"
                    let LEN=${#DATA}-7
	            DATA="${DATA: -$LEN}"
                elif [[ "${CHAR}" = "VERIFY(" ]]
                then
                    ARG=${DATA#*\(}
                    INTOKEN=$(Mini_Parser "${ARG}")
                    let LEN=${#ARG}-${#INTOKEN}-1
	            INTOKEN="${DATA: -$LEN}"
                    ARG=${INTOKEN%%\)*}
                    echo "#undef __b2c__cacerts" >> $g_HFILE
                    echo "#define __b2c__cacerts ${ARG//${g_PARSEVAR}/ }" >> $g_HFILE
                    if [[ ${g_LIB_TLS} = +(*wolfssl*) ]]
                    then
                        echo "#undef __b2c__capeer" >> $g_HFILE
                        echo "#define __b2c__capeer SSL_VERIFY_PEER" >> $g_HFILE
                    fi
		    TOKEN="${TOKEN}VERIFY("
                    let LEN=${#DATA}-7
                    if [[ ${LEN} -eq 0 ]]
                    then
                        break
                    fi
	            DATA="${DATA: -$LEN}"
	        fi
                CHAR="${DATA:0:6}"
                if [[ "${CHAR}" = "UBOUND" ]]
                then
                    ARG=${DATA%%\)*}
                    let LEN=${#DATA}-${#ARG}-1
                    ARG=${ARG//\$/$g_STRINGSIGN}
                    ARG=${ARG//\#/$g_FLOATSIGN}
                    ARG=${ARG//\%/$g_LONGSIGN}
                    if [[ -n $(Get_Var "__b2c__assoc_${ARG##*\(}" ${g_FUNCNAME}) ]]
                    then
                        TOKEN="${TOKEN}NRKEYS(${ARG##*\(})"
                    elif [[ $g_DYNAMICARRAYS = +(* ${ARG##*\(}@${g_FUNCNAME} *) ]]
                    then
                        TOKEN="${TOKEN}${ARG##*\(}__b2c_array"
                    else
	                TYPE=$(Get_Var "${ARG##*\(}" ${g_FUNCNAME})
                        TOKEN="${TOKEN}(sizeof(${ARG##*\(})/sizeof(${TYPE})-${g_OPTION_BASE})"
                    fi
                    if [[ ${LEN} -eq 0 ]]
                    then
                        break
                    fi
	            DATA="${DATA: -$LEN}"
	        elif [[ "${CHAR}" = "INVERT" ]]
                then
                    ARG=${DATA#*\(}
                    INTOKEN=$(Mini_Parser "${ARG}")
                    TYPE=$(Get_Var "__b2c__assoc_${INTOKEN}" ${g_FUNCNAME})
                    case ${TYPE} in
                        "char*"|"STRING")
                            NR=0;;
                        "double"|"FLOATING")
                            NR=1;;
                        "float")
                            NR=2;;
                        "long"|"NUMBER")
                            NR=3;;
                        "int")
                            NR=4;;
                        "short")
                            NR=5;;
                        "char")
                            NR=6;;
                        *)
                            NR=-1;;
                    esac
                    INTOKEN=${INTOKEN//\$/$g_STRINGSIGN}
                    INTOKEN=${INTOKEN//\#/$g_FLOATSIGN}
                    INTOKEN=${INTOKEN//\%/$g_LONGSIGN}
                    TOKEN="${TOKEN}INVERT(${NR},"
                    let LEN=${#DATA}-7
	            DATA="${DATA: -$LEN}"
                fi
                CHAR="${DATA:0:6}"
	        if [[ "${CHAR}" = "INDEX(" || "${CHAR}" = "INDEX$" ]]
                then
                    ARG=${DATA#*\(}
                    INTOKEN=$(Mini_Parser "${ARG}")
                    TYPE=$(Get_Var "__b2c__assoc_${INTOKEN}" ${g_FUNCNAME})
                    if [[ -z ${TYPE} ]]
                    then
                        TYPE=$(Get_Var ${INTOKEN} ${g_FUNCNAME})
                    fi
                    case ${TYPE} in
                        "char*"|"STRING")
                            NR=0;;
                        "double"|"FLOATING")
                            NR=1;;
                        "float")
                            NR=2;;
                        "long"|"NUMBER")
                            NR=3;;
                        "int")
                            NR=4;;
                        "short")
                            NR=5;;
                        "char")
                            NR=6;;
                        *)
                            NR=-1;;
                    esac
                    INTOKEN=${INTOKEN//\$/$g_STRINGSIGN}
                    INTOKEN=${INTOKEN//\#/$g_FLOATSIGN}
                    INTOKEN=${INTOKEN//\%/$g_LONGSIGN}
                    if [[ -n $(Get_Var "__b2c__assoc_${INTOKEN}" ${g_FUNCNAME}) ]]
                    then
                        TOKEN="${TOKEN}INDEX\$(${NR},"
                        let LEN=${#DATA}-7
                    elif [[ $g_DYNAMICARRAYS = +(* ${INTOKEN}@${g_FUNCNAME} *) ]]
                    then
                        TOKEN="${TOKEN}INDEX(${INTOKEN}__b2c_array,${NR},"
                        let LEN=${#DATA}-6
                    else
	                TYPE=$(Get_Var "${INTOKEN}" ${g_FUNCNAME})
                        TOKEN="${TOKEN}INDEX(sizeof(${INTOKEN})/sizeof(${TYPE})-${g_OPTION_BASE},${NR},"
                        let LEN=${#DATA}-6
                    fi
	            DATA="${DATA: -$LEN}"
                fi
                CHAR="${DATA:0:5}"
                if [[ "${CHAR}" = "LOOP$" || "${CHAR}" = "COIL$" || "${CHAR}" = "LOOP(" ]]
                then
                    DELIM="__b2c__option_delim"
                    ARG=${DATA#*\(}
                    FIRST=$(Mini_Parser "${ARG}")
                    let LEN=${#DATA}-${#FIRST}-7
	            ARG="${ARG: -$LEN}"
                    SECOND=$(Mini_Parser "${ARG}")
                    let LEN=${#ARG}-${#SECOND}
	            ARG="${ARG: -$LEN}"
                    if [[ ${ARG:0:1} = "," ]]
                    then
                        ARG="${ARG:1}"
                        SRC=$(Mini_Parser "${ARG}")
                        let LEN=${#ARG}-${#SRC}
	                ARG="${ARG: -$LEN}"
                        if [[ ${ARG:0:1} = "," ]]
                        then
                            ARG="${ARG:1}"
                            DELIM=$(Mini_Parser "${ARG}")
                        fi
                    else
                        SRC="${SECOND}"
                        SECOND="${FIRST}"
                        FIRST="_"
                    fi
                    if [[ ${SRC} = +(*LOOP*|*COIL\$*) || ${ARG} = +(*LOOP*|*COIL\$*) ]]
                    then
                        TOKEN="LOOP_ERROR"
		        break
                    fi
                    if [[ "${CHAR}" = "LOOP$" ]]
                    then
                        TOKEN=$(Pre_Tokenize_Functions "IF setjmp(__b2c__loop2) THEN:FOR ${FIRST}=1 TO ${SECOND}:__b2c__loop_result${g_STRINGSIGN} = CONCAT\$(__b2c__loop_result${g_STRINGSIGN}, ${SRC}):NEXT:CALL longjmp(__b2c__loop1, 1):ENDIF:${TOKEN}")
                    elif [[ "${CHAR}" = "COIL$" ]]
                    then
                        TOKEN=$(Pre_Tokenize_Functions "IF setjmp(__b2c__loop2) THEN:FOR ${FIRST}=1 TO ${SECOND}:__b2c__loop_result${g_STRINGSIGN} = APPEND\$(__b2c__loop_result${g_STRINGSIGN}, 0, ${SRC}, ${DELIM}):NEXT:CALL longjmp(__b2c__loop1, 1):ENDIF:${TOKEN}")
                    else
                        TOKEN=$(Pre_Tokenize_Functions "IF setjmp(__b2c__loop2) THEN:FOR ${FIRST}=1 TO ${SECOND}:__b2c__loop_result = __b2c__loop_result + (${SRC}):NEXT:CALL longjmp(__b2c__loop1, 1):ENDIF:${TOKEN}")
                    fi
                elif [[ "${CHAR}" = "IIF\$(" ]]
                then
                    ARG=${DATA#*\(}
                    INTOKEN=$(Mini_Parser "${ARG}")
                    if [[ $ARG = +(*${g_PARSEVAR}BETWEEN${g_PARSEVAR}*\;*) || $ARG = +(*${g_PARSEVAR}BEYOND${g_PARSEVAR}*\;*) ]]
                    then
                        ARG="${ARG:${#INTOKEN}+1}"
                        INTOKEN="$INTOKEN;$(Mini_Parser ${ARG})"
                    fi
                    Parse_Equation "${INTOKEN}"
                    g_EQUATION=$(Pre_Tokenize_Functions "${g_EQUATION}")
		    TOKEN="${TOKEN}IIF\$(${g_EQUATION}"
                    let LEN=${#DATA}-${#INTOKEN}-5
	            DATA="${DATA: -$LEN}"
                elif [[ "${CHAR}" = "EVAL(" ]]
                then
                    if [[ $NR -eq 1 ]]
	            then
                        UNIQ=$(echo ${TOKEN} | cksum - | cut -d' ' -f1)
                        VARS="char *__b2c_evalvars_${g_FUNCNAME}_${g_COUNTER}_${UNIQ}[] = {"
                        VALS="double __b2c_evalvals_${g_FUNCNAME}_${g_COUNTER}_${UNIQ}[] = {"
                        for i in ${!g_ALL_FUNC_VARS[@]}
                        do
                            if [[ "${i##*___}" = ${g_FUNCNAME} ]]
                            then
                                TYPE=$(Get_Var ${i%%___*} ${g_FUNCNAME})
                                if [[ ${TYPE} != +(*\**) && ${TYPE} = +(*double|*FLOATING) ]]
                                then
                                    SRC=${i%%___*}
                                    VARS="${VARS}\"${SRC}\","
                                    VALS="${VALS}${SRC},"
                                    ((NR+=1))
                                fi
                            fi
                        done
                        for i in ${!g_ALL_MAIN_VARS[@]}
                        do
                            TYPE=$(Get_Var $i)
                            if [[ ${TYPE} != +(*\**) && ${TYPE} = +(*double|*FLOATING) ]]
                            then
                                VARS="${VARS}\"${i}\","
                                VALS="${VALS}${i},"
                                ((NR+=1))
                            fi
                        done
                        echo "${VARS} NULL};" >> $g_CFILE
                        echo "${VALS} 0};" >> $g_CFILE
                    fi
		    TOKEN="${TOKEN}EVAL(__b2c_evalvars_${g_FUNCNAME}_${g_COUNTER}_${UNIQ},__b2c_evalvals_${g_FUNCNAME}_${g_COUNTER}_${UNIQ},${NR}-1,"
                    let LEN=${#DATA}-5
	            DATA="${DATA: -$LEN}"
                elif [[ "${CHAR}" = "FIND(" ]]
                then
                    ARG=${DATA#*\(}
                    FIRST=$(Mini_Parser "${ARG}")
                    INTOKEN=$(Trim "${FIRST//\$/$g_STRINGSIGN}")
                    INTOKEN=${INTOKEN//\#/$g_FLOATSIGN}
                    INTOKEN=${INTOKEN//\%/$g_LONGSIGN}
                    TYPE=$(Get_Var __b2c__tree_${INTOKEN} ${g_FUNCNAME})
                    let LEN=${#ARG}-${#FIRST}-1
	            ARG="${ARG: -$LEN}"
                    SECOND=$(Mini_Parser "${ARG}")
                    UNIQ="__b2c__${INTOKEN}_${g_COUNTER}_${RANDOM}"
                    if [[ ${TYPE#*:} = +(*char\**) ]]
                    then
                        echo "char *${UNIQ} = (char*)${SECOND};" >> $g_CFILE
                        TOKEN="${TOKEN}FIND(${TYPE%:*},${FIRST},(void**)${UNIQ},0"
                    else
                        echo "${TYPE#*:} *${UNIQ} = (${TYPE#*:}*)malloc(sizeof(${TYPE#*:})); *${UNIQ} = (${TYPE#*:})${SECOND};" >> $g_CFILE
                        TOKEN="${TOKEN}FIND(${TYPE%:*},${FIRST},(void*)${UNIQ},1"
                    fi
                    let LEN=${#DATA}-${#FIRST}-${#SECOND}-6
	            DATA="${DATA: -$LEN}"
                fi
                CHAR="${DATA:0:4}"
	        if [[ "${CHAR}" = "IIF(" ]]
                then
                    ARG=${DATA#*\(}
                    INTOKEN=$(Mini_Parser "${ARG}")
                    if [[ $ARG = +(*${g_PARSEVAR}BETWEEN${g_PARSEVAR}*\;*) || $ARG = +(*${g_PARSEVAR}BETWEEN${g_PARSEVAR}*\;*) ]]
                    then
                        ARG="${ARG:${#INTOKEN}+1}"
                        INTOKEN="$INTOKEN;$(Mini_Parser ${ARG})"
                    fi
                    Parse_Equation "${INTOKEN}"
                    g_EQUATION=$(Pre_Tokenize_Functions "${g_EQUATION}")
		    TOKEN="${TOKEN}IIF(${g_EQUATION}"
                    let LEN=${#DATA}-${#INTOKEN}-4
	            DATA="${DATA: -$LEN}"
	        elif [[ "${CHAR}" = +(REM[[:space:]]|REM${g_PARSEVAR}) || ${DATA} = "REM" ]]
                then
                    let LEN=0
                    break
	        elif [[ ${g_LOWERCASE} -eq 1 && "${CHAR}" = "int(" ]]
                then
                    TOKEN="${TOKEN}INT("
                    let LEN=${#DATA}-4
	            DATA="${DATA: -$LEN}"
                fi
            fi
	    CHAR="${DATA:0:1}"
	    case $CHAR in
	        \\)
		    if [[ $IS_ESCAPED -eq 0 ]]
		    then
		        IS_ESCAPED=1
		    else
		        IS_ESCAPED=0
		    fi;;
	        \")
		    if [[ $IS_ESCAPED -eq 0 ]]
		    then
		        if [[ $IS_STRING -eq 0 ]]
		        then
			    IS_STRING=1
		        else
			    IS_STRING=0
		        fi
		    fi
		    IS_ESCAPED=0;;
            esac
	    TOKEN="${TOKEN}${CHAR}"
	    let LEN=${#DATA}-1
	    DATA="${DATA: -$LEN}"
        done
        echo "${TOKEN}"
    else
        echo "${DATA}"
    fi
}

#-----------------------------------------------------------

function Tokenize
{
    typeset CHAR IS_STATEMENT TOKEN DATA LEN LINE INLEN INCHAR INTOKEN ITEM1 ITEM2 RESULT ELEM STR
    typeset -i DIRECT INSPAC BRACKET ISQUOTE IS_STRING INSTR IS_ESCAPED INESCAPED IN_FUNC SFTOT=0

    # Verify if there is a class definition or we are in a (multiline) comment
    if [[ ${1} = +(CLASS*) || $g_COMMENT -eq 1 ]]
    then
        Parse_Line "${1}"
        return
    fi

    # In TRACE MODE show linenr and code
    if [[ $g_TRACE -eq 1 ]]
    then
        if [[ ${1} != +(FUNCTION*) && ${1} != +(SUB*) && ${1} != +(ELIF*) && ${1} != +(ELSE*) && -z ${g_TRACE_PREFIX} ]]
        then
	    echo "if(__b2c__getch() == 27) {fprintf(stderr, \"TRACE OFF - exiting trace mode.\n\"); exit(EXIT_SUCCESS);}" >> $g_CFILE
	    LINE=$(echo ${1} | tr '\042\134\045' '\047\057\043')
	    echo "fprintf(stderr, \"File '${g_CURFILE}' line %d: ${LINE}\n\", $g_COUNTER);" >> $g_CFILE
            if [[ -n $g_MONITOR ]]
            then
                echo "${g_MONITOR#*&&} ;" >> $g_CFILE
            fi
        fi
        g_TRACE_PREFIX=
    fi

    # Initialize miniparser, convert spaces
    DATA=$(Pre_Tokenize_Functions "${1}")
    RESULT="${DATA//${g_PARSEVAR}/ }"

    # Check on nested loops
    if [[ ${DATA} = "LOOP_ERROR" ]]
    then
        echo -e "\nSyntax error: multiple LOOP$/COIL$/LOOP functions in one statement at line $g_COUNTER in file '$g_CURFILE'!"
        exit 1
    fi

    while true
    do
        IN_FUNC=0
        IS_ESCAPED=0
        IS_STRING=0
        IS_STATEMENT=""
        TOKEN=
        LEN=${#DATA}

        until [[ $LEN -eq 0 ]]
        do
	    CHAR="${DATA:0:1}"
	    case $CHAR in
	        :)
                    if [[ $IS_STRING -eq 0 && "${DATA:1:1}" = ":" ]]
                    then
	                let LEN=${#DATA}-1
	                DATA="${DATA: -$LEN}"
	                TOKEN="${TOKEN}:"
		    elif [[ $IS_STRING -eq 0 && $g_USE_C -eq 0 && $g_USE_H -eq 0 && $IN_FUNC -eq 0 ]]
		    then
		        Tokenize "${TOKEN//${g_PARSEVAR}/ }"
		        CHAR=
		        TOKEN=
		        IS_STATEMENT=""
		    fi;;
	        ${g_TAB})
		    if [[ $IS_STRING -eq 0 ]]
		    then
		        TOKEN="${TOKEN} "
                    else
		        TOKEN="${TOKEN}${g_TAB}"
                    fi
		    CHAR=
		    IS_ESCAPED=0
		    ;;
	        $)
		    if [[ $IS_STRING -eq 0 || ${1} = +(*IMPORT*FROM*TYPE*) ]]
		    then
		        TOKEN="${TOKEN}${g_STRINGSIGN}"
		        CHAR=
		        IS_ESCAPED=0
		    fi;;
                \()
                    if [[ ${IS_STRING} -eq 0 && $g_USE_C -eq 0 && $g_USE_H -eq 0 ]]
                    then
                        ((IN_FUNC+=1))
                    fi;;
                \))
                    if [[ ${IS_STRING} -eq 0 && $g_USE_C -eq 0 && $g_USE_H -eq 0 ]]
                    then
                        ((IN_FUNC-=1))
                    fi;;
                \?)
                    if [[ ${IS_STRING} -eq 0 && $g_USE_C -eq 0 && $g_USE_H -eq 0 && $IN_FUNC -eq 0 ]]
                    then
                        CHAR="PRINT "
                    fi;;
                \[)
                    if [[ ${IS_STRING} -eq 0 && "${DATA:0:2}" != "[]" && "${DATA:0:11}" != "[(uint64_t)" ]]
                    then
                        CHAR="[(uint64_t)"
                    fi;;
	        %)
		    if [[ $IS_STRING -eq 0 && ${TOKEN: -1} = +([a-zA-Z0-9_]) ]]
		    then
		        TOKEN="${TOKEN}${g_LONGSIGN}"
		        CHAR=
		        IS_ESCAPED=0
		    fi;;
	        \#)
		    if [[ $IS_STRING -eq 0 && ${TOKEN: -1} = +([a-zA-Z0-9_]) && ${#TOKEN} -gt 0 ]]
		    then
		        TOKEN="${TOKEN}${g_FLOATSIGN}"
		        CHAR=
		        IS_ESCAPED=0
		    fi;;
	        \\)
		    if [[ $IS_ESCAPED -eq 0 ]]
		    then
		        IS_ESCAPED=1
		    else
		        IS_ESCAPED=0
		    fi;;
	        \")
		    if [[ $IS_ESCAPED -eq 0 ]]
		    then
		        if [[ $IS_STRING -eq 0 ]]
		        then
			    IS_STRING=1
		        else
			    IS_STRING=0
		        fi
		    fi
		    IS_ESCAPED=0;;
                \&|\+)
		    if [[ $IS_STRING -eq 0 && $g_USE_C -eq 0 && $g_USE_H -eq 0 ]]
		    then
                        # ITEMIZER1: Get item on the left side
                        INTOKEN="${TOKEN// /${g_PARSEVAR}}"
                        INLEN=${#INTOKEN}
                        ITEM1=""
                        BRACKET=0
                        INSPAC=0
                        INSTR=0
                        DIRECT=0
                        ISQUOTE=0
                        until [[ $INLEN -eq 0 ]]
                        do
                            INCHAR="${INTOKEN: -1}"
                            case ${INCHAR} in
                                \)|\])
                                    ISQUOTE=0
                                    DIRECT=1
                                    if [[ ${INSTR} -eq 0 ]]
                                    then
                                        ((BRACKET+=1))
                                    fi;;
                                \(|\[)
                                    ISQUOTE=0
                                    DIRECT=1
                                    if [[ ${INSTR} -eq 0 ]]
                                    then
                                        ((BRACKET-=1))
                                        if [[ ${BRACKET} -lt 0 ]]
                                        then
                                            break
                                        fi
                                    fi;;
                                =)
                                    ISQUOTE=0
                                    if [[ ${INSTR} -eq 0 ]]
                                    then
                                        break
                                    fi;;
                                \>)
                                    if [[ "${INTOKEN: -2}" != "->" ]]
                                    then
                                        ISQUOTE=0
                                        if [[ ${INSTR} -eq 0 ]]
                                        then
                                            break
                                        fi
                                    fi;;
                                ,|-|\*|\/|%|\<)
                                    ISQUOTE=0
                                    if [[ ${INSTR} -eq 0 && ${BRACKET} -eq 0 ]]
                                    then
                                        break
                                    fi;;
                    	        \\)
		                    if [[ $ISQUOTE -eq 1 ]]
		                    then
		                        INSTR=1
		                    fi
                                    ISQUOTE=0;;
	                        \")
                                    ISQUOTE=1
                                    DIRECT=1
		                    if [[ $INSTR -eq 0 ]]
		                    then
			                INSTR=1
		                    else
			                INSTR=0
		                    fi;;
                                [A-Za-z])
                                    ISQUOTE=0
                                    DIRECT=1
                                    if [[ ${INSTR} -eq 0 && ${BRACKET} -eq 0 ]]
                                    then
                                        if [[ $INSPAC -gt 0 ]]
                                        then
                                            break
                                        fi
                                    fi;;
                                ${g_PARSEVAR})
                                    ISQUOTE=0
                                    if [[ ${INSTR} -eq 0 && ${BRACKET} -eq 0 ]]
                                    then
                                        if [[ ${DIRECT} -gt 0 ]]
                                        then
                                            INSPAC=1
                                        fi
                                    fi;;
                                :)
                                    if [[ ${BRACKET} -eq 0 ]]
                                    then
                                        ISQUOTE=0
                                        if [[ ${INSTR} -eq 0 ]]
                                        then
                                            break
                                        fi
                                    fi;;
                            esac
	                    if [[ "${INCHAR}" = "${g_PARSEVAR}" ]]
	                    then
	                        ITEM1=" ${ITEM1}"
                            else
	                        ITEM1="${INCHAR}${ITEM1}"
                            fi
                            let INLEN=${#INTOKEN}-1
                            INTOKEN="${INTOKEN:0:$INLEN}"
                        done
                        # If ITEM is a string element continue
			if [[ $(Check_String_Type ${ITEM1}) -eq 1 ]]
			then
                            TOKEN="${INTOKEN// /${g_PARSEVAR}}"
                            # ITEMIZER2: Get item on the right side
                            ((LEN-=1))
                            INTOKEN="${DATA: -$LEN}"
                            INLEN=${#INTOKEN}
                            ITEM2=""
                            BRACKET=0
                            INSTR=0
                            INESCAPED=0
			    INSPAC=0
			    DIRECT=0
                            until [[ $INLEN -eq 0 ]]
                            do
                                INCHAR="${INTOKEN:0:1}"
                                case $INCHAR in
                                    \()
					DIRECT=1
                                        if [[ ${INSTR} -eq 0 ]]
                                        then
                                            ((BRACKET+=1))
                                        fi;;
                                    \))
					DIRECT=1
                                        if [[ ${INSTR} -eq 0 ]]
                                        then
                                            ((BRACKET-=1))
                                            if [[ ${BRACKET} -lt 0 ]]
                                            then
                                                break
                                            fi
                                        fi;;
                                    ,|\=|\<|\>|\!|-|\*|\/|%)
                                        if [[ ${INSTR} -eq 0 && ${BRACKET} -eq 0 ]]
                                        then
                                            break
                                        fi;;
                                    \&|\+)
                                        if [[ ${INSTR} -eq 0 && ${BRACKET} -eq 0 ]]
                                        then
			                    INSPAC=0
			                    DIRECT=0
                                            INCHAR=","
                                        fi;;
            	                    \\)
		                        if [[ $INESCAPED -eq 0 ]]
		                        then
		                            INESCAPED=1
		                        else
		                            INESCAPED=0
		                        fi;;
	                            \")
					DIRECT=1
		                        if [[ $INESCAPED -eq 0 ]]
		                        then
		                            if [[ $INSTR -eq 0 ]]
		                            then
			                        INSTR=1
		                            else
			                        INSTR=0
		                            fi
                                        fi
                                        INESCAPED=0;;
				    [A-Za-z])
					DIRECT=1
					if [[ ${INSTR} -eq 0 && ${BRACKET} -eq 0 ]]
					then
					    if [[ $INSPAC -gt 0 ]]
					    then
						break
					    fi
					fi;;
				    ${g_PARSEVAR})
					if [[ ${INSTR} -eq 0 && ${BRACKET} -eq 0 ]]
					then
					    if [[ ${DIRECT} -gt 0 ]]
					    then
						INSPAC=1
					    fi
					fi;;
                                    :|\;)
                                        if [[ ${INSTR} -eq 0 && ${BRACKET} -eq 0 ]]
                                        then
                                            break
                                        fi;;
                                esac
	                        if [[ "${INCHAR}" = "${g_PARSEVAR}" ]]
	                        then
	                            ITEM2="${ITEM2} "
                                elif [[ "${INCHAR}" = "$" ]]
                                then
		                    if [[ $INSTR -eq 0 || ${1} = +(*IMPORT*FROM*TYPE*) ]]
		                    then
	                                ITEM2="${ITEM2}${g_STRINGSIGN}"
                                    else
	                                ITEM2="${ITEM2}$"
                                    fi
                                else
	                            ITEM2="${ITEM2}${INCHAR}"
                                fi
                                let INLEN=${#INTOKEN}-1
                                INTOKEN="${INTOKEN: -$INLEN}"
                            done
                            ELEM=$(Mini_Parser "${ITEM2}")
                            if [[ $(Check_String_Type ${ELEM}) -eq 1 ]]
			    then
                                TOKEN="${TOKEN} CONCAT${g_STRINGSIGN}(${ITEM1},${ITEM2}) "
                                ((INLEN+=1))
		                DATA="${DATA: -$INLEN}"
                            else
	                        TOKEN="${TOKEN}${ITEM1}${CHAR}"
                            fi
                            CHAR=""
                        fi
                    fi
		    IS_ESCAPED=0;;
                [A-Za-z=])
		    if [[ $IS_STRING -eq 0 ]]
		    then
		        IS_STATEMENT=" "
		    fi
		    IS_ESCAPED=0;;
	        *)
		    IS_ESCAPED=0;;
	    esac
	    # Convert back to space
	    if [[ "${CHAR}" = "${g_PARSEVAR}" ]]
	    then
	        TOKEN="${TOKEN}${IS_STATEMENT}"
            elif [[ -n ${CHAR} ]]
            then
	        TOKEN="${TOKEN}${CHAR}"
	    fi
	    let LEN=${#DATA}-1
	    DATA="${DATA: -$LEN}"
        done
        # Check if all nested '&' and '+' have been parsed. The '%' is the modulo operator, but also an integer suffix.
        if [[ "${TOKEN//[&+%]/}" = "${TOKEN}" || "${TOKEN}" = "${RESULT}" ]]
        then
            break
        fi
        RESULT=${TOKEN}
        DATA="${TOKEN// /${g_PARSEVAR}}"
    done

    # Determine amount of string funcs: substitute string macros
    for STR in ${!g_MACRO_STRINGS[@]}
    do
        RESULT="${RESULT//${STR}/${g_MACRO_STRINGS[${STR}]}}"
    done
    # Determine amount of string funcs: count
    while [[ "${RESULT//${g_STRINGSIGN}\(/}" != "${RESULT}" ]]
    do
        ((SFTOT+=1))
        RESULT="${RESULT/${g_STRINGSIGN}\(/}"
    done
    if [[ $SFTOT -gt $g_STRING_FUNC ]]
    then
        g_STRING_FUNC=$SFTOT
    fi

    # Start parsing
    Parse_Line "${TOKEN//${g_PARSEVAR}/ }"
}

#-----------------------------------------------------------

function Parse_Chunk
{
    typeset CHAR IS_ESCAPED IS_STRING IS_POINTER TOKEN DATA LEN TERM EQ IS_EQUATION CHECK LAST V1 V2 LB RB

    IS_ESCAPED=0
    IS_POINTER=0
    IS_STRING=0
    IS_EQUATION=0
    CHECK=0
    TOKEN=

    # Check if this is a string
    if [[ $(Check_String_Type "${1}") -eq 1 ]]
    then
        CHECK=1
    fi

    # Initialize miniparser, convert spaces
    DATA=$(Trim "${1}")
    LEN=${#DATA}

    # Keep track of surrounding brackets
    while [[ ${DATA:0:1} = "(" ]]
    do
        ((LEN-=1))
        DATA=${DATA:1}
        LB="${LB}("
    done
    while [[ ${DATA: -1} = ")" ]]
    do
        ((LEN-=1))
        DATA=${DATA:0:${LEN}}
        RB="${RB})"
    done
    DATA=$(echo ${DATA// /${g_PARSEVAR}})

    until [[ $LEN -eq 0 ]]
    do
        CHAR="${DATA:0:8}"
        if [[ ${#DATA} -gt 8 && $CHAR = "BETWEEN${g_PARSEVAR}" ]]
        then
            TERM="${DATA##*BETWEEN}"
            V1=$(Mini_Parser "${TERM}" "AND")
            TERM="${TERM:${#V1}}"
            if [[ ${TERM} = +(AND*) ]]
            then
                V2="${TERM:3}"
            else
                V2="${TERM:1}"
            fi
            if [[ $CHECK -eq 1 ]]
            then
                if [[ $V2 = +(*${g_PARSEVAR}EXCL) ]]
                then
                    TOKEN="(__b2c__STRCMP(${LB}$TOKEN, __b2c__min_str($V1,${V2%EXCL*}))${RB} > 0 && __b2c__STRCMP(${LB}$TOKEN, __b2c__max_str($V1,${V2%EXCL*}))${RB} < 0 ? 1 : 0)"
                else
                    TOKEN="(__b2c__STRCMP(${LB}$TOKEN, __b2c__min_str($V1,$V2))${RB} >= 0 && __b2c__STRCMP(${LB}$TOKEN, __b2c__max_str($V1,$V2))${RB} <= 0 ? 1 : 0)"
                fi
                CHECK=0
            else
                if [[ $V2 = +(*${g_PARSEVAR}EXCL) ]]
                then
                    TOKEN="(${LB}$TOKEN > fmin($V1,${V2%EXCL*})${RB} && ${LB}$TOKEN < fmax($V1,${V2%EXCL*})${RB} ? 1 : 0)"
                else
                    TOKEN="(${LB}$TOKEN >= fmin($V1,$V2)${RB} && ${LB}$TOKEN <= fmax($V1,$V2)${RB} ? 1 : 0)"
                fi
            fi
            TOKEN=$(echo ${TOKEN//${g_PARSEVAR}/ })
            LB=
            RB=
            break
        fi
        CHAR="${DATA:0:7}"
        if [[ ${#DATA} -gt 7 && $CHAR = "BEYOND${g_PARSEVAR}" ]]
        then
            TERM="${DATA##*BEYOND}"
            V1=$(Mini_Parser "${TERM}" "AND")
            TERM="${TERM:${#V1}}"
            if [[ ${TERM} = +(AND*) ]]
            then
                V2="${TERM:3}"
            else
                V2="${TERM:1}"
            fi
            if [[ $CHECK -eq 1 ]]
            then
                if [[ $V2 = +(*${g_PARSEVAR}EXCL) ]]
                then
                    TOKEN="(__b2c__STRCMP(${LB}$TOKEN, __b2c__min_str($V1,${V2%EXCL*}))${RB} > 0 && __b2c__STRCMP(${LB}$TOKEN, __b2c__max_str($V1,${V2%EXCL*}))${RB} < 0 ? 0 : 1)"
                else
                    TOKEN="(__b2c__STRCMP(${LB}$TOKEN, __b2c__min_str($V1,$V2))${RB} >= 0 && __b2c__STRCMP(${LB}$TOKEN, __b2c__max_str($V1,$V2))${RB} <= 0 ? 0 : 1)"
                fi
                CHECK=0
            else
                if [[ $V2 = +(*${g_PARSEVAR}EXCL) ]]
                then
                    TOKEN="(${LB}$TOKEN > fmin($V1,${V2%EXCL*})${RB} && ${LB}$TOKEN < fmax($V1,${V2%EXCL*})${RB} ? 0 : 1)"
                else
                    TOKEN="(${LB}$TOKEN >= fmin($V1,$V2)${RB} && ${LB}$TOKEN <= fmax($V1,$V2)${RB} ? 0 : 1)"
                fi
            fi
            TOKEN=$(echo ${TOKEN//${g_PARSEVAR}/ })
            LB=
            RB=
            break
        fi
        CHAR="${DATA:0:2}"
	case $CHAR in
            "==")
                if [[ $IS_STRING -eq 0 ]]
                then
	            DATA="= ${DATA:2}"
                fi;;
            "<>")
                if [[ $IS_STRING -eq 0 ]]
                then
	            DATA="!=${DATA:2}"
                fi;;
        esac
	CHAR="${DATA:0:1}"
	case $CHAR in
	    =)
		if [[ $IS_STRING -eq 0 ]]
		then
                    if [[ $CHECK -eq 1 || $(Get_Var "${TOKEN}" ${g_FUNCNAME}) = +(*char\**) ]]
                    then
			if [[ -n $EQ ]]
			then
			    EQ="${EQ}="
			else
			    TERM="${TOKEN}"
			    TOKEN=
			    CHECK=1
			    EQ="=="
			fi
                    elif [[ $IS_EQUATION -eq 0 ]]
                    then
		        TOKEN="${TOKEN}=="
                    else
		        TOKEN="${TOKEN}="
                        IS_EQUATION=0
                    fi
		    IS_ESCAPED=0
                else
		    TOKEN="${TOKEN}="
		fi;;
	    !)
		if [[ $IS_STRING -eq 0 ]]
		then
                    if [[ $CHECK -eq 1 || $(Get_Var "${TOKEN}" ${g_FUNCNAME}) = +(*char\**) ]]
                    then
                        TERM="${TOKEN}"
                        TOKEN=
                        CHECK=1
                        EQ="!"
                    elif [[ $IS_EQUATION -eq 0 ]]
                    then
                        TOKEN="${TOKEN}!="
		        IS_ESCAPED=0
                        let LEN=${#DATA}-1
                        DATA="${DATA: -$LEN}"
                    else
                        TOKEN="${TOKEN}!"
                        IS_EQUATION=0
                    fi
                else
                    TOKEN="${TOKEN}!"
		fi;;
            \<)
		if [[ $IS_STRING -eq 0 ]]
		then
                    if [[ $CHECK -eq 1 || $(Get_Var "${TOKEN}" ${g_FUNCNAME}) = +(*char\**) ]]
                    then
                        TERM="${TOKEN}"
                        TOKEN=
                        CHECK=1
			EQ="<"
		    else
			if [[ $IS_EQUATION -eq 1 ]]
			then
			    IS_EQUATION=0
			else
			    IS_EQUATION=1
			fi
			TOKEN="${TOKEN}<"
		    fi
		else
		    TOKEN="${TOKEN}<"
		fi;;
            \>)
		if [[ $IS_STRING -eq 0 && $IS_POINTER -eq 0 ]]
		then
                    if [[ $CHECK -eq 1 || $(Get_Var "${TOKEN}" ${g_FUNCNAME}) = +(*char\**) ]]
                    then
                        TERM="${TOKEN}"
                        TOKEN=
                        CHECK=1
			EQ=">"
		    else
			if [[ $IS_EQUATION -eq 1 ]]
			then
			    IS_EQUATION=0
			else
			    IS_EQUATION=1
			fi
			TOKEN="${TOKEN}>"
		    fi
		else
                    TOKEN="${TOKEN}>"
		    IS_POINTER=0
		fi;;
	    \\)
		if [[ $IS_ESCAPED -eq 0 ]]
		then
		    IS_ESCAPED=1
		else
		    IS_ESCAPED=0
		fi
                TOKEN="${TOKEN}\\";;
            -)
		if [[ $IS_STRING -eq 0 && $IS_POINTER -eq 0 ]]
                then
		    IS_POINTER=1
                fi
		TOKEN="${TOKEN}-";;
	    \")
		if [[ $IS_ESCAPED -eq 0 ]]
		then
		    if [[ $IS_STRING -eq 0 ]]
		    then
			IS_STRING=1
		    else
			IS_STRING=0
		    fi
		fi
		IS_ESCAPED=0
                TOKEN="${TOKEN}\"";;
	    *)
		# Handle normal char after '<' or '>' symbol
		if [[ $IS_EQUATION -eq 1 ]]
		then
		    IS_EQUATION=0
		    LAST=$(echo "${TOKEN: -1}")
		    TOKEN="(${TOKEN%?})${LAST}"
		fi
		    
                # Convert back to space
	        if [[ "${CHAR}" = "${g_PARSEVAR}" ]]
	        then
	            TOKEN="${TOKEN} "
                else
	            TOKEN="${TOKEN}${CHAR}"
	        fi
		IS_POINTER=0
		IS_ESCAPED=0;;
	esac
	let LEN=${#DATA}-1
	DATA="${DATA: -$LEN}"
    done

    if [[ $CHECK -eq 1 ]]
    then
        g_EQUATION="${g_EQUATION} ${LB}__b2c__STRCMP(${TERM}, $TOKEN)${RB} $EQ 0"
    else
        g_EQUATION="${g_EQUATION} ${LB}${TOKEN}${RB}"
    fi

    g_EQUATION="${g_EQUATION} ${2}"
}

#-----------------------------------------------------------

function Parse_Equation
{
    typeset CHAR IS_ESCAPED IS_STRING TOKEN DATA LEN FLAG
    typeset AND OR BETWEEN

    g_EQUATION=
    IS_ESCAPED=0
    IS_STRING=0
    FLAG=0
    TOKEN=

    AND="${g_PARSEVAR}AND${g_PARSEVAR}"
    OR="${g_PARSEVAR}OR${g_PARSEVAR}"
    BETWEEN="${g_PARSEVAR}BETWEEN${g_PARSEVAR}"
    BEYOND="${g_PARSEVAR}BEYOND${g_PARSEVAR}"

    # Initialize miniparser, convert spaces
    DATA=$(echo ${1// /${g_PARSEVAR}})
    LEN=${#DATA}

    until [[ $LEN -eq 0 ]]
    do
        CHAR="${DATA:0:9}"
	if [[ "${CHAR}" = "${BETWEEN}" ]]
        then
	    if [[ $IS_STRING -eq 0 ]]
	    then
                FLAG=1
            fi
        fi
        CHAR="${DATA:0:8}"
	if [[ "${CHAR}" = "${BEYOND}" ]]
        then
	    if [[ $IS_STRING -eq 0 ]]
	    then
                FLAG=1
            fi
        fi
        CHAR="${DATA:0:5}"
	if [[ "${CHAR}" = "${AND}" ]]
        then
            if [[ ${FLAG} -eq 0 ]]
            then
	        if [[ $IS_STRING -eq 0 ]]
	        then
		    Parse_Chunk "${TOKEN}" " AND "
                    let LEN=${#DATA}-4
	            DATA="${DATA: -$LEN}"
		    CHAR=
		    TOKEN=
                fi
            else
                FLAG=0
            fi
        fi
        CHAR="${DATA:0:4}"
	if [[ "${CHAR}" = "${OR}" ]]
        then
	    if [[ $IS_STRING -eq 0 ]]
	    then
		Parse_Chunk "${TOKEN}" " OR "
                let LEN=${#DATA}-3
	        DATA="${DATA: -$LEN}"
		CHAR=
		TOKEN=
            fi
        fi
	CHAR="${DATA:0:1}"
	case $CHAR in
	    \\)
		if [[ $IS_ESCAPED -eq 0 ]]
		then
		    IS_ESCAPED=1
		else
		    IS_ESCAPED=0
		fi;;
	    \")
		if [[ $IS_ESCAPED -eq 0 ]]
		then
		    if [[ $IS_STRING -eq 0 ]]
		    then
			IS_STRING=1
		    else
			IS_STRING=0
		    fi
		fi
		IS_ESCAPED=0;;
	    *)
		IS_ESCAPED=0;;
	esac
	# Convert back to space
	if [[ "${CHAR}" = "${g_PARSEVAR}" ]]
	then
	    TOKEN="${TOKEN} "
        else
	    TOKEN="${TOKEN}${CHAR}"
	fi
	let LEN=${#DATA}-1
	DATA="${DATA: -$LEN}"
    done
    Parse_Chunk "${TOKEN}"
}

#-----------------------------------------------------------
#
# Main program
#
#-----------------------------------------------------------

# Default BACON settings
let g_MAX_DIGITS=32

# This is the size for static buffers like getline, read etc.
let g_BUFFER_SIZE=512

# Maximum RETURN buffers
let g_MAX_RBUFFERS=64

# Defaults for parameters
g_CCNAME=
g_TEMPDIR=
g_INCFILES=
g_CCFLAGS=
g_BINEXT=

g_CCNAME_TMP=
g_TEMPDIR_TMP=
g_INCFILES_TMP=
g_LDFLAGS_TMP=
g_CCFLAGS_TMP=

let g_NO_COMPILE=0
let g_TMP_PRESERVE=0
let g_QUIET=0
let g_EXEC=0
let g_SEMANTIC=0
let g_NO_QUESTION=0
let g_CPP=0
let g_XGETTEXT=0
let g_SAVE_CONFIG=0
let g_DEBUG=0

let g_USE_C=0
let g_USE_H=0
let g_MAX_BACKLOG=5

g_INCLUDE_FILES=
g_PRAGMA_INCLUDE=
g_PRAGMA_REGEX=
let g_TRACE=0
let g_OPTION_BASE=0
let g_OPTION_SOCKET=5
g_OPTION_TLS=
let g_OPTION_EVAL=0
g_INC_TLS=
g_LIB_TLS=
let g_OPTION_BREAK=1
let g_OPTION_DISABLE_C_ESCAPE=0

# Some global declarations
g_CURFILE=
g_FUNCNAME=
g_SOURCEFILE=
g_FUNCTYPE=
g_PROTOTYPE=
g_TMP_FILES=
g_LOCALSTRINGS=
g_STRINGARRAYS=
g_GLOBALARRAYS=
g_STRINGARGS=
g_DYNAMICARRAYS=
g_STATICARRAYS=
g_RECORDCACHE=
let g_LOOPCTR=0
g_ERRORTXT=
g_EQUATION=
let g_COMMENT=0
g_TRACE_PREFIX=
g_IGNORE_PARSE="1"
g_PRIORITY="\"NORMAL:-VERS-TLS1.3:%COMPAT\""
g_OPTION_EXPLICIT="0"
g_OPTION_INPUT="\"\n\""
g_VARTYPE="long"
g_OBJ_FILES=
g_MAKE_LINE=
g_MONITOR=
let g_STRING_FUNC=1
g_DOTIMES=0
g_LOCAL_SBUFFER=
g_TWEAK=

# Always create a final label
g_CATCHGOTO="__B2C__PROGRAM__EXIT"
g_CATCH_USED=0

# Records
g_RECORDNAME=
g_RECORDVAR=
g_RECORDARRAY=
g_WITHVAR=
g_RECORDEND_BODY=
g_RECORDEND_HEADER=

# Socket defaults
g_SOCKTYPE="SOCK_STREAM"
g_NETWORKTYPE="TCP"
g_MULTICAST_TTL=1
g_SCTP_STREAMS=1

# Select/Case
typeset -a g_SELECTVAR
typeset -a g_IN_CASE
g_SELECTVAR_CTR=0

# Relate
typeset -a g_RELATE
g_RELATE_CTR=0

g_FCTR=0
g_CCTR=0
NOLEX=0
RETURN_CODE=0

# Timer related
ttime=0

# Read any configfile values
if [[ ! -d $HOME/.bacon ]]
then
    mkdir $HOME/.bacon
fi

if [[ -f $HOME/.bacon/bacon.cfg ]]
then
    while read -r LINE
    do
	case ${LINE%% *} in
	    ccname) g_CCNAME_TMP=${LINE#ccname}; g_CCNAME_TMP=${g_CCNAME_TMP##*( )};;
	    tempdir) g_TEMPDIR_TMP=${LINE#tempdir}; g_TEMPDIR_TMP=${g_TEMPDIR_TMP##*( )};;
	    incfiles) g_INCFILES_TMP=${LINE#incfiles};;
	    ldflags) g_LDFLAGS_TMP=${LINE#ldflags};;
	    ccflags) g_CCFLAGS_TMP=${LINE#ccflags};;
	    lowercase) g_LOWERCASE_TMP=${LINE#lowercase};;
	    intense) Color_Intense=${LINE#intense};;
	    linenr) Line_Number_Active=${LINE#linenr};;
	esac
    done < $HOME/.bacon/bacon.cfg
fi

# Get arguments
while getopts ":c:d:i:l:o:t:xnjfpqrsvwyz@" OPT
do
    case $OPT in
	c) g_CCNAME=$OPTARG;;
	d) if [[ ! -d $OPTARG ]]
	   then
		mkdir -p $OPTARG
	   fi
	   g_TEMPDIR=$OPTARG;;
	i) if [[ ${OPTARG:0:1} = "/" || ${OPTARG:0:2} = "./" ]]
           then
               g_INCFILES="${g_INCFILES}#include \"${OPTARG}\""
           elif [[ ${OPTARG:0:1} = "<" ]]
           then
               g_INCFILES="${g_INCFILES}#include ${OPTARG}"
           else
	       g_INCFILES="${g_INCFILES}#include \"`pwd`/${OPTARG}\""
	   fi;;
	l) if [[ $OPTARG = +(* *) || $OPTARG = +(-*) ]]
           then
               g_LDFLAGS="$OPTARG $g_LDFLAGS"
           else
	       g_LDFLAGS="-l$OPTARG $g_LDFLAGS"
           fi;;
	o) g_CCFLAGS="$g_CCFLAGS $OPTARG";;
	n) g_NO_COMPILE=1;;
	j) g_CPP=1;;
	f) g_LDFLAGS="$g_LDFLAGS -shared -rdynamic"
	   g_CCFLAGS="$g_CCFLAGS -fPIC"
	   g_BINEXT=".so";; 
	p) g_TMP_PRESERVE=1;;
	q) g_QUIET=1;;
        r) g_EXEC=1;;
	s) g_SEMANTIC=1;;
        t) case ${OPTARG} in
                pbc*|PBC*)
                    g_TWEAK="${g_TWEAK}#define __b2c_Pool_Block_Count ${OPTARG#*=}\n";;
                pbs*|PBS*)
                    g_TWEAK="${g_TWEAK}#define __b2c_Pool_Block_Size ${OPTARG#*=}\n";;
                hld*|HLD*)
                    g_TWEAK="${g_TWEAK}#define __b2c_HASH_LINEAR_DEPTH ${OPTARG#*=}\n";;
                hss*|HSS*)
                    g_TWEAK="${g_TWEAK}#define __b2c_HASH_STR_STORE ${OPTARG#*=}\n";;
                mrb*|MRB*)
                    g_MAX_RBUFFERS=${OPTARG#*=};;
           esac;;
	x) g_XGETTEXT=1;;
	y) g_NO_QUESTION=1;;
	v) echo
	   echo "BaCon version $g_VERSION on $(uname -s -m) - Shell - (c) Peter van Eerten - MIT License."
	   echo
	   exit 0;; 
	w) g_SAVE_CONFIG=1;;
	z) g_LOWERCASE=1;;
	@) g_DEBUG=1;;
	\?|h) echo 
	    echo "USAGE: bacon [options] program[.bac]"
	    echo 
	    echo "OPTIONS:"
	    echo 
	    echo -e " -c <compiler>\tCompiler to use (default: cc)"
	    echo -e " -l <ldflags>\tPass libraries to linker"
	    echo -e " -o <options>\tPass compiler options"
	    echo -e " -i <include>\tAdd include file to C code"
	    echo -e " -d <tmpdir>\tTemporary directory (default: .)"
	    echo -e " -t <param=val>\tTweak internal parameter"
	    echo -e " -y \t\tAutomatically delete temporary files"
	    echo -e " -x \t\tExtract gettext strings"
	    echo -e " -z \t\tAllow lowercase keywords"
	    echo -e " -f \t\tCreate Shared Object"
	    echo -e " -n \t\tDo not compile, only convert"
	    echo -e " -j \t\tInvoke C Preprocessor"
	    echo -e " -p \t\tPreserve temporary files"
	    echo -e " -q \t\tShow summary after conversion only"
	    echo -e " -r \t\tCompile and execute in one step"
	    echo -e " -s \t\tSuppress semantic error warnings"
	    echo -e " -w \t\tSave options to BaCon configfile"
	    echo -e " -@ \t\tAdd debug information"
	    echo -e " -v \t\tShow version"
	    echo -e " -h \t\tShow help"
	    echo 
	    exit 0;;
    esac
done

shift $(($OPTIND-1))

# See if configfile must be written
if [[ $g_SAVE_CONFIG -eq 1 ]]
then
    echo -e "ccname $g_CCNAME" > $HOME/.bacon/bacon.cfg
    echo -e "tempdir $g_TEMPDIR" >> $HOME/.bacon/bacon.cfg
    echo -e "incfiles ${g_INCFILES//#include/@}" >> $HOME/.bacon/bacon.cfg
    echo -e "ldflags ${g_LDFLAGS}" >> $HOME/.bacon/bacon.cfg
    echo -e "ccflags ${g_CCFLAGS}" >> $HOME/.bacon/bacon.cfg
    echo -e "lowercase ${g_LOWERCASE}" >> $HOME/.bacon/bacon.cfg
    echo -e "intense ${Color_Intense}" >> $HOME/.bacon/bacon.cfg
    echo -e "linenr ${Line_Number_Active}" >> $HOME/.bacon/bacon.cfg
    g_CCNAME_TMP=$g_CCNAME
    g_TEMPDIR_TMP=$g_TEMPDIR
    g_INCFILES_TMP=${g_INCFILES//#include/@}
    g_LDFLAGS_TMP=$g_LDFLAGS
    g_CCFLAGS_TMP=$g_CCFLAGS
    g_LOWERCASE_TMP=$g_LOWERCASE
fi

# Use the commandline or configfile settings?
if [[ -z $g_CCNAME ]]
then
    g_CCNAME="${g_CCNAME_TMP}"
    if [[ -z $g_CCNAME ]]
    then
        g_CCNAME=cc
    fi
fi
if [[ -z $g_TEMPDIR ]]
then
    g_TEMPDIR="${g_TEMPDIR_TMP}"
    if [[ -z $g_TEMPDIR ]]
    then
        g_TEMPDIR="."
    fi
fi
if [[ -z $g_INCFILES ]]
then
    g_INCFILES="${g_INCFILES_TMP//@/#include}"
fi
g_LDFLAGS="${g_LDFLAGS} ${g_LDFLAGS_TMP}"
if [[ -z $g_CCFLAGS ]]
then
    g_CCFLAGS="${g_CCFLAGS_TMP}"
fi
if [[ -z $g_LOWERCASE || $g_LOWERCASE -eq 0 ]]
then
    g_LOWERCASE="${g_LOWERCASE_TMP}"
fi

# Check if a filename was entered, if so get it
if [[ $# -eq 0 ]]
then
    if [[ $g_SAVE_CONFIG -eq 0 ]]
    then
        echo -e "System error: no filename? Run with '-h' to see usage."
        exit 1
    fi
elif [[ "$@" = +(http://*) ]]
then
    if [[ -z `command -v telnet 2>/dev/null` ]]
    then
	echo "System error: No telnet client found! Cannot retrieve file."
	exit 1
    fi
    echo -n "Fetching file... "

    # Remove http part
    g_SOURCEFILE="${@#*http://}"

    # Get header to see if file exists, and if so, get length
    HEAD=`(echo "set crlf on"; echo "open ${g_SOURCEFILE%%/*} 80"; sleep 1;
    echo "HEAD /${g_SOURCEFILE#*/} HTTP/1.1"; echo "Host: ${g_SOURCEFILE%%/*}"; echo;
    sleep 1; echo "quit";) | telnet 2>/dev/null`

    LEN=`echo ${HEAD#*Content-Length: }`

    # No file found on server
    if [[ "${LEN%% *}" = "telnet>" || "${HEAD}" != +(*Content-Length*) ]]
    then
        echo "System error: file not found! Check URL and try again."
        exit 1
    fi

    # Get the actual contents of the file
    DOWNLOAD=`(echo "set crlf on"; echo "open ${g_SOURCEFILE%%/*} 80"; sleep 2;
    echo "GET /${g_SOURCEFILE#*/} HTTP/1.1"; echo "Host: ${g_SOURCEFILE%%/*}"; echo;
    sleep 2; echo "quit";) | telnet 2>/dev/null`

    # Set the final filename and save
    g_SOURCEFILE="${1##*/}"
    let START=${#DOWNLOAD}-${LEN%% *}
    echo "${DOWNLOAD:${START}:${#DOWNLOAD}}" > $g_SOURCEFILE

    # Check resulting filesize with HTTP header
    FILELEN=`wc -c $g_SOURCEFILE`
    let FILELEN=${FILELEN%% *}-1
    if [[ ${FILELEN} -ne ${LEN%% *} ]]
    then
        echo "System error: file could not be downloaded probably due to a timeout. Try again later."
        exit 1
    fi
    echo "done."
elif [[ "$@" != +(*.bac) ]]
then
    g_SOURCEFILE="$@.bac"
else
    g_SOURCEFILE="$@"
fi

# Check if file exists
if [[ ! -f $g_SOURCEFILE ]]
then
    echo -e "System error: file '$g_SOURCEFILE' not found!"
    exit 1
fi

# Change the working directory
if [[ -d ${g_SOURCEFILE%/*} && ${g_SOURCEFILE} = +(/*) ]]
then
    cd ${g_SOURCEFILE%/*}
fi

# Now create the global filenames where to write to
g_CFILE=$g_TEMPDIR/${g_SOURCEFILE##*/}.c
g_HFILE=$g_TEMPDIR/${g_SOURCEFILE##*/}.h
g_GENERIC=$g_TEMPDIR/${g_SOURCEFILE##*/}.generic.h
g_FUNCTIONS=$g_TEMPDIR/${g_SOURCEFILE##*/}.functions.h
STRINGARRAYFILE=$g_TEMPDIR/${g_SOURCEFILE##*/}.string.h
FLOATARRAYFILE=$g_TEMPDIR/${g_SOURCEFILE##*/}.float.h
SRCARRAYFILE=$g_TEMPDIR/${g_SOURCEFILE##*/}.src.h
g_BACONTOKEN=$g_TEMPDIR/${g_SOURCEFILE##*/}.token.lex
g_BACONLEXER=$g_TEMPDIR/${g_SOURCEFILE##*/}.lex

# Add to total file list
g_TMP_FILES="$g_CFILE $g_HFILE $STRINGARRAYFILE $FLOATARRAYFILE"

# Check if previous temporary files exist
LEN=`ls $g_TEMPDIR/${g_SOURCEFILE%.bac}.*.* 2>/dev/null | wc -l`
if [[ ${g_NO_QUESTION} -eq 1 ]]
then
    rm -f $g_TEMPDIR/${g_SOURCEFILE%.bac}.*.*
else
    if [[ ${LEN} -gt 0 ]]
    then
        if [[ ${BACON_IN_DOCKER} = "true" ]]
        then
            ANSWER="y"
        else
            echo "WARNING: ${LEN} temporary files found!"
        fi
        ls $g_TEMPDIR/${g_SOURCEFILE%.bac}.*.* | sort
        if [[ -n $BASH ]]
        then
            read -p "Do you want to delete them ([y]/n)? " ANSWER
        else
            read ANSWER?"Do you want to delete them ([y]/n)? "
        fi
        if [[ -z ${ANSWER} || ${ANSWER} = "y" ]]
        then
            rm -f $g_TEMPDIR/${g_SOURCEFILE%.bac}.*.*
            echo "Temporary files were deleted."
        else
            echo "Exiting..."
            exit 1
        fi
    fi
fi

# Keep start time
ttime=$SECONDS

# Create C file
echo "/* Created with Shell BaCon $g_VERSION - (c) Peter van Eerten - MIT License */" > $g_CFILE
echo "#include \"${g_SOURCEFILE##*/}.h\"" >> $g_CFILE
echo "#include \"${g_SOURCEFILE##*/}.string.h\"" >> $g_CFILE
echo "#include \"${g_SOURCEFILE##*/}.float.h\"" >> $g_CFILE

# Create H file
echo "/* Created with Shell BaCon $g_VERSION - (c) Peter van Eerten - MIT License */" > $g_HFILE
echo "#include \"${g_SOURCEFILE##*/}.generic.h\"" >> $g_HFILE
echo "#include \"${g_SOURCEFILE##*/}.functions.h\"" >> $g_HFILE

echo "char *__b2c__stringarray[] = {" >> $STRINGARRAYFILE

echo "double __b2c__floatarray[] = {" >> $FLOATARRAYFILE

if [[ ${g_LDFLAGS} = +(*shared*) ]]
then
    echo "/************************************/" >> $g_CFILE
    echo "/* Init function for shared objects */" >> $g_CFILE
    echo "/************************************/" >> $g_CFILE
    echo "#ifdef __GNUC__" >> $g_CFILE
    echo "static int BaCon_init() __attribute__((constructor));" >> $g_CFILE
    echo "#endif" >> $g_CFILE
    echo "int BaCon_init(void){int argc=0; char *argv[2] = { NULL };" >> $g_CFILE
else
    echo "/****************************/" >> $g_CFILE
    echo "/* Main program starts here */" >> $g_CFILE
    echo "/****************************/" >> $g_CFILE
    echo "int main(int argc, char **argv){" >> $g_CFILE
fi

# Set buffering to line oriented etc.
echo "setvbuf(stdout, NULL, _IOLBF, 0);" >> $g_CFILE
echo "atexit(__b2c_str_free);" >> $g_CFILE
echo "__b2c__set_stack_size();" >> $g_CFILE

# Check version
echo "if(argc>0) { __b2c__me_var${g_STRINGSIGN} = __b2c_Copy_String(__b2c__me_var${g_STRINGSIGN}, argv[0]); }" >> $g_CFILE

# See if we have the detector
echo "if(argc==2 && !strncmp(argv[1], \"-bacon\", 6)) { fprintf(stderr, \"Converted by %s.\n\", COMPILED_BY_WHICH_BACON${g_STRINGSIGN}); exit(EXIT_SUCCESS); }" >> $g_CFILE

# Put arguments into reserved variable ARGUMENT
echo "/* Setup the reserved variable 'ARGUMENT' */" >> $g_CFILE
echo "__b2c__argument(&ARGUMENT${g_STRINGSIGN}, argc, argv);" >> $g_CFILE
echo "/* By default seed random generator */" >> $g_CFILE
echo "srandom((unsigned int)time(NULL));" >> $g_CFILE
echo "/* Determine current moment and keep it for timer function */" >> $g_CFILE
echo "__b2c__nanotimer(1); __b2c__timer(1);" >> $g_CFILE
echo "/* Setup error signal handling */" >> $g_CFILE
echo "signal(SIGILL, __b2c__catch_signal);" >> $g_CFILE
echo "signal(SIGABRT, __b2c__catch_signal);" >> $g_CFILE
echo "signal(SIGFPE, __b2c__catch_signal);" >> $g_CFILE
echo "signal(SIGSEGV, __b2c__catch_signal);" >> $g_CFILE
echo "/* Rest of the program */" >> $g_CFILE

# There are no imported symbols yet
g_IMPORTED=

# List all BaCon functions
DATA_1="ABS ACCEPT ACOS ADD ADDRESS ALARM ALIAS ALIGN$ AMOUNT AND APPEND APPEND$ APPENDING ARGUMENT$ ARRAY AS ASC ASIN ASSOC ATN ATN2 B64DEC$ B64ENC$ BACK BAPPEND BASE BASENAME$ BETWEEN BEYOND BG BIT BLACK BLINK BLOAD BLUE BOLD BREAK BROADCAST"
DATA_2="BSAVE BY BYTELEN CA$ CALL CASE CATCH CEIL CERTIFICATE CHANGE$ CHANGEDIR CHOP$ CHR$ CHUNK CIPHER$ CL$ CLASS CLEAR CLOSE CMDLINE CMODE CN$ COIL$ COLLAPSE COLLAPSE$ COLLECT COLOR COLUMNS COMPARE COMPILER CONCAT$ CONST CONTINUE"
DATA_3="COPY COS COUNT CR$ CURDIR$ CURRENT CURSOR CUT$ CYAN DATA DAY DEC DECLARE DECR DEF DEFAULT DEG DEL$ DELETE DELIM DELIM$ DEVICE DIRECTORY DIRNAME$ DLE$ DO DONE DOTIMES DOWN DOWNTO DQ EDITBOM$ EL$ ELIF ELSE END ENDCLASS ENDENUM ENDFILE ENDFORK"
DATA_4="ENDFUNC ENDFUNCTION ENDIF ENDRECORD ENDSELECT ENDSUB ENDUSEC ENDUSEH ENDWITH ENUM EPRINT EQ EQUAL ERR$ ERROR ESC ESCAPE$ EVAL EVEN EXCHANGE$ EXCL EXEC$ EXIT EXP EXPLICIT EXPLODE$ EXTRACT$ FALSE FG FI FILE FILEEXISTS FILELEN FILETIME"
DATA_5="FILETYPE FILL$ FIND FIRST$ FLATTEN$ FLOATING FLOOR FN FOR FORK FORMAT FORWARD FP FRAMEWORK FREE FROM FTYPE FUNC FUNCTION GE GETBYTE GETENVIRON$ GETFILE GETKEY GETLINE GETPEER$ GETX GETY GLOBAL GOSUB GOTO GOTOXY GREEN GT HASBOM HASDELIM HASH"
DATA_6="HEAD$ HEX$ HOST$ HOSTNAME$ HOUR IF IIF IIF$ IMODE IMPORT IN INBETWEEN$ INCLUDE INCR INDEX INDEX$ INPUT INSERT$ INSTR INSTRREV INT INTENSE INTERNATIONAL INTL$ INVERSE INVERT IS ISASCII ISFALSE ISKEY ISNOT ISTOKEN ISTRUE ISUTF8 ITALIC JOIN LABEL LAST$"
DATA_7="LCASE$ LDFLAGS LE LEFT$ LEN LET LIBRARY LINENO LMODE LOAD$ LOCAL LOG LOOKUP LOOP LOOP$ LT MAGENTA MAKEDIR MAP MATCH MAX MAX$ MAXNUM MAXRANDOM ME$ MEMCHECK MEMORY MEMREWIND MEMSTREAM MEMTELL MEMTYPE MERGE$ MID$ MIN MIN$ MINUTE"
DATA_8="MOD MONITOR MONTH MONTH$ MULTICAST MYPID NANOTIMER NE NETWORK NEXT NL$ NNTL$ NO_C_ESC NODE NORMAL NOT NOW NRKEYS NULL NUMBER OBTAIN$ ODD OFF OFFSET OMODE ON OPEN OPTION OPTIONS OR OS$ OTHER OUTBETWEEN$ PARSE PEEK PI POKE POW PRAGMA PRINT PRIORITY"
DATA_9="PROPER PROPER$ PROTO PULL PUSH PUTBYTE PUTLINE QUOTED RAD RANDOM RE READ READING READLN READWRITE REALPATH$ REAP RECEIVE RECORD RECURSIVE RED REDIM REGEX REGLEN RELATE REM RENAME REPEAT REPLACE$ RESET RESIZE RESTORE RESUME RETURN"
DATA_10="RETVAL REV$ REVERSE$ REWIND RIGHT$ RIP$ RND ROL ROR ROTATE$ ROUND ROWS RUN RUN$ SAVE SCREEN SCROLL SCTP SEARCH SECOND SEED SEEK SELECT SEND SERVER SET SETENVIRON SETSERIAL SGN SIGNAL SIN SIZE SIZEOF SLEEP SOCKET SORT SORT$ SOURCE$"
DATA_11="SP SPC$ SPEED SPLIT SQR START STARTPOINT STATIC STEP STOP STR$ STRIKE STRING SUB SUM SUMF SWAP SYSTEM TAB$ TAIL$ TALLY TAN TCP TELL TEXTDOMAIN THEN TIMER TIMEVALUE TLS TO TOTAL TOASCII$ TOKEN$ TRACE TRAP TREE TRUE TYPE TYPEOF$ UBOUND UCASE$"
DATA_12="UCS UDP ULEN UNDERLINE UNESCAPE$ UNFLATTEN$ UNIQ$ UNSET UNTIL UP USEC USEH UTF8 UTF8$ VAL VAR VARTYPE VERIFY VERSION$ WAIT WALK$ WEEK WEEKDAY$ WEND WHENCE WHERE WHILE WHITE WITH WRITELN WRITING YEAR YELLOW"

# Allow lowercase statements and functions, exceptions are CONST, STATIC, INT because they're also C types - see Pre_Tokenize
if [[ $g_LOWERCASE -eq 1 ]]
then
    echo -n "Creating lowercase definitions... "
    for i in ${DATA_1} ${DATA_2} ${DATA_3} ${DATA_4} ${DATA_5} ${DATA_6} ${DATA_7} ${DATA_8} ${DATA_9} ${DATA_10} ${DATA_11} ${DATA_12}
    do
        if [[ ${i} != "INT" && ${i} != "CONST" && ${i} != "STATIC" ]]
        then
            MAPPING="$MAPPING -D`echo ${i}|tr [:upper:] [:lower:]`=${i}"
        fi
    done
    echo "done."
    g_CPP=1
fi

# Prevent filename expansion
set -f

# Check if the C Preprocessor needs to run
if [[ $g_CPP -eq 1 ]]
then
    if [[ -n `command -v cpp 2>/dev/null` ]]
    then
        echo -n "Preprocessing '${g_SOURCEFILE}'... "
        # Change next line marker to overcome C preprocessor interpretation
        while read -r LINE; do if [[ ${LINE} = +(\#*) ]]; then echo "${LINE}"; else echo "@${LINE}@"; fi; done < $g_SOURCEFILE > $g_SOURCEFILE.tmp
        cpp -w -P $MAPPING $g_SOURCEFILE.tmp $g_SOURCEFILE.cpp
        # Restore next line marker
        while read -r LINE; do LINE="${LINE:1}"; echo "${LINE%@*}"; done < $g_SOURCEFILE.cpp > $g_SOURCEFILE.bac2
	g_TMP_FILES="$g_TMP_FILES ${g_SOURCEFILE}.cpp ${g_SOURCEFILE}.tmp ${g_SOURCEFILE}.bac2"
        g_FEED="${g_SOURCEFILE}.bac2"
        echo "done."
    else
	echo -e "System error: the C Preprocessor 'cpp' not found on this system! Exiting..."
	exit 1
    fi
else
    g_FEED=${g_SOURCEFILE}
fi
# Set current filename
g_CURFILE="${g_SOURCEFILE}"

# Initialize
LEN=
TOTAL=
SEQ=
g_COUNTER=0
g_TOTAL_LINES=0

# Register internal result variables for LOOP, LOOP$, COIL$ functions
Save_Main_Var "__b2c__loop_result${g_STRINGSIGN}" "char*"
Save_Main_Var "__b2c__loop_result" "long"

# ERROR and '_' variable can be reset manually by user, so register it
Save_Main_Var "ERROR" "int"
Save_Main_Var "_" "long"

# Detect if this is a Windows file
if [[ `head -1 ${g_FEED}` = +(*${g_CRLF}) ]]
then
    echo "System error: Windows file detected! Remove non-Unix CR line separators first. Exiting..."
    exit 1
fi

# Start walking through program
echo -e -n "\rConverting '${g_SOURCEFILE}'... "

while read -r LINE || [[ -n "$LINE" ]]
do
    ((g_COUNTER+=1))
    if [[ $g_QUIET -eq 0 ]]
    then
	echo -e -n "\rConverting '${g_SOURCEFILE}'... ${g_COUNTER}\033[0K"
    fi
    # Line is not empty?
    if [[ -n "$LINE" ]]
    then
	if [[ "$LINE" = +(* \\) && "$LINE" != +(${g_SQUOTESIGN}*) ]]
	then
	    let LEN="${#LINE}"-1
	    SEQ="${LINE:0:$LEN}"
	    TOTAL="${TOTAL}${SEQ}"
        else
	    TOTAL="${TOTAL}${LINE}"
	    if [[ "${TOTAL}" != +(${g_SQUOTESIGN}*) ]]
	    then
                if [[ ${g_DEBUG} -eq 1 ]]
                then
                    echo "/* line $g_COUNTER \"${g_SOURCEFILE##*/}\" */" >> $g_CFILE
                    echo "/* line $g_COUNTER \"${g_SOURCEFILE##*/}\" */" >> $g_HFILE
                else
                    echo "#line $g_COUNTER \"${g_SOURCEFILE##*/}\"" >> $g_CFILE
                    echo "#line $g_COUNTER \"${g_SOURCEFILE##*/}\"" >> $g_HFILE
                fi
		Tokenize "${TOTAL}"
	    fi
	    TOTAL=
	fi
    fi
done < ${g_FEED}

# Debug variables
if [[ ${g_DEBUG} -eq 1 ]]
then
    echo "__b2c_str_realloc_debug_string();" >> $g_CFILE
    echo "__b2c_mempool_realloc_debug();" >> $g_CFILE
fi

# Restore filename expansion
set +f

# Finalize main C-file
if [[ $g_CATCH_USED -eq 1 ]]
then
    echo "__B2C__PROGRAM__EXIT:" >> $g_CFILE
fi
echo "return(0);" >> $g_CFILE
echo "}" >> $g_CFILE

# Finalize STRING ARRAY file for DATA
echo " \"\" };" >> $STRINGARRAYFILE

# Finalize FLOAT ARRAY file for DATA
echo " 0.0};" >> $FLOATARRAYFILE

((g_TOTAL_LINES+=$g_COUNTER))
ttime=$(($SECONDS-$ttime))
echo -e "\rConverting '${g_SOURCEFILE}'... done, ${g_TOTAL_LINES} lines were processed in ${ttime} seconds."

# Debug variables
if [[ ${g_DEBUG} -eq 1 ]]
then
    Debug_Vars
fi

# Include local buffers
if [[ -n $g_LOCAL_SBUFFER ]]
then
    echo ${g_LOCAL_SBUFFER} >> $g_HFILE
fi

# Check if generated source file exists
if [[ -f $SRCARRAYFILE ]]
then
    echo "#include \"$SRCARRAYFILE\"" >> $g_HFILE
    g_TMP_FILES="${g_TMP_FILES} $SRCARRAYFILE"
fi

# Include functions and subs
for i in $g_INCLUDE_FILES
do
    echo "#include \"${i}\"" >> $g_HFILE
done
echo "void __b2c__set_stack_size(void) { struct rlimit rl; getrlimit (RLIMIT_STACK, &rl); rl.rlim_cur = RLIM_INFINITY; setrlimit (RLIMIT_STACK, &rl); }" >> $g_HFILE

# Create function to free globally declared arrays
if [[ -n ${g_GLOBALARRAYS} ]]
then
    echo "void __b2c__arrays_free(void) { ${g_GLOBALARRAYS} }" >> $g_HFILE
fi
echo "void __b2c__twalk_free(void) { if (__b2c__twalk_array) { free (__b2c__twalk_array); } }" >> $g_HFILE

# Create generic headerfile, functions are converted using macros
echo "/* Created with Shell BaCon $g_VERSION - (c) Peter van Eerten - MIT License */" > $g_GENERIC
echo -e "${g_PRAGMA_INCLUDE}" >> $g_GENERIC
# Add user include files
if [[ -n ${g_INCFILES} ]]
then
    echo -e "${g_INCFILES//#include/\\n#include}" >> $g_GENERIC
fi
echo "#include <stdio.h>" >> $g_GENERIC
echo "#include <stdlib.h>" >> $g_GENERIC
echo "#include <stdarg.h>" >> $g_GENERIC
echo "#include <stdint.h>" >> $g_GENERIC
echo "#include <libgen.h>" >> $g_GENERIC
echo "#include <limits.h>" >> $g_GENERIC
echo "#include <float.h>" >> $g_GENERIC
echo "#include <sys/resource.h>" >> $g_GENERIC
echo "#include <sys/time.h>" >> $g_GENERIC
echo "#include <sys/stat.h>" >> $g_GENERIC
echo "#include <sys/types.h>" >> $g_GENERIC
echo "#include <sys/wait.h>" >> $g_GENERIC
echo "#include <sys/socket.h>" >> $g_GENERIC
echo "#include <sys/utsname.h>" >> $g_GENERIC
echo "#include <sys/ioctl.h>" >> $g_GENERIC
echo "#include <dirent.h>" >> $g_GENERIC
echo "#include <setjmp.h>" >> $g_GENERIC
echo "#include <netdb.h>" >> $g_GENERIC
if [[ `uname` = +(*BSD*) ]]
then
    echo "#include <netinet/in.h>" >> $g_GENERIC
    echo "#define strcat(x, y) __b2c_strlcat(x, y)" >> $g_GENERIC
    echo "#define strcpy(x, y) __b2c_strlcpy(x, y)" >> $g_GENERIC
fi
echo "#include <arpa/inet.h>" >> $g_GENERIC
echo "#include <signal.h>" >> $g_GENERIC
# REGEX header
if [[ -n $g_PRAGMA_REGEX ]]
then
    if [[ $g_PRAGMA_REGEX != +(* INCLUDE *) ]]
    then
        SUBSTR=${g_PRAGMA_REGEX%% *}
        if [[ $SUBSTR = +(*tre*) ]]
        then
            echo "#include <tre/regex.h>" >> $g_GENERIC
        elif [[ $SUBSTR = +(*pcre*) ]]
        then
            echo "#include <pcreposix.h>" >> $g_GENERIC
        elif [[ $SUBSTR = +(*onig*) ]]
        then
            echo "#include <onigposix.h>" >> $g_GENERIC
        fi
    else
        SUBSTR=${g_PRAGMA_REGEX##* INCLUDE }
        echo "#include ${SUBSTR%% *}" >> $g_GENERIC
    fi
else
    echo "#include <regex.h>" >> $g_GENERIC
fi
# TLS header
if [[ -n ${g_INC_TLS} ]]
then
    if [[ ${g_INC_TLS} = +(* INCLUDE *) ]]
    then
        for i in ${g_INC_TLS##* INCLUDE }
        do
            echo "#include ${i}" >> $g_GENERIC
        done
    else
        echo -e "${g_INC_TLS}" >> $g_GENERIC
    fi
fi
echo "#include <fcntl.h>" >> $g_GENERIC
echo "#include <math.h>" >> $g_GENERIC
echo "#include <unistd.h>" >> $g_GENERIC
echo "#include <string.h>" >> $g_GENERIC
echo "#include <ctype.h>" >> $g_GENERIC
echo "#include <wctype.h>" >> $g_GENERIC
echo "#include <locale.h>" >> $g_GENERIC
echo "#include <dlfcn.h>" >> $g_GENERIC
echo "#include <errno.h>" >> $g_GENERIC
echo "#include <termios.h>" >> $g_GENERIC
echo "#include <time.h>" >> $g_GENERIC
echo "#include <fts.h>" >> $g_GENERIC
echo "#define ENTRY ENTRY_libc" >> $g_GENERIC
echo "#include <search.h>" >> $g_GENERIC
echo "#undef ENTRY" >> $g_GENERIC
echo "/* Undefine all symbols which happen to be BaCon keywords */" >> $g_GENERIC
for i in ${DATA_1} ${DATA_2} ${DATA_3} ${DATA_4} ${DATA_5} ${DATA_6} ${DATA_7} ${DATA_8} ${DATA_9} ${DATA_10} ${DATA_11} ${DATA_12}
do
    if [[ ${i} != +(*\$) && ${i} != "NULL" ]]
    then
        echo "#undef ${i}" >> $g_GENERIC
    fi
done

echo "/* Declarations for internal variables */" >> $g_GENERIC
echo "jmp_buf __b2c__jump;" >> $g_GENERIC
echo "int __b2c__trap = 1;" >> $g_GENERIC
echo "int __b2c__catch_set_backup = 0, __b2c__catch_set = 0;" >> $g_GENERIC
echo "void (*__b2c__error_callback)(char*, char*, long) = NULL;" >> $g_GENERIC
echo "int __b2c__option_compare = 0;" >> $g_GENERIC
echo "int __b2c__option_quoted = 1;" >> $g_GENERIC
echo "int __b2c__option_dq = 34;" >> $g_GENERIC
echo "int __b2c__option_esc = 92;" >> $g_GENERIC
echo "int __b2c__option_utf8 = 0;" >> $g_GENERIC
echo "int __b2c__option_proper = 0;" >> $g_GENERIC
echo "int __b2c__option_error = 1;" >> $g_GENERIC
echo "int __b2c__option_tls = 0;" >> $g_GENERIC
echo "char *__b2c__option_delim = \" \";" >> $g_GENERIC
echo "int __b2c__option_memstream = 0;" >> $g_GENERIC
echo "int __b2c__option_startpoint = 0;" >> $g_GENERIC
echo "int __b2c__option_open = O_RDWR|O_NOCTTY|O_SYNC;" >> $g_GENERIC
echo "int __b2c__collapse = 0;" >> $g_GENERIC
echo "int __b2c__break_ctr = 0;" >> $g_GENERIC
echo "int __b2c__break_flag = 0;" >> $g_GENERIC
echo "char __b2c__chop_default[] = \"\r\n\t \";" >> $g_GENERIC
echo "int __b2c__stringarray_ptr = 0;" >> $g_GENERIC
echo "int __b2c__floatarray_ptr = 0;" >> $g_GENERIC
echo "long __b2c__ctr = 0;" >> $g_GENERIC
# Save the max amount of parallel string buffers
echo "#define __b2c_STRING_FUNC ($g_STRING_FUNC)" >> $g_GENERIC
echo "#define __b2c_EMPTYSTRING (char*)\"\"" >> $g_GENERIC
echo "jmp_buf __b2c__gosub_buffer[$g_MAX_RBUFFERS];" >> $g_GENERIC
echo "int __b2c__gosub_buffer_ptr = -1;" >> $g_GENERIC
echo "char* __b2c__loop_result${g_STRINGSIGN} = NULL;" >> $g_GENERIC
echo "long __b2c__loop_result = 0;" >> $g_GENERIC
echo "jmp_buf __b2c__data_jump, __b2c__loop1, __b2c__loop2;" >> $g_GENERIC
echo "char *__b2c__assign = NULL;" >> $g_GENERIC
echo "void **__b2c__assign2 = NULL;" >> $g_GENERIC
echo "int __b2c__counter;" >> $g_GENERIC
echo "char **__b2c__stack = NULL;" >> $g_GENERIC
echo "void **__b2c__twalk_array = NULL; int __b2c__twalk_idx = 0;" >> $g_GENERIC
echo "extern char *__b2c__stringarray[];" >> $g_GENERIC
echo "extern double __b2c__floatarray[];" >> $g_GENERIC
echo "char *__b2c__me_var${g_STRINGSIGN} = NULL;" >> $g_GENERIC
echo "/* Declarations for BaCon variables */" >> $g_GENERIC
echo "char *ARGUMENT${g_STRINGSIGN} = NULL;" >> $g_GENERIC
echo "int ERROR = 0;" >> $g_GENERIC
echo "int RETVAL = 0;" >> $g_GENERIC
echo "int REGLEN = 0;" >> $g_GENERIC
echo "int SP = 0;" >> $g_GENERIC
echo "long _ = 0;" >> $g_GENERIC
echo "char VERSION${g_STRINGSIGN}[] = \"$g_VERSION\";" >> $g_GENERIC
# Prototypes for functions
echo "/* Prototypes for internal functions */" >> $g_GENERIC
echo "int __b2c__strcmp(const char*, const char*);" >> $g_GENERIC
echo "char *__b2c__strdup(char*);" >> $g_GENERIC
echo "char *__b2c__strndup(char*, size_t);" >> $g_GENERIC
echo "void *__b2c_mempool_realloc_core(void*, size_t, int);" >> $g_GENERIC
echo "void *__b2c_str_realloc_core(char*, size_t, int);" >> $g_GENERIC
echo "long __b2c__delim_engine_core(int, int, long*, char*, char*, long, int);" >> $g_GENERIC
if [[ `uname` = +(*BSD*) ]]
then
    echo "char *__b2c_strlcat(char*, const char*);" >> $g_GENERIC
    echo "char *__b2c_strlcpy(char*, const char*);" >> $g_GENERIC
fi
echo "/* Prototypes for BaCon functions */" >> $g_GENERIC
echo "char *ERR${g_STRINGSIGN}(int);" >> $g_GENERIC
echo "int __b2c_utf8_conv(int,char*);" >> $g_GENERIC
echo "char *__b2c_Copy_String_core(char*, char*, int);" >> $g_GENERIC
echo "char* __b2c_Swap_String(char**, char**);" >> $g_GENERIC
echo "unsigned long __b2c__len(const char*);" >> $g_GENERIC
echo "unsigned long __b2c__ulen(int,char*,char*,char*,int);" >> $g_GENERIC
echo "unsigned long __b2c__blen(int,char*,char*,char*,long,int);" >> $g_GENERIC
echo "unsigned long __b2c__ucs2_clen(int,char*,char*,char*,int);" >> $g_GENERIC
echo "long __b2c__regex_core(int, int, char*, char*, char*);" >> $g_GENERIC
echo "char *__b2c__extract_core(int, int, char*, char*, char*, int);" >> $g_GENERIC
echo "char *__b2c__replace_core(int, int, char*, char*, char*, char*, int);" >> $g_GENERIC
echo "char *__b2c__walk_core(int, int, char*, char*, int, char*, int, char*);" >> $g_GENERIC
echo "void __b2c_str_free(void);" >> $g_GENERIC
echo "void __b2c__arrays_free(void);" >> $g_GENERIC
echo "void __b2c__twalk_free(void);" >> $g_GENERIC
echo "int __b2c__collect(void*, void***, int, int);" >> $g_GENERIC
echo "/* Internal macro definitions */" >> $g_GENERIC
echo "#define __b2c__MEMTYPE char" >> $g_GENERIC
echo "#define __b2c__STRCMP __b2c__strcmp" >> $g_GENERIC
echo "#define __b2c__BUFOFFSET 16" >> $g_GENERIC
echo "#define __b2c__LBUFSIZE(x) (*(uint32_t*)((uint8_t*)x-__b2c__BUFOFFSET+8))" >> $g_GENERIC
echo "#define __b2c__RBUFSIZE(x) (*(uint32_t*)((uint8_t*)x-__b2c__BUFOFFSET+4))" >> $g_GENERIC
echo "#define __b2c__STRFREE(x) if(__b2c_str_realloc_get_string(x)) { if(!__b2c_mempool_realloc_free((uint8_t*)x-__b2c__BUFOFFSET-__b2c__LBUFSIZE(x))) { free((uint8_t*)x-__b2c__BUFOFFSET-__b2c__LBUFSIZE(x)); } __b2c_str_realloc_del_string(x); } else { if(x) { free(x); } }" >> $g_GENERIC
echo "#define __b2c__SETLEN(x,y) *(uint32_t*)(x-__b2c__BUFOFFSET) = y;" >> $g_GENERIC
echo "#define __b2c__FUNCSELECT2(_1, _2, x, ...) x" >> $g_GENERIC
echo "#define __b2c__FUNCSELECT3(_1, _2, _3, x, ...) x" >> $g_GENERIC
echo "#define __b2c__FUNCSELECT4(_1, _2, _3, _4, x, ...) x" >> $g_GENERIC
echo "#define __b2c__FUNCSELECT5(_1, _2, _3, _4, _5, x, ...) x" >> $g_GENERIC
echo "#define __b2c_mempool_realloc_debug() __b2c_mempool_realloc_core(NULL, 0, 0)" >> $g_GENERIC
echo "#define __b2c_mempool_realloc_free(x) __b2c_mempool_realloc_core(x, 0, 1)" >> $g_GENERIC
echo "#define __b2c_mempool_realloc_in_block(x) __b2c_mempool_realloc_core(x, 0, 2)" >> $g_GENERIC
echo "#define __b2c_mempool_realloc(x, y) __b2c_mempool_realloc_core(x, y, 3)" >> $g_GENERIC
echo "#define __b2c_str_realloc(x, y) __b2c_str_realloc_core(x, y, 0)" >> $g_GENERIC
echo "#define __b2c_str_realloc_left(x, y) __b2c_str_realloc_core(x, y, 1)" >> $g_GENERIC
echo "#define __b2c_str_realloc_add_string(x) __b2c_str_realloc_core((char*)x, 0, 2)" >> $g_GENERIC
echo "#define __b2c_str_realloc_del_string(x) __b2c_str_realloc_core((char*)x, 0, 3)" >> $g_GENERIC
echo "#define __b2c_str_realloc_get_string(x) (x!=NULL && __b2c_str_realloc_core((char*)x, 0, 4))" >> $g_GENERIC
echo "#define __b2c_str_realloc_free_string() __b2c_str_realloc_core(NULL, 0, 6)" >> $g_GENERIC
echo "#define __b2c_str_realloc_debug_string() __b2c_str_realloc_core(NULL, 0, 5)" >> $g_GENERIC
echo "#define __b2c_Copy_String(x, y) __b2c_Copy_String_core(x, y, -1)" >> $g_GENERIC
echo "#define __b2c_Copy_N_String(x, y, z) __b2c_Copy_String_core(x, y, z)" >> $g_GENERIC
echo "#define __b2c__delim_engine(x, y, z, a, b) __b2c__delim_engine_core(1, x, y, z, a, b, 0)" >> $g_GENERIC
echo "#define __b2c__delim_engine_cache(x, y, z, a, b) __b2c__delim_engine_core(1, x, y, z, a, b, 1)" >> $g_GENERIC
echo "#define __b2c__delim_engine_free() __b2c__delim_engine_core(0, 0, NULL, NULL, NULL, 0, 0)" >> $g_GENERIC
echo "#define __b2c__regex(x, y, z, q) __b2c__regex_core(1, x, y, z, q)" >> $g_GENERIC
echo "#define __b2c__regex_free() __b2c__regex_core(0, 0, NULL, NULL, NULL)" >> $g_GENERIC
echo "#define __b2c__extract(x, y, z, q, r) __b2c__extract_core(1, x, y, z, q, r)" >> $g_GENERIC
echo "#define __b2c__extract_free() __b2c__extract_core(0, 0, NULL, NULL, NULL, 0)" >> $g_GENERIC
echo "#define __b2c__replace(x, y, z, q, r, s) __b2c__replace_core(1, x, y, z, q, r, s)" >> $g_GENERIC
echo "#define __b2c__replace_free() __b2c__replace_core(0, 0, NULL, NULL, NULL, NULL, 0)" >> $g_GENERIC
echo "#define __b2c__walk(x, y, z, a, b, c, d) __b2c__walk_core(1, x, y, z, a, b, c, d)" >> $g_GENERIC
echo "#define __b2c__walk_free() __b2c__walk_core(0, 0, NULL, NULL, 0, NULL, 0, NULL)" >> $g_GENERIC
echo "#if INTPTR_MAX == INT64_MAX" >> $g_GENERIC
echo "#define HASH_FUNC (uint64_t)__b2c__HashFNV1a_64" >> $g_GENERIC
echo "#elif INTPTR_MAX == INT32_MAX" >> $g_GENERIC
echo "#define HASH_FUNC (uint32_t)__b2c__HashFNV1a_32" >> $g_GENERIC
echo "#else" >> $g_GENERIC
echo "#define HASH_FUNC (uint16_t)__b2c__HashFNV1a_16_new" >> $g_GENERIC
echo "#endif" >> $g_GENERIC
if [[ -n $BASH ]]
then
    echo "#define COMPILED_BY_WHICH_BACON${g_STRINGSIGN} \"Shell Script BaCon $g_VERSION in BASH $BASH_VERSION\"" >> $g_GENERIC
elif [[ -n $ZSH_NAME ]]
then
    echo "#define COMPILED_BY_WHICH_BACON${g_STRINGSIGN} \"Shell Script BaCon $g_VERSION in ZSH $ZSH_VERSION\"" >> $g_GENERIC
else
    echo "#define COMPILED_BY_WHICH_BACON${g_STRINGSIGN} \"Shell Script BaCon $g_VERSION in KSH $KSH_VERSION\"" >> $g_GENERIC
fi
echo "#define RUNTIMEERROR(a, x, y, z) do { if(__b2c__option_error) { fprintf(stderr, \"Runtime error: statement '%s' at line %d in '%s': %s\n\", a, x, y, ERR${g_STRINGSIGN}(z)); exit(z); } if(__b2c__error_callback){(*__b2c__error_callback)(a,y,x);} } while(0)" >> $g_GENERIC
echo "#define RUNTIMEFERR(a, x, y, z) do { if(__b2c__option_error) { fprintf(stderr, \"Runtime error: function '%s' at line %d in '%s': %s\n\", a, z, y, ERR${g_STRINGSIGN}(x)); exit(x); } if(__b2c__error_callback){(*__b2c__error_callback)(a,y,z);} } while(0)" >> $g_GENERIC
echo "#define RUNTIMEDEBUG(x, y, z) (__b2c__getch() == 27 ? fprintf(stderr, \"TRACE OFF - exiting trace mode.\n\") && __b2c__stop_program() : fprintf(stderr, \"File '%s' line %d: %s\n\", #x, y, z)${g_MONITOR} )" >> $g_GENERIC
echo "int __b2c__stop_program(void) { exit(EXIT_SUCCESS); return(1); }" >> $g_GENERIC
echo "/* BaCon functions */" >> $g_GENERIC
echo "#define ABS(x) (((x) < 0) ? -(x) : (x))" >> $g_GENERIC
echo "#define ACOS(x) acos((double)x)" >> $g_GENERIC
echo "#define ADDRESS(x) (uintptr_t)(&x)" >> $g_GENERIC
echo "#define __b2c__ALIGN3(x, y, z) __b2c__align(__LINE__, __FILE__, x, y, z, 0)" >> $g_GENERIC
echo "#define __b2c__ALIGN4(x, y, z, f) __b2c__align(__LINE__, __FILE__, x, y, z, f)" >> $g_GENERIC
echo "#define ALIGN${g_STRINGSIGN}(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__ALIGN4, __b2c__ALIGN3)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__AMOUNT1(x) __b2c__amount(x, NULL)" >> $g_GENERIC
echo "#define __b2c__AMOUNT2(x, y) __b2c__amount(x, y)" >> $g_GENERIC
echo "#define AMOUNT(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__AMOUNT2, __b2c__AMOUNT1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define AND &&" >> $g_GENERIC
echo "#define __b2c__APPEND3(x, y, z) __b2c__append(NULL, 0, x, y, z, NULL)" >> $g_GENERIC
echo "#define __b2c__APPEND4(x, y, z, f) __b2c__append(NULL, 0, x, y, z, f)" >> $g_GENERIC
echo "#define APPEND${g_STRINGSIGN}(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__APPEND4, __b2c__APPEND3)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__FAPPEND4(s, x, y, z) __b2c__append(&s, 1, x, y, z, NULL)" >> $g_GENERIC
echo "#define __b2c__FAPPEND5(s, x, y, z, f) __b2c__append(&s, 1, x, y, z, f)" >> $g_GENERIC
echo "#define F_APPEND${g_STRINGSIGN}(...) __b2c__FUNCSELECT5(__VA_ARGS__, __b2c__FAPPEND5, __b2c__FAPPEND4)(__VA_ARGS__)" >> $g_GENERIC
echo "#define ASC(x) (x == NULL ? 0 : (unsigned char)*x)" >> $g_GENERIC
echo "#define ASIN(x) asin((double)x)" >> $g_GENERIC
echo "#define ATN(x) atan((double)x)" >> $g_GENERIC
echo "#define ATN2(x,y) atan2((double)x,(double)y)" >> $g_GENERIC
echo "#define B64DEC${g_STRINGSIGN}(x) __b2c__b64dec(__LINE__, __FILE__, x)" >> $g_GENERIC
echo "#define __b2c__B64ENC1(x) __b2c__b64enc(x, 0)" >> $g_GENERIC
echo "#define __b2c__B64ENC2(x, y) __b2c__b64enc((char*)x, y)" >> $g_GENERIC
echo "#define B64ENC${g_STRINGSIGN}(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__B64ENC2, __b2c__B64ENC1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__BASENAME1(x) __b2c__dirname(__LINE__, __FILE__, 1, x, 0)" >> $g_GENERIC
echo "#define __b2c__BASENAME2(x, y) __b2c__dirname(__LINE__, __FILE__, 1, x, y)" >> $g_GENERIC
echo "#define BASENAME${g_STRINGSIGN}(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__BASENAME2, __b2c__BASENAME1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define BIN${g_STRINGSIGN}(x) __b2c__bin(sizeof(__b2c__MEMTYPE), x)" >> $g_GENERIC
echo "#define BIT(x) __b2c__bit(x)" >> $g_GENERIC
echo "#define BLOAD(x) (void*)__b2c__load(1, __LINE__, __FILE__, x)" >> $g_GENERIC
echo "#define __b2c__BYTELEN2(x, y) __b2c__blen(__LINE__, __FILE__, \"BYTELEN\", x, y, 0)" >> $g_GENERIC
echo "#define __b2c__BYTELEN3(x, y, z) __b2c__blen(__LINE__, __FILE__, \"BYTELEN\", x, y, z)" >> $g_GENERIC
echo "#define BYTELEN(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__BYTELEN3, __b2c__BYTELEN2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define CA${g_STRINGSIGN}(x) __b2c__ca(__LINE__, __FILE__, x)" >> $g_GENERIC
echo "#define CN${g_STRINGSIGN}(x) __b2c__cn(__LINE__, __FILE__, x)" >> $g_GENERIC
echo "#define CIPHER${g_STRINGSIGN}(x) __b2c__cipher(__LINE__, __FILE__, x)" >> $g_GENERIC
echo "#define VERIFY(x, y) ((SSL*)x == NULL ? -1 : (long)SSL_get_verify_result((SSL*)x) )" >> $g_GENERIC
echo "#define ACCEPT(x) __b2c__accept(__LINE__, __FILE__, __b2c__caprivate, __b2c__caserver, x)" >> $g_GENERIC
echo "#define CEIL(x) (double)ceil(x)" >> $g_GENERIC
echo "#define __b2c__CHANGE3(x, y, z) __b2c__change(x, y, z, NULL)" >> $g_GENERIC
echo "#define __b2c__CHANGE4(x, y, z, f) __b2c__change(x, y, z, f)" >> $g_GENERIC
echo "#define CHANGE${g_STRINGSIGN}(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__CHANGE4, __b2c__CHANGE3)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__CHOP1(x) __b2c__chop(NULL, 0, x, NULL, 0)" >> $g_GENERIC
echo "#define __b2c__CHOP2(x, y) __b2c__chop(NULL, 0, x, y, 0)" >> $g_GENERIC
echo "#define __b2c__CHOP3(x, y, z) __b2c__chop(NULL, 0, x, y, z)" >> $g_GENERIC
echo "#define CHOP${g_STRINGSIGN}(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__CHOP3, __b2c__CHOP2, __b2c__CHOP1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__FCHOP2(s, x) __b2c__chop(&s, 1, x, NULL, 0)" >> $g_GENERIC
echo "#define __b2c__FCHOP3(s, x, y) __b2c__chop(&s, 1, x, y, 0)" >> $g_GENERIC
echo "#define __b2c__FCHOP4(s, x, y, z) __b2c__chop(&s, 1, x, y, z)" >> $g_GENERIC
echo "#define F_CHOP${g_STRINGSIGN}(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__FCHOP4, __b2c__FCHOP3, __b2c__FCHOP2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define CHR${g_STRINGSIGN}(x) __b2c__asc2char(x)" >> $g_GENERIC
echo "#define UTF8${g_STRINGSIGN}(x) __b2c__asc2utf8(x)" >> $g_GENERIC
echo "#define CL${g_STRINGSIGN} \"\033[2K\"" >> $g_GENERIC
echo "#define CMDLINE(x) __b2c__getopt(argc, argv, x)" >> $g_GENERIC
echo "#define COIL${g_STRINGSIGN}(...) ( !setjmp(__b2c__loop1) ? __b2c__loop_helper(__b2c__loop2) : __b2c__loop_result${g_STRINGSIGN} )" >> $g_GENERIC
echo "#define __b2c__COLLAPSE1(x) __b2c__collapse_func(x, NULL)" >> $g_GENERIC
echo "#define __b2c__COLLAPSE2(x, y) __b2c__collapse_func(x, y)" >> $g_GENERIC
echo "#define COLLAPSE${g_STRINGSIGN}(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__COLLAPSE2, __b2c__COLLAPSE1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define COLUMNS __b2c__screen(0)" >> $g_GENERIC
echo "#define CONCAT${g_STRINGSIGN}(...) __b2c__concat(sizeof((const char*[]) {__VA_ARGS__}) / sizeof(char*), __VA_ARGS__)" >> $g_GENERIC
echo "#define F_CONCAT${g_STRINGSIGN}(...) __b2c__concat2(sizeof((const char*[]) {__VA_ARGS__}) / sizeof(char*), __VA_ARGS__)" >> $g_GENERIC
echo "#define COS(x) cos((double)x)" >> $g_GENERIC
echo "#define COUNT(x, y) ((x) != NULL ? __b2c__count(__LINE__, __FILE__, x, y) : 0)" >> $g_GENERIC
echo "#define CR${g_STRINGSIGN} \"\r\"" >> $g_GENERIC
echo "#define CURDIR${g_STRINGSIGN} __b2c__curdir()" >> $g_GENERIC
echo "#define __b2c__CUT3(x, y, z) __b2c__cut(x, y, z, NULL)" >> $g_GENERIC
echo "#define __b2c__CUT4(x, y, z, f) __b2c__cut(x, y, z, f)" >> $g_GENERIC
echo "#define CUT${g_STRINGSIGN}(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__CUT4, __b2c__CUT3)(__VA_ARGS__)" >> $g_GENERIC
echo "#define DAY(x) __b2c__time(x, 1)" >> $g_GENERIC
echo "#define __b2c__DEC1(x) __b2c__hex2dec(__LINE__, __FILE__, x, 0)" >> $g_GENERIC
echo "#define __b2c__DEC2(x, y) __b2c__hex2dec(__LINE__, __FILE__, x, y)" >> $g_GENERIC
echo "#define DEC(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__DEC2, __b2c__DEC1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define DEG(x) (x*180/PI)" >> $g_GENERIC
echo "#define __b2c__DEL2(x, y) __b2c__del(x, y, NULL)" >> $g_GENERIC
echo "#define __b2c__DEL3(x, y, z) __b2c__del(x, y, z)" >> $g_GENERIC
echo "#define DEL${g_STRINGSIGN}(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__DEL3, __b2c__DEL2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define DELIM${g_STRINGSIGN}(x, y, z) __b2c__delim(x, y, z)" >> $g_GENERIC
echo "#define DIRNAME${g_STRINGSIGN}(x) __b2c__dirname(__LINE__, __FILE__, 2, x, 0)" >> $g_GENERIC
echo "#define DLE${g_STRINGSIGN} \"\r\n\"" >> $g_GENERIC
echo "#define EDITBOM${g_STRINGSIGN}(x, y) __b2c__editbom(x, y)" >> $g_GENERIC
echo "#define EL${g_STRINGSIGN} \"\033[0K\"" >> $g_GENERIC
echo "#define ENDFILE(x) feof(x)" >> $g_GENERIC
echo "#define EQ ==" >> $g_GENERIC
echo "#define EQUAL(x, y) ((x) != NULL && (y) != NULL ? !__b2c__STRCMP(x, y) : 0)" >> $g_GENERIC
echo "#define ESCAPE${g_STRINGSIGN}(x) __b2c__escape(__LINE__, __FILE__, x)" >> $g_GENERIC
echo "#define EVAL(x, y, z, q) __b2c__eval(__LINE__, __FILE__, x, y, z, q)" >> $g_GENERIC
echo "#define EVEN(x) (((long)(x) % 2 == 0) ? 1 : 0)" >> $g_GENERIC
echo "#define __b2c__EXCHANGE3(x, y, z) __b2c__exchange(x, y, z, NULL)" >> $g_GENERIC
echo "#define __b2c__EXCHANGE4(x, y, z, f) __b2c__exchange(x, y, z, f)" >> $g_GENERIC
echo "#define EXCHANGE${g_STRINGSIGN}(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__EXCHANGE4, __b2c__EXCHANGE3)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__EXEC1(x) __b2c__exec(0, __LINE__, __FILE__, x, NULL, 0)" >> $g_GENERIC
echo "#define __b2c__EXEC2(x, y) __b2c__exec(0, __LINE__, __FILE__, x, y, 0)" >> $g_GENERIC
echo "#define __b2c__EXEC3(x, y, z) __b2c__exec(0, __LINE__, __FILE__, x, y, z)" >> $g_GENERIC
echo "#define EXEC${g_STRINGSIGN}(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__EXEC3, __b2c__EXEC2, __b2c__EXEC1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define EXP(x) exp((double)x)" >> $g_GENERIC
echo "#define __b2c__EXPLODE1(x) __b2c__explode(__LINE__, __FILE__, x, 1, NULL)" >> $g_GENERIC
echo "#define __b2c__EXPLODE2(x, y) __b2c__explode(__LINE__, __FILE__, x, y, NULL)" >> $g_GENERIC
echo "#define __b2c__EXPLODE3(x, y, z) __b2c__explode(__LINE__, __FILE__, x, y, z)" >> $g_GENERIC
echo "#define EXPLODE${g_STRINGSIGN}(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__EXPLODE3, __b2c__EXPLODE2, __b2c__EXPLODE1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__EXTRACT2(x, y) __b2c__extract(__LINE__, __FILE__, x, y, 0)" >> $g_GENERIC
echo "#define __b2c__EXTRACT3(x, y, z) __b2c__extract(__LINE__, __FILE__, x, y, z)" >> $g_GENERIC
echo "#define EXTRACT${g_STRINGSIGN}(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__EXTRACT3, __b2c__EXTRACT2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define FALSE 0" >> $g_GENERIC
echo "#define FILEEXISTS(x) (x != NULL ? !access(x, F_OK) : 0)" >> $g_GENERIC
echo "#define FILELEN(x) __b2c__filelen(__LINE__, __FILE__, x)" >> $g_GENERIC
echo "#define FILETIME(x, y) __b2c__filetime(__LINE__, __FILE__, x, y)" >> $g_GENERIC
echo "#define FILETYPE(x) __b2c__filetype(__LINE__, __FILE__, x)" >> $g_GENERIC
echo "#define FILL${g_STRINGSIGN}(x, y) ((y) >= 0 && (y) <= 0x10FFFF ? __b2c__fill(x, y) : NULL)" >> $g_GENERIC
echo "#define FIND(x, y, z, a) __b2c__find(x, y, z, a)" >> $g_GENERIC
echo "#define __b2c__FIRST2(x, y) __b2c__first(x, y, NULL)" >> $g_GENERIC
echo "#define __b2c__FIRST3(x, y, z) __b2c__first(x, y, z)" >> $g_GENERIC
echo "#define FIRST${g_STRINGSIGN}(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__FIRST3, __b2c__FIRST2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__FLATTEN1(x) __b2c__flatten(x, NULL)" >> $g_GENERIC
echo "#define __b2c__FLATTEN2(x, y) __b2c__flatten(x, y)" >> $g_GENERIC
echo "#define FLATTEN${g_STRINGSIGN}(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__FLATTEN2, __b2c__FLATTEN1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define FLOATING double" >> $g_GENERIC
echo "#define FLOOR(x) (long)floor(x)" >> $g_GENERIC
echo "#define FORK fork()" >> $g_GENERIC
echo "#define FP(x) (void*)(&x)" >> $g_GENERIC
echo "#define GE >=" >> $g_GENERIC
echo "#define GETENVIRON${g_STRINGSIGN}(x) ((x) != NULL ? __b2c__getenv(x) : (char*)\"null\")" >> $g_GENERIC
echo "#define GETKEY __b2c__getch()" >> $g_GENERIC
echo "#define GETPEER${g_STRINGSIGN}(x) __b2c__getpeer(__LINE__, __FILE__, (uintptr_t)x)" >> $g_GENERIC
echo "#define GETX __b2c__getxy(0)" >> $g_GENERIC
echo "#define GETY __b2c__getxy(1)" >> $g_GENERIC
echo "#define GT >" >> $g_GENERIC
echo "#define HASBOM(x) __b2c__hasbom(x)" >> $g_GENERIC
echo "#define __b2c__HASDELIM1(x) __b2c__hasdelim(x, NULL)" >> $g_GENERIC
echo "#define __b2c__HASDELIM2(x, y) __b2c__hasdelim(x, y)" >> $g_GENERIC
echo "#define HASDELIM(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__HASDELIM2, __b2c__HASDELIM1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__HASH1(x) HASH_FUNC((char*)x, 0)" >> $g_GENERIC
echo "#define __b2c__HASH2(x, y) HASH_FUNC((char*)x, y)" >> $g_GENERIC
echo "#define HASH(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__HASH2, __b2c__HASH1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__HEAD2(x, y) __b2c__head(x, y, NULL)" >> $g_GENERIC
echo "#define __b2c__HEAD3(x, y, z) __b2c__head(x, y, z)" >> $g_GENERIC
echo "#define HEAD${g_STRINGSIGN}(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__HEAD3, __b2c__HEAD2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define HEX${g_STRINGSIGN}(x) __b2c__dec2hex(x)" >> $g_GENERIC
echo "#define HOST${g_STRINGSIGN}(x) __b2c__nethost(__LINE__, __FILE__, x)" >> $g_GENERIC
echo "#define HOSTNAME${g_STRINGSIGN} __b2c__hostname(__LINE__, __FILE__)" >> $g_GENERIC
echo "#define HOUR(x) __b2c__time(x, 4)" >> $g_GENERIC
echo "#define __b2c__IIF2(x, y) (x ? y : 0)" >> $g_GENERIC
echo "#define __b2c__IIF3(x, y, z) (x ? y : z)" >> $g_GENERIC
echo "#define IIF(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__IIF3, __b2c__IIF2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__IIFS2(x, y) (char*)(x ? y : NULL)" >> $g_GENERIC
echo "#define __b2c__IIFS3(x, y, z) (char*)(x ? y : z)" >> $g_GENERIC
echo "#define IIF${g_STRINGSIGN}(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__IIFS3, __b2c__IIFS2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__INBETWEEN3(x, y, z) __b2c__inbetween(0, x, y, z, 0)" >> $g_GENERIC
echo "#define __b2c__INBETWEEN4(x, y, z, f) __b2c__inbetween(0, x, y, z, f)" >> $g_GENERIC
echo "#define INBETWEEN${g_STRINGSIGN}(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__INBETWEEN4, __b2c__INBETWEEN3)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__INDEX4(r, t, x, y) __b2c__index(__LINE__, __FILE__, r+${g_OPTION_BASE}, t, (void*)x, 0, y)" >> $g_GENERIC
echo "#define __b2c__INDEX5(r, t, x, y, z) __b2c__index(__LINE__, __FILE__, r+${g_OPTION_BASE}, t, (void*)x, z, y)" >> $g_GENERIC
echo "#define INDEX(...) __b2c__FUNCSELECT5(__VA_ARGS__, __b2c__INDEX5, __b2c__INDEX4)(__VA_ARGS__)" >> $g_GENERIC
echo "#define INDEX${g_STRINGSIGN}(t, x, y) __b2c__index_assoc(__LINE__, __FILE__, t, (__b2c__htable*)__b2c__assoc_ ## x, y)" >> $g_GENERIC
echo "#define INSERT${g_STRINGSIGN}(x, y, z) __b2c__insert(__LINE__, __FILE__, x, y, z)" >> $g_GENERIC
echo "#define __b2c__INSTR2(x, y) __b2c__instr(__LINE__, __FILE__, x, y, -1)" >> $g_GENERIC
echo "#define __b2c__INSTR3(x, y, z) __b2c__instr(__LINE__, __FILE__, x, y, z)" >> $g_GENERIC
echo "#define INSTR(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__INSTR3, __b2c__INSTR2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__INSTRREV2(x, y) __b2c__instrrev(__LINE__, __FILE__, x, y, -1)" >> $g_GENERIC
echo "#define __b2c__INSTRREV3(x, y, z) __b2c__instrrev(__LINE__, __FILE__, x, y, z)" >> $g_GENERIC
echo "#define INSTRREV(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__INSTRREV3, __b2c__INSTRREV2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define INT(x) lrint((double)x)" >> $g_GENERIC
echo "#define INTL${g_STRINGSIGN}(x) gettext(x)" >> $g_GENERIC
echo "#define INVERT(t, x) __b2c__invert(__LINE__, __FILE__, t, &__b2c__assoc_ ## x)" >> $g_GENERIC
echo "#define IS ==" >> $g_GENERIC
echo "#define ISASCII(x) __b2c__isascii(x)" >> $g_GENERIC
echo "#define ISFALSE(x) ((x) == 0)" >> $g_GENERIC
echo "#define ISKEY(x, ...) (__b2c__hash_find_key_do(__b2c__assoc_ ## x, 0, __b2c__KEYCOLLECT(__VA_ARGS__)) == NULL ? 0 : 1)" >> $g_GENERIC
echo "#define ISNOT !=" >> $g_GENERIC
echo "#define __b2c__ISTOKEN2(x, y) __b2c__istoken(x, y, NULL)" >> $g_GENERIC
echo "#define __b2c__ISTOKEN3(x, y, z) __b2c__istoken(x, y, z)" >> $g_GENERIC
echo "#define ISTOKEN(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__ISTOKEN3, __b2c__ISTOKEN2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define ISTRUE(x) ((x) != 0)" >> $g_GENERIC
echo "#define ISUTF8(x) __b2c__isutf8(x)" >> $g_GENERIC
echo "#define LCASE${g_STRINGSIGN}(x) __b2c__lcase(__LINE__, __FILE__, x)" >> $g_GENERIC
echo "#define LE <=" >> $g_GENERIC
echo "#define __b2c__LEFT1(x) __b2c__left(__LINE__, __FILE__, x, 1)" >> $g_GENERIC
echo "#define __b2c__LEFT2(x, y) __b2c__left(__LINE__, __FILE__, x, y)" >> $g_GENERIC
echo "#define LEFT${g_STRINGSIGN}(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__LEFT2, __b2c__LEFT1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define LEN(x) (__b2c__option_utf8 ? __b2c__ulen(__LINE__, __FILE__, \"LEN\", (char*)x, -1) : __b2c__len(x))" >> $g_GENERIC
echo "#define __b2c__ULEN1(x) __b2c__ulen(__LINE__, __FILE__, \"ULEN\", (char*)x, -1)" >> $g_GENERIC
echo "#define __b2c__ULEN2(x, y) __b2c__ulen(__LINE__, __FILE__, \"ULEN\", (char*)x, y)" >> $g_GENERIC
echo "#define ULEN(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__ULEN2, __b2c__ULEN1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__LAST2(x, y) __b2c__last(x, y, NULL)" >> $g_GENERIC
echo "#define __b2c__LAST3(x, y, z) __b2c__last(x, y, z)" >> $g_GENERIC
echo "#define LAST${g_STRINGSIGN}(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__LAST3, __b2c__LAST2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define LINENO __LINE__" >> $g_GENERIC
echo "#define LOAD${g_STRINGSIGN}(x) __b2c__load(0, __LINE__, __FILE__, x)" >> $g_GENERIC
echo "#define LOG(x) log((double)x)" >> $g_GENERIC
echo "#define LOOP${g_STRINGSIGN}(...) ( !setjmp(__b2c__loop1) ? __b2c__loop_helper(__b2c__loop2) : __b2c__loop_result${g_STRINGSIGN} )" >> $g_GENERIC
echo "#define LOOP(...) ( !setjmp(__b2c__loop1) ? __b2c__loop_helper2(__b2c__loop2) : __b2c__loop_result )" >> $g_GENERIC
echo "#define LT <" >> $g_GENERIC
echo "#define __b2c__MATCH2(x, y) __b2c__match(x, y, -1, NULL)" >> $g_GENERIC
echo "#define __b2c__MATCH3(x, y, z) __b2c__match(x, y, z, NULL)" >> $g_GENERIC
echo "#define __b2c__MATCH4(x, y, z, f) __b2c__match(x, y, z, f)" >> $g_GENERIC
echo "#define MATCH(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__MATCH4, __b2c__MATCH3, __b2c__MATCH2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define MAX(x, y) fmax(x, y)" >> $g_GENERIC
echo "#define MAX${g_STRINGSIGN}(x, y) __b2c__max_str(x, y)" >> $g_GENERIC
echo "#define MAXNUM(x) (x)POW(2, SIZEOF(x)*8)" >> $g_GENERIC
if [[ `uname` = +(*SunOS*|*OSF1*) ]]
then
    echo "#define MAXRANDOM 2147483647" >> $g_GENERIC
else
    echo "#define MAXRANDOM RAND_MAX" >> $g_GENERIC
fi
echo "#define ME${g_STRINGSIGN} __b2c__me_var${g_STRINGSIGN}" >> $g_GENERIC
echo "#define MEMCHECK(x) __b2c__memory__check((char*)x, sizeof(__b2c__MEMTYPE))" >> $g_GENERIC
echo "#define MEMORY(x) (calloc(x+__b2c__option_memstream, sizeof(__b2c__MEMTYPE)))" >> $g_GENERIC
echo "#define MEMTELL(x) (long)x" >> $g_GENERIC
echo "#define __b2c__MERGE1(x) __b2c__merge(x, NULL)" >> $g_GENERIC
echo "#define __b2c__MERGE2(x, y) __b2c__merge(x, y)" >> $g_GENERIC
echo "#define MERGE${g_STRINGSIGN}(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__MERGE2, __b2c__MERGE1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__MID2(x, y) __b2c__mid(__LINE__, __FILE__, NULL, 0, x, y, -1)" >> $g_GENERIC
echo "#define __b2c__MID3(x, y, z) __b2c__mid(__LINE__, __FILE__, NULL, 0, x, y, z)" >> $g_GENERIC
echo "#define MID${g_STRINGSIGN}(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__MID3, __b2c__MID2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__FMID3(s, x, y) __b2c__mid(__LINE__, __FILE__, &s, 1, x, y, -1)" >> $g_GENERIC
echo "#define __b2c__FMID4(s, x, y, z) __b2c__mid(__LINE__, __FILE__, &s, 1, x, y, z)" >> $g_GENERIC
echo "#define F_MID${g_STRINGSIGN}(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__FMID4, __b2c__FMID3)(__VA_ARGS__)" >> $g_GENERIC
echo "#define MIN(x, y) fmin(x, y)" >> $g_GENERIC
echo "#define MIN${g_STRINGSIGN}(x, y) __b2c__min_str(x, y)" >> $g_GENERIC
echo "#define MINUTE(x) __b2c__time(x, 5)" >> $g_GENERIC
echo "#define MOD(x, y) ((long)(x) % (long)(y))" >> $g_GENERIC
echo "#define MONTH(x) __b2c__time(x, 2)" >> $g_GENERIC
echo "#define MONTH${g_STRINGSIGN}(x) __b2c__datename(x, 2)" >> $g_GENERIC
echo "#define MYPID getpid()" >> $g_GENERIC
echo "#define NANOTIMER __b2c__nanotimer(0)" >> $g_GENERIC
echo "#define NE !=" >> $g_GENERIC
echo "#define NL${g_STRINGSIGN} \"\n\"" >> $g_GENERIC
echo "#define NNTL${g_STRINGSIGN}(x,y,z) ngettext(x,y,z)" >> $g_GENERIC
echo "#define NOT(x) (!(x))" >> $g_GENERIC
echo "#define NOW (long)time(NULL)" >> $g_GENERIC
echo "#define NRKEYS(x) __b2c__hash_nrkeys(__b2c__assoc_ ## x)" >> $g_GENERIC
echo "#define NUMBER long" >> $g_GENERIC
echo "#define __b2c__OBTAIN1(x) __b2c__hash_obtain(__b2c__assoc_ ## x, NULL)" >> $g_GENERIC
echo "#define __b2c__OBTAIN2(x, y) __b2c__hash_obtain(__b2c__assoc_ ## x, y)" >> $g_GENERIC
echo "#define __b2c__OBTAIN3(x, y, z) __b2c__hash_obtain_by_sort(__LINE__, __FILE__, __b2c__assoc_ ## x, y, z, __b2c__obtain_type_ ## x)" >> $g_GENERIC
echo "#define OBTAIN${g_STRINGSIGN}(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__OBTAIN3, __b2c__OBTAIN2, __b2c__OBTAIN1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define ODD(x) (((long)(x) % 2 != 0) ? 1 : 0)" >> $g_GENERIC
echo "#define OR ||" >> $g_GENERIC
echo "#define OS${g_STRINGSIGN} __b2c__os(__LINE__, __FILE__)" >> $g_GENERIC
echo "#define __b2c__OUTBETWEEN3(x, y, z) __b2c__inbetween(1, x, y, z, 0)" >> $g_GENERIC
echo "#define __b2c__OUTBETWEEN4(x, y, z, f) __b2c__inbetween(1, x, y, z, f)" >> $g_GENERIC
echo "#define OUTBETWEEN${g_STRINGSIGN}(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__OUTBETWEEN4, __b2c__OUTBETWEEN3)(__VA_ARGS__)" >> $g_GENERIC
echo "#define PEEK(x) (__b2c__peek_check(__LINE__, __FILE__, (char*)x, sizeof(__b2c__MEMTYPE)) == 0 ? *(__b2c__MEMTYPE *)(x) : 0)" >> $g_GENERIC
echo "#define PI 3.14159265358979323846" >> $g_GENERIC
echo "#define POW(x, y) pow((double)x, (double)y)" >> $g_GENERIC
echo "#define __b2c__PROPER1(x) __b2c__proper(__LINE__, __FILE__, x, NULL)" >> $g_GENERIC
echo "#define __b2c__PROPER2(x, y) __b2c__proper(__LINE__, __FILE__, x, y)" >> $g_GENERIC
echo "#define PROPER${g_STRINGSIGN}(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__PROPER2, __b2c__PROPER1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define RAD(x) (x*PI/180)" >> $g_GENERIC
echo "#define RANDOM(x) ((x) != 0 ? random()/(MAXRANDOM/(x)) : 0)" >> $g_GENERIC
echo "#define REALPATH${g_STRINGSIGN}(x) __b2c__dirname(__LINE__, __FILE__, 0, x, 0)" >> $g_GENERIC
echo "#define REAP(x) waitpid(x, NULL, WNOHANG)" >> $g_GENERIC
echo "#define REGEX(x, y) __b2c__regex(__LINE__, __FILE__, x, y)" >> $g_GENERIC
echo "#define __b2c__REPLACE3(x, y, z) __b2c__replace(__LINE__, __FILE__, x, y, z, 0)" >> $g_GENERIC
echo "#define __b2c__REPLACE4(x, y, z, f) __b2c__replace(__LINE__, __FILE__, x, y, z, f)" >> $g_GENERIC
echo "#define REPLACE${g_STRINGSIGN}(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__REPLACE4, __b2c__REPLACE3)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__REV1(x) __b2c__rev(x, NULL)" >> $g_GENERIC
echo "#define __b2c__REV2(x, y) __b2c__rev(x, y)" >> $g_GENERIC
echo "#define REV${g_STRINGSIGN}(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__REV2, __b2c__REV1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define REVERSE${g_STRINGSIGN}(x) __b2c__reverse(__LINE__, __FILE__, x)" >> $g_GENERIC
echo "#define __b2c__RIGHT1(x) __b2c__right(__LINE__, __FILE__, x, 1)" >> $g_GENERIC
echo "#define __b2c__RIGHT2(x, y) __b2c__right(__LINE__, __FILE__, x, y)" >> $g_GENERIC
echo "#define RIGHT${g_STRINGSIGN}(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__RIGHT2, __b2c__RIGHT1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__RIP2(x, y) __b2c__rip(__LINE__, __FILE__, x, y, -1)" >> $g_GENERIC
echo "#define __b2c__RIP3(x, y, z) __b2c__rip(__LINE__, __FILE__, x, y, z)" >> $g_GENERIC
echo "#define RIP${g_STRINGSIGN}(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__RIP3, __b2c__RIP2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define RND random()" >> $g_GENERIC
echo "#define ROL(x) __b2c__rol(sizeof(__b2c__MEMTYPE), x)" >> $g_GENERIC
echo "#define ROR(x) __b2c__ror(sizeof(__b2c__MEMTYPE), x)" >> $g_GENERIC
echo "#define __b2c__ROTATE2(x, y) __b2c__rotate(x, y, NULL)" >> $g_GENERIC
echo "#define __b2c__ROTATE3(x, y, z) __b2c__rotate(x, y, z)" >> $g_GENERIC
echo "#define ROTATE${g_STRINGSIGN}(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__ROTATE3, __b2c__ROTATE2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define ROUND(x) lrint((double)x)" >> $g_GENERIC
echo "#define ROWS __b2c__screen(1)" >> $g_GENERIC
echo "#define __b2c__RUN1(x) __b2c__exec(1, __LINE__, __FILE__, x, NULL, 0)" >> $g_GENERIC
echo "#define __b2c__RUN2(x, y) __b2c__exec(1, __LINE__, __FILE__, x, y, 0)" >> $g_GENERIC
echo "#define __b2c__RUN3(x, y, z) __b2c__exec(1, __LINE__, __FILE__, x, y, z)" >> $g_GENERIC
echo "#define RUN${g_STRINGSIGN}(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__RUN3, __b2c__RUN2, __b2c__RUN1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__SEARCH2(x, y) __b2c__search(__LINE__, __FILE__, x, y, -1)" >> $g_GENERIC
echo "#define __b2c__SEARCH3(x, y, z) __b2c__search(__LINE__, __FILE__, x, y, z)" >> $g_GENERIC
echo "#define SEARCH(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__SEARCH3, __b2c__SEARCH2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define SECOND(x) __b2c__time(x, 6)" >> $g_GENERIC
echo "#define SETENVIRON(x, y) if((x) != NULL && (y) != NULL) setenv(x, y, 1)" >> $g_GENERIC
echo "#define SGN(x) ((x) == 0 ? 0 : ((x) < 0 ? -1 : 1))" >> $g_GENERIC
echo "#define SIN(x) sin((double)x)" >> $g_GENERIC
echo "#define SIZEOF(x) sizeof(x)" >> $g_GENERIC
echo "#define __b2c__SORT1(x) __b2c__sort(x, NULL)" >> $g_GENERIC
echo "#define __b2c__SORT2(x, y) __b2c__sort(x, y)" >> $g_GENERIC
echo "#define SORT${g_STRINGSIGN}(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__SORT2, __b2c__SORT1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define SPC${g_STRINGSIGN}(x) ((x) > 0 ? __b2c__spc(x) : NULL)" >> $g_GENERIC
echo "#define SQR(x) sqrt((double)(x))" >> $g_GENERIC
echo "#define STR${g_STRINGSIGN}(x) __b2c__str(x)" >> $g_GENERIC
echo "#define STRING char*" >> $g_GENERIC
echo "#define SUM(x,...) __b2c__sum($g_OPTION_BASE, x, __VA_ARGS__, LONG_MAX)" >> $g_GENERIC
echo "#define SUMF(x,...) __b2c__sumf($g_OPTION_BASE, x, __VA_ARGS__, DBL_MAX)" >> $g_GENERIC
echo "#define SYSTEM(x) do {if (x != NULL) {RETVAL = system(x); if(WIFEXITED(RETVAL)) RETVAL = WEXITSTATUS(RETVAL);} else RETVAL=0;} while(0)" >> $g_GENERIC
echo "#define TAB${g_STRINGSIGN}(x) ((x) > 0 ? __b2c__tab(x) : NULL)" >> $g_GENERIC
echo "#define __b2c__TAIL2(x, y) __b2c__tail(x, y, NULL)" >> $g_GENERIC
echo "#define __b2c__TAIL3(x, y, z) __b2c__tail(x, y, z)" >> $g_GENERIC
echo "#define TAIL${g_STRINGSIGN}(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__TAIL3, __b2c__TAIL2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__TALLY2(x, y) __b2c__tally(x, y, -1)" >> $g_GENERIC
echo "#define __b2c__TALLY3(x, y, z) __b2c__tally(x, y, z)" >> $g_GENERIC
echo "#define TALLY(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__TALLY3, __b2c__TALLY2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define TAN(x) tan((double)x)" >> $g_GENERIC
echo "#define TELL(x) ftell(x)" >> $g_GENERIC
echo "#define TIMER __b2c__timer(0)" >> $g_GENERIC
echo "#define TIMEVALUE(x,y,z,a,b,c) __b2c__epoch(x,y,z,a,b,c)" >> $g_GENERIC
echo "#define TOASCII${g_STRINGSIGN}(x) __b2c__toascii(x)" >> $g_GENERIC
echo "#define __b2c__TOKEN2(x, y) __b2c__token(x, y, NULL)" >> $g_GENERIC
echo "#define __b2c__TOKEN3(x, y, z) __b2c__token(x, y, z)" >> $g_GENERIC
echo "#define TOKEN${g_STRINGSIGN}(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__TOKEN3, __b2c__TOKEN2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define TOTAL(x) __b2c__total(x)" >> $g_GENERIC
echo "#define TRUE 1" >> $g_GENERIC
echo "#define UCASE${g_STRINGSIGN}(x) __b2c__ucase(__LINE__, __FILE__, x)" >> $g_GENERIC
echo "#define UCS(x) (unsigned int)__b2c__utf8toasc(x)" >> $g_GENERIC
echo "#define UNESCAPE${g_STRINGSIGN}(x) __b2c__unescape(__LINE__, __FILE__, x)" >> $g_GENERIC
echo "#define __b2c__UNFLATTEN1(x) __b2c__unflatten(x, NULL)" >> $g_GENERIC
echo "#define __b2c__UNFLATTEN2(x, y) __b2c__unflatten(x, y)" >> $g_GENERIC
echo "#define UNFLATTEN${g_STRINGSIGN}(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__UNFLATTEN2, __b2c__UNFLATTEN1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define __b2c__UNIQ1(x) __b2c__uniq(x, NULL)" >> $g_GENERIC
echo "#define __b2c__UNIQ2(x, y) __b2c__uniq(x, y)" >> $g_GENERIC
echo "#define UNIQ${g_STRINGSIGN}(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__UNIQ2, __b2c__UNIQ1)(__VA_ARGS__)" >> $g_GENERIC
echo "#define VAL(x) ((x) != NULL ? atof(x) : 0)" >> $g_GENERIC
echo "#define WAIT(x, y) __b2c__netpeek(__LINE__, __FILE__, (uintptr_t)x, y)" >> $g_GENERIC
echo "#define __b2c__WALK4(x, y, z, q) __b2c__walk(__LINE__, __FILE__, x, y, z, q, NULL)" >> $g_GENERIC
echo "#define __b2c__WALK5(x, y, z, q, f) __b2c__walk(__LINE__, __FILE__, x, y, z, q, f)" >> $g_GENERIC
echo "#define WALK${g_STRINGSIGN}(...) __b2c__FUNCSELECT5(__VA_ARGS__, __b2c__WALK5, __b2c__WALK4)(__VA_ARGS__)" >> $g_GENERIC
echo "#define WEEK(x) __b2c__time(x, 7)" >> $g_GENERIC
echo "#define WEEKDAY${g_STRINGSIGN}(x) __b2c__datename(x, 1)" >> $g_GENERIC
echo "#define __b2c__WHERE2(x, y) __b2c__where(x, y, NULL)" >> $g_GENERIC
echo "#define __b2c__WHERE3(x, y, z) __b2c__where(x, y, z)" >> $g_GENERIC
echo "#define WHERE(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__WHERE3, __b2c__WHERE2)(__VA_ARGS__)" >> $g_GENERIC
echo "#define YEAR(x) __b2c__time(x, 3)" >> $g_GENERIC
echo "#define __b2c__cacerts NULL" >> $g_GENERIC
echo "#define __b2c__capeer 0" >> $g_GENERIC
echo "#define __b2c__caprivate NULL" >> $g_GENERIC
echo "#define __b2c__caserver NULL" >> $g_GENERIC

# Check presence of lex
if [[ -n `command -v flex 2>/dev/null` ]]
then
    LEX="flex"
elif [[ -n `command -v lex 2>/dev/null` ]]
then
    LEX="lex"
else
    echo "WARNING: neither 'lex' nor 'flex' was found on this system!"
    echo "Generated binary cannot be optimized."
fi

if [[ -n ${LEX} ]]
then
    # Create lexer file to see which functions are needed, so the resulting binary can be optimized
    echo "%{" > ${g_BACONLEXER}
    echo "#include <stdio.h>" >> ${g_BACONLEXER}
    echo "%}" >> ${g_BACONLEXER}
    echo "%x text escaped comment multi" >> ${g_BACONLEXER}
    echo "WS [ \n\r\t]+" >> ${g_BACONLEXER}
    echo "%%" >> ${g_BACONLEXER}
    echo "\"ALARM\"{WS}       printf(\"alarm \");" >> ${g_BACONLEXER}
    echo "\"ALIGN\$(\"        printf(\"align delimengine \");" >> ${g_BACONLEXER}
    echo "\"AMOUNT(\"         printf(\"amount delimengine \");" >> ${g_BACONLEXER}
    echo "\"APPEND\"{WS}      printf(\"save concat \");" >> ${g_BACONLEXER}
    echo "\"APPEND\$(\"       printf(\"append delimengine \");" >> ${g_BACONLEXER}
    echo "\"ASSOC\"{WS}       printf(\"hash sortstr sortnr \");" >> ${g_BACONLEXER}
    echo "\"B64DEC\$(\"       printf(\"base64 \");" >> ${g_BACONLEXER}
    echo "\"B64ENC\$(\"       printf(\"base64 \");" >> ${g_BACONLEXER}
    echo "\"BASENAME\$(\"     printf(\"dirname \");" >> ${g_BACONLEXER}
    echo "\"BIT(\"            printf(\"binary \");" >> ${g_BACONLEXER}
    echo "\"BIN\$(\"          printf(\"binary \");" >> ${g_BACONLEXER}
    echo "\"BLOAD(\"          printf(\"load \");" >> ${g_BACONLEXER}
    echo "\"CA\$(\"           printf(\"cipher \");" >> ${g_BACONLEXER}
    echo "\"CHANGE\$(\"       printf(\"change delimengine \");" >> ${g_BACONLEXER}
    echo "\"CHOP\$(\"         printf(\"chop \");" >> ${g_BACONLEXER}
    echo "\"CHR\$(\"          printf(\"chrstr \");" >> ${g_BACONLEXER}
    echo "\"CIPHER\$(\"       printf(\"cipher \");" >> ${g_BACONLEXER}
    echo "\"CMDLINE(\"        printf(\"cmdline \");" >> ${g_BACONLEXER}
    echo "\"CN\$(\"           printf(\"cipher \");" >> ${g_BACONLEXER}
    echo "\"COIL\$(\"         printf(\"append delimengine \");" >> ${g_BACONLEXER}
    echo "\"COLLAPSE\$(\"     printf(\"collapsefunc delimengine \");" >> ${g_BACONLEXER}
    echo "\"COLLECT\"{WS}     printf(\"collect \");" >> ${g_BACONLEXER}
    echo "\"COLUMNS\"         printf(\"screen \");" >> ${g_BACONLEXER}
    echo "\"&\"|\"+\"         printf(\"concat \");" >> ${g_BACONLEXER}
    echo "\"CONCAT\$(\"       printf(\"concat \");" >> ${g_BACONLEXER}
    echo "\"COPY\"{WS}        printf(\"copy \");" >> ${g_BACONLEXER}
    echo "\"COUNT(\"          printf(\"count chrstr \");" >> ${g_BACONLEXER}
    echo "\"CURDIR\$\"        printf(\"curdir \");" >> ${g_BACONLEXER}
    echo "\"CUT\$(\"          printf(\"cut delimengine \");" >> ${g_BACONLEXER}
    echo "\"DAY(\"            printf(\"chrono \");" >> ${g_BACONLEXER}
    echo "\"DEC(\"            printf(\"dec \");" >> ${g_BACONLEXER}
    echo "\"DEL\$(\"          printf(\"delstr delimengine \");" >> ${g_BACONLEXER}
    echo "\"DELIM\$(\"        printf(\"delimstr delimengine \");" >> ${g_BACONLEXER}
    echo "\"DIRNAME\$(\"      printf(\"dirname \");" >> ${g_BACONLEXER}
    echo "\"EDITBOM\$(\"      printf(\"bom \");" >> ${g_BACONLEXER}
    echo "\"ESCAPE\$(\"       printf(\"doescape chrstr \");" >> ${g_BACONLEXER}
    echo "\"EVAL(\"           printf(\"eval \");" >> ${g_BACONLEXER}
    echo "\"EXCHANGE\$(\"     printf(\"exchange delimengine \");" >> ${g_BACONLEXER}
    echo "\"EXEC\$(\"         printf(\"exec delimengine \");" >> ${g_BACONLEXER}
    echo "\"EXPLODE\$(\"      printf(\"explode delimengine \");" >> ${g_BACONLEXER}
    echo "\"EXTRACT\$(\"      printf(\"extract hash \");" >> ${g_BACONLEXER}
    echo "\"FILELEN(\"        printf(\"filelen \");" >> ${g_BACONLEXER}
    echo "\"FILETIME(\"       printf(\"filetime \");" >> ${g_BACONLEXER}
    echo "\"FILETYPE(\"       printf(\"filetype \");" >> ${g_BACONLEXER}
    echo "\"FILL\$(\"         printf(\"fill \");" >> ${g_BACONLEXER}
    echo "\"FIND(\"           printf(\"find \");" >> ${g_BACONLEXER}
    echo "\"FIRST\$(\"        printf(\"first delimengine \");" >> ${g_BACONLEXER}
    echo "\"FLATTEN\$(\"      printf(\"flatten \");" >> ${g_BACONLEXER}
    echo "\"FOR\"{WS}         printf(\"for delimengine \");" >> ${g_BACONLEXER}
    echo "\"GETENVIRON\$(\"   printf(\"getenviron \");" >> ${g_BACONLEXER}
    echo "\"GETFILE\"{WS}     printf(\"getfile \");" >> ${g_BACONLEXER}
    echo "\"GETKEY\"          printf(\"getkey \");" >> ${g_BACONLEXER}
    echo "\"GETLINE\"{WS}     printf(\"getline \");" >> ${g_BACONLEXER}
    echo "\"GETPEER\$(\"      printf(\"getpeer \");" >> ${g_BACONLEXER}
    echo "\"GETX\"            printf(\"getxy \");" >> ${g_BACONLEXER}
    echo "\"GETY\"            printf(\"getxy \");" >> ${g_BACONLEXER}
    echo "\"HASBOM(\"         printf(\"bom \");" >> ${g_BACONLEXER}
    echo "\"HASDELIM(\"       printf(\"hasdelim delimengine \");" >> ${g_BACONLEXER}
    echo "\"HASH(\"           printf(\"hash sortstr sortnr \");" >> ${g_BACONLEXER}
    echo "\"HEAD\$(\"         printf(\"head delimengine \");" >> ${g_BACONLEXER}
    echo "\"HEX\$(\"          printf(\"hex \");" >> ${g_BACONLEXER}
    echo "\"HOST\$(\"         printf(\"host \");" >> ${g_BACONLEXER}
    echo "\"HOSTNAME\$\"      printf(\"hostname \");" >> ${g_BACONLEXER}
    echo "\"HOUR(\"           printf(\"chrono \");" >> ${g_BACONLEXER}
    echo "\"INBETWEEN\$(\"    printf(\"between delimengine \");" >> ${g_BACONLEXER}
    echo "\"INDEX(\"          printf(\"indexarray sortnr sortstr \");" >> ${g_BACONLEXER}
    echo "\"INDEX\$(\"        printf(\"indexassoc hash \");" >> ${g_BACONLEXER}
    echo "\"INPUT\"{WS}       printf(\"input \");" >> ${g_BACONLEXER}
    echo "\"INSERT\$(\"       printf(\"insert \");" >> ${g_BACONLEXER}
    echo "\"INSTR(\"          printf(\"instring \");" >> ${g_BACONLEXER}
    echo "\"INSTRREV(\"       printf(\"instrrev \");" >> ${g_BACONLEXER}
    echo "\"INVERT(\"         printf(\"invert hash \");" >> ${g_BACONLEXER}
    echo "\"ISASCII(\"        printf(\"chrstr \");" >> ${g_BACONLEXER}
    echo "\"ISTOKEN(\"        printf(\"istok delimengine \");" >> ${g_BACONLEXER}
    echo "\"ISUTF8(\"         printf(\"chrstr \");" >> ${g_BACONLEXER}
    echo "\"JOIN\"{WS}        printf(\"join \");" >> ${g_BACONLEXER}
    echo "\"LAST\$(\"         printf(\"last delimengine \");" >> ${g_BACONLEXER}
    echo "\"LCASE\$(\"        printf(\"lcase \");" >> ${g_BACONLEXER}
    echo "\"LEFT\$(\"         printf(\"left \");" >> ${g_BACONLEXER}
    echo "\"LOAD\$(\"         printf(\"load \");" >> ${g_BACONLEXER}
    echo "\"LOOKUP\"{WS}      printf(\"lookup hash sortnr sortstr \");" >> ${g_BACONLEXER}
    echo "\"LOOP\$(\"         printf(\"concat \");" >> ${g_BACONLEXER}
    echo "\"MAKEDIR\"{WS}     printf(\"makedir delimengine \");" >> ${g_BACONLEXER}
    echo "\"MATCH(\"          printf(\"match delimengine \");" >> ${g_BACONLEXER}
    echo "\"MERGE\$(\"        printf(\"merge delimengine \");" >> ${g_BACONLEXER}
    echo "\"MID\$(\"          printf(\"mid \");" >> ${g_BACONLEXER}
    echo "\"MINUTE(\"         printf(\"chrono \");" >> ${g_BACONLEXER}
    echo "\"MONTH(\"          printf(\"chrono \");" >> ${g_BACONLEXER}
    echo "\"MONTH\$(\"        printf(\"datename \");" >> ${g_BACONLEXER}
    echo "\"NANOTIMER\"       printf(\"nano \");" >> ${g_BACONLEXER}
    echo "\"NETWORK\"{WS}     printf(\"network delimengine \");" >> ${g_BACONLEXER}
    echo "\"OBTAIN\$(\"       printf(\"obtain hash sortnr sortstr \");" >> ${g_BACONLEXER}
    echo "\"OS\$\"            printf(\"os \");" >> ${g_BACONLEXER}
    echo "\"OUTBETWEEN\$(\"   printf(\"between delimengine \");" >> ${g_BACONLEXER}
    echo "\"PARSE\"{WS}       printf(\"parse delimengine \");" >> ${g_BACONLEXER}
    echo "\"PEEK(\"           printf(\"peek \");" >> ${g_BACONLEXER}
    echo "\"PROPER\$(\"       printf(\"proper delimengine \");" >> ${g_BACONLEXER}
    echo "\"READLN\"{WS}      printf(\"readln \");" >> ${g_BACONLEXER}
    echo "\"REALPATH\$(\"     printf(\"dirname \");" >> ${g_BACONLEXER}
    echo "\"RECURSIVE\"{WS}   printf(\"recursive \");" >> ${g_BACONLEXER}
    echo "\"REGEX(\"          printf(\"regex hash \");" >> ${g_BACONLEXER}
    echo "\"REPLACE\$(\"      printf(\"replace hash \");" >> ${g_BACONLEXER}
    echo "\"RETURN\"{WS}      printf(\"return \");" >> ${g_BACONLEXER}
    echo "\"REV\$(\"          printf(\"revstr delimengine \");" >> ${g_BACONLEXER}
    echo "\"REVERSE\$(\"      printf(\"reverse \");" >> ${g_BACONLEXER}
    echo "\"RIGHT\$(\"        printf(\"right \");" >> ${g_BACONLEXER}
    echo "\"RIP\$(\"          printf(\"rip \");" >> ${g_BACONLEXER}
    echo "\"ROL(\"            printf(\"binary \");" >> ${g_BACONLEXER}
    echo "\"ROR(\"            printf(\"binary \");" >> ${g_BACONLEXER}
    echo "\"ROTATE\$(\"       printf(\"rotate delimengine \");" >> ${g_BACONLEXER}
    echo "\"ROWS\"            printf(\"screen \");" >> ${g_BACONLEXER}
    echo "\"RUN\$(\"          printf(\"exec \");" >> ${g_BACONLEXER}
    echo "\"SAVE\"{WS}        printf(\"save \");" >> ${g_BACONLEXER}
    echo "\"SEARCH(\"         printf(\"search \");" >> ${g_BACONLEXER}
    echo "\"SECOND(\"         printf(\"chrono \");" >> ${g_BACONLEXER}
    echo "\"SERVER\"{WS}      printf(\"server delimengine \");" >> ${g_BACONLEXER}
    echo "\"SETSERIAL\"{WS}   printf(\"setserial \");" >> ${g_BACONLEXER}
    echo "\"SIGNAL\"{WS}      printf(\"signal \");" >> ${g_BACONLEXER}
    echo "\"SORT\"{WS}        printf(\"sortassoc lookup sortnr sortstr hash \");" >> ${g_BACONLEXER}
    echo "\"SORT\$(\"         printf(\"sortdelim sortstr delimengine \");" >> ${g_BACONLEXER}
    echo "\"SPC\$(\"          printf(\"spc \");" >> ${g_BACONLEXER}
    echo "\"SPLIT\"{WS}       printf(\"split delimengine \");" >> ${g_BACONLEXER}
    echo "\"SUM(\"            printf(\"sum \");" >> ${g_BACONLEXER}
    echo "\"SUMF(\"           printf(\"sum \");" >> ${g_BACONLEXER}
    echo "\"TAB\$(\"          printf(\"tab \");" >> ${g_BACONLEXER}
    echo "\"TAIL\$(\"         printf(\"tail delimengine \");" >> ${g_BACONLEXER}
    echo "\"TALLY(\"          printf(\"tally \");" >> ${g_BACONLEXER}
    echo "\"TIMER\"           printf(\"timer \");" >> ${g_BACONLEXER}
    echo "\"TIMEVALUE(\"      printf(\"epoch \");" >> ${g_BACONLEXER}
    echo "\"TOASCII\$(\"      printf(\"chrstr \");" >> ${g_BACONLEXER}
    echo "\"TOKEN\$(\"        printf(\"token delimengine \");" >> ${g_BACONLEXER}
    echo "\"TOTAL(\"          printf(\"total \");" >> ${g_BACONLEXER}
    echo "\"TRACE\"{WS}       printf(\"getkey \");" >> ${g_BACONLEXER}
    echo "\"TREE\"{WS}        printf(\"tree collect sortnr sortstr \");" >> ${g_BACONLEXER}
    echo "\"UCASE\$(\"        printf(\"ucase \");" >> ${g_BACONLEXER}
    echo "\"UCS(\"            printf(\"chrstr \");" >> ${g_BACONLEXER}
    echo "\"UNESCAPE\$(\"     printf(\"unescape \");" >> ${g_BACONLEXER}
    echo "\"UNFLATTEN\$(\"    printf(\"flatten \");" >> ${g_BACONLEXER}
    echo "\"UNIQ\$(\"         printf(\"uniq obtain delimengine hash sortnr sortstr \");" >> ${g_BACONLEXER}
    echo "\"UTF8\$(\"         printf(\"chrstr \");" >> ${g_BACONLEXER}
    echo "\"WAIT(\"           printf(\"wait \");" >> ${g_BACONLEXER}
    echo "\"WALK\$(\"         printf(\"walk hash \");" >> ${g_BACONLEXER}
    echo "\"WEEK(\"           printf(\"chrono \");" >> ${g_BACONLEXER}
    echo "\"WEEKDAY\$(\"      printf(\"datename \");" >> ${g_BACONLEXER}
    echo "\"WHERE(\"          printf(\"where delimengine \");" >> ${g_BACONLEXER}
    echo "\"YEAR(\"           printf(\"chrono \");" >> ${g_BACONLEXER}
    echo "\\\"                BEGIN(text);" >> ${g_BACONLEXER}
    echo "<text>\\\\          BEGIN(escaped);" >> ${g_BACONLEXER}
    echo "<text>\\\"          BEGIN(INITIAL);" >> ${g_BACONLEXER}
    echo "<text>.             /* Do nothing */" >> ${g_BACONLEXER}
    echo "<escaped>\n\\\"     BEGIN(INITIAL);" >> ${g_BACONLEXER}
    echo "<escaped>\n         /* Do nothing */" >> ${g_BACONLEXER}
    echo "<escaped>.          BEGIN(text);" >> ${g_BACONLEXER}
    echo "\\'                 BEGIN(comment);" >> ${g_BACONLEXER}
    echo "<comment>\n         BEGIN(INITIAL);" >> ${g_BACONLEXER}
    echo "<comment>.          /* Do nothing */" >> ${g_BACONLEXER}
    echo "\"/*\"              BEGIN(multi);" >> ${g_BACONLEXER}
    echo "<multi>[^*]*        /* Eat anything that's not a '*' */" >> ${g_BACONLEXER}
    echo "<multi>\"*\"+[^*/]* /* Eat up '*'s not followed by '/' */" >> ${g_BACONLEXER}
    echo "<multi>\"*\"+\"/\"  BEGIN(INITIAL);" >> ${g_BACONLEXER}
    echo "{WS}                /* Skip whitespace */" >> ${g_BACONLEXER}
    echo ".                   /* Skip anything else */" >> ${g_BACONLEXER}
    echo "<<EOF>>             yyterminate();" >> ${g_BACONLEXER}
    echo "%%" >> ${g_BACONLEXER}
    echo "int main(int argc, char *argv[]) { printf(\"argument error malloc memcheck minmax nano str timer utf8 \"); yylex(); return(0); } int yywrap(void) { return(1); }" >> ${g_BACONLEXER}

    echo -n "Creating lexical analyzer using ${LEX}... "
    ${LEX} -o ${g_BACONLEXER}.c ${g_BACONLEXER}
    ${g_CCNAME} ${g_BACONLEXER}.c -o ${g_BACONLEXER}.exe
    echo "done."

    # Create list of required functions
    TOTAL=$(cat ${g_FEED} | ${g_BACONLEXER}.exe)
    for i in $g_TMP_FILES
    do
        if [[ ${i} = +(*bac) ]]
        then
            TOTAL="${TOTAL} $(cat ${i} | ${g_BACONLEXER}.exe)"
        fi
    done
    TOTAL="$(echo ${TOTAL} | tr '\040' '\012' | sort -u)"
    if [[ ${g_DEBUG} -eq 1 ]]
    then
        echo "Analyzing dependencies... $(echo ${TOTAL} | tr '\012' '\040')"
    fi
    NOLEX=0
    g_TMP_FILES="${g_TMP_FILES} ${g_GENERIC} ${g_FUNCTIONS} ${g_BACONLEXER} ${g_BACONLEXER}.c ${g_BACONLEXER}.exe"
else
    NOLEX=1
    g_TMP_FILES="${g_TMP_FILES} ${g_GENERIC} ${g_FUNCTIONS}"
fi

# Generate functions
echo "/* Created with Shell BaCon $g_VERSION - (c) Peter van Eerten - MIT License */" > $g_FUNCTIONS
echo -e "${g_TWEAK}" >> $g_FUNCTIONS

if [[ ${TOTAL//base64/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "/* Portions of this code based on Bob Trower's C implementation at http://base64.sourceforge.net - MIT licensed */ static const char cd64[]=\"|\$\$\$}rstuvwxyz{\$\$\$\$\$\$\$>?@ABCDEFGHIJKLMNOPQRSTUVW\$\$\$\$\$\$XYZ[\\\\]^_\`abcdefghijklmnopq\";" >> $g_FUNCTIONS
    echo "static const char cb64[]=\"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/\"; static void __b2c__encodeblock( unsigned char *in, unsigned char *out, int len)" >> $g_FUNCTIONS
    echo "{ out[0] = (unsigned char) cb64[ (int)(in[0] >> 2) ]; out[1] = (unsigned char) cb64[ (int)(((in[0] & 0x03) << 4) | ((in[1] & 0xf0) >> 4)) ];" >> $g_FUNCTIONS
    echo "out[2] = (unsigned char) (len > 1 ? cb64[ (int)(((in[1] & 0x0f) << 2) | ((in[2] & 0xc0) >> 6)) ] : '='); out[3] = (unsigned char) (len > 2 ? cb64[ (int)(in[2] & 0x3f) ] : '='); }" >> $g_FUNCTIONS
    echo "char * __b2c__b64enc (char* src, int len) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned char in[4], out[4]; int i, j, cur = 0, posit = 0; if (src == NULL) { return(NULL); }" >> $g_FUNCTIONS
    echo "if (len == 0) { len = __b2c__len (src); } if (len == 0) { return (NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], ((len + 2) / 3) * 4 + 1);" >> $g_FUNCTIONS
    echo "while( cur < len ){ for( i = 0; i < 3 && (cur + i < len); i++ ){ in[i] = (unsigned char) src[cur+i]; } in[i] = 0; cur += i; if( i > 0 ) { __b2c__encodeblock( in, out, i );" >> $g_FUNCTIONS
    echo "for( j = 0; j < 4; j++ ) { buf[idx][posit+j] = out[j]; } posit += 4; } } buf[idx][posit] = '\0'; __b2c__SETLEN (buf[idx], posit); return(char*)(buf[idx]); }" >> $g_FUNCTIONS
    echo "static void __b2c__decodeblock(unsigned char in[4], unsigned char out[3]) { out[0] = (unsigned char ) (in[0] << 2 | in[1] >> 4); out[1] = (unsigned char)(in[1] << 4 | in[2] >> 2);" >> $g_FUNCTIONS
    echo "out[2] = (unsigned char ) (((in[2] << 6) & 0xc0) | in[3]); }" >> $g_FUNCTIONS
    echo "char *__b2c__b64dec(int l, char *k, char *src) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned char in[4], out[3], v; int i = 0, stlen, dec_len, len, cur = 0, posit = 0; if(src == NULL){ return (NULL); }" >> $g_FUNCTIONS
    echo "stlen = __b2c__len (src); if (stlen == 0) { return (NULL); } if(stlen % 4) { ERROR = 5; RUNTIMEFERR (\"B64DEC$\", ERROR, k, l); return(NULL); } dec_len = 3*stlen/4; while(src[stlen+i-1] == 61) { dec_len--; i--; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], dec_len + 4); while(cur < stlen){ for (len = 0, i = 0; i < 4 && (cur < stlen); i++) { v = 0; while (cur < stlen && v == 0){ v = (unsigned char) src[cur]; cur++; v = (unsigned char) ((v < 43 || v > 122) ? 0 : cd64[ v - 43 ]);" >> $g_FUNCTIONS
    echo "if (v) {v = (unsigned char) ((v == '$') ? 0 : v - 61);} } if(cur <= stlen){ len++; if (v) { in[i] = (unsigned char)(v - 1); } else { in[i] = 0; } } } if(len){ __b2c__decodeblock(in, out);" >> $g_FUNCTIONS
    echo "for(i = 0; i < len - 1; i++) { buf[idx][posit + i] = out[i]; } buf[idx][posit + i] = '\0'; posit += len - 1; } } __b2c__SETLEN(buf[idx], dec_len); return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//binary/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "unsigned long __b2c__bit(long x) { return(x ? 2<<(x-1) : 1); } unsigned long __b2c__rol(int type, long x)" >> $g_FUNCTIONS
    echo "{ return((x)&lrint(pow(2, type*8-1)) ? (((x)<<1)|1)&lrint(pow(2, type*8)-1) : ((x)<<1)&lrint(pow(2, type*8)-1)); }" >> $g_FUNCTIONS
    echo "unsigned long __b2c__ror(int type, long x) { return((x)&1 ? (((x)>>1)&lrint(pow(2, type*8)-1))|lrint(pow(2, type*8-1)) : ((x)>>1)&lrint(pow(2, type*8)-1)); }" >> $g_FUNCTIONS
    echo "char *__b2c__bin(int type, long x) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long i; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], type*8+1); for(i = 0; i<type*8; i++) { if(x&1) { buf[idx][type*8-1-i] = 49; } else { buf[idx][type*8-1-i] = 48; }" >> $g_FUNCTIONS
    echo "x = x>>1; } buf[idx][type*8] = '\0'; __b2c__SETLEN(buf[idx], type*8); return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//chop/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__chop(char **swap, int type, char *source, char *string, int location) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *tmp; long length; if (source == NULL || *source == '\0') { if (type == 1) { *swap = __b2c_Copy_String(*swap, NULL); } return (NULL); } if (string == NULL) { string = (char *) __b2c__chop_default; }" >> $g_FUNCTIONS
    echo "idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } length = __b2c__len(string); if (location == 0 || location == 1) { while (*source != '\0') { if(memchr(string, *source, length)) { source++; } else { break; } } if (*source == '\0'){ if (type == 1) { *swap = __b2c_Copy_String (*swap, NULL); } return(NULL); } } tmp = source + __b2c__len(source) - 1;" >> $g_FUNCTIONS
    echo "if(location == 0 || location == 2) { while (tmp >= source && *tmp != '\0') { if(memchr(string, *tmp, length)) { tmp--; } else { break; } } } tmp++; buf[idx] = (char*)__b2c_str_realloc(buf[idx], tmp-source+1); memmove(buf[idx], source, tmp - source);" >> $g_FUNCTIONS
    echo "__b2c__SETLEN(buf[idx], tmp - source); buf[idx][tmp - source] = '\0'; if (type == 1) { return(__b2c_Swap_String(swap, &buf[idx])); } return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//chrstr/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__asc2char (int i) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], 2); len = snprintf(buf[idx], 2, \"%c\", i); __b2c__SETLEN(buf[idx], len); return(char*)(buf[idx]); }" >> $g_FUNCTIONS
    echo "char *__b2c__asc2utf8 (int i) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len; char buffer[5]; len = __b2c_utf8_conv(i, buffer); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1); memcpy(buf[idx], buffer, len); __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
    echo "unsigned int __b2c__utf8toasc(char* ptr) { unsigned int result = 0; if((*ptr&0xF0)==0xF0) { result = (*ptr&0x07)<<2; ptr++; result = result | ((*ptr&0x30)>>4); result = result << 8; result = result | ((*ptr&0x0F)<<4);" >> $g_FUNCTIONS
    echo "ptr++; result = result | ((*ptr&0x3C)>>2); result = result << 8; result = result | ((*ptr&0x03)<<6); ptr++; result = result | (*ptr&0x3F); } else if((*ptr&0xE0)==0xE0) { result = (*ptr&0x0F)<<4; ptr++;" >> $g_FUNCTIONS
    echo "result = result | ((*ptr&0x3C)>>2); result = result << 8; result = result | ((*ptr&0x03)<<6); ptr++; result = result | (*ptr&0x3F); } else if((*ptr&0xC0)==0xC0) { result = (*ptr&0x1C)>>2; result = result << 8;" >> $g_FUNCTIONS
    echo "result = result | ((*ptr&0x03)<<6); ptr++; result = result | (*ptr&0x3F); } else if((*ptr&0x80) == 0) { result = (*ptr&0x7F); } return (result); }" >> $g_FUNCTIONS
    echo "unsigned char __b2c__isascii(const char *ptr) { long x; for(x=0; *(ptr+x); x++) { if(*(ptr+x)&128) return(0); } return(1); }" >> $g_FUNCTIONS
    echo "unsigned char __b2c__isutf8(const char *ptr) { int result = 1; if (ptr == NULL) { return (0); } while (*ptr) { if ((*ptr & 0xF0) == 0xF0)" >> $g_FUNCTIONS
    echo "{ if ((*(ptr + 1) & 0xC0) != 0x80 || (*(ptr + 2) & 0xc0) != 0x80 || (*(ptr + 3) & 0xc0) != 0x80 ) { result = 0; break; } ptr += 4; } else if ((*ptr & 0xE0) == 0xE0)" >> $g_FUNCTIONS
    echo "{ if ((*(ptr + 1) & 0xc0) != 0x80 || (*(ptr + 2) & 0xc0) != 0x80 ) { result = 0; break; } ptr += 3; } else if ((*ptr & 0xC0) == 0xC0) { if ((*(ptr + 1) & 0xc0) != 0x80 )" >> $g_FUNCTIONS
    echo "{ result = 0; break; } ptr += 2; } else if ((*ptr & 0x80) == 0) { ptr++; } else { result = 0; break; } } return (result); }" >> $g_FUNCTIONS
    echo "char *__b2c__toascii(char *ptr) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len, x; len = __b2c__len (ptr); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], len); for(x = 0; x < len; x++) { *(buf[idx] + x) = *(ptr + x) & 0x7f; } __b2c__SETLEN (buf[idx], len); buf[idx][len] = '\0'; return((char*)buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//cmdline/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c__getopt(int argc, char **argv, char* str){int opt; extern char *optarg; extern int optind, opterr; opterr = 0; opt = getopt(argc, argv, str); if(opt != -1)" >> $g_FUNCTIONS
    echo "{ ARGUMENT${g_STRINGSIGN} = __b2c_Copy_String(ARGUMENT${g_STRINGSIGN}, optarg); } else { ARGUMENT${g_STRINGSIGN} = __b2c_Copy_String(ARGUMENT${g_STRINGSIGN}, argv[optind]); } return(opt); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//concat/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__concat(int n, ...) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long length = 0, buflen = 0, cnew; char *next; va_list ap; if (n == 0) { return (NULL); } idx++;" >> $g_FUNCTIONS
    echo "if (idx == __b2c_STRING_FUNC) { idx = 0; } va_start (ap, n); if(buf[idx]) { buflen = __b2c__RBUFSIZE(buf[idx]); } while (n) { next = va_arg (ap, char *); if (next) { cnew = __b2c__len (next);" >> $g_FUNCTIONS
    echo "if(length+cnew >= buflen) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + cnew); buflen = __b2c__RBUFSIZE(buf[idx]); } memcpy(buf[idx] + length, next, cnew); length += cnew; }" >> $g_FUNCTIONS
    echo "n--; } va_end (ap); if (buf[idx]) { __b2c__SETLEN (buf[idx], length); buf[idx][length] = '\0'; } return ((char *) buf[idx]); }" >> $g_FUNCTIONS
    echo "char *__b2c__concat2(int total, ...) { char *iter, *result, *first, *next, *offset; int n_copy = 0, pos = 0, length = 0, cnew, flen = 0, stage = 0; uint32_t lbufsize = 0, rbufsize = 0; va_list ap_copy, ap; va_start (ap, total);" >> $g_FUNCTIONS
    echo "first = result = offset = va_arg (ap, char *); total--; if (total == 0) { return (NULL); } va_copy (ap_copy, ap); if(first) { n_copy = total; } while (n_copy) { iter = va_arg (ap_copy, char *); if (iter == first) { flen = __b2c__len (first); break; }" >> $g_FUNCTIONS
    echo "pos += __b2c__len (iter); n_copy--; } va_end (ap_copy); if (__b2c_str_realloc_get_string(result) ) { lbufsize = __b2c__LBUFSIZE (result); rbufsize = __b2c__RBUFSIZE (result); }" >> $g_FUNCTIONS
    echo "else { rbufsize = __b2c__len(first); } if (n_copy) { if (pos >= lbufsize) { result = (char *) __b2c_str_realloc_left(result, lbufsize + rbufsize + pos); offset = result; } __b2c_str_realloc_del_string(result);" >> $g_FUNCTIONS
    echo "memmove (result - __b2c__BUFOFFSET - pos, result - __b2c__BUFOFFSET, __b2c__BUFOFFSET); result -= pos; __b2c_str_realloc_add_string(result); __b2c__LBUFSIZE (result) -= pos; __b2c__RBUFSIZE (result) += pos;" >> $g_FUNCTIONS
    echo "rbufsize = __b2c__RBUFSIZE (result); } next = va_arg (ap, char *); total--; while (total >= 0) { if (next) { if (next == first) { cnew = flen; } else { cnew = __b2c__len (next); } if (cnew + flen + length >= rbufsize)" >> $g_FUNCTIONS
    echo "{ result = (char *) __b2c_str_realloc (result, cnew + flen + length); rbufsize = __b2c__RBUFSIZE (result); offset = result + pos; } if (next != first) { memmove (result + length, next, cnew); } else { if (stage == 0) { stage = 1; } else" >> $g_FUNCTIONS
    echo "{ memmove (result + length, offset, cnew); } } length += cnew; } next = va_arg (ap, char *); total--; } va_end (ap); if(result) { __b2c__SETLEN (result, length); result[length] = '\0'; } return ((char *) result); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//count/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "long __b2c__count (int l, char *k, char *x, unsigned int y) { long i, z = 0; if (__b2c__option_utf8) { while (*x) { if (__b2c__utf8toasc (x) == y) { z++; } if ((*x & 0xF0) == 0xF0) { x += 4; }" >> $g_FUNCTIONS
    echo "else if ((*x & 0xE0) == 0xE0) { x += 3; } else if ((*x & 0xC0) == 0xC0) { x += 2; } else if ((*x & 0x80) == 0) { x++; } else { ERROR = 38; RUNTIMEFERR (\"COUNT\", ERROR, k, l); return(0); } } } else " >> $g_FUNCTIONS
    echo "{ for (i = 0; x[i] != '\0'; i++) { if (x[i] == y) { z++; } } } return z; }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//curdir/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__curdir (void) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], ${g_BUFFER_SIZE});" >> $g_FUNCTIONS
    echo "buf[idx] = getcwd(buf[idx], ${g_BUFFER_SIZE}); __b2c__SETLEN(buf[idx], strlen(buf[idx])); buf[idx][${g_BUFFER_SIZE}-1] = '\\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//datename/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char* __b2c__datename(time_t now, int which) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; struct tm *ts; int len = 0; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], ${g_MAX_DIGITS}); ts = localtime (&now); switch (which) { case 1: len = strftime(buf[idx], ${g_MAX_DIGITS}, \"%A\", ts); break;" >> $g_FUNCTIONS
    echo "case 2: len = strftime(buf[idx], ${g_MAX_DIGITS}, \"%B\", ts); break; } __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//dec/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "uint64_t __b2c__hex2dec (int l, char *k, char *h, int flag) { uint64_t j=0; char *status = NULL; if(h == NULL) { return(0); } if(flag == 1) { flag = 2; } else if(flag > 36) {ERROR = 5; RUNTIMEFERR (\"DEC\", ERROR, k, l); return(0); }" >> $g_FUNCTIONS
    echo "if(flag == 0) { j = strtol(h, &status, 16); if(*status != '\0' && __b2c__trap) { ERROR = 5; RUNTIMEFERR (\"DEC\", ERROR, k, l); return(0); } } else { j = strtol(h, &status, flag);" >> $g_FUNCTIONS
    echo "if(*status != '\0') { ERROR = 5; RUNTIMEFERR (\"DEC\", ERROR, k, l); return(0); } } return(uint64_t)(j); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//dirname/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "#ifndef PATH_MAX" >> $g_FUNCTIONS
    echo "#define PATH_MAX 4096" >> $g_FUNCTIONS
    echo "#endif" >> $g_FUNCTIONS
    echo "char *__b2c__dirname(int l, char *k, int x, char *y, long arg) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long i; char *dup; if(y == NULL || __b2c__len(y) == 0){ return(NULL); }" >> $g_FUNCTIONS
    echo "idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], PATH_MAX*sizeof(char)); dup = __b2c__strdup(y); switch(x) {case 0: if ((realpath(y, buf[idx])) == NULL) { if (__b2c__trap) { ERROR = 26; RUNTIMEFERR(\"REALPATH$\", ERROR, k, l); return(NULL); }" >> $g_FUNCTIONS
    echo "else strncpy(buf[idx], \"Error getting real path\", ${g_BUFFER_SIZE}); } break; case 1: if(strncpy(buf[idx], basename(dup), PATH_MAX) == NULL) {if (__b2c__trap) { ERROR = 26; RUNTIMEFERR(\"BASENAME$\", ERROR, k, l); return(NULL); } else strncpy (buf[idx], \"Error getting basename\", ${g_BUFFER_SIZE});}" >> $g_FUNCTIONS
    echo "break; case 2: if (strncpy(buf[idx], dirname(dup), PATH_MAX) == NULL) {if(__b2c__trap) { ERROR = 26; RUNTIMEFERR(\"DIRNAME$\", ERROR, k, l); return(NULL); } else strncpy(buf[idx], \"Error getting dirname\", ${g_BUFFER_SIZE});" >> $g_FUNCTIONS
    echo "} break;} __b2c__STRFREE(dup); __b2c__SETLEN(buf[idx], strlen(buf[idx])); buf[idx][PATH_MAX - 1] = '\0'; if(arg && x==1){ for(i=__b2c__len(buf[idx]); i>=0; i--) { if(buf[idx][i] == 46) break; }" >> $g_FUNCTIONS
    echo "if(i >= 0){ if(arg == 1) { buf[idx][i] = '\\0'; __b2c__SETLEN(buf[idx], i);} if(arg == 2){ i++; memmove(buf[idx], buf[idx]+i, __b2c__len(buf[idx])-i+1);" >> $g_FUNCTIONS
    echo "__b2c__SETLEN(buf[idx], __b2c__len(buf[idx])-i);} } else if(arg == 2) {buf[idx][0] = '\0'; __b2c__SETLEN(buf[idx], 0);} } return(char*)(buf[idx]);}" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//epoch/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "unsigned long __b2c__epoch(int year, int month, int day, int hour, int minute, int second){struct tm tm; time_t t; tm.tm_year = year - 1900; tm.tm_mon = month - 1; tm.tm_mday = day;" >> $g_FUNCTIONS
    echo "tm.tm_hour = hour; tm.tm_min = minute; tm.tm_sec = second; tm.tm_isdst = -1; t = mktime(&tm); if (t == -1) return (0); return(long) t; }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//error/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char * ERR${g_STRINGSIGN}(int nr) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long flen = 0, slen = 0; char *first = NULL, *second = NULL; switch (nr)" >> $g_FUNCTIONS
    echo "{ case 0: first = \"Success\"; break; case 1: first = \"Trying to access illegal memory: \"; second = strerror(errno); break;" >> $g_FUNCTIONS
    echo "case 2: first = \"Error opening file: \"; second = strerror (errno); break; case 3: first = \"Could not open library.\"; break;" >> $g_FUNCTIONS
    echo "case 4: first = \"Symbol not found in library.\"; break; case 5: first = \"Wrong value: \"; second = strerror(errno); break;" >> $g_FUNCTIONS
    echo "case 6: first = \"Unable to claim memory.\"; break; case 7: first = \"Unable to delete file: \"; second = strerror(errno); break;" >> $g_FUNCTIONS
    echo "case 8: first = \"Could not open directory: \"; second = strerror(errno); break; case 9: first = \"Unable to rename file: \"; second = strerror(errno); break;" >> $g_FUNCTIONS
    echo "case 10: first = \"NETWORK argument should contain colon with port number\"; break; case 11: first = \"Could not resolve hostname!\"; break;" >> $g_FUNCTIONS
    echo "case 12: first = \"Socket error: \"; second = strerror(errno); break; case 13: first = \"Unable to open address: \"; second = strerror(errno); break;" >> $g_FUNCTIONS
    echo "case 14: first = \"Error reading from socket: \"; second = strerror(errno); break; case 15: first = \"Error sending to socket: \"; second = strerror(errno); break;" >> $g_FUNCTIONS
    echo "case 16: first = \"Error checking socket: \"; second = strerror(errno); break; case 17: first = \"Unable to bind the specified socket address: \"; second = strerror(errno); break;" >> $g_FUNCTIONS
    echo "case 18: first = \"Unable to listen to socket address: \"; second = strerror(errno); break; case 19: first = \"Cannot accept incoming connection: \"; second = strerror(errno); break;" >> $g_FUNCTIONS
    echo "case 20: first = \"Unable to remove directory: \"; second = strerror(errno); break; case 21: first = \"Unable to create directory: \"; second = strerror(errno); break;" >> $g_FUNCTIONS
    echo "case 22: first = \"Unable to change to directory: \"; second = strerror(errno); break; case 23: first = \"GETENVIRON argument does not exist as environment variable\"; break;" >> $g_FUNCTIONS
    echo "case 24: first = \"Unable to stat file: \"; second = strerror(errno); break; case 25: first = \"Search contains illegal string\"; break;" >> $g_FUNCTIONS
    echo "case 26: first = \"Cannot return name: \"; second = strerror(errno); break; case 27: first = \"Illegal regex expression\"; break;" >> $g_FUNCTIONS
    echo "case 28: first = \"Unable to create bidirectional pipes: \"; second = strerror(errno); break; case 29: first = \"Unable to fork process: \"; second = strerror(errno); break;" >> $g_FUNCTIONS
    echo "case 30: first = \"Cannot read from pipe: \"; second = strerror(errno); break; case 31: first = \"Gosub nesting too deep!\"; break;" >> $g_FUNCTIONS
    echo "case 32: first = \"Could not open device: \"; second = strerror(errno); break; case 33: first = \"Error configuring serial port: \"; second = strerror(errno); break;" >> $g_FUNCTIONS
    echo "case 34: first = \"Error accessing device: \"; second = strerror(errno); break; case 35: first = \"Error in INPUT: \"; second = strerror(errno); break;" >> $g_FUNCTIONS
    echo "case 36: first = \"Illegal value in SORT dimension!\"; break; case 37: first = \"Illegal option for SEARCH!\"; break;" >> $g_FUNCTIONS
    echo "case 38: first = \"Invalid UTF8 string!\"; break; case 39: first = \"Illegal EVAL expression!\"; break;" >> $g_FUNCTIONS
    echo "case 40: first = \"SSL file descriptor error!\"; break; case 41: first = \"Error loading certificate!\"; break;" >> $g_FUNCTIONS
    echo "case 42: first = \"Widget not found!\"; ERROR = 42; break; case 43: first = \"Unsupported array type!\"; break; };" >> $g_FUNCTIONS
    echo "if(first) { flen = strlen(first); } if(second) { slen = strlen(second); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], flen+slen+1);if(first)" >> $g_FUNCTIONS
    echo "{ memmove(buf[idx], first, flen); } if(second) { memmove(buf[idx]+flen, second, slen); } __b2c__SETLEN(buf[idx], flen+slen); buf[idx][flen+slen] = '\0'; return((char*)buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//exec/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "static char **__b2c__Get_Args(char *line) { char **ptr = NULL; long start, x, collapse; long length = 0, amount = 0; collapse = __b2c__collapse; __b2c__collapse = 1; start = __b2c__delim_engine (2, &amount, line, \" \", 0); ptr = (char**)calloc(amount, sizeof(char*));" >> $g_FUNCTIONS
    echo "for(x = 0; x < amount; x++) { start = __b2c__delim_engine_cache (1, &length, line, \" \", x + 1); ptr[x] = __b2c__strndup(line+start, length); } ptr[x] = NULL; __b2c__collapse = collapse; return (ptr); }" >> $g_FUNCTIONS
    echo "char * __b2c__exec(int t, int l, char *k, char *cmd, char *str, int out) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int forking, length, dnull; ssize_t result = 0; int wpipe[2], rpipe[2]; char **args; char *ans = NULL;" >> $g_FUNCTIONS
    echo "idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], sizeof(char)); if (pipe (rpipe) < 0 || pipe (wpipe) < 0) { if (__b2c__trap) { ERROR = 29; RUNTIMEFERR(\"EXEC$\", ERROR, k, l); return(NULL); } } if ((forking = fork ()) < 0) { if (__b2c__trap) { ERROR = 29; RUNTIMEFERR(\"EXEC$\", ERROR, k, l); return(NULL); } }" >> $g_FUNCTIONS
    echo "else if (forking == 0) { fflush(stdout); close (wpipe[1]); close (rpipe[0]); dup2 (wpipe[0], STDIN_FILENO); close (wpipe[0]);	dnull = open(\"/dev/null\", O_RDWR); if(out == 1) { dup2 (rpipe[1], STDOUT_FILENO); dup2(dnull, STDERR_FILENO); } else if (out == 2) { dup2(dnull, STDOUT_FILENO);" >> $g_FUNCTIONS
    echo "dup2(rpipe[1], STDERR_FILENO); } else { dup2(rpipe[1], STDOUT_FILENO); dup2(rpipe[1], STDERR_FILENO); } close (rpipe[1]); if(t == 0) { forking = system (cmd); if (WIFEXITED (forking)) result = WEXITSTATUS (forking); }" >> $g_FUNCTIONS
    echo "else { args = __b2c__Get_Args(cmd); if(execvp(args[0], args) < 0 ) { if (__b2c__trap) { ERROR = 29; RUNTIMEFERR (\"EXEC$\", ERROR, k, l); return(NULL); } } } close(dnull); __b2c_str_free(); _exit(result); } else { close (wpipe[0]); close (rpipe[1]); ans = (char*)malloc(${g_BUFFER_SIZE});" >> $g_FUNCTIONS
    echo "length = 0; if (str != NULL) result = write (wpipe[1], str, __b2c__len(str)); close (wpipe[1]); do { result = read (rpipe[0], ans, ${g_BUFFER_SIZE}); if (result == -1 && __b2c__trap) { ERROR = 30; RUNTIMEFERR(\"EXEC$\", ERROR, k, l); return(NULL); }" >> $g_FUNCTIONS
    echo "if (result == 0) { break; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], length + result + 1); if (buf[idx] == NULL && __b2c__trap) { ERROR = 6; RUNTIMEFERR(\"EXEC$\", ERROR, k, l); return(NULL); }" >> $g_FUNCTIONS
    echo "memcpy(buf[idx] + length, ans, (size_t)labs(result)); length += result; } while (result > 0); __b2c__SETLEN(buf[idx], length); buf[idx][length] = '\0';" >> $g_FUNCTIONS
    echo "close (rpipe[0]); free (ans); wait (&RETVAL); RETVAL = WEXITSTATUS (RETVAL); } return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//filelen/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "long __b2c__filelen(int l, char *k, const char *x) {struct stat buf; if(stat(x, &buf) < 0 && __b2c__trap){ERROR = 24; RUNTIMEFERR(\"FILELEN\", ERROR, k, l); return(0); }" >> $g_FUNCTIONS
    echo "if(x == NULL || stat(x, &buf) < 0) return -1; else return(long)(buf.st_size);}" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//filetime/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "long __b2c__filetime(int l, char *k, const char *x, int y) {struct stat buf; if(stat(x, &buf) < 0 && __b2c__trap){ERROR = 24; RUNTIMEFERR(\"FILETIME\", ERROR, k, l); return(0); }" >> $g_FUNCTIONS
    echo "if(x == NULL || stat(x, &buf) < 0 || y < 0 || y > 2) { return -1; } switch(y) {case 0: return(long)(buf.st_atime); break;" >> $g_FUNCTIONS
    echo "case 1: return(long)(buf.st_mtime); break;} return(long)(buf.st_ctime);}" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//filetype/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c__filetype(int l, char *k, const char *file) { int type = 0; struct stat buf = { 0 }; if(file == NULL) { return(0); } if(lstat (file, &buf) < 0 && __b2c__trap) { ERROR = 24; RUNTIMEFERR (\"FILETYPE\", ERROR, k, l); return(0); }" >> $g_FUNCTIONS
    echo "switch (buf.st_mode & S_IFMT) { case S_IFBLK: type = 4; break; case S_IFCHR: type = 3; break; case S_IFDIR: type = 2; break; case S_IFIFO: type = 5; break; case S_IFLNK: type = 6; break;" >> $g_FUNCTIONS
    echo "case S_IFREG: type = 1; break; case S_IFSOCK: type = 7; break; default: if(__b2c__trap) { ERROR = 24; RUNTIMEFERR(\"FILETYPE\", ERROR, k, l); return(0); } break; } return(type); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//fill/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char * __b2c__fill (unsigned long amount, unsigned int txt) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char bf[5]; int x, len; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } if (__b2c__option_utf8) { len = __b2c_utf8_conv (txt, bf);" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], amount*len+1); for (x = 0; x < (amount * len); x += len) { memcpy(buf[idx] + x, bf, len); } __b2c__SETLEN(buf[idx], amount * len); buf[idx][amount * len] = '\0'; } else" >> $g_FUNCTIONS
    echo "{ buf[idx] = (char*)__b2c_str_realloc(buf[idx], amount+1); memset(buf[idx], txt, amount); __b2c__SETLEN(buf[idx], amount); buf[idx][amount] = '\0'; } return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//flatten/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__flatten(char *src, char *meta) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char quote[1]; long len, x, pos=0, escaped=0; quote[0] = __b2c__option_dq; if(src == NULL) { return(src); }" >> $g_FUNCTIONS
    echo "if (meta == NULL) { meta = quote; } len = __b2c__len(src); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1);" >> $g_FUNCTIONS
    echo "memmove(buf[idx], src, len); buf[idx][len] = '\\0'; for(x = 0; src[x] != 0; x++) { if(src[x] == meta[0]) { if(!escaped) { memmove(buf[idx]+pos, src+x+1, len-x-1); }" >> $g_FUNCTIONS
    echo "else { pos++; escaped = 0; } } else { if(src[x] == __b2c__option_esc) { if(!escaped) { memmove(buf[idx]+pos, src+x+1, len-x-1); escaped = 1; } else { pos++; } }" >> $g_FUNCTIONS
    echo "else { pos++; escaped = 0; } } } __b2c__SETLEN(buf[idx], pos); buf[idx][pos] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
    echo "char * __b2c__unflatten (char *src, char *meta) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char quote[1]; long x, pos = 1; quote[0] = __b2c__option_dq; if (src == NULL) { return (src); }" >> $g_FUNCTIONS
    echo "if (meta == NULL) { meta = quote; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], 2*__b2c__len(src)+1); buf[idx][0] = meta[0];" >> $g_FUNCTIONS
    echo "for (x = 0; src[x] != 0; x++) { if (src[x] == meta[0]) { buf[idx][pos++] = __b2c__option_esc; buf[idx][pos++] = src[x]; } else {buf[idx][pos++] = src[x];} } buf[idx][pos++] = meta[0];" >> $g_FUNCTIONS
    echo "__b2c__SETLEN(buf[idx], pos); buf[idx][pos] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//getenviron/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__getenv (char *env) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *result; long len; result = getenv (env); if(result == NULL) { return(NULL); } len = strlen(result); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], (len+1)*sizeof(char)); strncpy(buf[idx], result, len); __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//getkey/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "long __b2c__getch(void){long ch; struct termios oldt, newt; tcflush(STDIN_FILENO, TCIFLUSH); tcgetattr(STDIN_FILENO, &oldt); newt = oldt; newt.c_lflag &= ~(ICANON | ECHO); newt.c_cc[VMIN]=1;" >> $g_FUNCTIONS
    echo "newt.c_cc[VTIME]=0; tcsetattr(STDIN_FILENO, TCSANOW, &newt); ch = getchar(); tcsetattr(STDIN_FILENO, TCSANOW, &oldt); return(ch);}" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//getpeer/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    if [[ `uname` = "OSF1" ]]
    then
        LEN="int"
    else
        LEN="unsigned int"
    fi
    echo "char * __b2c__getpeer(int l, char *k, uintptr_t remote) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; struct sockaddr_in *peer; ${LEN} length = sizeof (peer); char port[6]; int desc = 0; peer = (struct sockaddr_in*)calloc(1, sizeof(*peer));" >> $g_FUNCTIONS
    if [[ ${g_OPTION_TLS} = +(1*|TRUE*) ]]
    then
        if [[ ${g_LIB_TLS} = +(*gnutls*) ]]
        then
            echo "if(__b2c__option_tls) { BIO_get_fd(((SSL*)remote)->gnutls_state, &desc); }" >> $g_FUNCTIONS
        else
            echo "if(__b2c__option_tls) { desc = SSL_get_fd((SSL*)remote); }" >> $g_FUNCTIONS
        fi
    fi
    echo "if(!__b2c__option_tls) { desc = remote; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], ${g_BUFFER_SIZE}*sizeof(char));" >> $g_FUNCTIONS
    echo "if (getpeername(desc, (struct sockaddr *) peer, &length) < 0) { if (__b2c__trap) { ERROR = 16; RUNTIMEFERR(\"GETPEER$\", ERROR, k, l); return(NULL); } else strncpy(buf[idx], \"Peer not found\", ${g_BUFFER_SIZE}); }" >> $g_FUNCTIONS
    echo "else { strncpy(buf[idx], inet_ntoa (peer->sin_addr),  ${g_BUFFER_SIZE} - 7); strcat(buf[idx], \":\"); snprintf (port, 6, \"%d\", ntohs (peer->sin_port)); strcat(buf[idx], port); }" >> $g_FUNCTIONS
    echo "free (peer); __b2c__SETLEN(buf[idx], strlen(buf[idx])); buf[idx][ ${g_BUFFER_SIZE} - 1] = '\0'; return(char*)(buf[idx]);}" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//getxy/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "long __b2c__getxy(int type){char asw[$g_BUFFER_SIZE]; struct termios old, cnew; int len, x = 0, y = 0; tcgetattr(STDIN_FILENO, &old); cnew = old; cnew.c_lflag &= ~(ICANON | ECHO); tcsetattr(STDIN_FILENO, TCSANOW, &cnew);" >> $g_FUNCTIONS
    echo "if(write(STDOUT_FILENO, \"\033[6n\", 4)>=0){len = read(STDIN_FILENO, asw, $g_BUFFER_SIZE); asw[len] = '\0'; tcsetattr(STDIN_FILENO, TCSANOW, &old); sscanf(asw, \"\033[%d;%dR\", &y, &x);} if (!type) return(long)x; return(long)y;}" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//sortnr/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c__sortnrd(const void *a, const void *b) {if (*(double*)a==*(double*)b) return(0); else if (*(double*)a < *(double*)b) return(-1); else return(1);}" >> $g_FUNCTIONS
    echo "int __b2c__sortnrd_wrap(const void *a, const void *b) { return(__b2c__sortnrd(*(void**)a, *(void**)b)); }" >> $g_FUNCTIONS
    echo "int __b2c__sortnrd_down(const void *a, const void *b) {if (*(double*)a==*(double*)b) return(0); else if (*(double*)a < *(double*)b) return(1); else return(-1);}" >> $g_FUNCTIONS
    echo "int __b2c__sortnrd_wrap_down(const void *a, const void *b) { return(__b2c__sortnrd_down(*(void**)a, *(void**)b)); }" >> $g_FUNCTIONS
    echo "int __b2c__sortnrf(const void *a, const void *b) {if (*(float*)a==*(float*)b) return(0); else if (*(float*)a < *(float*)b) return(-1); else return(1);}" >> $g_FUNCTIONS
    echo "int __b2c__sortnrf_wrap(const void *a, const void *b) { return(__b2c__sortnrf(*(void**)a, *(void**)b)); }" >> $g_FUNCTIONS
    echo "int __b2c__sortnrf_down(const void *a, const void *b) {if (*(float*)a==*(float*)b) return(0); else if (*(float*)a < *(float*)b) return(1); else return(-1);}" >> $g_FUNCTIONS
    echo "int __b2c__sortnrf_wrap_down(const void *a, const void *b) { return(__b2c__sortnrf_down(*(void**)a, *(void**)b)); }" >> $g_FUNCTIONS
    echo "int __b2c__sortnrl(const void *a, const void *b) {if (*(long*)a==*(long*)b) return(0); else if (*(long*)a < *(long*)b) return(-1); else return(1);}" >> $g_FUNCTIONS
    echo "int __b2c__sortnrl_wrap(const void *a, const void *b) { return(__b2c__sortnrl(*(void**)a, *(void**)b)); }" >> $g_FUNCTIONS
    echo "int __b2c__sortnrl_down(const void *a, const void *b) {if (*(long*)a==*(long*)b) return(0); else if (*(long*)a < *(long*)b) return(1); else return(-1);}" >> $g_FUNCTIONS
    echo "int __b2c__sortnrl_wrap_down(const void *a, const void *b) { return(__b2c__sortnrl_down(*(void**)a, *(void**)b)); }" >> $g_FUNCTIONS
    echo "int __b2c__sortnri(const void *a, const void *b) {if (*(int*)a==*(int*)b) return(0); else if (*(int*)a < *(int*)b) return(-1); else return(1);}" >> $g_FUNCTIONS
    echo "int __b2c__sortnri_wrap(const void *a, const void *b) { return(__b2c__sortnri(*(void**)a, *(void**)b)); }" >> $g_FUNCTIONS
    echo "int __b2c__sortnri_down(const void *a, const void *b) {if (*(int*)a==*(int*)b) return(0); else if (*(int*)a < *(int*)b) return(1); else return(-1);}" >> $g_FUNCTIONS
    echo "int __b2c__sortnri_wrap_down(const void *a, const void *b) { return(__b2c__sortnri_down(*(void**)a, *(void**)b)); }" >> $g_FUNCTIONS
    echo "int __b2c__sortnrs(const void *a, const void *b) {if (*(short*)a==*(short*)b) return(0); else if (*(short*)a < *(short*)b) return(-1); else return(1);}" >> $g_FUNCTIONS
    echo "int __b2c__sortnrs_wrap(const void *a, const void *b) { return(__b2c__sortnrs(*(void**)a, *(void**)b)); }" >> $g_FUNCTIONS
    echo "int __b2c__sortnrs_down(const void *a, const void *b) {if (*(short*)a==*(short*)b) return(0); else if (*(short*)a < *(short*)b) return(1); else return(-1);}" >> $g_FUNCTIONS
    echo "int __b2c__sortnrs_wrap_down(const void *a, const void *b) { return(__b2c__sortnrs_down(*(void**)a, *(void**)b)); }" >> $g_FUNCTIONS
    echo "int __b2c__sortnrc(const void *a, const void *b) {if (*(char*)a==*(char*)b) return(0); else if (*(char*)a < *(char*)b) return(-1); else return(1);}" >> $g_FUNCTIONS
    echo "int __b2c__sortnrc_wrap(const void *a, const void *b) { return(__b2c__sortnrc(*(void**)a, *(void**)b)); }" >> $g_FUNCTIONS
    echo "int __b2c__sortnrc_down(const void *a, const void *b) {if (*(char*)a==*(char*)b) return(0); else if (*(char*)a < *(char*)b) return(1); else return(-1);}" >> $g_FUNCTIONS
    echo "int __b2c__sortnrc_wrap_down(const void *a, const void *b) { return(__b2c__sortnrc_down(*(void**)a, *(void**)b)); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//sortstr/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c__sortstr(const void *a, const void *b)" >> $g_FUNCTIONS
    echo "{if(*(char **)a == NULL) return(-1); if(*(char **)b == NULL) return(1); return strcmp(*(char **)a, *(char **)b);}" >> $g_FUNCTIONS
    echo "int __b2c__sortstr2(const void *a, const void *b)" >> $g_FUNCTIONS
    echo "{if(a == NULL) return(-1); if(b == NULL) return(1); return strcmp((char*)a, (char*)b);}" >> $g_FUNCTIONS
    echo "int __b2c__sortstr_down(const void *a, const void *b)" >> $g_FUNCTIONS
    echo "{if(*(char **)a == NULL) return(-1); if(*(char **)b == NULL) return(1); return strcmp(*(char **)b, *(char **)a);}" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//malloc/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__strdup(char *s) { if (s == NULL) { return(NULL); } return(__b2c_Copy_String(NULL, s)); }" >> $g_FUNCTIONS
    echo "char *__b2c__strndup(char *s, size_t n) { if(s == NULL) { return(NULL); } return(__b2c_Copy_N_String(NULL, s, n)); }" >> $g_FUNCTIONS
    echo "int __b2c__strcmp(const char *__b2c__s1, const char *__b2c__s2){ int len1 = 0, len2 = 0; len1 = __b2c__len(__b2c__s1); len2 = __b2c__len(__b2c__s2); if((__b2c__s1 == NULL || len1 == 0) && (__b2c__s2 == NULL || len2 == 0)) { return(0); }" >> $g_FUNCTIONS
    echo "if(__b2c__s1 == NULL || len1 == 0) { return(-1); } if(__b2c__s2 == NULL || len2 == 0) { return(1); } return(strcmp(__b2c__s1, __b2c__s2)); }" >> $g_FUNCTIONS
    echo "int __b2c__strcasecmp(const char *__b2c__s1, const char *__b2c__s2){ int len1 = 0, len2 = 0; len1 = __b2c__len(__b2c__s1); len2 = __b2c__len(__b2c__s2); if((__b2c__s1 == NULL || len1 == 0) && (__b2c__s2 == NULL || len2 == 0)) { return(0); }" >> $g_FUNCTIONS
    echo "if(__b2c__s1 == NULL || len1 == 0) { return(-1); } if(__b2c__s2 == NULL || len2 == 0) { return(1); } return(strcasecmp(__b2c__s1, __b2c__s2)); }" >> $g_FUNCTIONS
    echo "#ifndef __b2c_Pool_Block_Count" >> $g_FUNCTIONS
    echo "#define __b2c_Pool_Block_Count 2048" >> $g_FUNCTIONS
    echo "#endif" >> $g_FUNCTIONS
    echo "#ifndef __b2c_Pool_Block_Size" >> $g_FUNCTIONS
    echo "#define __b2c_Pool_Block_Size 1024" >> $g_FUNCTIONS
    echo "#endif" >> $g_FUNCTIONS
    echo "void *__b2c_mempool_realloc_core (void *address, size_t size, int action) { static char bottom[__b2c_Pool_Block_Count*__b2c_Pool_Block_Size] = { 0 }; static void *top = NULL, *current = NULL; static int inited = 0, amount_used = 0; void *result = NULL;" >> $g_FUNCTIONS
    echo "if(!inited) { current = bottom; top = bottom + (__b2c_Pool_Block_Size * __b2c_Pool_Block_Count); *(uintptr_t*)current = (uintptr_t)((uint8_t*)current + __b2c_Pool_Block_Size); inited++; } switch(action) { case 0: fprintf(stderr, \"Memory pool contains %d slots, each %d bytes, of which %d were used.\n\", __b2c_Pool_Block_Count, __b2c_Pool_Block_Size, inited);" >> $g_FUNCTIONS
    echo "break; case 1: if((uintptr_t)address >= (uintptr_t)bottom && (uintptr_t)address < (uintptr_t)top) { *(uintptr_t *)address = (uintptr_t)current; current = address; amount_used--; return(address); } break; case 2:" >> $g_FUNCTIONS
    echo "if ((uintptr_t)address >= (uintptr_t)bottom && (uintptr_t)address < (uintptr_t)top) { return(address); } break; default: if(amount_used < __b2c_Pool_Block_Count-1 && size < __b2c_Pool_Block_Size) { if(address == NULL) { result = current;" >> $g_FUNCTIONS
    echo "current = (void*)*(uintptr_t*)current; amount_used++; if(amount_used == inited) { *(uintptr_t*)current = (uintptr_t)((uint8_t*)current + __b2c_Pool_Block_Size); inited++; } } else if((uintptr_t)address >= (uintptr_t)bottom && (uintptr_t)address < (uintptr_t)top)" >> $g_FUNCTIONS
    echo "{ if(size == 0) { *(uintptr_t*)address = (uintptr_t)current; current = address; amount_used--; } else { result = address; } } else { result = realloc(address, size); } } else { if(address == NULL) { result = realloc(address, size); }" >> $g_FUNCTIONS
    echo "else if((uintptr_t)address >= (uintptr_t)bottom && (uintptr_t)address < (uintptr_t)top) { if(size == 0) { *(uintptr_t*)address = (uintptr_t)current; current = address; amount_used--; } else { result = malloc(size > __b2c_Pool_Block_Size ? size : __b2c_Pool_Block_Size);" >> $g_FUNCTIONS
    echo "memcpy(result, address, size > __b2c_Pool_Block_Size ? size : __b2c_Pool_Block_Size); *(uintptr_t*)address = (uintptr_t)current; current = address; amount_used--; } } else { result = realloc(address, size); } } break; } return ((void *) result); }" >> $g_FUNCTIONS
    echo "#ifndef __b2c_HASH_STR_STORE" >> $g_FUNCTIONS
    echo "#define __b2c_HASH_STR_STORE 0x100000" >> $g_FUNCTIONS
    echo "#endif" >> $g_FUNCTIONS
    echo "#define __b2c_HASH_STR_INDEX (__b2c_HASH_STR_STORE-1)" >> $g_FUNCTIONS
    echo "#ifndef __b2c_HASH_LINEAR_DEPTH" >> $g_FUNCTIONS
    echo "#define __b2c_HASH_LINEAR_DEPTH 16" >> $g_FUNCTIONS
    echo "#endif" >> $g_FUNCTIONS
    echo "#define __b2c_get_string(p, e, i, d, l) if(p) { while(e[i] != p) { i++; if(++d == l) { p=NULL; break; }}}" >> $g_FUNCTIONS
    echo "#define __b2c_del_string(p, e, i, d, l) if(p) { while(e[i] != p) { i++; if(++d == l) { break; } } if(d < l) { e[i] = NULL; } }" >> $g_FUNCTIONS
    echo "#define __b2c_add_string(p, e, i, d, l) if(p) { while(e[i] != NULL && e[i]!=p) { i++; if(++d == l) { if(++l == __b2c_HASH_LINEAR_DEPTH) { fprintf (stderr, \"\nInternal error: cannot register string! Try to tweak the 'hld' parameter.\n\"); __b2c_str_realloc_debug_string(); exit (EXIT_FAILURE); } } } e[i] = p; }" >> $g_FUNCTIONS
    echo "void *__b2c_str_realloc_core (char *ptr, size_t size, int action) { static char *even_addr[__b2c_HASH_STR_STORE + __b2c_HASH_LINEAR_DEPTH] = { NULL }; static int linear_depth = 1; char *next; uint32_t lbufsize = 0, rbufsize = 0, idx, len, depth = 0, total = 0; idx = (((uintptr_t) ptr % __b2c_HASH_STR_STORE) & __b2c_HASH_STR_INDEX); switch (action)" >> $g_FUNCTIONS
    echo "{ case 0: case 1: next = ptr; __b2c_get_string(next, even_addr, idx, depth, linear_depth); if(next) { lbufsize = __b2c__LBUFSIZE (ptr); rbufsize = __b2c__RBUFSIZE (ptr); if (action == 0) { if (rbufsize <= size) { __b2c_del_string(ptr, even_addr, idx, depth, linear_depth); next = (char*)__b2c_mempool_realloc(ptr - __b2c__BUFOFFSET - lbufsize, __b2c__BUFOFFSET + lbufsize + rbufsize + size * 2 + 1);" >> $g_FUNCTIONS
    echo "ptr = next + lbufsize; *(uint32_t *) ((char *) ptr + 4) = size * 2 + 1 + rbufsize; } else { return (ptr); } } else { if (lbufsize <= size) { __b2c_del_string(ptr, even_addr, idx, depth, linear_depth); next = (char*)__b2c_mempool_realloc(ptr - __b2c__BUFOFFSET - lbufsize, __b2c__BUFOFFSET + lbufsize + rbufsize + size * 2);" >> $g_FUNCTIONS
    echo "memmove (next + lbufsize + size * 2, next + lbufsize, __b2c__BUFOFFSET + rbufsize); ptr = next + size * 2 + lbufsize; *(uint32_t *) ((char *) ptr + 8) = size * 2 + lbufsize; } else { return (ptr); } } } else { rbufsize = __b2c__len (ptr); next = (char*)__b2c_mempool_realloc(ptr, __b2c__BUFOFFSET + rbufsize + size * 2 + 1);" >> $g_FUNCTIONS
    echo "if (action == 0) { ptr = next; *(uint32_t *) ((char *) ptr) = rbufsize; *(uint32_t *) ((char *) ptr + 4) = rbufsize + size * 2 + 1; *(uint32_t *) ((char *) ptr + 8) = 0; } else { memmove (next + size * 2, next, __b2c__BUFOFFSET + rbufsize); ptr = next+size * 2; *(uint32_t *) ((char *) ptr) = rbufsize;" >> $g_FUNCTIONS
    echo "*(uint32_t *) ((char *) ptr + 4) = rbufsize + 1; *(uint32_t *) ((char *) ptr + 8) = size * 2; } } ptr += __b2c__BUFOFFSET; idx = (((uintptr_t) ptr % __b2c_HASH_STR_STORE) & __b2c_HASH_STR_INDEX); depth = 0; __b2c_add_string(ptr, even_addr, idx, depth, linear_depth); break; case 2: __b2c_add_string(ptr, even_addr, idx, depth, linear_depth);" >> $g_FUNCTIONS
    echo "break; case 3: __b2c_del_string(ptr, even_addr, idx, depth, linear_depth); break; case 4: __b2c_get_string(ptr, even_addr, idx, depth, linear_depth); break; case 5: for (idx = 0; idx < __b2c_HASH_STR_STORE + __b2c_HASH_LINEAR_DEPTH; idx++) { if (even_addr[idx] != NULL) { total++; len = (*(uint32_t*)(even_addr[idx]-__b2c__BUFOFFSET));" >> $g_FUNCTIONS
    echo "lbufsize = __b2c__LBUFSIZE(even_addr[idx]); rbufsize = __b2c__RBUFSIZE(even_addr[idx]); if(len > 64) { even_addr[idx][64] = 0; fprintf(stderr, \"Bucketnr:lbuf:rbuf:length:string = %d:%d:%d:%d:%s[...]\n\", idx, lbufsize, rbufsize, len, even_addr[idx]); } else { fprintf(stderr, \"Bucketnr:lbuf:rbuf:length:string = %d:%d:%d:%d:%s\n\", idx, lbufsize, rbufsize, len, even_addr[idx]); } } }" >> $g_FUNCTIONS
    echo "fprintf(stderr, \"Total optimized strings: %d - max depth: %d\n\", total, linear_depth); break; case 6: for (idx = 0; idx < __b2c_HASH_STR_STORE + __b2c_HASH_LINEAR_DEPTH; idx++) { if(even_addr[idx] && !__b2c_mempool_realloc_in_block(even_addr[idx])) { free(even_addr[idx] - __b2c__BUFOFFSET - __b2c__LBUFSIZE(even_addr[idx])); } } break; } return (ptr); }" >> $g_FUNCTIONS
    echo "char *__b2c_Copy_String_core(char *x, char *y, int len) { long ylen; if(y == NULL) { __b2c__STRFREE(x); return(NULL); } if(len == -1) { ylen = __b2c__len(y); } else { ylen = len; } if (ylen == 0) { __b2c__STRFREE (x); return (NULL); } x = (char*)__b2c_str_realloc(x, ylen);" >> $g_FUNCTIONS
    echo "memmove(x, y, ylen); __b2c__SETLEN(x, ylen); x[ylen] = '\0'; return(x); }" >> $g_FUNCTIONS
    echo "char *__b2c_Swap_String(char **x, char **y) { char *ptr; ptr = *x; *x = *y; *y = ptr; return(*x); }" >> $g_FUNCTIONS
    echo "unsigned long __b2c__len (const char *ptr) { if (ptr == NULL) { return (0); } if(__b2c_str_realloc_get_string(ptr)) { return (*(uint32_t *) (ptr - __b2c__BUFOFFSET)); } return ((unsigned long) strlen (ptr)); }" >> $g_FUNCTIONS
    echo "char *__b2c__loop_helper(jmp_buf buf) { if(__b2c__loop_result${g_STRINGSIGN} != NULL) { __b2c__SETLEN (__b2c__loop_result${g_STRINGSIGN}, 0); __b2c__loop_result${g_STRINGSIGN} = __b2c_Copy_String(__b2c__loop_result${g_STRINGSIGN}, NULL); } longjmp(buf, 1); return(NULL); }" >> $g_FUNCTIONS
    echo "long __b2c__loop_helper2(jmp_buf buf) { __b2c__loop_result = 0; longjmp(buf, 1); return(0); }" >> $g_FUNCTIONS
    echo "void __b2c__free_str_array_members(char ***array, int base, int size) { int i; if(*array != NULL) { for(i=0; i < size; i++){ __b2c__STRFREE((*array)[i+base]); (*array)[i+base] = NULL; } } }" >> $g_FUNCTIONS
    if [[ `uname` = +(*BSD*) ]]
    then
        echo "char *__b2c_strlcat(char *dest, const char *src) { strlcat(dest, src, __b2c__len(dest)+__b2c__len(src)+1); return(dest); }" >> $g_FUNCTIONS
        echo "char *__b2c_strlcpy(char *dest, const char *src) { strlcpy(dest, src, __b2c__len(src)+1); return(dest); }" >> $g_FUNCTIONS
    fi
    echo -n "void __b2c_str_free(void) {" >> $g_FUNCTIONS
    if [[ ${TOTAL//regex/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
    then
        echo -n "__b2c__regex_free();" >> $g_FUNCTIONS
    fi
    if [[ ${TOTAL//extract/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
    then
        echo -n "__b2c__extract_free();" >> $g_FUNCTIONS
    fi
    if [[ ${TOTAL//replace/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
    then
        echo -n "__b2c__replace_free();" >> $g_FUNCTIONS
    fi
    if [[ ${TOTAL//walk/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
    then
        echo -n "__b2c__walk_free();" >> $g_FUNCTIONS
    fi
    if [[ ${TOTAL//delimengine/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
    then
        echo -n "__b2c__delim_engine_free();" >> $g_FUNCTIONS
    fi
    if [[ -n ${g_GLOBALARRAYS} ]]
    then
        echo -n "__b2c__arrays_free();" >> $g_FUNCTIONS
    fi
    if [[ ${TOTAL//collect/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
    then
        echo -n "__b2c__twalk_free();" >> $g_FUNCTIONS
    fi
    echo "__b2c_str_realloc_free_string(); }">> $g_FUNCTIONS
fi

if [[ ${TOTAL//hash/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "typedef struct __b2c__htable { char *key[65536]; void *value[65536]; char *index[65536]; int total; struct __b2c__htable *next; } __b2c__htable;" >> $g_FUNCTIONS
    echo "const char *__b2c__hash_key_collect(int n, const char *first, ...) { static char *keys[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long length = 0, buflen = 0, cnew; char *next; va_list ap; if (n == 0) { return (NULL); } if (n == 1) { return (first); }" >> $g_FUNCTIONS
    echo "idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } if (keys[idx]) { buflen = __b2c__RBUFSIZE(keys[idx]); } cnew = __b2c__len(first); if(cnew >= buflen) { keys[idx] = (char *) __b2c_str_realloc(keys[idx], cnew); buflen = __b2c__RBUFSIZE(keys[idx]); }" >> $g_FUNCTIONS
    echo "memcpy(keys[idx], first, cnew); length += cnew; n--; va_start (ap, first); while (n) { next = va_arg (ap, char *); if (next) { cnew = __b2c__len (next); if(length + cnew + 1 >= buflen) { keys[idx] = (char *) __b2c_str_realloc(keys[idx], (length + cnew + 1 + 1) * sizeof (char));" >> $g_FUNCTIONS
    echo "buflen = __b2c__RBUFSIZE(keys[idx]); } keys[idx][length] = 32; length++; memmove (keys[idx] + length, next, cnew); length += cnew; } n--; } va_end (ap); __b2c__SETLEN(keys[idx], length); keys[idx][length] = '\0'; return ((char *) keys[idx]); }" >> $g_FUNCTIONS
    echo "#define __b2c__KEYCOLLECT(...) __b2c__hash_key_collect(sizeof((const char*[]){__VA_ARGS__}) / sizeof(char*), __VA_ARGS__, NULL)" >> $g_FUNCTIONS
    echo "uint64_t __b2c__HashFNV1a_64(const char *key, int len){ uint64_t hash = 14695981039346656037UL; if(key==NULL) { return(0); } if(len) { while(len) { hash = 1099511628211 * (hash ^ *key); key++; len--; } } else { while(*key) { hash = 1099511628211 * (hash ^ *key); key++; } } return(hash); }" >> $g_FUNCTIONS
    echo "uint32_t __b2c__HashFNV1a_32(const char *key, int len){ uint32_t hash = 2166136261UL; if(key==NULL) { return(0); } if(len) { while(len) { hash = 16777619 * (hash ^ *key); key++; len--; } } else { while(*key) { hash = 16777619 * (hash ^ *key); key++; } } return(hash); }" >> $g_FUNCTIONS
    echo "#define __b2c__HashFNV1a_16(x) __b2c__HashFNV1a_16_new(x, 0)" >> $g_FUNCTIONS
    echo "uint16_t __b2c__HashFNV1a_16_new(const char *key, int len) { uint32_t hash = 2166136261UL; if (key == NULL) { return (0); } if (len) { while(len) { hash = 16777619 * (hash ^ *key); key++; len--; } } else" >> $g_FUNCTIONS
    echo "{ while (*key) { hash = 16777619 * (hash ^ *key); key++; } } return ((hash >> 16) ^ (hash & 0xffff)); }" >> $g_FUNCTIONS
    echo "__b2c__htable *__b2c__hash_new(void) { __b2c__htable *name; name = (__b2c__htable*)calloc(1, sizeof(__b2c__htable)); name->next = NULL; name->total = 0; return(name); }" >> $g_FUNCTIONS
    echo "__b2c__htable* __b2c__hash_find_key_do(__b2c__htable *name, unsigned short hash, const char *key) { if(key == NULL || name == NULL) { return(NULL); } if(hash == 0) { hash = __b2c__HashFNV1a_16(key); } do" >> $g_FUNCTIONS
    echo "{ if(name->key[hash] && !strcmp(name->key[hash], key)) { return(name); } name = name->next; } while(name); return(NULL); }" >> $g_FUNCTIONS
    echo "#define __b2c__hash_find_key(x, y, ...) __b2c__hash_find_key_do(x, y, __b2c__KEYCOLLECT(__VA_ARGS__))" >> $g_FUNCTIONS
    echo "void *__b2c__hash_find_value_do(__b2c__htable *name, const char *key) { __b2c__htable *table; unsigned short pos; if(name == NULL || key == NULL) { return(NULL); } pos = __b2c__HashFNV1a_16(key); table = __b2c__hash_find_key(name, pos, key);" >> $g_FUNCTIONS
    echo "if(table) { return(table->value[pos]); } return(NULL); }" >> $g_FUNCTIONS
    echo "#define __b2c__hash_find_value(x, ...) __b2c__hash_find_value_do(x, __b2c__KEYCOLLECT(__VA_ARGS__))" >> $g_FUNCTIONS
    echo "void __b2c__hash_add_do(__b2c__htable *name, const void *value, int flag, unsigned int len, const char *key) { unsigned short hash; if(name == NULL || value == NULL) { return; } hash = __b2c__HashFNV1a_16(key);" >> $g_FUNCTIONS
    echo "while(1) { if(name->key[hash] == NULL) { name->total++; break; } if(!strcmp(name->key[hash], key)) { if(flag != 2) { break; } } if(name->next) { name = name->next; } else { name->next = __b2c__hash_new(); name = name->next;} }" >> $g_FUNCTIONS
    echo "if(!name->key[hash]) { name->key[hash] = __b2c_Copy_String(name->key[hash], (char*)key); name->index[name->total-1] = name->key[hash]; } if(flag == 0) { if(!name->value[hash]) { name->value[hash] = calloc(1, sizeof(void*)); } memcpy(name->value[hash], value, sizeof(void*)); }" >> $g_FUNCTIONS
    echo "else if(flag == 3) { name->value[hash] = realloc(name->value[hash], len); memcpy(name->value[hash], value, len); } else { name->value[hash] = __b2c_Copy_String((char*)name->value[hash], (char*)value); } }" >> $g_FUNCTIONS
    echo "#define __b2c__hash_add(x, y, ...) __b2c__hash_add_do(x, y, 0, 0, __b2c__KEYCOLLECT(__VA_ARGS__))" >> $g_FUNCTIONS
    echo "#define __b2c__hash_add_str(x, y, ...) __b2c__hash_add_do(x, y, 1, 0, __b2c__KEYCOLLECT(__VA_ARGS__))" >> $g_FUNCTIONS
    echo "#define __b2c__hash_add_redundant(x, y, ...) __b2c__hash_add_do(x, y, 2, 0, __b2c__KEYCOLLECT(__VA_ARGS__))" >> $g_FUNCTIONS
    echo "#define __b2c__hash_add_data(x, y, len, ...) __b2c__hash_add_do(x, y, 3, len, __b2c__KEYCOLLECT(__VA_ARGS__))" >> $g_FUNCTIONS
    echo "void *__b2c__hash_realloc_str_value_do(__b2c__htable *name, int len, const char *key) { __b2c__htable *table; unsigned short pos; if (name == NULL || key == NULL) { return (NULL); } __b2c__hash_add_str(name, \"\", key); pos = __b2c__HashFNV1a_16(key);" >> $g_FUNCTIONS
    echo "table = __b2c__hash_find_key(name, pos, key); table->value[pos] = realloc(table->value[pos], len); return (table->value[pos]); }" >> $g_FUNCTIONS
    echo "#define __b2c__hash_realloc_str_value(x, y, ...) __b2c__hash_realloc_str_value_do(x, y, __b2c__KEYCOLLECT(__VA_ARGS__))" >> $g_FUNCTIONS
    echo "void __b2c__hash_del_do(__b2c__htable *name, int rebuild, const char *key) { __b2c__htable *found; unsigned short pos; int i, which; if(name == NULL) { return; } pos = __b2c__HashFNV1a_16(key); found = __b2c__hash_find_key(name, pos, key);" >> $g_FUNCTIONS
    echo "if(found) { if (rebuild) { for (i = 0; i < found->total; i++) { which = __b2c__HashFNV1a_16(found->index[i]); if (which == pos) { if(i != found->total-1) { found->index[i] = found->index[found->total-1]; } found->index[found->total-1] = NULL; break; } } }" >> $g_FUNCTIONS
    echo "__b2c__STRFREE(found->key[pos]); found->key[pos] = NULL; if(found->value[pos]) { __b2c__STRFREE(found->value[pos]); } found->value[pos] = NULL; found->total -= 1; } }" >> $g_FUNCTIONS
    echo "#define __b2c__hash_del(x, ...) __b2c__hash_del_do(x, 1, __b2c__KEYCOLLECT(__VA_ARGS__))" >> $g_FUNCTIONS
    echo "#define __b2c__hash_del_norebuild(x, ...) __b2c__hash_del_do(x, 0, __b2c__KEYCOLLECT(__VA_ARGS__))" >> $g_FUNCTIONS
    echo "void __b2c__hash_clear_do(__b2c__htable *name, int regex) { __b2c__htable *orig, *next; int i; orig = name; while(name) { for(i = 0; i < 65536; i++) { if(name->key[i]) { __b2c__STRFREE(name->key[i]); } name->key[i] = NULL;" >> $g_FUNCTIONS
    echo "if(name->value[i]) { if(regex) { regfree(&(*(regex_t*)name->value[i])); } __b2c__STRFREE(name->value[i]); } name->value[i] = NULL; } next = name->next; name->next = NULL; name->total = 0; if(name != orig) { free(name); } name = next; } }" >> $g_FUNCTIONS
    echo "#define __b2c__hash_clear(x) __b2c__hash_clear_do(x, 0)" >> $g_FUNCTIONS
    echo "#define __b2c__hash_clear_regfree(x) __b2c__hash_clear_do(x, 1)" >> $g_FUNCTIONS
    echo "int __b2c__hash_nrkeys(__b2c__htable *name) { int total = 0; while(name) { total += name->total; name = name->next; } return(total); }" >> $g_FUNCTIONS
    echo "void __b2c__hash_dup_do(__b2c__htable *from, __b2c__htable *to, int flag) { int i; char *value; while(from) { for(i = 0; i < 65536; i++) { if(from->key[i]) { value = (char*)__b2c__hash_find_value(from, from->key[i]); if(flag==0) { __b2c__hash_add(to, value, from->key[i]); } " >> $g_FUNCTIONS
    echo "else { __b2c__hash_add_str(to, value, from->key[i]); } } } from = from->next; if(to->next == NULL) { to->next = __b2c__hash_new(); } to = to->next; } }" >> $g_FUNCTIONS
    echo "#define __b2c__hash_dup(x, y) __b2c__hash_dup_do(x, y, 0)" >> $g_FUNCTIONS
    echo "#define __b2c__hash_dup_str(x, y) __b2c__hash_dup_do(x, y, 1)" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//obtain/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__hash_obtain(__b2c__htable *name, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long ctr, dlen, len, total = 0; if(name == NULL) { return (NULL); } if(delim == NULL) { delim = __b2c__option_delim; }" >> $g_FUNCTIONS
    echo "if(name->total == 0) { return (NULL); } dlen = __b2c__len(delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], dlen); do { for(ctr=0; ctr < name->total; ctr++) { len = __b2c__len(name->index[ctr]);" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], total+len+dlen); memmove(buf[idx] + total, name->index[ctr], len); total += len; memmove(buf[idx] + total, delim, dlen); total += dlen; } name = name->next; }" >> $g_FUNCTIONS
    echo "while(name); __b2c__SETLEN(buf[idx], total-dlen); buf[idx][total-dlen] = '\0'; return((char*)buf[idx]); }" >> $g_FUNCTIONS
    echo "char *__b2c__hash_obtain_by_sort(int l, char *k, __b2c__htable * name, char *delim, int up_down, int type) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; void **values = { NULL }; char **keys = { NULL }; void **dups = { NULL }; __b2c__htable *ptr, *inv; int i, j, pos = 0, start = 0, cur = 0; long dlen, len, total = 0;" >> $g_FUNCTIONS
    echo "unsigned short loc; char *value; char bf[${g_MAX_DIGITS} + 1] = { 0 }; if (name == NULL || name->total == 0) { return (NULL); } if (delim == NULL) { delim = __b2c__option_delim; } values = (void **) calloc (__b2c__hash_nrkeys (name), sizeof (char *)); inv = __b2c__hash_new (); ptr = name; do { for(i = 0; i < ptr->total; i++) { loc = __b2c__HashFNV1a_16(ptr->index[i]); switch(type)" >> $g_FUNCTIONS
    echo "{ case 0: value = (char*)ptr->value[loc]; break; case 1: snprintf (bf, ${g_MAX_DIGITS}, \"%g\", *(double *) ptr->value[loc]); value = bf; break; case 2: snprintf (bf, ${g_MAX_DIGITS}, \"%g\", *(float *) ptr->value[loc]); value = bf; break;" >> $g_FUNCTIONS
    echo "case 3: snprintf (bf, ${g_MAX_DIGITS}, \"%ld\", *(long *) ptr->value[loc]); value = bf; break; case 4: snprintf (bf, ${g_MAX_DIGITS}, \"%d\", *(int *) ptr->value[loc]); value = bf; break; case 5: snprintf (bf, ${g_MAX_DIGITS}, \"%d\", *(short *) ptr->value[loc]); value = bf; break;" >> $g_FUNCTIONS
    echo "case 6: snprintf (bf, ${g_MAX_DIGITS}, \"%d\", *(char *) ptr->value[loc]); value = bf; break; default: if (__b2c__trap) { ERROR = 43; RUNTIMEFERR(\"OBTAIN$\", ERROR, k, l); return(NULL); } } __b2c__hash_add_redundant(inv, ptr->index[i], value); values[pos++] = ptr->value[loc]; } ptr = ptr->next; } while (ptr);" >> $g_FUNCTIONS
    echo "switch (type) { case 0: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortstr); } else { qsort (&values[0], pos, sizeof (void *), __b2c__sortstr_down); } break; case 1: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrd_wrap); }" >> $g_FUNCTIONS
    echo "else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrd_wrap_down); } break; case 2: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrf_wrap); } else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrf_wrap_down); } break;" >> $g_FUNCTIONS;
    echo "case 3: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrl_wrap); } else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrl_wrap_down); } break; case 4: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnri_wrap); }" >> $g_FUNCTIONS
    echo "else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnri_wrap_down); } break; case 5: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrs_wrap); } else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrs_wrap_down); } break;" >> $g_FUNCTIONS
    echo "case 6: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrc_wrap); } else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrc_wrap_down); } break; } dlen = __b2c__len (delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], dlen);" >> $g_FUNCTIONS
    echo "keys = (char**)calloc(__b2c__hash_nrkeys(name), sizeof(char*)); dups = (void**)calloc(__b2c__hash_nrkeys(name), sizeof(void*)); for(i = 0; i < pos; i++) { if(type > 0) { keys[i] = (char*)calloc(${g_MAX_DIGITS}, sizeof(char)); } switch (type)" >> $g_FUNCTIONS
    echo "{ case 0: keys[i] = __b2c__strdup((char*)values[i]); break; case 1: snprintf (keys[i], ${g_MAX_DIGITS}, \"%g\", *(double *) values[i]); break; case 2: snprintf(keys[i], ${g_MAX_DIGITS}, \"%g\", *(float*)values[i]); break;" >> $g_FUNCTIONS
    echo "case 3: snprintf(keys[i], ${g_MAX_DIGITS}, \"%ld\", *(long *) values[i]); break; case 4: snprintf(keys[i], ${g_MAX_DIGITS}, \"%d\", *(int *) values[i]); break; case 5: snprintf(keys[i], ${g_MAX_DIGITS}, \"%d\", *(short*)values[i]); break; case 6:" >> $g_FUNCTIONS
    echo "snprintf(keys[i], ${g_MAX_DIGITS}, \"%d\", *(char *) values[i]); break; } dups[i] = __b2c__strdup((char*)__b2c__hash_find_value_do (inv, keys[i])); __b2c__hash_del_norebuild (inv, keys[i]); }" >> $g_FUNCTIONS
    echo "do { if(type == 0) { while(cur < pos-1 && !strcmp(keys[cur], keys[cur+1])) { cur++; } } else { while(cur < pos-1 && !memcmp(keys[cur], keys[cur+1], sizeof(void*))) { cur++; } } qsort (&dups[start], cur-start+1, sizeof (char *), __b2c__sortstr);" >> $g_FUNCTIONS
    echo "for (j = start; j <= cur; j++) { len = __b2c__len ((char *) dups[j]); buf[idx] = (char*)__b2c_str_realloc(buf[idx], total + len + dlen);" >> $g_FUNCTIONS
    echo "memmove(buf[idx] + total, dups[j], len); free(dups[j]); free(keys[j]); total += len; memmove(buf[idx] + total, delim, dlen); total += dlen; } cur++; start = cur; } while(cur < pos);" >> $g_FUNCTIONS
    echo "__b2c__hash_clear (inv); free(inv); free(values); free(dups); free(keys); total -= dlen; __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\0'; return((char*)buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//lookup/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c__lookup_by_order(__b2c__htable *name, char ***array, int size, int base) { int i, count = 0; if(name) { if(*array) { __b2c__free_str_array_members (&(*array), base, size); free(*array); } *array = (char **)calloc(__b2c__hash_nrkeys(name)+base, sizeof(char*));" >> $g_FUNCTIONS
    echo "count = base; do { for(i = 0; i < name->total; i++) { (*array)[count] = __b2c_Copy_String((*array)[count], name->index[i]); count++; } name = name->next; } while(name); count -= base; } return(count); }" >> $g_FUNCTIONS
    echo "int __b2c__lookup_by_sort (__b2c__htable * name, char ***array, int size, int base, int type, int (*compare)(const void*, const void*)) { void **values = { NULL }; char **keys = { NULL }; __b2c__htable *ptr, *inv; char *value; int i, j, pos = 0, count = 0, cur = 0, start = 0; unsigned short loc; char buf[${g_MAX_DIGITS} + 1] = { 0 };" >> $g_FUNCTIONS
    echo "if (*array) { __b2c__free_str_array_members (&(*array), base, size); free (*array); } if (name) { values = (void **) calloc (__b2c__hash_nrkeys (name), sizeof (char *)); inv = __b2c__hash_new (); ptr = name; do" >> $g_FUNCTIONS
    echo "{ for(i = 0; i < ptr->total; i++) { loc = __b2c__HashFNV1a_16 (ptr->index[i]); switch (type) { case 0: value = (char*)ptr->value[loc]; break; case 1: snprintf (buf, ${g_MAX_DIGITS}, \"%g\", *(double *) ptr->value[loc]); value = buf; break; case 2: snprintf (buf, ${g_MAX_DIGITS}, \"%g\", *(float *) ptr->value[loc]); value = buf;" >> $g_FUNCTIONS
    echo "break; case 3: snprintf (buf, ${g_MAX_DIGITS}, \"%ld\", *(long *) ptr->value[loc]); value = buf; break; case 4: snprintf (buf, ${g_MAX_DIGITS}, \"%d\", *(int *) ptr->value[loc]); value = buf; break; case 5: snprintf (buf, ${g_MAX_DIGITS}, \"%d\", *(short *) ptr->value[loc]); value = buf; break; case 6: snprintf (buf, ${g_MAX_DIGITS}, \"%d\", *(char *) ptr->value[loc]);" >> $g_FUNCTIONS
    echo "value = buf; break; } __b2c__hash_add_redundant(inv, ptr->index[i], value); values[pos++] = ptr->value[loc]; } ptr = ptr->next; } while (ptr); qsort (&values[0], pos, sizeof (void *), compare); *array = (char**)calloc(__b2c__hash_nrkeys(name) + base, sizeof(char*)); keys = (char**)calloc(__b2c__hash_nrkeys(name) + base, sizeof(char*));" >> $g_FUNCTIONS
    echo "count = base; for (i = 0; i < pos; i++) { if(type > 0) { keys[i] = (char*)calloc(${g_MAX_DIGITS}, sizeof(char)); } switch (type) { case 0: keys[i] = __b2c__strdup((char*)values[i]); break; case 1: snprintf(keys[i], ${g_MAX_DIGITS}, \"%g\", *(double *) values[i]); break; case 2: snprintf(keys[i], ${g_MAX_DIGITS}, \"%g\", *(float *) values[i]); break;" >> $g_FUNCTIONS
    echo "case 3: snprintf(keys[i], ${g_MAX_DIGITS}, \"%ld\", *(long *) values[i]); break; case 4: snprintf(keys[i], ${g_MAX_DIGITS}, \"%d\", *(int *) values[i]); break; case 5: snprintf(keys[i], ${g_MAX_DIGITS}, \"%d\", *(short *) values[i]); break; case 6: snprintf(keys[i], ${g_MAX_DIGITS}, \"%d\", *(char *) values[i]); break; }" >> $g_FUNCTIONS
    echo "value = (char*)__b2c__hash_find_value_do(inv, keys[i]); (*array)[count++] = __b2c__strdup (value); __b2c__hash_del_norebuild (inv, keys[i]); } do { if (type == 0) { while (cur < pos - 1 && !strcmp (keys[cur], keys[cur + 1])) { cur++; } } else { while (cur < pos - 1 && !memcmp (keys[cur], keys[cur + 1], sizeof(void*))) { cur++; }}" >> $g_FUNCTIONS
    echo "qsort(&(*array)[start+base], cur - start + 1, sizeof(char*), __b2c__sortstr); for (j = start; j <= cur; j++) { free (keys[j]); } cur++; start = cur; } while (cur < pos); __b2c__hash_clear (inv); free (inv); free (values);" >> $g_FUNCTIONS
    echo "free (keys); count -= base; } return (count); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//hex/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__dec2hex(int nr) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], ${g_MAX_DIGITS});" >> $g_FUNCTIONS
    echo "len = snprintf(buf[idx], ${g_MAX_DIGITS}, \"%X\", nr); __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//host/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__nethost(int l, char *k, char *host) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int y, flag = 0; struct hostent *he = NULL; unsigned char bf[sizeof(struct sockaddr_in*)]; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], ${g_BUFFER_SIZE}); for (y = 0; host[y] != '\\0'; y++) { if (isalpha (*(host + y))) { flag = 1; break; } } if (flag){ he = gethostbyname (host); strncpy(buf[idx], inet_ntoa(*((struct in_addr*)he->h_addr)), ${g_BUFFER_SIZE}); }" >> $g_FUNCTIONS
    echo "else { if (inet_pton(AF_INET, host, bf) <= 0) { if (__b2c__trap) { ERROR = 11; RUNTIMEFERR (\"HOST$\", ERROR, k, l); return(NULL); } else { strncpy(buf[idx], \"Host not found\", ${g_BUFFER_SIZE}); } }" >> $g_FUNCTIONS
    echo "else { he = gethostbyaddr(bf, sizeof(struct sockaddr_in*), AF_INET); if(he == NULL) { if (__b2c__trap) { ERROR = 11; RUNTIMEFERR (\"HOST$\", ERROR, k, l); return(NULL); } else { strncpy(buf[idx], \"Host not found\", ${g_BUFFER_SIZE}); } } else { strncpy(buf[idx], he->h_name, ${g_BUFFER_SIZE}); } } }" >> $g_FUNCTIONS
    echo "__b2c__SETLEN(buf[idx], strlen(buf[idx])); buf[idx][${g_BUFFER_SIZE}-1] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//hostname/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__hostname(int l, char *k) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], ${g_BUFFER_SIZE}*sizeof(char));" >> $g_FUNCTIONS
    echo "if(gethostname(buf[idx], ${g_BUFFER_SIZE})) { if (__b2c__trap) { ERROR = 26; RUNTIMEFERR(\"HOSTNAME$\", ERROR, k, l); return(NULL); } else strncpy (buf[idx], \"Error getting hostname\", ${g_BUFFER_SIZE}); }" >> $g_FUNCTIONS
    echo "__b2c__SETLEN(buf[idx], strlen(buf[idx])); buf[idx][${g_BUFFER_SIZE}-1] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//indexarray/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c__index (int line, char *k, size_t range, int type, void *array, int flag, ...) { int result = 0 + ${g_OPTION_BASE}; double d; float f; long l; int i; short s; char c; char *term; void *index; va_list ap; va_start (ap, flag); if (flag == 0) { switch (type)" >> $g_FUNCTIONS
    echo "{ case 0: term = va_arg(ap, char*); if ((index = lfind (&term, array, &range, sizeof (char *), __b2c__sortstr)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (char *) + 1; } break; case 1: d = va_arg (ap, double); if ((index = lfind (&d, array, &range, sizeof (double), __b2c__sortnrd)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (double) + 1; } break;" >> $g_FUNCTIONS
    echo "case 2: f = va_arg (ap, double); if ((index = lfind (&f, array, &range, sizeof (float), __b2c__sortnrf)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (float) + 1; } break; case 3: l = va_arg (ap, long); if ((index = lfind (&l, array, &range, sizeof (long), __b2c__sortnrl)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (long) + 1; } break;" >> $g_FUNCTIONS
    echo "case 4: i = va_arg (ap, int); if ((index = lfind (&i, array, &range, sizeof (int), __b2c__sortnri)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (int) + 1; } break; case 5: s = va_arg (ap, int); if ((index = lfind (&s, array, &range, sizeof (short), __b2c__sortnrs)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (short) + 1; } break;" >> $g_FUNCTIONS
    echo "case 6: c = va_arg (ap, int); if ((index = lfind (&c, array, &range, sizeof (char), __b2c__sortnrc)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (char) + 1; } break; default: if (__b2c__trap) { ERROR = 43; RUNTIMEFERR (\"INDEX\", ERROR, k, line); return(0); } } } else { switch (type)" >> $g_FUNCTIONS
    echo "{ case 0: term = va_arg(ap, char*); if ((index = bsearch (&term, array, range, sizeof (char *), __b2c__sortstr)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (char *) + 1; } break; case 1: d = va_arg (ap, double); if ((index = bsearch (&d, array, range, sizeof (double), __b2c__sortnrd)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (double) + 1; } break;" >> $g_FUNCTIONS
    echo "case 2: f = va_arg (ap, double); if ((index = bsearch (&f, array, range, sizeof (float), __b2c__sortnrf)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (float) + 1; } break; case 3: l = va_arg (ap, long); if ((index = bsearch (&l, array, range, sizeof (long), __b2c__sortnrl)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (long) + 1; } break;" >> $g_FUNCTIONS
    echo "case 4: i = va_arg (ap, int); if ((index = bsearch (&i, array, range, sizeof (int), __b2c__sortnri)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (int) + 1; } break; case 5: s = va_arg (ap, int); if ((index = bsearch (&s, array, range, sizeof (short), __b2c__sortnrs)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (short) + 1; } break;" >> $g_FUNCTIONS
    echo "case 6: c = va_arg (ap, int); if ((index = bsearch (&c, array, range, sizeof (char), __b2c__sortnrc)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (char) + 1; } break; default: if (__b2c__trap) { ERROR = 43; RUNTIMEFERR (\"INDEX\", ERROR, k, line); return(0); } } } va_end (ap); return (result - ${g_OPTION_BASE}); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//indexassoc/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__index_assoc (int l, char *k, int type, __b2c__htable * name, ...) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; __b2c__htable *inv; unsigned short pos; char *value, *result; char bf[${g_MAX_DIGITS} + 1] = { 0 }; int i, len; va_list ap; if(name == NULL || name->total == 0) { return (NULL); } inv = __b2c__hash_new (); do { for(i = 0; i < name->total; i++) { pos = __b2c__HashFNV1a_16(name->index[i]); switch (type) { case 0: value = (char*)name->value[pos];" >> $g_FUNCTIONS
    echo "break; case 1: snprintf (bf, ${g_MAX_DIGITS}, \"%g\", *(double *) name->value[pos]); value = bf; break; case 2: snprintf (bf, ${g_MAX_DIGITS}, \"%g\", *(float *) name->value[pos]); value = bf; break; case 3: snprintf (bf, ${g_MAX_DIGITS}, \"%ld\", *(long *) name->value[pos]); value = bf; break; case 4: snprintf (bf, ${g_MAX_DIGITS}, \"%d\", *(int *) name->value[pos]); value = bf; break; case 5: snprintf (bf, ${g_MAX_DIGITS}, \"%d\", *(short *) name->value[pos]); value = bf; break;" >> $g_FUNCTIONS
    echo "case 6: snprintf (bf, ${g_MAX_DIGITS}, \"%d\", *(char *) name->value[pos]); value = bf; break; default: if (__b2c__trap) { ERROR = 43; RUNTIMEFERR (\"INDEX$\", ERROR, k, l); return(NULL); } } __b2c__hash_add_redundant (inv, name->index[i], value); } name = name->next; } while (name); va_start (ap, name); switch (type) { case 0: value = va_arg (ap, char *); break; case 1: snprintf (bf, ${g_MAX_DIGITS}, \"%g\", va_arg (ap, double)); value = bf; break;" >> $g_FUNCTIONS
    echo "case 2: snprintf (bf, ${g_MAX_DIGITS}, \"%g\", va_arg (ap, double)); value = bf; break; case 3: snprintf (bf, ${g_MAX_DIGITS}, \"%ld\", va_arg (ap, long)); value = bf; break; case 4: snprintf (bf, ${g_MAX_DIGITS}, \"%d\", va_arg (ap, int)); value = bf; break; case 5: snprintf (bf, ${g_MAX_DIGITS}, \"%d\", va_arg (ap, int)); value = bf; break; case 6: snprintf (bf, ${g_MAX_DIGITS}, \"%d\", va_arg (ap, int)); value = bf; break;" >> $g_FUNCTIONS
    echo "default: if (__b2c__trap) { ERROR = 43; RUNTIMEFERR (\"INDEX$\", ERROR, k, l); return(NULL); } } va_end (ap); result = (char *) __b2c__hash_find_value_do (inv, value); idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } len = __b2c__len (result); buf[idx] = (char *) __b2c_str_realloc (buf[idx], len + 1); memmove (buf[idx], result, len); __b2c__SETLEN (buf[idx], len); buf[idx][len] = '\0'; __b2c__hash_clear (inv); free (inv); return ((char *) buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//invert/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c__invert (int line, char *k, int type, __b2c__htable ** name) { __b2c__htable *inv, *ptr; char bf[${g_MAX_DIGITS} + 1] = { 0 }; unsigned short pos; char *swap = NULL; int j, coll = 0; double d; float f; int i; long l; short s; char c; if (*name == NULL || (*name)->total == 0) { return (0); } inv = __b2c__hash_new (); ptr = *name; do { for (j = 0; j < ptr->total; j++) { pos = __b2c__HashFNV1a_16(ptr->index[j]); switch (type) { case 0: swap = (char*)ptr->value[pos]; break;" >> $g_FUNCTIONS
    echo "case 1: snprintf (bf, ${g_MAX_DIGITS}, \"%g\", *(double *) ptr->value[pos]); d = atof(ptr->index[j]); break; case 2: snprintf (bf, ${g_MAX_DIGITS}, \"%g\", *(float *) ptr->value[pos]); f = atof(ptr->index[j]); break; case 3: snprintf (bf, ${g_MAX_DIGITS}, \"%ld\", *(long *) ptr->value[pos]); l = atol(ptr->index[j]); break; case 4: snprintf (bf, ${g_MAX_DIGITS}, \"%d\", *(int *) ptr->value[pos]); i = atoi(ptr->index[j]); break;" >> $g_FUNCTIONS
    echo "case 5: snprintf (bf, ${g_MAX_DIGITS}, \"%d\", *(short *) ptr->value[pos]); s = atoi(ptr->index[j]); break; case 6: snprintf (bf, ${g_MAX_DIGITS}, \"%d\", *(char *) ptr->value[pos]); c = atoi(ptr->index[j]); break; default: if (__b2c__trap) { ERROR = 43; RUNTIMEFERR (\"INVERT\", ERROR, k, line); return(0); } } if(__b2c__hash_find_value_do(inv, bf) || __b2c__hash_find_value_do(inv, swap)) { coll++; } switch(type) { case 0: __b2c__hash_add_str(inv, ptr->index[j], swap); break;" >> $g_FUNCTIONS
    echo "case 1: __b2c__hash_add(inv, &d, bf); break; case 2: __b2c__hash_add(inv, &f, bf); break; case 3: __b2c__hash_add(inv, &l, bf); break; case 4: __b2c__hash_add(inv, &i, bf); break; case 5: __b2c__hash_add(inv, &s, bf); break; case 6: __b2c__hash_add(inv, &c, bf); break; default: if (__b2c__trap) { ERROR = 43; RUNTIMEFERR (\"INVERT\", ERROR, k, line); return(0); } } } ptr = ptr->next; } while (ptr); __b2c__hash_clear (*name);" >> $g_FUNCTIONS
    echo "free(*name); *name = inv; return(coll); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//insert/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char * __b2c__insert (int l, char *k, char *src, int pos, char *str) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len, tot, blen; if (str == NULL) { return (src); } if (src == NULL) { return(str); } len = __b2c__len (src); tot = __b2c__len (str);" >> $g_FUNCTIONS
    echo "idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+tot+1); pos--; if (pos <= 0) { memmove(buf[idx], str, tot); memmove(buf[idx] + tot, src, len); } else if (pos > len) { memmove(buf[idx], src, len);" >> $g_FUNCTIONS
    echo "memmove(buf[idx] + len, str, tot); } else { if (__b2c__option_utf8) { blen = __b2c__blen (l, k, \"INSERT$\", src, pos, 0); memmove(buf[idx], src, blen); memmove(buf[idx] + blen, str, tot);" >> $g_FUNCTIONS
    echo "memmove(buf[idx] + blen + tot, src + blen, len - blen); } else { memmove(buf[idx], src, pos); memmove(buf[idx] + pos, str, tot); memmove(buf[idx] + pos + tot, src + pos, len - pos); } }" >> $g_FUNCTIONS
    echo "__b2c__SETLEN(buf[idx], len + tot); buf[idx][len + tot] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//instring/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "long __b2c__instr(int l, char *k, char *first, char *tmp, int pos) { char *result; if (first == NULL) { return (0); } if (tmp == NULL || __b2c__len (tmp) == 0) { return (0); } if (pos <= 0) {  pos = 1; }" >> $g_FUNCTIONS
    echo "result = strstr (first + pos - 1, tmp); if(result == NULL) {  return (0); } if (__b2c__option_utf8) { return (long) __b2c__ucs2_clen (l, k, \"INSTR\", first, result - first + 1); } return (long) (result - first + 1); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//instrrev/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "long __b2c__instrrev(int m, char *k, char *first, char *tmp, int pos) { char *result, *found; long l; if (first == NULL){ return (0);} if (tmp == NULL || __b2c__len (tmp) == 0) { return (0); } if (pos < 0) { pos = 0; }" >> $g_FUNCTIONS
    echo "l = __b2c__len (first); found = first; do { result = strstr (found, tmp); if (result != NULL && result <= first + l - pos) { found = result + 1; continue; } if (result > first + l - pos) result = NULL; } while (result != NULL);" >> $g_FUNCTIONS
    echo "if (__b2c__option_startpoint) { if (l - (found - first) + 1 > l) { return(0); } if (__b2c__option_utf8) { return (long) (__b2c__ulen (l, k, \"INSTRREV\", first, -1) - __b2c__ucs2_clen (l, k, \"INSTRREV\", first, found - first) + 1); }" >> $g_FUNCTIONS
    echo "return (long) (l - (found - first) + 1); } if (__b2c__option_utf8) { return (long) __b2c__ucs2_clen (m, k, \"INSTRREV\", first, found - first); } return (long) (found - first); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//lcase/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char * __b2c__lcase(int l, char *k, char *src) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len, i; size_t mbslen; wchar_t *wcs, *wp; char *local; if (src == NULL) { return (NULL); } len = __b2c__len (src); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1); if (__b2c__option_utf8) { local = setlocale (LC_ALL, \"\"); if ((mbslen = mbstowcs (NULL, src, 0)) == (size_t) - 1) { ERROR = 38; RUNTIMEFERR (\"LCASE$\", ERROR, k, l); return(NULL); } wcs = (wchar_t*)calloc (mbslen + 1, sizeof (wchar_t));" >> $g_FUNCTIONS
    echo "if(mbstowcs(wcs, src, mbslen + 1) == (size_t)-1) { ERROR = 38; RUNTIMEFERR (\"LCASE$\", ERROR, k, l); return(NULL); } for (wp = wcs; *wp != 0; wp++) { *wp = towlower (*wp); } if(wcstombs(buf[idx], wcs, len) == (size_t)-1) { ERROR = 38; RUNTIMEFERR (\"LCASE$\", ERROR, k, l); return(NULL); } free (wcs);" >> $g_FUNCTIONS
    echo "setlocale (LC_ALL, local); } else { for (i = 0; i < len; i++) { buf[idx][i] = tolower(src[i]); } } __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//left/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char * __b2c__left(int l, char *k, char *src, unsigned long n) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned long length; if (src == NULL) { return (NULL); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } length = __b2c__len (src);" >> $g_FUNCTIONS
    echo "if (n > (__b2c__option_utf8 ? __b2c__ucs2_clen (l, k, \"LEFT$\", src, length) : length)) { return(src); } else { if (__b2c__option_utf8)" >> $g_FUNCTIONS
    echo "{ n = __b2c__blen (l, k, \"LEFT$\", src, n, 0); } buf[idx] = (char *) __b2c_str_realloc (buf[idx], n+1); memmove(buf[idx], src, n); __b2c__SETLEN (buf[idx], n); buf[idx][n] = '\0'; } return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//load/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char* __b2c__load(int flag, int l, char *k, char *file) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; FILE *handle; struct stat bf; void* mem; handle = fopen ((const char*)file, \"r\"); if(handle == NULL && __b2c__trap)" >> $g_FUNCTIONS
    echo "{ ERROR = 2; RUNTIMEFERR (\"LOAD$/BLOAD\", ERROR, k, l); return(NULL); } if(stat(file, &bf) < 0 && __b2c__trap) { ERROR = 24; RUNTIMEFERR (\"LOAD$/BLOAD\", ERROR, k, l); return(NULL); } if(flag) { mem = calloc(bf.st_size+__b2c__option_memstream, sizeof(char));" >> $g_FUNCTIONS
    echo "if(fread (mem, sizeof (char), bf.st_size, handle) != (size_t)bf.st_size && __b2c__trap) { ERROR = 2; RUNTIMEFERR(\"BLOAD\", ERROR, k, l); return(NULL); } fclose(handle); return(char*)(mem); } else" >> $g_FUNCTIONS
    echo "{ idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], bf.st_size + 1); if(fread(buf[idx], sizeof (char), bf.st_size, handle) != (size_t)bf.st_size && __b2c__trap)" >> $g_FUNCTIONS
    echo "{ ERROR = 2; RUNTIMEFERR (\"LOAD$\", ERROR, k, l); return(NULL); } __b2c__SETLEN(buf[idx], bf.st_size); buf[idx][bf.st_size] = '\0'; fclose(handle); return(char*)(buf[idx]); } }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//memcheck/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "void __b2c__catch_signal(int sig){" >> $g_FUNCTIONS
    echo "switch (sig) {case SIGABRT: fprintf(stderr, \"ERROR: signal ABORT received - internal error. Try to compile the program with TRAP LOCAL to find the cause.\n\"); break;" >> $g_FUNCTIONS
    echo "case SIGFPE: fprintf(stderr, \"ERROR: signal for FPE received - division by zero? Examine the calculations in the program.\n\"); break;" >> $g_FUNCTIONS
    echo "case SIGSEGV: fprintf(stderr, \"ERROR: signal for SEGMENTATION FAULT received - memory invalid or array out of bounds? Try to compile the program with TRAP LOCAL to find the cause.\n\"); break;" >> $g_FUNCTIONS
    echo "case SIGILL: fprintf(stderr, \"ERROR: signal for ILLEGAL INSTRUCTION received - executing the program on other hardware? Try to recompile the program from scratch.\n\"); break;} exit(sig);}" >> $g_FUNCTIONS
    echo "void __b2c__segv(int sig){ longjmp(__b2c__jump, 1); }" >> $g_FUNCTIONS
    echo "int __b2c__memory__check (char *x, int size) { volatile char c; unsigned int i, illegal = 1; struct sigaction osa, psa; sigaction(SIGSEGV, NULL, &osa); if (osa.sa_handler != SIG_IGN)" >> $g_FUNCTIONS
    echo "{ memset(&psa, 0, sizeof(psa)); psa.sa_flags = SA_NODEFER|SA_RESTART; psa.sa_handler = __b2c__segv; sigaction(SIGSEGV, &psa, NULL); } if (!setjmp (__b2c__jump))" >> $g_FUNCTIONS
    echo "{ for (i = 0; i < size; i++) { c = *(char*)(x+i); /* Use c to avoid warning */ if(c) {;} } } else { illegal = 0; } sigaction(SIGSEGV, &osa, NULL); return (illegal); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//mid/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__mid(int l, char *k, char **swap, int type, char *src, long pos, long length) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long src_len; if (src == NULL) { if (type == 1) { *swap = __b2c_Copy_String (*swap, NULL); } return(NULL); }" >> $g_FUNCTIONS
    echo "idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } src_len = __b2c__len (src); pos -= 1; if (pos < 0) { pos = (__b2c__option_utf8 ? __b2c__ucs2_clen (l, k, \"MID$\", src, src_len) : src_len) + 1 + pos; } if (__b2c__option_utf8) { pos = __b2c__blen (l, k, \"MID$\", src, pos, 0); }" >> $g_FUNCTIONS
    echo "if (pos > src_len) { if (type == 1) { *swap = __b2c_Copy_String (*swap, NULL); } return(NULL); } if (__b2c__option_utf8 && length >= 0) { length = __b2c__blen (l, k, \"MID$\", src + pos, length, 0); } if (length < 0 || pos + length > src_len) { length = src_len - pos; }" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], length + 1); memmove (buf[idx], src + pos, length); __b2c__SETLEN (buf[idx], length); buf[idx][length] = '\0'; if (type == 1) { return (__b2c_Swap_String (swap, &buf[idx])); } return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//minmax/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char* __b2c__min_str(char* x, char* y) {if(strcmp(x, y) < 0) { return(x); } return(y);}" >> $g_FUNCTIONS
    echo "char* __b2c__max_str(char* x, char* y) {if(strcmp(x, y) > 0) { return(x); } return(y);}" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//os/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__os(int l, char *k) { static char *result = NULL ; struct utsname bf; unsigned int len = 0; if(!result) { result = (char*)__b2c_str_realloc(result, 256 * sizeof (char)); if (uname(&bf) < 0 && __b2c__trap)" >> $g_FUNCTIONS
    echo "{ ERROR = 26; RUNTIMEFERR(\"OS$\", ERROR, k, l); return(NULL); } strncpy(result, bf.sysname, 64); len += strlen(bf.sysname); strncat(result, \" \", 2); len++; strncat(result, bf.machine, 128);" >> $g_FUNCTIONS
    echo "len += strlen(bf.machine); __b2c__SETLEN(result, len); result[len] = '\0'; } return(char*)result; }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//peek/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c__peek_check(int l, char *k, char* x, int size) {if(__b2c__trap) {if(!__b2c__memory__check((char*)x, size)) {ERROR=1; RUNTIMEFERR(\"PEEK\", ERROR, k, l); return(0); } } return(0); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//recursive/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c__rmrecursive(int l, char *k, char *dir){DIR *mydir; char *path, *item = NULL; struct stat buf = { 0 }; struct dirent *next = { NULL }; mydir = opendir(dir); if(mydir == NULL) {if(__b2c__trap) {ERROR = 8; RUNTIMEFERR(\"DELETE RECURSIVE\", ERROR, k, l); return(0);} }" >> $g_FUNCTIONS
    echo "while (1) { if (item != NULL) free(item); next = readdir(mydir); if(next != NULL) { item = (char*)calloc((strlen (next->d_name) + 1), sizeof(char));" >> $g_FUNCTIONS
    echo "strcpy(item, next->d_name); } else { break; } if (!strcmp (item, \".\") || !strcmp(item, \"..\") ) continue; path = (char*)calloc(strlen(dir)+strlen(item)+2, sizeof(char));" >> $g_FUNCTIONS
    echo "strcpy(path, dir); strcat(path, \"/\"); strcat(path, item); lstat(path, &buf); if(S_ISDIR (buf.st_mode)) { __b2c__rmrecursive(l, k, path); } else { if(remove(path) < 0)" >> $g_FUNCTIONS
    echo "{ if(__b2c__trap) { ERROR = 7; RUNTIMEFERR(\"DELETE RECURSIVE\", ERROR, k, l); return(0); } } } if(path != NULL) free(path); } closedir(mydir); if(remove(dir) < 0)" >> $g_FUNCTIONS
    echo "{ if(__b2c__trap) { ERROR = 7; RUNTIMEFERR(\"DELETE RECURSIVE\", ERROR, k, l); return(0); } } return(0);}" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//reverse/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__reverse(int l, char *k, char *src) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long i, length, len, blen; if (src == NULL) { return (NULL); } length = __b2c__len (src); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], length+1); if(__b2c__option_utf8) { len = length; while (len > 0) { blen = __b2c__blen (l, k, \"REVERSE$\", src, 1, 0); memcpy(buf[idx] + len - blen, src, blen); src += blen; len -= blen; } } else" >> $g_FUNCTIONS
    echo "{ for (i = 0; i < length; i++) { buf[idx][i] = src[length-i-1]; } } __b2c__SETLEN(buf[idx], length); buf[idx][length] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//right/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char * __b2c__right (int l, char *k, char *src, unsigned long n) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned long length; if (src == NULL) { return (NULL); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } length = __b2c__len (src);" >> $g_FUNCTIONS
    echo "if (n > (__b2c__option_utf8 ? __b2c__ucs2_clen (l, k, \"RIGHT$\", src, length) : length)) { return(src); } else { if (__b2c__option_utf8)" >> $g_FUNCTIONS
    echo "{ n = __b2c__blen (l, k, \"RIGHT$\", src, n, 1); } buf[idx] = (char*)__b2c_str_realloc(buf[idx], n+1); memmove(buf[idx], src + length - n, n); __b2c__SETLEN(buf[idx], n); buf[idx][n] = '\0'; } return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//rip/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__rip(int l, char *k, char *src, long pos, long length) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long src_len; if (src == NULL) { return (NULL); } src_len = __b2c__len (src); pos -= 1;" >> $g_FUNCTIONS
    echo "if (pos < 0) { pos = (__b2c__option_utf8 ? __b2c__ucs2_clen (l, k, \"RIP$\", src, src_len) : src_len) + 1 + pos; } if (__b2c__option_utf8) { pos = __b2c__blen (l, k, \"RIP$\", src, pos, 0); } if (pos > src_len)" >> $g_FUNCTIONS
    echo "{ return (NULL); } if (__b2c__option_utf8 && length >= 0) { length = __b2c__blen (l, k, \"RIP$\", src + pos, length, 0); } if (length < 0 || pos + length > src_len)" >> $g_FUNCTIONS
    echo "{ length = src_len - pos; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], src_len); memmove(buf[idx], src, pos); memmove(buf[idx]+pos, src+pos+length, src_len-pos-length);" >> $g_FUNCTIONS
    echo "__b2c__SETLEN(buf[idx], src_len-length); buf[idx][src_len-length] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//screen/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "long __b2c__screen(int type){long x; struct winsize tmp; ioctl(STDOUT_FILENO, TIOCGWINSZ, &tmp); if(type) { x = tmp.ws_row; } else { x = tmp.ws_col; } return(x); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//search/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "long __b2c__search (int l, char *k, FILE *x, char *y, int whence) { long off, pos=0, org_pos; int flag = 0; char *ptr; if (x == NULL && __b2c__trap)" >> $g_FUNCTIONS
    echo "{ ERROR = 2; RUNTIMEFERR (\"SEARCH\", ERROR, k, l); return(0); } if (y == NULL && __b2c__trap) { ERROR = 25; RUNTIMEFERR (\"SEARCH\", ERROR, k, l); return(0); } org_pos = ftell (x); ptr = (char *) malloc (__b2c__len (y) + 1);" >> $g_FUNCTIONS
    echo "switch(whence) { case -1: case 0: off = 1; break; case 1: off = 1; break; case 2: off = -1; break; case 3: off = -1; break; default: ERROR = 37; RUNTIMEFERR (\"SEARCH\", ERROR, k, l); return(0); } do { switch(whence) { case -1: case 0: fseek (x, pos, SEEK_SET);" >> $g_FUNCTIONS
    echo "break; case 1: fseek (x, org_pos+pos, SEEK_SET);break; case 2: flag = fseek (x, org_pos- __b2c__len (y)+pos, SEEK_SET); break; case 3: fseek (x, pos-__b2c__len (y), SEEK_END); break; }" >> $g_FUNCTIONS
    echo "if (fread (ptr, sizeof (char), __b2c__len (y), x) <= 0) { if (__b2c__trap) { ERROR = 2; RUNTIMEFERR (\"SEARCH\", ERROR, k, l); return(0); } } pos += off; } while (!feof (x) && !flag && memcmp (ptr, y, __b2c__len (y)));" >> $g_FUNCTIONS
    echo "if (memcmp (ptr, y, __b2c__len (y))) { pos = -1; } else {pos = ftell(x)-__b2c__len (y); } fseek (x, org_pos, SEEK_SET); free (ptr); return(pos); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//spc/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__spc(int amount) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], amount+1);" >> $g_FUNCTIONS
    echo "memset(buf[idx], 32, amount); __b2c__SETLEN(buf[idx], amount); buf[idx][amount] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//str/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char * __b2c__str(double nr) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len; idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc (buf[idx], ${g_MAX_DIGITS}); if(floor(nr) == nr)" >> $g_FUNCTIONS
    echo "{ len = snprintf(buf[idx], ${g_MAX_DIGITS}, \"%ld\", (long)nr); } else { len = snprintf(buf[idx], ${g_MAX_DIGITS}, \"%g\", (double)nr); } __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//sum/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "long __b2c__sum(int base, long *array, long nr, ...) { va_list ap; long limit = 0, total = 0; int x; va_start (ap, nr); limit = va_arg (ap, long); va_end (ap);" >> $g_FUNCTIONS
    echo "for(x = base; x < nr+base; x++) { if(limit == LONG_MAX){ total += array[x]; } else { if(array[x]>limit) { total += array[x]; } } } return(total); }" >> $g_FUNCTIONS
    echo "double __b2c__sumf(int base, double *array, double nr, ...) { va_list ap; double limit = 0, total = 0; int x; va_start (ap, nr); limit = va_arg (ap, double); va_end (ap);" >> $g_FUNCTIONS
    echo "for(x = base; x < nr+base; x++) { if(limit == DBL_MAX){ total += array[x]; } else { if(array[x]>limit) { total += array[x]; } } } return(total); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//tab/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__tab(int amount) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], amount+1);" >> $g_FUNCTIONS
    echo "memset(buf[idx], 9, amount); __b2c__SETLEN(buf[idx], amount); buf[idx][amount] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//tally/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "long __b2c__tally(char *haystack, char *needle, int pos) { char *res; long total = 0; if (haystack == NULL) { return (0); }" >> $g_FUNCTIONS
    echo "if (needle == NULL || __b2c__len(needle) == 0) { return (0); } if (pos <= 0) { pos = 1; }" >> $g_FUNCTIONS
    echo "haystack+=pos-1; while((res = strstr(haystack, needle)) != NULL) { haystack = res+1; total++; } return((long)total); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//chrono/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then 
    echo "long __b2c__time (time_t now, int which){ long result; char *buffer; struct tm *ts; buffer = (char*)calloc(${g_MAX_DIGITS}, sizeof (char)); ts = localtime (&now); switch (which) {" >> $g_FUNCTIONS
    echo "case 1: strftime (buffer, ${g_MAX_DIGITS}, \"%d\", ts); break; case 2: strftime (buffer, ${g_MAX_DIGITS}, \"%m\", ts); break; case 3: strftime (buffer, ${g_MAX_DIGITS}, \"%Y\", ts); break;" >> $g_FUNCTIONS
    echo "case 4: strftime (buffer, ${g_MAX_DIGITS}, \"%H\", ts); break; case 5: strftime (buffer, ${g_MAX_DIGITS}, \"%M\", ts); break; case 6: strftime (buffer, ${g_MAX_DIGITS}, \"%S\", ts); break;" >> $g_FUNCTIONS
    echo "case 7: strftime (buffer, ${g_MAX_DIGITS}, \"%W\", ts); break; } result = atol(buffer); free(buffer); return(result); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//timer/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "unsigned long __b2c__timer(int init) { struct timeval time; static time_t elapsed_secs = 0; static int elapsed_usecs = 0; if(init) { gettimeofday(&time, NULL); elapsed_usecs = time.tv_usec; elapsed_secs = time.tv_sec; return(0); }" >> $g_FUNCTIONS
    echo "else { gettimeofday(&time, NULL); if(difftime(time.tv_sec, elapsed_secs) < 1) { return((unsigned long) (time.tv_usec-elapsed_usecs)/1000); }" >> $g_FUNCTIONS
    echo "else { return((unsigned long) (difftime(time.tv_sec, elapsed_secs)-1)*1000+((1000000-elapsed_usecs)+time.tv_usec)/1000); } } }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//nano/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "uint64_t __b2c__nanotimer(int init) { static struct timespec before = { 0 }; struct timespec after; if (init) { clock_gettime(CLOCK_MONOTONIC, &before); return(0); } else { clock_gettime(CLOCK_MONOTONIC, &after); return((int64_t)(after.tv_sec - before.tv_sec) * (int64_t)1000000000UL + (int64_t)(after.tv_nsec - before.tv_nsec)); } }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//delimengine/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "/* API >>>> nr == 0, use_cache == 0 : rebuild cache | nr != 0, use_cache == 0 : dynamic calc member | nr != 0, use_cache == 1 : use member from cache */" >> $g_FUNCTIONS
    echo "long __b2c__delim_engine_core(int action, int type, long *returned_value, char *string, char *delim, long nr, int use_cache) { static long *cache = NULL, cache_tot = 0, cnt = 0; long x, len, pos = 0, start = 0; int in_string = 0, is_escaped = 0; if(action == 0) { if(cache) { free(cache); cache = NULL; } return(0); } *returned_value = 0; if (string == NULL || string[0] == 0) { return (0); }" >> $g_FUNCTIONS
    echo "if (delim == NULL) { delim = __b2c__option_delim; } len = __b2c__len (delim); if(!use_cache) { cnt = 0; for (x = 0; string[x] != 0; x++) { if (!in_string) { if (len == 1 ? string[x] == delim[0] : !strncmp (string + x, delim, len)) { if (__b2c__collapse == 0 || x > start) { cnt++; if (cnt > cache_tot)" >> $g_FUNCTIONS
    echo "{ cache = (long*)realloc(cache, (cnt*2+2) * sizeof(long)); cache_tot = cnt; } cache[cnt * 2] = x - start; cache[cnt * 2 + 1] = start; } if(nr && nr == cnt) { break; } start = x + len; } } if (string[x] == __b2c__option_esc) { if (!is_escaped) { is_escaped = 1; } else { is_escaped = 0; } } else if (string[x] == __b2c__option_dq)" >> $g_FUNCTIONS
    echo "{ if (!is_escaped && __b2c__option_quoted) { in_string = 1 - in_string; } is_escaped = 0; } else { is_escaped = 0; } } if (__b2c__collapse == 0 || x > start) { cnt++; if (cnt > cache_tot) { cache = (long*)realloc(cache, (cnt*2+2) * sizeof(long)); cache_tot = cnt; } cache[cnt * 2] = x - start;" >> $g_FUNCTIONS
    echo "cache[cnt * 2 + 1] = start; } } if (nr <= cnt) { if (type == 1) { *returned_value = cache[nr*2]; pos = cache[nr*2+1]; } else { *returned_value = cnt; pos = cache[nr*2+1]; } } return(pos); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//argument/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "void __b2c__argument(char **arg, int total, char **data) { long x, dlen, slen, pos, tot_len = 0; char quote[] = { 34, 0 }; if (total == 0) { *arg = NULL; } else { dlen = __b2c__len (__b2c__option_delim); for (pos = 0; pos < total; pos++)" >> $g_FUNCTIONS
    echo "{ slen = strlen(data[pos]); *arg = (char*)__b2c_str_realloc(*arg, tot_len + slen * 2 + dlen + 1); if (strstr (data[pos], \" \") || strstr (data[pos], \"\\\"\")) { (*arg)[tot_len++] = 34; for (x = 0; data[pos][x] != 0; x++) { if (data[pos][x] == quote[0])" >> $g_FUNCTIONS
    echo "{ (*arg)[tot_len++] = __b2c__option_esc; } (*arg)[tot_len++] = data[pos][x]; } (*arg)[tot_len++] = 34; } else { memmove (*arg + tot_len, data[pos], slen); tot_len += slen; } if (pos < total - 1) { memmove (*arg + tot_len, __b2c__option_delim, dlen);" >> $g_FUNCTIONS
    echo "tot_len += dlen; } } __b2c__SETLEN(*arg, tot_len); (*arg)[tot_len] = 0; } }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//token/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__token(char *string, long nr, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start; long length = 0; if (string == NULL || nr < 1) { return (NULL); }" >> $g_FUNCTIONS
    echo "start = __b2c__delim_engine(1, &length, string, delim, nr); if(length == 0) { return(NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], length+1); memmove(buf[idx], string + start, length); __b2c__SETLEN(buf[idx], length); buf[idx][length] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//where/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "long __b2c__where (char *string, long nr, char *delim) { long result = 0, length = 0; if (string == NULL || nr < 1) { return (0); } result = __b2c__delim_engine (1, &length, string, delim, nr); return(result+1); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//amount/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "long __b2c__amount(char *string, char *delim) { long amount = 0; if (string == NULL) { return (0); } __b2c__delim_engine(2, &amount, string, delim, 0); return(amount); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//hasdelim/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c__hasdelim (char *string, char *delim) { long length = 0; long start = 0; if (string == NULL) { return (0); }" >> $g_FUNCTIONS
    echo "start = __b2c__delim_engine (2, &length, string, delim, 2); if(start == 0) { return (0); } if (delim == NULL) { delim = __b2c__option_delim; } return (start-__b2c__len (delim)+1); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//exchange/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__exchange (char *string, int index1, int index2, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long tmp, tlen, len1, len2, start1 = 0, start2 = 0; long length = 0;" >> $g_FUNCTIONS
    echo "if (string == NULL || index1 <= 0 || index2 <= 0) { return (string); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start1 = __b2c__delim_engine(1, &length, string, delim, index1);" >> $g_FUNCTIONS
    echo "len1 = length; length = 0; start2 = __b2c__delim_engine(1, &length, string, delim, index2); len2 = length; if (start1 == start2) { return (string); } else if (start2 < start1)" >> $g_FUNCTIONS
    echo "{ tmp = start2; start2 = start1; start1 = tmp; tmp = len2; len2 = len1; len1 = tmp; } tlen = __b2c__len (string); buf[idx] = (char*)__b2c_str_realloc(buf[idx], tlen+1); memmove(buf[idx], string, start1);" >> $g_FUNCTIONS
    echo "memmove(buf[idx] + start1, string + start2, len2); memmove(buf[idx] + start1 + len2, string + start1 + len1, start2 - (start1 + len1));" >> $g_FUNCTIONS
    echo "memmove(buf[idx] + start1 + len2 + start2 - (start1 + len1), string + start1, len1); memmove(buf[idx] + start1 + len2 + start2 - (start1 + len1) + len1, string + start2 + len2, tlen - (start2 + len2));" >> $g_FUNCTIONS
    echo "__b2c__SETLEN(buf[idx], tlen); buf[idx][tlen] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//change/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__change(char *string, int index, char *cnew, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long tlen, start, len, nlen; long length = 0; if(string == NULL) { return(cnew); }" >> $g_FUNCTIONS
    echo "if (index <= 0) { return (string); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine(1, &length, string, delim, index); len = length; tlen = __b2c__len(string); nlen = __b2c__len(cnew);" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], tlen-len+nlen+1); memmove(buf[idx], string, start); memmove(buf[idx] + start, cnew, nlen); memmove(buf[idx] + start + nlen, string + start + len, tlen - (start + len));" >> $g_FUNCTIONS
    echo "__b2c__SETLEN(buf[idx], tlen - len + nlen); buf[idx][tlen-len+nlen] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//istok/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "long __b2c__istoken(char *string, char *token, char *delim) { long len, start, x, result = 0; long length = 0, amount = 0; if(string == NULL) { return(0); } if(delim == NULL)" >> $g_FUNCTIONS
    echo "{ delim = __b2c__option_delim; } len = __b2c__len(token); if(len==0) { return(0); } start = __b2c__delim_engine (2, &amount, string, delim, 0); for(x = 0; x < amount; x++)" >> $g_FUNCTIONS
    echo "{ start = __b2c__delim_engine_cache(1, &length, string, delim, x+1); if(len == length && memcmp(string + start, token, len) == 0) { result = x+1; break; } } return (result); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//uniq/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__uniq(char *string, char *delim) { long x, start, amount = 0, length = 0; int t = 1; __b2c__htable *table; char *item, *result; if(string == NULL) { return (string); }" >> $g_FUNCTIONS
    echo "if(delim == NULL) { delim = __b2c__option_delim; } start = __b2c__delim_engine (2, &amount, string, delim, 0); if(amount <= 1) { return (string); }" >> $g_FUNCTIONS
    echo "table = __b2c__hash_new(); for (x = 0; x < amount; x++) { start = __b2c__delim_engine_cache(1, &length, string, delim, x+1); item = __b2c__strndup(string+start, length);" >> $g_FUNCTIONS
    echo "if(!__b2c__hash_find_key(table, 0, item)) { __b2c__hash_add(table, &t, item); } __b2c__STRFREE(item); } result = __b2c__hash_obtain(table, delim);" >> $g_FUNCTIONS
    echo "__b2c__hash_clear(table); free(table); return(result); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//sortdelim/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__sort(char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char **array; char *buffer, *backup; long start, total = 0, x, len, dlen; long amount = 0; long length = 0;" >> $g_FUNCTIONS
    echo "if(string == NULL) { return (string); } if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } dlen = __b2c__len (delim); buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len(string)+1);" >> $g_FUNCTIONS
    echo "buffer = __b2c__strdup (string); backup = buffer; start = __b2c__delim_engine (2, &amount, buffer, delim, 0); array = (char **) calloc(amount, sizeof (char *)); for (x = 0; x < amount; x++)" >> $g_FUNCTIONS
    echo "{ start = __b2c__delim_engine (1, &length, string, delim, 1); buffer[start + length] = '\0'; if(buffer[start] == 34 && buffer[start+length-1] == 34) { buffer[start + length-1] = '\0';" >> $g_FUNCTIONS
    echo "array[x] = buffer + start + 1; } else { array[x] = buffer + start; } string += (start + length + dlen); buffer += (start + length + dlen); } qsort (&array[0], amount, sizeof (char *), __b2c__sortstr);" >> $g_FUNCTIONS
    echo "for (x = 0; x < amount; x++) { len = strlen (array[x]); if(strstr(array[x], delim)) { buf[idx][total] = 34; memmove(buf[idx] + total+1, array[x], len);" >> $g_FUNCTIONS
    echo "buf[idx][total+len+1] = 34; total += len+2;} else { memmove(buf[idx] + total, array[x], len); total += len; } if (x < amount - 1) { memmove(buf[idx] + total, delim, dlen);" >> $g_FUNCTIONS
    echo "total += dlen; } } __b2c__STRFREE(backup); free(array); __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//sortassoc/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "void __b2c__assoc_sort(__b2c__htable **name, int type, int (*compare) (const void *, const void *)) { char **results = {  NULL }; int total; char *value; __b2c__htable *ptr; int i; total =  __b2c__lookup_by_sort(*name, &results, 0, 0, type, compare);" >> $g_FUNCTIONS
    echo "ptr = __b2c__hash_new(); for (i = 0; i < total; i++) { value = (char *) __b2c__hash_find_value_do(*name, results[i]); if(type == 0) { __b2c__hash_add_str(ptr, value, results[i]); } else { __b2c__hash_add(ptr, value, results[i]); } } __b2c__hash_clear (*name); free (*name); *name = ptr;" >> $g_FUNCTIONS
    echo "if(results) { __b2c__free_str_array_members(&results, 0, total); free(results); } }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//revstr/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__rev(char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, total, x, len, dlen; long amount = 0; long length = 0; if (string == NULL) { return (string); }" >> $g_FUNCTIONS
    echo "len = __b2c__len (string); if (delim == NULL) { delim = __b2c__option_delim; } dlen = __b2c__len (delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0);" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + 1); total = len; for (x = 0; x < amount; x++) { start = __b2c__delim_engine_cache(1, &length, string, delim, x+1);" >> $g_FUNCTIONS
    echo "memmove(buf[idx] + total-length, string + start, length); total -= length; if (x < amount-1) { memmove(buf[idx] + total-dlen, delim, dlen); total -= dlen; } }" >> $g_FUNCTIONS
    echo "__b2c__SETLEN(buf[idx], len); buf[idx][len] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//delimstr/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__delim(char *string, char *from, char *to) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, total = 0, x, tlen, dlen; long amount = 0; long length = 0; if (string == NULL) { return (string); }" >> $g_FUNCTIONS
    echo "if(from == NULL) { from = __b2c__option_delim; } if(to == NULL) { to = __b2c__option_delim; } dlen = __b2c__len (from); tlen = __b2c__len (to); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, from, 0);" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len(string)+amount*tlen+1); for (x = 0; x < amount; x++) { start = __b2c__delim_engine (1, &length, string, from, 1); memmove(buf[idx] + total, string + start, length);" >> $g_FUNCTIONS
    echo "total += length; if (x < amount-1) { memmove(buf[idx] + total, to, tlen); total += tlen; } string += (start + length + dlen); } __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//head/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__head (char *string, long pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start; long amount = 0; long length = 0; if (string == NULL)" >> $g_FUNCTIONS
    echo "{ return (string); } if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0);" >> $g_FUNCTIONS
    echo "if(amount < 1 || pos < 1) { return (NULL); } if (pos > amount) { pos = amount; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len(string)+1); start = __b2c__delim_engine_cache(1, &length, string, delim, pos);" >> $g_FUNCTIONS
    echo "memmove(buf[idx], string, start + length); __b2c__SETLEN(buf[idx], start + length); buf[idx][start + length] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//tail/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__tail(char *string, long pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, slen; long amount = 0; long length = 0; if (string == NULL)" >> $g_FUNCTIONS
    echo "{ return (string); } if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0);" >> $g_FUNCTIONS
    echo "if (amount < 1 || pos < 1) { return (NULL); } if (amount - pos + 1 < 1) { pos = 1; } else { pos = amount - pos + 1; } slen = __b2c__len (string); buf[idx] = (char*)__b2c_str_realloc(buf[idx], slen+1);" >> $g_FUNCTIONS
    echo "start = __b2c__delim_engine_cache(1, &length, string, delim, pos); memmove(buf[idx], string + start, slen-start); __b2c__SETLEN(buf[idx], slen-start); buf[idx][slen-start] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//append/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__append(char **swap, int type, char *string, long pos, char *cnew, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, dlen, slen, nlen, total = 0; long amount = 0; long length = 0; if (cnew == NULL || pos < 0)" >> $g_FUNCTIONS
    echo "{ if (type == 1) { *swap = __b2c_Copy_String(*swap, string); } return (string); } if (delim == NULL) { delim = __b2c__option_delim; } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0);" >> $g_FUNCTIONS
    echo "dlen = __b2c__len (delim); nlen = __b2c__len (cnew); slen = __b2c__len (string); buf[idx] = (char *) __b2c_str_realloc (buf[idx], slen + nlen + dlen + 1); if (pos == 0 || pos > amount) { if (__b2c__collapse == 0 || (__b2c__collapse == 1 && slen > 0)) { memmove (buf[idx], string, slen);" >> $g_FUNCTIONS
    echo "total += slen; } if (__b2c__collapse == 0 || (__b2c__collapse == 1 && nlen > 0)) { if(__b2c__collapse == 0 || total) { memmove (buf[idx] + total, delim, dlen); total += dlen; } memmove (buf[idx] + total, cnew, nlen); total += nlen; } } else { start = __b2c__delim_engine_cache (1, &length, string, delim, pos);" >> $g_FUNCTIONS
    echo "memmove (buf[idx], string, start); total += start; memmove (buf[idx] + total, cnew, nlen); total += nlen; memmove (buf[idx] + total, delim, dlen); total += dlen; memmove (buf[idx] + total, string + start, slen - start); total += (slen - start); } __b2c__SETLEN (buf[idx], total);" >> $g_FUNCTIONS
    echo "buf[idx][total] = '\0'; if (type == 1) { return(__b2c_Swap_String(swap, &buf[idx])); } return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//delstr/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__del(char *string, long pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, slen, dlen, total = 0; long amount = 0; long length = 0; if (string == NULL)" >> $g_FUNCTIONS
    echo "{ return (string); } if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0); if (pos < 1 || pos > amount)" >> $g_FUNCTIONS
    echo "{ return(string); } dlen = __b2c__len (delim); slen = __b2c__len (string); buf[idx] = (char*)__b2c_str_realloc(buf[idx], slen + 1); start = __b2c__delim_engine_cache(1, &length, string, delim, pos); memmove(buf[idx], string, start);" >> $g_FUNCTIONS
    echo "total += start; if (pos < amount) { memmove(buf[idx] + total, string + start + length + dlen, slen-(start + length + dlen)); total += slen-(start + length + dlen); }" >> $g_FUNCTIONS
    echo "else { if(total >= dlen) { total -= dlen; } } __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//cut/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__cut(char *string, long pos1, long pos2, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start1, start2, tmp, total = 0; long amount = 0; long length = 0; if (string == NULL)" >> $g_FUNCTIONS
    echo "{ return (string); } if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } if (pos1 > pos2) { tmp = pos1; pos1 = pos2; pos2 = tmp; } __b2c__delim_engine (2, &amount, string, delim, 0);" >> $g_FUNCTIONS
    echo "if(pos1 < 1) { pos1 = 1; } if(pos2 > amount) { pos2 = amount; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len(string)+1); start1 = __b2c__delim_engine (1, &length, string, delim, pos1);" >> $g_FUNCTIONS
    echo "start2 = __b2c__delim_engine (1, &length, string, delim, pos2); memmove(buf[idx], string + start1, start2-start1+length); total += (start2-start1+length); __b2c__SETLEN(buf[idx], total);" >> $g_FUNCTIONS
    echo "buf[idx][total] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//align/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__align (int l, char *k, char *str, unsigned long width, int mode, int indent) { static unsigned char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, x, y, left, line_start = 0, paragraph_end = 0, last_write_pos, write_pos = 0, characters, last_read_pos, read_pos = 0, wtotal = 0, ctotal = 0, found = 0, tab, pos, spaces;" >> $g_FUNCTIONS
    echo "int quoted, collapse, utf8, preserve = 0; long amount = 0, length = 0, total, lw; char *string = NULL, *backup, *concat, *wrap, *line; if (str == NULL) { return (str); } if (width < 1) { return (NULL); } collapse = __b2c__collapse; quoted = __b2c__option_quoted; utf8 = __b2c__option_utf8; __b2c__option_quoted = 0; backup = string = __b2c__strdup (str);" >> $g_FUNCTIONS
    echo "if ((unsigned char) string[0] == 0xEF && (unsigned char) string[1] == 0xBB && (unsigned char) string[2] == 0xBF) { string += 3; __b2c__option_utf8 = 1; preserve = 1; } for (x = 0; string[x]; x++) { if (string[x] == 10 && string[x + 1] == 10) x++; else if (string[x] == 10) string[x] = 32; }" >> $g_FUNCTIONS
    echo "__b2c__collapse = 1; start = __b2c__delim_engine (2, &amount, string, \" \", 0); concat = (char *) calloc (x + amount + 1, sizeof (char)); for (x = 0; x < amount; x++) { start = __b2c__delim_engine_cache(1, &length, string, \" \", x+1); memmove (concat + ctotal, string + start, length); ctotal += length;" >> $g_FUNCTIONS
    echo "if (x < amount - 1) { memset (concat + ctotal, 32, 1); ctotal += 1; } } __b2c__STRFREE(backup); backup = wrap = (char *) calloc (ctotal*2 + 1, sizeof (char)); while (read_pos < ctotal) { if (*(concat + read_pos) == 32) { if (write_pos == 0) { read_pos++; continue; } else" >> $g_FUNCTIONS
    echo "{ last_write_pos = wtotal; last_read_pos = read_pos; found = 1; } } memmove (wrap + wtotal, concat + read_pos, 1); write_pos++; wtotal++; if (*(concat + read_pos) == 10) { write_pos = 0; line_start = wtotal; } else if ((__b2c__option_utf8 ? __b2c__ucs2_clen (l, k, \"ALIGN$\", wrap + line_start, write_pos) : write_pos) > width)" >> $g_FUNCTIONS
    echo "{ if (found) { memset (wrap + last_write_pos, 10, 1); wtotal = last_write_pos + 1; read_pos = last_read_pos; if (*(concat + read_pos + 1) == 10) { read_pos++; } } else { memset (wrap + wtotal, 10, 1); wtotal += 1; } found = 0; write_pos = 0; line_start = wtotal; } read_pos++; } __b2c__collapse = 0;" >> $g_FUNCTIONS
    echo "start = __b2c__delim_engine (2, &amount, wrap, \"\n\", 0); line_start = 0; idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (unsigned char*)__b2c_str_realloc((char*)buf[idx], amount * indent + amount * width * 4 + 3 + 1); if(preserve) { buf[idx][0] = 0xEF; buf[idx][1] = 0xBB; buf[idx][2] = 0xBF;" >> $g_FUNCTIONS
    echo "line_start += 3; } line = (char *) calloc (width * 4, sizeof (char)); for (x = 1; x <= amount; x++) { __b2c__collapse = 0; paragraph_end = 0; start = __b2c__delim_engine (1, &length, wrap, \"\n\", 1); if(length && (*(wrap + start + length + 1) == 10 || x == amount )) { paragraph_end = 1; } characters = (__b2c__option_utf8 ? __b2c__ucs2_clen (l, k, \"ALIGN$\", wrap + start, length) : length);" >> $g_FUNCTIONS
    echo "switch (mode) { case 0: memset (buf[idx] + line_start, 32, indent); line_start += indent; memmove (buf[idx] + line_start, wrap + start, length); line_start += length; memset (buf[idx] + line_start, 32, width - characters); line_start += (width - characters); if (x < amount) { memset (buf[idx] + line_start, '\n', 1); line_start++; } break;" >> $g_FUNCTIONS
    echo "case 1: memset (buf[idx] + line_start, 32, indent); line_start += indent; memset (buf[idx] + line_start, 32, width - characters); line_start += (width - characters); memmove (buf[idx] + line_start, wrap + start, length); line_start += length; if (x < amount) { memset (buf[idx] + line_start, '\n', 1); line_start++; } break;" >> $g_FUNCTIONS
    echo "case 2: tab = (width - characters) / 2; memset (buf[idx] + line_start, 32, indent + tab); line_start += (indent + tab); memmove (buf[idx] + line_start, wrap + start, length); line_start += length; memset (buf[idx] + line_start, 32, tab + (width - characters) % 2); line_start += (tab + (width - characters) % 2); if (x < amount)" >> $g_FUNCTIONS
    echo "{ memset (buf[idx] + line_start, '\n', 1); line_start++; } break; case 3: memmove (line, wrap + start, length); line[length] = '\0'; pos = __b2c__delim_engine (2, &total, line, \" \", 0); left = width - characters; spaces = total - 1; memset (buf[idx] + line_start, 32, indent); line_start += indent; for (y = 1; y <= total; y++)" >> $g_FUNCTIONS
    echo "{ pos = __b2c__delim_engine_cache (1, &lw, line, \" \", y); memmove (buf[idx] + line_start, line + pos, lw); line_start += lw; if(y<total) { memset (buf[idx] + line_start, 32, 1); line_start++; if (left && total > 1 && !paragraph_end && y > (spaces/2)-(left/2)) { tab = (left < spaces ? 1 : left / spaces); memset (buf[idx] + line_start, 32, tab); left -= tab;" >> $g_FUNCTIONS
    echo "spaces--; line_start += tab; } } } if (x < amount) { memset (buf[idx] + line_start, '\n', 1); line_start++; } break; } wrap += (start + length + 1); } free(backup); free (concat); free (line); __b2c__option_quoted = quoted; __b2c__collapse = collapse; __b2c__option_utf8 = utf8; __b2c__SETLEN (buf[idx], line_start); buf[idx][line_start] = '\0'; return (char *) (buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//bom/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c__hasbom(char *string) { if (string == NULL || __b2c__len(string) < 3) { return (0); } if ((unsigned char) string[0] == 0xEF && (unsigned char) string[1] == 0xBB && (unsigned char) string[2] == 0xBF) { return(1); } return(0); }" >> $g_FUNCTIONS
    echo "char *__b2c__editbom(char *string, int edit) { static unsigned char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int slen; if (string == NULL) { return(NULL); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } slen = __b2c__len(string);" >> $g_FUNCTIONS
    echo "buf[idx] = (unsigned char*)__b2c_str_realloc((char*)buf[idx], 3+slen+1); if(edit) { if ((unsigned char)string[0] == 0xEF && (unsigned char)string[1] == 0xBB && (unsigned char)string[2] == 0xBF) { return (string); } buf[idx][0] = 0xEF; buf[idx][1] = 0xBB;" >> $g_FUNCTIONS
    echo "buf[idx][2] = 0xBF; memcpy(buf[idx]+3, string, slen); __b2c__SETLEN(buf[idx], slen+3); buf[idx][slen+3] = '\0'; } else { if ((unsigned char)string[0] != 0xEF || (unsigned char)string[1] != 0xBB || (unsigned char)string[2] != 0xBF) { return(string); }" >> $g_FUNCTIONS
    echo "memcpy(buf[idx], string+3, slen-3); __b2c__SETLEN(buf[idx], slen-3); buf[idx][slen-3] = '\0'; } return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//proper/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char * __b2c__proper(int l, char *k, char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *local; long start, total = 0, x, y, dlen, blen; long amount = 0; long length = 0; wchar_t wcs[8] = { 0 }; if (string == NULL) { return (string); }" >> $g_FUNCTIONS
    echo "if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } dlen = __b2c__len (delim); start = __b2c__delim_engine (2, &amount, string, delim, 0); buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len (string)+1); if(__b2c__option_utf8)" >> $g_FUNCTIONS
    echo "{ local = setlocale (LC_ALL, \"\"); for (x = 0; x < amount; x++) { start = __b2c__delim_engine (1, &length, string, delim, 1); blen = __b2c__blen (l, k, \"PROPER$\", string + start, 1, 0); if (mbtowc (wcs, string + start, blen) == (int) - 1) { ERROR = 38; RUNTIMEFERR (\"PROPER$\", ERROR, k, l); return(NULL); }" >> $g_FUNCTIONS
    echo "*wcs = towupper (*wcs); if (wctomb(buf[idx] + total, *wcs) == (int) - 1) { ERROR = 38; RUNTIMEFERR (\"PROPER$\", ERROR, k, l); return(NULL); } for (y = blen; y < length; y += blen) { blen = __b2c__blen (l, k, \"PROPER$\", string + start + y, 1, 0); if (mbtowc (wcs, string + start + y, blen) == (int) - 1)" >> $g_FUNCTIONS
    echo "{ ERROR = 38; RUNTIMEFERR (\"PROPER$\", ERROR, k, l); return(NULL); } if(__b2c__option_proper == 0) { *wcs = towlower (*wcs); } if (wctomb(buf[idx] + total + y, *wcs) == (int) - 1) { ERROR = 38; RUNTIMEFERR (\"PROPER$\", ERROR, k, l); return(NULL); } } total += length; if (x < amount-1) { memmove(buf[idx] + total, delim, dlen);" >> $g_FUNCTIONS
    echo "total += dlen; } string += (start + length + dlen); } setlocale (LC_ALL, local); } else { for (x = 0; x < amount; x++) { start = __b2c__delim_engine (1, &length, string, delim, 1); *(buf[idx] + total) = toupper(*(string+start)); for (y = 1; y < length; y ++) { *(buf[idx]+total+y) = (__b2c__option_proper == 0 ? tolower(*(string+start+y)) : *(string+start+y)); }" >> $g_FUNCTIONS
    echo "total += length; if (x < amount-1) { memmove(buf[idx] + total, delim, dlen); total += dlen; } string += (start + length + dlen); } } __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//rotate/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__rotate (char *string, int pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, total = 0, x, dlen; long amount = 0, length = 0; char *next; if (string == NULL) { return (string); } if (delim == NULL) { delim = __b2c__option_delim; }" >> $g_FUNCTIONS
    echo "idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } dlen = __b2c__len (delim); start = __b2c__delim_engine (2, &amount, string, delim, 0); if (amount <= 1) { return (string); } if (abs (pos) >= amount) { pos = pos % amount; } if (pos == 0) { return (string); } if (pos < 0)" >> $g_FUNCTIONS
    echo "{ pos = amount + pos; } next = string; buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len (string) + 1); start = __b2c__delim_engine (1, &length, string, delim, amount-pos+1); string += start; for (x = amount - pos; x < amount; x++) { start = __b2c__delim_engine (1, &length, string, delim, 1);" >> $g_FUNCTIONS
    echo "memmove(buf[idx] + total, string + start, length); total += length; memmove(buf[idx] + total, delim, dlen); total += dlen; string += (start + length + dlen); } for (x = 0; x < amount - pos; x++) { start = __b2c__delim_engine (1, &length, next, delim, 1);" >> $g_FUNCTIONS
    echo "memmove(buf[idx] + total, next + start, length); total += length; if (x < amount - pos - 1) { memmove(buf[idx] + total, delim, dlen); total += dlen; } next += (start + length + dlen); }" >> $g_FUNCTIONS
    echo "__b2c__SETLEN(buf[idx], total);buf[idx][total] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//last/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__last (char *string, int pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, slen; long amount = 0; long length = 0; if (string == NULL) { return (string); } if (delim == NULL) { delim = __b2c__option_delim; }" >> $g_FUNCTIONS
    echo "idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0); if (pos <= 0) { return (string); } if (amount < 1 || pos >= amount) { return (NULL); } slen = __b2c__len (string); buf[idx] = (char*)__b2c_str_realloc(buf[idx], slen + 1);" >> $g_FUNCTIONS
    echo "start = __b2c__delim_engine_cache(1, &length, string, delim, pos+1); memmove(buf[idx], string + start, slen-start); __b2c__SETLEN(buf[idx], slen-start); buf[idx][slen-start] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//first/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char * __b2c__first (char *string, int pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long dlen, end; long amount = 0; long length = 0; if (string == NULL) { return (string); } if (delim == NULL) { delim = __b2c__option_delim; }" >> $g_FUNCTIONS
    echo "idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } end = __b2c__delim_engine (2, &amount, string, delim, 0); if (pos <= 0) { return (string); } if (amount < 1 || pos >= amount) { return (NULL); } buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len (string)+1);" >> $g_FUNCTIONS
    echo "end = __b2c__delim_engine_cache(1, &length, string, delim, amount-pos+1); dlen = __b2c__len (delim); memmove(buf[idx], string, end-dlen); __b2c__SETLEN(buf[idx], end-dlen); buf[idx][end-dlen] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//match/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c__match(char *string1, char *string2, long count, char *delim) { long dlen, start1, start2, amount1, amount2, length1, length2, tmplen; int x, found = 1, wildcard = 0, after = 0; if (string1 == NULL && string2 == NULL) { return (1); }" >> $g_FUNCTIONS
    echo "if (count == 0) { return (1); } if (delim == NULL) { delim = __b2c__option_delim; } start1 = __b2c__delim_engine (2, &amount1, string1, delim, 0); if (count > amount1) { return (0); } if(count == -1) { count = amount1; } dlen = __b2c__len (delim);" >> $g_FUNCTIONS
    echo "for (x = 0; x < count; x++) { start1 = __b2c__delim_engine (1, &length1, string1, delim, 1); start2 = __b2c__delim_engine (1, &length2, string2, delim, 1); if (length1 == 0) { found = wildcard; break; } if (length2 == 0)" >> $g_FUNCTIONS
    echo "{ found = wildcard; break; } if (strncmp (string2, \"?\", 1)) { if (!strncmp (string2, \"*\", 1)) { wildcard = 1; __b2c__delim_engine (2, &amount2, string2+1, delim, 0); if(amount2) { after = 1; string2+=1+dlen; } else { after = 0; found = wildcard; break; } }" >> $g_FUNCTIONS
    echo "else { if (!strncmp (string2, \"\\\\?\", 2) || !strncmp (string2, \"\\\\*\", 2)) { string2++; length2--; } } __b2c__delim_engine (1, &tmplen, string2, delim, 1); if(length1 != tmplen || memcmp (string1, string2, tmplen)) { if (wildcard == 0) { found = 0; break; } else { string2 = string2-1-dlen; } }" >> $g_FUNCTIONS
    echo "else { wildcard = 0; after = 0; } if(wildcard == 0) { string2 += (start2 + length1 + dlen); } } else { string2 += (start2 + length2 + dlen); } string1 += (start1 + length1 + dlen); } if(after) { found = 0; } return (found); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//explode/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__explode (int l, char *k, char *string, int pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long x, dlen, len, blen, ctr=0, where = 0, escaped = 0, in_string = 0; if (string == NULL || pos <= 0 || pos >= (len = __b2c__len (string)) ) { return (string); } if (delim == NULL) { delim = __b2c__option_delim; }" >> $g_FUNCTIONS
    echo "dlen = __b2c__len (delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } blen = pos; buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + (len - 1) * dlen + 1); for (x = 0; x < len; x += blen) { if (__b2c__option_utf8) { blen = __b2c__blen(l, k, \"EXPLODE$\", string + x, pos, 0); } if(*(string+x) == __b2c__option_esc) { escaped = 1 - escaped; } if(*(string+x) == 34)" >> $g_FUNCTIONS
    echo "{ if(!escaped && __b2c__option_quoted) { in_string = 1 - in_string; } escaped = 0; } else { escaped = 0; } memmove(buf[idx] + where, string + x, blen); where+=blen; if (x < (len - blen) && !in_string) { memmove(buf[idx] + where, delim, dlen); where+=dlen; ctr+=dlen; } } __b2c__SETLEN(buf[idx], len+ctr); buf[idx][len+ctr] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//merge/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__merge(char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, total = 0, x; long amount = 0; long length = 0; if (string == NULL) { return (string); }" >> $g_FUNCTIONS
    echo "if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0); buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len (string) + 1); for(x = 1; x <= amount; x++)" >> $g_FUNCTIONS
    echo "{ start = __b2c__delim_engine_cache(1, &length, string, delim, x); memmove(buf[idx] + total, string + start, length); total += length; } __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//between/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__inbetween(int flag, char *haystack, char *lm, char *rm, int greedy) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *l, *pos; int collapse; long len, start, end=0, in, w1, w2; long length = 0;" >> $g_FUNCTIONS
    echo "if (haystack == NULL || lm == NULL || rm == NULL) { return (NULL); } collapse = __b2c__collapse; __b2c__collapse = 0; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &length, haystack, lm, 2);" >> $g_FUNCTIONS
    echo "if (start == 0) { __b2c__collapse = collapse; return (NULL); } if (greedy == 0) { in = __b2c__delim_engine (2, &length, haystack+start+end, rm, 2); if (in == 0) { __b2c__collapse = collapse; return (NULL); }" >> $g_FUNCTIONS
    echo "l = haystack+start-__b2c__len(lm); pos = haystack+start+in-__b2c__len(rm); } else if (greedy == 1) { while (1) { in = __b2c__delim_engine (2, &length, haystack+start+end, rm, 2); if(in) { end += in; } else { break; } }" >> $g_FUNCTIONS
    echo "if (end == 0) { __b2c__collapse = collapse; return (NULL); } l = haystack+start-__b2c__len(lm); pos = haystack+start+end-__b2c__len(rm); } else { w1 = start; w2 = start;" >> $g_FUNCTIONS
    echo "while (1) { end = __b2c__delim_engine (2, &length, haystack + w1, rm, 2); if (end == 0) { __b2c__collapse = collapse; return (NULL); } in = __b2c__delim_engine (2, &length, haystack + w2, lm, 2); if (in && ((w2 + in) < (w1 + end)))" >> $g_FUNCTIONS
    echo "{ w1 = w1 + end; w2 = w2 + in; } else { break; } } l = haystack + start - __b2c__len (lm); pos = haystack + w1 + end - __b2c__len (rm); } if (flag) { pos += strlen (rm); len = strlen (pos); buf[idx] = (char*)__b2c_str_realloc(buf[idx], (l - haystack) + len + 1);" >> $g_FUNCTIONS
    echo "memmove(buf[idx], haystack, l - haystack); memmove(buf[idx] + (l - haystack), pos, len); __b2c__SETLEN(buf[idx], (l - haystack) + len); buf[idx][(l - haystack) + len] = '\0'; } else" >> $g_FUNCTIONS
    echo "{ l += strlen (lm); buf[idx] = (char*)__b2c_str_realloc(buf[idx], pos - l + 1); memmove(buf[idx], l, pos - l); __b2c__SETLEN(buf[idx], pos - l); buf[idx][pos - l] = '\0'; } __b2c__collapse = collapse; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//ucase/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char * __b2c__ucase(int l, char *k, char *src) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len, i; size_t mbslen; wchar_t *wcs, *wp; char *local; if (src == NULL) { return (NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } len = __b2c__len (src);" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + 1); if(__b2c__option_utf8) { local = setlocale (LC_ALL, \"\"); if ((mbslen = mbstowcs (NULL, src, 0)) == (size_t) - 1) { ERROR = 38; RUNTIMEFERR (\"UCASE$\", ERROR, k, l); return(NULL); } wcs = (wchar_t*)calloc (mbslen + 1, sizeof (wchar_t)); if (mbstowcs (wcs, src, mbslen + 1) == (size_t) - 1)" >> $g_FUNCTIONS
    echo "{ ERROR = 38; RUNTIMEFERR (\"UCASE$\", ERROR, k, l); return(NULL); } for (wp = wcs; *wp != 0; wp++) { *wp = towupper (*wp); } if(wcstombs(buf[idx], wcs, len) == (size_t) - 1) { ERROR = 38; RUNTIMEFERR (\"UCASE$\", ERROR, k, l); return(NULL); } free (wcs);" >> $g_FUNCTIONS
    echo "setlocale(LC_ALL, local); } else { for (i = 0; i < len; i++) { buf[idx][i] = toupper (src[i]); } } __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//utf8/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c_utf8_conv(int txt, char* utf8) { unsigned char b1, b2, b3; int len; if (txt > 0xFFFF) { b1 = txt & 0x0000FF; b2 = (txt & 0x00FF00) >> 8; b3 = (txt & 0xFF0000) >> 16;" >> $g_FUNCTIONS
    echo "len = snprintf (utf8, 5, \"%c%c%c%c\", 0xF0 | (b3 >> 2), 0x80 | ((b3 & 0x03) << 4) | ((b2 & 0xF0) >> 4), 0x80 | ((b2 & 0x0F) << 2) | ((b1 & 0xC0) >> 6)," >> $g_FUNCTIONS
    echo "0x80 | (b1 & 0x3F)); } else if (txt > 0x07FF) { b1 = txt & 0x00FF; b2 = (txt & 0xFF00) >> 8; len = snprintf (utf8, 4, \"%c%c%c\", 0xE0 | ((b2 & 0xF0) >> 4)," >> $g_FUNCTIONS
    echo "0x80 | ((b2 & 0x0F) << 2) | ((b1 & 0xC0) >> 6), 0x80 | (b1 & 0x3F)); } else if (txt > 0x007F) { b1 = txt & 0x00FF; b2 = (txt & 0xFF00) >> 8; len = snprintf (utf8, 3, \"%c%c\"," >> $g_FUNCTIONS
    echo "0xC0 | (b2 << 2) | ((b1 & 0xC0) >> 6), 0x80 | (b1 & 0x3F)); } else { len = snprintf (utf8, 2, \"%c\", txt & 0x7F); } return(len); }" >> $g_FUNCTIONS
    echo "unsigned long __b2c__ulen (int l, char *k, char *func, char *ptr, int pos) { long len = 0; if (ptr == NULL) { return(0); } if(pos < 0) { while(*ptr){ if((*ptr&0xF0) == 0xF0) { len++; ptr += 4; } else if((*ptr&0xE0) == 0xE0) { len++; ptr += 3; }" >> $g_FUNCTIONS
    echo "else if((*ptr&0xC0) == 0xC0) { len++; ptr += 2; } else if((*ptr&0x80) == 0) { len++; ptr++; } else { ERROR = 38; RUNTIMEFERR(func, ERROR, k, l); return(0); } } } else { len = __b2c__ucs2_clen(l, k, \"ULEN\", ptr, pos); } return(len); }" >> $g_FUNCTIONS
    echo "unsigned long __b2c__blen (int l, char *k, char *func, char *ptr, long c, int flag) { char *org = ptr; if (ptr == NULL){ return (0); }" >> $g_FUNCTIONS
    echo "if(flag) { c = __b2c__ulen (l, k, \"BYTELEN\", org, -1)-c; } while (*ptr && c > 0) { if ((*ptr & 0xF0) == 0xF0) { ptr += 4; } else if ((*ptr & 0xE0) == 0xE0) { ptr += 3; } else if ((*ptr & 0xC0) == 0xC0) { ptr += 2; } else if ((*ptr & 0x80) == 0)" >> $g_FUNCTIONS
    echo "{ ptr++; } else { ERROR = 38; fprintf (stderr, \"Cannot decode UTF-8 string: '%s'\n\", org); RUNTIMEFERR (func, ERROR, k, l); return(0); } c--; } if(flag) { return (__b2c__len(org) - (ptr - org)); } else { return (ptr - org); } }" >> $g_FUNCTIONS
    echo "unsigned long __b2c__ucs2_clen (int l, char* k, char *func, char *ptr, int c) { int len = 0; char *org; if (ptr == NULL) return (0); org = ptr; while (*ptr && c > 0) { if ((*ptr & 0xF0) == 0xF0) { ptr += 4; c -= 4; } else if ((*ptr & 0xE0) == 0xE0)" >> $g_FUNCTIONS
    echo "{ ptr += 3; c -= 3; } else if ((*ptr & 0xC0) == 0xC0) { ptr += 2; c -= 2; } else if ((*ptr & 0x80) == 0) { ptr++; c--; } else { ERROR = 38; fprintf(stderr, \"Cannot decode UTF-8 string: '%s'\n\", org); RUNTIMEFERR (func, ERROR, k, l); return(0); } len++; } return (len); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//wait/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "long __b2c__netpeek(int l, char *k, uintptr_t fd, int usec){fd_set rfds; struct timeval tv; int desc = 0; long retval; struct termios oldt = { 0 }, newt = { 0 }; if(fd == STDIN_FILENO){tcgetattr(STDIN_FILENO, &oldt);" >> $g_FUNCTIONS
    echo "newt = oldt; newt.c_lflag &= ~(ICANON | ECHO); newt.c_cc[VMIN]=1; newt.c_cc[VTIME]=0; tcsetattr(STDIN_FILENO, TCSANOW, &newt);} tv.tv_usec = (usec%1000)*1000; tv.tv_sec = usec/1000; FD_ZERO(&rfds);" >> $g_FUNCTIONS
    echo "if(fd == STDIN_FILENO) { desc = fd; } else {" >> $g_FUNCTIONS
    if [[ ${g_OPTION_TLS} = +(1*|TRUE*) ]]
    then
        if [[ ${g_LIB_TLS} = +(*gnutls*) ]]
        then
            echo "if(__b2c__option_tls) { BIO_get_fd(((SSL*)fd)->gnutls_state, &desc); }" >> $g_FUNCTIONS
        else
            echo "if(__b2c__option_tls) { desc = SSL_get_fd((SSL*)fd); }" >> $g_FUNCTIONS
        fi
    fi
    echo "if(!__b2c__option_tls) { desc = fd; } }" >> $g_FUNCTIONS
    echo "FD_SET(desc, &rfds); retval = select(desc + 1, &rfds, NULL, NULL, &tv); if(retval == -1 && __b2c__trap) { ERROR = 16; RUNTIMEFERR(\"WAIT\", ERROR, k, l); return(0); }" >> $g_FUNCTIONS
    echo "if(fd == STDIN_FILENO){ if(retval) if(read(fd, &retval, 1)==0) { retval=0; } tcsetattr(STDIN_FILENO, TCSANOW, &oldt);} return(retval); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//extract/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__extract_core(int action, int l, char *k, char *src, char *needle, int flag) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int reti = 0, len, pos = 0; char *tmp; regex_t regex; char __b2c__buf[100]; regmatch_t where[1];" >> $g_FUNCTIONS
    echo "static __b2c__htable *table_icase = NULL, *table_normal = NULL; void *found = NULL; if(action == 0) { __b2c__hash_clear_regfree(table_icase); free(table_icase); __b2c__hash_clear_regfree(table_normal); free(table_normal); return(NULL); } if (src == NULL || needle == NULL) { return (src); } if (__b2c__len (src) == 0 || __b2c__len (needle) == 0) { return (src); } idx++; if (idx == __b2c_STRING_FUNC)" >> $g_FUNCTIONS
    echo "{ idx = 0; } buf[idx] = (char *) __b2c_str_realloc (buf[idx], __b2c__len (src) + 1); if (flag > 0) { if (__b2c__option_compare == 0) { if (table_normal == NULL) { table_normal = __b2c__hash_new(); } found = __b2c__hash_find_value_do(table_normal, needle);" >> $g_FUNCTIONS
    echo "if(!found) { reti = regcomp(&regex, needle, REG_EXTENDED); if (reti == 0) { __b2c__hash_add_data(table_normal, (void *) &regex, sizeof(regex), needle); } } else { regex = *(regex_t*)found; } } else { if (table_icase == NULL) { table_icase = __b2c__hash_new (); }" >> $g_FUNCTIONS
    echo "found = __b2c__hash_find_value_do(table_icase, needle); if (!found) { reti = regcomp (&regex, needle, REG_EXTENDED|REG_ICASE); if (reti == 0) { __b2c__hash_add_data (table_icase, (void *) &regex, sizeof (regex), needle); } } else { regex = *(regex_t*)found; } }" >> $g_FUNCTIONS
    echo "if (__b2c__trap && reti) { ERROR = 27; regerror (reti, &regex, __b2c__buf, sizeof (__b2c__buf)); fprintf (stderr, \"%s\n\", __b2c__buf); RUNTIMEFERR(\"EXTRACT$\", ERROR, k, l); return (NULL); } while ((reti = regexec (&regex, src, 1, where, 0)) == 0)" >> $g_FUNCTIONS
    echo "{ memcpy (buf[idx] + pos, src, (size_t) where[0].rm_so); pos += where[0].rm_so; src += (long) where[0].rm_eo; } len = strlen (src); memcpy (buf[idx] + pos, src, len); pos += len; } else { while ((tmp = strstr (src, needle)) != NULL)" >> $g_FUNCTIONS
    echo "{ memcpy (buf[idx] + pos, src, (size_t) (tmp - src)); pos += tmp - src; src = tmp + __b2c__len (needle); } len = strlen (src); memcpy (buf[idx] + pos, src, len); pos += len; } __b2c__SETLEN (buf[idx], pos); buf[idx][pos] = '\0'; return (char *) (buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//regex/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "long __b2c__regex_core (int action, int l, char *k, char *x, char *y) { regex_t reg; int reti = 0; char buf[100]; regmatch_t where[1]; static __b2c__htable *table_icase = NULL, *table_normal = NULL; void *found = NULL; if(action == 0) { __b2c__hash_clear_regfree(table_icase); free(table_icase); __b2c__hash_clear_regfree(table_normal); free(table_normal);" >> $g_FUNCTIONS
    echo "return(0); } if (x == NULL || y == NULL) { return (0); } if (__b2c__option_compare == 0) { if (table_normal == NULL) { table_normal = __b2c__hash_new(); } found = __b2c__hash_find_value_do (table_normal, y); if (!found) { reti = regcomp (&reg, y, REG_EXTENDED); if (reti == 0) { __b2c__hash_add_data (table_normal, (void *) &reg, sizeof (reg), y); } }" >> $g_FUNCTIONS
    echo "else { reg = *(regex_t*)found; } } else { if (table_icase == NULL) { table_icase = __b2c__hash_new(); } found = __b2c__hash_find_value_do (table_icase, y); if (!found) { reti = regcomp (&reg, y, REG_EXTENDED | REG_ICASE); if (reti == 0) { __b2c__hash_add_data (table_icase, (void *) &reg, sizeof (reg), y); } }" >> $g_FUNCTIONS
    echo "else { reg = *(regex_t*)found; } } if (__b2c__trap && reti) { ERROR = 27; regerror (reti, &reg, buf, sizeof (buf)); fprintf(stderr, \"%s\n\", buf); RUNTIMEFERR(\"REGEX\", ERROR, k, l); return (0); } reti = regexec (&reg, x, 1, where, 0); if (!reti) { REGLEN = where[0].rm_eo - where[0].rm_so;" >> $g_FUNCTIONS
    echo "return (where[0].rm_so + 1); } else { REGLEN = 0; return (0); } }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//replace/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__replace_core (int action, int l, char *k, char *haystack, char *needle, char *replace, int flag) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *tmp; long replen, hstlen, ndllen, length = 0; regex_t regex; int i, reti = 0; char buffer[100]; regmatch_t where[1];" >> $g_FUNCTIONS
    echo "static __b2c__htable *table_icase = NULL, *table_normal = NULL; void *found = NULL; if(action == 0) { __b2c__hash_clear_regfree(table_icase); free(table_icase); __b2c__hash_clear_regfree(table_normal); free(table_normal); return(NULL); } if (haystack == NULL || needle == NULL) { return (haystack); } if (replace == NULL) { replace = __b2c_EMPTYSTRING; } ndllen = __b2c__len (needle); hstlen = __b2c__len (haystack); if (hstlen == 0 || ndllen == 0)" >> $g_FUNCTIONS
    echo "{ return (haystack); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } if (flag == 2) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], hstlen + 1); strncpy (buf[idx], haystack, hstlen); for (i = 0; i < hstlen; i++) { if ((tmp = strchr (needle, buf[idx][i])) != NULL) { buf[idx][i] = replace[tmp - needle]; } }" >> $g_FUNCTIONS
    echo "__b2c__SETLEN (buf[idx], i); buf[idx][i] = '\0'; return (char *) (buf[idx]); } buf[idx] = (char *) __b2c_str_realloc (buf[idx], sizeof (char)); buf[idx][0] = '\0'; replen = __b2c__len (replace); if (flag == 1) { if (__b2c__option_compare == 0) { if (table_normal == NULL) { table_normal = __b2c__hash_new (); }" >> $g_FUNCTIONS
    echo "found = __b2c__hash_find_value_do(table_normal, needle); if (!found) { reti = regcomp (&regex, needle, REG_EXTENDED); if (reti == 0) { __b2c__hash_add_data (table_normal, (void *) &regex, sizeof (regex), needle); } } else { regex = *(regex_t*)found; } } else { if (table_icase == NULL)" >> $g_FUNCTIONS
    echo "{ table_icase = __b2c__hash_new (); } found = __b2c__hash_find_value_do(table_icase, needle); if (!found) { reti = regcomp (&regex, needle, REG_EXTENDED | REG_ICASE); if (reti == 0) { __b2c__hash_add_data (table_icase, (void *) &regex, sizeof (regex), needle); } } else { regex = *(regex_t*)found; } }" >> $g_FUNCTIONS
    echo "if (__b2c__trap && reti) { ERROR = 27; regerror (reti, &regex, buffer, sizeof (buffer)); fprintf (stderr, \"%s\n\", buffer); RUNTIMEFERR (\"REPLACE$\", ERROR, k, l); return (NULL); } while ((reti = regexec (&regex, haystack, 1, where, 0)) == 0) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + where[0].rm_so + replen + 1);" >> $g_FUNCTIONS
    echo "memcpy (buf[idx] + length, haystack, (size_t) where[0].rm_so); length += where[0].rm_so; memcpy (buf[idx] + length, replace, replen); length += replen; haystack += (long) where[0].rm_eo; }} else { while ((tmp = strstr (haystack, needle)) != NULL) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + tmp - haystack + replen + 1);" >> $g_FUNCTIONS
    echo "memcpy (buf[idx] + length, haystack, (size_t) (tmp - haystack)); length += tmp - haystack; memcpy (buf[idx] + length, replace, replen); length += replen; haystack = tmp + ndllen; }} hstlen = strlen (haystack); buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + hstlen + 1); memcpy (buf[idx] + length, haystack, hstlen);" >> $g_FUNCTIONS
    echo "length += hstlen; __b2c__SETLEN (buf[idx], length); buf[idx][length] = '\0'; return (char *) (buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//walk/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "#ifndef PATH_MAX" >> $g_FUNCTIONS
    echo "#define PATH_MAX 4096" >> $g_FUNCTIONS
    echo "#endif" >> $g_FUNCTIONS
    echo "static int __b2c__walk_filter_file(regex_t reg, char *file, int type, struct stat bf) { regmatch_t where[1]; if (regexec(&reg, file, 1, where, 0) == 0) { if (((type & 1) && S_ISREG(bf.st_mode)) || ((type & 2) && S_ISDIR(bf.st_mode)) || ((type & 4) && S_ISCHR(bf.st_mode)) || ((type & 8) && S_ISBLK(bf.st_mode)) ||" >> $g_FUNCTIONS
    echo " ((type & 16) && S_ISFIFO(bf.st_mode)) || ((type & 32) && S_ISLNK(bf.st_mode)) || ((type & 64) && S_ISSOCK(bf.st_mode))) { return(1); } } return(0); }" >> $g_FUNCTIONS
    echo "static int __b2c__walk_each_file_recurse(regex_t reg, char **buf, char *dir, int type, char *delim) { FTS *fts; FTSENT *ent; struct stat bf; char *item[2]; int dlen, flen, total = 0, result = 0; item[0] = dir; item[1] = NULL; fts = fts_open(item, FTS_PHYSICAL | FTS_NOCHDIR | FTS_XDEV, NULL); if(fts == NULL)" >> $g_FUNCTIONS
    echo "{ return(-1); } dlen = __b2c__len(delim); while(1) { ent = fts_read(fts); if(ent == NULL) { break; } if (lstat(ent->fts_path, &bf) < 0 && __b2c__trap) { result = -1; break; } if(__b2c__walk_filter_file(reg, ent->fts_path, type, bf))" >> $g_FUNCTIONS
    echo "{ if(ent->fts_info != FTS_D) { flen = __b2c__len(ent->fts_path); *buf = (char*)__b2c_str_realloc(*buf, total+flen+dlen+1); memcpy(*buf+total, ent->fts_path, flen); memcpy(*buf+total+flen, delim, dlen);" >> $g_FUNCTIONS
    echo "total += flen + dlen; } } } if(total == 0) { dlen = 0; } __b2c__SETLEN(*buf, total-dlen); (*buf)[total - dlen] = '\0'; fts_close(fts); return (result); }" >> $g_FUNCTIONS
    echo "static int __b2c__walk_each_file_dir (regex_t reg, char **buf, const char *dir, int type, char *delim) { DIR *here; struct dirent *item; struct stat bf; int dlen, flen, plen, total = 0, result = 0; char path[PATH_MAX] = { 0 }; here = opendir (dir); if (here == NULL) { return (-1); } dlen = __b2c__len(delim); plen = strlen(dir);" >> $g_FUNCTIONS
    echo "if (plen >= PATH_MAX) { return (-1); } strncpy (path, dir, PATH_MAX - 1); plen++; if (plen >= PATH_MAX) { return (-1); } strncat (path, \"/\", PATH_MAX - plen - 1); while (1) { item = readdir (here); if (item == NULL) { break; } if (!strcmp (item->d_name, \".\") || !strcmp (item->d_name, \"..\")) { continue; } memset (path + plen, 0, 1);" >> $g_FUNCTIONS
    echo "flen = strlen(item->d_name); if (plen + flen >= PATH_MAX) { return (-1); } strncat (path, item->d_name, PATH_MAX - plen - 1); flen += plen; if (lstat (path, &bf) < 0 && __b2c__trap) { result = -1; break; } if (__b2c__walk_filter_file (reg, path, type, bf)) { *buf = (char*)__b2c_str_realloc(*buf, total + flen + dlen + 1);" >> $g_FUNCTIONS
    echo "memcpy(*buf+total, path, flen); memcpy(*buf+total+flen, delim, dlen); total += flen + dlen; } } if(total == 0) { dlen = 0; } __b2c__SETLEN(*buf, total - dlen); (*buf)[total - dlen] = '\0'; closedir (here); return (result); }" >> $g_FUNCTIONS
    echo "char *__b2c__walk_core(int action, int l, char *k, char *dir, int type, char *exp, int recurse, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; regex_t reg; char buffer[100]; int reti = 0; static __b2c__htable *table_icase = NULL, *table_normal = NULL; void *found = NULL; if(action == 0) { __b2c__hash_clear_regfree(table_icase); free(table_icase); __b2c__hash_clear_regfree(table_normal); free(table_normal); return(NULL); } if (dir == NULL || exp == NULL)" >> $g_FUNCTIONS
    echo "{ return (NULL); } if (delim == NULL) { delim = __b2c__option_delim; } if ((type < 1 || type > 127) && __b2c__trap) { ERROR = 5; RUNTIMEFERR(\"WALK$\", ERROR, k, l); return (NULL); } if (__b2c__option_compare == 0) { if (table_normal == NULL) { table_normal = __b2c__hash_new (); } found = __b2c__hash_find_value_do (table_normal, exp);" >> $g_FUNCTIONS
    echo "if (!found) { reti = regcomp (&reg, exp, REG_EXTENDED); if (reti == 0) { __b2c__hash_add_data (table_normal, (void *) &reg, sizeof (reg), exp); } } else { reg = *(regex_t*)found; } } else { if (table_icase == NULL) { table_icase = __b2c__hash_new (); } found = __b2c__hash_find_value_do (table_icase, exp); if (!found)" >> $g_FUNCTIONS
    echo "{ reti = regcomp (&reg, exp, REG_EXTENDED | REG_ICASE); if (reti == 0) { __b2c__hash_add_data (table_icase, (void *) &reg, sizeof (reg), exp); } } else { reg = *(regex_t*)found; } } if (__b2c__trap && reti) { ERROR = 27; regerror (reti, &reg, buffer, sizeof (buffer)); fprintf(stderr, \"%s\n\", buffer); RUNTIMEFERR(\"WALK$\", ERROR, k, l);" >> $g_FUNCTIONS
    echo "return (NULL); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char *) __b2c_str_realloc (buf[idx], PATH_MAX * sizeof (char)); if (recurse) { if (__b2c__walk_each_file_recurse (reg, &buf[idx], dir, type, delim) == -1) { ERROR = 24; RUNTIMEFERR(\"WALK$\", ERROR, k, l); return (NULL); } } else" >> $g_FUNCTIONS
    echo "{ if (__b2c__walk_each_file_dir (reg, &buf[idx], dir, type, delim) == -1) { ERROR = 24; RUNTIMEFERR (\"WALK$\", ERROR, k, l); return (NULL); } } return (char *) (buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//eval/} != ${TOTAL} || ${g_OPTION_EVAL} -eq 1 ]]
then
    echo "#include <matheval.h>" >> $g_FUNCTIONS
    echo "double __b2c__eval(int l, char *k, char **vars, double *vals, int nr, char *expr) { void *f; double result; if (expr == NULL) return (0); f = evaluator_create(expr);" >> $g_FUNCTIONS
    echo "if(f) { result = evaluator_evaluate(f, nr, vars, vals); } else if (__b2c__trap) { ERROR = 39; RUNTIMEFERR(\"EVAL\", ERROR, k, l); return(0); } evaluator_destroy(f); return(result); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//getfile/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo -e "void __b2c__getfile(int l, char *k, char **result, DIR * from, int *type) { struct dirent *dir; *type = -1; dir = readdir (from); if (dir != NULL) { *result = __b2c__strdup (dir->d_name);\n#ifdef _DIRENT_HAVE_D_TYPE\nswitch (dir->d_type) { case DT_UNKNOWN: *type = 0; break;" >> $g_FUNCTIONS
    echo "case DT_REG: *type = 1; break; case DT_DIR: *type = 2; break; case DT_FIFO: *type = 5; break; case DT_SOCK: *type = 7; break; case DT_CHR: *type = 3; break; case DT_BLK: *type = 4; break; case DT_LNK: *type = 6; break; default: if(__b2c__trap)" >> $g_FUNCTIONS
    echo -e "{ ERROR = 24; RUNTIMEFERR(\"GETFILE\", ERROR, k, l); return; } }\n#endif\n } else { *result = NULL; } }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//copy/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c__copy(const char *from, const char *to) { char buffer[${g_BUFFER_SIZE}]; FILE *in, *out; size_t size; in = fopen(from, \"r\"); out = fopen(to, \"w\"); if(in == NULL || out == NULL) { return(1); }" >> $g_FUNCTIONS
    echo "while((size = fread(buffer, sizeof(char), ${g_BUFFER_SIZE}, in)) > 0) { if(fwrite(buffer, sizeof(char), size, out) != size) { return(1); } } fclose(in); fclose(out); return(0); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//input/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "void __b2c__input(int l, char *k, char **result, char *sep) { size_t size; ssize_t total; size = ${g_BUFFER_SIZE}; *result = (char*)calloc(${g_BUFFER_SIZE}, sizeof(char));" >> $g_FUNCTIONS
    echo "total = getdelim(&(*result), &size, ASC(sep), stdin); if(total == 0) { free(*result); *result = NULL; } else if(total > 0 && (*result)[total-1] == ASC(sep)) { (*result)[total-1] = '\0'; } else if (__b2c__trap) { ERROR = 2; RUNTIMEFERR(\"INPUT\", ERROR, k, l); } }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//readln/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "void __b2c__readln(char **result, FILE *from) { size_t size; ssize_t total; size = ${g_BUFFER_SIZE}; *result = (char*)calloc(${g_BUFFER_SIZE}, sizeof(char));" >> $g_FUNCTIONS
    echo "total = getline(&(*result), &size, from); if(total == 0) { free(*result); *result = NULL; } else if(total > 0 && (*result)[total-1] == '\n') { (*result)[total-1] = '\0'; } }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//return/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__return (char *data) { static char *rbuffer[${g_MAX_RBUFFERS}] = { NULL }; static int rbuffer_ptr = 0; size_t size; if(data == NULL) { return(NULL); } size = __b2c__len (data); if(size == 0) { return(NULL); }" >> $g_FUNCTIONS
    echo "rbuffer_ptr++; if(rbuffer_ptr >= ${g_MAX_RBUFFERS}) { rbuffer_ptr = 0; } rbuffer[rbuffer_ptr] = (char *) __b2c_str_realloc (rbuffer[rbuffer_ptr], size + 1); memcpy (rbuffer[rbuffer_ptr], data, size + 1);" >> $g_FUNCTIONS
    echo "__b2c__SETLEN (rbuffer[rbuffer_ptr], size); rbuffer[rbuffer_ptr][size] = '\0'; return (rbuffer[rbuffer_ptr]); }" >> $g_FUNCTIONS

fi

if [[ ${TOTAL//join/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "void __b2c__join (char **result, char **array, int base, int size, char *by) { long dlen, i, slen, total; dlen = __b2c__len (by); total = __b2c__len (array[0 + base]);" >> $g_FUNCTIONS
    echo "*result = (char*)calloc(total, sizeof(char)+1); memmove(*result, array[0 + base], total); for (i = 1; i < size; i++) { if (array[i + base] != NULL) { slen = __b2c__len (array[i + base]);" >> $g_FUNCTIONS
    echo "*result = (char *) realloc (*result, (total + dlen + slen + 1) * sizeof (char)); memmove (*result + total, by, dlen); total += dlen; memmove (*result + total, array[i + base], slen);" >> $g_FUNCTIONS
    echo "total += slen; } } (*result)[total] = '\0'; }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//network/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    if [[ ${g_LIB_TLS} = +(*gnutls*) ]]
    then
        echo "#define SSL_set_tlsext_host_name(connection, name) gnutls_server_name_set(((SSL*)connection)->gnutls_state, GNUTLS_NAME_DNS, name, LEN(name))" >> $g_FUNCTIONS
        echo "#undef VERIFY" >> $g_FUNCTIONS
        echo "long VERIFY(uintptr_t ssl, char* pem) { int result = 0; gnutls_certificate_credentials_t cred = 0; if((SSL*)ssl == NULL) { return(-1); }" >> $g_FUNCTIONS
        echo "gnutls_certificate_allocate_credentials(&cred); gnutls_certificate_set_x509_trust_file(cred, pem, GNUTLS_X509_FMT_PEM);" >> $g_FUNCTIONS
        echo "if(gnutls_credentials_set(((SSL*)ssl)->gnutls_state, GNUTLS_CRD_CERTIFICATE, cred) != 0) { return(-1); } if(gnutls_certificate_verify_peers2(((SSL*)ssl)->gnutls_state, &result) !=0) { return(-1); }" >> $g_FUNCTIONS
        echo "gnutls_certificate_free_credentials(cred); return(result); }" >> $g_FUNCTIONS
        echo "SSL_METHOD *TLS_client_method(void) { SSL_METHOD *tls; tls = calloc(1, sizeof(SSL_METHOD)); strncpy(tls->priority_string, ${g_PRIORITY}, 256); tls->connend = 2; return(tls); }" >> $g_FUNCTIONS
    fi
    echo "int __b2c__network_init(uintptr_t *handle, char *site, char *org, int sock_type, int sock_opt, char *nw_type, int multicast_ttl, int sctp_streams, int capeer, char *cacerts) { struct sockaddr_in *addr, *from; struct hostent *he;" >> $g_FUNCTIONS
    echo "long amount = 0; long length = 0; char data_client[${g_BUFFER_SIZE}]; char *host, *local, *port, *from_client; struct timeval tval; int sock, i, yes = 1; long start; char ttl = 1; __b2c__delim_engine (2, &amount, site, \",\", 0);" >> $g_FUNCTIONS
    echo "addr = (struct sockaddr_in*)calloc(amount, sizeof(*addr)); for(i = 0; i < amount; i++) { start = __b2c__delim_engine (1, &length, site, \",\", i+1); if(length >= ${g_BUFFER_SIZE}) { return(5); } memset(data_client, 0, ${g_BUFFER_SIZE});" >> $g_FUNCTIONS
    echo "strncpy(data_client, site+start, length); if(strstr(data_client, \":\") == NULL) { return(10); } host = strtok(data_client, \":\"); port = strtok(NULL, \":\"); he = gethostbyname(host); if(he == NULL || he->h_addr == NULL) { return(11); }" >> $g_FUNCTIONS
    echo "addr[i].sin_family = AF_INET; addr[i].sin_port = htons((long)atol(port)); addr[i].sin_addr = *((struct in_addr *) he->h_addr); }" >> $g_FUNCTIONS
    if [[ ${g_NETWORKTYPE} = "SCTP" ]]
    then
        echo "sock = socket(AF_INET, sock_type, IPPROTO_SCTP);" >> $g_FUNCTIONS
    else
        echo "sock = socket(AF_INET, sock_type, 0);" >> $g_FUNCTIONS
    fi
    echo "if(sock == -1) { return(12); } tval.tv_sec = sock_opt; tval.tv_usec = 0; setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &tval, sizeof (struct timeval));" >> $g_FUNCTIONS
    echo "setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof (int)); if(org) { __b2c__delim_engine (2, &amount, org, \",\", 0); from = (struct sockaddr_in*)calloc(amount, sizeof(*from));" >> $g_FUNCTIONS
    echo "for(i = 0; i < amount; i++) { start = __b2c__delim_engine (1, &length, site, \",\", i+1); from_client = __b2c__strndup(org+start, length); if(strstr(from_client, \":\"))" >> $g_FUNCTIONS
    echo "{ local = strtok(from_client, \":\"); port = strtok(NULL, \":\"); } else { local = from_client; port = NULL; } he = gethostbyname(local); if(he == NULL || he->h_addr == NULL) { return(11); }" >> $g_FUNCTIONS
    echo "from[i].sin_family = AF_INET; if(port) { from[i].sin_port = htons((long)atol(port)); } from[i].sin_addr = *((struct in_addr *)he->h_addr); free(from_client); }" >> $g_FUNCTIONS
    if [[ ${g_NETWORKTYPE} = "SCTP" ]]
    then
        echo "if(sctp_bindx(sock, (struct sockaddr *)from, 1, SCTP_BINDX_ADD_ADDR) < 0) { return(17); } free(from); }" >> $g_FUNCTIONS
        echo "struct sctp_initmsg initmsg; memset (&initmsg, 0, sizeof (initmsg)); initmsg.sinit_max_attempts = 3; initmsg.sinit_num_ostreams = sctp_streams; initmsg.sinit_max_instreams = sctp_streams;" >> $g_FUNCTIONS
        echo -e "setsockopt(sock, IPPROTO_SCTP, SCTP_INITMSG, &initmsg, sizeof (initmsg));\n#ifdef SCTP_SOCKOPT_CONNECTX_OLD\nif(sctp_connectx(sock, (struct sockaddr *) addr, 1, NULL) < 0) { return(13); }" >> $g_FUNCTIONS
        echo -e "#else\nif(sctp_connectx(sock, (struct sockaddr *) addr, 1) < 0) { return(13); }\n#endif" >> $g_FUNCTIONS
    else
        echo "if(bind(sock, (struct sockaddr *)from, sizeof(struct sockaddr)) < 0) { return(17); } free(from); }" >> $g_FUNCTIONS
        echo "if (!strcmp(nw_type, \"BROADCAST\")) { setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(int)); } if(!strcmp(nw_type, \"MULTICAST\")) { setsockopt(sock, IPPROTO_IP, IP_MULTICAST_LOOP, &yes, sizeof(int));" >> $g_FUNCTIONS
        echo "ttl = multicast_ttl; setsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, &ttl, sizeof(unsigned char)); }" >> $g_FUNCTIONS
        echo "if(connect(sock, (struct sockaddr*)addr, sizeof(struct sockaddr)) < 0) { return(13); }" >> $g_FUNCTIONS
    fi
    echo "*handle = sock;" >> $g_FUNCTIONS
    if [[ ${g_OPTION_TLS} = +(1*|TRUE*) ]]
    then
        echo "if(__b2c__option_tls) { int ret; SSL_CTX *ssl_context = NULL; SSL *ssl_sock; SSL_library_init(); ssl_context = SSL_CTX_new(TLS_client_method()); SSL_CTX_set_verify(ssl_context, capeer, NULL);" >> $g_FUNCTIONS
        if [[ ${g_LIB_TLS} != +(*gnutls*) ]]
        then
            echo "SSL_CTX_load_verify_locations(ssl_context, cacerts, NULL);" >> $g_FUNCTIONS
        fi
        if [[ ${g_LIB_TLS} != +(*gnutls*) && ${g_LIB_TLS} != +(*wolfssl*) ]]
        then
            echo "SSL_CTX_set_options(ssl_context, SSL_OP_LEGACY_SERVER_CONNECT);" >> $g_FUNCTIONS
        fi
        echo "SSL_CTX_set_options(ssl_context, SSL_OP_ALL); ssl_sock = SSL_new(ssl_context); SSL_set_tlsext_host_name(ssl_sock, host); if(SSL_set_fd(ssl_sock, *handle) == 0) { return(40); }" >> $g_FUNCTIONS
        echo "if((ret = SSL_connect(ssl_sock)) <= 0) { fprintf(stderr, \"SSL CONNECT error: %s\n\", ERR_error_string(SSL_get_error(ssl_sock, ret), NULL)); return(40); }" >> $g_FUNCTIONS
        echo "*handle = (uintptr_t)ssl_sock; }" >> $g_FUNCTIONS
    fi
    echo "free(addr); return(0); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//server/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    if [[ ${g_LIB_TLS} = +(*gnutls*) ]]
    then
        echo "SSL_METHOD *TLS_server_method(void) { SSL_METHOD *tls; tls = calloc(1, sizeof(SSL_METHOD)); strncpy(tls->priority_string, \"NONE:PFS:+VERS-ALL:+VERS-DTLS-ALL:+CIPHER-ALL:+CIPHER-GOST-ALL:+MAC-ALL:+MAC-GOST-ALL\", 256); tls->connend = 1; return(tls); }" >> $g_FUNCTIONS
    fi
    echo "int __b2c__server_init(uintptr_t *handle, char *site, int sock_type, int sock_opt, int sctp_streams) { struct sockaddr_in *addr; struct hostent *he; long amount = 0; long length = 0; char *host, *port;" >> $g_FUNCTIONS
    echo "char data_client[${g_BUFFER_SIZE}]; struct timeval tval; int fd, i, yes = 1; long start; __b2c__delim_engine (2, &amount, site, \",\", 0); addr = (struct sockaddr_in*)calloc(amount, sizeof(*addr)); for(i = 0; i < amount; i++)" >> $g_FUNCTIONS
    echo "{ start = __b2c__delim_engine(1, &length, site, \",\", i + 1); if (length >= ${g_BUFFER_SIZE}) { return (5); } memset (data_client, 0, ${g_BUFFER_SIZE}); strncpy(data_client, site + start, length);" >> $g_FUNCTIONS
    echo "if(strstr(data_client, \":\") == NULL) { return(10); } host = strtok(data_client, \":\"); port = strtok(NULL, \":\"); if(strstr(site, \"INADDR_ANY:\") || strstr(site, \"*:\")) { addr[i].sin_addr.s_addr = htonl(INADDR_ANY); }" >> $g_FUNCTIONS
    echo "else { he = gethostbyname(host); if(he == NULL || he->h_addr == NULL) { return(11); } addr[i].sin_addr = *((struct in_addr*)he->h_addr); }" >> $g_FUNCTIONS
    echo "addr[i].sin_family = AF_INET; addr[i].sin_port = htons((long)atol(port)); }" >> $g_FUNCTIONS
    if [[ ${g_NETWORKTYPE} = "SCTP" ]]
    then
        echo "fd = socket(AF_INET, sock_type, IPPROTO_SCTP);" >> $g_FUNCTIONS
        echo "struct sctp_initmsg initmsg; memset(&initmsg, 0, sizeof(initmsg)); initmsg.sinit_max_attempts = 3;" >> $g_FUNCTIONS
        echo "initmsg.sinit_num_ostreams = sctp_streams; initmsg.sinit_max_instreams = sctp_streams;" >> $g_FUNCTIONS
        echo "setsockopt(fd, IPPROTO_SCTP, SCTP_INITMSG, &initmsg, sizeof(initmsg));" >> $g_FUNCTIONS
    else
        echo "fd = socket(AF_INET, sock_type, 0);" >> $g_FUNCTIONS
    fi
    echo "if(fd == -1) { return(12); } tval.tv_sec = sock_opt; tval.tv_usec = 0; setsockopt(fd, SOL_SOCKET, SO_SNDTIMEO, &tval, sizeof(struct timeval));" >> $g_FUNCTIONS
    echo "setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));" >> $g_FUNCTIONS
    if [[ ${g_NETWORKTYPE} = "SCTP" ]]
    then
        echo "if(sctp_bindx(fd, (struct sockaddr *)addr, 1, SCTP_BINDX_ADD_ADDR) < 0) { return(17); }" >> $g_FUNCTIONS
    else
        echo "if(bind(fd, (struct sockaddr *)addr, sizeof(struct sockaddr)) < 0) { return(17); }" >> $g_FUNCTIONS
    fi
    if [[ ${g_NETWORKTYPE} = "MULTICAST" ]]
    then
        echo "struct ip_mreq imreq; imreq.imr_multiaddr.s_addr = inet_addr(host); imreq.imr_interface.s_addr = INADDR_ANY;" >> $g_FUNCTIONS
	echo "setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &imreq, sizeof(imreq));" >> $g_FUNCTIONS
    fi
    if [[ ${g_NETWORKTYPE} != "UDP" && ${g_NETWORKTYPE} != "BROADCAST" && ${g_NETWORKTYPE} != "MULTICAST" ]]
    then
        echo "if(listen(fd, $g_MAX_BACKLOG) < 0) { return(18); }" >> $g_FUNCTIONS
    fi
    echo "*handle = fd; free(addr); return(0); }" >> $g_FUNCTIONS
    echo "uintptr_t __b2c__accept(int l, char *k, char *priv, char *cert, uintptr_t fd) { uintptr_t handle; int desc; desc = accept(fd, NULL, NULL); if(desc < 0){ ERROR = 19; RUNTIMEFERR(\"ACCEPT\", ERROR, k, l); return(0); }" >> $g_FUNCTIONS
    if [[ ${g_OPTION_TLS} = +(1*|TRUE*) ]]
    then
        echo "if(__b2c__option_tls) { int result = 0; SSL_CTX *ssl_context = NULL; SSL *ssl_sock = NULL; SSL_library_init(); ssl_context = SSL_CTX_new(TLS_server_method());" >> $g_FUNCTIONS
        echo "if(SSL_CTX_use_PrivateKey_file(ssl_context, priv, SSL_FILETYPE_PEM) <= 0) { return(41); } if(SSL_CTX_use_certificate_file(ssl_context, cert, SSL_FILETYPE_PEM) <= 0) { return(41); }" >> $g_FUNCTIONS
        echo "ssl_sock = SSL_new(ssl_context); SSL_set_fd(ssl_sock, desc); if((result = SSL_accept(ssl_sock)) <= 0){ fprintf(stderr, \"SSL ACCEPT error: %s\n\", ERR_error_string(SSL_get_error(ssl_sock, result), NULL));" >> $g_FUNCTIONS
        echo "return(-1); } handle = (uintptr_t)ssl_sock; }" >> $g_FUNCTIONS
    else
        echo "if(!__b2c__option_tls) { handle = (uintptr_t)desc; }" >> $g_FUNCTIONS
    fi
    echo "return(handle); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//save/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c__save(int mode, size_t size, char *file, ...) { FILE *outfile; va_list args; char *item; switch(mode){ case 0: case 1: outfile = fopen((const char *) file, \"w\"); break;" >> $g_FUNCTIONS
    echo "case 2: case 3: outfile = fopen((const char *) file, \"a\"); break; } if (outfile == NULL) { return(2); } switch(mode) { case 0: case 2: va_start(args, file); while((item = va_arg(args, char*)) != NULL)" >> $g_FUNCTIONS
    echo "{ fprintf(outfile, \"%s\", item); } va_end(args); break; case 1: case 3: va_start(args, file); if(fwrite(va_arg(args, void*), 1, size, outfile) != size){ return(2); } va_end(args); break; } fclose (outfile); return(0); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//setserial/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c_setserial(int device, int mode, int param, int value, int donot) { struct termios tty; memset(&tty, 0, sizeof(tty)); if(tcgetattr(device, &tty) != 0) { return(33); } switch(mode)" >> $g_FUNCTIONS
    echo "{ case 0: if(donot) { tty.c_iflag &= value; } else { tty.c_iflag |= value; } break; case 1: if(donot) { tty.c_oflag &= value; } else { tty.c_oflag |= value; } break; case 2: if(donot) { tty.c_cflag &= value; }" >> $g_FUNCTIONS
    echo "else { tty.c_cflag |= value; } break; case 3: if(donot) { tty.c_lflag &= value; } else { tty.c_lflag |= value; } break; case 4: tty.c_cc[param] = value; break; case 5: cfsetospeed(&tty, value); cfsetispeed(&tty, value);" >> $g_FUNCTIONS
    echo "break; } if(tcsetattr(device, TCSANOW, &tty) != 0) { return(33); } return(0); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//getline/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__getline(char **handle) { char *pos, *result; if(*handle == NULL || (*handle)[0] == '\0') { return(NULL); } else { pos = strchr(*handle, '\n'); if(pos)" >> $g_FUNCTIONS
    echo "{ result = __b2c_Copy_N_String(NULL, *handle, (size_t)(pos - *handle)); } else { result = __b2c_Copy_String(NULL, *handle); } *handle += __b2c__len(result); if((*handle)[0] == '\n') { (*handle)++; } } return(result); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//split/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "void __b2c__split_by(char ***array, int base, long *amount, char *string, char *by) { long length, i, start; __b2c__free_str_array_members(&(*array), base, *amount);" >> $g_FUNCTIONS
    echo "start = __b2c__delim_engine(2, amount, string, by, 0); *array = (char**)realloc(*array, (*amount+base) * sizeof(char*)); for (i = 0; i < *amount; i++)" >> $g_FUNCTIONS
    echo "{ start = __b2c__delim_engine_cache(1, &length, string, by, i+1); (*array)[i + base] =__b2c_Copy_N_String(NULL, string + start, (size_t)length); } }" >> $g_FUNCTIONS
    echo "void __b2c__split_with(char ***array, int base, long *amount, char *string, int counter) { long length, i; __b2c__free_str_array_members (&(*array), base, *amount);" >> $g_FUNCTIONS
    echo "length = __b2c__len(string); if (counter > length) { counter = length; } *amount = (length / counter) + (length % counter != 0 ? 1 : 0); *array = (char**)realloc(*array, (*amount+base)*sizeof(char*));" >> $g_FUNCTIONS
    echo "if (counter > 0) { for (i = 0; i < *amount; i++) { (*array)[i + base] = __b2c_Copy_N_String(NULL, string + i*counter, (size_t)counter); } } }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//for/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "long __b2c__for_amount(char *string, char *step) { long amount = 0; __b2c__delim_engine(2, &amount, string, step, 0); return(amount); }" >> $g_FUNCTIONS
    echo "void __b2c__for_item (char **string, char *step, char **result) { long length = 0; long start; start = __b2c__delim_engine (1, &length, *string, step, 1); if(length == 0) { *result = NULL; } else" >> $g_FUNCTIONS
    echo "{ *result = (char *) __b2c_str_realloc (*result, length + 1); memmove (*result, *string + start, length); __b2c__SETLEN (*result, length); (*result)[length] = '\0'; } *string += (start + length + __b2c__len (step)); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//makedir/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c__makedir(char *newdir) { long start, amount = 0, length = 0; int item, collapse; char *dir; if (newdir != NULL && *newdir != 0) { collapse = __b2c__collapse; __b2c__collapse = 0; dir = (char*)calloc(__b2c__len(newdir)+1, sizeof(char));" >> $g_FUNCTIONS
    echo "start = __b2c__delim_engine(2, &amount, newdir, \"/\", 0); for(item = 1; item <= amount; item++) { start = __b2c__delim_engine(1, &length, newdir, \"/\", item); if(length) { strncat(dir, newdir+start, length);" >> $g_FUNCTIONS
    echo "if(mkdir(dir, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) < 0 && errno != EEXIST && errno != 0) { return(21); } } if(item < amount) { strcat(dir, \"/\"); } } free(dir); __b2c__collapse = collapse; } return(0); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//alarm/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "void __b2c__alarm(void *func, long time) { void(*target)(int); struct itimerval alarm; struct sigaction psa; memset(&psa, 0, sizeof(psa)); psa.sa_flags = SA_RESETHAND|SA_RESTART;" >> $g_FUNCTIONS
    echo "*((void**)&target) = func; psa.sa_handler = target; sigaction(SIGALRM, &psa, NULL); alarm.it_value.tv_sec = (long)(time)/1000; alarm.it_value.tv_usec = ((time)%1000)*1000;" >> $g_FUNCTIONS
    echo "alarm.it_interval.tv_sec = 0; alarm.it_interval.tv_usec = 0; setitimer(ITIMER_REAL, &alarm, NULL); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//signal/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "void __b2c__signal(void *func, int action) { void(*target)(int); struct sigaction psa; memset(&psa, 0, sizeof(psa)); *((void**)&target) = func; psa.sa_flags = SA_RESETHAND|SA_RESTART; psa.sa_handler = target; sigaction(action, &psa, NULL); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//cipher/} != ${TOTAL} || ${g_OPTION_TLS} = +(1*|TRUE*) ]]
then
    echo "char *__b2c__ca(int l, char *k, uintptr_t desc) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len; char buffer[4096] = { 0 }; X509 *cert; X509_NAME *name; if((SSL*)desc == NULL) { ERROR = 40; RUNTIMEFERR(\"CA$\", ERROR, k, l); return(NULL); } cert = (X509*)SSL_get_peer_certificate((SSL*)desc); if(cert==NULL) { ERROR = 41; RUNTIMEFERR(\"CA$\", ERROR, k, l); return(NULL); }" >> $g_FUNCTIONS
    echo "name = X509_get_issuer_name(cert); X509_NAME_oneline(name, buffer, 4095); len = strlen(buffer); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + 1); memmove(buf[idx], buffer, len);__b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0';" >> $g_FUNCTIONS
    if [[ ${g_LIB_TLS} = +(*gnutls*) ]]
    then
        echo "free(name);" >> $g_FUNCTIONS
    fi
    echo "X509_free(cert); return(char*)(buf[idx]); }" >> $g_FUNCTIONS
    echo "char *__b2c__cn(int l, char *k, uintptr_t desc) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len; char buffer[4096] = { 0 }; X509 *cert; X509_NAME *name; if((SSL*)desc == NULL) { ERROR = 40; RUNTIMEFERR(\"CN$\", ERROR, k, l); return(NULL); } cert = (X509*)SSL_get_peer_certificate((SSL*)desc); if(cert==NULL) { ERROR = 41; RUNTIMEFERR(\"CA$\", ERROR, k, l); return(NULL); }" >> $g_FUNCTIONS
    echo "name = X509_get_subject_name(cert); X509_NAME_oneline(name, buffer, 4095); len = strlen(buffer); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + 1); memmove(buf[idx], buffer, len);__b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0';" >> $g_FUNCTIONS
    if [[ ${g_LIB_TLS} = +(*gnutls*) ]]
    then
        echo "free(name);" >> $g_FUNCTIONS
    fi
    echo "X509_free(cert); return(char*)(buf[idx]); }" >> $g_FUNCTIONS
    echo "char *__b2c__cipher(int l, char *k, uintptr_t desc) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len; char buffer[4096] = { 0 }; if((SSL*)desc == NULL) { ERROR = 40; RUNTIMEFERR(\"CIPHER$\", ERROR, k, l); return(NULL); } SSL_CIPHER_description(SSL_get_current_cipher((SSL*)desc), buffer, 4095);" >> $g_FUNCTIONS
    echo "len = strlen(buffer); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + 1); memmove(buf[idx], buffer, len);__b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//doescape/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__escape(int l, char *k, char *string) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long slen, length = 0; unsigned int current; if (string == NULL) { return (string); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], sizeof(char));" >> $g_FUNCTIONS
    echo "while(*string) { current = __b2c__utf8toasc(string); if(current > 0xffff) { buf[idx] = (char *) __b2c_str_realloc(buf[idx], length + 11); snprintf(buf[idx]+length, 11, \"\\\\U%08X\", current); length += 10; } else if(current > 0x7f)" >> $g_FUNCTIONS
    echo "{ buf[idx] = (char *) __b2c_str_realloc(buf[idx], length + 7); snprintf(buf[idx]+length, 7, \"\\\\u%04X\", current); length += 6; } else { buf[idx] = (char *) __b2c_str_realloc(buf[idx], length + 2);" >> $g_FUNCTIONS
    echo "switch(current) { case 7: snprintf(buf[idx]+length, 3, \"\\\\a\"); length+=2; break; case 8: snprintf(buf[idx]+length, 3, \"\\\\b\"); length+=2; break; case 27: snprintf(buf[idx]+length, 3, \"\\\\e\"); length+=2; break;" >> $g_FUNCTIONS
    echo "case 12: snprintf(buf[idx]+length, 3, \"\\\\f\"); length+=2; break; case 10: snprintf(buf[idx]+length, 3, \"\\\\n\"); length+=2; break; case 13: snprintf(buf[idx]+length, 3, \"\\\\r\"); length+=2; break;" >> $g_FUNCTIONS
    echo "case 9: snprintf(buf[idx]+length, 3, \"\\\\t\"); length+=2; break; case 11: snprintf(buf[idx]+length, 3, \"\\\\v\"); length+=2; break; case 92: snprintf(buf[idx]+length, 3, \"\\\\\\\\\"); length+=2; break;" >> $g_FUNCTIONS
    echo "case 39: snprintf(buf[idx]+length, 3, \"\\\\'\"); length+=2; break; case 34: snprintf(buf[idx]+length, 3, \"\\\\\\${g_DQUOTESIGN}\"); length+=2; break; case 63: snprintf(buf[idx]+length, 3, \"\\\\?\"); length+=2; break;" >> $g_FUNCTIONS
    echo "default: snprintf(buf[idx]+length, 2, \"%c\", current); length+=1; } } slen = __b2c__blen(l, k, \"ESCAPE$\", string, 1, 0); if(slen == 0) { break; } else {string += slen; } } __b2c__SETLEN(buf[idx], length); buf[idx][length] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//unescape/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__unescape(int l, char *k, char *string) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len, tlen, length = 0; char *pos, *status = NULL; char hex[9], buffer[9]; uint32_t byte; if (string == NULL) { return (string); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], sizeof(char)); while ((pos = strchr (string, 92)) != NULL) { switch (*(pos + 1)) { case 'u': case 'U': buf[idx] = (char *) __b2c_str_realloc(buf[idx], length + (pos - string)); memcpy(buf[idx] + length, string, (size_t) (pos - string));" >> $g_FUNCTIONS
    echo "length += (uintptr_t) (pos - string); string = pos + 2; if (*(pos + 1) == 'u') { tlen = 4; } else { tlen = 8; } if (__b2c__len (string) < tlen) { ERROR = 5; RUNTIMEFERR(\"UNESCAPE$\", ERROR, k, l); return(NULL); } strncpy (hex, string, tlen); hex[tlen] = '\0';" >> $g_FUNCTIONS
    echo "byte = strtol (hex, &status, 16); len = __b2c_utf8_conv (byte, buffer); buf[idx] = (char*)__b2c_str_realloc(buf[idx], length + len); memcpy(buf[idx] + length, buffer, len); string += tlen; length += len;" >> $g_FUNCTIONS
    echo "break; default: buf[idx] = (char*)__b2c_str_realloc(buf[idx], length + (pos - string) + 1); memcpy(buf[idx] + length, string, (size_t) (pos - string)); length += (uintptr_t) (pos - string);" >> $g_FUNCTIONS
    echo "switch (*(pos + 1)) { case 'a': byte = 7; string = pos + 2; break; case 'b': byte = 8; string = pos + 2; break; case 'e': byte = 27; string = pos + 2; break; case 'f': byte = 12; string = pos + 2; break; case 'n': byte = 10; string = pos + 2; break;" >> $g_FUNCTIONS
    echo "case 'r': byte = 13; string = pos + 2; break; case 't': byte = 9; string = pos + 2; break; case 'v': byte = 11; string = pos + 2; break; case 92: byte = 92; string = pos + 2; break; case 39: byte = 39; string = pos + 2; break;" >> $g_FUNCTIONS
    echo "case 34: byte = 34; string = pos + 2; break; case 63: byte = 63; string = pos + 2; break; default: byte = (uint8_t)(*(pos)); string = pos + 1; } buf[idx][length] = (uint8_t) byte; length += 1; } } len = __b2c__len(string);" >> $g_FUNCTIONS
    echo "buf[idx] = (char*)__b2c_str_realloc(buf[idx], length + len + 1); memcpy(buf[idx] + length, string, len); length += len; __b2c__SETLEN(buf[idx], length); buf[idx][length] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//tree/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "void __b2c__tree_add(void *node, void **tree, int(*func)(const void*, const void*)) { void *result; if(node) { result = tsearch(node, tree, func); if(*(uintptr_t**)result != (uintptr_t*)node) { __b2c__STRFREE(node); } } }" >> $g_FUNCTIONS
    echo "void __b2c__binary_tree_free(void *tree, int(*func)(const void*, const void*)) { int total, i; void **array = { NULL }; total = __b2c__collect(tree, &array, ${g_OPTION_BASE}, 0); for(i = ${g_OPTION_BASE}; i<total; i++)" >> $g_FUNCTIONS
    echo "{ tdelete((void*)array[i], &tree, func); __b2c__STRFREE(array[i]); } if(array) { free(array); } }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//find/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "int __b2c__find(int (*func)(const void*, const void*), void* tree, void* node, int dofree) { void **result; result = tfind(node, &tree, func); if(dofree) { free(node); } if(result == NULL) { return(0); } return(1); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//collect/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "static void __b2c__collect_do(const void *node, VISIT which, int depth) { switch (which) { case preorder: break; case endorder: break; case postorder: case leaf: __b2c__twalk_idx++; __b2c__twalk_array = (void**)realloc(__b2c__twalk_array, sizeof(void*)*__b2c__twalk_idx);" >> $g_FUNCTIONS
    echo "__b2c__twalk_array[__b2c__twalk_idx-1] = *(uintptr_t**)node; break; } }" >> $g_FUNCTIONS
    echo "int __b2c__collect(void *tree, void ***array, int base, int type) { int i, count; if(__b2c__twalk_array) { free(__b2c__twalk_array); __b2c__twalk_array = NULL; } if(*array) { free(*array); *array = NULL; } __b2c__twalk_idx = 0; twalk(tree, __b2c__collect_do); count = base;" >> $g_FUNCTIONS
    echo "*array = (void*)calloc(__b2c__twalk_idx, sizeof(void*)); for (i = 0; i < __b2c__twalk_idx; i++) { switch(type) { case 0: (*array)[count++] = (char*)__b2c__twalk_array[i]; break; case 1: (*(double**)array)[count++] = *(double*)__b2c__twalk_array[i]; break;" >> $g_FUNCTIONS
    echo "case 2: (*(float**)array)[count++] = *(float*)__b2c__twalk_array[i]; break; case 3: (*(long**)array)[count++] = *(long*)__b2c__twalk_array[i]; break; case 4: (*(int**)array)[count++] = *(int*)__b2c__twalk_array[i]; break;" >> $g_FUNCTIONS
    echo "case 5: (*(short**)array)[count++] = *(short*)__b2c__twalk_array[i]; break; case 6: (*(char**)array)[count++] = *(char*)__b2c__twalk_array[i]; break; } } return (count-base); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//total/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "static void __b2c__total_do(const void *node, VISIT which, int depth) { switch (which) { case preorder: break; case endorder: break; case postorder: case leaf: __b2c__twalk_idx++; break; } }" >> $g_FUNCTIONS
    echo "int __b2c__total(void *tree) { __b2c__twalk_idx = 0; twalk(tree, __b2c__total_do); return(__b2c__twalk_idx); }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//parse/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "void __b2c__parse(char ***array, int base, long *amount1, char *string, char *with, char *delim) { long dlen, start1, start2, amount2, length1, length2, tmplen, sublen = 0; int x, i = 0, wildcard = 0, next = 0; char *pos = NULL;" >> $g_FUNCTIONS
    echo "__b2c__free_str_array_members (&(*array), base, *amount1); free (*array); *array = NULL; if (string == NULL && with == NULL) { *amount1 = 0; return; } if (delim == NULL) { delim = __b2c__option_delim; }" >> $g_FUNCTIONS
    echo "start1 = __b2c__delim_engine (2, amount1, string, delim, 0); if(*amount1 == 0) { return; } *array = (char **) realloc (*array, (*amount1 + base) * sizeof (char *)); dlen = __b2c__len (delim);" >> $g_FUNCTIONS
    echo "for (x = 0; x < *amount1; x++) { start1 = __b2c__delim_engine (1, &length1, string, delim, 1); start2 = __b2c__delim_engine (1, &length2, with, delim, 1); if(!strncmp (with, \"?\", 1))" >> $g_FUNCTIONS
    echo "{ (*array)[i + base] = __b2c_Copy_N_String(NULL, string, (size_t) length1); i++; string += (start1 + length1 + dlen); with += (start2 + length2 + dlen); } else { next = 0; if(!strncmp (with, \"*\", 1))" >> $g_FUNCTIONS
    echo "{ wildcard = 1; if(!pos) { pos = string; } __b2c__delim_engine (2, &amount2, with + 1, delim, 0); if(amount2) { next = 1 + dlen; } else { next = 1; } } else if(!strncmp(with, \"\\\\*\", 2) || !strncmp(with, \"\\\\?\", 2))" >> $g_FUNCTIONS
    echo "{ with++; length2--; } __b2c__delim_engine (1, &tmplen, with + next, delim, 1); if(length1 != tmplen || memcmp(string, with+next, tmplen)) { if (wildcard == 1) { if(sublen == 0) { sublen += length1; } else { sublen += length1 + dlen; } }" >> $g_FUNCTIONS
    echo "else { __b2c__free_str_array_members (&(*array), base, i); free (*array); *array = NULL; i = 0; break; } } else { if(wildcard) { (*array)[i + base] = __b2c_Copy_N_String(NULL, pos, (size_t)sublen); pos = NULL; sublen = 0; i++; } wildcard = 0; }" >> $g_FUNCTIONS
    echo "string += (start1 + length1 + dlen); if (wildcard == 0) { with += (start2 + length1 + dlen + next); } } } if (wildcard) { (*array)[i + base] = __b2c_Copy_N_String(NULL, pos, (size_t) sublen); i++; } *amount1 = i; }" >> $g_FUNCTIONS
fi

if [[ ${TOTAL//collapsefunc/} != ${TOTAL} || ${NOLEX} -eq 1 ]]
then
    echo "char *__b2c__collapse_func(char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, dlen, option, x, total = 0; long amount = 0, length = 0; if (string == NULL) { return (string); } if (delim == NULL) { delim = __b2c__option_delim; }" >> $g_FUNCTIONS
    echo "option = __b2c__collapse; __b2c__collapse = 1; dlen = __b2c__len (delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len (string) + 1); __b2c__delim_engine(2, &amount, string, delim, 0); for (x = 0; x < amount; x++)" >> $g_FUNCTIONS
    echo "{ start = __b2c__delim_engine (1, &length, string, delim, 1); memmove(buf[idx] + total, string + start, length); total += length; if (x < amount - 1) { memmove(buf[idx] + total, delim, dlen); total += dlen; }" >> $g_FUNCTIONS
    echo "string += (start + length); } __b2c__collapse = option; __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\0'; return(char*)(buf[idx]); }" >> $g_FUNCTIONS
fi

# Check MEMORY/FREE
if [[ $g_SEMANTIC -eq 0 ]]
then
    for i in ${!g_SEMANTIC_MEMFREE[@]}
    do
	echo -e "WARNING: no FREE for the memory address ${g_SEMANTIC_MEMFREE[$i]}!"
    done
fi

# Check OPEN/CLOSE handles
if [[ $g_SEMANTIC -eq 0 ]]
then
    for i in ${!g_SEMANTIC_OPENCLOSE[@]}
    do
	echo -e "WARNING: no CLOSE for the OPEN handle ${g_SEMANTIC_OPENCLOSE[$i]}!"
    done
fi

# Show error in case function has no end
if [[ -n $g_FUNCNAME ]]
then
    echo -e "Syntax error: the SUB/FUNCTION '$g_FUNCNAME' has no END in file '$g_CURFILE'!"
    exit 1
fi

# Indentation only when files are preserved
if [[ $g_TMP_PRESERVE -eq 1 ]]
then
    if [[ -n `command -v indent 2>/dev/null` ]]
    then
	echo -n "Applying indentation... "
	for i in $g_TMP_FILES
	do
	    if [[ $i != +(*.cpp) && $i != +(*.tmp) && $i != +(*.bac) && $i != +(*.lex) && $i != +(*.exe) ]]
	    then
		if [[ `uname` = "Darwin" || `uname` = +(*BSD*) ]]
		then
		    mv ${i} "${i}.BAK"
		    indent "${i}.BAK" ${i}
		    rm "${i}.BAK"
		else
		    # indent $i
		    indent -bad -bap -bli0 -cli4 -cbi0 -nbc -nbfda -nsc -nprs -bls -blf -lp -ts4 -ppi2 -npsl -i4 -il4 -l140 -nbbo $i
		    rm $i~
		fi
	    fi
	done
	echo "done."
    else
	echo "WARNING: 'indent' not found on this system!"
	echo "Generated source code cannot be beautified."
    fi
fi

# Check if we need to run xgettext
if [[ ${g_XGETTEXT} -eq 1 ]]
then
    if [[ -n `command -v xgettext 2>/dev/null` ]]
    then
	echo -n "Executing xgettext... "
	xgettext --keyword=INTL${g_STRINGSIGN} --keyword=NNTL${g_STRINGSIGN}:1,2 -d ${g_SOURCEFILE%.*} -s -o ${g_SOURCEFILE%.*}.pot $g_TMP_FILES 2>&1
	if [[ ! -f "${g_SOURCEFILE%.*}.pot" ]]
	then
	    echo "WARNING: catalog file not created!"
	else
	    echo "done."
	fi
    else
	echo "WARNING: 'xgettext' not found on this system!"
    fi
fi

# Creation of the Makefile
echo -e "# Created with Shell BaCon $g_VERSION - (c) Peter van Eerten - MIT License\n" > $g_TEMPDIR/Makefile.bacon
BASE="${g_SOURCEFILE%.*}"
echo -e "${BASE##*/}$g_BINEXT: ${g_SOURCEFILE##*/}.o" >> $g_TEMPDIR/Makefile.bacon
echo -e "\t$g_CCNAME -o ${BASE##*/}$g_BINEXT ${g_SOURCEFILE##*/}.o $g_LDFLAGS ${g_LIB_TLS} -lm" >> $g_TEMPDIR/Makefile.bacon
echo -e "${g_SOURCEFILE##*/}.o: ${g_SOURCEFILE##*/}.c" >> $g_TEMPDIR/Makefile.bacon
echo -e "\t$g_CCNAME $g_CCFLAGS -c ${g_SOURCEFILE##*/}.c" >> $g_TEMPDIR/Makefile.bacon
echo -e "\n.PHONY: clean" >> $g_TEMPDIR/Makefile.bacon
echo -e "clean:" >> $g_TEMPDIR/Makefile.bacon
echo -e "\trm -f *.o *.c ${g_SOURCEFILE%.*}$g_BINEXT ${g_SOURCEFILE%.bac}.*.* Makefile.bacon" >> $g_TEMPDIR/Makefile.bacon
g_TMP_FILES="$g_TMP_FILES $g_TEMPDIR/Makefile".bacon

# Start compilation
if [[ $g_NO_COMPILE -eq 0 ]]
then
    if [[ -z `command -v $g_CCNAME 2>/dev/null` ]]
    then
	echo "WARNING: '$g_CCNAME' not found on this system!"
	echo "Generated source code cannot be compiled."
	exit 0
    fi
    echo -n "Compiling '${g_SOURCEFILE}'... "

    # Make sure GCC uses English localization
    export LANG="C"

    # Using 'cd' here to be compatible with older make's
    cd $g_TEMPDIR
    make -f Makefile.bacon 2>${g_SOURCEFILE##*/}.log
    RETURN_CODE=$?

    # Go back to working directory
    cd - >/dev/null

    g_TMP_FILES="$g_TMP_FILES $g_TEMPDIR/${g_SOURCEFILE##*/}.log $g_TEMPDIR/${g_SOURCEFILE##*/}.o"

    if [[ -z `cat $g_TEMPDIR/${g_SOURCEFILE##*/}.log` ]]
    then
	echo "Done, program '${g_SOURCEFILE##*/}$g_BINEXT' ready."
        if [[ $g_EXEC -eq 1 ]]
        then
            ${g_TEMPDIR}/${g_SOURCEFILE%.bac*}
        fi
    else
        LINE=$(cat ${g_TEMPDIR}/${g_SOURCEFILE##*/}.log | grep -v ".generic.h" | grep -E -i "error:|warning:|note:" | head -1)
        LINE=${LINE//$g_STRINGSIGN/\$}
        LINE=${LINE//$g_FLOATSIGN/\#}
        LINE=${LINE//$g_LONGSIGN/\%}
        echo ${LINE}
	echo
        if [[ $g_QUIET -eq 0 ]]
        then
            if [[ ${BACON_IN_DOCKER} = "true" ]]
            then
                ANSWER="y"
            else
                if [[ -n $BASH ]]
                then
                    read -p "INFO: see full error report (y/[n])? " ANSWER
                else
                    read ANSWER?"INFO: see full error report (y/[n])? "
                fi
            fi
            if [[ ${ANSWER} = "y" ]]
            then
                LINE=$(cat $g_TEMPDIR/${g_SOURCEFILE##*/}.log)
                LINE=${LINE//$g_STRINGSIGN/\$}
                LINE=${LINE//$g_FLOATSIGN/\#}
                LINE=${LINE//$g_LONGSIGN/\%}
                echo "${LINE}"
                echo
            fi
        fi
        # Preserve temp files
	g_TMP_PRESERVE=1
    fi
fi

# Cleanup
if [[ $g_TMP_PRESERVE -eq 0 ]]
then
    for i in $g_TMP_FILES
    do
	if [[ -f $i && ${i} != +(*.bac) ]]
        then
	    rm $i
        fi
    done
fi

exit $RETURN_CODE
