CFLAGS=-g -c -DYYDEBUG
EXT=diy
LIB=-I lib
LANG=diy

all: flex yacc link generate

flex:
	flex -l $(LANG).l

yacc:
	byacc -dv inicial.y

link:
	gcc $(CFLAGS) $(LIB) y.tab.c lex.yy.c

generate:
	gcc -o $(LANG) y.tab.o lex.yy.o $(LIB) -lutil -lfl

clean:
	rm -f y.output y.tab.c y.tab.h lex.yy.c
	rm -f *.o
	rm -f .DS_Store
	rm -f $(LANG)
	clear

zip:
	zip proj diy.l inicial.y string.diy iter.diy recurs.diy factorial.diy rand.diy mean.diy