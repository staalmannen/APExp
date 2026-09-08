# meson-tests

This project contains tests from [meson/test cases].

## modifying tests

Don't forget to update muon/subprojcts/meson-tests.wrap with the sha1 of the new
HEAD.

## syncing tests with upstream

1. Checkout the `upstream` branch of this repo.
2. Checkout the desired revision to sync to in the meson repo.
3. Run `tools/update_tests.sh` from the muon repo:

```
tools/update_tests.sh -cf path/to/meson path/to/meson-tests
```

   This will format and copy all tests from the meson repo into the meson-tests
   repo.
4. Review and commit changes.  There shouldn't be any conflicts as this branch
   contains formatting changes only.
5. Switch back to `master` in the meson-tests repo.
6. Rebase: `git rebase -i upstream`.  Resolve conflicts
7. Update muon/tests/project/meson.build with the sha1 of the new HEAD.
8. Force push meson-tests and push muon

[meson/test cases]: https://github.com/mesonbuild/meson/tree/master/test%20cases
