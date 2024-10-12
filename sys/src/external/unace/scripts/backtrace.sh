#!/bin/sh
# Public domain
#
# The app2debug must be compiled with -g -O0
#   otherwise there won't be enough info
#
# https://www.brendangregg.com/blog/2016-08-09/gdb-example-ncurses.html
#

w_system=$(uname -s)

case "$w_system" in
    Darwin) echo "$0:
    lldb doesn't work on macOS due to permissions or something
    "
        exit ;;
esac


usage()
{
    echo "syntax:

  1) $0 [options] -run <app> [args]
        run app through gdb and get a backtrace [recommended]

  2) $0 [options] -coredump <app> [args]
        run app and expect a core dump which will be used to produce the backtrace

  3) $0 [options] -corefile file <app>
        produce backtrace from corefile without running app

 options:
      --gdb    use gdb
      --lldb   use lldb
"
    exit 0
}

#===========================================================

set_backtrace_app()
{
  if [ -z "$BACKTRACE_APP" ] ; then
    # Use gdb where possible, lldb doesn't seem work at least on linux i686
    # https://bugs.archlinux32.org/index.php?do=details&task_id=108
    if command -v gdb ; then
        BACKTRACE_APP='gdb'
    elif command -v lldb ; then
        BACKTRACE_APP='lldb'
    else
        echo "gdb and lldb are missing..."
        exit 1 # error
    fi
  fi
}

#===========================================================
# easiest method to get a backtrace, run app through gdb

backtrace_run()
{
    if [ -z "$BACKTRACE_APP" ] ; then
        echo "\$BACKTRACE_APP has not been set"
    fi
    if [ "$BACKTRACE_APP" = "gdb" ] ; then
        gdb --batch --quiet \
            -ex="run" \
            -ex="thread apply all backtrace" \
            --args ${app2debug} ${app_args}
    elif [ "$BACKTRACE_APP" = "lldb" ] ; then
        # https://lldb.llvm.org/use/map.html
        if [ "$(uname -m)" = "i686" ] ; then
            echo "*** WARNING: lldb may be broken in i686"
        fi
        # -o "thread backtrace all"
        # -o "bt all"
        lldb --batch  \
            -o "run" \
            -o "bt" \
            -- ${app2debug} ${app_args}
    else
        echo "${BACKTRACE_APP}: unknown backtrace app"
        exit 1 # error
    fi
}

#===========================================================
# - run application and expect a core dump
# - the core dump file location is the problem here
# - the platform may not allow core dumps

app_to_core_dump() # this sets CORE_FILE
{
    coredump_path='coredump'
    if [ "$w_system" = "Linux" ] ; then
        # this is 'core' by default, but can also include directory and %variables
        coredump_path=$(cat /proc/sys/kernel/core_pattern)
        echo "coredump pattern = ${coredump_path}"
        echo
        # force creation of core dump (reset this value at the end)
        cur_ulimit=$(ulimit -c)
        ulimit -c unlimited
    fi
    rm -f ${coredump_path}

    ${app2debug} ${app_args}
    rtval=$?
    case ${exit_code} in 132|133|134|135|136|137|138|139) # 128 + SIGXXX
        # SIGILL|SIGTRAP|SIGABRT|SIGBUS?|SIGFPE|?|SIGBUS?|SIGSEGV
        need_coredump=1
        ;;
    esac

    if [ "$w_system" = "Linux" ] ; then
        ulimit -c ${cur_ulimit}
    fi

    if [ ${rtval} -lt 128 ] ; then
        # anything below 128 doesn't signal a core dump file should be written
        exit ${rtval}
    fi

    if [ -f "$coredump_path" ] ; then
        CORE_FILE="$coredump_path"
        return 0;
    fi

    # try to find core dump
    coredump_path=$(find -maxdepth 1 -name 'core.*' | head -n 1)
    if [ -f "$coredump_path" ] ; then
        CORE_FILE="$coredump_path"
        return 0;
    fi

    # if we get here, we must exit with the app's exit code
    if [ "$need_coredump" ] ; then
        echo "ERROR: Where is the core dump?"
    fi
    exit ${rtval}
}

#===========================================================

backtrace_from_core_dump()
{
    # don't call this function if $CORE_FILE doesn't exist
    if [ -z "$BACKTRACE_APP" ] ; then
        echo "\$BACKTRACE_APP has not been set"
    fi
    echo
    echo "CORE_FILE = $CORE_FILE"
    echo
    if [ "$BACKTRACE_APP" = "gdb" ] ; then
        # -ex="bt full"
        gdb --batch --quiet \
            -ex="thread apply all backtrace" \
            ${app2debug} ${CORE_FILE}
    elif [ "$BACKTRACE_APP" = "lldb" ] ; then
        # https://lldb.llvm.org/use/map.html
        if [ "$(uname -m)" = "i686" ] ; then
            echo "*** WARNING: lldb may be broken in i686"
        fi
         lldb --batch \
            -o "bt" \
            --core "$CORE_FILE" ${app2debug}
    else
        echo "${BACKTRACE_APP}: unknown backtrace app"
        exit 1 # error
    fi
}

#===========================================================
# main

unset NEED_CORE_DUMP CORE_FILE

if [ -z "$1" ] ; then
    usage
fi

for i in $@
do
    case $1 in
        -run|--run) ok=1 ;;
        -coredump|--coredump) NEED_CORE_DUMP=1 ;;
        -corefile|--corefile) CORE_FILE=${2} ; shift ;;
        --gdb)  BACKTRACE_APP='gdb'   ;;
        --lldb) BACKTRACE_APP='lldb' ;;
        -h|--help) usage ;;
        -*) echo "Unknown param: $1" ;;
        *) break ;;
    esac
    shift
done

app2debug=${1}
shift
app_args="$@"

if [ -z "$app2debug" ] ; then
    usage
fi

if [ ! -f "$app2debug" ] ; then
    echo "$app2debug: not found"
    exit 1 # error
fi

set_backtrace_app

if [ -z "$NEED_CORE_DUMP" ] && [ -z "$CORE_FILE" ] ; then
    backtrace_run
    exit $?
fi

if [ "$NEED_CORE_DUMP" ] ; then
    app_to_core_dump
    backtrace_from_core_dump
    exit $?
fi

if [ "$CORE_FILE" ] ; then
    if [ ! -f "$CORE_FILE" ] ; then
        echo "ERROR: $CORE_FILE doesn't exist"
        exit 1
    fi
    backtrace_from_core_dump
fi
