#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_integer - Prints a given integer number in base 10.
 * @num: the given integer number.
 *
 * Return: the number of printed characters.
 */

int print_integer(int num)
{
	int n_chars = 0;
	int cur_digit = 0;
	int num_digits[10];
	int num_len = 0;
	int is_negative = (num < 0);
	int i = 0;

	if (num < 0)
		num *= -1;
	while (num != 0)
	{
		num_digits[i] = num % 10 + '0';	
		num /= 10;
		num_len++;
		i++;
	}
	num_len--;
	if (is_negative)
		n_chars += write(STDOUT_FILENO, "-", 1);
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
