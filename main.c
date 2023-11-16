#include "secondheader.h"

/**
 * liberate_data - This program frees data structure
 *
 * @datash: data structure
 * Return: no return
 */

void liberate_data(data_shell *datash)
{
	unsigned int a = 0;

	while (datash->_environment[a])
	{
		free(datash->_environment[a]);
		a++;
	}

	free(datash->_environment);
	free(datash->pid);
}

/**
 * apply_data - This program Initialize data structure
 *
 * @datash: data structure
 * @av: argument vector
 * Return: no return
 */

void apply_data(data_shell *datash, char **av)
{
	unsigned int a;

	datash->av = av;
	datash->inputs = NULL;
	datash->args = NULL;
	datash->position = 0;
	datash->measure = 1;

	for (a = 0; environ[a]; a++)
		;

	datash->_environment = malloc(sizeof(char *) * (a + 1));

	for (a = 0; environ[a]; a++)
	{
		datash->_environment[a] = _stringdup(environ[a]);
	}

	datash->_environment[a] = NULL;
	datash->pid = aux_fromitoa(getpid());
}

/**
 * main - The program's Entry point
 *
 * @agc: argument count
 * @agv: argument vector
 *
 * Return: 0 on success.
 */

int main(int agc, char **agv)
{
	data_shell datash;
	(void) agc;

	signal(SIGINT, gt_signedinnt);
	apply_data(&datash, agv);
	shell_loop(&datash);
	liberate_data(&datash);
	if (datash.position < 0)
		return (255);
	return (datash.position);
}
