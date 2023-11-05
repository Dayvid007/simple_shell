#include "header.h"
#include "secondheader.h"

/**
 * err_environ - A program that brings  error message for env in get_env.
 * @datash: data relevant (counter, arguments)
 * Return: print error message.
 */

char *err_environ(data_shell *datash)
{
	int getlength;
	char *printerror;
	char *ver_string;
	char *message;

	ver_string = aux_fromitoa(datash->counter);
	message = ": Unable to add/remove from environment\n";
	getlength = _stringlen(datash->av[0]) + _stringlen(ver_string);
	getlength += _stringlen(datash->args[0]) + _stringlen(message) + 4;
	printerror = malloc(sizeof(char) * (length + 1));

	if (printerror == 0)
	{
		free(printerror);
		free(ver_string);
		return (NULL);
	}

	_stringcpy(printerror, datash->av[0]);
	_stringcat(printerror, ": ");
	_stringcat(printerror, ver_string);
	_stringcat(printerror, ": ");
	_stringcat(printerror, datash->args[0]);
	_stringcat(printerror, message);
	_stringcat(printerror, "\0");
	free(ver_string);

	return (printerror);
}

/**
 * err_pt_126 - A program that brings
 * error message for path and failure denied permission.
 * @datash: This gets data relevant (counter, arguments).
 *
 * Return: The error string.
 */

char *err_pt_126(data_shell *datash)
{
	int gtlength;
	char *ver_string;
	char *printerror;

	ver_string = aux_fromitoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_stringcpy(printerror, datash->av[0]);
	_stringcat(printerror, ": ");
	_stringcat(printerror, ver_string);
	_stringcat(printerror, ": ");
	_stringcat(printerror, datash->args[0]);
	_stringcat(printerror, ": Permission denied\n");
	_stringcat(printerror, "\0");
	free(ver_string);
	return (printerror);
}
