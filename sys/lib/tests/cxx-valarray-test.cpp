// cxx-valarray-test.cpp -- `std::valarray' in the APExp C++ library.
//
// FROM: re2c, which is the only caller `valarray' has in this tree and
// whose whole use of it is ONE line --
//
//     std::valarray<bool> loops(skel.nodes_count);   // control_flow.cc:61
//
// a depth-first-search visited bitmap.  Section 1 is that line and
// nothing else, because the measured demand is the part that must not
// regress; the rest of the file is the arithmetic the type exists for.
//
// ---- TWO ARMS, AND THE REFERENCE ONE IS NOT DECORATION -------------------
//
//   g++ -std=c++14 -DREFERENCE -o ref cxx-valarray-test.cpp   # libstdc++
//   eccp -o cxx-valarray-test cxx-valarray-test.cpp           # APExp, on the VM
//
// The `-DREFERENCE' arm builds the SAME assertions against libstdc++, so
// a disagreement is a bug in one of the two and the test cannot quietly
// be wrong about the rule.  *It has paid for itself twice in this
// library already*, once by being wrong itself.
//
// The APExp arm runs more sections than the reference one: the extra ones
// are marked APExp-only and assert things the standard leaves undefined
// (a mismatched-size compound operation, a reduction over an empty
// array) or that are this library's convention rather than the
// standard's (`expected'-returning factories).
//
// ---- THE CONVENTION DIFFERENCE IS HIDDEN IN HELPERS ----------------------
//
// This library is exception-free, so what the standard spells
// `valarray<T> v(n)' is spelled `make_valarray(n)' and answers
// `expected'.  The `mk'/`cl'/`sh'/... helpers below absorb that so the
// body of every section is IDENTICAL text in both arms -- which is the
// only way the comparison means anything.
//
// Print PASS/FAIL per case; exit with the number of failures.

#include <cstdio>
#include <cstddef>

#ifdef REFERENCE
#include <valarray>
#else
#include <valarray>
#endif

static int failures = 0;

static void check(bool ok, char const *what) {
  std::printf("%s: %s\n", ok ? "PASS" : "FAIL", what);
  if (!ok) {
    ++failures;
  }
}

// ---------------------------------------------------------------------------
// The arm-difference helpers.  Everything below this block is common text.
// ---------------------------------------------------------------------------

#ifdef REFERENCE

template<class T> std::valarray<T> mk(std::size_t n) {
  return std::valarray<T>(n);
}
template<class T> std::valarray<T> mkv(std::size_t n, T v) {
  return std::valarray<T>(v, n); // note: the standard's order is (value, count)
}
template<class T> std::valarray<T> mkr(T const *p, std::size_t n) {
  return std::valarray<T>(p, n);
}
template<class T> std::valarray<T> cl(std::valarray<T> const &a) {
  return a;
}
template<class T> void rs(std::valarray<T> &a, std::size_t n) {
  a.resize(n);
}
template<class T> void rsv(std::valarray<T> &a, std::size_t n, T v) {
  a.resize(n, v);
}
template<class T> std::valarray<T> sh(std::valarray<T> const &a, int n) {
  return a.shift(n);
}
template<class T> std::valarray<T> csh(std::valarray<T> const &a, int n) {
  return a.cshift(n);
}
template<class T, class F> std::valarray<T> ap(std::valarray<T> const &a, F f) {
  return a.apply(f);
}

#else

template<class T> std::valarray<T> mk(std::size_t n) {
  auto r = std::valarray<T>::make_valarray(n);
  return r ? std::move(r.value()) : std::valarray<T>();
}
template<class T> std::valarray<T> mkv(std::size_t n, T v) {
  auto r = std::valarray<T>::make_valarray(n, v);
  return r ? std::move(r.value()) : std::valarray<T>();
}
template<class T> std::valarray<T> mkr(T const *p, std::size_t n) {
  auto r = std::valarray<T>::make_valarray_range(p, p + n);
  return r ? std::move(r.value()) : std::valarray<T>();
}
template<class T> std::valarray<T> cl(std::valarray<T> const &a) {
  auto r = a.clone();
  return r ? std::move(r.value()) : std::valarray<T>();
}
template<class T> void rs(std::valarray<T> &a, std::size_t n) {
  (void)a.resize(n);
}
template<class T> void rsv(std::valarray<T> &a, std::size_t n, T v) {
  (void)a.resize(n, v);
}
template<class T> std::valarray<T> sh(std::valarray<T> const &a, int n) {
  auto r = a.shift(n);
  return r ? std::move(r.value()) : std::valarray<T>();
}
template<class T> std::valarray<T> csh(std::valarray<T> const &a, int n) {
  auto r = a.cshift(n);
  return r ? std::move(r.value()) : std::valarray<T>();
}
template<class T, class F> std::valarray<T> ap(std::valarray<T> const &a, F f) {
  auto r = a.apply(f);
  return r ? std::move(r.value()) : std::valarray<T>();
}

#endif

// Compare against a plain C array, which is the one thing both arms agree
// about without a helper.
template<class T>
static bool same(std::valarray<T> const &a, T const *want, std::size_t n) {
  if (a.size() != n) {
    return false;
  }
  for (std::size_t i = 0; i < n; ++i) {
    if (!(a[i] == want[i])) {
      return false;
    }
  }
  return true;
}

static int twice(int v) {
  return v * 2;
}

int main(void) {
  std::setvbuf(stdout, NULL, _IOLBF, 0);
  std::printf("cxx-valarray-test: starting\n");

  // ---- 1. re2c's line, which is the whole measured demand --------------
  {
    std::size_t const nodes_count = 7;
    std::valarray<bool> loops = mk<bool>(nodes_count);

    check(loops.size() == nodes_count, "1a sizing factory gives the asked-for size");

    bool all_false = true;
    for (std::size_t i = 0; i < nodes_count; ++i) {
      if (loops[i]) {
        all_false = false;
      }
    }
    // The zero fill is the half re2c silently depends on: a DFS that
    // starts with a dirty visited map terminates early and drops paths.
    check(all_false, "1b every element is value-initialised (false)");

    loops[3] = true;
    loops[5] = true;
    check(loops[3] && loops[5], "1c operator[] stores through a real reference");
    check(!loops[0] && !loops[4] && !loops[6], "1d a store touches no neighbour");

    // valarray<bool> is NOT specialised the way vector<bool> is, so this
    // must be a genuine bool&, not a proxy.
    bool &slot = loops[2];
    slot       = true;
    check(loops[2], "1e operator[] yields a true lvalue, not a proxy");
  }

  // ---- 2. the fill factory ---------------------------------------------
  {
    std::valarray<int> v = mkv<int>(4, 9);
    int const want[4] = {9, 9, 9, 9};
    check(same(v, want, 4), "2a fill factory fills every element");

    std::valarray<int> e = mk<int>(0);
    check(e.size() == 0, "2b a zero-length array is legal and empty");
  }

  // ---- 3. the range factory --------------------------------------------
  {
    int const src[5] = {3, 1, 4, 1, 5};
    std::valarray<int> v = mkr<int>(src, 5);
    check(same(v, src, 5), "3a range factory copies the range in order");
  }

  // ---- 4. clone is independent -----------------------------------------
  {
    int const src[3] = {1, 2, 3};
    std::valarray<int> a = mkr<int>(src, 3);
    std::valarray<int> b = cl(a);
    b[1]                 = 99;

    int const want_a[3] = {1, 2, 3};
    int const want_b[3] = {1, 99, 3};
    check(same(a, want_a, 3), "4a writing the copy leaves the original alone");
    check(same(b, want_b, 3), "4b the copy took the write");
  }

  // ---- 5. compound assignment, array and scalar ------------------------
  {
    int const sa[4] = {1, 2, 3, 4};
    int const sb[4] = {10, 20, 30, 40};
    std::valarray<int> a = mkr<int>(sa, 4);
    std::valarray<int> b = mkr<int>(sb, 4);

    a += b;
    int const want1[4] = {11, 22, 33, 44};
    check(same(a, want1, 4), "5a += between two arrays is elementwise");

    a -= b;
    check(same(a, sa, 4), "5b -= undoes it");

    a *= 3;
    int const want2[4] = {3, 6, 9, 12};
    check(same(a, want2, 4), "5c *= by a scalar touches every element");

    a /= 3;
    check(same(a, sa, 4), "5d /= by a scalar undoes it");

    std::valarray<int> c = mkr<int>(sa, 4);
    c <<= 2;
    int const want3[4] = {4, 8, 12, 16};
    check(same(c, want3, 4), "5e <<= by a scalar shifts every element");

    std::valarray<int> d = mkr<int>(sb, 4);
    d %= 7;
    int const want4[4] = {3, 6, 2, 5};
    check(same(d, want4, 4), "5f %= by a scalar is elementwise");
  }

  // ---- 6. reductions ----------------------------------------------------
  {
    int const src[5] = {3, 1, 4, 1, 5};
    std::valarray<int> v = mkr<int>(src, 5);
    check(v.sum() == 14, "6a sum adds every element");
    check(v.min() == 1, "6b min finds the smallest");
    check(v.max() == 5, "6c max finds the largest");

    int const one[1] = {42};
    std::valarray<int> s = mkr<int>(one, 1);
    check(s.sum() == 42 && s.min() == 42 && s.max() == 42,
          "6d a one-element array reduces to that element");
  }

  // ---- 7. apply ---------------------------------------------------------
  {
    int const src[3] = {1, 2, 3};
    std::valarray<int> a = mkr<int>(src, 3);
    std::valarray<int> b = ap(a, twice);

    int const want[3] = {2, 4, 6};
    check(same(b, want, 3), "7a apply maps every element");
    check(same(a, src, 3), "7b apply leaves the original alone");
  }

  // ---- 8. shift and cshift ---------------------------------------------
  //
  // A POSITIVE count moves elements towards the front in both, which is
  // the direction the name does not tell you and the standard does.
  {
    int const src[5] = {1, 2, 3, 4, 5};
    std::valarray<int> v = mkr<int>(src, 5);

    std::valarray<int> s2 = sh(v, 2);
    int const want_s2[5] = {3, 4, 5, 0, 0};
    check(same(s2, want_s2, 5), "8a shift(+2) moves left and zero-fills");

    std::valarray<int> sm = sh(v, -2);
    int const want_sm[5] = {0, 0, 1, 2, 3};
    check(same(sm, want_sm, 5), "8b shift(-2) moves right and zero-fills");

    std::valarray<int> c2 = csh(v, 2);
    int const want_c2[5] = {3, 4, 5, 1, 2};
    check(same(c2, want_c2, 5), "8c cshift(+2) wraps instead of filling");

    std::valarray<int> cm = csh(v, -2);
    int const want_cm[5] = {4, 5, 1, 2, 3};
    // The negative case is the one that separates a correct cshift from a
    // plausible one: C++ `%' truncates towards zero, so an index computed
    // as (i + n) % size is NEGATIVE here and must be normalised by hand.
    check(same(cm, want_cm, 5), "8d cshift(-2) wraps the other way");

    check(same(v, src, 5), "8e neither shift disturbs the original");
  }

  // ---- 9. resize --------------------------------------------------------
  //
  // The standard's resize VALUE-INITIALISES EVERY element and does not
  // preserve the old contents -- a valarray is a numeric vector, not a
  // container.  Code written against the standard reads stale values if
  // this is "fixed" to preserve them.
  {
    int const src[3] = {7, 8, 9};
    std::valarray<int> v = mkr<int>(src, 3);
    rs(v, 5);
    int const want[5] = {0, 0, 0, 0, 0};
    check(same(v, want, 5), "9a resize value-initialises every element");

    std::valarray<int> w = mkr<int>(src, 3);
    rsv(w, 4, 6);
    int const want2[4] = {6, 6, 6, 6};
    check(same(w, want2, 4), "9b resize with a value fills every element");

    std::valarray<int> x = mkr<int>(src, 3);
    rs(x, 0);
    check(x.size() == 0, "9c resize to zero empties it");
  }

#ifndef REFERENCE
  // ---- 10. APExp-only: what this library defines and the standard does not
  {
    // The standard calls a mismatched-size compound operation undefined,
    // so any behaviour conforms.  This library does NOTHING, which is the
    // one choice that cannot read or write past either object.
    int const sa[3] = {1, 2, 3};
    int const sb[5] = {1, 1, 1, 1, 1};
    std::valarray<int> a = mkr<int>(sa, 3);
    std::valarray<int> b = mkr<int>(sb, 5);
    a += b;
    check(same(a, sa, 3), "10a a mismatched-size compound op is a no-op");
    check(a.size() == 3, "10b and does not resize either operand");

    // Reductions over an empty array: undefined in the standard (there is
    // no value to return), a value-initialised T here rather than a read
    // through a null pointer.
    std::valarray<int> e = mk<int>(0);
    check(e.sum() == 0, "10c sum of an empty array is zero, not a fault");
    check(e.min() == 0 && e.max() == 0, "10d min/max of an empty array are zero");

    // The factories answer `expected', which is the library's convention
    // and the reason the standard's sizing constructor is absent.
    auto r = std::valarray<int>::make_valarray(3, 5);
    check(static_cast<bool>(r), "10e make_valarray answers a usable expected");
    check(r && r.value().size() == 3, "10f and the value is the array asked for");

    // apply_inplace is the no-allocation form, so it cannot fail and
    // returns the array rather than an expected.
    int const src[3] = {1, 2, 3};
    std::valarray<int> v = mkr<int>(src, 3);
    v.apply_inplace(twice);
    int const want[3] = {2, 4, 6};
    check(same(v, want, 3), "10g apply_inplace maps in place without allocating");

    // Moving out leaves a valid empty array behind rather than a
    // double-free waiting to happen.
    std::valarray<int> src2 = mkr<int>(src, 3);
    std::valarray<int> dst  = std::move(src2);
    check(dst.size() == 3, "10h move takes the storage");
    check(src2.size() == 0, "10i and leaves the source empty and destructible");
  }
#endif

  std::printf("cxx-valarray-test: %d failures\n", failures);
  return failures;
}
