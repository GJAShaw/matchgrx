/*
 * file: main.c
 * type: C source
 * project: matchrgx
 *
 * References:
 * https://man7.org/linux/man-pages/man3/regex.3.html
 *
 */

#include <libgen.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

void print_usage(char *executable_name);

int main(int argc, char **argv)
{

	enum    eflags_values{CAN_MATCH_BOL_AND_EOL = 0};
	int     result = 0;
	regex_t regex;

	/* Handle arguments */
	if (argc != 3) {
		print_usage(argv[0]);
		if (argc == 1) {
			/* be nice, and assume user just wanted help */
			exit(EXIT_SUCCESS);
		} else {
			/* usage error, must be punished */
			exit(EXIT_FAILURE);
		}
	}

	/*
	 * Compile the regex argument, argv[1].
	 *
	 * REG_EXTENDED Use extended, not basic, regular expressions
	 * REG_NOSUB    Do not report position of matches
	 */
	result = regcomp(&regex, argv[1], REG_EXTENDED | REG_NOSUB);
	if (result != 0)
		exit(result);


	/*
	 * Test the string argument argv[2] against the compiled regex.
	 *
	 * regexec() ignores nmatch and pmatch arguments if the regex was
	 * compiled using REG_NOSUB, so we supply 0 and NULL.
	 */
	result = regexec(
		&regex,
		argv[2],
		(size_t)0, /* nmatch ignored*/
		(regmatch_t *)NULL, /* pmatch ignored */
		(int)CAN_MATCH_BOL_AND_EOL
	);
	return result;
}

void print_usage(char *executable_name)
{
	puts("\nUsage:");
	puts("To detect one or more regex matches in a string:");
	printf("\t%s%s\n\n", basename(executable_name), " regex string");
	puts("To get this help text:");
	printf("\t%s\n", basename(executable_name));

	puts("");

	puts("Parameters:");
	puts("\tregex:\tan extended regular expression");
	puts("\tstring:\ta string in which to search for the regex");
	puts("");
	puts("\tIt is the user's responsibility to prevent the shell");
	puts("\tmangling any 'special characters' in the arguments.");
	puts("");

	puts("Exit status:");
	puts("\t0:\tsuccessful match, or 'no arguments supplied - gave help'");
	printf("\t%d%s\t%s\n", REG_NOMATCH, ":", "no match, or wrong number of arguments");
	puts("\tAny other status: regex compilation error, see regex(3) man page");
	puts("");

}
