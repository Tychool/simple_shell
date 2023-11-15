#include "shell.h"

/**
 * th_ndFirst - look for a node that start with a prefix
 *
 * @nd: node
 * @pre: prefix
 * @ch: character to match
 * Return: matching node
 */
list_t *th_ndFirst(list_t *nd, char *pre, char ch)
{
	while (nd && !(th_firstletter(nd->str, pre) &&
	(ch == -1 || nd->str[th_strlen(pre)] == ch)))
	{
		nd = nd->nxt;
	}
	return (nd);
}

/**
 * th_ltos - convert list to strings
 * @head_nd: head
 * Return: array of converted list
 */
char **ltos(list_t *head_nd)
{
	if (head_nd == NULL)
		return (NULL);

	size_t size = th_llen(head_nd);
	if (size == 0)
		return (NULL);

	char **strngs = malloc(sizeof(char *) * (size + 1));
	if (strngs == NULL)
		return (NULL);
	size_t i;

	for (i = 0; head_nd; head_nd = head_nd->nxt, i++)
	{
		strngs[i] = th_strcpy(malloc(th_strlen(head_nd->str) + 1),
		head_nd->str);
		
		if (strngs[i] == NULL)
		{
			while (i > 0)
			{
				free(strngs[--i]);
			}
			free(strngs);
			return (NULL);
		}
	}
	strngs[i] = NULL;
	return (strngs);
}


