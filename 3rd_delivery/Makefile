all: yacc lex burg compile # execute assemble

lex:
	flex -l diy.l

yacc:
	byacc -dv diy.y

burg:
	./pburg -T diy.brg

compile:
	gcc -g -c -I lib y.tab.c lex.yy.c yyselect.c 
	gcc -o diy y.tab.o lex.yy.o yyselect.o -L lib -lutil -lfl

# execute:
# 	./diy file.diy

# assemble:
#	nasm -felf file.diy
# 	ld -o diy -melf_i386 diy.o lib/libdiy.a

clean:
	rm -f y.output y.tab.c y.tab.h lex.yy.c yyselect.c
	rm -f *.o *.asm
	rm -f .DS_Store
	rm -f diy
	clear

zip:
	zip proj diy.l diy.y diy.brg Makefile