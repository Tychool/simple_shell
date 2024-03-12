#include "shell.h"

/**
 * th_sig_handler - Handle signal
 * @sig_num: type of signal
 */
void th_sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		th_puts("\n$ ");
	}
}

/**
* th_EOF - End of file
* @len: line length from getline
* @buff: buffer
 */
void th_EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			th_puts("\n");
			free(buff);
		}
		exit(0);
	}
}
/**
  * th_isatty - check terminal
  */

void th_isatty(void)
{
	if (isatty(STDIN_FILENO))
		th_puts("$ ");
}
