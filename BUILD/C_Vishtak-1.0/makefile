install: all
	#mkdir ~/STR1
	#mv C_Vishtak ~/STR1/

all: C_Vishtak

C_Vishtak: C_Vishtak.o help.o fu.o
	gcc -o C_Vishtak C_Vishtak.o help.o fu.o

C_Vishtak.o: C_Vishtak.c C_Vishtak.h
	gcc -c -o C_Vishtak.o C_Vishtak.c

help.o: help.c C_Vishtak.h
	gcc -c -o help.o help.c

fu.o: fu.c C_Vishtak.h
	gcc -c -o fu.o fu.c

.PHONY: clean
clean:
	rm -f C_Vishtak C_Vishtak.o help.o fu.o
	
