# Geração do analisador lexical (gera o ficheiro lex.yy.c
flex -l diy.l

# Geração do analisador sintáctico (gera os ficheiros y.tab.c, y.tab.h e y.output)
yacc -dv diy.y

# Geração dos ficheiros objecto relocatáveis
gcc -g -c -DYYDEBUG -I lib y.tab.c lex.yy.c

# Geração do compilador (geração de código para i386
gcc -o diy y.tab.o lex.yy.o -L lib -lutil -lfl

# Compilar um ficheiro fonte para produzir o respectivo ficheiro assembly
./diy hello.diy