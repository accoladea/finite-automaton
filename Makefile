PROGRAMS = main

CFLAGS = -g -std=c99 -Wall -Werror -Wno-char-subscripts

programs: $(PROGRAMS)

main: main.o nfa_to_dfa_conversion.o dfa.o nfa.o IntSet.o
	$(CC) -o $@ $^

clean:
	-rm $(PROGRAMS) *.o