#include "main.h"

/**
 * _printf - Prints a formatted text
 * @format: The string that needds to be formatted
 * Return: The number of character of the characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int tally = 0;

	va_start(args, format);

	if (format == NULL || (*format == '%' && *(format + 1) == '\0'))
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			handle_format(args, *format, &tally);
		}
		else
		{
			write(1, format, 1);
			tally++;
		}

		format++;
	}

	va_end(args);
	return (tally);
}
