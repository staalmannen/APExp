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

function eq($what, $got, $want) {
	global $fails;
	$g = var_export($got, true);
	$w = var_export($want, true);
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

printf("\nphp-smoke: %d failures\n", $fails);
exit($fails);
