/*
 * cxx-deque-test.cpp -- does APExp's deque (and stack, and queue) behave?
 *
 *	eccp -o cxx-deque-test cxx-deque-test.cpp
 *	./cxx-deque-test
 *
 * and the host arms, which must BOTH be 0:
 *
 *	sys/lib/tests/hostkencc/cxxlib-host.sh --deque
 *	g++ -std=c++14 -DREFERENCE -o /tmp/dqref cxx-deque-test.cpp
 *
 * ---- WHY A REFERENCE ARM, AND WHAT IT CAN AND CANNOT ASK -------------
 *
 * Everything in sections 0 to 7 is a STANDARD rule about `deque', so
 * libstdc++ can be asked the identical file and a disagreement says
 * which side is wrong.  That arm has already earned itself once in this
 * tree: `cxx-iostream-test' asserted the C++98 extraction rule and
 * libstdc++ said C++11, *and the library had the same bug the test did.*
 *
 * **The arms differ in exactly one mechanical way and it is hidden in a
 * macro.**  APExp's `push_back'/`push'/`push_front' return
 * `expected<void, std_error>' where the standard returns `void', because
 * this library is exception-free and `vector::push_back' already does --
 * see `containers/deque.h'.  `PUSH(e)' is `(void)(e)', which is valid
 * for both, *so the two arms run the same statements* rather than two
 * sets of statements that are merely believed to correspond.
 *
 * Section 8 is APExp-only: `make_deque', `clone' and the `expected' at()
 * have no libstdc++ counterpart to compare against.
 *
 * ---- WHAT THE SIZES ARE FOR ------------------------------------------
 *
 * A deque's whole difficulty is the BLOCK BOUNDARY and the map growing,
 * and `block_size' for `int' here is 512/4 = 128.  **So every size below
 * is chosen to cross one**: 1000 elements is eight blocks, and the
 * mixed-end section alternates so the map has to grow at BOTH ends.  *A
 * deque test that never leaves the first block is a test of an array*,
 * which is the shape that would pass against almost any mistake in this
 * file.
 */

#include <stdio.h>

#include <deque>
#include <stack>
#include <queue>
#include <cassert>

#ifdef REFERENCE
#define PUSH(e) (e)
#else
#define PUSH(e) ((void)(e))
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

int main(void) {
  setvbuf(stdout, 0, _IOLBF, 0);
  printf("cxx-deque-test: starting\n");

  /* ---- section 0: the control --------------------------------- */
  printf("section 0: an empty deque (control)\n");
  {
    std::deque<int> d;
    chk("a new deque is empty", d.empty());
    chkn("a new deque has size 0", static_cast<long>(d.size()), 0);
    chk("begin equals end", d.begin() == d.end());
  }

  /* ---- section 1: push_back across blocks --------------------- */
  printf("section 1: push_back across block boundaries\n");
  {
    std::deque<int> d;
    for (int i = 0; i < 1000; i++) {
      PUSH(d.push_back(i));
    }
    chkn("size after 1000 push_back", static_cast<long>(d.size()), 1000);
    chkn("front", d.front(), 0);
    chkn("back", d.back(), 999);
    bool ok = true;
    for (int i = 0; i < 1000; i++) {
      if (d[static_cast<std::size_t>(i)] != i) {
        ok = false;
        break;
      }
    }
    chk("every element readable by index", ok);
  }

  /* ---- section 2: push_front across blocks -------------------- */
  printf("section 2: push_front across block boundaries\n");
  {
    std::deque<int> d;
    for (int i = 0; i < 1000; i++) {
      PUSH(d.push_front(i));
    }
    chkn("size after 1000 push_front", static_cast<long>(d.size()), 1000);
    chkn("front is the last pushed", d.front(), 999);
    chkn("back is the first pushed", d.back(), 0);
    bool ok = true;
    for (int i = 0; i < 1000; i++) {
      if (d[static_cast<std::size_t>(i)] != (999 - i)) {
        ok = false;
        break;
      }
    }
    chk("push_front reverses the order", ok);
  }

  /* ---- section 3: both ends at once --------------------------- */
  printf("section 3: alternating ends\n");
  {
    /* The map has to grow at both ends; 600 each way is nine blocks. */
    std::deque<int> d;
    for (int i = 0; i < 600; i++) {
      PUSH(d.push_back(i));
      PUSH(d.push_front(-i - 1));
    }
    chkn("size", static_cast<long>(d.size()), 1200);
    chkn("front", d.front(), -600);
    chkn("back", d.back(), 599);
    bool ok = true;
    for (int i = 0; i < 1200; i++) {
      int const want = i - 600;
      if (d[static_cast<std::size_t>(i)] != want) {
        ok = false;
        break;
      }
    }
    chk("the whole sequence is in order", ok);
  }

  /* ---- section 4: popping ------------------------------------- */
  printf("section 4: pop_front and pop_back\n");
  {
    std::deque<int> d;
    for (int i = 0; i < 500; i++) {
      PUSH(d.push_back(i));
    }
    for (int i = 0; i < 200; i++) {
      d.pop_front();
    }
    chkn("size after 200 pop_front", static_cast<long>(d.size()), 300);
    chkn("front after pop_front", d.front(), 200);
    for (int i = 0; i < 200; i++) {
      d.pop_back();
    }
    chkn("size after 200 pop_back", static_cast<long>(d.size()), 100);
    chkn("back after pop_back", d.back(), 299);
    chkn("front is unchanged by pop_back", d.front(), 200);

    /* ***POP THEN PUSH IS THE CASE A BLOCK-MAP DEQUE GETS WRONG***:
     * the start offset has moved, so the next push_front must reuse
     * the space the pops freed rather than ask for more. */
    for (int i = 0; i < 100; i++) {
      d.pop_front();
    }
    chk("emptied by popping", d.empty());
    for (int i = 0; i < 300; i++) {
      PUSH(d.push_back(i));
    }
    chkn("refilled after being emptied", static_cast<long>(d.size()), 300);
    chkn("refilled front", d.front(), 0);
    chkn("refilled back", d.back(), 299);
  }

  /* ---- section 5: iterators ----------------------------------- */
  printf("section 5: iterators\n");
  {
    std::deque<int> d;
    for (int i = 0; i < 300; i++) {
      PUSH(d.push_back(i));
    }
    long sum = 0;
    for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it) {
      sum += *it;
    }
    chkn("forward iteration sums correctly", sum, 44850);

    long rsum = 0;
    for (std::deque<int>::reverse_iterator it = d.rbegin(); it != d.rend(); ++it) {
      rsum += *it;
    }
    chkn("reverse iteration sums the same", rsum, 44850);

    chkn("end - begin is the size", static_cast<long>(d.end() - d.begin()), 300);
    chkn("random access through an iterator", d.begin()[250], 250);
    chkn("iterator arithmetic", *(d.begin() + 7), 7);
    chk("ordering compares", d.begin() < d.end());

    std::deque<int> const &cd = d;
    long               csum   = 0;
    for (std::deque<int>::const_iterator it = cd.begin(); it != cd.end(); ++it) {
      csum += *it;
    }
    chkn("const iteration sums the same", csum, 44850);
  }

  /* ---- section 6: erase, clear, swap, compare ----------------- */
  printf("section 6: erase, clear, swap and compare\n");
  {
    std::deque<int> d;
    for (int i = 0; i < 10; i++) {
      PUSH(d.push_back(i));
    }
    d.erase(d.begin() + 3);
    chkn("size after erase", static_cast<long>(d.size()), 9);
    chkn("the element after the erased one moved down", d[3], 4);
    chkn("the element before it did not", d[2], 2);

    std::deque<int> e;
    for (int i = 0; i < 9; i++) {
      PUSH(e.push_back((i < 3) ? i : (i + 1)));
    }
    chk("equal deques compare equal", d == e);
    PUSH(e.push_back(99));
    chk("different sizes compare unequal", d != e);

    d.clear();
    chk("clear empties", d.empty());
    chkn("clear leaves size 0", static_cast<long>(d.size()), 0);
    /* Refilling after clear is the case that would be quadratic, or
     * wrong, if clear had freed the blocks and left the offsets. */
    for (int i = 0; i < 200; i++) {
      PUSH(d.push_back(i));
    }
    chkn("refilled after clear", static_cast<long>(d.size()), 200);
    chkn("refilled after clear, back", d.back(), 199);

    std::deque<int> a;
    std::deque<int> b;
    PUSH(a.push_back(1));
    PUSH(b.push_back(2));
    PUSH(b.push_back(3));
    a.swap(b);
    chkn("swap moved the sizes", static_cast<long>(a.size()), 2);
    chkn("swap moved the values", a.front(), 2);
    chkn("swap moved the other way too", b.front(), 1);
  }

  /* ---- section 7: stack and queue ----------------------------- */
  printf("section 7: stack and queue\n");
  {
    std::stack<int> s;
    chk("a new stack is empty", s.empty());
    for (int i = 0; i < 300; i++) {
      PUSH(s.push(i));
    }
    chkn("stack size", static_cast<long>(s.size()), 300);
    chkn("stack top is the last pushed", s.top(), 299);
    s.pop();
    chkn("stack top after pop", s.top(), 298);
    chkn("stack size after pop", static_cast<long>(s.size()), 299);
  }
  {
    std::queue<int> q;
    chk("a new queue is empty", q.empty());
    for (int i = 0; i < 300; i++) {
      PUSH(q.push(i));
    }
    chkn("queue size", static_cast<long>(q.size()), 300);
    chkn("queue front is the FIRST pushed", q.front(), 0);
    chkn("queue back is the last pushed", q.back(), 299);
    q.pop();
    chkn("queue front after pop", q.front(), 1);
    chkn("queue size after pop", static_cast<long>(q.size()), 299);

    /* A queue is the shape that shows a deque using only one end: push
     * 300 and pop 300 repeatedly, and a deque that never reuses the
     * front would grow without bound. */
    for (int round = 0; round < 20; round++) {
      for (int i = 0; i < 50; i++) {
        PUSH(q.push(i));
      }
      for (int i = 0; i < 50; i++) {
        q.pop();
      }
    }
    chkn("size after 20 push/pop rounds", static_cast<long>(q.size()), 299);
  }

#ifndef REFERENCE
  /* ---- section 8: the APExp-only API --------------------------- */
  /*
   * `make_deque', `clone' and an `expected'-returning `at' have no
   * libstdc++ counterpart, so the reference arm cannot be asked about
   * them and they are measured here on their own terms.
   */
  printf("section 8: make_deque, clone and at (APExp arm only)\n");
  {
    auto made = std::deque<int>::make_deque(5, 7);
    chk("make_deque succeeds", static_cast<bool>(made));
    if (made) {
      chkn("make_deque gives the right size", static_cast<long>(made.value().size()), 5);
      chkn("make_deque fills with the value", made.value()[3], 7);
    }
  }
  {
    std::deque<int> d;
    for (int i = 0; i < 300; i++) {
      (void)d.push_back(i);
    }
    auto c = d.clone();
    chk("clone succeeds", static_cast<bool>(c));
    if (c) {
      chk("the clone compares equal", c.value() == d);
      chkn("the clone has its own storage", c.value()[7], 7);
      c.value()[7] = 99;
      chkn("writing the clone does not touch the original", d[7], 7);
    }
  }
  {
    std::deque<int> d;
    (void)d.push_back(5);
    auto good = d.at(0);
    chk("at in range succeeds", static_cast<bool>(good));
    auto bad = d.at(9);
    chk("at out of range fails", !static_cast<bool>(bad));
    if (!bad) {
      chk("at out of range says out_of_range",
          bad.error() == std::std_error::out_of_range);
    }
  }
#endif

  printf("\ncxx-deque-test: %d failure%s\n", fails, (1 == fails) ? "" : "s");
  return fails;
}
