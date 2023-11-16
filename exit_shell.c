#include "secondheader.h"

/**
 * exit_theshell - exits the shell
 *
 * @datash: data relevant (status and args)
 * Return: 0 on success.
 */
int exit_theshell(data_shell *datash)
{
	unsigned int newstatus;
	int is_figures;
	int string_len;
	int huge_number;

	if (datash->args[1] != NULL)
	{
		newstatus = _atoi(datash->args[1]);
		is_figures = _isdigit(datash->args[1]);
		string_len = _stringlen(datash->args[1]);
		huge_number = newstatus > (unsigned int)INT_MAX;
		if (!is_figures || string_len > 10 || huge_number)
		{
			gt_err(datash, 2);
			datash->position = 2;
			return (1);
		}
		datash->position = (newstatus % 256);
	}
	return (0);
}
