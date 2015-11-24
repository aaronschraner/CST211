
CC=g++
CFLAGS=-std=c++11 
CPPFILES=test.cpp 
HFILES=*.h
EXE=treeIterator

$(EXE):$(CPPFILES) $(HFILES) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(CPPFILES)

run:$(EXE)
	./$(EXE) $(EXEARGS)

clean:
	rm -fv *~ $(EXE)
