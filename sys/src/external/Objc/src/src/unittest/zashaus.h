
/*
 * Computer Algebra Kit (c) 1993,1994,2000 by David Stes.  All Rights Reserved.
 *
 * Copyright (c) 2000 David Stes.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Library General Public License as published 
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#include <cakit.h>

/* the name zashaus.h or Zassenhaus.h comes from the ecc package */
/* see sourceforge.net/projects/ecc */

id PolynomialModularFrobeniusTable(id X,int p,id P);
id PolynomialModularFrobenius(id a,id m,id frobtable);

id ModularFrobeniusNorm(id Q,int d,id P,id frobtable);
id ModularFrobeniusTrace(id Q,int d,id P,id frobtable);

id SeparateFactors(id list,id P,int d,int p,int mu,id frobtable);
id FactorDistinctDegree(id X,id P,int p,int mu);

