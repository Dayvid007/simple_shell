#include "secondheader.h"

/**
 * rpted_char - counts the repetitions of a char
 *
 * @ipt: input string
 * @a: index
 * Return: repetitions
 */
int rpted_char(char *ipt, int a)
{
	if (*(ipt - 1) == *ipt)
		return (rpted_char(ipt - 1, a + 1));

	return (a);
}

/**
 * err_div_op - finds syntax errors
 *
 * @ipt: input string
 * @a: index
 * @last: last char read
 * Return: index of error. 0 when there are no
 * errors
 */
int err_div_op(char *ipt, int a, char last)
{
	int str_count;

	str_count = 0;
	if (*ipt == '\0')
		return (0);

	if (*ipt == ' ' || *ipt == '\t')
		return (err_div_op(ipt + 1, a + 1, last));

	if (*ipt == ';')
		if (last == '|' || last == '&' || last == ';')
			return (a);

	if (*ipt == '|')
	{
		if (last == ';' || last == '&')
			return (a);

		if (last == '|')
		{
			str_count = rpted_char(ipt, 0);
			if (str_count == 0 || str_count > 1)
				return (a);
		}
	}

	if (*ipt == '&')
	{
		if (last == ';' || last == '|')
			return (a);

		if (last == '&')
		{
			str_count = rpted_char(ipt, 0);
			if (str_count == 0 || str_count > 1)
				return (a);
		}
	}

	return (err_div_op(ipt + 1, a + 1, *ipt));
}

/**
 * fest_char - finds index of the first char
 *
 * @ipt: input string
 * @a: index
 * Return: 1 if there is an error. 0 in other case.
 */
int fest_char(char *ipt, int *a)
{

	for (*a = 0; ipt[*a]; *a += 1)
	{
		if (ipt[*a] == ' ' || ipt[*a] == '\t')
			continue;

		if (ipt[*a] == ';' || ipt[*a] == '|' || ipt[*a] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * pint_syn_err - prints when a syntax error is found
 *
 * @datash: data structure
 * @inputs: input string
 * @a: index of the error
 * @bool: to control msg error
 * Return: no return
 */
void pint_syn_err(data_shell *datash, char *inputs, int a, int bool)
{
	char *str_msg, *str_msg2, *str_msg3, *err, *measure;
	int len1;

	if (inputs[a] == ';')
	{
		if (bool == 0)
			str_msg = (inputs[a + 1] == ';' ? ";;" : ";");
		else
			str_msg = (inputs[a - 1] == ';' ? ";;" : ";");
	}

	if (inputs[a] == '|')
		str_msg = (inputs[a + 1] == '|' ? "||" : "|");

	if (inputs[a] == '&')
		str_msg = (inputs[a + 1] == '&' ? "&&" : "&");

	str_msg2 = ": Syntax error: \"";
	str_msg3 = "\" unexpected\n";
	measure = aux_fromitoa(datash->measure);
	len1 = _stringlen(datash->av[0]) + _stringlen(measure);
	len1 += _stringlen(str_msg) + _stringlen(str_msg2) + _stringlen(str_msg3) + 2;

	err = malloc(sizeof(char) * (len1 + 1));
	if (err == 0)
	{
		free(measure);
		return;
	}
	_stringcpy(err, datash->av[0]);
	_stringcat(err, ": ");
	_stringcat(err, measure);
	_stringcat(err, str_msg2);
	_stringcat(err, str_msg);
	_stringcat(err, str_msg3);
	_stringcat(err, "\0");

	write(STDERR_FILENO, err, len1);
	free(err);
	free(measure);
}

/**
 * check_syn_err - intermediate function to
 * find and print a syntax error
 *
 * @datash: data structure
 * @inputs: input string
 * Return: 1 if there is an error. 0 in other case
 */
int check_syn_err(data_shell *datash, char *inputs)
{
	int str_beg = 0;
	int str_f_char = 0;
	int a = 0;

	str_f_char = fest_char(inputs, &str_beg);
	if (str_f_char == -1)
	{
		pint_syn_err(datash, inputs, str_beg, 0);
		return (1);
	}

	a = err_div_op(inputs + str_beg, 0, *(inputs + str_beg));
	if (a != 0)
	{
		pint_syn_err(datash, inputs, str_beg + a, 1);
		return (1);
	}

	return (0);
}
