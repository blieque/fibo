#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char const colour_normal[]		= "\033[0m",
		   colour_pale_yellow[]	= "\033[93m";

#include "functions.h"

int main(int argc, char *argv[]) {

	/* parsing arguments */

	int arg,
		arg_showseq = 0;
	for (arg = 1; arg < argc; arg++) {

		if (strcmp(argv[arg], "-h") == 0) {

			help(argv[0]);
			return 0;

		} else if (strcmp(argv[arg], "-s") == 0) {

			arg_showseq	= 1;

		}

	}

	/* user input fun */

	unsigned int const limit	= get_limit(argc, argv);
	int error_check				= error_handle(limit, argv);

	if (!error_check) {
		return limit;
	}

	/* the big loop */

	int output[2 * (limit - 1)],
		div;

	memset(output, 0, sizeof(output));

	for (div = limit; div > 1; div--) {

		int const workarrsize	= 2 * div + 9;
		int workindex	= 2,
			*workarr	= malloc(workarrsize * sizeof(int));

		workarr[0] = workarr[1] = 1;

		while (!(workarr[workindex - 2] == 1 && workarr[workindex - 1] == 0)) {

			workarr[workindex]	= (workarr[workindex - 2] + workarr[workindex - 1]) % div;

			if (workarr[workindex] == 0) {
				output[2 * (div - 2)]++;

				if (output[2 * (div - 2) + 1] == 0) {
					output[2 * (div - 2) + 1]	= workindex + 1;
				}
			}

			workindex++;

			if (workindex % (workarrsize - 1) == 0) {
				int *newarr	=	realloc(workarr, (workindex + workarrsize) * sizeof(int));
				if (newarr == NULL) {
					free(workarr);
					printf("Something went tits up. Quitting without dignity.\n");
					return -4;
				} else {
					workarr	= newarr;
				}
			}

		}

		if (arg_showseq) {

			printf("%d\t: 1,1,", div);

			int j;
			for (j = 2; j < workindex; j++) {

				if (j != workindex - 1) {

					printf("%d,", workarr[j]);
					if (workarr[j] == 0) {
						printf("\n\t  ");
					}

				} else {
					printf("%d", workarr[j]);
				}

			}

			printf("\n");
			 
		}

	}

	/* output */

	if (arg_showseq) {
		printf("\n");
	}


	int i;
	for (i = 0; i < limit - 1; i++) {
		 
		printf("%d\t: { cc: %d, cl: %d }\n",
				i + 2,
				output[2 * i],
				output[2 * i + 1]);
		
	}

	return 0;

}
