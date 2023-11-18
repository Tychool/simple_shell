#include "shell.h"

/**
 * th_chars_dup - duplicate characters
 * @pth: path
 * @i: index at the begining
 * @end: index at the end
 * Return: new array of characters
 */
char *th_chars_dup(char *pth, int i, int end)
{
	int indx = i, dup = 0;
	static char arrays[READ_BUFFER];

	while (indx < end)
	{
		if (pth[indx] != ':')
			arrays[dup] = pth[indx];
		indx++;
	}
	arrays[dup] = '\0';
	return (arrays);
}

/**
 * th_pathfinder - loof for commad in a path
 * @data: data
 * @pth: path
 * @command: command
 * Return: command path
 */
char *th_pathfinder(data_t *data, char *pth, char *command)
{
	if (!pth || !th_strlen(command))
		return (NULL);
	if (th_strlen(command) > 2 && th_firstLetter(command, "./")
			&& th_is_exec(data, command))
		return (command);
	int indx, cur_indx = 0;

	for (indx = 0; pth[indx]; indx++)
	{
		if (pth[indx] == ':')
		{
			char *current_path = th_chars_dup(pth, cur_indx, indx);

			th_strcat(current_path, *current_path ? "/" : "");
			th_strcat(current_path, command);

			if (th_is_exec(data, current_path))
				return (current_path);
			cur_indx = indx + 1;
		}
	}
	return (NULL);
}
