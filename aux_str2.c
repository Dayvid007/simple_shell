#include "main.h"

/**
 * _stringdup - A program that duplicates a str in the heap memory.
 * @string: Type char pointer str
 * Return: The duplicated string
 */

char *_stringdup(const char *string)
{
	char *new_mem;
	size_t length;

	length = _stringlen(s);
	new_mem = malloc(sizeof(char) * (length + 1));
	if (new_mem == NULL)
		return (NULL);
	_memorycpy(new_mem, string, length + 1);
	return (new_mem);
}

/**
 * _stringlen - This program returns the lenght of a string.
 * @string: Type char pointer.
 * Return: Always 0.
 */
int _stringlen(const char *string)
{
	int length;

	for (length = 0; s[length] != 0; length++)
	{
	}
	return (length);
}

/**
 * compare_chars - This program compares chars of strings
 * @string: input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */

int compare_chars(char string[], const char *delim)
{
	unsigned int a, b, c;

	for (a = 0, c = 0; str[a]; a++)
	{
		for (b = 0; delim[b]; b++)
		{
			if (str[a] == delim[b])
			{
				c++;
				break;
			}
		}
	}
	if (a == c)
		return (1);
	return (0);
}

/**
 * _stringtok - splits a string by some delimiter.
 * @string: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */

char *_stringtok(char string[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (string != NULL)
	{
		if (compare_chars(string, delim))
			return (NULL);
		splitted = string; /*Stores the first address*/
		i = _stringlen(string);
		str_end = &string[i]; /*Stores the last address*/
	}
	str_start = splitted;
	if (str_start == str_end) /*Reaching the particular end*/
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/*Breaking loop with a view to finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - defines if string passed is a number
 *
 * @string: input string
 * Return: 1 if string is a number. 0 in other case.
 */

int _isdigit(const char *string)
{
	unsigned int i;

	for (i = 0; string[i]; i++)
	{
		if (string[i] < 48 || string[i] > 57)
			return (0);
	}
	return (1);
}
