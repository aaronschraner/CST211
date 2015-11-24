CC=clang++
CFLAGS=-std=c++11
DEBUGFLAGS=-g
CPPFILES=main.cpp 
HFILES=*.h iterators/*.h
EXE=treeIter

$(EXE):$(CPPFILES) $(HFILES) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(CPPFILES)

debug:$(CPPFILES) $(HFILES) Makefile
	$(CC) $(DEBUGFLAGS) $(CFLAGS) -o $(EXE) $(CPPFILES) 
	gdb ./$(EXE)

run:$(EXE)
	./$(EXE) $(EXEARGS)

clean:
	rm -fv *~ iterators/*~ $(EXE)
