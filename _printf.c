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
	unsigned int arg_len = 0;
	unsigned int i = 0;
	int n_chars = 0;
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
				write(STDOUT_FILENO, &arg_c, 1);
				n_chars--;
				i++;
			}
			else if (format[i + 1] == 's')
			{
				arg_s = va_arg(ap, char*);
				arg_len = _strlen(arg_s);
				write(STDOUT_FILENO, arg_s, arg_len);
				n_chars += arg_len - 2;
				i++;
			}
		}
		else
		{
			cur_c = format[i];
			write(STDOUT_FILENO, &cur_c, 1);
		}
		n_chars++;
		i++;
	}
	va_end(ap);
	return (n_chars);
}
