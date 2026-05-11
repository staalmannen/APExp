#!/bin/sh
# runtests.sh - run CHICKEN testsuite
#
# - Note: this needs a proper shell, so it will not work with plain mingw
#   (just the compiler and the Windows shell, without MSYS)

set -e
if test -z "$MSYSTEM"; then
    TEST_DIR=`pwd`
    PATH_SEP=':'
else
    # Use Windows-native format with drive letters instead of awkward
    # MSYS /c/blabla "pseudo-paths" which break when used in syscalls.
    TEST_DIR=`pwd -W`
    PATH_SEP=';'
fi

DYLD_LIBRARY_PATH=${TEST_DIR}/..
LD_LIBRARY_PATH=${TEST_DIR}/..
LIBRARY_PATH=${TEST_DIR}/..:${LIBRARY_PATH}
# Cygwin uses LD_LIBRARY_PATH for dlopen(), but the dlls linked into
# the binary are read by the OS itself, which uses $PATH (mingw too)
# Oddly, prefixing .. with ${TEST_DIR}/ does _not_ work on mingw!
PATH=..:${PATH}

export DYLD_LIBRARY_PATH LD_LIBRARY_PATH LIBRARY_PATH PATH

case `uname` in
	AIX)
		DIFF_OPTS=-b ;;
	*)
		DIFF_OPTS=-bu ;;
esac

CHICKEN=${TEST_DIR}/../${PROGRAM_PREFIX}chicken${PROGRAM_SUFFIX}
CHICKEN_PROFILE=${TEST_DIR}/../${PROGRAM_PREFIX}chicken-profile${PROGRAM_SUFFIX}
CHICKEN_INSTALL=${TEST_DIR}/../${PROGRAM_PREFIX}chicken-install${PROGRAM_SUFFIX}
CHICKEN_UNINSTALL=${TEST_DIR}/../${PROGRAM_PREFIX}chicken-uninstall${PROGRAM_SUFFIX}
CHICKEN_INSTALL_REPOSITORY=${TEST_DIR}/test-repository
CHICKEN_REPOSITORY_PATH="${TEST_DIR}/..${PATH_SEP}${CHICKEN_INSTALL_REPOSITORY}"

export CHICKEN_INSTALL_REPOSITORY CHICKEN_REPOSITORY_PATH

TYPESDB=../types.db
COMPILE_OPTIONS="-v -compiler ${CHICKEN} -I${TEST_DIR}/.. -L${TEST_DIR}/.. -include-path ${TEST_DIR}/.. -libdir ${TEST_DIR}/.. -rpath ${TEST_DIR}/.."

compile="../${PROGRAM_PREFIX}csc${PROGRAM_SUFFIX} ${COMPILE_OPTIONS} -o a.out -types ${TYPESDB} -ignore-repository"
compile_r="../${PROGRAM_PREFIX}csc${PROGRAM_SUFFIX} ${COMPILE_OPTIONS}"
compile_s="../${PROGRAM_PREFIX}csc${PROGRAM_SUFFIX} ${COMPILE_OPTIONS} -s -types ${TYPESDB} -ignore-repository"
interpret="../${PROGRAM_PREFIX}csi${PROGRAM_SUFFIX} -n -include-path ${TEST_DIR}/.."
time=time

# Check for a "time" command, since some systems don't ship with a
# time(1) or shell builtin and we also can't portably rely on `which',
# `command', etc. NOTE "time" must be called from a variable here.
set +e
$time true >/dev/null 2>/dev/null
test $? -eq 127 && time=
set -e

rm -fr *.exe *.so *.o *.obj *.out *.import.* ../foo.import.* test-repository
mkdir -p test-repository
cp $TYPESDB test-repository/types.db

echo "======================================== repository search path ..."
if test -z "$MSYSTEM"; then
  export -p >./env.out
  unset CHICKEN_REPOSITORY_PATH
  $interpret -s repository-path-default.scm
  . ./env.out
else
  env -u CHICKEN_REPOSITORY_PATH $interpret -s repository-path-default.scm
fi
$compile_s sample-module.scm -j sample-module
cp sample-module.so $CHICKEN_INSTALL_REPOSITORY
cp sample-module.import.scm $CHICKEN_INSTALL_REPOSITORY
$interpret -s repository-path.scm "${TEST_DIR}/.." "${TEST_DIR}/test-repository"

echo "======================================== types.db consistency ..."
$interpret -s types-db-consistency.scm ${TYPESDB}

echo "======================================== version tests ..."
$compile version-tests.scm
./a.out

echo "======================================== compiler tests ..."
$compile compiler-tests.scm
./a.out

echo "======================================== csc tests ..."
$interpret -s csc-tests.scm

echo "======================================== compiler inlining tests  ..."
$compile_r inline-me.scm -s -J -oi inline-me.inline
$compile inlining-tests.scm -optimize-level 3
./a.out
$compile inline-unroll.scm -optimize-level 3
./a.out

echo "======================================== compiler message tests ..."
$compile -analyze-only messages-test.scm 2>messages.out
diff $DIFF_OPTS messages.expected messages.out

echo "======================================== optimizer tests  ..."
$compile clustering-tests.scm -clustering
./a.out

$compile rest-arg-tests.scm -specialize
./a.out

echo "======================================== profiler tests ..."
$compile null.scm -profile -profile-name TEST.profile
./a.out
$CHICKEN_PROFILE TEST.profile

echo "======================================== scrutiny tests ..."
$compile scrutinizer-tests.scm -analyze-only
$compile typematch-tests.scm -specialize -no-warnings
./a.out

$compile test-scrutinizer-message-format.scm -analyze-only -specialize 2>scrutinizer-message-format.out || true
$compile scrutiny-tests.scm -analyze-only -specialize 2>scrutiny.out
$compile scrutiny-tests-2.scm -analyze-only -specialize 2>scrutiny-2.out
$compile specialization-tests.scm -analyze-only -specialize -specialize 2>specialization.out

# Replace foo123 -> fooXX so gensyms don't trigger failures
$compile redact-gensyms.scm -o redact-gensyms
./redact-gensyms "tmp,g,scm:,a,b" < scrutinizer-message-format.out > scrutinizer-message-format.redacted
./redact-gensyms < scrutiny-2.out > scrutiny-2.redacted
./redact-gensyms < scrutiny.out > scrutiny.redacted
./redact-gensyms < specialization.out > specialization.redacted

diff $DIFF_OPTS scrutinizer-message-format.expected scrutinizer-message-format.redacted
diff $DIFF_OPTS scrutiny.expected scrutiny.redacted
diff $DIFF_OPTS scrutiny-2.expected scrutiny-2.redacted
diff $DIFF_OPTS specialization.expected specialization.redacted

$compile scrutiny-tests-3.scm -specialize -block
./a.out

$compile scrutiny-tests-strict.scm -strict-types -specialize
./a.out

echo "======================================== line number database ..."
$compile -O3 test-line-numbers.scm 2> test-line-numbers.out
diff $DIFF_OPTS test-line-numbers.expected test-line-numbers.out
./a.out

echo "======================================== specialization tests ..."
rm -f foo.types foo.import.*
$compile specialization-test-1.scm -emit-types-file foo.types -specialize \
  -debug ox -emit-import-library foo
./a.out
$compile specialization-test-2.scm -types foo.types -types specialization-test-2.types -specialize -debug ox
./a.out
rm -f foo.types foo.import.*

echo "======================================== specialization benchmark ..."
$compile fft.scm -O2 -local -d0 -disable-interrupts -b -o fft1.out
$compile fft.scm -O2 -local -specialize -debug x -d0 -disable-interrupts -b -o fft2.out -specialize
echo "normal:"
$time ./fft1.out 1000 7
echo "specialized:"
$time ./fft2.out 1000 7

echo "======================================== unboxing benchmark ..."
$compile fft.scm -O2 -local -d0 -disable-interrupts -b -o fft1.out
$compile fft.scm -O4 -debug x -d0 -disable-interrupts -b -o fft2.out
echo "normal:"
$time ./fft1.out 1000 7
echo "unboxing:"
$time ./fft2.out 1000 7

echo "======================================== callback tests ..."
$compile -extend c-id-valid.scm callback-tests.scm
./a.out

if ./a.out twice; then
    echo "double-return from callback didn't fail"
    exit 1
else
    echo "double-return from callback failed as it should."
fi

echo "======================================== runtime tests ..."
$interpret -s apply-test.scm
$compile apply-test.scm
./a.out
if ./a.out -:A10k; then
    echo "apply test with limited temp stack didn't fail"
    exit 1
else
    echo "apply test with limited temp stack failed as it should."
fi

$compile test-gc-hooks.scm
./a.out

echo "======================================== library tests ..."
$interpret -s library-tests.scm
$compile -specialize library-tests.scm
./a.out
$interpret -s records-and-setters-test.scm
$compile records-and-setters-test.scm
./a.out
$interpret -s record-printer-test.scm
$compile record-printer-test.scm
./a.out

echo "======================================== reader tests ..."
$interpret -s reader-tests.scm

echo "======================================== dynamic-wind tests ..."
$interpret -s dwindtst.scm >dwindtst.out
diff $DIFF_OPTS dwindtst.expected dwindtst.out
$compile dwindtst.scm
./a.out >dwindtst.out
diff $DIFF_OPTS dwindtst.expected dwindtst.out

echo "======================================== lolevel tests ..."
$interpret -s lolevel-tests.scm
$compile -specialize lolevel-tests.scm
./a.out

echo "======================================== arithmetic tests ..."
$interpret -D check -s arithmetic-test.scm

echo "======================================== pretty-printer tests ..."
$interpret -s pp-test.scm

echo "======================================== evaluation environment tests ..."
$interpret -s environment-tests.scm

echo "======================================== syntax tests ..."
$interpret -s syntax-tests.scm

echo "======================================== syntax tests (compiled) ..."
$compile syntax-tests.scm
./a.out

echo "======================================== syntax tests (v2, compiled) ..."
$compile syntax-tests-2.scm
./a.out

echo "======================================== meta-syntax tests ..."
$interpret -bnq meta-syntax-test.scm -e '(import foo)' -e "(assert (equal? '((1)) (bar 1 2)))" -e "(assert (equal? '(list 1 2 3) (listify)))" -e "(import test-import-syntax-for-syntax)" -e "(assert (equal? '(1) (test)))" -e "(import test-begin-for-syntax)" -e "(assert (equal? '(1) (test)))"
$compile_s meta-syntax-test.scm -j foo
$compile_s foo.import.scm
$interpret -bnq meta-syntax-test.scm -e '(import foo)' -e "(assert (equal? '((1)) (bar 1 2)))" -e "(assert (equal? '(list 1 2 3) (listify)))" -e "(import test-import-syntax-for-syntax)" -e "(assert (equal? '(1) (test)))" -e "(import test-begin-for-syntax)" -e "(assert (equal? '(1) (test)))"

echo "======================================== reexport tests ..."
$interpret -bnq reexport-tests.scm
$compile reexport-tests.scm
./a.out
rm -f reexport-m*.import*
$compile_s reexport-m1.scm -J
$compile_s reexport-m1.import.scm
$interpret -s reexport-m2.scm
$compile reexport-m2.scm
./a.out
$compile_s reexport-m3.scm -J
$compile_s reexport-m4.scm -J
$compile_s reexport-m5.scm -J
$compile_s reexport-m6.scm -J
$compile_s reexport-m7.scm -J
$compile_s reexport-m8.scm -J
$compile_s reexport-m9.scm -J
$compile_s reexport-m10.scm -J
$compile reexport-tests-2.scm
./a.out

echo "======================================== functor tests ..."
$interpret -bnq simple-functors-test.scm
$compile simple-functors-test.scm
./a.out
$interpret -bnq functor-tests.scm
$compile functor-tests.scm
./a.out
$compile -s square-functor.scm -J
$compile -s square-functor.import.scm
$interpret -bnq use-square-functor.scm
$compile use-square-functor.scm
./a.out
$compile -s use-square-functor.scm -J
$interpret -nqe '(require-library use-square-functor)' -e '(import sf1)' -e '(import sf2)'
rm -f sf1.import.* sf2.import.* lst.import.* mod.import.*

echo "======================================== compiler syntax tests ..."
$compile compiler-syntax-tests.scm
./a.out

echo "======================================== import tests ..."
$interpret -bnq import-tests.scm

echo "======================================== import library tests ..."
rm -f ../foo.import.* foo.import.*
$compile import-library-test1.scm -emit-import-library foo
$interpret -s import-library-test2.scm
$compile_s foo.import.scm -o foo.import.so
$interpret -s import-library-test2.scm
$compile import-library-test2.scm
./a.out
rm -f foo.import.*

echo "======================================== optionals test ..."
$interpret -s test-optional.scm
$compile test-optional.scm
./a.out

echo "======================================== syntax tests (matchable) ..."
$interpret matchable.scm -s match-test.scm

echo "======================================== syntax tests (loopy-loop) ..."
$interpret -s loopy-test.scm

echo "======================================== r4rstest ..."
echo "(expect mult-float-print-test to fail)"
$interpret -e '(set! ##sys#procedure->string (constantly "#<procedure>"))' \
  -i -s r4rstest.scm >r4rstest.out

diff $DIFF_OPTS r4rstest.expected r4rstest.out

echo "======================================== syntax tests (r5rs_pitfalls) ..."
echo "(expect two failures)"
$interpret -i -s r5rs_pitfalls.scm

echo "======================================== r7rs tests ..."
$interpret -i -s r7rs-tests.scm

echo "======================================== module tests ..."
$interpret -include-path ${TEST_DIR}/.. -s module-tests.scm
$interpret -include-path ${TEST_DIR}/.. -s module-tests-2.scm

echo "======================================== module tests (command line options) ..."
module="test-$(date +%s)"
$compile test.scm -A -w -j "$module" -module "$module"
$interpret -e "(import-syntax $module)"
rm -f "$module.import.scm"

echo "======================================== module tests (compiled) ..."
$compile module-tests-compiled.scm
./a.out
$compile module-static-eval-compiled.scm
./a.out
$compile -static module-static-eval-compiled.scm
./a.out

echo "======================================== module tests (chained) ..."
rm -f m*.import.* test-chained-modules.so
$interpret -bnq test-chained-modules.scm
$compile_s test-chained-modules.scm -j m3
$compile_s m3.import.scm
$interpret -bn test-chained-modules.so
$interpret -bn test-chained-modules.so -e '(import m3) (s3)'

echo "======================================== module tests (ec) ..."
rm -f ec.so ec.import.*
$interpret -bqn ec.scm ec-tests.scm
$compile_s ec.scm -emit-import-library ec -o ec.so
$compile_s ec.import.scm -o ec.import.so 
$interpret -bnq ec.so ec-tests.scm
# $compile ec-tests.scm
# ./a.out        # takes ages to compile

echo "======================================== module tests (static link) ..."
$compile_r -static -unit sample-module -J -c sample-module.scm
mv sample-module.link sample-module.import.scm sample-module.o* "$CHICKEN_INSTALL_REPOSITORY"
$compile_r -static module-static-link.scm -o a.out
./a.out

echo "======================================== port tests ..."
$interpret -s port-tests.scm

echo "======================================== read-lines tests ..."
$interpret -s read-lines-tests.scm

echo "======================================== fixnum tests ..."
$compile fixnum-tests.scm
./a.out
$compile -unsafe fixnum-tests.scm
./a.out

echo "======================================== random number tests ..."
$interpret -s random-tests.scm

echo "======================================== string->number tests ..."
$interpret -s numbers-string-conversion-tests.scm
$compile -specialize numbers-string-conversion-tests.scm
./a.out

echo "======================================== basic numeric ops tests ..."
$interpret -s numbers-test.scm
$compile -specialize numbers-test.scm
./a.out

echo "======================================== Alex Shinn's numeric ops tests ..."
$interpret -s numbers-test-ashinn.scm
$compile -specialize numbers-test-ashinn.scm
./a.out

echo "======================================== Gauche's numeric ops tests ..."
$interpret -s numbers-test-gauche.scm
$compile -specialize numbers-test-gauche.scm
./a.out

echo "======================================== srfi-4 tests ..."
$interpret -s srfi-4-tests.scm

echo "======================================== condition tests ..."
$interpret -s condition-tests.scm

echo "======================================== data-structures tests ..."
$interpret -s data-structures-tests.scm

echo "======================================== path tests ..."
$interpret -bnq path-tests.scm

echo "======================================== srfi-45 tests ..."
$interpret -s srfi-45-tests.scm

echo "======================================== posix tests ..."
$compile posix-tests.scm
./a.out

echo "======================================== file access tests ..."
if test -n "$MSYSTEM"; then
  $interpret -s file-access-tests.scm //
  $interpret -s file-access-tests.scm \\
else
  $interpret -s file-access-tests.scm /
fi

echo "======================================== find-files tests ..."
$interpret -bnq test-find-files.scm

echo "======================================== create-temporary-file tests ..."
if test -z "$MSYSTEM"; then
  echo "== SKIPPED due to problematic unsetenv behaviour on Windows =="
else
  $interpret -bnq test-create-temporary-file.scm
fi

echo "======================================== record-renaming tests ..."
$interpret -bnq record-rename-test.scm

echo "======================================== regular expression tests ..."
$interpret -bnq test-irregex.scm
$interpret -bnq test-glob.scm

echo "======================================== compiler/nursery stress test ..."
for s in 100000 120000 200000 250000 300000 350000 400000 450000 500000; do
    echo "  $s"
    ${CHICKEN} -ignore-repository ../port.scm -:s$s -output-file tmp.c -include-path ${TEST_DIR}/..
done

echo "======================================== heap literal stress test ..."
$compile heap-literal-stress-test.scm
for s in 100000 120000 200000 250000 300000 350000 400000 450000 500000; do
  echo "  $s"
  ./a.out -:d -:g -:hi$s
done

echo "======================================== weak pointer test ..."
$compile weak-pointer-test.scm
./a.out

echo "======================================== symbol-GC tests ..."
$compile symbolgc-tests.scm
./a.out

echo "======================================== finalizer tests ..."
$interpret -s test-finalizers.scm
$compile test-finalizers.scm
./a.out
$compile finalizer-error-test.scm
echo "expect an error message here:"
./a.out -:hg101
$compile test-finalizers-2.scm
./a.out

echo "======================================== locative stress test ..."
$compile locative-stress-test.scm
./a.out

echo "======================================== syntax-rules stress test ..."
$time $interpret -bnq syntax-rule-stress-test.scm

echo "======================================== include test ..."
mkdir -p a/b
echo > a/b/ok.scm
echo '(include "a/b/ok.scm")' > a/b/include.scm
$compile -analyze-only a/b/include.scm
echo '(include "b/ok.scm")' > a/b/include.scm
$compile -analyze-only a/b/include.scm -include-path a
echo '(include-relative "ok.scm")' > a/b/include.scm
$compile -analyze-only a/b/include.scm
echo '(include-relative "b/ok.scm")' > a/include.scm
$compile -analyze-only a/include.scm
echo '(include-relative "b/ok.scm")' > a/b/include.scm
$compile -analyze-only a/b/include.scm -include-path a
echo > a/b/other.scm
# make sure first include doesn't change state for second:
echo '(include-relative "b/ok.scm") (include-relative "b/other.scm")' > a/include.scm
$compile -analyze-only a/include.scm
echo '(include-relative "ok.scm")' > a/b/other.scm
echo '(include-relative "b/other.scm")' > a/include.scm
$compile -analyze-only a/include.scm
echo '(include-relative "b/other.scm") (let () (include-relative "b/ok.scm") (include-relative "b/ok.scm"))' > a/include.scm
$compile -analyze-only a/include.scm
rm -r a

echo "======================================== executable tests ..."
$compile executable-tests.scm
./a.out "$TEST_DIR/a.out"

echo "======================================== user pass tests ..."
$compile -extend user-pass-tests.scm null.scm

echo "======================================== embedding (1) ..."
$compile embedded1.c
./a.out

echo "======================================== embedding (2) ..."
$compile -e embedded2.scm
./a.out

echo "======================================== embedding (3) ..."
$compile -e embedded3.c embedded4.scm
./a.out

echo "======================================== linking tests ..."
$compile_r -unit reverser reverser/tags/1.0/reverser.scm -J -c
mv reverser/tags/1.0/reverser.o* ./
$compile_r -link reverser linking-tests.scm -o a.out
./a.out
$compile_r -link reverser linking-tests.scm -o a.out -static
./a.out
mv reverser.o* reverser.import.scm "$CHICKEN_INSTALL_REPOSITORY"
$compile_r -link reverser linking-tests.scm -o a.out
./a.out
$compile_r -link reverser linking-tests.scm -o a.out -static
./a.out

echo "======================================== private repository test ..."
mkdir -p tmp
$compile private-repository-test.scm -private-repository -o tmp/xxx
tmp/xxx ${TEST_DIR}/tmp
# This MUST be `pwd`: ${PWD} is not portable, and ${TEST_DIR} breaks mingw-msys
PATH=`pwd`/tmp:$PATH xxx ${TEST_DIR}/tmp
# this may crash, if the PATH contains a non-matching libchicken.dll on Windows:
#PATH=$PATH:${TEST_DIR}/tmp xxx ${TEST_DIR}/tmp

echo "======================================== multiple return values tests ..."
$interpret -s multiple-values.scm
$compile multiple-values.scm
./a.out

echo "======================================== done. All tests passed."
