#!/bin/sh
# Public domain
#
# 2023-01-03
# 
# - This is for Linux + GLIBC, works with any app that
#   was compiled with <mcheck.h> and calls the mtrace() function
# - The mtrace utility is required
#
export CFLAGS="-DW_MTRACE -ggdb3"

#### how to make this work with apps:
##if defined(W_MTRACE) && defined(__GLIBC__)
##include <mcheck.h>
##endif

#int main(int argc, char * argv[])
#{
##if defined(W_MTRACE) && defined(__GLIBC__)
#   mtrace();
##endif
#}

#==============================================================

help()
{
    echo "
syntax:
  $0 [-cfg mtrace.cfg] <command>

  commands: 
     -run      compile app and run mtrace
     -rebuild  reconfigure, compile everything and run mtrace

  Use -rebuild to ensure mtrace is enabled in the build
  and then use -run to compile only what's changed

  mtrace() may only work as expected with C applications...
"
    exit $1
}

if [ -z "$MTRACE_CFG" ] ; then
    scriptdir=$(dirname "$0")
    MTRACE_CFG=${scriptdir}/mtrace.cfg
fi
if [ "$1" = "-cfg" ] ; then
    MTRACE_CFG=$(realpath "$2")
    shift 2
fi
if [ -z "$MTRACE_CFG" ] ; then
    help 1
fi

. ${MTRACE_CFG} || exit 1

REBUILD=no
case $1 in
    -rebuild) REBUILD=yes ;;
    -run)     REBUILD=no ;;
    *) help 0 ;;
esac

#==============================================================

if [ "$(uname -s)" != "Linux" ] ; then
    echo "This only runs on Linux (requires the GNU C Library)"
    exit
else
    echo -e "\nInfo: this only works with the GNU C Library\n"
fi

if ! command -v mtrace ; then
    printf "mtrace is missing\n";
    exit 1
fi

appname=$(basename "$app")
mtrace_dir=$(pwd)/0mtrace_${appname}
rm -rf "${mtrace_dir}"
mkdir -p "${mtrace_dir}"
export MALLOC_TRACE=${mtrace_dir}/mtrace.txt

#==============================================================

if [ -f autogen.sh ] && [ ! -f configure ] ; then
    ./autogen.sh
fi

if [ "$REBUILD" = "yes" ] ; then
    if [ -f configure ] ; then
        ./configure ${configure_opts}
    fi
else
    if [ -f configure ] && [ ! -f config.log ] ; then
        ./configure ${configure_opts}
    fi
fi

if [ -f Makefile ] ; then
    if [ "$REBUILD" = "yes" ] ; then
        ${make_clean}
    fi
    ${make_cmd}
fi

if ! [ -f ${app} ] ; then
    echo "$app not found"
    exit 1
fi

#==============================================================

echo
echo "CFG: $MTRACE_CFG"
echo

i=1
while IFS="|" read app_args cleanup_cmd
do
    if [ -z "$app_args" ] ; then
        continue
    fi
    sync
    if [ -n "$test_subdir" ] ; then
        rm -rf ${test_subdir}
        mkdir -p ${test_subdir}
        cd ${test_subdir}
    fi
    rm -f ${MALLOC_TRACE}
    (
    echo
    echo "${app} ${app_args}"
    echo
    ${app} ${app_args}
    ) >${mtrace_dir}/mtrace${i}.${appname}.log 2>&1
    ${cleanup_cmd}
    printf "TEST: $app_args "
    mtrace ${app} ${MALLOC_TRACE} > ${mtrace_dir}/mtrace-out.txt
    mtret=$?
    case $mtret in
        # mtrace is a perl script, apparently 0 & 1 are valid codes
        # anything else is because of die() which can be any number
        0) echo "... OK" ;;
        1) 
            echo "... ERR"
            echo "** Memory leaks detected in ${mtrace_dir}/mtrace${i}-out.txt"
            ;;
        *)
            echo
            echo " [${mtret}] error running mtrace"
            ;;
    esac
    if [ ! -f ${MALLOC_TRACE} ] ; then
        echo "     you may need to recompile the app with mtrace() support"
        exit 1
    fi
    mv ${MALLOC_TRACE} ${mtrace_dir}/mtrace${i}.txt
    mv ${mtrace_dir}/mtrace-out.txt ${mtrace_dir}/mtrace${i}-out.txt
    i=$((i+1))
    if [ -n "$test_subdir" ] ; then
        cd ..
    fi
done <<EOF
$mtrace_tests
EOF

if [ -n "$test_subdir" ] ; then
    rm -rf "$test_subdir"
fi

echo
echo "see ${mtrace_dir}  directory"
