/****************** "DHRYSTONE" Benchmark Program ***************************/
/*  File:       main.c
 *  Author:     Reinhold P. Weicker
 *              Siemens Nixdorf, Paderborn/Germany
 *              weicker@specbench.org
 */

#include <assert.h>  // For final verification
#include <limits.h>  // INT_MAX
#include <stdbool.h> // For bool
#include <stdint.h>  // C99 integers
#include <stdio.h>
#include <stdlib.h>  // For malloc, exit, atoi
#include <string.h>  // for strcpy, strcmp

#include "dhrystone.h"


int main (int argc, const char *argv[])
/*****/
{
  INT Number_Of_Runs;
    
  /* Arguments */
  if (argc > 2)
  {
     printf ("Usage: %s [number of loops]\n", argv[0]);
     exit (1);
  }
  if (argc == 2)
  {
     int Number_Of_Runs_Param = atoi (argv[1]);
     if (Number_Of_Runs_Param >= MAX_INT) {
        fprintf(stderr, "ERROR: The selected int type %s with MAX_INT=%d is too small for the number of runs %d!\n", INTTYPENAME, MAX_INT, Number_Of_Runs_Param);
        exit (0);
     }
     Number_Of_Runs = Number_Of_Runs_Param;
  } else
  {
     Number_Of_Runs = NUMBER_OF_RUNS;
  }
  if (Number_Of_Runs <= 0)
  {
     Number_Of_Runs = NUMBER_OF_RUNS;
  }

  printf ("\n");
  printf ("Dhrystone Benchmark, Version %s\n", Version);
#ifdef OPTIMIZE
  const CHAR optlevel = OPTIMIZE;
#else
  const CHAR optlevel = 0;
#endif
  const char *optstring = NULL;
  switch (optlevel) {
  case 0:
    optstring = "none";
    break;
  case 1:
    optstring = "1";
    break;
  case 2:
    optstring = "2";
    break;
  case 3:
    optstring = "3";
    break;
  case 's':
    optstring = "size";
    break;
  }
  if (Reg)
  {
    printf ("Program compiled with 'register' attribute, optimization=%s, int=%s\n", optstring, INTTYPENAME);
  }
  else
  {
    printf ("Program compiled without 'register' attribute, optimization=%s, int=%s\n", optstring, INTTYPENAME);
  }
  printf ("Using %s, HZ=%d\n", CLOCK_TYPE, HZ);
  printf ("\n");
  
  Dhrystone(Number_Of_Runs);
}
