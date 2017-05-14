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

 INTFLAGS=""
 INT16FLAGS="-DINTTYPE=16"
 INT32FLAGS="-DINTTYPE=32"
 INT64FLAGS="-DINTTYPE=64"
 FAST16FLAGS="-DINTTYPE=-16"
 FAST32FLAGS="-DINTTYPE=-32"
 FAST64FLAGS="-DINTTYPE=-64"


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

#
# C99 integer types below:
#

echo "${CC}      -c ${CFLAGS} ${INT16FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${CFLAGS} ${INT16FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${CFLAGS} ${INT16FLAGS} $SRC dry1.o ${LFLAGS} -o dry2int16"
      ${CC} -DPASS2 ${CFLAGS} ${INT16FLAGS} $SRC dry1.o ${LFLAGS} -o dry2int16 || exit 1
./dry2int16 ${1-32000} 2>&1

echo "${CC}      -c ${CFLAGS} ${INT32FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${CFLAGS} ${INT32FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${CFLAGS} ${INT32FLAGS} $SRC dry1.o ${LFLAGS} -o dry2int32"
      ${CC} -DPASS2 ${CFLAGS} ${INT32FLAGS} $SRC dry1.o ${LFLAGS} -o dry2int32 || exit 1
./dry2int32 ${1-100000} 2>&1

echo "${CC}      -c ${CFLAGS} ${INT64FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${CFLAGS} ${INT64FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${CFLAGS} ${INT64FLAGS} $SRC dry1.o ${LFLAGS} -o dry2fast64"
      ${CC} -DPASS2 ${CFLAGS} ${INT64FLAGS} $SRC dry1.o ${LFLAGS} -o dry2fast64 || exit 1
./dry2fast64 ${1-100000} 2>&1

# ... and fast variant of them

echo "${CC}      -c ${CFLAGS} ${FAST16FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${CFLAGS} ${FAST16FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${CFLAGS} ${FAST16FLAGS} $SRC dry1.o ${LFLAGS} -o dry2fast16"
      ${CC} -DPASS2 ${CFLAGS} ${FAST16FLAGS} $SRC dry1.o ${LFLAGS} -o dry2fast16 || exit 1
./dry2fast16 ${1-32000} 2>&1

echo "${CC}      -c ${CFLAGS} ${FAST32FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${CFLAGS} ${FAST32FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${CFLAGS} ${FAST32FLAGS} $SRC dry1.o ${LFLAGS} -o dry2fast32"
      ${CC} -DPASS2 ${CFLAGS} ${FAST32FLAGS} $SRC dry1.o ${LFLAGS} -o dry2fast32 || exit 1
./dry2fast32 ${1-100000} 2>&1

echo "${CC}      -c ${CFLAGS} ${FAST64FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${CFLAGS} ${FAST64FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${CFLAGS} ${FAST64FLAGS} $SRC dry1.o ${LFLAGS} -o dry2fast64"
      ${CC} -DPASS2 ${CFLAGS} ${FAST64FLAGS} $SRC dry1.o ${LFLAGS} -o dry2fast64 || exit 1
./dry2fast64 ${1-100000} 2>&1

#
# C99 integer types with MAX optimization below:
#

echo "${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${INT16FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${INT16FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${INT16FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3int16"
      ${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${INT16FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3int16 || exit 1
./dry2o3int16 ${1-32000} 2>&1

echo "${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${INT32FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${INT32FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${INT32FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3int32"
      ${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${INT32FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3int32 || exit 1
./dry2o3int32 ${1-100000} 2>&1

echo "${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${INT64FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${INT64FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${INT64FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3fast64"
      ${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${INT64FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3fast64 || exit 1
./dry2o3fast64 ${1-100000} 2>&1

# ... and their fast counterparts

echo "${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${FAST16FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${FAST16FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${FAST16FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3fast16"
      ${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${FAST16FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3fast16 || exit 1
./dry2o3fast16 ${1-32000} 2>&1

echo "${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${FAST32FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${FAST32FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${FAST32FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3fast32"
      ${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${FAST32FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3fast32 || exit 1
./dry2o3fast32 ${1-100000} 2>&1

echo "${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${FAST64FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${FAST64FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${FAST64FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3fast64"
      ${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${FAST64FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3fast64 || exit 1
./dry2o3fast64 ${1-100000} 2>&1


rm -f dry1.o
 