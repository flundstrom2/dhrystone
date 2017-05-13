#!/bin/bash

      SRC=dhry1.c
       CC=gcc
 GCCFLAGS="-Wno-pointer-to-int-cast -fno-inline -fno-inline-functions"
   CFLAGS="${CFLAGS} -std=c99"
   CFLAGS="${CFLAGS} ${GCCFLAGS}"
  #CFLAGS="${CFLAGS} -DNDEBUG"                                                      # Print algorithm results
OPT1FLAGS="-O1 -DOPTIMIZE=1"                                                        # -O1 equals -O on gcc.
OPT2FLAGS="-O2 -DOPTIMIZE=2"
OPT3FLAGS="-O3 -DOPTIMIZE=3"
OPTsFLAGS="-Os -DOPTIMIZE='s'"

echo "${CC}      -c ${CFLAGS} $SRC -o dry1.o"
      ${CC}      -c ${CFLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${CFLAGS} $SRC dry1.o ${LFLAGS} -o dry2"
      ${CC} -DPASS2 ${CFLAGS} $SRC dry1.o ${LFLAGS} -o dry2 || exit 1
./dry2 ${1-100000}

echo "${CC}      -c -DREG ${CFLAGS} $SRC -o dry1.o"
      ${CC}      -c -DREG ${CFLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 -DREG ${CFLAGS} $SRC dry1.o ${LFLAGS} -o dry2nr"
      ${CC} -DPASS2 -DREG ${CFLAGS} $SRC dry1.o ${LFLAGS} -o dry2nr || exit 1
./dry2nr ${1-100000}

echo "${CC}      -c ${OPT1FLAGS} ${CFLAGS} $SRC -o dry1.o"
      ${CC}      -c ${OPT1FLAGS} ${CFLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${OPT1FLAGS} ${CFLAGS} $SRC dry1.o ${LFLAGS} -o dry2o1"
      ${CC} -DPASS2 ${OPT1FLAGS} ${CFLAGS} $SRC dry1.o ${LFLAGS} -o dry2o1 || exit 1
./dry2o1 ${1-100000}

echo "${CC}      -c ${OPT2FLAGS} ${CFLAGS} $SRC -o dry1.o"
      ${CC}      -c ${OPT2FLAGS} ${CFLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${OPT2FLAGS} ${CFLAGS} $SRC dry1.o ${LFLAGS} -o dry2o2"
      ${CC} -DPASS2 ${OPT2FLAGS} ${CFLAGS} $SRC dry1.o ${LFLAGS} -o dry2o2 || exit 1
./dry2o2 ${1-100000}

echo "${CC}      -c ${OPT3FLAGS} ${CFLAGS} $SRC -o dry1.o"
      ${CC}      -c ${OPT3FLAGS} ${CFLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3"
      ${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3 || exit 1
./dry2o3 ${1-100000}

echo "${CC}      -c ${OPTsFLAGS} ${CFLAGS} $SRC -o dry1.o"
      ${CC}      -c ${OPTsFLAGS} ${CFLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${OPTsFLAGS} ${CFLAGS} $SRC dry1.o ${LFLAGS} -o dry2os"
      ${CC} -DPASS2 ${OPTsFLAGS} ${CFLAGS} $SRC dry1.o ${LFLAGS} -o dry2os || exit 1
./dry2os ${1-100000}

rm -f dry1.o
 