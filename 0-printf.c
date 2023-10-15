#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include "main.h"
/**
 * chtoStrcat - concatenates a character to a string
 * @str: the string before concatenation
 * @ch: the character to be added to the string
 */
void chtoStrcat(char *str, char ch)
{
	char charstr[2];

	charstr[0] = ch;
	charstr[1] = '\0';
	strcat(str, charstr);
}
/**
 * _printf - prints a formated text
 * @format: the string that needs to be formated
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	char result[150] = "";
	char specifier[3] = "";
	va_list arg;

	va_start(arg, format);
	for (int i = 0; i < strlen(format); i++)
	{
		if (format[i] == '%' && specifier[0] != '%')
			specifier[0] = '%';
		else if (specifier[0] == '%')
			specifier[1] = format[i];
		if (specifier[0] == '%' && specifier[1] == 'c')
		{
			chtoStrcat(result, va_arg(arg, int));
			specifier[0] = ' ';
			specifier[1] = ' ';
			continue;
		}
		else if (specifier[0] == '%' && specifier[1] == 's')
		{
			strcat(result, va_arg(arg, char *));
			specifier[0] = ' ';
			specifier[1] = ' ';
			continue;
		}
		else if (specifier[0] == '%' && specifier[1] == '%')
		{
			chtoStrcat(result, '%');
			specifier[0] = ' ';
			specifier[1] = ' ';
			continue;
		}
		if (format[i] != '%')
			chtoStrcat(result, format[i]);
	}
	va_end(arg);
	write(1, result, strlen(result));
	return (strlen(result));
}
