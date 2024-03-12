#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

typedef struct thlist_path
{
    char *dir_name;
    struct thlist_path *pth_name;
} thlist_path;

char *th_which(char *filename, thlist_path *head);
char *th_getenv(const char *name);
list_path *th_add_node_end(thlist_path **head, char *str);
list_path *th_linkpath(char *path);

typedef struct thbuild
{
    char *name;
    void (*func)(char **);
} thbuild;

void (*th_checkbuild(char **av))(char **av);
int th_atoi(char *s);
void th_exit_sh(char **av);
void th_env(char **av);
void th_setenv(char **av);
void th_unsetenv(char **av);

void th_free_av(char **av);
void th_free_list(thlist_path *head);
int th_putchar(char c);
void th_puts(char *str);
int th_strlen(char *s);
char *th_strdup(char *str);
char *th_concat_all(char *name, char *sep, char *value);

char **th_splitstring(char *str, const char *delim);
void th_execute(char **argv);
void *th_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void th_isatty(void);
void th_EOF(int len, char *buff);
void th_sig_handler(int sig_num);

#endif
