#include 

/**
 * th_realloc - Reallocates memory block to the specified size
 * @ptr: Pointer to the previous memory block
 * @old_size: Size of the previous memory block
 * @new_size: Size of the new memory block
 * 
 * This function reallocates memory for a block of memory pointed to by ptr. 
 * The block is resized to the new_size bytes while preserving its contents.
 * 
 * Return: On success, returns a pointer to the newly allocated memory block.
 *         On failure or if new_size is zero and ptr is not NULL, returns NULL.
 */
void *th_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *new;
    char *old;

    unsigned int i = 0;

    if (ptr == NULL)
        return (malloc(new_size));

    if (new_size == old_size)
        return (ptr);

    if (new_size == 0 && ptr != NULL)
    {
        free(ptr);
        return (NULL);
    }

    new = malloc(new_size);
    old = ptr;
    
    if (new == NULL)
        return (NULL);

    if (new_size > old_size)
    {
        while (i < old_size)
        {
            new[i] = old[i];
            i++;
        }

        free(ptr);
        
        while (i < new_size)
        {
            new[i] = '\0';
            i++;
        }
    }

    if (new_size < old_size)
    {
        while (i < new_size)
        {
            new[i] = old[i];
            i++;
        }

        free(ptr);
    }

    return (new);
}

/**
 * execute - executes a command
 * @argv: array of arguments
 */

void th_execute(char **argv)
{

	int do_, status;

	if (!argv || !argv[0])
		return;
	do_ = fork();
	if (do_ == -1)
	{
		perror(th_getenv("_"));
	}
	if (do_ == 0)
	{
		execve(argv[0], argv, environ);
    {
			perror(argv[0]);
    }
		exit(EXIT_FAILURE);
	}
	wait(&status);
}
