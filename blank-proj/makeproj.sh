#!/bin/bash

mkdir $1
cp -r ../Stanford_CS106B_linux/* ./$1
ln -s $(pwd)/$1/StanfordCPPLib/libStanfordCPPLib.a $(pwd)/$1/libStanfordCPPLib.a

#
## MAKE FILE
#
echo "PROGRAM = $1
OBJECTS = $1.o

CPPOPTIONS = -IStanfordCPPLib -fvisibility-inlines-hidden
LDOPTIONS = -L.
LIB = -lStanfordCPPLib

all: \$(PROGRAM)

$1: \$(OBJECTS)
	g++ -o \$(PROGRAM) \$(LDOPTIONS) \$(OBJECTS) \$(LIB)

$1.o: $1.cpp Makefile libStanfordCPPLib.a
	g++ -c \$(CPPOPTIONS) $1.cpp

libStanfordCPPLib.a:
	@rm -f libStanfordCPPLib.a
	(cd StanfordCPPLib; make all)
	ln -s StanfordCPPLib/libStanfordCPPLib.a .


tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a \$(PROGRAM)
" >> ./$1/Makefile

#
## CPP FILE
#
echo "#include <iostream>
#include \"./StanfordCPPLib/console.h\"
using namespace std;

int main() {

    return 0;
}
" >> ./$1/$1.cpp

