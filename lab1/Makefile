CC=g++
CFLAGS=-std=c++11
EXE=minesweeper
HFILES=Board.h Cell.h Exception.h array2D.h array2D_impl.h row.h row_impl.h Minesweeper.h
CPPFILES=Board.cpp Cell.cpp Exception.cpp main.cpp Minesweeper.cpp

$(EXE):$(CPPFILES) $(HFILES) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(CPPFILES) 

run:$(EXE)
	./$(EXE)

clean:
	rm -fv $(EXE) *~
