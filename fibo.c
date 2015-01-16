#include <stdlib.h>
#include <stdio.h>

char const colour_normal[]		= "\033[0m",
		   colour_pale_yellow[]	= "\033[93m";

int get_limit(int argc, char *argv[]) {

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

int error_handle(int limit, char *executable) {

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

		printf("%s%s%s\nSee \"%s -h\" for help.\n", colour_pale_yellow, error_message, colour_normal, executable);
		return 0;

	} else {

		return 1;

	}

}

int main(int argc, char *argv[]) {

	/* user input fun */

	unsigned int const limit	= get_limit(argc, argv);
	int error_check				= error_handle(limit, argv[0]);

	if (!error_check || limit > 200) {
		return limit;
	}

	/* generating some fibonacci seq. */

	int fibonacci[limit],
		output[limit],
		i			= 2;
	fibonacci[0] = fibonacci[1]	= 1;

	while (output[i] <= limit) {

		output[i]	= output[(int)i - 1] + output[(int)i - 2];
		printf("%d\n", output[(int)i - 2]);
		i++;
		
	}

	/* the big loop */

	/* output */

	printf("%d\n", fibonacci[20]);
	printf("%d\n", fibonacci[60]);
	printf("%d\n", fibonacci[80]);

	printf("Quitting becuase my author hasn't written any code of meaning yet.\n");
	return 0;

}
