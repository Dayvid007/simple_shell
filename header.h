#ifndef HEADER_H
#define HEADER_H
#define TOTALSIZE 1024
#define KOT_TOTALSIZE 128
#define KOT_MILED " \t\r\n\a"


extern char **environ;


/**
 * struct data - This contains all relevant data
 * @av: The argument vector
 * @inputs: user inputting the command line
 * @args: all tokens of the command line
 * @position: status or position of the shell
 * @measure: measuring the lines
 * @_environment: The envirronment variables
 * @pid: process ID (identification) of the shell
 */

typedef struct data
{
	char **av;
	char *inputs;
	char **args;
	int position;
	int measure;
	char **_environment;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - single linked list
 * @divider: either; or| and&
 * @next: next node ->
 * Description: single linked list to store separators
 */

typedef struct sep_list_s
{
	char divider;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @straight_line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */

typedef struct line_list_s
{
	char *straight_line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list
 * @variable_length: length of the variable
 * @value: value of the variable
 * @value_length: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */

typedef struct r_var_list
{
	int variable_length;
	char *value;
	int value_length;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command args.
 * @cmd_name: command line name inputted by the user
 * @f: The data type pointer function.
 */

typedef struct builtin_s
{
	char *cmd_name;
	int (*f)(data_shell *datash);
} builtin_t;

#endif
