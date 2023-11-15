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

#define READ_BUFFER 512
#define WRITE_BUFFER 512
#define FREE_BUFFER -1
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
	int curr_line;
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
	.curr_line = 0, \
	.rror_index = 0,\
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
	.cmd_ = 0, \
	.buffer_t = 0,\
}

typedef struct builtin
{
	char *t;
	int (*f)(data_t *);
} inbuilt_t;
/*PROTOTYPES*/

char *th_strcpy(char *to, char *from);
char *th_strdup(const char *str);
int th_strlen(char *s);
int th_strcmp(char *str1, char *str2);
char *th_firstletter(const char *haystack, const char *needle);
char *th_strcat(char *to, char *from);
int th_stoi(char *s);
int th_str_overwrite(char **oldstr, char *newstr);
int th_is_inter(data_t *data);
char **th_tok_strtow(char *st, char *del_st);
char **th_tok_strtowd(char *st, char del_st);
int th_freeptr(void **ptr);
char *th_memset(char *s, char bb, unsigned int n);
void th_freesos(char **p);
void *th_realloc(void *ptr, unsigned int old, unsigned int _new);
int th_isatty(int fd);
int th_isalpha(int c);
int th_is_exec(data_t *data, char *pth_ad);
int th_isDelimeter(char c, char *delimeter);
int th_putchar(char c);
void th_puts(char *str);
int th_erroutc(char c);
void th_errouts(char *str);
int th_err_atoi(char *s);
int th_pdec(int in, int file_d);
int th_putfile_d(char c, int file_d);
int th_pdec(int in, int file_d);
int th_putsfile_d(char *str, int file_d);
char *th_strncpy(char *to, char *from, int n);
char *th_strncat(char *to, char *from, int n);
char *th_strchr(char *s, char c);



#endif
