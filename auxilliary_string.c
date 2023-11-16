#include "secondheader.h"

/**
 * _stringcat - This program concatenate two strings
 * @new_src: char pointer the dest of the copied str
 * @src: const char pointer the source of str
 * Return: the new_src
 */

char *_stringcat(char *new_src, const char *src)
{
	int a;
	int b;

	for (a = 0; new_src[a] != '\0'; a++)
	;
	for (b = 0; src[b] != '\0'; b++)
	{
		new_src[a] = src[b];
		a++;
	}

	new_src[a] = '\0';
	return (new_src);
}

/**
 * *_stringcpy - Copies the string pointed to by src to the new_str.
 * @new_src: Type char pointer the dest of the copied str
 * @src: Type char pointer the source of str
 * Return: the new_src.
 */

char *_stringcpy(char *new_src, char *src)
{

	size_t z;

	for (z = 0; src[z] != '\0'; z++)
	{
		new_src[z] = src[z];
	}
	new_src[z] = '\0';

	return (new_src);
}

/**
 * _stringcmp - A function / program that compares two strings.
 * @string1: type string 1 compared
 * @string2: type string 2 compared
 * Return: Always 0.
 */

int _stringcmp(char *string1, char *string2)
{
	int i;

	for (i = 0; string1[i] == string2[i] && string1[i]; i++)
	;
	if (string1[i] > string2[i])
		return (1);
	if (string1[i] < string2[i])
		return (-1);
	return (0);
}

/**
 * _stringchr - This locates a character in a string,
 * @string: string.
 * @cha: character.
 * Return: first occurence character c.
 */

char *_stringchr(char *string, char cha)
{
	unsigned int i = 0;

	for (; *(string + i) != '\0'; i++)
		if (*(string + i) == cha)
			return (string + i);
	if (*(string + i) == cha)
		return (string + i);
	return ('\0');
}

/**
 * _stringspn - This program gets the length of a prefix substring.
 * @string: initial segment.
 * @granted: accepted bytes.
 * Return: the number of accepted bytes.
 */

int _stringspn(char *string, char *granted)
{
	int a, b, bool;

	for (a = 0; *(string + a) != '\0'; a++)
	{
		bool = 1;
		for (b = 0; *(granted + b) != '\0'; b++)
		{
			if (*(string + a) == *(granted + b))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (a);
}
