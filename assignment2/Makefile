CC=g++
CFLAGS=-std=c++11 -Werror -pedantic # no mercy
EXE=array2d
HFILES=array2D.h array2D_impl.h row.h row_impl.h
CPPFILES=main.cpp Exception.cpp

$(EXE):$(CPPFILES) $(HFILES) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(CPPFILES) 

run:$(EXE)
	./$(EXE)

clean:
	rm -fv $(EXE) *~
