#include "shell.h"
/**
 * th_which - find the pathname of a file
 * @filename: command or file name
 * @head: head node of path dir list
 * Return: pathname or NULL if not found
 */
char *th_which(char *filename, th_list_path *head)
{
    char *string;
    struct stat st;

    th_list_path *tmp = head;

    while (tmp)
    {
        string = th_concat_all(tmp->dir_name, "/", filename);
        if (stat(string, &st) == 0)
        {
            return (string);
        }
        free(string);
        tmp = tmp->pth_name;
    }

    return (NULL);
}

/**
 * th_free_list - frees a list
 * @head: pointer to list
 */
void th_free_list(th_list_path *head)
{
    th_list_path *mem;

    while (head)
    {
        mem = head->pth_name;
        free(head->dir_name);
        free(head);
        head = mem;
    }
}
