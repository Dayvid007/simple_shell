#include "secondheader.h"

/**
 * is_cdirectory - checks ":" if is in the current directory.
 * @pat: type char pointer char.
 * @i: type int pointer of index.
 * Return: 1 if the path is searchable in the cd, 0 otherwise.
 */
int is_cdirectory(char *pat, int *i)
{
	if (pat[*i] == ':')
		return (1);

	while (pat[*i] != ':' && pat[*i])
	{
		*i += 1;
	}

	if (pat[*i])
		*i += 1;

	return (0);
}

/**
 * _whch - locates a command
 *
 * @cmd: command name
 * @_environment: environment variable
 * Return: location of the command.
 */
char *_whch(char *cmd, char **_environment)
{
	char *path, *str_path, *tok_path, *str_dir;
	int len1_directory, len1_changecmd, j;
	struct stat st;

	path = _gtenv("PATH", _environment);
	if (path)
	{
		str_path = _stringdup(path);
		len1_changecmd = _stringlen(cmd);
		tok_path = _stringtok(str_path, ":");
		j = 0;
		while (tok_path != NULL)
		{
			if (is_cdirectory(path, &j))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len1_directory = _stringlen(tok_path);
			str_dir = malloc(len1_directory + len1_changecmd + 2);
			_stringcpy(str_dir, tok_path);
			_stringcat(str_dir, "/");
			_stringcat(str_dir, cmd);
			_stringcat(str_dir, "\0");
			if (stat(str_dir, &st) == 0)
			{
				free(str_path);
				return (str_dir);
			}
			free(str_dir);
			tok_path = _stringtok(NULL, ":");
		}
		free(str_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_execute - determines if is an executable
 *
 * @datash: data structure
 * Return: 0 if is not an executable, other number if it does
 */
int is_execute(data_shell *datash)
{
	struct stat st;
	int k;
	char *inbuilt;

	inbuilt = datash->args[0];
	for (k = 0; inbuilt[k]; k++)
	{
		if (inbuilt[k] == '.')
		{
			if (inbuilt[k + 1] == '.')
				return (0);
			if (inbuilt[k + 1] == '/')
				continue;
			else
				break;
		}
		else if (inbuilt[k] == '/' && k != 0)
		{
			if (inbuilt[k + 1] == '.')
				continue;
			k++;
			break;
		}
		else
			break;
	}
	if (k == 0)
		return (0);

	if (stat(inbuilt + k, &st) == 0)
	{
		return (k);
	}
	gt_err(datash, 127);
	return (-1);
}

/**
 * chck_err_cmd - verifies if user has permissions to access
 *
 * @dir: destination directory
 * @datash: data structure
 * Return: 1 if there is an error, 0 if not
 */
int chck_err_cmd(char *dir, data_shell *datash)
{
	if (dir == NULL)
	{
		gt_err(datash, 127);
		return (1);
	}

	if (_stringcmp(datash->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			gt_err(datash, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(datash->args[0], X_OK) == -1)
		{
			gt_err(datash, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmd_execute - executes command lines
 *
 * @datash: data relevant (args and input)
 * Return: 1 on success.
 */
int cmd_execute(data_shell *datash)
{
	pid_t str_pd;
	pid_t wpd;
	int capital;
	int executor;
	char *str_dir;
	(void) wpd;

	executor = is_execute(datash);
	if (executor == -1)
		return (1);
	if (executor == 0)
	{
		str_dir = _whch(datash->args[0], datash->_environment);
		if (chck_err_cmd(str_dir, datash) == 1)
			return (1);
	}

	str_pd = fork();
	if (str_pd == 0)
	{
		if (executor == 0)
			str_dir = _whch(datash->args[0], datash->_environment);
		else
			str_dir = datash->args[0];
		execve(str_dir + executor, datash->args, datash->_environment);
	}
	else if (str_pd < 0)
	{
		perror(datash->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(str_pd, &capital, WUNTRACED);
		} while (!WIFEXITED(capital) && !WIFSIGNALED(capital));
	}

	datash->position = capital / 256;
	return (1);
}
