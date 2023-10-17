#include "main.h"

/**
 * get_width - gets width for printing specified thing
 * @format: Formatted string
 * @i: arguments to be printed in the formated text
 * @args: arguments.
 *
 * Return: w
 */
int get_width(const char *format, int *i, va_list args)
{
	int curr_i;
	int w = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			w *= 10;
			w += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			w = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (w);
}
