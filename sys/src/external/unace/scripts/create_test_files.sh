#!/bin/sh
# Public domain

MWD=$(pwd)
CHKSUM_TYPE='md5'
DOWNLOAD_IS_REQUIRED='no'
CMD="unace x %s"  # %s = inputfile
CMD_RET=0

#===================================================================

##how to create dirlist from current dir
#find . -type d | sort | sed -e 's%\./%%' -e '/^\.$/d' > ../dirlist.dirs

##how to create md5 file from current dir
#find . -type f | sort | sed 's%\./%%' | while read f; do md5sum "$f" ; done > ../dirlist.md5
#find . -type f | sort | sed 's%\./%%' | while read f; do sha256sum "$f" ; done > ../dirlist.sha256

scriptdir=$(dirname "$0")
. ${scriptdir}/0functions.sh

set_checksum_app
set_download_app


create_dirlist_file_from_dir() # $1:<from_dir> $2:<dirlist_file>
{
    fromdir="$1"
    dirlist_file="$2"
    find ${fromdir} -type d | sort | sed -e 's%\./%%' -e '/^\.$/d' > ${dirlist_file}
    if [ "$(cat "${dirlist_file}")" = "" ] ; then
        # empty dir, remove dirlist_file
        rm -f "${dirlist_file}"
    fi
}


create_sums_file_from_dir() # $1:<from_dir> $2:<chkfile>
{
    fromdir="$1"
    chkfile="$2"
    if test -z "$CHKSUM_APP" ; then
        return 0 # ok
    fi
    if [ "$CHKSUM_APP" = "$CHKSUM_BSD" ] ; then
        # --BSD--
        find ${fromdir} -type f | sort | sed 's%\./%%' | \
            while read xfilex ; do
                filesum=$($CHKSUM_APP -q "$xfilex")
                echo "$filesum  $xfilex"
            done > ${chkfile}
    else
        # --GNU--
        find ${fromdir} -type f | sort | sed 's%\./%%' | \
            while read xfilex ; do
                ${CHKSUM_APP} "$xfilex" # handle files with spaces
            done > ${chkfile}
    fi
    if [ $? -ne 0 ] ; then
        return 1 #error
    fi
    return 0 # ok
}


process_file()
{
    inputfile=${1}
    file=$(basename "$inputfile")
    case $inputfile in
      http*|ftp*)
        download_file "$inputfile"
        if [ $? -ne 0 ] ; then
            exit 1
        fi
        realpath=$(readlink -f "$file")
        TESTFILE_DIR=$(dirname "$realpath")
        ;;
      *)
        if [ ! -f "$inputfile" ] ; then
            echo "$inputfile doesn't exist"
            exit 1
        fi
        TESTFILE_DIR=$(dirname "$inputfile")
        ;;
    esac
    #--
    echo "* [Processing] $file"
    #--
    TESTFILE_NAME=${file}
    TESTFILE=${TESTFILE_DIR}/${file}
    CHKFILE=${TESTFILE_DIR}/${TESTFILE_NAME}.${CHKSUM_TYPE}
    DIRFILE=${TESTFILE_DIR}/${TESTFILE_NAME}.dirs
    if [ -f "$CHKFILE" ] ; then
        echo "** ${file} has already been processed. Delete generated files to process again"
        return
    fi
    #--
    rm -rf ${file}_test
    mkdir -p ${file}_test
    cd  ${file}_test
    #--
    case $CMD in
        *"%s"*) RCMD=$(printf "$CMD" "$TESTFILE") ;;
        *) RCMD=${CMD} ;;
    esac
    echo "# ${RCMD}"
    ${RCMD}
    wret=$?
    if [ ${wret} -ne ${CMD_RET} ] ; then
        echo "Got exit code ${wret}, but was expecting ${CMD_RET}"
        exit 1
    fi
    create_sums_file_from_dir . ${CHKFILE}
    create_dirlist_file_from_dir . ${DIRFILE}
    cd ..
}

#===================================================================

if [ -z "$1" ] ; then
    echo "Nothing to process..."
    exit 0
fi

case ${1} in
    http*|ftp*) rpath=${1} ;;
    *) rpath=$(readlink -f "$1") ;; #= realpath()
esac

mkdir -p create_test_tmp
cd create_test_tmp

case "$rpath" in *create_test.list)
    echo "create_test.list: should contain files to process..."
    while read line
    do
        if [ -z "$line" ] ; then
            continue
        fi
        case $line in "#"*)
            continue;;
        esac
        process_file "$line"
    done < "$rpath"
    exit
    ;;
esac

process_file "$rpath"
