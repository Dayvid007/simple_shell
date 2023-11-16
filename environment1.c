#include "secondheader.h"

/**
 * chr_environ_name - compares env variables names
 * with the name passed.
 * @nameenv: name of the environment variable
 * @str_name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int chr_environ_name(const char *nameenv, const char *str_name)
{
	int a = 0;

	while (nameenv[a] != '=')
	{
		if (nameenv[a] != str_name[a])
		{
			return (0);
		}
		a++;
	}
	return (a + 1);
}

/**
 * _gtenv - get an environment variable
 * @name: name of the environment variable
 * @_environment: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *_gtenv(const char *name, char **_environment)
{
	char *ptr_environ;
	int j, str_mov;

	/* Initialize ptr_env value */
	ptr_environ = NULL;
	str_mov = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (j = 0; _environment[j]; j++)
	{
		/* If name and env are equal */
		str_mov = chr_environ_name(_environment[j], name);
		if (str_mov)
		{
			ptr_environ = _environment[j];
			break;
		}
	}

	return (ptr_environ + str_mov);
}

/**
 * _env - prints the evironment variables
 *
 * @datash: data relevant.
 * Return: 1 on success.
 */
int _env(data_shell *datash)
{
	int fir, sec;

	for (fir = 0; datash->_environment[fir]; fir++)
	{

		for (sec = 0; datash->_environment[fir][sec]; sec++)
			;

		write(STDOUT_FILENO, datash->_environment[fir], sec);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->position = 0;

	return (1);
}
