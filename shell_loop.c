#include "secondheader.h"

/**
 * without_comment - This program deletes comments from the input
 * @in: input string
 * Return: input without comments
 */

char *without_comment(char *in)
{
	int a, go_to;

	go_to = 0;
	for (a = 0; in[a]; a++)
	{
		if (in[a] == '#')
		{
			if (a == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[a - 1] == ' ' || in[a - 1] == '\t' || in[a - 1] == ';')
				go_to = a;
		}
	}

	if (go_to != 0)
	{
		in = _reallocate(in, a, go_to + 1);
		in[go_to] = '\0';
	}

	return (in);
}

/**
 * shell_loop - Loop of shell
 * @datash: data relevant (av, input, args)
 * Return: no return.
 */

void shell_loop(data_shell *datash)
{
	int pool, i_eof;
	char *go_in;

	pool = 1;
	while (pool == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		go_in = rd_ln(&i_eof);
		if (i_eof != -1)
		{
			go_in = without_comment(go_in);
			if (go_in == NULL)
				continue;

			if (check_syn_err(datash, go_in) == 1)
			{
				datash->position = 2;
				free(go_in);
				continue;
			}
			go_in = rep_variable(go_in, datash);
			pool = divide_cmds(datash, go_in);
			datash->measure += 1;
			free(go_in);
		}
		else
		{
			pool = 0;
			free(go_in);
		}
	}
}
