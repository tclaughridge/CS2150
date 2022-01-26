# Thomas Laughridge
# tcl5tu@virginia.edu
# 10/5/21


CXX=clang++
CXXFLAGS=-Wall -o2
DEBUG=-g
OBJECTS=AVLNode.o AVLPathTest.o AVLTree.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(DEBUG) $(OBJECTS) -o a.out
	@echo "Done"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

AVLNode.o: AVLNode.cpp AVLNode.h

AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h

AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h
