.SUFFIXES: .brg .asm

COMPILER=diy
RUNTIME=runtime/librun.a
UTIL=lib/libutil.a

CC=gcc
CFLAGS=-g -Ilib -DYYDEBUG
LEX=flex
LFLAGS=-l
YACC=byacc
YFLAGS=-dv
BURG=./pburg
BFLAGS=-T -n
LDLIBS=-L lib -lutil

all: $(COMPILER) $(RUNTIME)
$(COMPILER): scan.o gram.o code.o $(UTIL)
	$(LINK.c) -o $@ $^
$(UTIL):
	make -C lib
$(RUNTIME):
	make -C runtime install
.brg.c:
	$(BURG) $(BFLAGS) $< $@
%: %.diy
	./diy $<
	nasm -felf64 $*.asm
	gcc $*.o -o $@ runtime/librun.a
code.c: gram.c
scan.c: gram.c
clean:
	rm -f y.tab.h y.output diy *.asm *.o scan.c gram.c code.c
	clear