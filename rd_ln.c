#include "secondheader.h"

/**
 * rd_ln - This program reads the input string.
 * @i_eof: return value of getline function
 * Return: input string
 */

char *rd_ln(int *i_eof)
{
	char *get_in = NULL;
	size_t buffsize = 0;

	*i_eof = getline(&get_in, &buffsize, stdin);

	return (get_in);
}
