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

	return char_count;
}

/**
 * format_string - Format the input string using format specifiers
 * @result: Pointer to store the result
 * @format: The format string
 * @args: Variable arguments
 * Return: The number of characters formatted
 */
int format_string(char **result, const char *format, va_list args)
{
	int char_count = 0;
	int result_size = 1024;  // Initial buffer size
	char *buffer = (char *)malloc(result_size);
	if (!buffer)
		return -1;

	int buffer_index = 0;

	for (int i = 0; format[i] != '\0'; i++)
	{
        	if (format[i] != '%')
        	{
			buffer[buffer_index++] = format[i];
			char_count++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
				break;
			switch (format[i])
			{
				case 'c':
					{
						char c = va_arg(args, int);
						buffer_index = handle_char(buffer, buffer_index, c, &char_count, &result_size);
					}
					break;
				case 's':
					{
						char *str = va_arg(args, char *);
						buffer_index = handle_string(buffer, buffer_index, str, &char_count, &result_size);
                    			}
					break;
				case 'd':
					{
						int num = va_arg(args, int);
						buffer_index = handle_int(buffer, buffer_index, num, &char_count, &result_size);
					}
					break;
				// Add more cases for other specifiers as needed
				default:
					buffer_index = handle_char(buffer, buffer_index, format[i], &char_count, &result_size);
			}
		}

		if (buffer_index >= result_size - 1)
		buffer = resize_buffer(&buffer, &result_size);
	}

	buffer[buffer_index] = '\0';
	*result = buffer;
	return char_count;
}

