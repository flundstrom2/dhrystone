#!/bin/bash

    DHRY1=dhry1
    DHRY2=dhry2
     MAIN=main
   VERIFY=verify_result
       CC=gcc
      OUT=../out/
      EXE=dry2
  POSTFIX=xx
            
 GCCFLAGS="-fno-inline -fno-inline-functions"
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

function compile {
  POSTFIX=$1
  OPTFLAGS=$2
  INTFLAGS=$3
  FLAGS="${OPTFLAGS} ${INTFLAGS} ${CFLAGS}"
  CMD="${CC}      -c ${FLAGS} ${DHRY1}.c  -o ${OUT}${DHRY1}.o"  ; echo ${CMD} ; ${CMD} || exit 1
  CMD="${CC}      -c ${FLAGS} ${DHRY2}.c  -o ${OUT}${DHRY2}.o"  ; echo ${CMD} ; ${CMD} || exit 1
  CMD="${CC}      -c ${FLAGS} ${VERIFY}.c -o ${OUT}${VERIFY}.o" ; echo ${CMD} ; ${CMD} || exit 1
  CMD="${CC}      -c ${FLAGS} ${MAIN}.c   -o ${OUT}${MAIN}.o"   ; echo ${CMD} ; ${CMD} || exit 1
  CMD="${CC}         ${FLAGS} ${OUT}${DHRY1}.o ${OUT}${DHRY2}.o ${OUT}${VERIFY}.o ${OUT}${MAIN}.o ${LFLAGS} -o ${OUT}${CC}${EXE}${POSTFIX}" ; echo ${CMD} ; ${CMD} || exit 1
  ${OUT}${CC}${EXE}${POSTFIX} ${1-100000}
}

#
# C99 Baseline usint default int:
#

compile

# ... with various optimization levels:
 
compile R  -DREG
compile O1 ${OPT1FLAGS}
compile O2 ${OPT2FLAGS}
compile O3 ${OPT3FLAGS}
compile Os ${OPTsFLAGS}

#
# C99 integer types below:
#

compile I16 ${INT16FLAGS}
compile I32 ${INT32FLAGS}
compile I64 ${INT64FLAGS}

# ... and fast variant of them
                   
compile F16 ${FAST16FLAGS}
compile F32 ${FAST32FLAGS}
compile F64 ${FAST64FLAGS}

#
# C99 integer types with MAX optimization below:
#

compile O3I16 ${OPT3FLAGS} ${INT16FLAGS}
compile O3I32 ${OPT3FLAGS} ${INT21FLAGS}
compile O3I64 ${OPT3FLAGS} ${INT64FLAGS}

# ... and their fast counterparts

compile O3F16 ${OPT3FLAGS} ${FAST16FLAGS}
compile O3F32 ${OPT3FLAGS} ${FAST21FLAGS}
compile O3F64 ${OPT3FLAGS} ${FAST64FLAGS}

exit 0

#
# C99 integer types below:
#


echo "${CC}      -c ${CFLAGS} ${INT16FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${CFLAGS} ${INT16FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${CFLAGS} ${INT16FLAGS} $SRC dry1.o ${LFLAGS} -o dry2int16"
      ${CC} -DPASS2 ${CFLAGS} ${INT16FLAGS} $SRC dry1.o ${LFLAGS} -o dry2int16 || exit 1
./dry2int16 ${1-32000}

echo "${CC}      -c ${CFLAGS} ${INT32FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${CFLAGS} ${INT32FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${CFLAGS} ${INT32FLAGS} $SRC dry1.o ${LFLAGS} -o dry2int32"
      ${CC} -DPASS2 ${CFLAGS} ${INT32FLAGS} $SRC dry1.o ${LFLAGS} -o dry2int32 || exit 1
./dry2int32 ${1-100000}

echo "${CC}      -c ${CFLAGS} ${INT64FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${CFLAGS} ${INT64FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${CFLAGS} ${INT64FLAGS} $SRC dry1.o ${LFLAGS} -o dry2fast64"
      ${CC} -DPASS2 ${CFLAGS} ${INT64FLAGS} $SRC dry1.o ${LFLAGS} -o dry2fast64 || exit 1
./dry2fast64 ${1-100000}

# ... and fast variant of them

echo "${CC}      -c ${CFLAGS} ${FAST16FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${CFLAGS} ${FAST16FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${CFLAGS} ${FAST16FLAGS} $SRC dry1.o ${LFLAGS} -o dry2fast16"
      ${CC} -DPASS2 ${CFLAGS} ${FAST16FLAGS} $SRC dry1.o ${LFLAGS} -o dry2fast16 || exit 1
./dry2fast16 ${1-32000}

echo "${CC}      -c ${CFLAGS} ${FAST32FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${CFLAGS} ${FAST32FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${CFLAGS} ${FAST32FLAGS} $SRC dry1.o ${LFLAGS} -o dry2fast32"
      ${CC} -DPASS2 ${CFLAGS} ${FAST32FLAGS} $SRC dry1.o ${LFLAGS} -o dry2fast32 || exit 1
./dry2fast32 ${1-100000}

echo "${CC}      -c ${CFLAGS} ${FAST64FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${CFLAGS} ${FAST64FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${CFLAGS} ${FAST64FLAGS} $SRC dry1.o ${LFLAGS} -o dry2fast64"
      ${CC} -DPASS2 ${CFLAGS} ${FAST64FLAGS} $SRC dry1.o ${LFLAGS} -o dry2fast64 || exit 1
./dry2fast64 ${1-100000}


#
# C99 integer types with MAX optimization below:
#

echo "${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${INT16FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${INT16FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${INT16FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3int16"
      ${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${INT16FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3int16 || exit 1
./dry2o3int16 ${1-32000}

echo "${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${INT32FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${INT32FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${INT32FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3int32"
      ${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${INT32FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3int32 || exit 1
./dry2o3int32 ${1-100000}

echo "${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${INT64FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${INT64FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${INT64FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3fast64"
      ${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${INT64FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3fast64 || exit 1
./dry2o3fast64 ${1-100000}

# ... and their fast counterparts

echo "${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${FAST16FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${FAST16FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${FAST16FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3fast16"
      ${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${FAST16FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3fast16 || exit 1
./dry2o3fast16 ${1-32000}

echo "${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${FAST32FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${FAST32FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${FAST32FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3fast32"
      ${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${FAST32FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3fast32 || exit 1
./dry2o3fast32 ${1-100000}

echo "${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${FAST64FLAGS} $SRC -o dry1.o"
      ${CC}      -c ${OPT3FLAGS} ${CFLAGS} ${FAST64FLAGS} $SRC -o dry1.o || exit 1
echo "${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${FAST64FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3fast64"
      ${CC} -DPASS2 ${OPT3FLAGS} ${CFLAGS} ${FAST64FLAGS} $SRC dry1.o ${LFLAGS} -o dry2o3fast64 || exit 1
./dry2o3fast64 ${1-100000}


rm -f dry*.o dry*.o main*.o
echo 
echo === SUCCESS ===
