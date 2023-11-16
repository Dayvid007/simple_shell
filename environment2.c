#include "secondheader.h"

/**
 * copy_info - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @val: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info(char *name, char *val)
{
	char *str_new;
	int length_nm, len_val_new, len1;

	length_nm = _stringlen(name);
	len_val_new = _stringlen(val);
	len1 = length_nm + len_val_new + 2;
	str_new = malloc(sizeof(char) * (len1));
	_stringcpy(str_new, name);
	_stringcat(str_new, "=");
	_stringcat(str_new, val);
	_stringcat(str_new, "\0");

	return (str_new);
}

/**
 * st_env - sets an environment variable
 *
 * @name: name of the environment variable
 * @val: value of the environment variable
 * @datash: data structure (environ)
 * Return: no return
 */
void st_env(char *name, char *val, data_shell *datash)
{
	int j;
	char *vary_environ, *name_env_iron;

	for (j = 0; datash->_environment[j]; j++)
	{
		vary_environ = _stringdup(datash->_environment[j]);
		name_env_iron = _stringtok(vary_environ, "=");
		if (_stringcmp(name_env_iron, name) == 0)
		{
			free(datash->_environment[j]);
			datash->_environment[j] = copy_info(name_env_iron, val);
			free(vary_environ);
			return;
		}
		free(vary_environ);
	}

	datash->_environment = _realocdp(datash->_environment, j,
			sizeof(char *) * (j + 2));
	datash->_environment[j] = copy_info(name, val);
	datash->_environment[j + 1] = NULL;
}

/**
 * _stenv - compares env variables names
 * with the name passed.
 * @datash: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _stenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		gt_err(datash, -1);
		return (1);
	}

	st_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * _unstenv - deletes a environment variable
 *
 * @datash: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _unstenv(data_shell *datash)
{
	char **reallocate_environment;
	char *vary_environ, *name_env_iron;
	int a, b, c;

	if (datash->args[1] == NULL)
	{
		gt_err(datash, -1);
		return (1);
	}
	c = -1;
	for (a = 0; datash->_environment[a]; a++)
	{
		vary_environ = _stringdup(datash->_environment[a]);
		name_env_iron = _stringtok(vary_environ, "=");
		if (_stringcmp(name_env_iron, datash->args[1]) == 0)
		{
			c = a;
		}
		free(vary_environ);
	}
	if (c == -1)
	{
		gt_err(datash, -1);
		return (1);
	}
	reallocate_environment = malloc(sizeof(char *) * (a));
	for (a = b = 0; datash->_environment[a]; a++)
	{
		if (a != c)
		{
			reallocate_environment[b] = datash->_environment[a];
			b++;
		}
	}
	reallocate_environment[b] = NULL;
	free(datash->_environment[c]);
	free(datash->_environment);
	datash->_environment = reallocate_environment;
	return (1);
}
