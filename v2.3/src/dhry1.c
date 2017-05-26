/****************** "DHRYSTONE" Benchmark Program ***************************/
/*  File:       dhrystone.h
 *  Author:     Reinhold P. Weicker
 *              Siemens Nixdorf, Paderborn/Germany
 *              weicker@specbench.org
 */
#include "dhrystone.h"

#include <assert.h>  // For final verification
#include <limits.h>  // INT_MAX
#include <stdint.h>  // C99 integers
#include <stdio.h>
#include <stdlib.h>  // For malloc, exit, atoi
#include <string.h>  // for strcpy, strcmp

/* Global Variables: */

Rec_Pointer     Ptr_Glob,
                Next_Ptr_Glob;
INT             Int_Glob;
bool            Bool_Glob;
CHAR            Ch_1_Glob,
                Ch_2_Glob;
INT             Arr_1_Glob [50];
INT             Arr_2_Glob [50] [50];

bool            Done;

/* start of variables for time measurement */

TIME            Begin_Time,
                End_Time,
                User_Time;
float           Microseconds,
                Dhrystones_Per_Second;


STORAGE_CLASS void POST_RET Dhrystone(INT number_Of_Runs) ATTRIBUTES
  /* main program, corresponds to procedures        */
  /* Main and Proc_0 in the Ada version             */
{
        One_Fifty       Int_1_Loc;
  REG   One_Fifty       Int_2_Loc;
        One_Fifty       Int_3_Loc;
  REG   CHAR            Ch_Index;
        Enumeration     Enum_Loc;
        Str_30          Str_1_Loc;
        Str_30          Str_2_Loc;
  REG   INT             Run_Index;
  REG   INT             Number_Of_Runs;

  _Static_assert (NUMBER_OF_RUNS < MAX_INT, "The selected int type " INTTYPENAME " is too small for the default number of runs!");

  /* Initializations */

  Next_Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));
  Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));

  Ptr_Glob->Ptr_Comp                    = Next_Ptr_Glob;
  Ptr_Glob->Discr                       = Ident_1;
  Ptr_Glob->variant.var_1.Enum_Comp     = Ident_3;
  Ptr_Glob->variant.var_1.Int_Comp      = 40;
  strcpy (Ptr_Glob->variant.var_1.Str_Comp,
          "DHRYSTONE PROGRAM, SOME STRING");
  strcpy (Str_1_Loc, "DHRYSTONE PROGRAM, 1'ST STRING");

  Arr_2_Glob [8][7] = 10;
        /* Was missing in published program. Without this statement,    */
        /* Arr_2_Glob [8][7] would have an undefined value.             */
        /* Warning: With 16-Bit processors and Number_Of_Runs > 32000,  */
        /* overflow may occur for this array element.                   */

  Number_Of_Runs = number_Of_Runs;
  Done = false;
  while (!Done) {

    /***************/
    /* Start timer */
    /***************/

    Start_Timer();

    for (Run_Index = 1; Run_Index <= Number_Of_Runs; ++Run_Index)
    {

      Proc_5();
      Proc_4();
      /* Ch_1_Glob == 'A', Ch_2_Glob == 'B', Bool_Glob == true */
      Int_1_Loc = 2;
      Int_2_Loc = 3;
      strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
      Enum_Loc = Ident_2;
      Bool_Glob = ! Func_2 (Str_1_Loc, Str_2_Loc);
      /* Bool_Glob == 1 */
      while (Int_1_Loc < Int_2_Loc)  /* loop body executed once */
      {
        Int_3_Loc = 5 * Int_1_Loc - Int_2_Loc;
        /* Int_3_Loc == 7 */
        Proc_7 (Int_1_Loc, Int_2_Loc, &Int_3_Loc);
       /* Int_3_Loc == 7 */
        Int_1_Loc += 1;
      } /* while */
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
      Proc_8 (Arr_1_Glob, Arr_2_Glob, Int_1_Loc, Int_3_Loc);
      /* Int_Glob == 5 */
      Proc_1 (Ptr_Glob);
      for (Ch_Index = 'A'; Ch_Index <= Ch_2_Glob; ++Ch_Index)
      /* loop body executed twice */
      {
        if (Enum_Loc == Func_1 (Ch_Index, 'C'))
        /* then, not executed */
        {
          Proc_6 (Ident_1, &Enum_Loc);
          strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 3'RD STRING");
          Int_2_Loc = Run_Index;
          Int_Glob = Run_Index;
        }
      }
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
      Int_2_Loc = Int_2_Loc * Int_1_Loc;
      Int_1_Loc = Int_2_Loc / Int_3_Loc;
      Int_2_Loc = 7 * (Int_2_Loc - Int_3_Loc) - Int_1_Loc;
      /* Int_1_Loc == 1, Int_2_Loc == 13, Int_3_Loc == 7 */
      Proc_2 (&Int_1_Loc);
      /* Int_1_Loc == 5 */

    } /* loop "for Run_Index" */

    /**************/
    /* Stop timer */
    /**************/

    Stop_Timer();

    User_Time = End_Time - Begin_Time;

    if (User_Time < Too_Small_Time)
    {
      // Measured time too small to obtain meaningful results

      if(Number_Of_Runs >= MAX_INT / 10) {
        fprintf(stderr, "ERROR: Unable to calculate dhrystone, since the target is too fast for the selected int size " INTTYPENAME ".\n");
        return;
      }

      Number_Of_Runs = Number_Of_Runs * 10;
      // Reset of globals Was missing in v2.2
      Int_Glob = 0;
      Bool_Glob = 0;
      Ch_1_Glob = 0;
      Ch_2_Glob = 0;
      memset(Arr_1_Glob, 0x00, sizeof(Arr_1_Glob));
      memset(Arr_2_Glob, 0x00, sizeof(Arr_2_Glob));
      Arr_2_Glob [8][7] = 10;
    } else Done = true;
  }

  verify_result(Number_Of_Runs,
                Int_1_Loc, Int_2_Loc, Int_3_Loc,
                Enum_Loc,
                Str_1_Loc, Str_2_Loc);
}

STORAGE_CLASS void POST_RET Proc_1 (REG Rec_Pointer Ptr_Val_Par) ATTRIBUTES
/******************/
    /* executed once */
{
  REG Rec_Pointer Next_Record = Ptr_Val_Par->Ptr_Comp;
                                        /* == Ptr_Glob_Next */
  /* Local variable, initialized with Ptr_Val_Par->Ptr_Comp,    */
  /* corresponds to "rename" in Ada, "with" in Pascal           */

  structassign (*Ptr_Val_Par->Ptr_Comp, *Ptr_Glob);
  Ptr_Val_Par->variant.var_1.Int_Comp = 5;
  Next_Record->variant.var_1.Int_Comp
        = Ptr_Val_Par->variant.var_1.Int_Comp;
  Next_Record->Ptr_Comp = Ptr_Val_Par->Ptr_Comp;
  Proc_3 (&Next_Record->Ptr_Comp);
    /* Ptr_Val_Par->Ptr_Comp->Ptr_Comp
                        == Ptr_Glob->Ptr_Comp */
  if (Next_Record->Discr == Ident_1)
    /* then, executed */
  {
    Next_Record->variant.var_1.Int_Comp = 6;
    Proc_6 (Ptr_Val_Par->variant.var_1.Enum_Comp,
           &Next_Record->variant.var_1.Enum_Comp);
    Next_Record->Ptr_Comp = Ptr_Glob->Ptr_Comp;
    Proc_7 (Next_Record->variant.var_1.Int_Comp, 10,
           &Next_Record->variant.var_1.Int_Comp);
  }
  else /* not executed */
    structassign (*Ptr_Val_Par, *Ptr_Val_Par->Ptr_Comp);
  PREVENT_INLINE();    // Gcc may occationally inline despite noinline. Put last not to affect stack allocation during invokation.
} /* Proc_1 */


STORAGE_CLASS void POST_RET Proc_2 (One_Fifty   *Int_Par_Ref) ATTRIBUTES
/******************/
    /* executed once */
    /* *Int_Par_Ref == 1, becomes 4 */
{
  One_Fifty  Int_Loc;
  Enumeration   Enum_Loc;

  Int_Loc = *Int_Par_Ref + 10;
  do /* executed once */
    if (Ch_1_Glob == 'A')
      /* then, executed */
    {
      Int_Loc -= 1;
      *Int_Par_Ref = Int_Loc - Int_Glob;
      Enum_Loc = Ident_1;
    } /* if */
  while (Enum_Loc != Ident_1); /* true */
  PREVENT_INLINE();    // Gcc may occationally inline despite noinline. Put last not to affect stack allocation during invokation.
} /* Proc_2 */


STORAGE_CLASS void POST_RET Proc_3 (Rec_Pointer *Ptr_Ref_Par) ATTRIBUTES
/******************/
    /* executed once */
    /* Ptr_Ref_Par becomes Ptr_Glob */
{
  if (Ptr_Glob != NULL)
    /* then, executed */
    *Ptr_Ref_Par = Ptr_Glob->Ptr_Comp;
  Proc_7 (10, Int_Glob, &Ptr_Glob->variant.var_1.Int_Comp);
  PREVENT_INLINE();    // Gcc may occationally inline despite noinline. Put last not to affect stack allocation during invokation.
} /* Proc_3 */


STORAGE_CLASS void POST_RET Proc_4 (void) ATTRIBUTES /* without parameters */
/*******/
    /* executed once */
{
  bool Bool_Loc;

  Bool_Loc = Ch_1_Glob == 'A';
  Bool_Glob = Bool_Loc | Bool_Glob;
  Ch_2_Glob = 'B';
  PREVENT_INLINE();    // Gcc may occationally inline despite noinline. Put last not to affect stack allocation during invokation.
} /* Proc_4 */


STORAGE_CLASS void POST_RET Proc_5 (void) ATTRIBUTES /* without parameters */
/*******/
    /* executed once */
{
  Ch_1_Glob = 'A';
  Bool_Glob = false;
  PREVENT_INLINE();    // Gcc may occationally inline despite noinline. Put last not to affect stack allocation during invokation.
} /* Proc_5 */


        /* Procedure for the assignment of structures,          */
        /* if the C compiler doesn't support this feature       */
#ifdef  NOSTRUCTASSIGN
inline void *memcpy (REG void * restrict d, REG const void * restrict s t, size_t l)
{
        while (l--) *d++ = *s++;
}
#endif
