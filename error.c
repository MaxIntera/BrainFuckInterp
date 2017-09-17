#include "interp.h"

void error(int code) {
	switch (code) {
		case 0:
			printf("error: not enough arguments\n");
			exit(1);
			break;
		case 1:
			printf("error: tried to access illeagal memory\n");
			exit(1);
			break;
	}
}
