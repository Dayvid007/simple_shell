#include "secondheader.h"

/**
 * cd_dt - This program  changes to the parent directory
 * @datash: data relevant (enviroment)
 * Return: no return
 */

void cd_dt(data_shell *datash)
{
	char printwd[PATH_MAX];
	char *direc, *cp_printwd, *cp_strtok_printwd;

	getcwd(printwd, sizeof(printwd));
	cp_printwd = _stringdup(printwd);
	st_env("OLDPWD", cp_printwd, datash);
	direc = datash->args[1];
	if (_stringcmp(".", direc) == 0)
	{
		st_env("PWD", cp_printwd, datash);
		free(cp_printwd);
		return;
	}
	if (_stringcmp("/", cp_printwd) == 0)
	{
		free(cp_printwd);
		return;
	}
	cp_strtok_printwd = cp_printwd;
	reverse_string(cp_strtok_printwd);
	cp_strtok_printwd = _stringtok(cp_strtok_printwd, "/");
	if (cp_strtok_printwd != NULL)
	{
		cp_strtok_printwd = _stringtok(NULL, "\0");

		if (cp_strtok_printwd != NULL)
			reverse_string(cp_strtok_printwd);
	}
	if (cp_strtok_printwd != NULL)
	{
		chdir(cp_strtok_printwd);
		st_env("PWD", cp_strtok_printwd, datash);
	}
	else
	{
		chdir("/");
		st_env("PWD", "/", datash);
	}
	datash->position = 0;
	free(cp_printwd);
}

/**
 * cd_to_this - A program that changes to a
 * directory given by the user
 * @datash: data relevant (directories)
 * Return: no return
 */

void cd_to_this(data_shell *datash)
{
	char printwd[PATH_MAX];
	char *direc, *cp_printwd, *cp_direc;

	getcwd(printwd, sizeof(printwd));

	direc = datash->args[1];
	if (chdir(direc) == -1)
	{
		gt_err(datash, 2);
		return;
	}

	cp_printwd = _stringdup(printwd);
	st_env("OLDPWD", cp_printwd, datash);

	cp_direc = _stringdup(direc);
	st_env("PWD", cp_direc, datash);

	free(cp_printwd);
	free(cp_direc);

	datash->position = 0;

	chdir(direc);
}

/**
 * cd_before - A program changes to
 * the previous directory
 * @datash: data relevant (environ)
 * Return: no return
 */

void cd_before(data_shell *datash)
{
	char printwd[PATH_MAX];
	char *p_printwd, *p_oldprintwd, *cp_printwd, *cp_oldprintwd;

	getcwd(printwd, sizeof(printwd));
	cp_printwd = _stringdup(printwd);

	p_oldprintwd = _gtenv("OLDPWD", datash->_environment);

	if (p_oldprintwd == NULL)
		cp_oldprintwd = cp_printwd;
	else
		cp_oldprintwd = _stringdup(p_oldprintwd);

	st_env("OLDPWD", cp_printwd, datash);

	if (chdir(cp_oldprintwd) == -1)
		st_env("PWD", cp_printwd, datash);
	else
		st_env("PWD", cp_oldprintwd, datash);

	p_printwd = _gtenv("PWD", datash->_environment);

	write(STDOUT_FILENO, p_printwd, _stringlen(p_printwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_printwd);
	if (p_oldprintwd)
		free(cp_oldprintwd);

	datash->position = 0;

	chdir(p_printwd);
}

/**
 * cd_to_origin - This program changes to home directory
 * @datash: data relevant (environ)
 * Return: no return
 */

void cd_to_origin(data_shell *datash)
{
	char *p_printwd, *origin;
	char printwd[PATH_MAX];

	getcwd(printwd, sizeof(printwd));
	p_printwd = _stringdup(printwd);
       
	origin = _gtenv("HOME", datash->_environment);

	if (origin == NULL)
	{
		st_env("OLDPWD", p_printwd, datash);
		free(p_printwd);
		return;
	}

	if (chdir(origin) == -1)
	{
		gt_err(datash, 2);
		free(p_printwd);
		return;
	}

	st_env("OLDPWD", p_printwd, datash);
	st_env("PWD", origin, datash);
	free(p_printwd);
	datash->position = 0;
}
