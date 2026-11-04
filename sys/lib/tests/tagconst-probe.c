/*
 * tagconst-probe.c -- does a large link-time constant survive into the
 * linked binary?
 *
 *	6c -S tagconst-probe.c            # what the COMPILER emits
 *	6c -o tagconst-probe.6 tagconst-probe.c
 *	6l -l -a -o /dev/null tagconst-probe.6 | grep MOV   # what the LINKER emits
 *
 * ***ANSWERED, AND IT IS A REGRESSION TEST NOW.*** The right answer is
 *
 *	MOVQ	$subr_tab_data+281474976716536(SB),AX
 *
 * from both commands. Anything else is a regression; the three outcomes
 * below say which stage lost it.
 *
 * ***THE ANSWER WAS THE THIRD ONE, WHICH IS WHY THIS FILE EXISTS.***
 * The VM's `6c -S' already printed `+5880' -- so the object file and
 * the linker were both cleared by the first command, and the hunt moved
 * into the compiler. `cc/cc.h's `Node.xoffset' was `long', 32 bits
 * under kencc, and `6c/sgen.c:122's `xcom' folds `ADD(CONST,
 * ADDR(NAME))' into the NAME with `l->xoffset += r->vconst'. The
 * CONTROL is the measurement that names the field: narrow `xoffset' to
 * `int' in a HOST build and this probe prints `+5880', restore it and
 * it prints the full constant. *The two other candidates -- `naddr's
 * local `v' and the `zaddr' writer -- were refuted the same way, by
 * narrowing them and finding the output unchanged.*
 *
 * ***A PROBE WITH THREE OUTCOMES RATHER THAN TWO.*** Report all
 * three lines; the pair is the measurement, because compiler and linker
 * can each lose the constant on their own and the symptom is identical.
 *
 *   compiler MOVQ $sym+281474976716536(SB)
 *   linker   MOVQ $sym+281474976716536(SB), 10 bytes 48 B8 ... 01 00
 *                                     -- both correct
 *   compiler MOVQ $sym+281474976716536(SB)
 *   linker   MOVL $<small>                -- the LINKER truncated
 *   compiler MOVQ $sym+281474976716536(SB)
 *   linker   MOVQ $sym+5880(SB)           -- the OBJECT FILE truncated,
 *                                            i.e. `6c/swt.c's zaddr
 *
 * WHERE IT CAME FROM. clisp's `lisp.run' died in `init_reader' because
 * `funcall(L(make_hash_table),4)' was handed something `funcall' did
 * not recognise as a function. `L()' builds a SUBR object as
 * `&subr_tab_data.D_make_hash_table + (subr_type << 48)', so the type
 * tag is a LINK-TIME CONSTANT with bit 48 set -- and `acid: asm()' on
 * the running binary showed
 *
 *	allocate_syntax_table+0x44   MOVL $0x41d5b0,BP
 *
 * where `6c -S' for the same line is
 *
 *	MOVQ $subr_tab_data+281474976722416(SB),BP
 *
 * 281474976722416 is (1<<48) + 0x2DF0. The tag is in the compiler's
 * output and gone from the linked code: every CLISP object built this
 * way arrives untyped.
 *
 * WHAT IS ALREADY RULED OUT, on the build host with
 * `sys/lib/tests/hostkencc' plus a host-built `6l':
 *
 *   - `6c/swt.c's `zaddr' WRITER: it sets `T_64' correctly once `l' is
 *     `int'.  **It was `long', which is a host-build bug and not a
 *     Plan 9 one** -- on kencc `long' is already 32 bits, so the
 *     truncation test worked there.  Fixed anyway, in 6c, 7c and 9c.
 *   - `6l/obj.c's `zaddr' READER: honours T_64.
 *   - `6l/span.c's `vaddr': computes in `vlong'.
 *   - `6l/span.c's `oclass': returns `Yi64' (measured, instrumented) for
 *     exactly this operand, and `optab.c's `ymovq' has
 *     `Yi64,Yrl,Ziq_rp', whose `Ziq_rp' emits `48 B8 +r io' with
 *     `put8'.  **The two `return Yi32' lines in `oclass' carrying an
 *     upstream "TO DO: Yi64" comment are NOT on this path**, which is
 *     worth knowing because they look exactly like the bug and are not
 *     it.  *(Written without the inner comment on purpose: a `*''/'
 *     inside a block comment ends it, which broke this very file on its
 *     first compile -- the same slip `cmd/clisp/config.h' made with
 *     `arch/*''/fenv.s'.)*
 *
 * So a host-built toolchain gets this RIGHT end to end. The VM does
 * not. The remaining difference is that the toolchain itself is
 * compiled by kencc there, where `long' is 32 bits -- so the next thing
 * to find is a `long` inside it holding something 64 bits wide. *This
 * probe is what separates "the object file lost it" from "the encoder
 * lost it" without reading any more source* -- and it answered a
 * question neither of those was: `6c' never put the constant in the
 * object file at all.
 *
 * ***THE LINE ABOVE SAID `6l' AND THE FIELD WAS IN `6c'.*** The guess
 * was reasonable -- the linker was the one component still built by
 * kencc that had not been read -- and it was wrong, and the probe's
 * FIRST command settled it in one line. *Which is the argument for
 * running the cheap measurement before the plausible reading.*
 *
 * It needs no headers and no libc, which is why `6l -l' can link it.
 */

typedef unsigned long long uint64;

struct big { long a[8000]; };
extern struct big subr_tab_data;

/* exactly the shape of CLISP's L(name): address + (tag << 48) */
void *
tagconst(void)
{
	return (unsigned char*)&subr_tab_data.a[1470] + ((uint64)1 << 48);
}

/*
 * SECOND CASE, AND IT IS A SECOND QUESTION RATHER THAN A RESTATEMENT.
 * `tagconst' asks whether the constant can be PRODUCED. This asks
 * whether it can be COMPARED, which on x86-64 is a different question
 * with a different answer: there is a `MOV r64, imm64' and there is
 * no `CMP r64, imm64'.
 *
 * `6c -S' emits
 *
 *	CMPQ	BP,$subr_tab_data+281474976716536(SB)
 *
 * which is not an instruction. `6l/span.c's `oclass' returns `Yi32'
 * for `$sym+off(SB)' whatever the offset -- the line carries its own
 * `TO DO: Yi64' -- and `optab.c's `ycmpl' has rows for `Yi8' and
 * `Yi32' only, so `Zm_ilo' calls `put4' and **thirty-two bits are
 * written with no diagnostic**.
 *
 * WHERE IT CAME FROM. clisp's `nullp(obj)' is `eq(obj,NIL)' and `NIL'
 * is `type_constpointer_object(symbol_type,&symbol_tab.S_nil)' -- the
 * same address-plus-tag shape as `L()', with the tag at bit 50. So
 * `endp' answered "not NIL" for NIL, every list looked dotted, and
 * `nreverse' in `init_packages' walked off the end. *Before `xoffset'
 * was widened both sides of that comparison were truncated and matched
 * each other*, which is why fixing the compiler moved the failure
 * EARLIER -- this tree's rule about a fix reaching code nothing reached
 * before, arriving as a comparison that had been wrong in a way that
 * cancelled.
 *
 * READ THE LINKER LINE, NOT THE COMPILER LINE, FOR THIS CASE. The
 * compiler is entitled to write the constant; the question is what the
 * encoder does with it, and the two answers are
 *
 *   CMPQ ... , 7 bytes  48 81 FD xx xx xx xx   -- truncated to imm32
 *   MOVQ $...,R11 then CMPQ BP,R11             -- correct
 */
int
tagcmp(void *p)
{
	return p == (void*)((unsigned char*)&subr_tab_data.a[1470]
	                    + ((uint64)1 << 48));
}
