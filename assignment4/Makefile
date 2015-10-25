CC=g++
CFLAGS=-std=c++11
EXE=ll
HFILES=Iterator.h Iterator_impl.h Node.h Node_impl.h LinkedList.h LinkedList_impl.h Stack.h Stack_impl.h 
CPPFILES=main.cpp Exception.cpp

$(EXE):$(HFILES) $(CPPFILES)
	$(CC) $(CFLAGS) -o $(EXE) $(CPPFILES)

run:$(EXE)
	./$(EXE)
	
clean:$(HFILES) $(CPPFILES)
	rm -fv *~ $(EXE)

debug:
	$(CC) $(CFLAGS) -o $(EXE) $(CPPFILES) -DVERBOSE
	./$(EXE)

ddebug:debug
	gdb -q -ex run ./$(EXE)
