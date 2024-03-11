#include "shell.h"

/**
 * th_exitt - exits the shell
 * @av: array of words of the entered line
 */
void th_exit_sh(char **av)
{
    int i, n;

    if (av[1])
    {
        n = th_atoi(av[1]);
        if (n <= -1)
            n = 2;
        th_free_av(av);
        exit(n);
    }
    for (i = 0; av[i]; i++)
        free(av[i]);
    free(av);
    exit(0);
}

/**
 * th_atoi - converts string to int
 * @s: pointer to a string
 * Return: the integer
 */
int th_atoi(char *s)
{
    int i, cnv_int, sign = 1;

    i = 0;
    cnv_int = 0;
    while (!((s[i] >= '0') && (s[i] <= '9')) && (s[i] != '\0'))
    {
        if (s[i] == '-')
        {
            sign = sign * (-1);
        }
        i++;
    }
    while ((s[i] >= '0') && (s[i] <= '9'))
    {
        cnv_int = (cnv_int * 10) + (sign * (s[i] - '0'));
        i++;
    }
    return (cnv_int);
}

/**
 * th_checkbuild - check for builtin cmd
 * @av: array of arguments
 * Return: pointer to function (void fun(*av))
 */
void (*th_checkbuild(char **av))(char **av)
{
    int i, j;
    thbuild env_mod[] = {
        {"exit", th_exit_sh},
        {"env", th_env},
        {"setenv", th_setenv},
        {"unsetenv", th_unsetenv},
        {NULL, NULL}
    };

    for (i = 0; env_mod[i].name; i++)
    {
        j = 0;
        if (env_mod[i].name[j] == av[0][j])
        {
            for (j = 0; av[0][j]; j++)
            {
                if (env_mod[i].name[j] != av[0][j])
                    break;
            }
            if (!av[0][j])
                return (env_mod[i].func);
        }
    }
    return (0);
}

/**
 * th_add_node_end - adds a new node at the end of a list_path list
 * @head: pointer to pointer to our linked list
 * @str: pointer to string in previous first node
 * Return: address of the new element/node
 */
list_path *th_add_node_end(list_path **head, char *str)
{
    list_path *tmp;
    list_path *new;

    new = malloc(sizeof(list_path));

    if (!new || !str)
    {
        return (NULL);
    }

    new->dir = str;

    new->p = '\0';
    if (!*head)
    {
        *head = new;
    }
    else
    {
        tmp = *head;

        while (tmp->p)
        {
            tmp = tmp->p;
        }

        tmp->p = new;
    }

    return (*head);
}

/**
 * th_add_node_end - add node to the end of a list
 * @head: pointer to a pointer to a linked list
 * @str: pointer previous node
 * Return: pointer to the new node
 */
list_path *th_add_node_end(list_path **head, char *str)
{
    thlist_path *tmp;
    thlist_path *new;

    new = malloc(sizeof(list_path));

    if (!new || !str)
    {
        return (NULL);
    }

    new->dir_name = str;

    new->pth_name = '\0';
    if (!*head)
    {
        *head = new;
    }
    else
    {
        tmp = *head;

        while (tmp->pth_name)
        {
            tmp = tmp->pth_name;
        }

        tmp->pth_name = new;
    }

    return (*head);
}
