/****************** "DHRYSTONE" Benchmark Program ***************************/
/*  File:       dhrystone.h
 *  Author:     Reinhold P. Weicker
 *              Siemens Nixdorf, Paderborn/Germany
 *              weicker@specbench.org
 */

#include "dhrystone.h"

#include <assert.h>  // For final verification
#include <limits.h>  // INT_MAX
#include <stdbool.h> // For bool
#include <stdint.h>  // C99 integers
#include <stdio.h>
#include <stdlib.h>  // For malloc, exit, atoi
#include <string.h>  // for strcpy, strcmp

#include "dhrystone.h"




extern  INT     Int_Glob;
extern  CHAR    Ch_1_Glob;


STORAGE_CLASS void POST_RET Proc_6 (Enumeration  Enum_Val_Par,
                                    Enumeration *Enum_Ref_Par) ATTRIBUTES
/*********************************/
    /* executed once */
    /* Enum_Val_Par == Ident_3, Enum_Ref_Par becomes Ident_2 */
{
  *Enum_Ref_Par = Enum_Val_Par;
  if (! Func_3 (Enum_Val_Par))
    /* then, not executed */
    *Enum_Ref_Par = Ident_4;
  switch (Enum_Val_Par)
  {
    case Ident_1: 
      *Enum_Ref_Par = Ident_1;
      break;
    case Ident_2: 
      if (Int_Glob > 100)
        /* then */
      *Enum_Ref_Par = Ident_1;
      else *Enum_Ref_Par = Ident_4;
      break;
    case Ident_3: /* executed */
      *Enum_Ref_Par = Ident_2;
      break;
    case Ident_4: break;
    case Ident_5: 
      *Enum_Ref_Par = Ident_3;
      break;
  } /* switch */
  PREVENT_INLINE(); // Gcc may occationally inline despite noinline. Put last not to affect stack allocation during invokation.
} /* Proc_6 */


STORAGE_CLASS void Proc_7 (One_Fifty       Int_1_Par_Val,
                           One_Fifty       Int_2_Par_Val,
                           One_Fifty      *Int_Par_Ref) ATTRIBUTES
/**********************************************/
    /* executed three times                                      */ 
    /* first call:      Int_1_Par_Val == 2, Int_2_Par_Val == 3,  */
    /*                  Int_Par_Ref becomes 7                    */
    /* second call:     Int_1_Par_Val == 10, Int_2_Par_Val == 5, */
    /*                  Int_Par_Ref becomes 17                   */
    /* third call:      Int_1_Par_Val == 6, Int_2_Par_Val == 10, */
    /*                  Int_Par_Ref becomes 18                   */
{
  One_Fifty Int_Loc;

  Int_Loc = Int_1_Par_Val + 2;
  *Int_Par_Ref = Int_2_Par_Val + Int_Loc;
  PREVENT_INLINE(); // Gcc may occationally inline despite noinline. Put last not to affect stack allocation during invokation.
} /* Proc_7 */


STORAGE_CLASS void POST_RET Proc_8 (Arr_1_Dim       Arr_1_Par_Ref,
                                    Arr_2_Dim       Arr_2_Par_Ref,
                                    INT             Int_1_Par_Val,
                                    INT             Int_2_Par_Val) ATTRIBUTES
/*********************************************************************/
    /* executed once      */
    /* Int_Par_Val_1 == 3 */
    /* Int_Par_Val_2 == 7 */
{
  REG One_Fifty Int_Index;
  REG One_Fifty Int_Loc;

  Int_Loc = Int_1_Par_Val + 5;
  Arr_1_Par_Ref [Int_Loc] = Int_2_Par_Val;
  Arr_1_Par_Ref [Int_Loc+1] = Arr_1_Par_Ref [Int_Loc];
  Arr_1_Par_Ref [Int_Loc+30] = Int_Loc;
  for (Int_Index = Int_Loc; Int_Index <= Int_Loc+1; ++Int_Index)
    Arr_2_Par_Ref [Int_Loc] [Int_Index] = Int_Loc;
  Arr_2_Par_Ref [Int_Loc] [Int_Loc-1] += 1;
  Arr_2_Par_Ref [Int_Loc+20] [Int_Loc] = Arr_1_Par_Ref [Int_Loc];
  Int_Glob = 5;
  PREVENT_INLINE();    // Gcc may occationally inline despite noinline. Put last not to affect stack allocation during invokation.
} /* Proc_8 */


STORAGE_CLASS Enumeration POST_RET Func_1 (Capital_Letter   Ch_1_Par_Val,
                                           Capital_Letter   Ch_2_Par_Val) ATTRIBUTES
/*************************************************/
    /* executed three times                                         */
    /* first call:      Ch_1_Par_Val == 'H', Ch_2_Par_Val == 'R'    */
    /* second call:     Ch_1_Par_Val == 'A', Ch_2_Par_Val == 'C'    */
    /* third call:      Ch_1_Par_Val == 'B', Ch_2_Par_Val == 'C'    */
{
  Capital_Letter        Ch_1_Loc;
  Capital_Letter        Ch_2_Loc;

  PREVENT_INLINE();    // Gcc may occationally inline despite noinline.

  Ch_1_Loc = Ch_1_Par_Val;
  Ch_2_Loc = Ch_1_Loc;
  if (Ch_2_Loc != Ch_2_Par_Val)
    /* then, executed */
    return (Ident_1);
  else  /* not executed */
  {
    Ch_1_Glob = Ch_1_Loc;
    return (Ident_2);
   }
} /* Func_1 */




STORAGE_CLASS bool POST_RET Func_2 (const Str_30  Str_1_Par_Ref,
                                       const Str_30  Str_2_Par_Ref) ATTRIBUTES
/*************************************************/
    /* executed once */
    /* Str_1_Par_Ref == "DHRYSTONE PROGRAM, 1'ST STRING" */
    /* Str_2_Par_Ref == "DHRYSTONE PROGRAM, 2'ND STRING" */
{
  REG One_Thirty        Int_Loc;
      Capital_Letter    Ch_Loc;

  PREVENT_INLINE();    // Gcc may occationally inline despite noinline.

  Int_Loc = 2;
  while (Int_Loc <= 2) /* loop body executed once */
    if (Func_1 (Str_1_Par_Ref[Int_Loc],
                Str_2_Par_Ref[Int_Loc+1]) == Ident_1)
      /* then, executed */
    {
      Ch_Loc = 'A';
      Int_Loc += 1;
    } /* if, while */
  if (Ch_Loc >= 'W' && Ch_Loc < 'Z')
    /* then, not executed */
    Int_Loc = 7;
  if (Ch_Loc == 'R')
    /* then, not executed */
    return (true);
  else /* executed */
  {
    if (strcmp (Str_1_Par_Ref, Str_2_Par_Ref) > 0)
      /* then, not executed */
    {
      Int_Loc += 7;
      Int_Glob = Int_Loc;
      return (true);
    }
    else /* executed */
      return (false);
  } /* if Ch_Loc */
} /* Func_2 */


STORAGE_CLASS bool POST_RET Func_3 (Enumeration Enum_Par_Val) ATTRIBUTES
/***************************/
    /* executed once        */
    /* Enum_Par_Val == Ident_3 */
{
  Enumeration Enum_Loc;

  PREVENT_INLINE(); // Gcc may occationally inline despite noinline.

  Enum_Loc = Enum_Par_Val;
  if (Enum_Loc == Ident_3)
    /* then, executed */
    return (true);
  else /* not executed */
    return (false);
} /* Func_3 */
