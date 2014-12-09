all:
	flex gram.l
	bison -d -v -g gram.y
	gcc -c *.c
	gcc -o compiler *.o -ly -lfl
	dot -Tpdf gram.dot -o gram.pdf

install:
	apt-get install gcc
	apt-get install g++
	apt-get install flex
	apt-get install bison
	apt-get install graphviz

run:
	./compiler testes/sample1.cm

clean:
	rm *.o compiler lex.yy.c gram.tab.c gram.tab.h gram.dot gram.pdf gram.output