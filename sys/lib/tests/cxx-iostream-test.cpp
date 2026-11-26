/*
 * cxx-iostream-test.cpp -- does APExp's minimal iostreams behave?
 *
 *	eccp -o cxx-iostream-test cxx-iostream-test.cpp
 *	./cxx-iostream-test
 *
 * and the two host arms, which must BOTH be 0:
 *
 *	sys/lib/tests/hostkencc/cxxlib-host.sh --iostream
 *	g++ -std=c++14 -DREFERENCE -o /tmp/ioref cxx-iostream-test.cpp
 *
 * ---- WHY THERE IS A `-DREFERENCE' ARM ------------------------------
 *
 * **Every assertion here is a STANDARD rule, so libstdc++ must pass the
 * identical file.**  That is the cheapest way to find out whether a
 * failure is the library's or the test's, and in this tree it has caught
 * both -- `cxx-wstring-test' was written this way and its reference arm
 * is what proved the six `memcpy' sites wrong rather than the test.
 *
 * *A test for a reimplementation of a standard component has an oracle
 * sitting on the build host*, which is not true of most things here, so
 * not using it would be the waste.
 *
 * ---- WHAT THIS CANNOT ASK ------------------------------------------
 *
 * The reference arm says nothing about `cout'/`cerr'/`cin', because
 * those are the one part that is NOT the standard's shape: APExp's are
 * references to function-local statics rather than objects in a library,
 * forced by `eccp''s munch pass scanning object files and never archive
 * members (`io/iostream.h' has the reasoning).  Section 9 exercises them
 * on their own terms and is skipped under `-DREFERENCE'.
 *
 * ---- SECTIONS ------------------------------------------------------
 *
 *   0  a string stream round trip -- the CONTROL.  If this fails nothing
 *      below means anything, because every other section measures
 *      through one.
 *   1  integer formatting: base, showbase, showpos, uppercase.
 *   2  width, fill and adjustment -- and that `width()' is CONSUMED by
 *      one insertion and not the next, which is the rule a per-inserter
 *      pad is most likely to lose.
 *   3  floating point: fixed, scientific, precision.
 *   4  `boolalpha' both ways.
 *   5  extraction: whitespace skipping, bases, failure leaves the value
 *      ALONE and sets failbit.
 *   6  `getline' -- the empty line, the delimiter not stored, and
 *      `gcount' counting the delimiter it consumed.
 *   7  unformatted I/O: `put', `write', `read', `peek', `unget'.
 *   8  seeking in a string stream.
 *   9  a real file, written and read back.
 *  10  `cout'/`cerr' exist and accept output (APExp arm only).
 */

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>

static int fails = 0;

static void chk(char const *tag, bool ok) {
  printf("%s: %s\n", ok ? "PASS" : "FAIL", tag);
  if (!ok) {
    fails++;
  }
}

static void chkstr(char const *tag, std::string const &got, char const *want) {
  bool const ok = (0 == strcmp(got.c_str(), want));
  if (ok) {
    printf("PASS: %s\n", tag);
  } else {
    printf("FAIL: %s -- got \"%s\", want \"%s\"\n", tag, got.c_str(), want);
    fails++;
  }
}

int main(void) {
  setvbuf(stdout, 0, _IOLBF, 0);
  printf("cxx-iostream-test: starting\n");

  /* ---- section 0: the control --------------------------------- */
  printf("section 0: a string stream round trip (control)\n");
  {
    std::ostringstream os;
    os << "hello";
    chkstr("ostringstream holds what was written", os.str(), "hello");

    std::istringstream is("world");
    std::string        w;
    is >> w;
    chkstr("istringstream gives it back", w, "world");
  }

  /* ---- section 1: integer formatting -------------------------- */
  printf("section 1: integer bases and flags\n");
  {
    std::ostringstream os;
    os << 255;
    chkstr("decimal", os.str(), "255");
  }
  {
    std::ostringstream os;
    os << std::hex << 255;
    chkstr("hex", os.str(), "ff");
  }
  {
    std::ostringstream os;
    os << std::hex << std::showbase << 255;
    chkstr("hex showbase", os.str(), "0xff");
  }
  {
    std::ostringstream os;
    os << std::hex << std::uppercase << std::showbase << 255;
    chkstr("hex uppercase showbase", os.str(), "0XFF");
  }
  {
    std::ostringstream os;
    os << std::oct << 8;
    chkstr("octal", os.str(), "10");
  }
  {
    std::ostringstream os;
    os << std::showpos << 42;
    chkstr("showpos", os.str(), "+42");
  }
  {
    std::ostringstream os;
    os << -42;
    chkstr("negative", os.str(), "-42");
  }
  {
    /* A value no 32-bit path can carry, because `long' is 32 bits on
     * this target and every integer inserter here funnels through
     * `long long'.  A truncation would be invisible at small values. */
    std::ostringstream os;
    os << 4294967296LL;
    chkstr("a value above 2**32", os.str(), "4294967296");
  }
  {
    std::ostringstream os;
    os << static_cast<unsigned long long>(18446744073709551615ULL);
    chkstr("unsigned long long max", os.str(), "18446744073709551615");
  }

  /* ---- section 2: width, fill, adjustment --------------------- */
  printf("section 2: width, fill and adjustment\n");
  {
    std::ostringstream os;
    os << std::setw(6) << 42;
    chkstr("setw right-adjusts by default", os.str(), "    42");
  }
  {
    std::ostringstream os;
    os << std::setw(6) << std::setfill('0') << 42;
    chkstr("setfill", os.str(), "000042");
  }
  {
    std::ostringstream os;
    os << std::left << std::setw(6) << 42 << '|';
    chkstr("left", os.str(), "42    |");
  }
  {
    std::ostringstream os;
    os << std::internal << std::setw(6) << std::setfill('0') << -42;
    chkstr("internal puts the sign first", os.str(), "-00042");
  }
  {
    /* ***`width()' IS CONSUMED BY ONE INSERTION.***  A padder written
     * per-inserter forgets this and pads both, which reads as "setw is
     * sticky" -- and setw being sticky is what `setfill' actually is,
     * so the two are easy to confuse. */
    std::ostringstream os;
    os << std::setw(4) << 1 << 2;
    chkstr("width applies once", os.str(), "   12");
  }
  {
    std::ostringstream os;
    os << std::setw(3) << "abcdef";
    chkstr("width shorter than the value does not truncate", os.str(), "abcdef");
  }

  /* ---- section 3: floating point ------------------------------ */
  printf("section 3: floating point\n");
  {
    std::ostringstream os;
    os << std::fixed << std::setprecision(2) << 3.14159;
    chkstr("fixed, precision 2", os.str(), "3.14");
  }
  {
    std::ostringstream os;
    os << std::fixed << std::setprecision(0) << 2.5;
    /* Banker's rounding in the C library: 2.5 -> "2".  Asserted
     * because it is what `printf("%.0f")' does and this stack is
     * specified to agree with `printf'. */
    chkstr("fixed, precision 0", os.str(), "2");
  }
  {
    std::ostringstream os;
    os << std::setprecision(6) << 100.0;
    chkstr("default float format drops trailing zeros", os.str(), "100");
  }
  {
    std::ostringstream os;
    os << std::scientific << std::setprecision(3) << 1234.5;
    chkstr("scientific", os.str(), "1.234e+03");
  }

  /* ---- section 4: boolalpha ----------------------------------- */
  printf("section 4: boolalpha\n");
  {
    std::ostringstream os;
    os << true << ' ' << false;
    chkstr("bool as 1/0", os.str(), "1 0");
  }
  {
    std::ostringstream os;
    os << std::boolalpha << true << ' ' << false;
    chkstr("bool as true/false", os.str(), "true false");
  }
  {
    std::istringstream is("true false");
    bool               a = false;
    bool               b = true;
    is >> std::boolalpha >> a >> b;
    chk("boolalpha extraction", a && !b && !is.fail());
  }

  /* ---- section 5: extraction ---------------------------------- */
  printf("section 5: extraction\n");
  {
    std::istringstream is("  12   34  ");
    int                a = 0;
    int                b = 0;
    is >> a >> b;
    chk("leading whitespace is skipped", (12 == a) && (34 == b) && !is.fail());
  }
  {
    std::istringstream is("ff");
    int                v = 0;
    is >> std::hex >> v;
    chk("hex extraction", (255 == v) && !is.fail());
  }
  {
    std::istringstream is("3.5");
    double             d = 0.0;
    is >> d;
    chk("double extraction", (d > 3.49) && (d < 3.51) && !is.fail());
  }
  {
    /* ***C++11 CHANGED THIS AND THE FIRST DRAFT ASSERTED THE C++98
     * RULE.***  The test said "a failed extraction leaves the value
     * alone", the `-DREFERENCE' arm disagreed on its very first run,
     * and libstdc++ was right: since C++11
     * [facet.num.get.virtuals] sets the value to ZERO when the
     * conversion fails.  *The test was wrong and the library then
     * had the same bug*, which is why both arms are run before
     * anything is written down.
     *
     * The two cases below are NOT the same: here the sentry succeeds
     * and the conversion fails, so the value is zeroed; in the next
     * block the sentry itself fails at end of input, no conversion is
     * attempted, and the value is untouched. */
    std::istringstream is("abc");
    int                v = 7;
    is >> v;
    chk("a failed extraction sets failbit", is.fail());
    chk("a failed conversion zeroes the value", 0 == v);
  }
  {
    std::istringstream is("5");
    int                v = 0;
    is >> v;
    chk("reading the last token succeeds", (5 == v) && !is.fail());
    int w = 9;
    is >> w;
    chk("reading past the end sets failbit", is.fail());
    chk("reading past the end sets eofbit", is.eof());
    chk("reading past the end leaves the value alone", 9 == w);
  }

  {
    /* ***AND THE SECOND DRAFT OF THIS CASE WAS ALSO WRONG, FOR THE
     * OPPOSITE REASON.***  It asserted that a failed `>>' into a
     * string EMPTIES it, because [istream.extractors] says the
     * extractor calls `str.erase()'.  libstdc++ left the old value
     * and is right: on empty input the SENTRY fails first, so
     * nothing in the extractor body runs.  *The erase is
     * unreachable for `operator>>'* -- a successful sentry has
     * already skipped whitespace and found a character, so there is
     * always at least one to extract.  What is observable is the
     * sentry's own rule, so that is what is asserted. */
    std::istringstream is("");
    std::string        str = "stale";
    is >> str;
    chk("extracting from empty input sets failbit", is.fail());
    chkstr("the sentry failing leaves the string alone", str, "stale");
  }
  {
    /* `getline' IS reachable, because its sentry does not skip
     * whitespace and so succeeds on a stream that is merely at its
     * end -- the erase then happens and the read fails after it. */
    std::istringstream is("");
    std::string        str = "stale";
    std::getline(is, str);
    chk("getline at end of input sets failbit", is.fail());
    chkstr("getline erases before it reads", str, "");
  }

  /* ---- section 6: getline ------------------------------------- */
  printf("section 6: getline\n");
  {
    std::istringstream is("one\ntwo\n");
    std::string        l;
    std::getline(is, l);
    chkstr("first line", l, "one");
    std::getline(is, l);
    chkstr("second line", l, "two");
    std::getline(is, l);
    chk("getline at end of input fails", is.fail());
  }
  {
    /* ***AN EMPTY LINE IS A SUCCESS.***  `0 == n -> failbit' is the
     * obvious implementation and it is wrong: the delimiter WAS
     * extracted, so something happened.  A reader loop over a file
     * with a blank line stops early against the naive version. */
    std::istringstream is("\nx\n");
    std::string        l;
    std::getline(is, l);
    chk("an empty line is not a failure", !is.fail());
    chkstr("an empty line yields an empty string", l, "");
    std::getline(is, l);
    chkstr("the line after an empty one", l, "x");
  }
  {
    std::istringstream is("a,b");
    std::string        l;
    std::getline(is, l, ',');
    chkstr("getline with a delimiter", l, "a");
    std::getline(is, l, ',');
    chkstr("getline to end of input without the delimiter", l, "b");
  }
  {
    /* `gcount' counts the delimiter that was consumed and discarded,
     * so "ab\n" read into a big buffer is THREE. */
    std::istringstream is("ab\n");
    char               buf[16];
    is.getline(buf, sizeof(buf));
    chkstr("getline into a buffer", std::string(buf), "ab");
    chk("gcount counts the delimiter", 3 == is.gcount());
  }

  /* ---- section 7: unformatted I/O ----------------------------- */
  printf("section 7: unformatted I/O\n");
  {
    std::ostringstream os;
    os.put('a');
    os.write("bc", 2);
    chkstr("put and write", os.str(), "abc");
  }
  {
    std::istringstream is("abcdef");
    char               buf[4];
    is.read(buf, 3);
    buf[3] = '\0';
    chk("read gives the right count", 3 == is.gcount());
    chkstr("read gives the right bytes", std::string(buf), "abc");
    chk("peek does not consume", 'd' == is.peek());
    chk("peek again is the same", 'd' == is.peek());
    chk("get after peek", 'd' == is.get());
    is.unget();
    chk("unget puts it back", 'd' == is.get());
  }
  {
    std::istringstream is("xy");
    chk("get returns the first character", 'x' == is.get());
    is.putback('x');
    chk("putback", 'x' == is.get());
  }

  /* ---- section 8: seeking ------------------------------------- */
  printf("section 8: seeking in a string stream\n");
  {
    std::istringstream is("0123456789");
    char               c = 0;
    is.seekg(5);
    is.get(c);
    chk("seekg absolute", '5' == c);
    is.seekg(-2, std::ios_base::cur);
    is.get(c);
    chk("seekg relative", '4' == c);
    is.seekg(0, std::ios_base::end);
    chk("seekg to the end gives the length", 10 == static_cast<long>(is.tellg()));
  }
  {
    std::stringstream ss;
    ss << "abc";
    chk("tellp after writing", 3 == static_cast<long>(ss.tellp()));
    std::string got;
    ss >> got;
    chkstr("a stringstream reads back what it wrote", got, "abc");
  }

  /* ---- section 9: a real file --------------------------------- */
  printf("section 9: a real file\n");
  {
    char const *const name = "/tmp/cxx-iostream-test.tmp";
    {
      std::ofstream of(name);
      chk("ofstream opens", of.is_open());
      of << "line one\n" << 42 << '\n';
      of.close();
      chk("ofstream closes clean", !of.fail());
    }
    {
      std::ifstream inf(name);
      chk("ifstream opens", inf.is_open());
      std::string l;
      std::getline(inf, l);
      chkstr("the file's first line", l, "line one");
      int v = 0;
      inf >> v;
      chk("the file's number", 42 == v);
      inf.close();
    }
    {
      std::ifstream missing("/tmp/cxx-iostream-test-does-not-exist");
      /* A stub that answers SUCCESS for a missing file is this tree's
       * commonest bug shape, so it is asserted rather than assumed. */
      chk("opening a missing file fails", !missing.is_open() && missing.fail());
    }
    remove(name);
  }

#ifndef REFERENCE
  /* ---- section 10: the standard streams ----------------------- */
  /*
   * APExp's `cout' is a REFERENCE to a function-local static, not an
   * object in a library -- see `io/iostream.h'.  So this section asks
   * what that arrangement has to get right and libstdc++ cannot be
   * asked the same question.
   */
  printf("section 10: cout/cerr/clog (APExp arm only)\n");
  {
    chk("cout and clog are distinct streams", &std::cout != &std::clog);
    chk("cerr and clog share a buffer", std::cerr.rdbuf() == std::clog.rdbuf());
    chk("cerr is unitbuf", 0 != (std::cerr.flags() & std::ios_base::unitbuf));
    chk("cin is tied to cout", std::cin.tie() == &std::cout);
    chk("cout is usable", static_cast<bool>(std::cout));
    std::cout << "" << std::flush;
    chk("cout survives a flush", !std::cout.fail());
  }
#endif

  printf("\ncxx-iostream-test: %d failure%s\n", fails, (1 == fails) ? "" : "s");
  return fails;
}
