// go-readdir-probe.go -- does WALKING DIRECTORIES UNDER GC PRESSURE
// reproduce `go list std's crash, with none of `go list' around it?
//
//	go run go-readdir-probe.go
//	GOGC=off go run go-readdir-probe.go      # the control
//
// ***A PROBE: REPORT WHAT IT PRINTS, DO NOT ASSERT IT.*** Nobody has
// promised an answer, and the two outcomes send the hunt to different
// places.
//
// WHERE IT CAME FROM. `sys/lib/tests/go-ladder' is six of seven on
// this machine -- `go build', running the result, `go run', and
// `go test sort strings' all pass, which is upstream's own assertions
// against this compiler and runtime. The one failure is
// `go list std', and it is the garbage collector:
//
//	runtime: garbage collector found invalid heap pointer
//	  *(0x8c78680+0x88)=0x8d0fd50 span=0x8d0c000-0x0-0x8d10000 state=2
//
// READ THAT CAREFULLY, BECAUSE THE OBVIOUS READING IS WRONG. The
// triple is (start<<PageShift, s->limit, (start+npages)<<PageShift)
// from `mgc0.c:379', so `s->limit' is 0 -- and a first pass here
// treated that as the bug and went looking for who failed to set it.
// **`state=2' is `MSpanFree' (`malloc.h:404')**, and a free span
// having limit 0 is simply what a free span looks like. *The field
// that looked broken was the one field that was behaving.*
//
// What the message actually says is that a word in a goroutine's
// stack frame was scanned as a pointer and points into FREED memory.
// go1.4 scans stacks PRECISELY, so a non-pointer is scanned only if
// that frame's stack map claims the slot holds a pointer. The stack
// is `scanstack' -> `gentraceback' -> `scanframe', under
// `os.(*File).readdir' (`os/dir_plan9.go:15').
//
// TWO THINGS ARE ALREADY RULED OUT and neither should be re-checked:
//   - the COLLECTOR, by `go test sort strings' -- those binaries
//     allocate and collect freely and both are `ok'.
//   - the HEAP DATA, by `GOGC=off go list std', which prints 156
//     packages, the right number.
//
// SO THE QUESTION THIS ASKS is whether the Plan 9 readdir path alone
// reproduces it:
//
//   crashes here      -> `os/dir_plan9.go' and what it calls is the
//                        path, and the next step is the stack map of
//                        the functions in it.
//   completes here    -> the readdir path is innocent and something
//                        else in `go list std' -- `go/build', the
//                        package graph -- holds the frame that is
//                        scanned wrongly.
//
// AND IT CANNOT YET SAY WHOSE BUG IT IS. go1.4's plan9/amd64 port was
// new in that release and thinly exercised, so upstream is a live
// candidate beside our own toolchain -- `6g' and `6l' are built by
// this tree's `pcc', which this release found FOUR silent miscompiles
// in. *An unattributed failure on a barely-tested platform is not
// evidence about either one.*
//
// The control matters as much as the run: `GOGC=off' must COMPLETE. If
// it crashes too, the heap really is corrupt and everything above is
// the wrong frame for the question.

package main

import (
	"fmt"
	"os"
	"path/filepath"
	"runtime"
)

func main() {
	root := runtime.GOROOT() + "/src"
	fmt.Println("go-readdir-probe: walking", root)

	files, dirs := 0, 0
	err := filepath.Walk(root, func(p string, fi os.FileInfo, err error) error {
		if err != nil {
			return nil // unreadable entries are not what this asks about
		}
		if fi.IsDir() {
			dirs++
		} else {
			files++
		}
		// Collect often. `go list std' crashed partway through the
		// same walk, so the point is GC pressure DURING readdir
		// rather than at the end of it.
		if (files+dirs)%200 == 0 {
			runtime.GC()
		}
		return nil
	})

	fmt.Printf("go-readdir-probe: %d dirs, %d files, err = %v\n", dirs, files, err)
	fmt.Println("go-readdir-probe: completed without a GC fault")
}
