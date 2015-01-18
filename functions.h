void help(char exe[]) {

	printf("%s by Blieque Mariguan <himself AT blieque.co.uk>,\n", exe);
	printf("https://github.com/blieque/fibo, GPL v3.0\n");

}

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

		if (user_input > 0) {
			limit	= user_input;
		} else {
			limit	= -2;
		}

	}

	return limit;

}

int error_handle(int limit, char *argv[]) {

	if (limit < 0) {

		char *error_message;

		switch (limit) {

			case -1:
				error_message	= "Your input was less than 0, or not an integer.";
				break;

			case -2:
				error_message	= "The argument given should be an integer above 0, and below 65536.";
				break;

			case -3:
				error_message	= "Unrecognised option given and ignored.";
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
