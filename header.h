#ifndef HEADER_H
#define HEADER_H
/**initially "MAIN_H" BEFORE CHANGED TO "HEADER_H" */

/**initially "BUFFSIZE" before changed to "TOTALSIZE" */
#define TOTALSIZE 1024

/**initially "TOK_BUFFSIZE" before changed to "KOT_TOTALSIZE" */
#define KOT_TOTALSIZE 128

/**initially "TOK_DELIM" before changed to "KOT_MILED" */
#define KOT_MILED " \t\r\n\a"

/* This points to an array of pointers to strings called the "environment" */
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

	/**initially variable ["input"] before changed to variable["inputs"] */
	char *inputs;
	char **args;
	/**initially variable["*status"] before chabged to ["position"] */
	int position;
	/**initially variable ["counter"] before changed to ["measure"] */
	int measure;
	/**initially variiable ["**_environ"] before changed to ["**_environment"] */
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
	/**initially "seperator" before changed to "divider" */
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
	/**initially "line" before changed to "straight_line"*/
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
	/**initially "len_var" before changed to "variable_length"*/
	int variable_length;

	/**initially "*val" before changed to "*value"*/
	char *value;

	/**initially "len_val" before changed to "value_length" */
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
	/**initially "*name" before changed to "*cmd_name"*/
	char *cmd_name;
	int (*f)(data_shell *datash);
} builtin_t;

#endif
