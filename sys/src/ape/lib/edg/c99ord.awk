#
# c99ord.awk -- keep the USABLE three families of EDG's `_Complex'
# helper runtime and drop the four kencc cannot parse.
#
#	awk -f c99ord.awk ../../../external/edg/lib_src/c99_complex.c >c99ord.c
#
# ---- WHY THIS EXISTS -------------------------------------------------
#
# `lib_src/c99_complex.c' is the one file of 51 that `mk install'
# cannot compile, and **it is not a C99 gap**: `cc/lex.c''s `itab'
# carries `_Complex' and `_Imaginary' and `lib/ap/complex' is musl's,
# 69 files.  What the file also needs is gcc's EXTENDED floats --
# `_Float16', `__bf16', `__float80', `__float128' -- which are
# TS 18661-3 and GNU rather than C99.
#
# The file is SEVEN FAMILIES of sixteen operations, and only four are
# out of reach:
#
#	float   double   long_double       <- kencc supports all three
#	float16 bfloat16 float80 float128  <- kencc has none of them
#
# so dropping the whole file drops three usable families with the four
# unusable ones, and a C++ translation unit using `_Complex double'
# link-fails on `__c99_complex_double_multiply'.
#
# ---- WHY NOT TEACH kencc THE FOUR TYPES INSTEAD ----------------------
#
# Because that is a compiler AND a runtime project, measured rather
# than feared:
#
#   * `specbits-model.py' says 7 spare type bits, so the four
#     SPECIFIERS would fit -- that is the only part that is cheap.
#   * `NTYPE' is 21 and `cc/cc.h' has SEVEN NTYPE-indexed tables;
#     `ewidth[]' appears in 27 files across the ten backends.  *One*
#     missing `typesuvinit[]' entry cost this tree an eleven-round
#     hunt and broke 386 cross-compilation silently.
#   * **There is no hardware for any of them here.**  `cc/sub.c:266'
#     maps `BDOUBLE|BLONG' to `types[TDOUBLE]`, so `long double' IS
#     `double' and the tree has no 80-bit extended at all; `__float80'
#     is x87 where Plan 9 amd64 is SSE2, and `_Float16'/`__float128'
#     have no amd64 instructions without AVX512-FP16.  All four would
#     need libgcc's soft-fp in libap -- thousands of lines whose
#     rounding is **untestable here**, since the fenv API is a stub on
#     every architecture (`fesetround()' does nothing).
#
# *That is months of compiler and runtime work whose payoff is a
# `_Complex' runtime for types nothing in this tree uses.*  The split
# below is the same payoff for an afternoon, and it is the three
# families anyone would actually reach for.
#
# ---- HOW, AND WHY awk ------------------------------------------------
#
# **A LINE filter does not work and that was tried first**: dropping
# every line naming an extended type keeps exactly the right 48
# function names and then does not compile, because the file is not
# one-definition-per-line throughout and the filter cuts multi-line
# constructs in half.  The split has to be STRUCTURAL -- whole
# top-level constructs, found by brace depth.
#
# **awk and not python because there is no python on the VM**, and
# this has to run during a Plan 9 build.  It was written against a
# python reference and the two outputs are **byte-identical**, which
# is what says the awk brace counting is right rather than merely
# plausible.
#
# ---- WHAT IT PRODUCES, MEASURED ON THE HOST --------------------------
#
#	273 top-level constructs, 96 kept, 177 dropped
#	gcc -std=c89 -c: clean
#	42 symbols: float, double and long_double each with all eight of
#	add conj divide eq multiply ne negate subtract, plus the 18
#	conversions among those three types
#	nothing undefined but `__stack_chk_fail', which is gcc's own
#	stack protector and does not exist under kencc
#
# ---- WHY IT IS NOT IN `OFILES' YET -----------------------------------
#
# **pcc is not gcc, and one failing member aborts the whole tree's
# `mk'** -- which is the exact hazard the comment above `OFILES' cites
# for leaving `c99_complex.$O' in.  A port that has only been built by
# one compiler has not been measured in that position.  The one
# command that settles it:
#
#	cd sys/src/ape/lib/edg
#	awk -f c99ord.awk ../../../external/edg/lib_src/c99_complex.c >/tmp/c99ord.c
#	pcc -c /tmp/c99ord.c
#
# Clean, and the rule and the `OFILES' entry go in together.
#
# Keep only the ordinary float/double/long_double families of EDG's
# `_Complex' helper runtime, dropping every top-level construct that
# names one of gcc's extended float types.  Plan 9 awk; no python on
# the VM.  A construct ends where brace depth returns to 0 on a line
# ending in `;' or `}'.
BEGIN { depth = 0; buf = ""; kept = 0; dropped = 0 }
{
	buf = buf $0 "\n"
	n = gsub(/\{/, "{"); depth += n
	n = gsub(/\}/, "}"); depth -= n
	if (depth == 0 && ($0 ~ /;[ \t]*$/ || $0 ~ /\}[ \t]*$/)) {
		if (buf ~ /_Float16|__bf16|__float80|__float128|float16|float80|float128|bfloat16/)
			dropped++
		else { printf "%s", buf; kept++ }
		buf = ""
	}
}
END {
	if (buf != "") printf "%s", buf
	printf "c99ord: kept %d dropped %d\n", kept, dropped | "cat 1>&2"
}
