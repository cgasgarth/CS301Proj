# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CC = g++ -std=c++20
CFLAGS = -Wall -g -O3

# ****************************************************
# Targets needed to bring the executable up to date
all: ASSEMBLE

ASSEMBLE: Main.o Functions.o
	$(CC) $(CFLAGS) -o ASSEMBLE Main.o Functions.o
	rm Main.o Functions.o

Main.o: main.cpp Functions.o Functions.h
	$(CC) $(CFLAGS) -c main.cpp

Functions.o: Functions.cpp Functions.h
	$(CC) $(CFLAGS) -c Functions.cpp

clean: 
	rm ASSEMBLE
