#include "main.h"

/**
 * is_printable - checks if printable
 * @ch: Char to be checked.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char ch)
{
	if (ch >= 32 && ch < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - concat ascci in hexadecimal code to buffer
 * @buffer: buffer array of characters.
 * @i: Index on the buffer.
 * @asc: ascii code value.
 * Return: Always 3
 */
int append_hexa_code(char asc, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (asc < 0)
		asc *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[asc / 16];
	buffer[i] = map_to[asc % 16];

	return (3);
}

/**
 * is_digit - checks if digit
 * @ch: Char to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @nu: Number
 * @siz: integer indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int nu, int siz)
{
	if (siz == S_LONG)
		return (nu);
	else if (siz == S_SHORT)
		return ((short)nu);

	return ((int)nu);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @nu: Number
 * @siz: integer indicating the type to be casted
 *
 * Return: Casted value of nu
 */
long int convert_size_unsgnd(unsigned long int nu, int siz)
{
	if (siz == S_LONG)
		return (nu);
	else if (siz == S_SHORT)
		return ((unsigned short)nu);

	return ((unsigned int)nu);
}
