CC=g++
CFLAGS=-std=c++11
CPPFILES=itertest.cpp
HFILES=
EXE=itt

$(EXE):$(CPPFILES) $(HFILES) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(CPPFILES)

run:$(EXE)
	./$(EXE)

clean:
	rm -fv *~ $(EXE)
