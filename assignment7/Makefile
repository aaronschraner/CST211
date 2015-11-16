CC=g++
CFLAGS=-std=c++11
CPPFILES=main.cpp
HFILES=*.h
EXE=graph

$(EXE):$(CPPFILES) $(HFILES) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(CPPFILES)

run:$(EXE)
	./$(EXE)

clean:
	rm -fv *~ $(EXE)
