#!/bin/sh
# Public domain
#
# Variables that can be exported and will be used here:
# - CHKSUM_TYPE
# - CHKSUM_APP
# - DOWNLOAD_APP (this include extra params so download_file() works)
# - DOWNLOAD_IS_REQUIRED [yes/no]
#

set_checksum_app() # $1:[$CHKSUM_TYPE]
{
    # set checksum app to be used later
    if [ -n "$1" ] ; then
        CHKSUM_TYPE="$1"
    fi
    case ${CHKSUM_TYPE} in
        md5)    CHKSUM_GNU='md5sum'    ; CHKSUM_BSD='md5'    ;;
        sha1)   CHKSUM_GNU='sha1sum'   ; CHKSUM_BSD='sha1'   ;;
        sha256) CHKSUM_GNU='sha256sum' ; CHKSUM_BSD='sha256' ;;
        sha512) CHKSUM_GNU='sha512sum' ; CHKSUM_BSD='sha512' ;;
        *)
            echo "*** ${CHKSUM_TYPE}: unknown checksum type"
            echo "*** Valid types: md5, sha1, sha256, sha512"
            exit 1 ;;
    esac

    if test -z "$CHKSUM_APP" ; then
        if command -v ${CHKSUM_GNU} ; then
            export CHKSUM_APP=${CHKSUM_GNU}
        elif command -v ${CHKSUM_BSD} ; then
            export CHKSUM_APP=${CHKSUM_BSD}
        else
            echo "${CHKSUM_GNU}/${CHKSUM_BSD} utility is missing, please install it"
            echo "aborting tests"
            exit 1
        fi
    fi
}


set_download_app()
{
    if test -n "$DOWNLOAD_APP" ; then
        return # already set
    fi
    if command -v curl ; then
        export DOWNLOAD_APP='curl -sSL -o'
    elif command -v wget ; then
        export DOWNLOAD_APP='wget -q --no-check-certificate -O'
    elif command -v fetch ; then # FreeBSD
        export DOWNLOAD_APP='fetch -q --no-verify-peer -o'
    else
        echo "Cannot find curl/wget/fetch.."
        if [ "$DOWNLOAD_IS_REQUIRED" = "yes" ] ; then
            exit 1
        fi
    fi
}


download_file() # $1:<url> [outfile]
{
    dlurl="$1"
    dlfile="$2"
    if [ -z "$dlfile" ] ; then
        dlfile=$(basename "$dlurl")
    fi
    if ! [ -f "${dlfile}" ] ; then
        if [ -z "$DOWNLOAD_APP" ] && [ "$DOWNLOAD_IS_REQUIRED" = "yes" ] ; then
            # only trigger this error if file is missing
            echo "\$DOWNLOAD_APP has not been set"
            exit 1
        fi
        echo "# ${DOWNLOAD_APP} \"${dlfile}\" \"${dlurl}\""
        ${DOWNLOAD_APP} "${dlfile}" "${dlurl}"
        if [ $? -ne 0 ] ; then
            echo "Could not download file" >&2
            rm -f "${dlfile}"
            return 1
        fi
    fi
    return 0
}


check_app_help() # $1<ret_code> $2:<app_help_cmd>
{
    expected_ret="$1"
    app_help="$2"
    #echo "# $app_help"
    ${app_help} >/dev/null 2>&1
    appret=$?
    if [ ${appret} -ne ${expected_ret} ] ; then
        echo "Something is wrong with ${app}"
        echo "Got code $appret (expected ${expected_ret})"
        echo "Aborted"
        exit 1
    fi
}


wrealpath() # $1:<path>
{
    # realpath may not exist (msys1, old macos, etc)
    # readlink -f may not work: old macos
    if [ -d "$1" ] ; then
        echo $(cd "$1" ; pwd -P)
        return $?
    fi
    xdirname=$(cd $(dirname "$1") ; pwd -P)
    xbasename=$(basename "$1")
    echo "${xdirname}/${xbasename}"
}
