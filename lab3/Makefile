
CC=g++
#uncomment this ----v  to show sorted numbers
CFLAGS=-std=c++11 #-DSHOWSORTS
CPPFILES=*.cpp
HFILES=*.h
EXE=freecell

$(EXE):$(CPPFILES) $(HFILES) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(CPPFILES)

run:$(EXE)
	./$(EXE) $(EXEARGS)

clean:
	rm -fv *~ sorts/*~ $(EXE) sort.log
