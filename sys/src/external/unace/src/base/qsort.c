#define INCL_BASE_QSORT

#include "base/includes.h"

tBASE_QSORT BASE_QSORT;

/*-----------------BASE_QSORT_XchgElements-------------------------------*/

void    BASE_QSORT_XchgElements(PUSHORT Var1, PUSHORT Var2)
{
USHORT Dummy;

  Dummy = *Var1;
  *Var1  = *Var2;
  *Var2  = Dummy;
}


/*-----------------BASE_QSORT_SortRange----------------------------------*/

void    BASE_QSORT_SortRange(INT Left, INT Right)
{
INT       NewLeft,
          NewRight;

  NewLeft  = Left;
  NewRight = Right;

  BASE_QSORT.Hyphen = BASE_QSORT.Frequencies[Right];

  do
  {
    while (BASE_QSORT.Frequencies[NewLeft] > BASE_QSORT.Hyphen)
    {
      NewLeft++;
    }

    while (BASE_QSORT.Frequencies[NewRight] < BASE_QSORT.Hyphen)
    {
      NewRight--;
    }

    if (NewLeft <= NewRight)
    {
      BASE_QSORT_XchgElements(&BASE_QSORT.Frequencies[NewLeft],
                              &BASE_QSORT.Frequencies[NewRight]);

      BASE_QSORT_XchgElements(&BASE_QSORT.Elements[NewLeft],
                              &BASE_QSORT.Elements[NewRight]);

      NewLeft++;
      NewRight--;
    }
  }
  while (NewLeft < NewRight);

  if (Left < NewRight)
  {
    if (Left < NewRight - 1)
    {
      BASE_QSORT_SortRange(Left, NewRight);
    }
    else
    {
      if (BASE_QSORT.Frequencies[Left] < BASE_QSORT.Frequencies[NewRight])
      {
        BASE_QSORT_XchgElements(&BASE_QSORT.Frequencies[Left],
                                &BASE_QSORT.Frequencies[NewRight]);

        BASE_QSORT_XchgElements(&BASE_QSORT.Elements[Left],
                                &BASE_QSORT.Elements[NewRight]);
      }
    }
  }

  if (Right > NewLeft)
  {
    if (NewLeft < Right - 1)
    {
      BASE_QSORT_SortRange(NewLeft, Right);
    }
    else
    {
      if (BASE_QSORT.Frequencies[NewLeft] < BASE_QSORT.Frequencies[Right])
      {
        BASE_QSORT_XchgElements(&BASE_QSORT.Frequencies[NewLeft],
                                &BASE_QSORT.Frequencies[Right]);

        BASE_QSORT_XchgElements(&BASE_QSORT.Elements[NewLeft],
                                &BASE_QSORT.Elements[Right]);
      }
    }
  }
}


/*-----------------BASE_QSORT_DoQuicksort--------------------------------*/

void    BASE_QSORT_DoQuicksort(INT NumberOfElements)
{
INT       I;

  for (I = NumberOfElements + 1; I--;)
  {
    BASE_QSORT.Elements[I] = I;
  }

  BASE_QSORT_SortRange(0, NumberOfElements);
}
