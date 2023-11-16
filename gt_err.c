#include "secondheader.h"

/**
 * gt_err - calls the error according the builtin, syntax or permission
 * @datash: data structure that contains arguments
 * @evaluate: error value
 * Return: error
 */
int gt_err(data_shell *datash, int evaluate)
{
	char *new_err;

	switch (evaluate)
	{
	case -1:
		new_err = err_environ(datash);
		break;
	case 126:
		new_err = err_pt_126(datash);
		break;
	case 127:
		new_err = err_absent(datash);
		break;
	case 2:
		if (_stringcmp("exit", datash->args[0]) == 0)
			new_err = err_depart_shell(datash);
		else if (_stringcmp("cd", datash->args[0]) == 0)
			new_err = err_gt_cd(datash);
		break;
	}

	if (new_err)
	{
		write(STDERR_FILENO, new_err, _stringlen(new_err));
		free(new_err);
	}

	datash->position = evaluate;
	return (evaluate);
}
