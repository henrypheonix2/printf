#include "main.h"

/**
 * print_unsigned - Prints unsigned integer number from the argument
 * list in base 10.
 * @ap: the given argument list.
 *
 * Return: the number of printed characters.
 */

int print_unsigned(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
	int n_chars = 0;
	int cur_digit = 0;
	int num_digits[10];
	int num_len = 0;
	int i = 0;

	while (num != 0)
	{
		num_digits[i] = (num % 10) + '0';
		num /= 10;
		num_len++;
		i++;
	}
	num_len--;
	while (num_len >= 0)
	{
		cur_digit = num_digits[num_len];
		write(STDOUT_FILENO, &cur_digit, 1);
		n_chars++;
		num_len--;
	}
	if (n_chars == 0)
		n_chars += write(STDOUT_FILENO, "0", 1);
	return (n_chars);
}