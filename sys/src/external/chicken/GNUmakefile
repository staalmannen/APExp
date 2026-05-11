# GNUmakefile - toplevel makefile.  This simply includes the
# platform-specific makefile or quits when no platform is selected.
#
# Copyright (c) 2008-2022, The CHICKEN Team
# Copyright (c) 2007, Felix L. Winkelmann
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
# conditions are met:
#
#   Redistributions of source code must retain the above copyright notice, this list of conditions and the following
#     disclaimer. 
#   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
#     disclaimer in the documentation and/or other materials provided with the distribution. 
#   Neither the name of the author nor the names of its contributors may be used to endorse or promote
#     products derived from this software without specific prior written permission. 
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
# OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
# OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

# If nothing selected, use default config (this should set PLATFORM)
ifeq ($(CONFIG)$(PLATFORM),)
CONFIG=config.make
endif

ifneq ($(CONFIG),)
# Avoid loading config when building a boot-chicken
ifneq ($(MAKECMDGOALS),boot-chicken)
include $(CONFIG)
endif
endif

include Makefile.detect

ifndef PLATFORM
$(info Please select your target platform by running one of the following commands:)
$(info )
$(foreach mf, $(wildcard Makefile.*), $(info $(MAKE) PLATFORM=$(mf:Makefile.%=%)))
$(info )
$(info For more information, consult the README file.)
$(error No PLATFORM given.)
else
include $(SRCDIR)Makefile.$(PLATFORM)
endif
