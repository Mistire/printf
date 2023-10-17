#include "main.h"

/**
 * _printf - Custom printf function with format specifiers
 * @format: The format string
 * @...: Variable number of arguments
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int char_count = 0;
	char *result = NULL;

	if (!format)
		return (-1);

	va_start(args, format);
	char_count = format_string(&result, format, args);
	va_end(args);

	if (result)
	{
		write(1, result, char_count);
		free(result);
	}

	return (char_count);
}	
