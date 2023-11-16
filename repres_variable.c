#include "secondheader.h"

/**
 * chck_environ - checks if the typed variable is an env variable
 *
 * @h: head of linked list
 * @in: input string
 * @data: data structure
 * Return: no return
 */
void chck_environ(r_var **h, char *in, data_shell *data)
{
	int str_row, chr_ome, i, str_lval;
	char **_evian;

	_evian = data->_environment;
	for (str_row = 0; _evian[str_row]; str_row++)
	{
		for (i = 1, chr_ome = 0; _evian[str_row][chr_ome]; chr_ome++)
		{
			if (_evian[str_row][chr_ome] == '=')
			{
				str_lval = _stringlen(_evian[str_row] + chr_ome + 1);
				add_rvar(h, i, _evian[str_row] + chr_ome + 1, str_lval);
				return;
			}

			if (in[i] == _evian[str_row][chr_ome])
				i++;
			else
				break;
		}
	}

	for (i = 0; in[i]; i++)
	{
		if (in[i] == ' ' || in[i] == '\t' || in[i] == ';' || in[i] == '\n')
			break;
	}

	add_rvar(h, i, NULL, 0);
}

/**
 * chck_variable - check if the typed variable is $$ or $?
 *
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * Return: no return
 */
int chck_variable(r_var **h, char *in, char *st, data_shell *data)
{
	int k, sa_lst, pa_lpd;

	sa_lst = _stringlen(st);
	pa_lpd = _stringlen(data->pid);

	for (k = 0; in[k]; k++)
	{
		if (in[k] == '$')
		{
			if (in[k + 1] == '?')
				add_rvar(h, 2, st, sa_lst), k++;
			else if (in[k + 1] == '$')
				add_rvar(h, 2, data->pid, pa_lpd), k++;
			else if (in[k + 1] == '\n')
				add_rvar(h, 0, NULL, 0);
			else if (in[k + 1] == '\0')
				add_rvar(h, 0, NULL, 0);
			else if (in[k + 1] == ' ')
				add_rvar(h, 0, NULL, 0);
			else if (in[k + 1] == '\t')
				add_rvar(h, 0, NULL, 0);
			else if (in[k + 1] == ';')
				add_rvar(h, 0, NULL, 0);
			else
				chck_environ(h, in + k, data);
		}
	}

	return (k);
}

/**
 * rpced_inputs - replaces string into variables
 *
 * @head: head of the linked list
 * @input: input string
 * @new_input: new input string (replaced)
 * @nlen: new length
 * Return: replaced string
 */
char *rpced_inputs(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *indices;
	int a, b, c;

	indices = *head;
	for (b = a = 0; a < nlen; a++)
	{
		if (input[b] == '$')
		{
			if (!(indices->variable_length) && !(indices->value_length))
			{
				new_input[a] = input[b];
				b++;
			}
			else if (indices->variable_length && !(indices->value_length))
			{
				for (c = 0; c < indices->variable_length; c++)
					b++;
				a--;
			}
			else
			{
				for (c = 0; c < indices->value_length; c++)
				{
					new_input[a] = indices->value[c];
					a++;
				}
				b += (indices->variable_length);
				a--;
			}
			indices = indices->next;
		}
		else
		{
			new_input[a] = input[b];
			b++;
		}
	}

	return (new_input);
}

/**
 * rep_variable - calls functions to replace string into vars
 *
 * @input: input string
 * @datash: data structure
 * Return: replaced string
 */
char *rep_variable(char *input, data_shell *datash)
{
	r_var *head, *indices;
	char *position, *new_input;
	int len1, len2;

	position = aux_fromitoa(datash->position);
	head = NULL;

	len1 = chck_variable(&head, input, position, datash);

	if (head == NULL)
	{
		free(position);
		return (input);
	}

	indices = head;
	len2 = 0;

	while (indices != NULL)
	{
		len2 += (indices->value_length - indices->variable_length);
		indices = indices->next;
	}

	len2 += len1;

	new_input = malloc(sizeof(char) * (len2 + 1));
	new_input[len2] = '\0';

	new_input = rpced_inputs(&head, input, new_input, len2);

	free(input);
	free(position);
	free_rvar(&head);

	return (new_input);
}
