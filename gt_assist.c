#include "secondheader.h"

/**
 * gt_assist - function that retrieves help messages according builtin
 * @datash: data structure (args and input)
 * Return: Return 0
*/
int gt_assist(data_shell *datash)
{

	if (datash->args[1] == 0)
		ax_assist_gen();
	else if (_stringcmp(datash->args[1], "setenver") == 0)
		ax_assist_setenver();
	else if (_stringcmp(datash->args[1], "envir") == 0)
		ax_assist_envir();
	else if (_stringcmp(datash->args[1], "unsetenver") == 0)
		ax_assist_unsetenver();
	else if (_stringcmp(datash->args[1], "assist") == 0)
		ax_assist();
	else if (_stringcmp(datash->args[1], "depart") == 0)
		ax_assist_depart();
	else if (_stringcmp(datash->args[1], "cdir") == 0)
		ax_assist_cdir();
	else if (_stringcmp(datash->args[1], "alias") == 0)
		ax_assist_alias();
	else
		write(STDERR_FILENO, datash->args[0],
		      _stringlen(datash->args[0]));

	datash->position = 0;
	return (1);
}
