
CC=g++
CFLAGS=-std=c++11
CPPFILES=main.cpp Exception.cpp
HFILES=*.h sorts/*.h
EXE=sort

$(EXE):$(CPPFILES) $(HFILES) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(CPPFILES)

run:$(EXE)
	./$(EXE)

clean:
	rm -fv *~ sorts/*~ $(EXE)
