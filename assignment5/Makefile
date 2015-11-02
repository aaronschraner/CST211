CC=g++
CFLAGS=-std=c++11
CPPFILES=Exception.cpp main.cpp 
HFILES=Array.h Array_impl.h CircularQueue.h CircularQueue_impl.h Exception.h Iterator.h Iterator_impl.h LinkedList.h LinkedList_impl.h Node.h Node_impl.h Queue.h Queue_impl.h 
EXE=cq

$(EXE):$(CPPFILES) $(HFILES) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(CPPFILES)

run:$(EXE)
	./$(EXE)

clean:
	rm -fv *~ $(EXE)
