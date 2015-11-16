CC=g++
CFLAGS=-std=c++11
CPPFILES=test.cpp
HFILES=*.h
EXE=test

$(EXE):$(CPPFILES) $(HFILES) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(CPPFILES)

run:$(EXE)
	./$(EXE)

clean:
	rm -fv *~ $(EXE)
