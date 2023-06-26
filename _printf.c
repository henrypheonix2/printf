#include "main.h"

void print_buffer(char buffer[], int *buffer_idx);

/**
 * _printf - Prints a string with arguments in a specified format
 * @format: the specified format
 *
 * Return: the number of printed chars
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int printed = 0;
	int printed_counter = 0;
	int flags, width, precision, size;
	int buffer_idx = 0;
	char buffer[BUFF_SIZE];
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[buffer_idx++] = format[i];
			if (buffer_idx == BUFF_SIZE)
				print_buffer(buffer, &i);
			printed_counter++;
		}
		else
		{
			print_buffer(buffer, &buffer_idx);
			flags = get_flags(format, &i);
			precision = get_precision(format, &i, args);
			width = get_width(format, &i, args);
			size = get_size(format, &i);
			i++;
			printed = handle_print(format, &i, args, buffer,
								   flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_counter += printed;
		}
		i++;
	}
	print_buffer(buffer, &buffer_idx);
	va_end(args);
	return (printed_counter);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: an Array of chars
 * @buffer_idx: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buffer_idx)
{
	if (*buffer_idx > 0)
		write(1, &buffer[0], *buffer_idx);

	*buffer_idx = 0;
}

