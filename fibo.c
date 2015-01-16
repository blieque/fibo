#include <stdlib.h>
#include <stdio.h>

int argc;
char *argv[];
char const colour_normal[]		= "\033[0m",
		   colour_pale_yellow[]	= "\033[93m";

int get_limit() {

	int limit;

	if (argc > 1) {

		int limit_arg	= atoi(argv[1]);

		if (limit_arg > 0) {
			limit	= limit_arg;
		} else {
			limit	= -1;
		}

	} else {

		int user_input;

		printf("Please enter an integer above zero (pro tip: don't enter letters): ");
		scanf("%d", &user_input);
		printf("%d\n", user_input);

		if (user_input > 0) {
			limit	= user_input;
		} else {
			limit	= -2;
		}

	}

	return limit;

}

int error_handle(int limit) {

	if (limit < 0) {

		char *error_message;

		switch (limit) {

			case -1:
				error_message	= "Your input was less than 0, or not an integer.";
				break;

			case -2:
				error_message	= "The argument given should be an integer above 0, and below 65536.";
				break;

			default:
				error_message	= "Unidentified error occured.";
				break;

		}

		printf("%s%s%s\nSee \"%s -h\" for help.\n",
				colour_pale_yellow,
				error_message,
				colour_normal,
				argv[0]);
		return 0;

	} else {

		return 1;

	}

}

int main() {

	/* user input fun */

	unsigned int const limit	= get_limit(argc, argv);
	int error_check				= error_handle(limit, argv[0]);

	if (!error_check) {
		return limit;
	}

	/* generating some fibonacci seq. */

	printf("limit: %d", limit);

	int fibonacci[limit],
		output[limit],
		i	= 2;
	fibonacci[0] = fibonacci[1]	= 1;

	while (fibonacci[i - 1] <= limit) {

		fibonacci[i]	= fibonacci[i - 1] + fibonacci[i - 2];
		i++;

	}

	/* the big loop */

	char find = 'E';

	const char *ptr = strchr(fibonacci, 0);
	if (ptr) {
	   int index = ptr - values;
	}

	j	= limit;
	for (int i )
	
	for (int j = limit; j > 0; j--) {

		int mod	= j;

	}

	/* output */

	printf("Quitting becuase my author hasn't written any code of meaning yet.\n");
	return 0;

}
