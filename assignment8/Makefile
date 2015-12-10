CC=clang++
CFLAGS=-std=c++11 
CPPFILES=main.cpp Exception.cpp
HFILES=*.h iterators/*.h
EXE=tree

$(EXE):$(CPPFILES) $(HFILES) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(CPPFILES)

run:$(EXE)
	./$(EXE) $(EXEARGS)

clean:
	rm -fv *~ iterators/*~ $(EXE)
