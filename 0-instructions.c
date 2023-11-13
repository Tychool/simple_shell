#include "shell.h"

/**
 * th_itoa - convert int to char
 *
 * @nn: number
 * @base: base (ie decimal = base10)
 * @line: current line
 * Return: pointer to the conversion
 */
char *th_itoa(long int nn, int base, int line)
{
	/*Define an array for digits in both lowercase and uppercase*/
	static const char *digits_lower = "0123456789abcdef";
	static const char *digits_upper = "0123456789ABCDEF";
	/*Buffer to store the converted string*/
	static char buffer[50];
	char *result = buffer;/*Pointer to the result string*/
	/*char sign = 0;*//*Sign indicator*/
	unsigned long n = (nn < 0 && !(line & CONV_UNSGND)) ? -nn : nn;
	/*Choose the appropriate array of digits based on the lowercase flag*/
	const char *array = (line & CONV_LCASE) ? digits_lower : digits_upper;
	/*Start from the end of the buffer*/
	result = result + sizeof(buffer) - 1;
	*result = '\0';
	/*Convert the number to the specified base*/
	do {
		*--result = array[n % base];
		n = n / base;
	} while (n != 0);
	/*Add sign if the number is negative and not an unsigned conversion*/
	if (nn < 0 && !(line & CONV_UNSGND))
		*--result = '-';
	return (result);
}
