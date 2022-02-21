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
    
tests: bears_main input01.txt input02.txt input03.txt input04.txt input05.txt
	$(BUILDDIR)/bears_main < test01.txt > output01.txt || true
	$(BUILDDIR)/bears_main < test02.txt > output02.txt || true
	$(BUILDDIR)/bears_main < test03.txt > output03.txt || true
	$(BUILDDIR)/bears_main < test04.txt > output04.txt || true
	$(BUILDDIR)/bears_main < test05.txt > output05.txt || true
	
compare: tests
	diff -i -w -B output01.txt expected01.txt || true
	diff -i -w -B output02.txt expected02.txt || true
	diff -i -w -B output03.txt expected03.txt || true
	diff -i -w -B output04.txt expected04.txt || true
	diff -i -w -B output05.txt expected05.txt || true


all: bears_main
	
clean:
	rm -f $(BUILDDIR)/bears_main
	rm -f $(OBJDIR)/*.o
	rm -f *.out.txt
