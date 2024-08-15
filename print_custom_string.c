#include "main.h"

/**
 * print_custom_string - Prints a custom string from the arguments list
 * which prints non printable characters using the following format
 * "\x and the ASCII code value in hexadecimal (upper case, only 2 chars)".
 * @ap: the argument list.
 *
 * Return: the number of printed characters.
 */

int print_custom_string(va_list ap)
{
	int n_chars = 0;
	int i = 0;
	int j = 0;
	char buffer[1024];
	char *arg_s;
	char cur_c;

	arg_s = va_arg(ap, char*);
	while (arg_s[i] != '\0')
	{
		cur_c = arg_s[i];
		if ((cur_c > 0 && cur_c < 32) || cur_c >= 127)
		{
			buffer[j] = '\\';
			buffer[j + 1] = 'x';
			if ((cur_c / 16) % 16 < 10)
				buffer[j + 2] = ((cur_c / 16) % 16) + '0';
			else
				buffer[j + 2] = ((cur_c / 16) % 16) - 10 + 'A';
			if (cur_c % 16 < 10)
				buffer[j + 3] = (cur_c % 16) + '0';
			else
				buffer[j + 3] = (cur_c % 16) - 10 + 'A';
			j += 4;
		}
		else
		{
			buffer[j] = cur_c;
			j++;
		}
		i++;
	}
	buffer[j] = '\0';
	if (_strlen(arg_s) >= 0)
		n_chars += write(STDOUT_FILENO, buffer, j + 1);
	else
		n_chars += write(STDOUT_FILENO, "(null)", 6);
	return (n_chars);
}
