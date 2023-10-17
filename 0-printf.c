#include "main.h"

/**
 * _printf - Custom printf-like function
 * @format: A constant character pointer representing the format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int (*print_function)(va_list, flags_t *);
	const char *format_iterator;
	va_list arguments;
	flags_t flags = {0, 0, 0};
	int character_count = 0;

	va_start(arguments, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (format_iterator = format; *format_iterator; format_iterator++)
	{
		if (*format_iterator == '%')
		{
			format_iterator++;

			if (*format_iterator == '%')
			{
				character_count += _putchar('%');
				continue;
			}

			while (get_flag(*format_iterator, &flags))
				format_iterator++;

			print_function = get_print(*format_iterator);
			character_count += (print_function)
				? print_function(arguments, &flags)
				: _printf("%%%c", *format_iterator);
		}
		else
		{
			character_count += _putchar(*format_iterator);
		}
	}

    	_putchar(-1);
    	va_end(arguments);
    	return character_count;
}

