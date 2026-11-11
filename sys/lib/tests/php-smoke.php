<?php
/*
 * php-smoke.php -- does the interpreter EVALUATE anything correctly?
 *
 *	php sys/lib/tests/php-smoke.php ; echo $status
 *
 * ***THIS TEST EXISTS BECAUSE THE PORT RAN `php -v' AND NOTHING
 * ELSE.***  The binary printed its version and exited 0, which was
 * read as "php works" -- and the first real program run on it, the
 * Phoronix Test Suite, died inside a six-line string-padding loop
 * with
 *
 *	Hard memory limit of 2147483648 bytes exhausted
 *	(tried to allocate 4294971392 bytes)
 *
 * **4294971392 is 2**32 + 4096**, which is not a quantity any program
 * asks for; it is a 64-bit value whose low half is sane and whose
 * high half holds a 1.  The allocation came from
 * `str_repeat(' ', $m)` in `pts_user_io::display_text_table`, where
 *
 *	$m = max($min, 1 + $extra + $widths[$c]) - strlen($cell);
 *
 * -- so the fault is in `strlen' or in integer arithmetic, and the
 * allocator was the victim rather than the culprit.  *A version
 * string is printed by `printf' before the engine evaluates a single
 * opcode*, so it cannot distinguish an interpreter that works from
 * one that computes nothing right.
 *
 * ***RUN IT ON THE BUILD HOST FIRST.***  Unlike every C test here,
 * this one has a real reference implementation to hand -- the host's
 * own php -- and a case that fails there is this file's bug and not
 * the port's.  Nothing below uses a feature newer than PHP 8.0, so
 * the host's 8.3 and the port's 8.5 must both answer 0.
 *
 * ***SECTION 1 IS THE ONE TO READ FIRST AND IS NOT DECORATION.***
 * `zend_long' is chosen by `Zend/zend_long.h' from `__x86_64__',
 * which this port defines, so PHP's integer is 64 bits -- while
 * kencc's `long' is 32 and `php_config.h' says `SIZEOF_LONG 4'.
 * Those two facts are both correct and they disagree with each
 * other, which is exactly the shape that produces a high half full
 * of junk.
 *
 * ***ON THIS PORT THE EXIT STATUS IS NOT USABLE YET, SO READ THE
 * COUNT LINE.***  `exit()' itself asks the allocator for 2**32 bytes
 * (see `docs/notes/php.md'), so the process dies with 137 after
 * printing its total.  The last line of output is the result until
 * that is fixed; the status will mean what it says again afterwards.
 *
 * Exit status is the failure count.
 */

$fails = 0;

/*
 * Long values are ELIDED IN THE MIDDLE, not truncated at the end.
 * Section 8 round-trips a few thousand bytes through libbz2 and
 * libz, and printing those in full buries every other line in the
 * section -- but *a value cut at the front only is the one that
 * hides a difference in the tail*, which is exactly where a
 * compression round trip goes wrong.  Both ends are kept.
 */
function brief($v) {
	$s = var_export($v, true);
	if (strlen($s) <= 72) return $s;
	return substr($s, 0, 36) . " ...[" . strlen($s) . " chars]... "
		. substr($s, -24);
}

function eq($what, $got, $want) {
	global $fails;
	$g = brief($got);
	$w = brief($want);
	if ($got === $want) {
		printf("  PASS %-44s %s\n", $what, $g);
	} else {
		printf("  FAIL %-44s got %s want %s\n", $what, $g, $w);
		$fails++;
	}
}

echo "php-smoke: does the interpreter evaluate correctly?\n\n";

/* ---------------------------------------------------------------- */
echo "Section 0: it runs at all\n";
eq("a literal survives", "hello", "hello");
eq("concatenation", "a" . "b" . "c", "abc");

/* ---------------------------------------------------------------- */
echo "\nSection 1: the integer width, which is the suspect\n";
/*
 * If PHP_INT_SIZE is 8 and PHP_INT_MAX is right, `zend_long' is a
 * clean 64 bits and the high half is not junk.  If either is wrong,
 * stop reading here -- everything below is downstream of it.
 */
eq("PHP_INT_SIZE", PHP_INT_SIZE, 8);
eq("PHP_INT_MAX", PHP_INT_MAX, 9223372036854775807);
/*
 * ***THE FIRST VERSION OF THIS CASE PUT ITS FINDING IN THE `want'
 * COLUMN, WHICH IS BACKWARDS.***  It was
 *
 *	eq("PHP_INT_MIN", PHP_INT_MIN, -9223372036854775807 - 1);
 *
 * and on Plan 9 it printed
 *
 *	got -9223372036854775807-1  want -9.223372036854776E+18
 *
 * -- the `got' side is correct and the EXPECTED side is the bug: the
 * subtraction overflowed into a float.  *An assertion whose expected
 * value is computed by the thing under test reports the fault as a
 * wrong expectation*, which is the same shape as the xcheck that read
 * both sides out of the field it was testing.  Asked directly now.
 */
eq("PHP_INT_MIN + PHP_INT_MAX is -1", PHP_INT_MIN + PHP_INT_MAX, -1);
eq("PHP_INT_MIN is an int", is_int(PHP_INT_MIN), true);
eq("LONG_MIN by subtraction stays an int",
   is_int(-9223372036854775807 - 1), true);
eq("...and equals PHP_INT_MIN", (-9223372036854775807 - 1) === PHP_INT_MIN, true);
eq("a literal above 2**32", 4294967296 + 4096, 4294971392);
eq("1 << 32", 1 << 32, 4294967296);
eq("a 2**32 round trip through a variable", (function () { $x = 4294967296; return $x; })(), 4294967296);
eq("int overflow becomes float", is_float(PHP_INT_MAX + 1), true);
eq("PHP_INT_SIZE matches pack()", strlen(pack('J', 1)), 8);

/* ---------------------------------------------------------------- */
echo "\nSection 2: strlen, which is half of the failing expression\n";
eq("strlen of a literal", strlen("MISSING"), 7);
eq("strlen of the empty string", strlen(""), 0);
eq("strlen of a built string", strlen("a" . "bc" . "def"), 6);
eq("strlen of a repeated string", strlen(str_repeat("ab", 10)), 20);
eq("strlen is an int, not a float", is_int(strlen("abc")), true);
eq("strlen of 1000 chars", strlen(str_repeat("x", 1000)), 1000);

/* ---------------------------------------------------------------- */
echo "\nSection 3: integer arithmetic in the shape that failed\n";
/*
 * `max($min, 1 + $extra + $width) - strlen($cell)' -- the exact
 * expression from `display_text_table', with the values the
 * extension table would have given it.  A port that gets every case
 * above right and this one wrong has a bug in `max' or in mixed
 * subtraction, which is worth separating.
 */
eq("max of two ints", max(0, 7), 7);
eq("max picks the larger", max(9, 3), 9);
eq("max over an array", max([3, 11, 7]), 11);
eq("subtraction of two strlens", strlen("REQUIRED") - strlen("DOM"), 5);
$widths = [7, 8];
$cells  = ["MISSING", "DOM"];
eq("the padding expression, column 0",
   max(0, 1 + 0 + $widths[0]) - strlen($cells[0]), 1);
eq("the padding expression, column 1",
   max(0, 1 + 0 + $widths[1]) - strlen($cells[1]), 6);
eq("a padding count is never near 2**32",
   (max(0, 1 + 0 + $widths[1]) - strlen($cells[1])) < 1024, true);

/* ---------------------------------------------------------------- */
echo "\nSection 3b: MULTIPLICATION, which the first version never asked\n";
/*
 * ***THE FIRST VERSION OF THIS FILE TESTED +, -, max, strlen AND
 * str_repeat, AND NOT `*'.***  It still found the bug, but only
 * through the back door: PHP compiles unary minus as `(-1) * x', so
 * `-9223372036854775807' was a float and the two PHP_INT_MIN cases
 * failed while nothing said the word "multiply".
 *
 * `zend_multiply.h:135' declared the product `long`, which is 64 bits
 * on every LP64 platform and **32 on kencc**, so the product was
 * truncated, the overflow check fired on a product that had not
 * overflowed, and the answer came back a DOUBLE. **Every integer
 * multiplication whose result did not fit in 32 bits was a float.**
 * That is a silent wrong answer in the commonest arithmetic there is,
 * and a test with five operators and not the sixth could only ever
 * have caught it sideways.
 */
eq("small product is an int", 6 * 7, 42);
eq("product just under 2**31", 46340 * 46340, 2147395600);
eq("PRODUCT OVER 2**32 STAYS AN INT", is_int(2000000 * 2000000), true);
eq("...and is right", 2000000 * 2000000, 4000000000000);
eq("a product near PHP_INT_MAX stays an int",
   is_int(1000000007 * 1000000009), true);
eq("...and is right", 1000000007 * 1000000009, 1000000016000000063);
eq("a negative product over 2**32 stays an int",
   is_int(-2000000 * 2000000), true);
eq("...and is right", -2000000 * 2000000, -4000000000000);
eq("unary minus on a big literal stays an int",
   is_int(-9223372036854775807), true);
/*
 * And the check must still FIRE when there is a real overflow -- a
 * fix that simply never reports one would pass everything above.
 */
eq("a REAL overflow still becomes a float",
   is_float(PHP_INT_MAX * 2), true);
eq("...and so does a real negative overflow",
   is_float(PHP_INT_MIN * 2), true);

/* ---------------------------------------------------------------- */
echo "\nSection 4: str_repeat, which is where it died\n";
eq("str_repeat small", str_repeat("-", 5), "-----");
eq("str_repeat zero", str_repeat("-", 0), "");
eq("str_repeat length", strlen(str_repeat(" ", 64)), 64);
eq("str_repeat of a 2-char string", str_repeat("ab", 3), "ababab");
eq("str_repeat 100k does not explode", strlen(str_repeat("x", 100000)), 100000);

/* ---------------------------------------------------------------- */
echo "\nSection 5: the whole failing loop, reduced\n";
/*
 * `display_text_table' over the very table php printed before it
 * died.  If sections 2 to 4 pass and this fails, the fault is in the
 * ARRAY handling rather than in the arithmetic.
 */
$table = [
	["MISSING DOM", "REQUIRED", "The Document Object Model."],
	["MISSING ZIP", "REQUIRED", "ZIP support."],
];
$colw = [];
for ($r = 0; $r < count($table); $r++) {
	for ($c = 0; $c < count($table[$r]); $c++) {
		if (!isset($colw[$c]) || strlen($table[$r][$c]) > $colw[$c]) {
			$colw[$c] = strlen($table[$r][$c]);
		}
	}
}
eq("column widths", $colw, [11, 8, 26]);
$out = '';
$maxpad = 0;
for ($r = 0; $r < count($table); $r++) {
	for ($c = 0; $c < count($table[$r]); $c++) {
		$out .= $table[$r][$c];
		$m = max(0, 1 + 0 + $colw[$c]) - strlen($table[$r][$c]);
		if ($m > $maxpad) $maxpad = $m;
		if ($m > 0) $out .= str_repeat(' ', $m);
	}
	$out .= "\n";
}
eq("the largest padding the loop asked for", $maxpad, 15);
eq("the table rendered to a sane length", strlen($out) < 200, true);

/* ---------------------------------------------------------------- */
echo "\nSection 6: the rest of the language, briefly\n";
eq("array count", count([1, 2, 3]), 3);
eq("sort", (function () { $a = [3, 1, 2]; sort($a); return $a; })(), [1, 2, 3]);
eq("foreach sums", (function () { $s = 0; foreach ([1, 2, 3] as $v) $s += $v; return $s; })(), 6);
eq("sprintf %d", sprintf("%d", 42), "42");
eq("sprintf %s width", sprintf("[%-6s]", "ab"), "[ab    ]");
eq("sprintf a wide int", sprintf("%d", 4294971392), "4294971392");
eq("substr", substr("abcdef", 2, 3), "cde");
eq("string offset", "abcdef"[2], "c");
eq("float arithmetic", 0.1 + 0.2 > 0.29999 && 0.1 + 0.2 < 0.30001, true);
eq("intdiv", intdiv(7, 2), 3);
eq("string to int", (int)"123", 123);
eq("associative array", (function () { $a = []; $a['k'] = 'v'; return $a['k']; })(), "v");
eq("preg_match (pcre2 is linked in)", preg_match('/^M(I)SSING$/', "MISSING", $m), 1);
eq("preg capture", $m[1], "I");
eq("json_encode", json_encode(['a' => 1]), '{"a":1}');
eq("json_decode round trip", json_decode('{"a":1}', true), ['a' => 1]);

/* ---------------------------------------------------------------- */
echo "\nSection 7: the platform's own files, which are the point of the port\n";
/*
 * Not a language rule, so these are reported and only the TYPE is
 * asserted: a Plan 9 machine has /net and a Linux build host does
 * not, and the test must pass on both.
 */
$net = @file_get_contents('/net/tcp/stats');
if ($net === false) {
	echo "  INFO /net/tcp/stats unreadable (expected off Plan 9)\n";
} else {
	echo "  INFO /net/tcp/stats: " . strlen($net) . " bytes\n";
	eq("a synthetic file's length is sane", strlen($net) < 65536, true);
}
eq("getcwd returns a string", is_string(getcwd()), true);
eq("PHP_OS is a string", is_string(PHP_OS), true);
echo "  INFO PHP_OS = " . PHP_OS . ", PHP_VERSION = " . PHP_VERSION . "\n";

/* ---------------------------------------------------------------- */
echo "\nSection 8: the twelve extensions, and each one DOING something\n";
/*
 * ***LOADED IS NOT WORKING, AND THAT IS THE WHOLE POINT OF THIS
 * SECTION.***  `extension_loaded()' asks whether a module entry was
 * registered, which is a fact about `internal_functions_cli.c' and
 * not about the library underneath it.  Every one of these
 * extensions was first seen "compiling clean" while its body was
 * `#ifdef'd out to nothing -- so a check that only counts modules
 * would have passed on that build too.
 *
 * So each line below calls through to the LIBRARY: bz2 round-trips
 * bytes through libbz2, zip and sqlite3 and curl and openssl each
 * ask their own library its version or do one real operation.
 */
$want = ['core', 'date', 'pcre', 'hash', 'json', 'random', 'Reflection',
	 'SPL', 'standard', 'libxml', 'dom', 'SimpleXML', 'zlib',
	 'posix', 'pcntl', 'bz2', 'readline', 'openssl', 'curl',
	 'sqlite3', 'zip', 'gd'];
$missing = [];
foreach ($want as $e) {
	if (!extension_loaded($e)) $missing[] = $e;
}
echo "  INFO loaded: " . implode(', ', get_loaded_extensions()) . "\n";
/*
 * ***ASSERTED ON Plan9 ONLY, and this is Section 7's rule rather than
 * a softening.***  The list above is a statement about THIS PORT's
 * `internal_functions_cli.c', so a build host that happens not to
 * ship `ext/readline' would fail it while being perfectly correct --
 * and *a test that fails on the reference cannot tell you whether the
 * test or the tree is wrong*, which is the whole reason this file is
 * run against host php first.
 *
 * `PHP_OS' is `"Plan9"' here, from `php_config.h:594'.  **Section 7
 * prints PHP_OS**, so a build whose PHP_OS changed shows up as this
 * check silently not running rather than as a mystery pass -- which
 * is the failure mode to watch for, not the one being accepted.
 */
if (PHP_OS === 'Plan9') {
	eq("every expected extension is registered", $missing, []);
} elseif ($missing) {
	echo "  INFO not on Plan9; absent here: " . implode(', ', $missing) . "\n";
}

/* bz2 -- a real round trip through libbz2, not a version string. */
if (extension_loaded('bz2')) {
	$plain = str_repeat("APExp bzip2 round trip. ", 200);
	$packed = bzcompress($plain, 9);
	eq("bzcompress returns a string", is_string($packed), true);
	eq("bzcompress actually compresses", strlen($packed) < strlen($plain), true);
	eq("bzdecompress round trip", bzdecompress($packed), $plain);
}

/* zlib -- the same question, since ext/zlib is what answers "MISSING ZIP". */
if (extension_loaded('zlib')) {
	$plain = str_repeat("APExp zlib round trip. ", 200);
	eq("gzdeflate/gzinflate round trip", gzinflate(gzdeflate($plain, 9)), $plain);
}

/* dom + libxml -- parse and read a value back out. */
if (extension_loaded('dom')) {
	$d = new DOMDocument();
	$d->loadXML('<r><a id="x">hello</a></r>');
	eq("DOM parses and reads text", $d->getElementsByTagName('a')->item(0)->textContent, "hello");
	eq("DOM reads an attribute", $d->getElementsByTagName('a')->item(0)->getAttribute('id'), "x");
}
if (extension_loaded('SimpleXML')) {
	$x = simplexml_load_string('<r><a>7</a></r>');
	eq("SimpleXML reads an element", (string)$x->a, "7");
}

/* sqlite3 -- create, insert, select, in memory, so no file is left. */
if (extension_loaded('sqlite3')) {
	echo "  INFO SQLite3 library version: " . SQLite3::version()['versionString'] . "\n";
	$db = new SQLite3(':memory:');
	$db->exec('CREATE TABLE t (a INTEGER, b TEXT)');
	$db->exec("INSERT INTO t VALUES (42, 'forty-two')");
	$row = $db->querySingle('SELECT b FROM t WHERE a = 42');
	eq("sqlite3 round trip", $row, "forty-two");
	$db->close();
}

/* openssl -- a digest and a random, both computed by libressl. */
if (extension_loaded('openssl')) {
	echo "  INFO OpenSSL: " . OPENSSL_VERSION_TEXT . "\n";
	eq("openssl_digest sha256 of the empty string",
	   openssl_digest("", "sha256"),
	   "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");
	eq("openssl_random_pseudo_bytes length",
	   strlen(openssl_random_pseudo_bytes(16)), 16);
	eq("a cipher list is non-empty", count(openssl_get_cipher_methods()) > 0, true);
}

/* curl -- built, and able to report its own library's version. */
if (extension_loaded('curl')) {
	$v = curl_version();
	echo "  INFO libcurl " . $v['version'] . ", ssl " . ($v['ssl_version'] ?? 'none') . "\n";
	eq("curl_init returns a handle", curl_init() !== false, true);
}

/* zip -- write an archive to a temp file, read it back, delete it. */
if (extension_loaded('zip')) {
	echo "  INFO libzip " . (function_exists('zip_libzip_version') ? zip_libzip_version() : ZipArchive::LIBZIP_VERSION) . "\n";
	/*
	 * ***tempnam() IS CHECKED BEFORE IT IS USED, AND THE REASON IS
	 * THAT IT RETURNED false ON THE VM.***  `ZipArchive::open(false)'
	 * is `open('')', which in php 8 is a `ValueError' -- an
	 * UNCAUGHT one, so it killed the interpreter and **every section
	 * after this one went unmeasured**.  That is this tree's own rule
	 * about a case that can kill the process arriving in a php
	 * script: it belongs behind a guard, and what is on the far side
	 * of the guard has to keep running.
	 *
	 * *And a missing tempnam is not a zip bug*, so the zip checks are
	 * SKIPPED rather than failed -- a count that blames the wrong
	 * layer is worse than a count with a hole in it.
	 *
	 * **The INFO lines are a probe and ask the question in order**:
	 * php's `php_do_open_temporary_file' resolves the directory with
	 * `CWD_REALPATH' and then calls `mkstemp' (php's `config.h' here
	 * answers `HAVE_MKSTEMP 1'), so a failure is in one of three
	 * places and these separate them in one run with no rebuild:
	 *   - `sys_get_temp_dir()' wrong -- note APE defines no
	 *     `P_tmpdir', so php falls through to its own "/tmp"
	 *     last-ditch default, which is right here but is a FALLBACK
	 *     and worth seeing;
	 *   - `realpath()' of it failing, i.e. the CWD_REALPATH step;
	 *   - plain `fopen()' in it working while `tempnam' does not,
	 *     which puts it on `mkstemp' and nothing else.
	 * `tmpfile()' is the fourth line because it takes the same path
	 * without returning a NAME, so it says whether the name or the
	 * file is the problem.
	 */
	$td = sys_get_temp_dir();
	$tmp = tempnam($td, 'apexpzip');
	if ($tmp === false || $tmp === '') {
		echo "  INFO tempnam() failed; the zip checks are SKIPPED, not failed\n";
		echo "  INFO sys_get_temp_dir() = " . var_export($td, true) . "\n";
		echo "  INFO realpath(td)       = " . var_export(@realpath($td), true) . "\n";
		echo "  INFO is_dir/is_writable = " . var_export(@is_dir($td), true)
		    . "/" . var_export(@is_writable($td), true) . "\n";
		$fh = @fopen($td . '/apexpzip-probe', 'w');
		echo "  INFO fopen in td        = " . var_export($fh !== false, true) . "\n";
		if ($fh !== false) { fclose($fh); @unlink($td . '/apexpzip-probe'); }
		echo "  INFO tmpfile()          = " . var_export(@tmpfile() !== false, true) . "\n";
	} else {
		$z = new ZipArchive();
		eq("ZipArchive::open for writing", $z->open($tmp, ZipArchive::OVERWRITE) === true, true);
		$z->addFromString('hello.txt', 'zip round trip');
		$z->close();
		$z2 = new ZipArchive();
		eq("ZipArchive::open for reading", $z2->open($tmp) === true, true);
		eq("zip round trip", $z2->getFromName('hello.txt'), "zip round trip");
		$z2->close();
		@unlink($tmp);
	}
}

/* posix -- ids that must agree with the ones standard php reports. */
if (extension_loaded('posix')) {
	eq("posix_getpid agrees with getmypid", posix_getpid(), getmypid());
	eq("posix_getuid returns an int", is_int(posix_getuid()), true);
	$u = posix_getpwuid(posix_getuid());
	eq("posix_getpwuid returns a name", is_array($u) && isset($u['name']), true);
	if (is_array($u)) echo "  INFO posix user: " . $u['name'] . "\n";
	eq("posix_uname returns a sysname", is_array(posix_uname()), true);
}

/* pcntl -- the parts that need no fork, so the test cannot hang. */
if (extension_loaded('pcntl')) {
	/*
	 * ***NO fork() HERE, DELIBERATELY.***  A forked child that does
	 * not exit turns this file into the one test in the tree that
	 * can hang, and the convention is that such a case gets its own
	 * file and its own SIGALRM.  What is asked here is only that
	 * the extension registered and its signal table is readable.
	 */
	eq("pcntl_signal_dispatch runs", (function () { pcntl_signal_dispatch(); return true; })(), true);
	eq("pcntl_strerror is a string", is_string(pcntl_strerror(1)), true);
}

/* readline -- registered, and its library version readable. */
if (extension_loaded('readline')) {
	$i = readline_info();
	eq("readline_info returns an array", is_array($i), true);
	if (is_array($i) && isset($i['library_version']))
		echo "  INFO readline " . $i['library_version'] . "\n";
}

/* gd -- against the EXTERNAL libgd, so this also proves lib/gd links. */
if (extension_loaded('gd')) {
	$i = gd_info();
	echo "  INFO GD Version: " . ($i['GD Version'] ?? '?') . "\n";
	/*
	 * ***THE CAPABILITY FLAGS ARE THE POINT OF THIS BLOCK, NOT THE
	 * DRAWING.***  libgd compiles stub entry points for JPEG, WebP,
	 * AVIF and XPM even with no such library -- they LINK and then
	 * call `gd_error("... has been disabled")' -- so a configure
	 * probe answers yes and `imagetypes()' would lie.  APExp answers
	 * those `HAVE_GD_*' no by hand, and these two lines are what
	 * says the hand answer reached PHP.
	 */
	eq("PNG support is reported", (bool)(imagetypes() & IMG_PNG), true);
	/*
	 * Asserted on Plan9 ONLY, by Section 7's rule: "JPEG is absent"
	 * is a statement about THIS PORT's libgd, not about php or gd,
	 * and a build host with a full libgd fails it while being
	 * perfectly correct. It did -- which is the control working.
	 */
	if (PHP_OS === 'Plan9') {
		eq("JPEG is NOT reported (libgd has only a stub)",
		   (bool)(imagetypes() & IMG_JPG), false);
		eq("imagejpeg() is absent rather than failing later",
		   function_exists('imagejpeg'), false);
	} else {
		printf("  INFO not on Plan9; this host reports JPEG=%s\n",
		    (imagetypes() & IMG_JPG) ? 'yes' : 'no');
	}

	/* A real round trip: draw, encode to PNG, decode, read a pixel. */
	$im = imagecreatetruecolor(40, 30);
	eq("imagecreatetruecolor", $im !== false, true);
	if ($im !== false) {
		$col = imagecolorallocate($im, 0x20, 0x90, 0xd0);
		imagefilledrectangle($im, 0, 0, 39, 29, $col);
		eq("pixel reads back", imagecolorat($im, 10, 10) & 0xffffff, 0x2090d0);
		ob_start();
		$wrote = imagepng($im);
		$png = ob_get_clean();
		eq("imagepng wrote something", $wrote && strlen($png) > 50, true);
		eq("PNG signature", substr($png, 0, 8), "\x89PNG\r\n\x1a\n");
		$im2 = imagecreatefromstring($png);
		eq("decoded the PNG back", $im2 !== false, true);
		if ($im2 !== false) {
			eq("round-tripped width", imagesx($im2), 40);
			eq("round-tripped pixel",
			   imagecolorat($im2, 10, 10) & 0xffffff, 0x2090d0);
			imagedestroy($im2);
		}
		imagedestroy($im);
	}
}

printf("\nphp-smoke: %d failures\n", $fails);
exit($fails);
