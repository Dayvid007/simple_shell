#include "secondheader.h"

/**
 * strconcat_cd - function that concatenates the message for cd error
 *
 * @datash: data relevant (directory)
 * @err_msg: message to print
 * @err: output message
 * @veron_string: counter lines
 * Return: error message
 */
char *strconcat_cd(data_shell *datash, char *err_msg,
char *err, char *veron_string)
{
	char *il_flag;

	_stringcpy(err, datash->av[0]);
	_stringcat(err, ": ");
	_stringcat(err, veron_string);
	_stringcat(err, ": ");
	_stringcat(err, datash->args[0]);
	_stringcat(err, err_msg);
	if (datash->args[1][0] == '-')
	{
		il_flag = malloc(3);
		il_flag[0] = '-';
		il_flag[1] = datash->args[1][1];
		il_flag[2] = '\0';
		_stringcat(err, il_flag);
		free(il_flag);
	}
	else
	{
		_stringcat(err, datash->args[1]);
	}

	_stringcat(err, "\n");
	_stringcat(err, "\0");
	return (err);
}

/**
 * err_gt_cd - error message for cd command in get_cd
 * @datash: data relevant (directory)
 * Return: Error message
 */
char *err_gt_cd(data_shell *datash)
{
	int len1, len_ident;
	char *err, *veron_string, *err_msg;

	veron_string = aux_fromitoa(datash->measure);
	if (datash->args[1][0] == '-')
	{
		err_msg = ": Illegal option ";
		len_ident = 2;
	}
	else
	{
		err_msg = ": can't cd to ";
		len_ident = _stringlen(datash->args[1]);
	}

	len1 = _stringlen(datash->av[0]) + _stringlen(datash->args[0]);
	len1 += _stringlen(veron_string) + _stringlen(err_msg) + len_ident + 5;
	err = malloc(sizeof(char) * (len1 + 1));

	if (err == 0)
	{
		free(veron_string);
		return (NULL);
	}

	err = strconcat_cd(datash, err_msg, err, veron_string);

	free(veron_string);

	return (err);
}

/**
 * err_absent - generic error message for command not found
 * @datash: data relevant (counter, arguments)
 * Return: Error message
 */
char *err_absent(data_shell *datash)
{
	int len1;
	char *err;
	char *veron_string;

	veron_string = aux_fromitoa(datash->measure);
	len1 = _stringlen(datash->av[0]) + _stringlen(veron_string);
	len1 += _stringlen(datash->args[0]) + 16;
	err = malloc(sizeof(char) * (len1 + 1));
	if (err == 0)
	{
		free(err);
		free(veron_string);
		return (NULL);
	}
	_stringcpy(err, datash->av[0]);
	_stringcat(err, ": ");
	_stringcat(err, veron_string);
	_stringcat(err, ": ");
	_stringcat(err, datash->args[0]);
	_stringcat(err, ": not found\n");
	_stringcat(err, "\0");
	free(veron_string);
	return (err);
}

/**
 * err_depart_shell - generic error message for exit in get_exit
 * @datash: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *err_depart_shell(data_shell *datash)
{
	int len1;
	char *err;
	char *veron_string;

	veron_string = aux_fromitoa(datash->measure);
	len1 = _stringlen(datash->av[0]) + _stringlen(veron_string);
	len1 += _stringlen(datash->args[0]) + _stringlen(datash->args[1]) + 23;
	err = malloc(sizeof(char) * (len1 + 1));
	if (err == 0)
	{
		free(veron_string);
		return (NULL);
	}
	_stringcpy(err, datash->av[0]);
	_stringcat(err, ": ");
	_stringcat(err, veron_string);
	_stringcat(err, ": ");
	_stringcat(err, datash->args[0]);
	_stringcat(err, ": Illegal number: ");
	_stringcat(err, datash->args[1]);
	_stringcat(err, "\n\0");
	free(veron_string);

	return (err);
}
