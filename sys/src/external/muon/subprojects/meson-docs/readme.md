# meson\_docs

This repo contains the documentation from the meson project along with refman
and a meson.build.  There are various muon-specific changes layered on top
including a few new documentation generators.

# syncing docs with upstream

1. Checkout the upstream branch of this repo.
2. Checkout the desired revision to sync to in the meson repo.
3. `cp -r path/to/meson/docs path/to/meson-docs`
4. Update version number in the `mesonbuild/coredata.py` stub.
5. Review and commit changes.
6. Switch back to master in the meson-docs repo.
7. Rebase: git rebase -i upstream. Resolve conflicts
8. Force push meson-docs and push muon
