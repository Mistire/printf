#include "main.h"
/**
 * reverse - reverses a string
 * @str: the string to be reversed
 */
void reverse(char *str)
{
	int length = strlen(str);
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
	char temp = str[start];

	str[start] = str[end];
	str[end] = temp;
	start++;
	end--;
	}
}
/**
 * itoa - converts an integer to binary
 * @value: the integer value
 * @str: the binary value
 * @base: base of conversion
 * Return: returns the binary value
 */
char *itoa(int value, char *str, int base)
{
	int isNegative = 0;
	int index = 0;

	if (base < 2 || base > 36)
	{
		str[0] = '\0';
		return (str);
	}
	if (value < 0)
	{
		isNegative = 1;
		value = -value;
	}
	do {
		int remainder = value % base;

		str[index++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'a');
		value = value / base;
	} while (value > 0);

	if (isNegative)
		str[index++] = '-';
	str[index] = '\0';
	reverse(str);

	return (str);
}
/**
 * print_binary - converts integer to binary and prints it
 * @result: the formated string
 * @num: integer
 * @specifier: the current specifier
 */
void print_binary(char *result, int num, char specifier[])
{
	char binary[33];

	itoa(num, binary, 2);
	strcat(result, binary);
	specifier[0] = ' ';
	specifier[1] = ' ';
}
