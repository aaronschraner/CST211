CC=g++
CFLAGS=-std=c++11 
CPPFILES=main.cpp 
HFILES=*.h
EXE=tree

$(EXE):$(CPPFILES) $(HFILES) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(CPPFILES)

run:$(EXE)
	./$(EXE) $(EXEARGS)

clean:
	rm -fv *~ $(EXE)
