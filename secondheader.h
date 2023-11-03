#ifndef SECONDHEADER_H
#define SECONDHEADER_H

/**inluding the header directive "header.h"*/
#include "header.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

/* aux_lists.c */

/**initially "sep_list *add_sep_node_end(sep_list **head, char sep);"*/
sep_list *add_sep_node(sep_list **head, char divide);

/**initially "void free_sep_list(sep_list **head);"*/
void free_sep(sep_list **head);

/**initially "line_list *add_line_node_end(line_list **head, char *line);"*/
line_list *add_line_node(line_list **head, char *straight_line);

/**initially "void free_line_list(line_list **head);"*/
void free_line_list(line_list **head);

/**End of aux_lists.c*/


/* aux_lists2.c */

/**"r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);"*/
r_var *add_rvar(r_var **head, int Ivap, char *var, int ival);

/**initially "void free_rvar_list(r_var **head);"*/
void free_rvar(r_var **head);

/**End of aux_lists2.c*/


/* aux_str functions */
char *_stringcat(char *new_src, const char *src);
char *_stringcpy(char *new_src, char *src);
int _stringcmp(char *string1, char *string2);
char *_stringchr(char *string, char cha);
int _stringspn(char *string, char *granted);
/**End of aux_str functions*/


/* aux_mem.c */

/**"void _memcpy(void *newptr, const void *ptr, unsigned int size);"*/
void _memorycpy(void *newpointer, const void *pointer, unsigned int size);

/**"void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);"*/
void *_reallocate(void *point, unsigned int prevs_size, unsigned int nw_size);

/**"**_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);"*/
char **_realocdp(char **point, unsigned int prevs_size, unsigned int nw_size);

/**End of aux_mem.c*/


/* aux_str2.c */

/**"char *_strdup(const char *s);"*/
char *_stringdup(const char *string);

/**"int _strlen(const char *s);"*/
int _stringlen(const char *string);

/**"int cmp_chars(char str[], const char *delim);"*/
int compare_chars(char string[], const char *delim);

/**"*char_strtok(char str[], const char *delim);"*/
char *_stringtok(char string[], const char *delim);

/**"int _isdigit(const char *s);"*/
int _isdigit(const char *string);

/**End of aux_str2.c*/

/* aux_str3.c */

/**"void rev_string(char *s);"*/
void reverse_string(char *string);

/**End of aux_str3.c*/


/* check_syntax_error.c */

/**"int repeated_char(char *input, int i);"*/
int rpted_char(char *ipt, int a);

/**"int error_sep_op(char *input, int i, char last);"*/
int err_div_op(char *ipt, int a, char last);

/**"int first_char(char *input, int *i);"*/
int fest_char(char *ipt, int *a);

/**"void print_syntax_error(data_shell*datash,char *input,int i, int bool);"*/
void pint_syn_err(data_shell *datash, char *inputs, int a, int bool);

/**"int check_syntax_error(data_shell *datash, char *input);"*/
int check_syn_err(data_shell *datash, char *inputs);

/**End check syntax error.c*/


/* shell_loop.c */

/**"char *without_comment(char *in);"*/
char *without_comment(char *in);

/**"void shell_loop(data_shell *datash);"*/
void shell_loop(data_shell *datash);

/**End of shell_loop.c**/


/* read_line.c */
/**"*read_line(int *i_eof);"*/
char *rd_ln(int *i_eof);

/**End read_line.c*/


/* split.c */

/**"char *swap_char(char *input, int bool);"*/
char *swp_cha(char *ipt, int bool);

/**"void add_nodes(sep_list **head_s, line_list **head_l, char *input);"*/
void add_node(sep_list **head_s, line_list **head_l, char *inputs);

/**"void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);"*/
void pull_nxt(sep_list **list_s, line_list **list_l, data_shell *datash);

/**"int split_commands(data_shell *datash, char *input);"*/
int divide_cmds(data_shell *datash, char *input);

/**"char **split_line(char *input);"*/
char **line_split(char *inputs);

/**End of split.c*/


/* rep_var.c */

/**"void check_env(r_var **h, char *in, data_shell *data);"*/
void chck_environ(r_var **h, char *in, data_shell *data);


/**"int check_vars(r_var **h, char *in, char *st, data_shell *data);"*/
int chck_variable(r_var **h, char *in, char *st, data_shell *data);

/**"char*replaced_input(r_var **head,char *input,char *new_input, intnlen);"*/
char *rpced_inputs(r_var **head, char *input, char *new_input, int nlen);

/**"char *rep_var(char *input, data_shell *datash);"*/
char *rep_variable(char *inputs, data_shell *datash);

/**End rep_var.c*/


/* get_line.c */

/**"void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);"*/
void get_line(char **lnptr, size_t *n, char *buffer, size_t a);

/**"ssize_t get_line(char **lineptr, size_t *n, FILE *stream);"*/
ssize_t get_line(char **lnptr, size_t *n, FILE *streaming);

/* exec_line */

/**"int exec_line(data_shell *datash);"*/
int execute_ln(data_shell *datash);

/* cmd_exec.c */

/**"int is_cdir(char *path, int *i);"*/
int is_cdirectory(char *pat, int *i);

/**"char *_which(char *cmd, char **_environ);"*/
char *_whch(char *cmd, char **_environment);

/**"int is_executable(data_shell *datash);"*/
int is_execute(data_shell *datash);

/**"int check_error_cmd(char *dir, data_shell *datash);"*/
int chck_err_cmd(char *dir, data_shell *datash);

/**"int cmd_exec(data_shell *datash);"*/
int cmd_execute(data_shell *datash);

/* env1.c */

/**"char *_getenv(const char *name, char **_environ);"*/
char *_gtenv(const char *name, char **_environment);

/**"int _env(data_shell *datash);"*/
int _env(data_shell *datash);

/* env2.c */

/**"char *copy_info(char *name, char *value);"*/
char *copy_info(char *name, char *val);

/**"void set_env(char *name, char *value, data_shell *datash);"*/
void st_env(char *name, char *val, data_shell *datash);

/**"int _setenv(data_shell *datash);"*/
int _stenv(data_shell *datash);

/**"int _unsetenv(data_shell *datash);"*/
int _unstenv(data_shell *datash);

/* cd.c */

/**"void cd_dot(data_shell *datash);"*/
void cd_dt(data_shell *datash);

/**"void cd_to(data_shell *datash);"*/
void cd_to_this(data_shell *datash);

/**"void cd_previous(data_shell *datash);"*/
void cd_before(data_shell *datash);

/**"void cd_to_home(data_shell *datash);"*/
void cd_to_origin(data_shell *datash);

/* cd_shell.c */

/**"int cd_shell(data_shell *datash);"*/
int cd_shell(data_shell *datash);

/* get_builtin */

/**"int (*get_builtOOBin(char *cmd))(data_shell *datash);"*/
int (*get_builtOOBin(char *cmd))(data_shell *datash);

/* _exit.c */

/**"int exit_shell(data_shell *datash);"*/
int exit_theshell(data_shell *datash);

/* aux_stdlib.c */

/**"int get_len(int n);"*/
int get_length(int n);

/**"char *aux_itoa(int n);"*/
char *aux_fromitoa(int b);

/**"int _atoi(char *s);"*/
int _atoi(char *s);

/* aux_error1.c */

/**"char *strcat_cd(data_shell *, char *, char *, char *);"*/
char *strconcat_cd(data_shell *, char *, char *, char *);

/**"char *error_get_cd(data_shell *datash);"*/
char *err_gt_cd(data_shell *datash);

/**"char *error_not_found(data_shell *datash);" */
char *err_absent(data_shell *datash);
/**"error_exit_shell(data_shell *datash)"*/
char *err_depart_shell(data_shell *datash);

/* aux_error2.c */
/**"char *error_get_alias(char **args)"*/
char *err_gt_alter(char **args);
/**"char *error_env(data_shell *datash);*/
char *err_environ(data_shell *datash);
/**"char *error_syntax(char **args);"*/
char *err_syn(char **args);
/**"char *error_permission(char **args);"*/
char *err_permit(char **args);
/**"char *error_path_126(data_shell *datash);"*/
char *err_pt_126(data_shell *datash);


/* get_error.c */
/**"int get_error(data_shell *datash, int eval);"*/
int gt_err(data_shell *datash, int evaluate);

/* get_sigint.c */
/**"void get_signint(int sig);"*/
void gt_signedinnt(int sigma);

/* aux_help.c */
/**"void aux_help_env(void);"*/
void ax_assist_envir(void);
/**"void aux_help_setenv(void)"*/
void ax_assist_setenver(void);
/**"void aux_help_unsetenv(void)"*/
void ax_assist_unsetenver(void);
/**"void aux_help_general(void);*/
void ax_assist_gen(void);
/**"void aux_help_exit(void);"*/
void ax_assist_depart(void);

/* aux_help2.c */
/**"void aux_help(void)"*/
void ax_assist(void);
/**"void aux_help_alias(void);"*/
void ax_assist_alias(void);
/**"void aux_help_cd(void);"*/
void ax_assist_cdir(void);

/* get_help.c */
/**"int get_help(data_shell *datash);"*/
int gt_assist(data_shell *datash);
#endif
