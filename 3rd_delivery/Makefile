all: lex yacc burg assemble

lex:
	flex -l diy.l

yacc:
	byacc -dv diy.y
	gcc -g -c -I lib y.tab.c lex.yy.c

burg:
	./pburg -T diy.brg diy.asm

assemble:
	nasm -felf32 diy.asm
	ld -o diy -melf_i386 diy.o lib/libdiy.a

clean:
	rm -f y.output y.tab.c y.tab.h lex.yy.c yyselect.c
	rm -f *.o *.asm
	rm -f .DS_Store
	rm -f diy
	clear

zip:
	zip proj diy.l diy.y diy.brg Makefile