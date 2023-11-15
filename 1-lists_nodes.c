#include "shell.h"

/**
 * th_ndb_add - add a node at the begining of list
 *
 * @head_nd: head
 * @str: same for all list_t
 * @nn: same
 *
 * Return: same for all list function
 */
list_t *th_ndb_add(list_t head_nd, const char *str, int nn)
{
	if (head_nd == NULL)
		return (NULL);
	list_t new = maloc(sizeof(list_t));
	if (new_h == NULL)
		return (NULL);
	th_memset(new_h, 0, sizeof(list_t));
	new_h->nn = nn;

	if (str != NULL)
	{
		new_h->str = th_strdup(str);
		if (new_h->str == NULL)
		{
			free(new_h);
			return(NULL);
		}
	}
	new_h-> = *head_nd;
	*head_nd = new_h;
	return (new_h);
}

/**
 * th_ndi_get - get list's node index
 *
 * @head_nd: head
 * @nd: node
 *
 * Return: index
 */
ssize_t th_ndi_get(list_t *head_nd, list_t *nd)
{
	size_t i = 0;

	while (head_nd != NULL && head_nd != nd)
	{
		head_nd = head_nd->next;
		i++;
	}
	return (head_nd == nd ? i : -1);
}

/**
 * th_llen - lenght of list
 * @first: first member of list
 * Return: list size
 */
size_t th_llen(const list_t *first)
{
	for (size_t indx = 0; first; indx++, first = first->nxt)
		;
	return (indx);
}

/**
 * th_print_l - print list
 * @first: first member of list
 * Return: list size
 */
size_t th_print_l(const list_t *first)
{
	for (size_t i = 0; first; i++, first = first->nxt)
	{
		th_puts(th_itoa(first->, 10, 0));
		th_puts(": ");
		(first->str != NULL) th_puts(firsy->str) : th_puts("Not found!");
		th_puts("\n");
	}
	return (i);
}
