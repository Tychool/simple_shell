#include "shell.h"
/**
 * th_which - find the pathname of a file
 * @filename: command or file name
 * @head: head node of path dir list
 * Return: pathname or NULL if not found
 */
char *th_which(char *filename, thlist_path *head)
{
    char *string;
    struct stat st;

    thlist_path *tmp = head;

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
void th_free_list(thlist_path *head)
{
    thlist_path *mem;

    while (head)
    {
        mem = head->pth_name;
        free(head->dir_name);
        free(head);
        head = mem;
    }
}

/**
 * th_linkpath - generate a linked list of path directories
 * @path: array of paths by ':'
 * Return: pointer to list
 */
thlist_path *th_linkpath(char *path)
{
    thlist_path *head = '\0';
    char *path_cue = th_strdup(path);
    char *tok = strtok(path_cue, ":");
    
    while (tok)
    {
        head = th_add_node_end(&head, tok);
        tok = strtok(NULL, ":");
    }

    return (head);
}
