#include "main.h"
/**
 * check_specifier - checks if there is a specifier in the format string
 * @specifier: a character array that stores a specifier
 * @format: a certain charcter from the string format
 */
void check_specifier(char specifier[], char format)
{
	if (format == '%' && specifier[0] != '%')
		specifier[0] = '%';
	else if (specifier[0] == '%')
		specifier[1] = format;
}
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
 * concat - concatenates a character to a string and resets the specifier
 * @result: the string before concatenation
 * @ch: the character to be added to the string
 * @specifier: the string that holds the specifier
 */
void concat(char result[], char ch, char specifier[])
{
	chtoStrcat(result, ch);
	specifier[0] = ' ';
	specifier[1] = ' ';
}
/**
 * format_string - formats a string based on the specifier
 * @arg: the variadic arguments
 * @format: the string that needs to be formated
 * @spec: the string that holds the specifier
 * @result: the final formated string
 */
void format_string(va_list arg, const char *format, char spec[], char result[])
{
	size_t i = 0;

	while (i < strlen(format))
	{
		check_specifier(spec, format[i]);
		if (spec[0] == '%' && spec[1] == 'c')
		{
			concat(result, va_arg(arg, int), spec);
			i++;
			continue;
		}
		else if (spec[0] == '%' && spec[1] == 's')
		{
			strcat(result, va_arg(arg, char *));
			spec[0] = ' ';
			spec[1] = ' ';
			i++;
			continue;
		}
		else if (spec[0] == '%' && spec[1] == '%')
		{
			concat(result, '%', spec);
			i++;
			continue;
		}
		if (format[i] != '%')
			chtoStrcat(result, format[i]);
		i++;
		}
}
