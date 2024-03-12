#include "shell.h"

int main(void)
{
	ssize_t len = 0;
  	size_t size = 0;
	thlist_path *head = '\0';
	char *buff = NULL, *value, *path_name, **av;
	void (*fun_sh)(char **);

	printf("Welcome to shell by Tshepang and Hezekiahs\n");
	signal(SIGINT, th_sig_handler);
	while (len != EOF)
	{
		th_isatty();
		len = getline(&buff, &size, stdin);
		th_EOF(len, buff);
		av = th_splitstring(buff, " \n");
		if (!av || !av[0])
			execute(av);
		else
		{
			value = th_getenv("PATH");
			head = th_linkpath(value);
			path_name = th_which(av[0], head);
			fun_sh = th_checkbuild(av);
			if (fun_sh)
			{
				free(buff);
				fun_sh(av);
			}
			else if (!path_name)
				execute(av);
			else if (path_name)
			{
				free(av[0]);
				av[0] = path_name;
				execute(av);
			}
		}
	}
	th_free_list(head);
	th_free_av(av);
	free(buff);
	return (0);
}
