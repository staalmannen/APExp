#!/usr/bin/python
#
# Utility script to generate .pc files for GLib
# for Visual Studio builds, to be used for
# building introspection files

# Author: Fan, Chun-wei
# Date: March 10, 2016

import os
import sys

from replace import replace_multi
from pc_base import BasePCItems

def main(argv):
    base_pc = BasePCItems()

    base_pc.setup(argv)
    croco_version = base_pc.version.split('.')
    pkg_replace_items = {'@LIBCROCO_MAJOR_VERSION@': croco_version[0],
                         '@LIBCROCO_MINOR_VERSION@': croco_version[1]}

    pkg_replace_items.update(base_pc.base_replace_items)

    # Generate libcroco-x.y.pc
    replace_multi(base_pc.top_srcdir + '/libcroco.pc.in',
                  base_pc.srcdir + '/libcroco-' + croco_version[0] +
                                   '.' + croco_version[1] + '.pc',
                  pkg_replace_items)

if __name__ == '__main__':
    sys.exit(main(sys.argv))
