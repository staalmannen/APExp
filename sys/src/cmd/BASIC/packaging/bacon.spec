Summary: BaCon - a free BASIC to C converter for Unix-based systems.
Name: bacon
Version: 4.8
Release: 1
License: MIT
Group: Development
Source: http://www.basic-converter.org/stable/bacon-4.8.tar.gz
URL: http://www.basic-converter.org
Distribution: CentOS 7
Vendor: Peter van Eerten
Packager: Peter van Eerten <peter@basic-converter.org>
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}
Requires: enscript

%description
BaCon intends to be a programming aid in creating tools which can be compiled
on different platforms (32bit and 64bit environments). It tries to revive the
days of the good old BASIC. Code converted by BaCon can be compiled by GCC,
the Compaq C Compiler, TCC or the clang/LLVM compiler. It can be compiled by
C++ compilers as well.

%prep
rm -rf ${RPM_BUILD_ROOT}
%setup

%build
./configure --prefix=/usr
make

%install
make DESTDIR=${RPM_BUILD_ROOT} install

%files
%doc CHANGES
/usr/share/man/man1/bacon.1.gz
/usr/bin/bacon
/usr/bin/bacon.sh
/usr/bin/bacongui-fltk
/usr/share/applications/bacongui-fltk.desktop
/usr/share/pixmaps/BaCon.png
/usr/share/pixmaps/BaCon.xbm
/usr/share/pixmaps/BaCon24.png
/usr/share/pixmaps/BaConEyes.png
/usr/share/pixmaps/BaConStrip.png
/usr/share/pixmaps/BaConLegacy.png
/usr/share/enscript/hl/bacon.st
/usr/share/BaCon/LICENSE.txt
/usr/share/BaCon/syntax/lower.m4
/usr/share/BaCon/syntax/upper.m4
/usr/share/BaCon/syntax/bacon.vim
/usr/share/BaCon/syntax/bacon.lang
/usr/share/BaCon/documentation/documentation.txt
/usr/share/BaCon/documentation/documentation.html
/usr/share/BaCon/documentation/doc_index.html
/usr/share/BaCon/documentation/doc_frame.html
