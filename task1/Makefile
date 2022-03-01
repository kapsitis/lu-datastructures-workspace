SRCDIR := .
OBJDIR := build
BUILDDIR := build
SRC_FILES := $(wildcard $(SRCDIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC_FILES))
CC := g++
CPPFLAGS := -Wall

# compilation command (takes all *.cpp into *.o)
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CPPFLAGS) -c -o $@ $<	

# linking 
task1: $(OBJ_FILES)
	g++ -o $@ $^
	mkdir -p $(SRCDIR)
	mkdir -p $(BUILDDIR)
	mv task1 $(BUILDDIR)
    
tests: task1 input01.txt 
	cp input01.txt $(BUILDDIR)/input1.txt
	$(BUILDDIR)/task1 || true
	
compare: tests
	diff -i -w -B output01.txt expected01.txt || true


all: task1
	
clean:
	rm -f $(BUILDDIR)/task1
	rm -f $(OBJDIR)/*.o
	rm -fr $(BUILDDIR)
	rm -f output*.txt
