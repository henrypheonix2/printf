#include "main.h"

/**
 * print_address - Prints an unsigned long number which represents
 * an address in memory from the argument list in base 16.
 * @ap: the given argument list.
 *
 * Return: the number of printed characters.
 */

int print_address(va_list ap)
{
	unsigned long addr = va_arg(ap, unsigned long);
	int n_chars = 0;
	int cur_digit = 0;
	int addr_digits[128];
	int addr_len = 0;
	int i = 0;

	n_chars += write(STDOUT_FILENO, "0x", 2);
	while (addr != 0)
	{
		if (addr % 16 < 10)
			addr_digits[i] = (addr % 16) + '0';
		else
			addr_digits[i] = (addr % 16) - 10 + 'a';
		addr /= 16;
		addr_len++;
		i++;
	}
	addr_len--;
	while (addr_len >= 0)
	{
		cur_digit = addr_digits[addr_len];
		write(STDOUT_FILENO, &cur_digit, 1);
		n_chars++;
		addr_len--;
	}
	if (n_chars == 2)
		n_chars += write(STDOUT_FILENO, "0", 1);
	return (n_chars);
}
