#include "main.h"

/**
 * print_address - Prints an unsigned integer number which represents
 * an address in memory from the argument list in base 16.
 * @ap: the given argument list.
 *
 * Return: the number of printed characters.
 */

int print_address(va_list ap)
{
	unsigned long num = va_arg(ap, unsigned long);
	int n_chars = 0;
	int cur_digit = 0;
	int num_digits[128];
	int num_len = 0;
	int i = 0;

	n_chars += write(STDOUT_FILENO, "0x", 2);
	while (num != 0)
	{
		if (num % 16 < 10)
			num_digits[i] = (num % 16) + '0';
		else
			num_digits[i] = (num % 16) - 10 + 'a';
		num /= 16;
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
	if (n_chars == 2)
		n_chars += write(STDOUT_FILENO, "0", 1);
	return (n_chars);
}
