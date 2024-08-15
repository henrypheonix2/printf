#include "main.h"

/**
 * handle_percent - Processes the conversion of the percent sign which
 * represents a directive in a format.
 * @format: a character string represents the format string
 * which is composed of zero or more directives.
 * @idx: the index of the current percent sign.
 * @ap: the list of arguments of the _printf fucntion.
 *
 * Return: the number of printed characters.
 */

int handle_percent(const char *format, int idx, va_list ap)
{
	int n_chars = 0;

	if (format[idx + 1] == 'c')
		n_chars += print_char(ap);
	else if (format[idx + 1] == 's')
		n_chars += print_string(ap);
	else if (format[idx + 1] == 'S')
		n_chars += print_custom_string(ap);
	else if (format[idx + 1] == 'd' || format[idx + 1] == 'i')
		n_chars += print_integer(ap);
	else if (format[idx + 1] == 'b')
		n_chars += print_binary(ap);
	else if (format[idx + 1] == 'u')
		n_chars += print_unsigned(ap);
	else if (format[idx + 1] == 'o')
		n_chars += print_octal(ap);
	else if (format[idx + 1] == 'x' || format[idx + 1] == 'X')
		n_chars += print_hexa(ap, format[idx + 1] == 'X');
	else if (format[idx + 1] == '%')
		n_chars += write(STDOUT_FILENO, "%", 1);
	else
		n_chars += write(STDOUT_FILENO, &format[idx], 2);
	return (n_chars);
}
