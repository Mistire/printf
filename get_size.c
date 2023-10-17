#include "main.h"

/**
 * get_size - Calculates size
 * @format: Formatted string
 * @i: arguments to be printed with the formated string
 *
 * Return: Precision specifier
 */
int get_size(const char *format, int *i)
{
	int curr = *i + 1;
	int x = 0;

	if (format[curr] == 'l')
		x = S_LONG;
	else if (format[curr] == 'h')
		x = S_SHORT;

	if (x == 0)
		*i = curr - 1;
	else
		*i = curr;

	return (x);
}
