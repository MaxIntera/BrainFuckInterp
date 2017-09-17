#include "interp.h"
#define MEM_CHUNK 64

void process(FILE *stream) {
	char c;
	char *memory = (char *) malloc(MEM_CHUNK);
	char *p = memory;

	while ((c = getc(stream)) != EOF) {
		switch(c) {
			case '+':
				(*p)++;
				break;
			case '-':
				(*p)--;
				break;
			case '>':
				if (p + 1 > memory + sizeof(memory))
					memory = (char *) realloc(memory, sizeof(memory) + MEM_CHUNK);
				p++;
				break;
			case '<':
				if (p == memory)
					error(1);
				p--;
				break;
			case '.':
				putchar(*p);
				break;
			case ',':
				*p = getchar();
				break;
			/* case '[': */
					

		}
	}
	putchar('\n');
	free(memory);
}
