#include "main.h"
/**
 * print_string - concatenates a string to the result
 * @result: the string before concatenation
 * @str: the string to be added to the result
 * @specifier: holds the specifier
 */
void print_string(char *result, char *str, char specifier[])
{
	if (*str != '\0')
		strcat(result, str);
	else
		strcat(result, "(null)");
	specifier[0] = ' ';
	specifier[1] = ' ';
}
