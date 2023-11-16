#include "secondheader.h"

/**
 * ax_assist - Help information for the builtin help.
 * Return: no return
 */
void ax_assist(void)
{
	char *new_get_help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, new_get_help, _stringlen(new_get_help));
	new_get_help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, new_get_help, _stringlen(new_get_help));
	new_get_help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, new_get_help, _stringlen(new_get_help));
}
/**
 * ax_assist_alias - Help information for the builtin alias.
 * Return: no return
 */
void ax_assist_alias(void)
{
	char *new_get_help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, new_get_help, _stringlen(new_get_help));
	new_get_help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, new_get_help, _stringlen(new_get_help));
}
/**
 * ax_assist_cdir - Help information for the builtin alias.
 * Return: no return
 */
void ax_assist_cdir(void)
{
	char *new_get_help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, new_get_help, _stringlen(new_get_help));
	new_get_help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, new_get_help, _stringlen(new_get_help));
}
