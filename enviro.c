#include "shell.h"

/**
 * th_env - Print the current environment.
 * @av: Array of arguments (unused).
 */
void th_env(char **av __attribute__ ((unused)))
{
    int i;

    for (i = 0; environ[i]; i++)
    {
        th_puts(environ[i]);
        th_puts("\n");
    }
}

/**
 * th_setenv - Initialize a new environment variable or modify an existing one.
 * @av: Array of entered words.
 */
void th_setenv(char **av)
{
    int i, j, k;

    if (!av[1] || !av[2])
    {
        perror(th_getenv("_"));
        return;
    }

    for (i = 0; environ[i]; i++)
    {
        j = 0;
        if (av[1][j] == environ[i][j])
        {
            while (av[1][j])
            {
                if (av[1][j] != environ[i][j])
                    break;

                j++;
            }
            if (av[1][j] == '\0')
            {
                k = 0;
                while (av[2][k])
                {
                    environ[i][j + 1 + k] = av[2][k];
                    k++;
                }
                environ[i][j + 1 + k] = '\0';
                return;
            }
        }
    }
    if (!environ[i])
    {
        environ[i] = th_concat_all(av[1], "=", av[2]);
        environ[i + 1] = '\0';
    }
}

/**
 * th_unsetenv - Remove an environment variable.
 * @av: Array of entered words.
 */
void th_unsetenv(char **av)
{
    int i, j;

    if (!av[1])
    {
        perror(th_getenv("_"));
        return;
    }

    for (i = 0; environ[i]; i++)
    {
        j = 0;
        if (av[1][j] == environ[i][j])
        {
            while (av[1][j])
            {
                if (av[1][j] != environ[i][j])
                    break;

                j++;
            }
            if (av[1][j] == '\0')
            {
                free(environ[i]);
                environ[i] = environ[i + 1];
                while (environ[i])
                {
                    environ[i] = environ[i + 1];
                    i++;
                }
                return;
            }
        }
    }
}

/**
 * th_getenv - get global variable
 * @name: var name
 * Return: var value (strings)
 */
char *th_getenv(const char *name)
{
    int i, j;
    char *value;

    if (!name)
        return (NULL);
    for (i = 0; environ[i]; i++)
    {
        j = 0;
        if (name[j] == environ[i][j])
        {
            while (name[j])
            {
                if (name[j] != environ[i][j])
                    break;

                j++;
            }
            if (name[j] == '\0')
            {
                value = (environ[i] + j + 1);
                return (value);
            }
        }
    }
    return (0);
}
