#include "shell.h"
#include <time.h>

/**
 * welcome - greetings
 *
 * Return: greetings
 */
void welcome(void)
{
	time_t c_time;
	struct tm *tm_info;

	time(&c_time);
	tm_info = localtime(&c_time);

	if (tm_info->tm_hour < 12)
		th_puts("Good morning\n");
	else if (tm_info->tm_hour < 18)
		th_puts("GOod afternoon");
	else
		th_puts("Good evening");
	
	for (int i = 0; i < 49; i++)
	{
		th_putchar('-');
		th_putchar('\n');
	}
	th_puts("Welcome to Tshepang and Hezekiahs' shell\n");
	printf("%02d:%02d:%02d\n", tm_info->tm_hour,
		tm_info->tm_min, tm_info->tm_sec);
	for (int j = 0; j < 49; j++)
	{
		th_putchar('-');
		th_putchar('-');
	}
}
