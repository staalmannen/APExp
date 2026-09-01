# Config.pm for APExp -- hand-maintained, not generated.
#
# On a normal perl build Configure writes config.sh and configpm turns
# that into Config.pm, several thousand lines of it. APExp does not run
# Configure: sys/src/external/perl/config.h is answered by hand for
# kencc, and there is no config.sh for configpm to read. So this file is
# the companion to that config.h and has to be kept beside it -- if you
# change a value there that appears here, change it here too.
#
# The previous stub carried nine keys, enough for ExtUtils::Miniperl's
# writemain() and nothing else, and no functions at all, so
#
#	perl -V
#
# failed: perl.c:2356 runs "use Config; Config::_V()", and -V:name runs
# Config::config_vars. Both are below.
#
# %Config is a plain hash here. The real one is tied so that the values
# can be unpacked lazily from a compressed string; there is no reason to
# do that with this many keys, and a plain hash behaves the same for
# every use except Config->TIEHASH.
#
# What is deliberately absent: nothing describes dynamic loading,
# because Plan 9 has no dlopen. usedl is '', dlsrc is dl_none.xs, and
# so is ''. Anything that asks whether it can build an XS extension
# gets a truthful no.

package Config;

use strict;
use warnings;

our $VERSION = '5.042002';

# The keys are config.sh's names, which is what %Config is indexed by --
# not config.h's macro names. Where a value comes straight from
# config.h the macro is named in a comment.
our %Config = (
    # ---- identity ----
    package         => 'perl5',
    version         => '5.42.2',
    PERL_REVISION   => 5,
    PERL_VERSION    => 42,
    PERL_SUBVERSION => 2,
    api_revision    => 5,
    api_version     => 42,
    api_subversion  => 2,
    api_versionstring => '5.42.2',
    version_patchlevel_string => 'version 42 subversion 2',
    perl_patchlevel => '',
    revision        => 5,
    patchlevel      => 42,
    subversion      => 2,

    # ---- platform ----
    osname          => 'plan9',            # config.h OSNAME
    osvers          => '4',
    archname        => 'amd64-plan9-ld',   # config.h ARCHNAME
    myarchname      => 'amd64-plan9',
    myhostname      => '',
    myuname         => 'plan9 apexp amd64',
    byteorder       => '12345678',         # config.h BYTEORDER, little endian
    path_sep        => ':',
    prefix          => '',
    exe_ext         => '',
    obj_ext         => '.o',
    lib_ext         => '.a',
    _o              => '.o',
    _a              => '.a',
    _exe            => '',

    # ---- where things live ----
    # These must agree with config.h's PRIVLIB, ARCHLIB, SITELIB,
    # SITEARCH and BIN. @INC is built from them, so a disagreement
    # shows up as "Can't locate" for a module that is installed.
    privlib         => '/sys/lib/perl',
    privlibexp      => '/sys/lib/perl',
    archlib         => '/amd64/lib/ape',
    archlibexp      => '/amd64/lib/ape',
    sitelib         => '/sys/lib/perl',
    sitelibexp      => '/sys/lib/perl',
    sitearch        => '/amd64/lib/ape',
    sitearchexp     => '/amd64/lib/ape',
    vendorlib       => '',
    vendorlibexp    => '',
    vendorarch      => '',
    vendorarchexp   => '',
    installprivlib  => '/sys/lib/perl',
    installarchlib  => '/amd64/lib/ape',
    installsitelib  => '/sys/lib/perl',
    installsitearch => '/amd64/lib/ape',
    bin             => '/amd64/bin/ape',
    binexp          => '/amd64/bin/ape',
    installbin      => '/amd64/bin/ape',
    scriptdir       => '/amd64/bin/ape',
    scriptdirexp    => '/amd64/bin/ape',
    perlpath        => '/amd64/bin/ape/perl',
    startperl       => '#!/amd64/bin/ape/perl',
    sitebin         => '/amd64/bin/ape',
    inc_version_list => '',
    inc_version_list_init => '0',

    # ---- the compiler ----
    cc              => 'pcc',
    ccname          => 'pcc',
    ccversion       => '',
    gccversion      => '',
    cpp             => 'cpp',
    cppstdin        => 'cc  -E',           # config.h CPPSTDIN
    cppminus        => '',
    cppflags        => '-D_POSIX_SOURCE -DHAVE_CONFIG_H -D_PLAN9_SOURCE -D_BSD_EXTENSION',
    ccflags         => '-D_POSIX_SOURCE -DHAVE_CONFIG_H -D_PLAN9_SOURCE -D_BSD_EXTENSION',
    optimize        => '',
    ld              => 'pcc',
    ldflags         => '',
    lddlflags       => '',
    ccdlflags       => '',
    cccdlflags      => '',
    libs            => '',
    libswanted      => '',
    perllibs        => '',
    libperl         => 'libperl.a',
    libc            => '/amd64/lib/ape/libap.a',
    ar              => 'ar',
    full_ar         => '/bin/ar',
    ranlib          => ':',
    nm_opt          => '',
    make            => 'mk',

    # ---- type sizes: kencc, amd64 ----
    # long is 32 bits here even though pointers are 64, which is why
    # ivtype is long long rather than long.
    intsize         => 4,
    longsize        => 4,
    shortsize       => 2,
    ptrsize         => 8,                  # config.h PTRSIZE
    longlongsize    => 8,
    doublesize      => 8,                  # config.h DOUBLESIZE
    longdblsize     => 8,                  # kencc: long double is double
    longdblkind     => 0,
    ivtype          => 'long long',
    ivsize          => 8,                  # config.h IVSIZE
    uvtype          => 'unsigned long long',
    uvsize          => 8,
    nvtype          => 'double',           # config.h NVTYPE
    nvsize          => 8,                  # config.h NVSIZE
    nv_preserves_uv_bits => 53,
    i8type          => 'char',      i8size  => 1,
    u8type          => 'unsigned char',  u8size  => 1,
    i16type         => 'short',     i16size => 2,
    u16type         => 'unsigned short', u16size => 2,
    i32type         => 'int',       i32size => 4,
    u32type         => 'unsigned int',   u32size => 4,
    i64type         => 'long long', i64size => 8,
    u64type         => 'unsigned long long', u64size => 8,
    quadtype        => 'long long',
    uquadtype       => 'unsigned long long',
    quadkind        => 3,
    alignbytes      => 8,
    use64bitint     => 'define',           # config.h USE_64_BIT_INT
    use64bitall     => 'define',           # config.h USE_64_BIT_ALL
    uselongdouble   => '',                 # kencc has no long double
    usequadmath     => '',
    ivdformat       => '"lld"',
    uvuformat       => '"llu"',
    uvxformat       => '"llx"',
    uvXUformat      => '"llX"',
    uvoformat       => '"llo"',
    nvsize_str      => '8',

    # ---- what this perl is and is not ----
    useithreads     => '',
    usethreads      => '',
    useperlio       => 'define',
    usemymalloc     => 'n',
    usemultiplicity => '',
    useshrplib      => 'false',
    usesitecustomize => '',
    usecrosscompile => '',
    usedevel        => '',
    usedtrace       => '',
    usefaststdio    => '',
    usemallocwrap   => 'define',
    usenm           => '',
    usevendorprefix => '',
    default_inc_excludes_dot => 'define',

    # ---- dynamic loading: none ----
    # Plan 9 has no dlopen, so every extension must be linked in, and
    # xs_init in perlmain.c is empty. Anything probing for XS support
    # should get a no from these rather than try and fail later.
    usedl           => '',
    dlsrc           => 'dl_none.xs',
    dlext           => 'none',
    so              => '',
    d_dlopen        => '',
    d_dlsymun       => '',
    dlobj           => '',
    static_ext      => '',
    dynamic_ext     => '',
    nonxs_ext       => '',
    extensions      => '',
    known_extensions => '',

    # ---- a few d_* the core library actually reads ----
    d_fork          => 'define',
    d_vfork         => '',
    d_pipe          => 'define',
    d_waitpid       => 'define',
    d_symlink       => '',                 # Plan 9 has no symbolic links
    d_link          => 'define',
    d_readlink      => '',
    d_lstat         => '',
    d_flock         => '',
    d_fcntl         => 'define',
    d_fcntl_can_lock => '',
    d_setlocale     => 'define',
    d_getpgrp       => 'define',
    d_setpgrp       => 'define',
    d_sigaction     => 'define',
    d_sigprocmask   => 'define',
    d_socket        => 'define',
    d_select        => 'define',
    d_poll          => 'define',
    d_mmap          => '',
    d_statblks      => '',
    d_casti32       => 'define',
    d_castneg       => 'define',
    d_void_closedir => '',
    d_nv_preserves_uv => '',
    d_longdbl       => 'define',
    d_longlong      => 'define',
    d_stdstdio      => '',
    d_faststdio     => '',

    ccsymbols       => '',
    cppsymbols      => '',
    cppccsymbols    => '',
    config_args     => '(hand-written for APExp; Configure was not run)',
    config_argc     => 0,
    cf_by           => 'apexp',
    cf_time         => '',
    Author          => '',
    Date            => '$Date$',
    Header          => '',
    Id              => '$Id$',
    Locker          => '',
    Log             => '$Log$',
    RCSfile         => '$RCSfile$',
    Revision        => '$Revision$',
    Source          => '',
    State           => '',
    osvers_str      => '4',
);

# %Config is exported the way the real Config.pm does it, by aliasing
# the glob into the caller.
sub import {
    my $caller = caller;

    no strict 'refs';
    *{"${caller}::Config"} = \%Config;
    return;
}

# config_sh() gives back the config.sh text this would have come from.
# Sorted, so two runs agree.
sub config_sh {
    return join('', map { "$_='$Config{$_}'\n" } sort keys %Config);
}

sub config_re {
    my $re = shift;

    return map { "$_='$Config{$_}'" }
           grep { /$re/ } sort keys %Config;
}

# "perl -V:name", one or more names; a name in slashes is a pattern.
# Prints name='value'; per line, and undef for a key we do not have --
# which is honest, since this Config is partial by construction.
sub config_vars {
    foreach my $name (@_) {
        if ($name =~ m!^/(.*)/$!) {
            my $re = $1;
            foreach my $key (sort keys %Config) {
                next unless $key =~ /$re/;
                print "$key='$Config{$key}';\n";
            }
            next;
        }
        if (exists $Config{$name}) {
            print "$name='$Config{$name}';\n";
        }
        else {
            print "$name='UNKNOWN';\n";
        }
    }
    return;
}

sub myconfig {
    my $summary = <<'END';
Summary of my $package (revision $revision $version_patchlevel_string) configuration:

  Platform:
    osname=$osname
    osvers=$osvers
    archname=$archname
    uname='$myuname'
    config_args='$config_args'
    hint=none, useposix=true, d_sigaction=$d_sigaction
    useithreads=$useithreads, usemultiplicity=$usemultiplicity
    use64bitint=$use64bitint, use64bitall=$use64bitall, longdblsize=$longdblsize
    useperlio=$useperlio, d_sfio=undef, uselargefiles=define, usesocks=undef
    use64bitint=$use64bitint
  Compiler:
    cc='$cc'
    ccflags ='$ccflags'
    optimize='$optimize'
    cppflags='$cppflags'
    ccversion='$ccversion', gccversion='$gccversion'
    intsize=$intsize, longsize=$longsize, ptrsize=$ptrsize, doublesize=$doublesize
    d_longlong=$d_longlong, longlongsize=$longlongsize, d_longdbl=$d_longdbl, longdblsize=$longdblsize
    ivtype='$ivtype', ivsize=$ivsize, nvtype='$nvtype', nvsize=$nvsize
    alignbytes=$alignbytes, prototype=define
  Linker and Libraries:
    ld='$ld'
    ldflags ='$ldflags'
    libs=$libs
    perllibs=$perllibs
    libc=$libc
    so=$so, useshrplib=$useshrplib, libperl=$libperl
  Dynamic Linking:
    dlsrc=$dlsrc, dlext=$dlext, d_dlsymun=undef, ccdlflags='$ccdlflags'
    cccdlflags='$cccdlflags', lddlflags='$lddlflags'

END
    $summary =~ s{\$(\w+)}{ defined $Config{$1} ? $Config{$1} : 'undef' }ge;
    return $summary;
}

# What "perl -V" prints. perl.c:2356 calls this.
sub _V {
    print myconfig();
    print "Characteristics of this binary (from libperl):\n";
    print "  Built under $Config{osname}\n";
    print "  \@INC:\n";
    print "    $_\n" for @INC;
    return;
}

1;
