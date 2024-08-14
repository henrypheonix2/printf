#include "main.h"

/**
 * print_char - Prints a char from the argument list.
 * @ap: the argument list.
 *
 * Return: the number of printed characters.
 */

int print_char(va_list ap)
{
	char arg_c;
	int n_chars = 0;

	arg_c = va_arg(ap, int);
	n_chars += write(STDOUT_FILENO, &arg_c, 1);
	return (n_chars);
}
