# Thomas Laughridge
# tcl5tu@virginia.edu
# 10/13/21


CXX=clang++
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=wordPuzzle.o timer.o hashTable.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(DEBUG) $(OBJECTS) -o a.out
	@echo "Done"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

hashTable.o: hashTable.cpp hashTable.h

timer.o: timer.cpp timer.h

wordPuzzle.o: wordPuzzle.cpp timer.h hashTable.h

