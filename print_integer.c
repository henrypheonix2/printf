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

	while (num != 0)
	{
		cur_digit = num % 10 + '0';
		write(STDOUT_FILENO, &cur_digit, 1);
		num /= 10;
		n_chars++;
	}
	return (n_chars);
}
