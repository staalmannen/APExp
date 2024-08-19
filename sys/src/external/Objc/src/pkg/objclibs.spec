Summary: Portable Object Compiler Shared Libraries
Name: objclibs
Version: 3.3.41
Release: 1%{?dist}
Group: Applications/File
License: GPLv2+
Source: https://sourceforge.net/projects/objc/files/src/objc-%{version}.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

%description
Shared Libraries for the Portable Object Compiler.

%prep
%setup -q -n objc-%{version}
./configure OBJCDIR=%{_prefix} --prefix=$RPM_BUILD_ROOT%{_prefix} EXTRA_MFLAGS=-fPIC

%build

make shlib

%install

rm -rf $RPM_BUILD_ROOT
mkdir $RPM_BUILD_ROOT

make installshlib

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%{_libdir}/libobjcrt.so
%{_libdir}/libobjpak.so

%changelog
* Sat Oct  7 13:52:10 CEST 2023 David Stes <stes@telenet.be> 3.3.41
Update for 3.3.41

* Wed Mar 13 2019 David Stes <stes@telenet.be> 3.3.11
Create for objc-3.3.11 as a separate package (currently not required for objc)

