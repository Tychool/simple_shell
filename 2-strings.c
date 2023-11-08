#include "shell.h"
/**
 * **th_tok_strtow - split given string into words.
 * Delimeters are ignored
 *
 * @st: string input
 * @del: string delimeter
 *
 * Return: pointer to an array of tok'ed strings
 * or return NULL if fail
 */
char **th_tok_strtow(char *st, char *del_st)
{
	int input_index, word_index;
	int char_index = 0;
	int char_count;
	int num_words = 0;
	char **words;

	/*check for null or empty string input*/
	if (st == NULL || st[0] == 0)
	{
		return (NULL);
	}
	/*is delimeter provided or not*/
	if (del_st == NULL)
	{
		del_st = " ";
	}
	/*count number of words in string input*/
	for (input_index = 0; st[input_index] != '\0'; input_index++)
	{
		if (th_isDelimeter(st[input_index], del_st) &&
		(th_isDelimeter(st[input_index + 1], del_st) ||
		!st[input_index + 1]))
		{
			num_words++;
		}
	}
	/*if there are no words*/
	if (num_words == 0)
	{
		return (NULL);
	}
	/*malloc for array of words*/
	words = malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
	{
		return (NULL);
	}

	/*now lets split input to words*/
	for (input_index = 0, word_index = 0; word_index < num_words; word_index++)
	{
		/*omit leading delimeters*/
		while (th_isDelimeter(st[input_index], del_st))
		{
			input_index++;
		}
		/*count current word*/
		char_count = 0;
		while (!th_isDelimeter(st[input_index + char_count], del_st)
		&& st[input_index + char_count])
		{
			char_count++;
		}
		/*malloc for current word*/
		words[word_index] = malloc(sizeof(char) * (char_count + 1));
		/*if malloc fails*/
		if (words[word_index] == NULL)
		{
			while (char_index < word_index)
			{
				free(words[char_index]);
				char_index++;
			}
			free(words);
			return (NULL);
		}
		/*copy characters to the current word*/
		while (char_index < char_count)
		{
			words[word_index][char_index] = st[input_index++];
		}
		/*terminate current word with NULL*/
		words[word_index][char_index] = 0;
	}
	words[word_index] = NULL;

	return (words);
}

/**
 * th_tok_strtowd - split a given string into word
 * use a single delimeter
 *
 * @st: string input
 * @del_st: string delimeter
 *
 * Return: pointer to an array of tok'ed string
 */
char **th_tok_strtowd(char *st, char del_st)
{
	int input_index, word_index;
	int char_index, char_count;
	int num_words = 0;
	char **words;

	/*check for null or empty string input*/
	if (st == NULL || st[0] == 0)
	{
		return (NULL);
	}
	/*count number of words in string input*/
	for (input_index = 0; st[input_index] != '\0'; input_index++)
	{
		if ((st[input_index] != del_st &&
		st[input_index + 1] == del_st) ||
		(st[input_index] != del_st && !st[input_index +1])
		|| st[input_index + 1] == del_st)
		{
			num_words++;
		}
	}
	/* if no words return NULL*/
	if (num_words == 0)
	{
		return (NULL);
	}
	/*malloc for word array*/
	words = malloc(sizeof(char *) * (num_words + 1));
	if (!words)
	{
		return (NULL);
	}
	/*split input string to word*/
	for (input_index = 0, word_index = 0; word_index < num_words; word_index++)
	{
		/*omit leading delemeter*/
		while (st[input_index] == del_st && st[input_index] != del_st)
		{
			input_index++;
		}
		/*count characters in current words*/
		char_count = 0;
		while (st[input_index + char_count] && st[input_index + char_index] != del_st)
		{
			char_count++;
		}
		/*malloc for current word*/
		words[word_index] = malloc(sizeof(char) * (char_count + 1));
		/*check if malloc fails*/
		if (words[word_index] == NULL)
		{
			for (char_index = 0; char_index < word_index; char_index++)
			{
				free(words[char_index]);
			}
			free(words);
			return (NULL);
		}
		/*copy character to current word*/
		for (char_index = 0; char_index < char_count; char_index++)
		{
			words[word_index][char_index] = st[input_index++];
		}
		/*NULL terminate the word*/
		words[word_index][char_index] = 0;
	}
	/*NULL terminate the array of words*/
	words[word_index] = NULL;

	return (words);
}
