#!/bin/bash

echo "Saisissez le nom de l'exécutable à créer : "
read cible

function getH {
cpt=0
for i in *.h; do
  h[$cpt]=$(basename $i .h);
  cpt=$(($cpt+1));
done
}

function getCC {
cpt=0
for i in *.cc; do
  cc[$cpt]=$(basename $i .cc);
  cpt=$(($cpt+1));
done
}

function createO {
cpt=0
for i in ${cc[*]}; do
  o[cpt]=$i.o;
  cpt=$(($cpt+1));
done
}

function genBlocks {

cpt=0
for i in ${cc[*]}; do
  genUsualHeader
  genHeaders

  printf "$i.o : $i.cc $usual ${headers[*]}\n" >> Makefile;
  printf "          \$(CC) -o $i.o -c $i.cc\n\n" >> Makefile
  cpt=$(($cpt+1));
done

}

function genUsualHeader {
if [ -e $i.h ]; then
  usual=$i.h
else
  usual=""
fi
}

function genHeaders {
if [ -e $i.h ]; then
  headers=$(cat $i.h | grep "#include \"" | cut -d'"' -f2 | tr "\n" " ")
  echo ${headers[*]}
fi
}

function createMakefile {

printf "CC= g++\n\n" > Makefile
printf "OBJECTS= ${o[*]}\n\n" >> Makefile
printf "TARGET= $cible\n\n" >> Makefile
printf "\$(TARGET) : \$(OBJECTS)\n" >> Makefile
printf "          \$(CC) \$(OBJECTS) -o \$(TARGET)\n\n" >> Makefile

genBlocks

printf "clean :\n" >> Makefile
printf "          rm -f *~ *.o \$(TARGET)\n" >> Makefile
}


# Déroulement :
getH
getCC
createO
createMakefile


#echo ${h[*]}
#echo ${cc[*]}
#echo ${o[*]}
#echo $cible
