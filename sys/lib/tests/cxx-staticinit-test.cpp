/*
 * cxx-staticinit-test.cpp -- do C++ static constructors run?
 *
 *	eccp -o cxx-staticinit-test cxx-staticinit-test.cpp
 *	./cxx-staticinit-test
 *
 * and the gcc reference arm, which must be 0:
 *
 *	g++ -std=c++14 -o /tmp/siref cxx-staticinit-test.cpp
 *
 * ---- WHAT IT CAME FROM --------------------------------------------
 *
 * `unrar x sample-3.rar' on a downloaded archive answered
 *
 *	Main archive header is corrupt
 *	<name> - the file header is corrupt
 *	Extracting <name>                               100%
 *	<name> - checksum error
 *	Total errors: 7
 *
 * and the obvious reading is a bad download.  **The PATTERN says
 * otherwise, and the pattern is free to read.**  Every structural
 * field parsed: unrar found the archive, found the member, knew its
 * name and its size, and ran the extraction to 100%.  *A corrupted
 * file does not parse cleanly and fail every CRC; it fails to parse.*
 * Everything that is a LENGTH worked and everything that is a
 * CHECKSUM failed, which is one mechanism and not seven.
 *
 * `crc.cpp:75' is that mechanism, and it is six words long:
 *
 *	struct CallInitCRC {CallInitCRC() {InitTables();}} static CallInit32;
 *
 * -- a namespace-scope object with a non-trivial constructor, which
 * is the only thing that ever fills `crc_tables'.  With the
 * constructor unrun the tables are all zeros, so **every CRC32 in the
 * program is wrong and no two of them disagree about how**.
 *
 * ---- WHY IT CANNOT RUN, READ RATHER THAN GUESSED -------------------
 *
 * EDG's model is the classic `munch': cpfe emits one
 * `__sti__<translation-unit>' function per TU with dynamic
 * initialisation, `lib_src/munch_ctors.c' declares
 * `PFV _ctors[1] = {0}' as a PLACEHOLDER, and a munch pass is meant
 * to scan the objects and regenerate that array.  `_Z12__call_ctorsv'
 * then walks it, and `lib_src/main.c''s `_main' calls that.
 *
 * **Three things are missing and any one of them is sufficient**:
 *
 *   1. There is no munch pass, so `_ctors' stays `{0}'.
 *   2. Nothing calls `_Z12__call_ctorsv'.  `_main' would, and this
 *      tree RENAMES it to `__edg_main' because `_main' is `6l''s
 *      default entry point (`6l/obj.c:305') -- see
 *      `lib/edg/mkfile'.  APE's own startup is
 *      `main9.s' -> `_callmain' -> `_apemain' -> `main' and calls
 *      nothing of EDG's.
 *   3. There is no cpfe option to emit the call at the top of `main'
 *      instead: `call_ctors', `init_before_main' and the like occur
 *      nowhere in the 2.9M-line corpus, and the only `targ_*init*'
 *      setting is `ia64_abi_use_int_static_init_guard', which is
 *      about guard VARIABLES.
 *
 * **And cpfe's own build has the same gap**, which is the
 * corroboration rather than a side note:
 * `__sti___9_fe_init_c_2cbd8fba' is defined in `src/fe_init.c' and
 * referenced by nothing in `src/', `lib_src/' or `util/'.  *cpfe
 * works anyway*, which is why this went unnoticed for the whole port
 * -- **the first program to NEED a static constructor is the first
 * one to show it.**  `lib/edg/mkfile' has carried it as "recorded,
 * not fixed" since the entry point was renamed.
 *
 * ---- HOW TO READ THE SECTIONS -------------------------------------
 *
 * Section 0 and section 3 are CONTROLS and must pass whatever the
 * verdict, or the test says nothing:
 *
 *   0  a constant-initialised global.  That is STATIC
 *      initialisation, done by the loader out of the data segment,
 *      with no code to run -- so a failure here is not this bug but
 *      something far worse.
 *   1  a namespace-scope object with a constructor: the bug.
 *   2  unrar's exact shape -- an unnamed struct type whose ctor
 *      fills a TABLE -- because `a flag was not set' and `a table
 *      was not filled' could in principle differ, and this is the
 *      one that matches the symptom.
 *   3  a FUNCTION-LOCAL static with a constructor.  C++ initialises
 *      that on first use, through a guard, with no munch involved,
 *      **so it must pass even with the gap wide open** -- and it is
 *      what separates "dynamic initialisation is broken" from "all
 *      statics are broken".
 *   4  CRC32 of "123456789" computed through a table built by a
 *      static constructor, which must be 0xCBF43926 -- the standard
 *      vector, so the number is checkable against any reference
 *      without trusting this file.  *This is the symptom itself,
 *      reproduced in forty lines rather than in 49 translation
 *      units.*
 *
 * A run where 0 and 3 pass and 1, 2 and 4 fail is the diagnosis
 * exactly.  A run where 3 fails too is a different and bigger bug.
 */

#include <stdio.h>

static int fails = 0;

static void chk(char const *tag, bool ok) {
  printf("%s: %s\n", ok ? "PASS" : "FAIL", tag);
  if (!ok)
    fails++;
}

/* ---- section 0: static initialisation, the control --------------- */
static int const const_global = 0x5A5A;

/* ---- section 1: a plain dynamic initialiser ---------------------- */
static int ctor_ran = 0;

struct SetFlag {
  SetFlag() { ctor_ran = 1; }
};
static SetFlag set_flag_obj;

/* ---- section 2: unrar's exact shape ------------------------------ */
static unsigned table[256];

static void fill_table(void) {
  for (unsigned i = 0; i < 256; i++) {
    unsigned c = i;
    for (unsigned j = 0; j < 8; j++)
      c = (c & 1) ? (c >> 1) ^ 0xEDB88320u : (c >> 1);
    table[i] = c;
  }
}

/* crc.cpp:75, spelled the same way round */
struct CallInitTable {
  CallInitTable() { fill_table(); }
} static call_init_obj;

/* ---- section 4: the symptom ------------------------------------- */
static unsigned crc32(void const *p, unsigned n) {
  unsigned char const *b = (unsigned char const *)p;
  unsigned c = 0xFFFFFFFFu;
  for (unsigned i = 0; i < n; i++)
    c = table[(c ^ b[i]) & 0xFF] ^ (c >> 8);
  return c ^ 0xFFFFFFFFu;
}

int main(void) {
  unsigned nonzero, i, crc;

  setvbuf(stdout, 0, _IOLBF, 0);
  printf("cxx-staticinit-test: starting\n");

  printf("section 0: constant-initialised global (control)\n");
  chk("a global with a constant initialiser holds it", const_global == 0x5A5A);

  printf("section 1: namespace-scope object with a constructor\n");
  chk("the constructor ran", ctor_ran == 1);

  printf("section 2: a constructor that fills a table (unrar's shape)\n");
  nonzero = 0;
  for (i = 0; i < 256; i++)
    if (table[i] != 0)
      nonzero++;
  printf("  %u of 256 entries are non-zero\n", nonzero);
  chk("the table is filled", nonzero == 255); /* table[0] is legitimately 0 */

  printf("section 3: function-local static (control)\n");
  {
    /*
     * Initialised on FIRST USE through a guard variable, with no
     * munch and no _ctors involved -- so this must pass even when
     * every other section fails, and a failure here means something
     * other than the missing munch pass.
     */
    struct LocalCtor {
      int v;
      LocalCtor() : v(0x1234) {}
    };
    static LocalCtor local;
    chk("a function-local static is constructed", local.v == 0x1234);
  }

  printf("section 4: CRC32 of \"123456789\" through that table\n");
  crc = crc32("123456789", 9);
  printf("  got 0x%08X, want 0xCBF43926\n", crc);
  chk("CRC32 matches the standard vector", crc == 0xCBF43926u);

  printf("\ncxx-staticinit-test: %d failure%s\n", fails, fails == 1 ? "" : "s");
  if (fails && ctor_ran == 0)
    printf("cxx-staticinit-test: static constructors do not run -- see the\n"
           "cxx-staticinit-test: header, and note that EVERY CRC in unrar is\n"
           "cxx-staticinit-test: then wrong, which is not a corrupt archive.\n");
  return fails;
}
