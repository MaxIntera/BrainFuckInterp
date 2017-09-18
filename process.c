#include "interp.h"
#define MEM_CHUNK 256

void process(FILE *stream) {
	char c;
	char *memory = (char *) malloc(MEM_CHUNK);
	char *p = memory;
	int curchar = 0;
	int *bracks = (int *) malloc(MEM_CHUNK * sizeof(int));
	int *bp = bracks;

	*memory = 1;
	p++;
	*bracks = 1;
	bp++;

	while ((c = getc(stream)) != EOF) {
	
#ifdef DEBUG
		printf("%c :: %d %d \n", c, memory[1], memory[2]);
#endif

		switch(c) {
			case '+':
				(*p)++;
				break;
			case '-':
				(*p)--;
				break;
			case '>':
				if (p + 1 > memory + *memory * MEM_CHUNK)
					memory = (char *) realloc(memory, ++*memory * MEM_CHUNK);
				p++;
				break;
			case '<':
				if (p == memory)
					error(1);
				p--;
				break;
			case '.':
#ifdef DEBUG
				printf("<%d>\n", *p);
#endif
#ifndef DEBUG
				printf("%c", *p);
#endif
				break;
			case ',':
				*p = getchar();
				break;
			case '[':
				if (*bracks * MEM_CHUNK < bp + 1 - bracks)
					bracks = (int *) realloc(bracks, ++*bracks * MEM_CHUNK * sizeof(int));
				*(bp++) = curchar;
				break;
			case ']':
				if (*p)
					fseek(stream, *(bp - 1) + 1, SEEK_SET);
				else
					bp--;
				break;
		}

		curchar++;
	}
	putchar('\n');
	free(memory);
	free(bracks);
}
