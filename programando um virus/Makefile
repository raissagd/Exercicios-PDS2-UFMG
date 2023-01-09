CC := g++
BUILDDIR := build
SRCDIR := src
FLAGS := -I include/

all: main

virus: 
	$(CC) $(FLAGS) -c $(SRCDIR)/virus.cpp -o $(BUILDDIR)/virus.o

paciente:
	$(CC) $(FLAGS) -c $(SRCDIR)/paciente.cpp -o $(BUILDDIR)/paciente.o

main: virus paciente
	$(CC) $(FLAGS) $(BUILDDIR)/*.o  $(SRCDIR)/main.cpp -o $(BUILDDIR)/main
	@chmod a+x $(BUILDDIR)/main

clean:
	rm -r $(BUILDDIR)/*