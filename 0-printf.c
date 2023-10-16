#include "main.h"

/**
 * _printf - prints a formated text
 * @format: the string that needs to be formated
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	char result[1024] = "";
	char specifier[3] = "";
	va_list arg;

	if (!format)
		return (1);
	va_start(arg, format);
	format_string(arg, format, specifier, result);
	va_end(arg);
	write(1, result, strlen(result));
	return (strlen(result));
}
