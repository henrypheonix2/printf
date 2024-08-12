#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: a character string represents the format string
 * which is composed of zero or more directives.
 *
 * Return: the number of characters printed (excluding the null
 * byte used to end output to strings).
 */

int _printf(const char *format, ...)
{
	char *arg_s;
	char arg_c;
	int i = 0;
	ssize_t n_chars = 0;
	va_list ap;

	if (format == NULL || (_strlen(format) == 1 && format[0] == '%'))
		return (-1);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			if (format[i + 1] == 'c')
			{
				arg_c = va_arg(ap, int);
				n_chars += write(STDOUT_FILENO, &arg_c, 1);
			}
			else if (format[i + 1] == 's')
			{
				arg_s = va_arg(ap, char*);
				if (_strlen(arg_s) >= 0)
					n_chars += write(STDOUT_FILENO, arg_s, _strlen(arg_s));
				else
					n_chars += write(STDOUT_FILENO, "(null)", 6);
			}
			else if (format[i + 1] == '%')
				n_chars += write(STDOUT_FILENO, "%", 1);
			else
				n_chars += write(STDOUT_FILENO, &format[i], 2);
			i++;
		}
		else
			n_chars += write(STDOUT_FILENO, &format[i], 1);
		i++;
	}
	va_end(ap);
	fflush(stdout);
	return (n_chars);
}
