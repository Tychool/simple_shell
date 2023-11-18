#ifndef SHELL_HEADER
#define SHELL_HEADER

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

#define READ_BUFFER 512
#define WRITE_BUFFER 512
#define FREE_BUFFER -1

#define GETCWD_FAIL "failed to get current working dir!!\n"
#define NOT_FOUND_MSG "Not found"
#define PROCESS_ERROR "Process failed!!\n"
#define PROCESS_ERROR_1 "permission denied\n"


#define TAB "\t"

#define EXIT_ERROR_0 "Invalid exit status\n"
#define ARG_ERROR0 "Argument not found \n"
#define ARG_ERROR1 "Invalid number of arguments\n"

#define H_PTH "shell_history"
#define H_MAX 2048
#define C_OR 0x01
#define C_AND 0x02
#define CH_CMD 0x03
#define C_NORMAL 0x00
#define CONV_LCASE 0x01
#define CONV_UNSGND 0x02
#define GET_LINE 0x00
#define STR_TOK 0x00




/**
 * struct th_lists - our sigly linked list
 * @nn: numbers
 * @str: strings
 * @nxt: next node
 */
typedef struct th_lists
{
	int nn;
	char *str;

	struct th_lists *nxt;
} list_t;
/*STRUCTS TYPEDEF*/
/**
 * struct th_data_pass - contains list of arguments that can
 * be passed into a function to allow us use a more consistent
 * and unchanging prototype for function  this func pointer
 * --------------------
 * FOR ARGUMENTS
 * --------------------
 * @arg_vector: argument vectors
 * @arg_count: argument counts
 * @argument: commands passed through user input
 * --------------------
 * PATHS
 * --------------------
 * @pth_ad: command path
 * @current_line: current line
 * --------------------
 * ERROR
 * --------------------
 * @error_index: count error in line
 * @error_no: error number
 *
 * --------------------
 * HISTORY
 * --------------------
 * @his: history
 * @his_line: line numbering for history
 *
 * --------------------
 * ENVIROMENTS
 * --------------------
 * @env_cp: local copy of enviroment (in a list)
 * env_mod: copy of modified enviroment
 * @env_ch: making sure to note a change in enviroment
 * @alias: alias
 * --------------------
 * COMMANDS
 * --------------------
 * @name: file input name
 * @fd_r: where to get commands
 * @cmd_stat: status of last commad
 * @cmd_buffer: buffer array for chain commands
 * @buffer_t: buffer type
 */
typedef struct th_data_pass
{
	/*arguments*/
	int arg_count;
	char *arguments;
	char **arg_vector;
	/*PATHS*/
	char *pth_ad;
	int current_line;
	/*ERROR*/
	unsigned int error_index;
	int error_no;
	/*HISTORY*/
	list_t *his;
	int his_line;
	/*ENVIROMENTS*/
	int env_ch;
	char **env_mod;
	list_t *env_cp;
	list_t *alias;
	/*COMMANDS*/
	char *name;
	char **cmd_buffer;
	int fd_r;
	int cmd_stat;
	int buffer_t;
} data_t;

#define INIT_DATA_T \
	(data_t){\
	.arg_count = 0, \
	.arguments = NULL, \
	.arg_vector = NULL, \
	.pth_ad = NULL, \
	.current_line = 0, \
	.error_index = 0,\
	.error_no = 0, \
	.his = NULL, \
	.his_line = 0, \
	.env_ch = 0, \
	.env_mod = NULL, \
	.env_cp = NULL, \
	.alias = NULL, \
	.name = NULL, \
	.cmd_buffer = NULL, \
	.fd_r = 0, \
	.cmd_stat = 0, \
	.buffer_t = 0,\
}
/**
 * struct builtin_table - files
 * @t: to files
 * @f: first files
 * Return: Void
 */
typedef struct builtin_table
{
	char *t;
	int (*f)(data_t *);
}
builtin_t;

/*PROTOTYPES*/

/*0-built*/
int th_alias(data_t *data);
int th_printas(list_t *nd);
int th_aliastostr(data_t *data, char *str);
int th_init_aliastostr(data_t *data, char *str);

/*0-err functions*/
int th_erroutc(char c);
void th_errouts(char *str);
int th_err_atoi(char *s);
int th_pdec(int in, int file_d);

/*0-han_da*/
void th_setdata(data_t *data, char **argv);
void th_cleardata(data_t *data);
void th_freedata(data_t *data, int free_all);

/*0-handle env*/
int th_set_env(data_t *data, char *variable, char *env_value);
char **th_get_env(data_t *data);
int th_unset_env(data_t *data, char *variable);
int th_env_del(data_t *data);

/*0-hist*/
char *th_history_pth(data_t *data);
int th_history_list(data_t *data, char *arrays, int lindex);
int th_history_index(data_t *data);
int th_history_rd(data_t *data);

/*0-instruct*/
char *th_itoa(long int nn, int base, int line);
void th_nocomments(char *arrays);
int th_aliasreplace(data_t *data);
int th_var_overwrite(data_t *data);

/*0-lists*/
size_t th_printls(const list_t *first);
void th_freel(list_t **head_nd);
int th_ndi_del(list_t **head_nd, unsigned int i);


/*0-out*/
int th_putchar(char c);
int th_putfile_d(char c, int file_d);
void th_puts(char *str);
int th_putsfile_d(char *str, int file_d);


/*0-para*/
int th_isatty(int fd);
int th_isalpha(int c);
int th_isDelimeter(char c, char *delimeter);

/*0-str*/
char *th_strcpy(char *to, char *from);
char *th_strdup(const char *str);
int th_strlen(char *s);
int th_strcmp(char *str1, char *str2);

/*1-built*/
int th_ch_process_dir(data_t *data);
int th_ch_dir(data_t *data);
int th_exit(data_t *data);
int th_history(data_t *data);

/*1-err*/
void th_perror(data_t *data, char *errmsg);

/*1-lists*/
/*list_t *th_ndb_add(list_t head_nd, const char *str, int nn);*/
ssize_t th_ndi_get(list_t *head_nd, list_t *nd);
size_t th_llen(const list_t *first);
size_t th_print_l(const list_t *first);

/*1-handl_env*/
int th_init_env(data_t *data);
int th_print_env(data_t *data);
char *th_env_value(data_t *data, const char *var_name);
int th_env_fill(data_t *data);

/*1-his*/
int th_history_w(data_t *data);

/*1-instruct*/
char *th_chars_dup(char *pth, int i, int end);
char *th_pathfinder(data_t *data, char *pth, char *command);
void th_cmd_find(data_t *data);

/*1-param*/
int th_is_inter(data_t *data);
int th_is_exec(data_t *data, char *pth_ad);
int th_iscmd_c(data_t *data, char *arrays, size_t *current_index);
void th_can_chcont(data_t *data, char *arrays,
	size_t *current_index, size_t start, size_t alen);

/*1-str*/
char *th_firstLetter(const char *haystack, const char *needle);
char *th_strcat(char *to, char *from);
int th_stoi(char *s);
int th_str_overwrite(char **oldstr, char *newstr);

/*2-str*/
char **th_tok_strtow(char *st, char *del_st);
char **th_tok_strtowd(char *st, char del_st);

/*2-list_node*/
list_t *th_ndFirst(list_t *nd, char *pre, char ch);
char **th_ltos(list_t *head_nd);
list_t *th_nde_add(list_t **head_nd, const char *str, int nn);
list_t *th_ndb_add(list_t **head_nd, const char *str, int nn);

/*3-str*/
char *th_strncpy(char *to, char *from, int n);
char *th_strncat(char *to, char *from, int n);
char *th_strchr(char *s, char c);
size_t th_str_cnt(const char *str);

/*getline_u*/
void th_signal_handler(int no);
ssize_t th_buffer_in(data_t *data, char **cmd_array, size_t *array_len);
ssize_t th_getinput(data_t *data);
ssize_t th_readbuffer(data_t *data, char *arrays, size_t *size);

/*main.c*/
int main(int argc, char **argv);

/*memFix*/
int th_freeptr(void **ptr);
char *th_memset(char *s, char bytes, unsigned int n);
void th_freesos(char **pstr);
void *th_realloc(void *ptr, unsigned int old, unsigned int _new);

/*shell_run*/
int th_shellrun(data_t *data, char **argv);

/*shell_utils*/
int th_findcmd(data_t *data);
void th_fork(data_t *data);
void th_cmdPTH(data_t *data);

/*th_getline*/
int th_get_line(data_t *data, char **lineptr, size_t *line_len);

/*welcome*/
void welcome(void);

#endif
