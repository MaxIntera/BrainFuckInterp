#include "interp.h"

int main(int argc, char **argv) {
	FILE *input;

	if (argc < 2) {
		error(0);
	}

	input = fopen(argv[1], "r");
	process(input);
	fclose(input);

	return 0;
}
