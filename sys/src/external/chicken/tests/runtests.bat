@echo off
@rem runtests.bat - run CHICKEN testsuite on cmd.exe with mingw

setlocal enableextensions

set TEST_DIR=%cd%

set CHICKEN=..\%PROGRAM_PREFIX%chicken%PROGRAM_SUFFIX%
set CHICKEN_PROFILE=..\%PROGRAM_PREFIX%chicken-profile%PROGRAM_SUFFIX%
set CHICKEN_INSTALL_REPOSITORY=%TEST_DIR%\test-repository
set CHICKEN_REPOSITORY_PATH=%TEST_DIR%\..;%CHICKEN_INSTALL_REPOSITORY%
set PATH=%TEST_DIR%\..;%PATH%

rem Increase this when tests start failing on "inexplicable" diffs
set FCBUFSIZE=500

set TYPESDB=..\types.db
set COMPILE_OPTIONS=-v -compiler %CHICKEN% -I%TEST_DIR%/.. -L%TEST_DIR%/.. -include-path %TEST_DIR%/.. -libdir %TEST_DIR%/..

set compile=..\%PROGRAM_PREFIX%csc%PROGRAM_SUFFIX% %COMPILE_OPTIONS% -o a.out -types %TYPESDB% -ignore-repository
set compile_r=..\%PROGRAM_PREFIX%csc%PROGRAM_SUFFIX% %COMPILE_OPTIONS%
set compile_s=..\%PROGRAM_PREFIX%csc%PROGRAM_SUFFIX% %COMPILE_OPTIONS% -s -types %TYPESDB% -ignore-repository
set interpret=..\%PROGRAM_PREFIX%csi%PROGRAM_SUFFIX% -n -include-path %TEST_DIR%/..

del /f /q /s *.exe *.so *.o *.obj *.out *.import.* ..\foo.import.* %CHICKEN_INSTALL_REPOSITORY%
rmdir /q /s %CHICKEN_INSTALL_REPOSITORY%
mkdir %CHICKEN_INSTALL_REPOSITORY%
copy %TYPESDB% %CHICKEN_INSTALL_REPOSITORY%

echo ======================================== repository search path ...
setlocal
set "CHICKEN_REPOSITORY_PATH="
%interpret% -s repository-path-default.scm
if errorlevel 1 exit /b 1
endlocal
%compile_s% sample-module.scm -j sample-module
if errorlevel 1 exit /b 1
copy sample-module.so %CHICKEN_INSTALL_REPOSITORY%
copy sample-module.import.scm %CHICKEN_INSTALL_REPOSITORY%
%interpret% -s repository-path.scm "%TEST_DIR%\.." "%TEST_DIR%\test-repository"
if errorlevel 1 exit /b 1

echo ======================================== types.db consistency ...
%interpret% -s types-db-consistency.scm %TYPESDB%
if errorlevel 1 exit /b 1

echo ======================================== version tests ...
%compile% version-tests.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== compiler tests ...
%compile% compiler-tests.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo "======================================== csc tests ..."
%interpret% -s csc-tests.scm
if errorlevel 1 exit /b 1

echo ======================================== compiler inlining tests  ...
%compile_r% inline-me.scm -s -J -oi inline-me.inline
if errorlevel 1 exit /b 1
%compile% inlining-tests.scm -optimize-level 3
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
%compile% inline-unroll.scm -optimize-level 3
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== compiler message tests ...
%compile% -analyze-only messages-test.scm 2>messages.out
if errorlevel 1 exit /b 1
fc /lb%FCBUFSIZE% /w messages.expected messages.out
if errorlevel 1 exit /b 1

echo ======================================== optimizer tests  ...
%compile% clustering-tests.scm -clustering
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

%compile% rest-arg-tests.scm -specialize
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== profiler tests ...
%compile% null.scm -profile -profile-name TEST.profile
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
%CHICKEN_PROFILE% TEST.profile
if errorlevel 1 exit /b 1

echo ======================================== scrutiny tests ...
%compile% scrutinizer-tests.scm -analyze-only
%compile% typematch-tests.scm -specialize -w
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

%compile% test-scrutinizer-message-format.scm -analyze-only -specialize 2>scrutinizer-message-format.out
rem this is expected to fail, so no errorlevel check
%compile% scrutiny-tests.scm -analyze-only -specialize 2>scrutiny.out
if errorlevel 1 exit /b 1
%compile% scrutiny-tests-2.scm -analyze-only -specialize 2>scrutiny-2.out
if errorlevel 1 exit /b 1
%compile% specialization-tests.scm -analyze-only -specialize 2>specialization.out
if errorlevel 1 exit /b 1

rem Replace foo123 -> fooXX so gensyms don't trigger failures
%compile% redact-gensyms.scm -o redact-gensyms
if errorlevel 1 exit /b 1
redact-gensyms "tmp,g,scm:,a,b" < scrutinizer-message-format.out > scrutinizer-message-format.redacted
if errorlevel 1 exit /b 1
redact-gensyms < scrutiny-2.out > scrutiny-2.redacted
if errorlevel 1 exit /b 1
redact-gensyms < scrutiny.out > scrutiny.redacted
if errorlevel 1 exit /b 1
redact-gensyms < specialization.out > specialization.redacted
if errorlevel 1 exit /b 1

fc /lb%FCBUFSIZE% /w scrutinizer-message-format.expected scrutinizer-message-format.redacted
if errorlevel 1 exit /b 1
fc /lb%FCBUFSIZE% /w scrutiny.expected scrutiny.redacted
if errorlevel 1 exit /b 1
fc /lb%FCBUFSIZE% /w scrutiny-2.expected scrutiny-2.redacted
if errorlevel 1 exit /b 1
fc /lb%FCBUFSIZE% /w specialization.expected specialization.redacted
if errorlevel 1 exit /b 1

%compile% scrutiny-tests-3.scm -specialize -block
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

%compile% scrutiny-tests-strict.scm -strict-types -specialize
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== line number database ...
%compile% -O3 test-line-numbers.scm 2>test-line-numbers.out
if errorlevel 1 exit /b 1
fc /lb%FCBUFSIZE% /w test-line-numbers.expected test-line-numbers.out
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== specialization tests ...
del /f /q foo.types foo.import.*
%compile% specialization-test-1.scm -emit-types-file foo.types -specialize -debug ox -emit-import-library foo
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
%compile% specialization-test-2.scm -types foo.types -types specialization-test-2.types -specialize -debug ox
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
del /f /q foo.types foo.import.*

echo ======================================== specialization benchmark ...
%compile% fft.scm -O2 -local -d0 -disable-interrupts -b -o fft1.out
if errorlevel 1 exit /b 1
%compile% fft.scm -O2 -local -specialize -debug x -d0 -disable-interrupts -b -o fft2.out -specialize
if errorlevel 1 exit /b 1
echo normal:
fft1.out 1000 7
if errorlevel 1 exit /b 1
echo specialized:
fft2.out 1000 7
if errorlevel 1 exit /b 1

echo ======================================== unboxing benchmark ...
%compile% fft.scm -O2 -local -d0 -disable-interrupts -b -o fft1.out
if errorlevel 1 exit /b 1
%compile% fft.scm -O4 -debug x -d0 -disable-interrupts -b -o fft2.out
if errorlevel 1 exit /b 1
echo normal:
fft1.out 1000 7
if errorlevel 1 exit /b 1
echo unboxing:
fft2.out 1000 7
if errorlevel 1 exit /b 1

echo ======================================== callback tests ...
%compile% -extend c-id-valid.scm callback-tests.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
a.out twice

if errorlevel 1 (
  echo double-return from callback failed as it should.
) else (
  echo double-return from callback didn't fail
  exit /b 1
)

echo ======================================== runtime tests ...
%interpret% -s apply-test.scm
if errorlevel 1 exit /b 1
%compile% apply-test.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
a.out -:A10k

if errorlevel 1 (
  echo apply test with limited temp stack failed as it should.
) else (
  echo apply test with limited temp stack didn't fail
  exit /b 1
)

%compile% test-gc-hooks.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== library tests ...
%interpret% -s library-tests.scm
if errorlevel 1 exit /b 1
%compile% -specialize library-tests.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
%interpret% -s records-and-setters-test.scm
if errorlevel 1 exit /b 1
%compile% records-and-setters-test.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
%interpret% -s record-printer-test.scm
if errorlevel 1 exit /b 1
%compile% record-printer-test.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== reader tests ...
%interpret% -s reader-tests.scm
if errorlevel 1 exit /b 1

echo ======================================== dynamic-wind tests ...
%interpret% -s dwindtst.scm >dwindtst.out
if errorlevel 1 exit /b 1
fc /lb%FCBUFSIZE% /w dwindtst.expected dwindtst.out
if errorlevel 1 exit /b 1
%compile% dwindtst.scm
if errorlevel 1 exit /b 1
a.out >dwindtst.out
if errorlevel 1 exit /b 1
fc /lb%FCBUFSIZE% /w dwindtst.expected dwindtst.out
if errorlevel 1 exit /b 1

echo ======================================== lolevel tests ...
%interpret% -s lolevel-tests.scm
if errorlevel 1 exit /b 1
%compile% lolevel-tests.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== arithmetic tests ...
%interpret% -D check -s arithmetic-test.scm
if errorlevel 1 exit /b 1

echo ======================================== pretty-printer tests ...
%interpret% -s pp-test.scm
if errorlevel 1 exit /b 1

echo ======================================== evaluation environment tests ...
%interpret% -s environment-tests.scm
if errorlevel 1 exit /b 1

echo ======================================== syntax tests ...
%interpret% -s syntax-tests.scm
if errorlevel 1 exit /b 1

echo ======================================== syntax tests (compiled) ...
%compile% syntax-tests.scm
a.out
if errorlevel 1 exit /b 1

echo ======================================== syntax tests (v2, compiled) ...
%compile% syntax-tests-2.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== meta-syntax tests ...
%interpret% -bnq meta-syntax-test.scm -e "(import foo)" -e "(assert (equal? '((1)) (bar 1 2)))" -e "(assert (equal? '(list 1 2 3) (listify)))" -e "(import test-import-syntax-for-syntax)" -e "(assert (equal? '(1) (test)))" -e "(import test-begin-for-syntax)" -e "(assert (equal? '(1) (test)))"
if errorlevel 1 exit /b 1
%compile_s% meta-syntax-test.scm -j foo
if errorlevel 1 exit /b 1
%compile_s% foo.import.scm
if errorlevel 1 exit /b 1
%interpret% -bnq meta-syntax-test.scm -e "(require-library meta-syntax-test)" -e "(import foo)" -e "(assert (equal? '((1)) (bar 1 2)))" -e "(assert (equal? '(list 1 2 3) (listify)))" -e "(import test-import-syntax-for-syntax)" -e "(assert (equal? '(1) (test)))" -e "(import test-begin-for-syntax)" -e "(assert (equal? '(1) (test)))"
if errorlevel 1 exit /b 1

echo ======================================== reexport tests ...
%interpret% -bnq reexport-tests.scm
if errorlevel 1 exit /b 1
%compile% reexport-tests.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
del /f /q reexport-m*.import*
%compile_s% reexport-m1.scm -J
if errorlevel 1 exit /b 1
%compile_s% reexport-m1.import.scm
if errorlevel 1 exit /b 1
%interpret% -s reexport-m2.scm
if errorlevel 1 exit /b 1
%compile% reexport-m2.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
%compile_s% reexport-m3.scm -J
if errorlevel 1 exit /b 1
%compile_s% reexport-m4.scm -J
if errorlevel 1 exit /b 1
%compile_s% reexport-m5.scm -J
if errorlevel 1 exit /b 1
%compile_s% reexport-m6.scm -J
if errorlevel 1 exit /b 1
%compile_s% reexport-m7.scm -J
if errorlevel 1 exit /b 1
%compile_s% reexport-m8.scm -J
if errorlevel 1 exit /b 1
%compile_s% reexport-m9.scm -J
if errorlevel 1 exit /b 1
%compile_s% reexport-m10.scm -J
if errorlevel 1 exit /b 1
%compile% reexport-tests-2.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1


echo ======================================== functor tests ...
%interpret% -bnq simple-functors-test.scm
if errorlevel 1 exit /b 1
%compile% simple-functors-test.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
%interpret% -bnq functor-tests.scm
if errorlevel 1 exit /b 1
%compile% functor-tests.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
%compile% -s square-functor.scm -J
if errorlevel 1 exit /b 1
%compile% -s square-functor.import.scm
if errorlevel 1 exit /b 1
%interpret% -bnq use-square-functor.scm
if errorlevel 1 exit /b 1
%compile% use-square-functor.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
%compile% -s use-square-functor.scm -J
if errorlevel 1 exit /b 1
%interpret% -nqe "(require-library use-square-functor)" -e "(import sf1)" -e "(import sf2)"
if errorlevel 1 exit /b 1
del /f /q sf1.import.* sf2.import.* lst.import.* mod.import.*

echo ======================================== compiler syntax tests ...
%compile% compiler-syntax-tests.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== import tests ...
%interpret% -bnq import-tests.scm
if errorlevel 1 exit /b 1

echo ======================================== import library tests ...
del /f /q ..\foo.import.* foo.import.*
%compile% import-library-test1.scm -emit-import-library foo
if errorlevel 1 exit /b 1
%interpret% -s import-library-test2.scm
if errorlevel 1 exit /b 1
%compile_s% foo.import.scm -o foo.import.so
if errorlevel 1 exit /b 1
%interpret% -s import-library-test2.scm
if errorlevel 1 exit /b 1
%compile% import-library-test2.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
del /f /q foo.import.*

echo ======================================== optionals test ...
%interpret% -s test-optional.scm
if errorlevel 1 exit /b 1
%compile% test-optional.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== syntax tests (matchable) ...
%interpret% matchable.scm -s match-test.scm
if errorlevel 1 exit /b 1

echo ======================================== syntax tests (loopy-loop) ...
%interpret% -s loopy-test.scm
if errorlevel 1 exit /b 1

echo ======================================== r4rstest ...
echo (expect mult-float-print-test to fail)
%interpret% -e "(set! ##sys#procedure->string (constantly \"#<procedure>\"))" -i -s r4rstest.scm >r4rstest.out
if errorlevel 1 exit /b 1

type r4rstest.out

echo ======================================== syntax tests (r5rs_pitfalls) ...
echo (expect two failures)
%interpret% -i -s r5rs_pitfalls.scm
if errorlevel 1 exit /b 1

echo "======================================== r7rs tests ..."
echo (expect two failures)
%interpret% -i -s r7rs-tests.scm
if errorlevel 1 exit /b 1

echo ======================================== module tests ...
%interpret% -include-path %TEST_DIR%/.. -s module-tests.scm
if errorlevel 1 exit /b 1
%interpret% -include-path %TEST_DIR%/.. -s module-tests-2.scm
if errorlevel 1 exit /b 1

echo ======================================== module tests (command line options) ...
set module="test"
%compile% test.scm -w -A -j %module% -module %module%
if errorlevel 1 exit /b 1
%interpret% -e "(import-syntax %module%)"
if errorlevel 1 exit /b 1
del /f /q %module%.import.scm

echo ======================================== module tests (compiled) ...
%compile% module-tests-compiled.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
%compile% module-static-eval-compiled.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
%compile% -static module-static-eval-compiled.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== module tests (chained) ...
del /f /q m*.import.* test-chained-modules.so
%interpret% -bnq test-chained-modules.scm
if errorlevel 1 exit /b 1
%compile_s% test-chained-modules.scm -j m3
if errorlevel 1 exit /b 1
%compile_s% m3.import.scm
if errorlevel 1 exit /b 1
%interpret% -bn test-chained-modules.so
if errorlevel 1 exit /b 1
%interpret% -bn test-chained-modules.so -e "(import m3) (s3)"
if errorlevel 1 exit /b 1

echo ======================================== module tests (ec) ...
del /f /q ec.so ec.import.*
%interpret% -bqn ec.scm ec-tests.scm
if errorlevel 1 exit /b 1
%compile_s% ec.scm -emit-import-library ec -o ec.so
if errorlevel 1 exit /b 1
%compile_s% ec.import.scm -o ec.import.so
if errorlevel 1 exit /b 1
%interpret% -bnq ec.so ec-tests.scm
rem %compile% ec-tests.scm
rem a.out        # takes ages to compile

echo ======================================== module tests (static link) ...
%compile_r% -static -unit sample-module -J -c sample-module.scm -o sample-module.obj
if errorlevel 1 exit /b 1
move sample-module.link %CHICKEN_INSTALL_REPOSITORY%
move sample-module.import.scm %CHICKEN_INSTALL_REPOSITORY%
move sample-module.obj %CHICKEN_INSTALL_REPOSITORY%
%compile_r% -static module-static-link.scm -o a.out
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== port tests ...
%interpret% -s port-tests.scm
if errorlevel 1 exit /b 1

echo ======================================== read-lines tests ...
%interpret% -s read-lines-tests.scm
if errorlevel 1 exit /b 1

echo ======================================== fixnum tests ...
%compile% fixnum-tests.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
%compile% -unsafe fixnum-tests.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo"======================================== random number tests ...
%interpret% -s random-tests.scm
if errorlevel 1 exit /b 1

echo ======================================== string-^>number tests ...
%interpret% -s numbers-string-conversion-tests.scm
if errorlevel 1 exit /b 1
%compile% -specialize numbers-string-conversion-tests.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== basic numeric ops tests ...
%interpret% -s numbers-test.scm
if errorlevel 1 exit /b 1
%compile% -specialize numbers-test.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== Alex Shinns numeric ops tests ...
%interpret% -s numbers-test-ashinn.scm
if errorlevel 1 exit /b 1
%compile% -specialize numbers-test-ashinn.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== Gauche numeric ops tests ...
%interpret% -s numbers-test-gauche.scm
if errorlevel 1 exit /b 1
%compile% -specialize numbers-test-gauche.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== srfi-4 tests ...
%interpret% -s srfi-4-tests.scm
if errorlevel 1 exit /b 1

echo ======================================== condition tests ...
%interpret% -s condition-tests.scm
if errorlevel 1 exit /b 1

echo ======================================== data-structures tests ...
%interpret% -s data-structures-tests.scm
if errorlevel 1 exit /b 1

echo ======================================== path tests ...
%interpret% -bnq path-tests.scm
if errorlevel 1 exit /b 1

echo ======================================== srfi-45 tests ...
%interpret% -s srfi-45-tests.scm
if errorlevel 1 exit /b 1

echo ======================================== posix tests ...
%compile% posix-tests.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== file access tests ...
%interpret% -s file-access-tests.scm /
if errorlevel 1 exit /b 1
%interpret% -s file-access-tests.scm \
if errorlevel 1 exit /b 1

echo ======================================== find-files tests ...
%interpret% -bnq test-find-files.scm
if errorlevel 1 exit /b 1

echo ======================================== create-temporary-file tests ...
echo == SKIPPED due to problematic unsetenv behaviour on Windows ==
@rem %interpret% -bnq test-create-temporary-file.scm
@rem if errorlevel 1 exit /b 1

echo ======================================== record-renaming tests ...
%interpret% -bnq record-rename-test.scm
if errorlevel 1 exit /b 1

echo ======================================== regular expression tests ...
%interpret% -bnq test-irregex.scm
if errorlevel 1 exit /b 1
%interpret% -bnq test-glob.scm
if errorlevel 1 exit /b 1

echo ======================================== compiler/nursery stress test ...
for %%s in (100000 120000 200000 250000 300000 350000 400000 450000 500000) do (
  echo %%s
  %CHICKEN% -ignore-repository ..\port.scm -:s%%s -output-file tmp.c -include-path %TEST_DIR%/..
  if errorlevel 1 exit /b 1
)

echo ======================================== heap literal stress test ...
%compile% heap-literal-stress-test.scm
if errorlevel 1 exit /b 1

for %%s in (100000 120000 200000 250000 300000 350000 400000 450000 500000) do (
  echo %%s
  a.out -:hi%%s
  if errorlevel 1 exit /b 1
)

echo ======================================== weak pointer test ...
%compile% weak-pointer-test.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== symbol-GC tests ...
%compile% symbolgc-tests.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== finalizer tests ...
%interpret% -s test-finalizers.scm
if errorlevel 1 exit /b 1
%compile% test-finalizers.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== finalizer tests (2) ...
%compile% finalizer-error-test.scm
if errorlevel 1 exit /b 1
a.out -:hg101
if errorlevel 1 exit /b 1
%compile% test-finalizers-2.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== locative stress test ...
%compile% locative-stress-test.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== syntax-rules stress test ...
%interpret% -bnq syntax-rule-stress-test.scm

echo "======================================== include test ..."
mkdir a\b
echo > a\b\ok.scm
echo '(include "a/b/ok.scm")' > a\b\include.scm
%compile% -analyze-only a\b\include.scm
if errorlevel 1 exit /b 1
echo '(include "b/ok.scm")' > a\b\include.scm
%compile% -analyze-only a\b\include.scm -include-path a
if errorlevel 1 exit /b 1
echo '(include-relative "ok.scm")' > a\b\include.scm
%compile% -analyze-only a\b\include.scm
if errorlevel 1 exit /b 1
echo '(include-relative "b/ok.scm")' > a\include.scm
%compile% -analyze-only a\include.scm
if errorlevel 1 exit /b 1
echo '(include-relative "b/ok.scm")' > a\b\include.scm
%compile% -analyze-only a\b\include.scm -include-path a
if errorlevel 1 exit /b 1
del /f /s /q a

echo "======================================== executable tests ..."
%compile% executable-tests.scm
if errorlevel 1 exit /b 1
a.out %TEST_DIR%\a.out
if errorlevel 1 exit /b 1

echo ======================================== embedding (1) ...
%compile% embedded1.c
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== embedding (2) ...
%compile% -e embedded2.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== embedding (3) ...
%compile% -e embedded3.c embedded4.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== linking tests ...
%compile_r% -unit reverser reverser\tags\1.0\reverser.scm -J -c -o reverser.obj
%compile_r% -link reverser linking-tests.scm -o a.out
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
%compile_r% -link reverser linking-tests.scm -o a.out -static
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
move reverser.obj %CHICKEN_INSTALL_REPOSITORY%
move reverser.import.scm %CHICKEN_INSTALL_REPOSITORY%
%compile_r% -link reverser linking-tests.scm -o a.out
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1
%compile_r% -link reverser linking-tests.scm -o a.out -static
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

echo ======================================== private repository test ...
del /f /s /q tmp
mkdir tmp
%compile% private-repository-test.scm -private-repository -o tmp\xxx
if errorlevel 1 exit /b 1
tmp\xxx %CD%\tmp
set PATH=%CD%\tmp;%PATH% xxx %CD%\tmp
rem this may crash, if the PATH contains a non-matching libchicken.dll on Windows:
set PATH=%PATH%;%CD%\tmp xxx %CD%\tmp

echo ======================================== multiple return values tests ...
%interpret% -s multiple-values.scm
if errorlevel 1 exit /b 1
%compile% multiple-values.scm
if errorlevel 1 exit /b 1
a.out
if errorlevel 1 exit /b 1

rem echo ======================================== reinstall tests
rem currently disabled for windows

echo ======================================== done. All tests passed.
