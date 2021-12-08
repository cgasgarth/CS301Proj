# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

ASSEMBLE: Main.o Functions.o
	$(CC) $(CFLAGS) -o ASSEMBLE Main.o Functions.o

# The main.o target can be written more simply

main.o: main.cpp Functions.h
	$(CC) $(CFLAGS) -c main.cpp

Functions.o: Functions.h
