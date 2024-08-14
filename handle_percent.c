#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_percent - processes the conversion of the percent sign
 * which represents a directive in a format.
 * @format: a character string represents the format string
 * which is composed of zero or more directives.
 *
 * Return: the number of printed characters.
 */

int handle_percent(const char *format, int idx, va_list ap)
{
	char *arg_s;
	char arg_c;
	ssize_t n_chars = 0;

	if (format[idx + 1] == 'c')
	{
		arg_c = va_arg(ap, int);
		n_chars += write(STDOUT_FILENO, &arg_c, 1);
	}
	else if (format[idx + 1] == 's')
	{
		arg_s = va_arg(ap, char*);
		if (_strlen(arg_s) >= 0)
			n_chars += write(STDOUT_FILENO, arg_s, _strlen(arg_s));
		else
			n_chars += write(STDOUT_FILENO, "(null)", 6);
	}
	else if (format[idx + 1] == '%')
		n_chars += write(STDOUT_FILENO, "%", 1);
	else
		n_chars += write(STDOUT_FILENO, &format[idx], 2);
	return (n_chars);
}