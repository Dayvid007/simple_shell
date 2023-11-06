#include "secondheader.h"

/**
 * ax_assist_envir - A program that helps
 * information for the builtin env
 * Return: no return
 */

void ax_assist_envir(void)
{
	char *gvhelp = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, gvhelp, _stringlen(gvhelp));
	gvhelp = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, gvhelp, _stringlen(gvhelp));

}

/**
 * aux_assist_setenver - A program that helps
 * information for the builtin setenv
 * Return: no return
 */

void aux_assist_setenver(void)
{

	char *gvhelp = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, gvhelp, _stringlen(gvhelp));
	gvhelp = "int replace)\n\t";
	write(STDOUT_FILENO, gvhelp, _stringlen(gvhelp));
	gvhelp = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, gvhelp, _stringlen(gvhelp));
}

/**
 * aux_assist_unsetenver - This program helps
 * information for the builtin unsetenv
 * Return: no return
 */

void aux_assist_unsetenver(void)
{
	char *gvhelp = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, gvhelp, _stringlen(gvhelp));
	gvhelp = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, gvhelp, _stringlen(gvhelp));
}

/**
 * aux_assist_gen - Entry point for help
 * information for the help builtin
 * Return: no return
 */

void aux_assist_gen(void)
{
	char *gvhelp = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, gvhelp, _stringlen(gvhelp));
	gvhelp = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, gvhelp, _stringlen(gvhelp));
	gvhelp = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, gvhelp, _stringlen(gvhelp));
	gvhelp = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, gvhelp, _stringlen(gvhelp));
	gvhelp = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, gvhelp, _stringlen(gvhelp));
	gvhelp = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, gvhelp, _stringlen(gvhelp));
	gvhelp = "unsetenv [variable]\n";
	write(STDOUT_FILENO, gvhelp, _stringlen(gvhelp));
}

/**
 * aux_assist_depart - This proograms helps
 * information fot the builint exit
 * Return: no return
 */

void aux_assist_depart(void)
{
	char *gvhelp = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, gvhelp, _stringlen(gvhelp));
	gvhelp = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, gvhelp, _stringlen(gvhelp));
	gvhelp = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, gvhelp, _stringlen(gvhelp));
}
