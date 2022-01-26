# Thomas Laughridge
# tcl5tu@virginia.edu
# 9/30/21


CXX=clang++
CXXFLAGS=-Wall -o2
DEBUG=-g
OBJECTS=TreeCalc.o TreeNode.o TreeCalcTest.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(DEBUG) $(OBJECTS) -o a.out
	@echo "Done"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h

TreeNode.o: TreeNode.cpp TreeNode.h