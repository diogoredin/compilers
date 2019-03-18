.SUFFIXES: .$(EXT) .asm
COMP=../diy # compiler
EXT=diy # file extension: .$(EXT)
LIB=diy # runtime library: lib$(LIB).a
RUN=../run # runtime directory
AS=nasm -felf32 # assembler command
LD=ld -melf_i386 # loader command

SRC=hello.diy ack.diy
EXE=$(SRC:%.diy=%)

all:: compiler runtime $(EXE)

compiler::
	make -C ..

runtime::
	make -C $(RUN)

%:%.$(EXT)
	$(COMP) $<
	$(AS) $*.asm -o $*.o
	$(LD) -o $@ $*.o -L$(RUN) -l$(LIB)

clean::
	rm -f *.o *.asm *.s *~ $(EXE)
