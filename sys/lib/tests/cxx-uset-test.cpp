/*
 * cxx-uset-test.cpp -- does APExp's unordered_set (and std::hash) behave?
 *
 *	eccp -o cxx-uset-test cxx-uset-test.cpp
 *	./cxx-uset-test
 *
 * and the host arms, which must BOTH be 0:
 *
 *	sys/lib/tests/hostkencc/cxxlib-host.sh --uset
 *	g++ -std=c++14 -DREFERENCE -o /tmp/usref cxx-uset-test.cpp
 *
 * ---- THE ARMS DIFFER IN ONE PLACE AND IT IS BEHIND A FUNCTION ---------
 *
 * APExp's `insert' answers
 * `expected<tuple<const_iterator, bool>, std_error>' where the standard
 * answers `pair<iterator, bool>' -- because this library is
 * exception-free and **has no `std::pair` at all**, so `set::insert'
 * already answers a tuple and this matches it.  `ins()' hides that, so
 * both arms run the SAME assertions rather than two sets of assertions
 * believed to correspond.
 *
 * ---- WHY SECTION 6 IS WORTH MORE THAN IT LOOKS -----------------------
 *
 * ***`hash<double>(0.0)' MUST EQUAL `hash<double>(-0.0)'.***  The two
 * compare EQUAL and have different bit patterns, so a hash over the
 * bytes gives one key two buckets -- store `-0.0', look up `0.0', miss.
 * *That is a silent wrong answer and not a crash*, and it is a STANDARD
 * rule, so libstdc++ answers the same question and the reference arm is
 * a real oracle for it.  The same goes for `bool`: any nonzero byte is
 * a valid `true' and must hash with every other `true'.
 *
 * ---- THE SIZES -------------------------------------------------------
 *
 * The bucket count starts at 3 and goes up through the prime table, so
 * **1000 inserts rehash about ten times** and every one of them relinks
 * every node.  A set that never rehashes is a test of a linked list.
 * Section 2 then looks up all 1000 AFTER the growth, which is what
 * catches a rehash that drops or duplicates a chain -- the failure a
 * size count alone cannot see.
 */

#include <stdio.h>

#include <unordered_set>
#include <functional>
#include <string>

#ifdef REFERENCE
#include <utility>
#else
#include <tuple>
#endif

static int fails = 0;

static void chk(char const *tag, bool ok) {
  printf("%s: %s\n", ok ? "PASS" : "FAIL", tag);
  if (!ok) {
    fails++;
  }
}

static void chkn(char const *tag, long got, long want) {
  if (got == want) {
    printf("PASS: %s\n", tag);
  } else {
    printf("FAIL: %s -- got %ld, want %ld\n", tag, got, want);
    fails++;
  }
}

/* `true' if the element was newly inserted; `false' if it was already
 * there OR the insert failed.  Both arms, one signature. */
template<class t_set, class t_val> static bool ins(t_set &s, t_val const &v) {
#ifdef REFERENCE
  return s.insert(v).second;
#else
  auto r = s.insert(v);
  if (!r) {
    return false;
  }
  return std::get<1>(r.value());
#endif
}

int main(void) {
  setvbuf(stdout, 0, _IOLBF, 0);
  printf("cxx-uset-test: starting\n");

  /* ---- section 0: the control --------------------------------- */
  printf("section 0: an empty set (control)\n");
  {
    std::unordered_set<int> s;
    chk("a new set is empty", s.empty());
    chkn("a new set has size 0", static_cast<long>(s.size()), 0);
    chk("begin equals end", s.begin() == s.end());
    chk("find on an empty set misses", s.find(1) == s.end());
    chkn("count on an empty set", static_cast<long>(s.count(1)), 0);
  }

  /* ---- section 1: insert, find, duplicates -------------------- */
  printf("section 1: insert, find and duplicates\n");
  {
    std::unordered_set<int> s;
    chk("the first insert is new", ins(s, 42));
    chkn("size after one insert", static_cast<long>(s.size()), 1);
    chk("find returns it", s.find(42) != s.end());
    chk("the element is right", *s.find(42) == 42);
    /* ***A DUPLICATE MUST BE REJECTED AND THE SIZE MUST NOT MOVE.***
     * A set that inserts duplicates still answers `find' correctly,
     * so only the size and the iteration count can see it. */
    chk("the second insert of the same key is NOT new", !ins(s, 42));
    chkn("size after a duplicate", static_cast<long>(s.size()), 1);
    chk("a different key is new", ins(s, 43));
    chkn("size after a different key", static_cast<long>(s.size()), 2);
    chk("a key never inserted is not found", s.find(44) == s.end());
  }

  /* ---- section 2: growth and rehashing ------------------------ */
  printf("section 2: 1000 inserts, which rehash about ten times\n");
  {
    std::unordered_set<int> s;
    bool                    allnew = true;
    for (int i = 0; i < 1000; i++) {
      if (!ins(s, i)) {
        allnew = false;
      }
    }
    chk("every one of 1000 inserts was new", allnew);
    chkn("size after 1000", static_cast<long>(s.size()), 1000);

    /* The lookups come AFTER all the growth, so a rehash that lost a
     * chain shows here and nowhere else. */
    bool allfound = true;
    for (int i = 0; i < 1000; i++) {
      if (s.find(i) == s.end()) {
        allfound = false;
        break;
      }
    }
    chk("all 1000 are still findable after the rehashes", allfound);

    bool nofalse = true;
    for (int i = 1000; i < 1100; i++) {
      if (s.find(i) != s.end()) {
        nofalse = false;
        break;
      }
    }
    chk("no key that was never inserted is found", nofalse);

    /* Re-inserting all 1000 must add nothing: that is the duplicate
     * rule tested across every bucket rather than in one. */
    bool anynew = false;
    for (int i = 0; i < 1000; i++) {
      if (ins(s, i)) {
        anynew = true;
      }
    }
    chk("re-inserting all 1000 adds nothing", !anynew);
    chkn("size is unchanged", static_cast<long>(s.size()), 1000);
  }

  /* ---- section 2b: SCATTERED keys ------------------------------ */
  /*
   * ***THIS SECTION EXISTS BECAUSE A CONTROL DID NOT FIRE.***  The
   * deliberate break was `rehash' relinking with the OLD bucket count
   * instead of the new one, and section 2 did not notice -- *0
   * failures against a provably broken rehash.*
   *
   * The reason is the DATA.  `hash<int>' is the identity, a rehash
   * happens exactly when `size == bucket_count', and section 2's keys
   * are `0 .. size-1' -- so every stored key is SMALLER than the old
   * bucket count, `h % old' is `h', `h % new' is `h', and the two
   * moduli agree for every node at every rehash.  *The wrong modulus
   * was not wrong for that data.*
   *
   * These keys are multiples of a large prime, so they exceed every
   * bucket count in the table and the two moduli disagree.  A dense
   * `0..N' run is the shape that makes a hash container look right.
   */
  printf("section 2b: scattered keys, where the bucket index matters\n");
  {
    std::unordered_set<int> s;
    int const               step = 1000003;
    bool                    allnew = true;
    for (int i = 1; i <= 400; i++) {
      if (!ins(s, i * step)) {
        allnew = false;
      }
    }
    chk("every scattered insert was new", allnew);
    chkn("size", static_cast<long>(s.size()), 400);

    bool allfound = true;
    for (int i = 1; i <= 400; i++) {
      if (s.find(i * step) == s.end()) {
        allfound = false;
        break;
      }
    }
    chk("every scattered key is findable after the rehashes", allfound);

    bool anynew = false;
    for (int i = 1; i <= 400; i++) {
      if (ins(s, i * step)) {
        anynew = true;
      }
    }
    chk("re-inserting the scattered keys adds nothing", !anynew);
    chkn("size is unchanged", static_cast<long>(s.size()), 400);

    long count = 0;
    for (std::unordered_set<int>::const_iterator it = s.begin(); it != s.end(); ++it) {
      count++;
    }
    chkn("iteration still visits each exactly once", count, 400);
  }

  /* ---- section 3: iteration ----------------------------------- */
  printf("section 3: iteration visits each element exactly once\n");
  {
    std::unordered_set<int> s;
    for (int i = 0; i < 500; i++) {
      (void)ins(s, i);
    }
    long count = 0;
    long sum   = 0;
    for (std::unordered_set<int>::const_iterator it = s.begin(); it != s.end(); ++it) {
      count++;
      sum += *it;
    }
    /* The SUM is what makes this a real check: a count alone passes
     * for an iteration that visits one element 500 times. */
    chkn("iteration visits size() elements", count, 500);
    chkn("and their sum is right", sum, 124750);
  }

  /* ---- section 4: erase --------------------------------------- */
  printf("section 4: erase\n");
  {
    std::unordered_set<int> s;
    for (int i = 0; i < 100; i++) {
      (void)ins(s, i);
    }
    chkn("erase of a present key returns 1", static_cast<long>(s.erase(50)), 1);
    chkn("size after erase", static_cast<long>(s.size()), 99);
    chk("the erased key is gone", s.find(50) == s.end());
    chk("its neighbours are not", (s.find(49) != s.end()) && (s.find(51) != s.end()));
    chkn("erase of an absent key returns 0", static_cast<long>(s.erase(50)), 0);
    chkn("size after a failed erase", static_cast<long>(s.size()), 99);
    /* Erasing everything then refilling is where a bucket left in a
     * bad state shows up. */
    for (int i = 0; i < 100; i++) {
      (void)s.erase(i);
    }
    chk("erasing everything empties it", s.empty());
    chk("and iteration agrees", s.begin() == s.end());
    for (int i = 0; i < 100; i++) {
      (void)ins(s, i);
    }
    chkn("refilled after erasing all", static_cast<long>(s.size()), 100);
  }

  /* ---- section 5: strings ------------------------------------- */
  printf("section 5: strings\n");
  {
    std::unordered_set<std::string> s;
    chk("insert a string", ins(s, std::string("alpha")));
    chk("insert another", ins(s, std::string("beta")));
    chk("the same string again is not new", !ins(s, std::string("alpha")));
    chkn("size", static_cast<long>(s.size()), 2);
    chk("find by an equal but distinct string object",
        s.find(std::string("alpha")) != s.end());
    chk("a string never inserted is not found", s.find(std::string("gamma")) == s.end());

    /* Long strings share no short-buffer state with short ones, so
     * this is the case where hashing the OBJECT rather than its
     * contents would answer wrongly. */
    std::string const longa(200, 'x');
    std::string const longb(200, 'x');
    chk("insert a long string", ins(s, longa));
    chk("an equal long string is not new", !ins(s, longb));
    chkn("size after the long strings", static_cast<long>(s.size()), 3);
  }

  /* ---- section 6: std::hash ----------------------------------- */
  printf("section 6: std::hash\n");
  {
    chk("equal ints hash equal", std::hash<int>()(7) == std::hash<int>()(7));
    chk("equal strings hash equal",
        std::hash<std::string>()(std::string("hello"))
            == std::hash<std::string>()(std::string("hello")));
    chk("different strings hash differently (not required, but expected)",
        std::hash<std::string>()(std::string("hello"))
            != std::hash<std::string>()(std::string("world")));
    /* The standard rule: equal keys must hash equal, and 0.0 == -0.0. */
    chk("0.0 and -0.0 hash equal (double)",
        std::hash<double>()(0.0) == std::hash<double>()(-0.0));
    chk("0.0 and -0.0 hash equal (float)",
        std::hash<float>()(0.0F) == std::hash<float>()(-0.0F));
    chk("equal doubles hash equal", std::hash<double>()(1.5) == std::hash<double>()(1.5));
    chk("true hashes with true", std::hash<bool>()(true) == std::hash<bool>()(true));
    chk("true and false hash differently",
        std::hash<bool>()(true) != std::hash<bool>()(false));
    int        v = 0;
    int *const p = &v;
    chk("a pointer hashes by value", std::hash<int *>()(p) == std::hash<int *>()(p));
  }
  {
    /* A set keyed on double, where the negative-zero rule is what
     * decides whether the lookup works at all. */
    std::unordered_set<double> s;
    chk("insert -0.0", ins(s, -0.0));
    chk("0.0 finds it", s.find(0.0) != s.end());
    chk("inserting 0.0 is not new", !ins(s, 0.0));
    chkn("size is one", static_cast<long>(s.size()), 1);
  }

  /* ---- section 7: clear, swap, load factor -------------------- */
  printf("section 7: clear, swap and load factor\n");
  {
    std::unordered_set<int> s;
    for (int i = 0; i < 300; i++) {
      (void)ins(s, i);
    }
    chk("bucket_count is at least the size", s.bucket_count() >= s.size());
    chk("load_factor is positive", s.load_factor() > 0.0F);
    s.clear();
    chk("clear empties", s.empty());
    chkn("clear leaves size 0", static_cast<long>(s.size()), 0);
    chk("clear leaves iteration empty", s.begin() == s.end());
    for (int i = 0; i < 300; i++) {
      (void)ins(s, i);
    }
    chkn("refilled after clear", static_cast<long>(s.size()), 300);

    std::unordered_set<int> a;
    std::unordered_set<int> b;
    (void)ins(a, 1);
    (void)ins(b, 2);
    (void)ins(b, 3);
    a.swap(b);
    chkn("swap moved the sizes", static_cast<long>(a.size()), 2);
    chk("swap moved the contents", a.find(2) != a.end());
    chk("and the other way", b.find(1) != b.end());
  }

#ifndef REFERENCE
  /* ---- section 8: the APExp-only API --------------------------- */
  printf("section 8: clone, make_unordered_set_range, rehash (APExp arm only)\n");
  {
    std::unordered_set<int> s;
    for (int i = 0; i < 200; i++) {
      (void)ins(s, i);
    }
    auto c = s.clone();
    chk("clone succeeds", static_cast<bool>(c));
    if (c) {
      chkn("the clone has the same size", static_cast<long>(c.value().size()), 200);
      bool allfound = true;
      for (int i = 0; i < 200; i++) {
        if (c.value().find(i) == c.value().end()) {
          allfound = false;
          break;
        }
      }
      chk("the clone has every element", allfound);
      (void)c.value().erase(5);
      chk("erasing in the clone does not touch the original", s.find(5) != s.end());
    }
  }
  {
    int const src[] = {4, 5, 6, 5, 4};
    auto      made  = std::unordered_set<int>::make_unordered_set_range(src, src + 5);
    chk("make_unordered_set_range succeeds", static_cast<bool>(made));
    if (made) {
      chkn("it de-duplicates", static_cast<long>(made.value().size()), 3);
    }
  }
  {
    std::unordered_set<int> s;
    for (int i = 0; i < 10; i++) {
      (void)ins(s, i);
    }
    auto r = s.rehash(1000);
    chk("rehash succeeds", static_cast<bool>(r));
    chk("rehash grew the bucket count", s.bucket_count() >= 1000);
    chkn("rehash kept the size", static_cast<long>(s.size()), 10);
    bool allfound = true;
    for (int i = 0; i < 10; i++) {
      if (s.find(i) == s.end()) {
        allfound = false;
        break;
      }
    }
    chk("rehash kept every element findable", allfound);
  }
#endif

  printf("\ncxx-uset-test: %d failure%s\n", fails, (1 == fails) ? "" : "s");
  return fails;
}
