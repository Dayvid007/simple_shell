#include "secondheader.h"

/**
 * get_length - This program gets the lenght of a number.
 * @n: type int number.
 * Return: Lenght of a number.
 */

int get_length(int n)
{
	unsigned int num;
	int getlenght = 1;

	if (n < 0)
	{
		getlenght++;
		num = n * -1;
	}
	else
	{
		num = n;
	}
	while (num > 9)
	{
		getlenght++;
		num = num / 10;
	}

	return (getlenght);
}

/**
 * aux_fromitoa -  This program function converts int to string.
 * @n: type int number
 * Return: String.
 */

char *aux_fromitoa(int n)
{
	unsigned int num;
	int gtlenght = get_length(n);
	char *buff;

	buff = malloc(sizeof(char) * (gtlenght + 1));
	if (buff == 0)
		return (NULL);

	*(buff + gtlenght) = '\0';

	if (n < 0)
	{
		num = n * -1;
		buff[0] = '-';
	}
	else
	{
		num = n;
	}

	gtlenght--;
	do {
		*(buff + gtlenght) = (num % 10) + '0';
		num = num / 10;
		gtlenght--;
	}
	while (num > 0)
		;
	return (buff);
}

/**
 * _atoi - This converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */

int _atoi(char *s)
{
	unsigned int counting = 0, size = 0, ouse = 0, pn = 1, m = 1, a;

	while (*(s + counting) != '\0')
	{
		if (size > 0 && (*(s + counting) < '0' || *(s + counting) > '9'))
			break;

		if (*(s + counting) == '-')
			pn *= -1;

		if ((*(s + counting) >= '0') && (*(s + counting) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		counting++;
	}

	for (a = counting - size; a < counting; a++)
	{
		ouse = ouse + ((*(s + a) - 48) * m);
		m /= 10;
	}
	return (ouse * pn);
}
