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

	while (first != NULL)
	{
		if (!first->str)
			th_puts(first->str);
		else
			th_puts(NOT_FOUND_MSG);
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
void th_freel(list_t **head_nd)
{
	if (head_nd == NULL || *head_nd == NULL)
	{
		return;
	}

	list_t *current_nd = *head_nd;

	while (current_nd != NULL)
	{
		list_t *next_nd = current_nd->nxt;

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
	
	for (list_t *current_nd = *head_nd; current_nd != NULL && i > 0; current_nd = current_nd->nxt, i--)
	{
		if (i == 0)
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
		i--;
	}
	return (0);
}
