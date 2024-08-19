$! Portable Object Compiler (c) 1997,98,99.  All Rights Reserved.
$! 
$! Compiler driver for OpenVMS.  Contributed by Pierre.Bru@spotimage.fr
$!
$ CC		:= CC
$ CFLAGS	:= /NOLIST
$ PFLAGS	:= /PREPROCESS_ONLY/DEFINE=(__PORTABLE_OBJC__,"""alloca=malloc""")/INCLUDE=OC_INCLUDE_DIRECTORY
$!OBJC1		:= OBJC1
$ OBJC1FLAGS	:= """-quiet"" ""-vms"" ""-init"" ""_objcInit"""
$
$ Source = P1
$ Source_Name = F$Parse(Source,,,"name")
$ Target_Name = F$Parse(Source,,,"name")
$
$ 'CC''PFLAGS' 'Source_Name'.M
$  OBJC1 'OBJC1FLAGS' 'Source_Name'.I 'Target_Name'.C
$ 'CC''CFLAGS' 'Source_Name'.C
