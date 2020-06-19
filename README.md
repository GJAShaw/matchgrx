# matchrgx

Command line tool to say if one or more matches of a regular expression exist in a string of characters

Very very simple stuff - there are more sophisticated regex tools for command line out there, which will tell you how many matches there are, where they are, even highlight them for you. This tool is just a simple yes/no utility to detect the presence or absence of a regex match.

Written as an Eclipse C project, hence the presence of .cproject, .project and .settings. Feel free to ignore these. There is only one source file, so it oughtn't to be too difficult to create your own build environment.

## usage
To detect one or more regex matches in a string

	matchrgx regex string

To get this help text

	matchrgx

## parameters
regex:	an extended regular expression

string:	a string in which to search for the regex

It is the user's responsibility to prevent the shell mangling any special characters in the arguments.

## exit status
0:	successful match, or 'no arguments supplied - gave help'

1:	no match

Any other status: regex compilation error, see regex(3) man page.

## references
[Linux Programmer's Manual REGEX(3)](https://man7.org/linux/man-pages/man3/regex.3.html)
