#include "main.h"

/**
 * _printf - Custom implementation of the printf function
 * @format: A constant pointer to the format string
 * Return: The count of characters printed
 */
int _printf(const char *format, ...)
{
	int (*print_func)(va_list, flags_t *);
	const char *format_ptr;
	va_list args;
	flags_t flags = {0, 0, 0};
	int char_count = 0;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (format_ptr = format; *format_ptr; format_ptr++)
	{
		if (*format_ptr == '%')
		{
			format_ptr++;

			if (*format_ptr == '%')
			{
				char_count += _putchar('%');
				continue;
			}

			while (get_flag(*format_ptr, &flags))
				format_ptr++;

			print_func = get_print(*format_ptr);
			char_count += (print_func)
			? print_func(args, &flags)
			: _printf("%%%c", *format_ptr);
		}
		else
		{
			char_count += _putchar(*format_ptr);
		}
	}

	_putchar(-1);
	va_end(args);
	return char_count;
}

