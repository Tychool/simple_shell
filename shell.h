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

char *th_strcpy(char *to, char *from);
char *th_strdup(const char *str);
int th_strlen(char *s);
int th_strcmp(char *str1, char *str2);
char *th_firstletter(const char *haystack, const char *needle);
char *th_strcat(char *to, char *from);
int th_stoi(char *s);
int th_str_overwrite(char **oldstr, char *newstr);

#endif
