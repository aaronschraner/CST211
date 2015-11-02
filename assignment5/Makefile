CC=g++
CFLAGS=-std=c++11
CPPFILES=Exception.cpp main.cpp 
HFILES=Array.h Array_impl.h CircularQueue.h CircularQueue_impl.h Exception.h 
EXE=cq

$(EXE):$(CPPFILES) $(HFILES) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(CPPFILES)

run:$(EXE)
	./$(EXE)

clean:
	rm -fv *~ $(EXE)
