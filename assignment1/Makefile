#Author: Aaron Schraner
#Date: September 30, 2015
#Purpose: Makefile for generic Array class and test functions
# (CST211 Assignment 1)

CC=clang++
EXE=array
HFILES=Array.h Exception.h
CPPFILES=main.cpp Exception.cpp
CFLAGS=-DTEST_CTORS -DTEST_OPERS -DTEST_SETTERS

$(EXE):$(HFILES) $(CPPFILES)
	$(CC) -o $(EXE) $(CPPFILES) $(CFLAGS)

run:$(EXE)
	./$(EXE)

clean:
	rm -fv $(EXE) *~
