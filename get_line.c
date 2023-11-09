#include "secondheader.h"

/**
 * gt_line - A program that assigns the line var for get_line
 * @lnptr: Buffer that store the input str
 * @buffer: str that is been called to line
 * @n: size of line
 * @a: size of buffer
 */

void gt_line(char **lnptr, size_t *n, char *buffer, size_t a)
{

	if (*lnptr == NULL)
	{
		if  (a > TOTALSIZE)
		{
			*n = a;
		}

		else
		{
			*n = TOTALSIZE;
		}

		*lnptr = buffer;
	}

	else if (*n < a)
	{
		if (a > TOTALSIZE)
		{
			*n = a;
		}

		else
		{
			*n = TOTALSIZE;
		}
		*lnptr = buffer;
	}

	else
	{
		_stringcpy(*lnptr, buffer);
		free(buffer);
	}
}

/**
 * get_line - The rogram that Read inpt from stream
 * @lnptr: buffer that stores the input
 * @n: size of lineptr
 * @streaming: stream to read from
 * Return: The number of bytes
 */

ssize_t get_line(char **lnptr, size_t *n, FILE *streaming)
{
	int a;
	static ssize_t inputs;
	ssize_t retrieval;
	char *buffering;
	char letter = 'z';

	if (inputs == 0)
		fflush(streaming);
	else
		return (-1);
	inputs = 0;

	buffering = malloc(sizeof(char) * TOTALSIZE);
	if (buffering == 0)
		return (-1);
	while (letter != '\n')
	{
		a = read(STDIN_FILENO, &letter, 1);
		if (a == -1 || (a == 0 && inputs == 0))
		{
			free(buffering);
			return (-1);
		}
		if (a == 0 && inputs != 0)
		{
			inputs++;
			break;
		}
		if (inputs >= TOTALSIZE)
			buffering= _reallocate(buffering, inputs, inputs + 1);
		buffering[inputs] = letter;
		inputs++;
	}

	buffering[inputs] = '\0';
	gt_line(lnptr, n, buffering, inputs);
	retrieval = inputs;
	if (a != 0)
		inputs = 0;
	return (retrieval);
}
