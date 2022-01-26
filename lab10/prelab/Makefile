# Defines the C++ compiler we'll be using
CXX = clang++

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS = -Wall -g

# All of the .o files for our program
OBJECTS = huffNode.o heap.o huffmanenc.o

# Compile our files into a.out
a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	-rm -f *.o *~

huffNode.o: huffNode.cpp huffNode.h

heap.o: heap.cpp heap.h

huffmanenc.o: huffmanenc.cpp huffNode.h