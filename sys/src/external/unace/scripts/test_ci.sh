#!/bin/sh

scdir=$(dirname "$0")
. ${scdir}/0functions.sh
. ${scdir}/test_ci.cfg

w_system=$(uname -s)

#=============================================================

cmd_echo()
{
    echo "# $@"
    "$@" #| exit 1
}

run_docker_imgs()
{
    #Only CircleCI seems to support this
    # 1) copy current directory to docker container
    # 2) run this script inside docker container to build and test the app
    QEMU_MULTIARCH_ENABLED=
    docker_results=
    dret=0
    dtty=
    if [ -t 0 ] && [ -t 1 ] ; then
        # avoid error: 'the input device is not a TTY'
        # only allocate tty if we detect one
        dtty="-it"
    fi
    for dq in ${DOCKER_TARGETS}
    do
        darch=
        dimg=
        case $dq in
            "#"*) continue ;;
            *"|"*) # ARCH|IMG
                darch=$(echo "$dq" | cut -f 1 -d '|')
                dimg=$(echo "$dq" | cut -f 2 -d '|') ;;
            *)  # IMG
                dimg=${dq} ;;
        esac
        echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++"
        echo "          $dq"
        echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++"
        if [ "$darch" ] && [ ! "$QEMU_MULTIARCH_ENABLED" ] ; then
            # Enable run containers with different architectures
            cmd_echo docker run --rm --privileged multiarch/qemu-user-static --reset -p yes
            QEMU_MULTIARCH_ENABLED=1
        fi
        # Run docker container
        if [ "$darch" ] ; then
            cmd_echo docker run ${dtty} -d --platform linux/${darch} --name WCONTAINER ${dimg}
        else
            cmd_echo docker run ${dtty} -d --name WCONTAINER ${dimg}
        fi
        #docker exec ${dtty} WCONTAINER sh -c "
        #        set -ex;
        #        apt update;
        #        apt upgrade -y;
        #        apt-get install -y git build-essential gdb;
        #        "
        CURDIR=$(pwd)
        cmd_echo docker exec ${dtty} WCONTAINER mkdir -p /tmp
        cmd_echo docker cp $CURDIR WCONTAINER:/tmp/
        cmd_echo docker exec ${dtty} WCONTAINER sh -c "
            set -ex;
            pwd;
            cd /tmp/$(basename $CURDIR);
                ./scripts/test_ci.sh;"
        if [ $? -eq 0 ] ; then
            confirm='OK'
        else
            confirm='ERR'
            dret=1
        fi
        echo ; echo ""
        docker_results="$docker_results
- ${darch}|${dimg}  : $confirm"
        cmd_echo docker stop WCONTAINER
        cmd_echo docker rm WCONTAINER
        echo
    done
    echo
    echo "+++++++"
    echo "Results"
    echo "+++++++"
    echo "$docker_results"
    exit ${dret}
}

if [ "$CIRCLECI" ] && [ "$DOCKER_TARGETS_CIRCLE" ] ; then
    DOCKER_TARGETS="${DOCKER_TARGETS_CIRCLE}"
    unset CIRCLECI DOCKER_TARGETS_CIRCLE
    run_docker_imgs
fi


#=============================================================

case $1 in
    debug|-debug)
        RUN_TEST_SCRIPT_DIRECTLY=1
        ;;
    installpkg_alpine)
        shift
        set -x
        apk add --no-cache ${@}
        exit $?
        ;;
    installpkg_deb)
        shift
        set -ex
        apt update
        apt upgrade -y
        apt-get install -y ${@}
        exit $?
        ;;
    installpkg_macos)
        shift
        set -x
        export HOMEBREW_NO_AUTO_UPDATE=1
        brew install ${@}
        exit $?
        ;;
    installpkg_freebsd)
        shift
        set -x
        #export REPO_AUTOUPDATE=NO
        pkg install -y ${@}
        exit $?
        ;;
esac

#=============================================================

cmdecho_v()
{
    echo
    echo "#################################"
    echo "# $@"
    echo "#################################"
    "$@"
}

print_config_log()
{
    for i in config.h config.log config.mk
    do
        echo "
===============================
	$i
===============================
"
        cat ${i}
    done
}

exit_error()
{
    print_config_log
    exit 1
}

#=============================================================
# print some system info

if [ -f /etc/os-release ] ; then
    . /etc/os-release
    echo "$PRETTY_NAME"
    echo
elif [ -f /etc/release ] ; then
    head -n 3 /etc/release
fi

uname -a
echo
if command -v cc 1>/dev/null 2>&1 ; then
    cc --version 2>/dev/null
elif command -v gcc 1>/dev/null 2>&1 ; then
    gcc --version 2>/dev/null
fi
#echo
#id

case "$w_system" in
    Darwin|FreeBSD)
        sysctl kern.coredump
        sysctl kern.corefile
        ;;
esac

#=============================================================

#export CFLAGS="-DDEBUG_W_ENDIAN"
export VERBOSE_ERRORS='yes' # the test script read this
#export PRINT_SUM_ON_ERROR='yes'
#exprt DOWNLOAD_IS_REQUIRED='yes'

    #cmdecho_v ./configure  || exit_error
    #cmdecho_v make         || exit_error
    #cmdecho_v make check   || exit_error
    ##cmdecho_v make install || exit_error

# assuming we're testing a compiled binary that's built with -02 (optimizations)
cmdecho_v ./scripts/run-tests.sh -rebuild
if [ $? -ne 0 ] ; then
    if [ "$w_system" = "Darwin" ] ; then
        # macOS is a hostile environment, just end here
        exit_error
    fi
    if grep -q ' -O2' config.log ; then
        echo
        echo "################################################################"  
        echo "   Testing with extra debug symbols and without optimizations   "
        echo "################################################################"
        echo
        # one or tests failed, segfaults?
        # run with extra debug symbols and without optimizations
        # if there are no segfaults, the optimizations are causing the segfaults
        cmdecho_v ./scripts/run-tests.sh -debug
    fi
    exit_error
fi


