Summary: Portable Object Compiler
Name: objc
Version: 3.3.41
Release: 1%{?dist}
Group: Applications/File
License: GPLv2+
Source: https://sourceforge.net/projects/objc/files/src/objc-%{version}.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

%description
The Portable Object Compiler, a language and a runtime library for producing C programs that operate by the runtime conventions of Smalltalk 80 in a UNIX environment, as described in Brad Cox's book on Objective-C.  Smalltalk and Objective-C offer Object Oriend Programming in which data, and the programs which may access it, are designed, built and maintained as inseparable units called objects.  The precompiler is backed by a library which supports Smalltalk 80's interpretation of messaging; binding of a message to its target routine is done at run time.  The library also contains a growing number of primitive class definitions, such as an Object class whose abilities are inherited by every object in the system and features such as Blocks, enclosures like in Smalltalk 80.

%prep
%setup -q
./configure OBJCDIR=%{_prefix} --prefix=$RPM_BUILD_ROOT%{_prefix}

%build

make compiler

%install

rm -rf $RPM_BUILD_ROOT
mkdir $RPM_BUILD_ROOT

make install
# motif-devel conflict on OpenSUSE 15.4
# rm -f $RPM_BUILD_ROOT%{_prefix}/share/man/man3objc/Object.3

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%{_bindir}/objc
%{_bindir}/objc1
%{_bindir}/cvtimport
%{_bindir}/postlink
%{_libdir}/objcrt.a
%{_libdir}/objpak.a
%{_libdir}/cakit.a
%{_libdir}/_prelink.o
%{_libdir}/_predll.o
%{_libdir}/objchelp.txt
%{_libdir}/objcdlso.ld
%{_prefix}/include/objcrt/OutOfMem.h
%{_prefix}/include/objcrt/Object.h
%{_prefix}/include/objcrt/objc.h
%{_prefix}/include/objcrt/Exceptn.h
%{_prefix}/include/objcrt/Message.h
%{_prefix}/include/objcrt/Block.h
%{_prefix}/include/objcrt/objcrt.h
%{_prefix}/include/cakit/cfloat.h
%{_prefix}/include/cakit/term.h
%{_prefix}/include/cakit/ccltn.h
%{_prefix}/include/cakit/matrix.h
%{_prefix}/include/cakit/polynom.h
%{_prefix}/include/cakit/cseq.h
%{_prefix}/include/cakit/intmodp.h
%{_prefix}/include/cakit/integer.h
%{_prefix}/include/cakit/ccomplex.h
%{_prefix}/include/cakit/monomial.h
%{_prefix}/include/cakit/cobject.h
%{_prefix}/include/cakit/symbol.h
%{_prefix}/include/cakit/cakit.h
%{_prefix}/include/cakit/vector.h
%{_prefix}/include/cakit/fraction.h
%{_prefix}/include/ppi/vectors.h
%{_prefix}/include/ppi/IPSequence.h
%{_prefix}/include/ppi/OrdCltn.h
%{_prefix}/include/ppi/String.h
%{_prefix}/include/ppi/SortCltn.h
%{_prefix}/include/ppi/Filer.h
%{_prefix}/include/ppi/IdArray.h
%{_prefix}/include/ppi/IntArray.h
%{_prefix}/include/ppi/Graph.h
%{_prefix}/include/ppi/Sequence.h
%{_prefix}/include/ppi/Array.h
%{_prefix}/include/ppi/mivarargs.h
%{_prefix}/include/ppi/StringCl.h
%{_prefix}/include/ppi/ICpak101.h
%{_prefix}/include/ppi/Assoc.h
%{_prefix}/include/objpak/set.h
%{_prefix}/include/objpak/outofbnd.h
%{_prefix}/include/objpak/rectangl.h
%{_prefix}/include/objpak/bag.h
%{_prefix}/include/objpak/array.h
%{_prefix}/include/objpak/ascfiler.h
%{_prefix}/include/objpak/idarray.h
%{_prefix}/include/objpak/cltn.h
%{_prefix}/include/objpak/unknownt.h
%{_prefix}/include/objpak/ordcltn.h
%{_prefix}/include/objpak/badvers.h
%{_prefix}/include/objpak/runarray.h
%{_prefix}/include/objpak/sortcltn.h
%{_prefix}/include/objpak/point.h
%{_prefix}/include/objpak/txtattr.h
%{_prefix}/include/objpak/ocstring.h
%{_prefix}/include/objpak/intarray.h
%{_prefix}/include/objpak/octext.h
%{_prefix}/include/objpak/paragrph.h
%{_prefix}/include/objpak/sequence.h
%{_prefix}/include/objpak/stack.h
%{_prefix}/include/objpak/dictnary.h
%{_prefix}/include/objpak/notfound.h
%{_prefix}/include/objpak/typeinc.h
%{_prefix}/include/objpak/objpak.h
%{_prefix}/include/objpak/txtstyle.h
%{_mandir}/man1/cvtimport.1.gz
%{_mandir}/man1/objc.1.gz
%{_mandir}/man1/postlink.1.gz
%{_mandir}/man1/vici.1.gz
%{_mandir}/man3objc/Array.3.gz
%{_mandir}/man3objc/AsciiFiler.3.gz
%{_mandir}/man3objc/BadVersion.3.gz
%{_mandir}/man3objc/Bag.3.gz
%{_mandir}/man3objc/BigInt.3.gz
%{_mandir}/man3objc/Block.3.gz
%{_mandir}/man3objc/CAObject.3.gz
%{_mandir}/man3objc/Cltn.3.gz
%{_mandir}/man3objc/Complex.3.gz
%{_mandir}/man3objc/Dictionary.3.gz
%{_mandir}/man3objc/Exception.3.gz
%{_mandir}/man3objc/Float.3.gz
%{_mandir}/man3objc/Fraction.3.gz
%{_mandir}/man3objc/IdArray.3.gz
%{_mandir}/man3objc/IntArray.3.gz
%{_mandir}/man3objc/IntegerModp.3.gz
%{_mandir}/man3objc/Matrix.3.gz
%{_mandir}/man3objc/Message.3.gz
%{_mandir}/man3objc/Monomial.3.gz
%{_mandir}/man3objc/NotFound.3.gz
# motif-devel conflict with Object.3
%{_mandir}/man3objc/Object.3.gz
%{_mandir}/man3objc/OrdCltn.3.gz
%{_mandir}/man3objc/OutOfBounds.3.gz
%{_mandir}/man3objc/OutOfMemory.3.gz
%{_mandir}/man3objc/Paragraph.3.gz
%{_mandir}/man3objc/Point.3.gz
%{_mandir}/man3objc/Polynomial.3.gz
%{_mandir}/man3objc/Rectangle.3.gz
%{_mandir}/man3objc/RunArray.3.gz
%{_mandir}/man3objc/Sequence.3.gz
%{_mandir}/man3objc/Set.3.gz
%{_mandir}/man3objc/SortCltn.3.gz
%{_mandir}/man3objc/Stack.3.gz
%{_mandir}/man3objc/String.3.gz
%{_mandir}/man3objc/Symbol.3.gz
%{_mandir}/man3objc/Term.3.gz
%{_mandir}/man3objc/Text.3.gz
%{_mandir}/man3objc/TextAttribute.3.gz
%{_mandir}/man3objc/TextStyle.3.gz
%{_mandir}/man3objc/TypeInconsistency.3.gz
%{_mandir}/man3objc/UnknownType.3.gz
%{_mandir}/man3objc/Vector.3.gz
%doc Beos.txt Books.txt Changes.txt Ibmvac.txt Install.txt Intro.txt Lcc.txt License.txt Mpw.txt Platform.txt Readme.txt Visual.txt Vms.txt Watcom.txt

%changelog
* Sat Oct  7 13:51:05 CEST 2023 David Stes <stes@telenet.be> 3.3.41
Update for 3.3.41

* Sat Feb 11 2023 David Stes <stes@telenet.be> 3.3.34
Update for 3.3.34, manpage Object.3 conflict with motif-devel

* Fri Nov 26 2021 David Stes <stes@telenet.be> 3.3.25
Update for 3.3.25

* Wed Mar 13 2019 David Stes <stes@telenet.be> 3.3.11
Update for 3.3.11

* Sun Dec 25 2016 David Stes <stes@telenet.be> 3.3.5
Update for 3.3.5

* Sat Aug 27 2016 David Stes <stes@telenet.be> 3.3.4
Update for 3.3.4

* Fri Dec 25 2015 David Stes <stes@telenet.be> 3.3.1
Update for 3.3.1

* Sat Sep 26 2015 David Stes <stes@telenet.be> 3.2.13
Copy spec file from example
