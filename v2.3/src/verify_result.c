/****************** "DHRYSTONE" Benchmark Program ***************************/
/*  File:       verify_result.c
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

#ifdef __DHRY_EMBEDDED
  #define fprintf(x,y) __DRHY_FPRINTF
#endif


void verify_result(REG INT            Number_Of_Runs,
                       One_Fifty      Int_1_Loc,
                   REG One_Fifty      Int_2_Loc,
                       One_Fifty      Int_3_Loc,
                       Enumeration    Enum_Loc,
                       Str_30         Str_1_Loc,
                       Str_30         Str_2_Loc)
{
#ifdef NDEBUG
  fprintf (stderr, "Final values of the variables used in the benchmark:\n");
  fprintf (stderr, "\n");
  fprintf (stderr, "Int_Glob:            %d\n", Int_Glob);
  fprintf (stderr, "        should be:   %d\n", 5);
  fprintf (stderr, "Bool_Glob:           %d\n", Bool_Glob);
  fprintf (stderr, "        should be:   %d\n", 1);
  fprintf (stderr, "Ch_1_Glob:           %c\n", Ch_1_Glob);
  fprintf (stderr, "        should be:   %c\n", 'A');
  fprintf (stderr, "Ch_2_Glob:           %c\n", Ch_2_Glob);
  fprintf (stderr, "        should be:   %c\n", 'B');
  fprintf (stderr, "Arr_1_Glob[8]:       %d\n", Arr_1_Glob[8]);
  fprintf (stderr, "        should be:   %d\n", 7);
  fprintf (stderr, "Arr_2_Glob[8][7]:    %d\n", Arr_2_Glob[8][7]);
  fprintf (stderr, "        should be:   Number_Of_Runs + 10\n");
  fprintf (stderr, "        should be:   %d\n", Number_Of_Runs + 10);
  fprintf (stderr, "Ptr_Glob->\n");
  fprintf (stderr, "  Ptr_Comp:          %p\n", Ptr_Glob->Ptr_Comp);
  fprintf (stderr, "        should be:   (implementation-dependent)\n");
  fprintf (stderr, "  Discr:             %d\n", Ptr_Glob->Discr);
  fprintf (stderr, "        should be:   %d\n", 0);
  fprintf (stderr, "  Enum_Comp:         %d\n", Ptr_Glob->variant.var_1.Enum_Comp);
  fprintf (stderr, "        should be:   %d\n", 2);
  fprintf (stderr, "  Int_Comp:          %d\n", Ptr_Glob->variant.var_1.Int_Comp);
  fprintf (stderr, "        should be:   %d\n", 17);
  fprintf (stderr, "  Str_Comp:          %s\n", Ptr_Glob->variant.var_1.Str_Comp);
  fprintf (stderr, "        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  fprintf (stderr, "Next_Ptr_Glob->\n");
  fprintf (stderr, "  Ptr_Comp:          %p\n", Next_Ptr_Glob->Ptr_Comp);
  fprintf (stderr, "        should be:   (implementation-dependent), same as above\n");
  fprintf (stderr, "  Discr:             %d\n", Next_Ptr_Glob->Discr);
  fprintf (stderr, "        should be:   %d\n", 0);
  fprintf (stderr, "  Enum_Comp:         %d\n", Next_Ptr_Glob->variant.var_1.Enum_Comp);
  fprintf (stderr, "        should be:   %d\n", 1);
  fprintf (stderr, "  Int_Comp:          %d\n", Next_Ptr_Glob->variant.var_1.Int_Comp);
  fprintf (stderr, "        should be:   %d\n", 18);
  fprintf (stderr, "  Str_Comp:          %s\n",
                                Next_Ptr_Glob->variant.var_1.Str_Comp);
  fprintf (stderr, "        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  fprintf (stderr, "Int_1_Loc:           %d\n", Int_1_Loc);
  fprintf (stderr, "        should be:   %d\n", 5);
  fprintf (stderr, "Int_2_Loc:           %d\n", Int_2_Loc);
  fprintf (stderr, "        should be:   %d\n", 13);
  fprintf (stderr, "Int_3_Loc:           %d\n", Int_3_Loc);
  fprintf (stderr, "        should be:   %d\n", 7);
  fprintf (stderr, "Enum_Loc:            %d\n", Enum_Loc);
  fprintf (stderr, "        should be:   %d\n", 1);
  fprintf (stderr, "Str_1_Loc:           %s\n", Str_1_Loc);
  fprintf (stderr, "        should be:   DHRYSTONE PROGRAM, 1'ST STRING\n");
  fprintf (stderr, "Str_2_Loc:           %s\n", Str_2_Loc);
  fprintf (stderr, "        should be:   DHRYSTONE PROGRAM, 2'ND STRING\n");
  fprintf (stderr, "\n");
#else
    assert(Int_Glob == 5);
    assert(Bool_Glob == true);
    assert(Ch_1_Glob == 'A');
    assert(Ch_2_Glob == 'B');
    assert(Arr_1_Glob[8] == 7);
    assert(Arr_2_Glob[8][7] == Number_Of_Runs+10);
    // assert((int) Ptr_Glob->Ptr_Comp == 816); //  (implementation-dependent)
    assert(Ptr_Glob->Discr == 0);
    assert(Ptr_Glob->variant.var_1.Enum_Comp == 2);
    assert(Ptr_Glob->variant.var_1.Int_Comp == 17);
    assert(strcmp(Ptr_Glob->variant.var_1.Str_Comp, "DHRYSTONE PROGRAM, SOME STRING") == 0);
    //assert((int) Next_Ptr_Glob->Ptr_Comp == 816); //  (implementation-dependent)
    assert(Next_Ptr_Glob->Discr == 0);
    assert(Next_Ptr_Glob->variant.var_1.Enum_Comp == 1);
    assert(Next_Ptr_Glob->variant.var_1.Int_Comp == 18);
    assert(strcmp(Next_Ptr_Glob->variant.var_1.Str_Comp, "DHRYSTONE PROGRAM, SOME STRING") == 0);
    assert(Int_1_Loc == 5);
    assert(Int_2_Loc == 13);
    assert(Int_3_Loc == 7);
    assert(strcmp(Str_1_Loc, "DHRYSTONE PROGRAM, 1'ST STRING") == 0);
    assert(strcmp(Str_2_Loc, "DHRYSTONE PROGRAM, 2'ND STRING") == 0);
#endif // NDEBUG
  Microseconds = (float) User_Time * Mic_secs_Per_Second
                      / ((float) HZ * ((float) Number_Of_Runs));
  Dhrystones_Per_Second = ((float) HZ * (float) Number_Of_Runs)
                      / (float) User_Time;

  // No longer applicable due to the high speed of today's CPU's:
  // printf ("Microseconds for one run through Dhrystone: ");
  // printf ("%10.1f \n", Microseconds);
  printf ("Dhrystones per Second:                      ");
  printf ("%10.0f\n", Dhrystones_Per_Second);
  printf ("Required number of rounds:                  %10.0fk\n", (float)Number_Of_Runs/1000);
}
