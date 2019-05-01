CC=g++
CFLAGS=-Wall
OBJECT= -c -o
TARGET=vector

$(TARGET): vector.o lex.o parser.o
	$(CC) $(CFLAGS) -o $@ $^

vector.o: vector.cpp vector.hpp parser.tab.hpp
	$(CC) $(CFLAGS) $(OBJECT) $@ $<

lex.o: lex.yy.c parser.tab.hpp
	$(CC) $(CFLAGS) $(OBJECT) $@ $<

parser.o: parser.tab.cpp parser.tab.hpp
	$(CC) $(CFLAGS) $(OBJECT) $@ $< 

parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -vd $<

lex.yy.c: lexer.lex
	flex $<

.PHONY: clean

clean: 
	rm -rf parser.output *.o *.tab.* *.yy.* vector