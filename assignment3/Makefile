CC=g++
CFLAGS=-std=c++11
EXE=ll
HFILES=Iterator.h Iterator_impl.h Node.h Node_impl.h LinkedList.h LinkedList_impl.h 
CPPFILES=main.cpp Exception.cpp

$(EXE):$(HFILES) $(CPPFILES)
	$(CC) $(CFLAGS) -o $(EXE) $(CPPFILES)

run:$(EXE)
	./$(EXE)
	
clean:
	rm -fv *~ $(EXE)
