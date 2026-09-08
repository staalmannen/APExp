#!/bin/sh
# SPDX-FileCopyrightText: Stone Tickle <lattis@mochiro.moe>
# SPDX-License-Identifier: GPL-3.0-only

set -eux

if [ ! -d ~/.ssh ]; then
	exit 0
fi

cat >> ~/.ssh/config <<EOF
Host github.com
    IdentityFile ~/.ssh/9ba5eb75-1169-44f2-b69c-9f10d73de0d0
    IdentitiesOnly yes
    StrictHostKeyChecking no
EOF

chmod 600 ~/.ssh/config

git remote add github git@github.com:muon-build/meson-docs.git
git push --force --mirror github
