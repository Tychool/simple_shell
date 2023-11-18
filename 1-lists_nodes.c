#include "shell.h"

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
		head_nd = head_nd->nxt;
		i++;
	}
	return (head_nd == nd ? i : SIZE_MAX);
}

/**
 * th_llen - lenght of list
 * @first: first member of list
 * Return: list size
 */
size_t th_llen(const list_t *first)
{
	size_t indx;
	for (indx = 0; first; indx++, first = first->nxt)
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
	size_t i;

	for (i = 0; first; i++, first = first->nxt)
	{
		th_puts(th_itoa(first->nn, 10, 0));
		th_puts(": ");
		(first->str != NULL) ? th_puts(first->str) : th_puts(NOT_FOUND_MSG);
	}
	return (i);
}
