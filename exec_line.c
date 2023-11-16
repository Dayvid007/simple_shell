#include "secondheader.h"

/**
 * execute_ln - This program finds builtins and commands
 * @datash: data relevant (args)
 * Return: 1 on success.
 */

int execute_ln(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtOOBin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_execute(datash));
}
