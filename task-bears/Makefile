SRCDIR := .
OBJDIR := build
BUILDDIR := build
SRC_FILES := $(wildcard $(SRCDIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC_FILES))
CC := g++
CPPFLAGS := -Wall

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CPPFLAGS) -c -o $@ $<	

bears_main: $(OBJ_FILES)
	g++ -o $@ $^
	mkdir -p $(SRCDIR)
	mkdir -p $(BUILDDIR)
	mv bears_main $(BUILDDIR)
    
tests: bears_main input01.txt 
	cp input01.txt $(BUILDDIR)/bears.in
	$(BUILDDIR)/bears_main || true
	mv $(BUILDDIR)/bears.out input01.txt
	
compare: tests
	diff -i -w -B output01.txt expected01.txt || true


all: bears_main
	
clean:
	rm -f $(BUILDDIR)/bears_main
	rm -f $(OBJDIR)/*.o
	rm -f output*.txt
