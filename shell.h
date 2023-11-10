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

#define READ_BUFFER 2048
#define WRITE_BUFFER 2048
#define FREE_BUFFER 0


/*STRUCTS*/


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
char *_memset(char *s, char bb, unsigned int n);
void th_freesos(char **p);
void *th_realloc(void *ptr, unsigned int old, unsigned int _new);
int th_isatty(int fd);
int th_isalpha(int c);
int th_is_exec(data_t *data, char *pth_ad);
int th_isDelimeter(char c, char *delimeter);

#endif
