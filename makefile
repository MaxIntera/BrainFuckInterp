brainfuck:  main.c error.c process.c
	gcc $(DEBUG) -g -ansi -Wall -pedantic main.c error.c process.c -o brainfuck
	
debug: DEBUG = -DDEBUG

debug: brainfuck

