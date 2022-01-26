# Thomas Laughridge
# tcl5tu@virginia.edu
# 10/5/21


CXX=clang++
CXXFLAGS=-Wall -o2
DEBUG=-g
OBJECTS=BSTPathTest.o BinarySearchTree.o BinaryNode.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(DEBUG) $(OBJECTS) -o a.out
	@echo "Done"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h

BinaryNode.o: BinaryNode.cpp BinaryNode.h

BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h
