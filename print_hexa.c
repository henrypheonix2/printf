#include "main.h"

/**
 * print_hexa - Prints an unsigned integer number from the argument
 * list in base 16.
 * @ap: the given argument list.
 * @capital: if its value is 1, the characters are printed in capital case.
 *
 * Return: the number of printed characters.
 */

int print_hexa(va_list ap, int capital)
{
	unsigned int num = va_arg(ap, unsigned int);
	int n_chars = 0;
	int cur_digit = 0;
	int num_digits[128];
	int num_len = 0;
	int i = 0;

	while (num != 0)
	{
		if (num % 16 < 10)
			num_digits[i] = (num % 16) + '0';
		else if (capital == 1)
			num_digits[i] = (num % 16) - 10 + 'A';
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
	if (n_chars == 0)
		n_chars += write(STDOUT_FILENO, "0", 1);
	return (n_chars);
}
