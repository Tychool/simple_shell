#include "shell.h"

/**
 * th_printls - print an element of list
 *
 * @first: head of the list
 *
 * Retutn: size of str in list
 */
size_t th_printls(const list_t *first)
{
	size_t indx = 0;

	while (first)
	{
		th_puts(first->str ? first->str : "Non found");
		th_puts("\n");
		first = first->nxt;
		indx++;
	}
	return (indx);
}

/**
 * th_freel - free a list
 * @head_nd: head node
 * Return: nothing
 */
void th_freel(list_t *head_nd)
{
	if (head_nd == NULL || *head_nd == NULL)
	{
		return;
	}

	list_t *current_nd = *head_nd;

	while (current_nd != NULL)
	{
		list_t *next_nd = current_nd->next_nd;

		free(current_nd->str);
		free(current_nd);

		current_nd = next_nd;
	}
	*head_nd = NULL;
}

/**
 * th_ndi_del - delete node at an index
 *
 * @head_nd: head
 * @i: index to delete
 * Return: 1
 */
int th_ndi_del(list_t **head_nd, unsigned int i)
{
	if (head_nd == NULL || *head_nd == NULL)
	{
		return (0);
	}
	if (i == 0)
	{
		list_t *nd = *head_nd;
		*head_nd = (*head_nd)->nxt;
		free(nd->str);
		free(nd);
		return (1);
	}
	list_t *prev = NULL;

	for (list_t *current_nd = *head_nd, unsigned int indx = 0; current != NULL; current_nd = current_nd->nxt, indx++)
	{
		if (indx == i)
		{
			if (prev != NULL)
			{
				prev->nxt = current_nd->nxt;
			}
			free(current_nd->str);
			free(current_nd);
			return (1);
		}
		prev = current_nd;
	}
	return (0);
}

/**
 * th_nde_add - add a node at the end of a list
 * @head_nd:
 * @str: string
 * @nn: number
 *
 * Return: address of new node
 */
list_t *th_nde_add(list_t **head_nd, const char *str, int nn)
{
	if (head == NULL)
	{
		return (NULL);
	}
	list_t *new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	th_memset(new, 0, sizeof(list_t));
	new->nn = nn;

	if (str != NULL)
	{
		new->str = th_strdup(str);
		if (!new->str)
		{
			free(new);
			return (NULL);
		}
	}
	if (*head_nd)
	{
		list_t *nd = head_nd;
		while (nd->nxt)
			nd = nd->nxt;
		nd-nxt = new;
	}
	else
		*head_nd = new;
	return (new);
}
