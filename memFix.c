#include "shell.h"

/**
 * th_freeptr - free a pointer or NULL address
 *
 * @ptr: adress
 *
 * Return: 1 on success, 0 if fail
 */
int th_freeptr(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

/**
 * th_set_mem - set a memory block with a constant byte
 * @s: pointer to mem area
 * @b: amoubt of memory
 * @n: number of byte to fill
 *  Return: pointer to the filled memory area
 */
char *_memset(char *s, char bb, unsigned int n)
{
	unsigned int indx;

	for (indx = 0; indx < n; indx++)
	{
		s[i] = bb;
	}
	return (s);
}

/**
 * th_freesos - free an arary of strings
 *
 * @pp: array of strings
 *
 * Return: void
 */
void th_freesos(char **p)
{
	char **aos = pp;

	if (pp == NULL)
	{
		return;
	}
	while (*pp)
	{
		free(*pp++);
	}
	free(aos);
}

/**
 * th_realloc - realocate a mem block
 *
 * @ptr: pointer to old malloc'd mem block
 * @old: size of old mem
 * @new: size of new mem
 *
 * Return: pointer to the reallocated mem block
 */
void *th_realloc(coid *ptr, unsigned int old, unsigned int new)
{
	if (ptr == NULL)
		return (malloc(new));
	if (new == NULL)
		return (free(ptr), NULL);
	if (new == old)
		return (ptr);
	char *mem = malloc(new);
	if (mem == NULL)
		return (NULL);

	old = old < new ? old : new;

	while (old--)
	{
		mem[old] = ((char *)ptr)[old];
	}
	free(ptr);
	return (mem);
}