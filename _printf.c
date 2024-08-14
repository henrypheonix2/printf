#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: a character string represents the format string
 * which is composed of zero or more directives.
 *
 * Return: the number of printed characters (excluding the null
 * byte used to end output to strings).
 */

int _printf(const char *format, ...)
{
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
			n_chars += handle_percent(format, i, ap);
			i++;
		}
		else
		{
			n_chars += write(STDOUT_FILENO, &format[i], 1);
		}
		i++;
	}
	va_end(ap);
	fflush(stdout);
	return (n_chars);
}
