
CC=g++
CFLAGS=-std=c++11 -DSHOWSORTS
CPPFILES=main.cpp Exception.cpp
HFILES=*.h sorts/*.h
EXE=sort

$(EXE):$(CPPFILES) $(HFILES) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(CPPFILES)

run:$(EXE)
	./$(EXE) $(EXEARGS)

clean:
	rm -fv *~ sorts/*~ $(EXE) sort.log
