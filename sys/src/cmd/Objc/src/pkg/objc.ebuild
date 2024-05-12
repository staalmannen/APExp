# Copyright 2020 Gentoo Authors
# Distributed under the terms of the GNU General Public License v2

EAPI=7

DESCRIPTION="Portable Object Compiler"
HOMEPAGE="http://objc.sourceforge.net"
SRC_URI="https://sourceforge.net/projects/objc/files/src/objc-3.3.30.tar.gz"

LICENSE="LGPL-2"
SLOT="0"
KEYWORDS="*"
IUSE=""

DEPEND=""
RDEPEND="${DEPEND}"
BDEPEND=""

# Gentoo unistd.h has fortify garbage in it, set LEX="flex --nounistd"
# Gentoo assumes --prefix=/usr and DESTDIR=${D}, we do it other way around
src_configure() {
   if [ ! -z "${D}" ]
   then
     mkdir -p ${D}/usr
     LEX="flex --nounistd" OBJCDIR=/usr econf --prefix=${D}/usr
   fi
}

