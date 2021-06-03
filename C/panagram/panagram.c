/**
 * @file	panagram.c
 * @brief	Program to check whether an input string is a panagram or not
 * @author	Jones <jonessos.ben@gmail.com>
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/** String to be checked */
#define __input_string__	"A quick brown fox jumps over the lazy dog"

/** A hash-map containing unique alphabets that have been observed in the input string as the program runs */
char MappedChars[26];

/**
 * @brief	Return the lowercase letter of the given alphabet
 * @param 1	An alphabet which could be uppercase or lowercase
 * @return	Lowercase alphabet of the input
 */
static inline char ignoreCase(char c)
{
	return isupper(c) ? tolower(c) : c;
}

/**
 * @brief	Check if a given alphabet is already seen in the input text or not
 * @param 1	Alphabet to be searched
 * @return	true: if it's already seen, false: if this is the first occurence
 */
static inline bool isMapped(char c)
{
	int i = 0;

	for (i = 0; i < (int)strlen(MappedChars); i++)
		if (MappedChars[i] == c)
			return true;

	MappedChars[i] = c;

	return false;
}

int main(void)
{
	int count = 0;
	const char * inp = __input_string__;

	for (int i = 0; i < (int)strlen(__input_string__); i++)
		if (isalpha(inp[i]))
			if (!isMapped(ignoreCase(inp[i])))
				if (++count == 26)
					break;

	fprintf(stdout, "Given string is %s panagram\n", (count == 26) ? "a" : "not a");

	return 0;
}
