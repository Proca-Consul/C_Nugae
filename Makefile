# MAKEFILE for C_Nugae
# (based on Homework 1: Parole, Parole, Parole
# by Ivano Salvo, Università Sapienza di Roma;
# link @ http://twiki.di.uniroma1.it/pub/Info_gen/Homework/2015-homework1.pdf)

# Set flags
CC	=	gcc
CFLAGS	=	-Wall	-pedantic	-std=c99	-o2

.SUFFIXES:	.c	.o

.PHONY:	all	clean

#################
# Main executable
#################
program:	quicksort.o	lexPerm.o	anagrams.o	secCode.o	program.o

################
# Object files
###############
quicksort.o:	quicksort.h

lexPerm.o:	quicksort.h	lexPerm.h

anagrams.o:	anagrams.h

secCode.o:	secCode.h

program.o:	quicksort.h	lexPerm.h	anagrams.h	secCode.h	program.c

clean:
	rm -f quicksort
	rm -f lexperm
	rm -f anagrams
	rm -f secretcode
	rm -f program
	rm -f $(wildcard *.o)
	rm -f $(wildcard .*.swp)


