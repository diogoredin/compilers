LIB=factorial
CFLAGS=-g -Dunderscore # -fno-stack-protector # em Ubunto
RUNTIME=lib$(LIB).a # stand-alone runtime

OBJ=linux.o lib.o sys.o

NASM=nasm -felf32

all: $(RUNTIME)

$(RUNTIME): dbl.o $(OBJ)
	ar crl $@ $?

dbl.o: dbl.c
	$(CC) $(CFLAGS) -DPOSTFIX -c $<

.SUFFIXES: .asm
.asm.o:
	$(NASM) $<

install:: all
	cp $(RUNTIME) ..

clean::
	rm -f $(RUNTIME) *.o a.out core
