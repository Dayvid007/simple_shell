#include "secondheader.h"

/**
 * get_builtOOBin - This program builtin that
 * pais the command in the arg
 * @cmd: command
 * Return: function pointer of the builtin command
 */

int (*get_builtOOBin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_theshell },
		{ "setenv", _stenv },
		{ "unsetenv", _unstenv },
		{ "cd", cd_shell },
		{ "help", gt_assist },
		{ NULL, NULL }
	};
	int a;

	for (a = 0; builtin[a].cmd_name; a++)
	{
		if (_stringcmp(builtin[a].cmd_name, cmd) == 0)
			break;
	}

	return (builtin[a].f);
}
