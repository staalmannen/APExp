#!/bin/sh
# SPDX-FileCopyrightText: Stone Tickle <lattis@mochiro.moe>
# SPDX-License-Identifier: GPL-3.0-only

set -eux

if [ ! -d ~/.ssh ]; then
	exit 0
fi

cat >> ~/.ssh/config <<EOF
Host github.com
    IdentityFile ~/.ssh/ead807ad-2453-416b-8ae6-308363891a8d
    IdentitiesOnly yes
    StrictHostKeyChecking no
EOF

chmod 600 ~/.ssh/config

git remote add github git@github.com:muon-build/meson-tests.git
git push --force --mirror github
