// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="new_selector.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_NEW_SELECTOR_H
#define PSTL_NEW_SELECTOR_H

#ifndef _LIBCPP_NEW
#  ifndef _NEW_
#    ifndef _NEW
#      ifndef SSDK_STL_NEW
#        include "new.h"
#      endif
#    endif
#  endif
#endif

#endif // PSTL_NEW_SELECTOR_H
