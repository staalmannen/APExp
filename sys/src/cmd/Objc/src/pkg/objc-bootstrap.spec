Summary: Bootstrap for Portable Object Compiler
Name: objc-bootstrap
Version: 3.3.38
Release: 1%{?dist}
Group: Applications/File
License: GPLv2+
Source: https://sourceforge.net/projects/objc/files/src/objc-bootstrap-%{version}.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

# redefine the default _prefix /usr to /opt/objc-boostrap
# the actual compiler is installed with the default /usr prefix
# but this is just the bootstrap compiler for compiling the real compiler
# when no previous objc rpm package exists
%define _prefix /opt/objc-bootstrap

%description
Package for bootstrapping the Portable Object Compiler when there is no previous package of the Portable Object Compiler available in a repository.

%prep
%setup -q
./configure OBJCDIR=%{_prefix} --prefix=$RPM_BUILD_ROOT%{_prefix}

%build

make

%install

rm -rf $RPM_BUILD_ROOT
mkdir $RPM_BUILD_ROOT
mkdir $RPM_BUILD_ROOT/opt
mkdir $RPM_BUILD_ROOT/opt/objc-bootstrap

make install

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%{_bindir}/objc
%{_bindir}/objc1
%{_bindir}/postlink
%{_libdir}/_prelink.o

%changelog
* Sat Feb 11 2023 David Stes <stes@telenet.be> 3.3.32
Use _prefix /opt/objc-bootstrap for bootstrap compiler

