#!/bin/sh
# Public domain

scdir=$(dirname "$0")
. ${scdir}/0functions.sh

scriptdir=$(wrealpath "$scdir")

w_system=$(uname -s)

if [ -z "$RUN_TESTS_CFG" ] ; then
    RUN_TESTS_CFG=${scriptdir}/run-tests.cfg
fi
if [ "$1" = "-cfg" ] ; then
    RUN_TESTS_CFG=$(wrealpath "$2")
    shift 2
fi
if [ -z "$RUN_TESTS_CFG" ] ; then
    help 1
fi

. ${RUN_TESTS_CFG} || exit 1

REBUILD=no
DEBUG_BUILD=
case $1 in
    -rebuild) REBUILD=yes ;;
    -run)     REBUILD=no ;;
    -debug)   REBUILD=yes ; DEBUG_BUILD=1 ;;
    -release) REBUILD=yes ;;
    #*) help 0 ;;
esac

if [ "$DEBUG_BUILD" ] ; then
    export CFLAGS="-DW_MTRACE -g -O0 -ggdb3 -Wextra -Wno-unused-parameter -Wno-missing-field-initializers"
fi

# ===========================================================================
# Functions

set_checksum_app
set_download_app

set_wine()
{
    wine=''
    if [ "${w_system}" = "Linux" ] ; then
        if [ "$wine_require_msys" = "yes" ] ; then
            echo "*** The tests currently fail on WINE (issues with paths, etc)"
            echo "*** You must use MSYS1 or MSYS2 (MinGW distribution)"
            echo
            exit 1
        fi
        wine='wine'
        if ! command -v wine >/dev/null ; then
            echo "WINE is not installed, cannot test .exe binaries..."
            exit 1
        fi
    fi
}


check_sums_from_file()
{
    # file was created with xxxsum (i.e. md5sum), otherwise this will fail
    chksum_file="$1"
    logfile="$2"
    if [ -z "$CHKSUM_APP" ] || [ -z "$chksum_file" ] ; then
        return 0 # ok
    fi
    echo "------------------------------" >>${logfile}
    if [ "$CHKSUM_APP" = "$CHKSUM_GNU" ] && [ "$PRINT_SUM_ON_ERROR" != "yes" ] ; then
        # GNU style, fast
        ${CHKSUM_APP} -c ${chksum_file} >>${logfile} 2>&1
        retcode=$?
        echo "------------------------------" >>${logfile}
        return $retcode
    fi
    # PRINT_SUM_ON_ERROR:
    # BSD and slow GNU: get sum from each file and compare
    # BSD implementations are not consistent, just use something that all versions understand
    while read sum file
    do
        if [ "$CHKSUM_APP" = "$CHKSUM_BSD" ] ; then
            filesum=$($CHKSUM_APP -q "$file")
        else # GNU
            filesum=$($CHKSUM_APP "$file" | cut -f 1 -d " ")
        fi
        if [ "$sum" != "$filesum" ] ; then
            echo "${file}: FAILED"  >>${logfile}
            echo "Got SUM     : $filesum" >>${logfile}
            echo "Expected SUM: $sum" >>${logfile}
            echo "*** checksum failed. stopped" >>${logfile}
            return 1 #error
        #else
        #    echo "${file}: [OK]"  >>${logfile}
        fi
    done < ${chksum_file}
    echo "All sums are OK" >>${logfile}
    echo "------------------------------" >>${logfile}
    return 0 # ok
}


check_dirs_from_dirlist_file()
{
	dirlist_file="$1"
	logfile="$2"
	if [ -z "$dirlist_file" ] ; then
		return 0
	fi
	wret=0
	echo "checking dirs..." >>${logfile}
	while read dir ; do
		if [ ! -d "$dir" ] ; then
			wret=1
			echo "[ERROR] $dir is missing" >>${logfile}
		fi
	done < ${dirlist_file}
	return ${wret}
}


gdbargs=''
if command -v gdb >/dev/null ; then
    gdbargs='gdb --args'
fi

ERROR_LOG_FILES=''

run_test()
{
    n_tests=$((n_tests+1))
    unset CHKFILE DIRFILE LOGFILE
    if [ -z "$TEST_FILE" ] ; then
        echo "** a \$TEST_FILE is required for run_test()"
        echo "** fix the script!"
        exit 1
    fi
    #--
    if [ -n "$TEST_FILE_URL" ] ; then
        download_file "$TEST_FILE_URL" "$TEST_FILE"
        unset TEST_FILE_URL
    fi
    #--
    if ! [ -f "$TEST_FILE" ] ; then
        echo "** $TEST_FILE doesn't exist .. fix the script"
        exit 1
    fi
    TEST_FILE_NAME=$(basename "$TEST_FILE")
    if [ -f ${TEST_FILE}.${CHKSUM_TYPE} ] ; then
        CHKFILE=${TEST_FILE}.${CHKSUM_TYPE}
    fi
    if [ -f ${TEST_FILE}.dirs ] ; then
        DIRFILE=${TEST_FILE}.dirs
    fi
    LOGFILE=${TESTDIR}/${TEST_FILE_NAME}.log
    #--
    test_error=
    #--
    printf "* [test] ${TEST_FILE_NAME}: "
    echo >${LOGFILE}
    echo "------------------------------------" >>${LOGFILE}
    echo "${gdbargs} $@" >>${LOGFILE}
    echo "------------------------------------" >>${LOGFILE}
    if [ "$TEST_USE_SUBDIR" = "yes" ] ; then
        xcurdirx=$(pwd)
        rm -rf ${TESTDIR}/${TEST_FILE_NAME}_test
        mkdir -p ${TESTDIR}/${TEST_FILE_NAME}_test
        cd ${TESTDIR}/${TEST_FILE_NAME}_test
    fi
    "$@" >>${LOGFILE} 2>&1
    exit_code=$?
    if [ "$TEST_RUN_GDB_ON_SEGFAULT" = "yes" ] ; then
        # segfault? try to get backtrace
        case ${exit_code} in 132|133|134|135|136|137|138|139)
            echo "------------------------------------" >>${LOGFILE}
            echo "${scriptdir}/backtrace.sh -run ${@}" >>${LOGFILE}
            echo "------------------------------------" >>${LOGFILE}
            ${scriptdir}/backtrace.sh -run ${@} >>${LOGFILE} 2>&1
            ;;
        esac
    fi
    if [ -z "$TEST_EXIT_CODE" ] ; then
        TEST_EXIT_CODE=0 # default
    fi
    case ${TEST_EXIT_CODE} in
        !*)
            if [ "!${exit_code}" = "${TEST_EXIT_CODE}" ] ; then
                echo "[ERROR] Exit code  = ${exit_code}" >>${LOGFILE}
                test_error=1
            fi
            ;;
        *)
            if [ "${exit_code}" = "${TEST_EXIT_CODE}" ] ; then
                echo "[OK] Exit code = ${exit_code}" >>${LOGFILE}
            else
                echo "[ERROR] Exit code  = ${exit_code}" >>${LOGFILE}
                echo "Expected exit code = ${TEST_EXIT_CODE}" >>${LOGFILE}
                test_error=1
            fi
            ;;
    esac
    if [ -n "$TEST_ERROR_FILE" ] ; then
        if [ -e "$TEST_ERROR_FILE" ] ; then
            echo "[ERROR] $TEST_ERROR_FILE exists" >>${LOGFILE}
            test_error=1
        fi
    fi
    if ! check_sums_from_file "${CHKFILE}" "${LOGFILE}" ; then
        test_error=1
    fi
    if ! check_dirs_from_dirlist_file "${DIRFILE}" "${LOGFILE}" ; then
        test_error=1
    fi
    if [ -z "$test_error" ] ; then
        echo "OK"
    else
        echo "ERROR"
        ERROR_LOG_FILES="$ERROR_LOG_FILES ${LOGFILE}"
        failed_tests=$((failed_tests+1))
    fi
    if [ "$TEST_USE_SUBDIR" = "yes" ] ; then
        cd "${xcurdirx}"
    fi
    unset TEST_FILE TEST_ERROR_FILE TEST_EXIT_CODE
}


cmdecho()
{
    echo "---------------"
    echo "# $@"
    echo "---------------"
    "$@"
}

# ===========================================================================

if [ -f autogen.sh ] && [ ! -f configure ] ; then
    ./autogen.sh
fi

if [ -f configure ] ; then
    if [ "$REBUILD" = "yes" ] || [ ! -f config.log ] ; then
        cmdecho ./configure ${configure_opts}
    fi
fi

if [ -f Makefile ] ; then
    if [ "$REBUILD" = "yes" ] ; then
        cmdecho ${make_clean}
    fi
    cmdecho ${make_cmd}
fi

if test -f ${app} ; then
    ok=1 
elif [ -f ${app}.exe ] ; then # .exe binary
    set_wine
    app="${wine} ${app}.exe"
else
    echo "$app not found"
    exit 1
fi

# basic check
cmdecho check_app_help ${help_ret_code} "${app} ${help_param}"

# ===========================================================================

echo
appname=$(basename "$app")
TESTDIR=$(pwd)/0runtests_${appname}
rm -rf "${TESTDIR}"
mkdir -p "${TESTDIR}"
cd ${TESTDIR}

failed_tests=0
n_tests=0
run_tests

# ===========================================================================

ret=0

if [ -n "$(echo $ERROR_LOG_FILES)" ] ; then
    ret=1
    echo
    if [ "$VERBOSE_ERRORS" = "yes" ] ; then
        echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
        cat $ERROR_LOG_FILES
    fi
fi

printf "\n Logs are in $TESTDIR\n"
echo "   (that dir is deleted and created everytime the tests are run)"
echo

if [ $failed_tests -gt 0 ] ; then
    echo "*  $failed_tests out of $n_tests tests failed"
else
    echo "*  All OK"
fi
echo

exit $ret
