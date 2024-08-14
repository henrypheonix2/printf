#include "main.h"

/**
 * print_string - Prints a string from the arguments list.
 * @ap: the argument list.
 *
 * Return: the number of printed characters.
 */

int print_string(va_list ap)
{
	int n_chars = 0;
	char *arg_s;

	arg_s = va_arg(ap, char*);
	if (_strlen(arg_s) >= 0)
		n_chars += write(STDOUT_FILENO, arg_s, _strlen(arg_s));
	else
		n_chars += write(STDOUT_FILENO, "(null)", 6);
	return (n_chars);
}
