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
	int arg_len = 0;
	int i = 0;
	ssize_t n_chars = 0;
	char cur_c;
	va_list ap;

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				arg_c = va_arg(ap, int);
				n_chars += write(STDOUT_FILENO, &arg_c, 1);
				i++;
			}
			else if (format[i + 1] == 's')
			{
				arg_s = va_arg(ap, char*);
				arg_len = _strlen(arg_s);
				if (arg_len >= 0)
					n_chars += write(STDOUT_FILENO, arg_s, arg_len);
				else
					n_chars += write(STDOUT_FILENO, "(null)", 6);
				i++;
			}
		}
		else
		{
			cur_c = format[i];
			n_chars += write(STDOUT_FILENO, &cur_c, 1);
		}
		i++;
	}
	va_end(ap);
	fflush(stdout);
	return (n_chars);
}
