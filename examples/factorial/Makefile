LANG=factorial
EXT=fac

# YACC Debug Flag
YYDEBUG=YYDEBUG=1

LEX=flex -l
YACC=byacc -dv
PBURG=./pburg #-T
NASM=nasm -felf
GCC= gcc -g

.SUFFIXES: .$(EXT) .asm .obj .exe

################################DEFINICOES############################################	

$(LANG): $(LANG).y $(LANG).l $(LANG).brg
	$(YACC) $(LANG).y
	$(LEX) $(LANG).l
	$(PBURG) $(LANG).brg
	make -C lib
	make -C run
	$(GCC) -o $(LANG) -DYYDEBUG=1 -Ilib lex.yy.c y.tab.c yyselect.c lib/libutil.a
	cd run; cp libfactorial.a ..
	
clean_if:
	rm ../examples/if.o ../examples/if.asm ../examples/if

%:%.$(EXT) 
#	rm $*.o $*.asm $*
	./$(LANG) -trace $<
	$(NASM) $*.asm -o $*.o
	ld -g -o $@ $*.o run/libfactorial.a

########################### EXEMPLOS ###############################
 
iter: iter.fac fact.fac
	./factorial $<
	nasm -felf iter.asm
	./factorial fact.fac
	nasm -felf fact.asm
	ld -o  $@ iter.o fact.o libfactorial.a

recurs: recurs.fac fact.fac
	./factorial $<
	nasm -felf recurs.asm
	./factorial fact.fac
	nasm -felf fact.asm
	ld -o  $@ recurs.o fact.o libfactorial.a


examples: clean_examples run_examples

exampleack: clean_examples
	./factorial ../examples/ack.fac > ../examples/ack.out

exampleint: clean_examples
	-$(YYDEBUG) ./factorial ../examples/intindex.fac > ../examples/intindex.out

run_examples: 
	-$(YYDEBUG) ./factorial ../examples/ack.fac > ../examples/ack.out
	-$(YYDEBUG) ./factorial ../examples/add.fac > ../examples/add.out
	-$(YYDEBUG) ./factorial ../examples/args.fac > ../examples/args.out
	-$(YYDEBUG) ./factorial ../examples/break.fac > ../examples/break.out
	-$(YYDEBUG) ./factorial ../examples/chrindex.fac > ../examples/chrindex.out
	-$(YYDEBUG) ./factorial ../examples/cont.fac > ../examples/cont.out
	-$(YYDEBUG) ./factorial ../examples/decl.fac > ../examples/decl.out
	-$(YYDEBUG) ./factorial ../examples/div.fac > ../examples/div.out
	-$(YYDEBUG) ./factorial ../examples/downto.fac > ../examples/downto.out
	-$(YYDEBUG) ./factorial ../examples/fib.fac > ../examples/fib.out
	-$(YYDEBUG) ./factorial ../examples/gcd.fac > ../examples/gcd.out
	-$(YYDEBUG) ./factorial ../examples/gt.fac > ../examples/gt.out
	-$(YYDEBUG) ./factorial ../examples/hello.fac > ../examples/hello.out
	-$(YYDEBUG) ./factorial ../examples/if.fac > ../examples/if.out
	-$(YYDEBUG) ./factorial ../examples/intindex.fac > ../examples/intindex.out
	-$(YYDEBUG) ./factorial ../examples/local.fac > ../examples/local.out
	-$(YYDEBUG) ./factorial ../examples/logic.fac > ../examples/logic.out
	-$(YYDEBUG) ./factorial ../examples/pi.fac > ../examples/pi.out
	-$(YYDEBUG) ./factorial ../examples/printi.fac > ../examples/printi.out
	-$(YYDEBUG) ./factorial ../examples/strtest.fac > ../examples/strtest.out	
	-$(YYDEBUG) ./factorial ../examples/tri.fac > ../examples/tri.out
	-$(YYDEBUG) ./factorial ../examples/upto.fac > ../examples/upto.out
	-$(YYDEBUG) ./factorial ../examples/while.fac > ../examples/while.out

diff_examples: run_examples
	-diff ../examples/ack.out ../examples/empty.out 
	-diff ../examples/add.out ../examples/empty.out
	-diff ../examples/args.out ../examples/empty.out
	-diff ../examples/break.out ../examples/empty.out
	-diff ../examples/chrindex.out ../examples/empty.out
	-diff ../examples/cont.out ../examples/empty.out
	-diff ../examples/decl.out ../examples/empty.out
	-diff ../examples/div.out ../examples/empty.out
	-diff ../examples/downto.out ../examples/empty.out
	-diff ../examples/fib.out ../examples/empty.out
	-diff ../examples/gcd.out ../examples/empty.out
	-diff ../examples/gt.out ../examples/empty.out
	-diff ../examples/hello.out ../examples/empty.out
	-diff ../examples/if.out ../examples/empty.out
	-diff ../examples/intindex.out ../examples/empty.out
	-diff ../examples/local.out ../examples/empty.out
	-diff ../examples/logic.out ../examples/empty.out
	-diff ../examples/pi.out ../examples/empty.out
	-diff ../examples/printi.out ../examples/empty.out
	-diff ../examples/strtest.out ../examples/empty.out
	-diff ../examples/tri.out ../examples/empty.out
	-diff ../examples/upto.out ../examples/empty.out
	-diff ../examples/while.out ../examples/empty.out	

clean_examples:
	rm -f ../examples/ack.out
	rm -f ../examples/add.out
	rm -f ../examples/args.out
	rm -f ../examples/break.out
	rm -f ../examples/chrindex.out
	rm -f ../examples/cont.out
	rm -f ../examples/decl.out
	rm -f ../examples/div.out
	rm -f ../examples/downto.out
	rm -f ../examples/fib.out
	rm -f ../examples/gcd.out
	rm -f ../examples/gt.out
	rm -f ../examples/hello.out
	rm -f ../examples/if.out
	rm -f ../examples/intindex.out
	rm -f ../examples/local.out
	rm -f ../examples/logic.out
	rm -f ../examples/pi.out
	rm -f ../examples/printi.out
	rm -f ../examples/strtest.out	
	rm -f ../examples/tri.out
	rm -f ../examples/upto.out
	rm -f ../examples/while.out


clean_exemplos3:		
	-cd ../exemplos3/exemplos/ && ls | grep -v "\." | xargs rm


# runs gdb with input
gdb:
	(echo commands; cat) | gdb 

clean_zip: 
	rm -f proj.zip


zip: 	clean_zip
	zip -r proj.zip lib run Makefile $(LANG).l $(LANG).y $(LANG).brg string.$(EXT) rand.$(EXT) mean.$(EXT) iter.$(EXT) recurs.$(EXT) fact.$(EXT)


install: $(LANG)
	cp $(LANG) ..

clean:	
	make clean -C lib
	make clean -C run	
	rm -f *.o $(LANG) lex.yy.c y.tab.c y.tab.h y.output lib$(LANG).a *~
