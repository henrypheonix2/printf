#include "main.h"

/**
 * print_pointer - Prints a given pointer
 * @types: the list which contains the given pointer
 * @buffer: a buffer to handle print
 * @flags:  to handle flag chars
 * @width: to handle the field width for some specifiers
 * @precision: to handle precision for some specifiers
 * @size: to handle the size
 * Return: the number of printed chars
 */
int print_pointer(va_list types, char buffer[],
				  int flags, int width, int precision, int size)
{
	char extra_c = 0;
	char padd = ' ';
	int ind = BUFF_SIZE - 2;
	int length = 2;
	int padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);
	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	num_addrs = (unsigned long)addrs;
	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;
	ind++;
	return (write_pointer(buffer, ind, length,
						  width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - Prints non printable chars
 * @types: the list which contains the given char
 * @buffer: a buffer to handle print
 * @flags:  to handle flag chars
 * @width: to handle the field width for some specifiers
 * @precision: to handle precision for some specifiers
 * @size: to handle the size
 * Return: the number of printed chars
 */
int print_non_printable(va_list types, char buffer[],
						int flags, int width, int precision, int size)
{
	int i = 0;
	int offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);
		i++;
	}
	buffer[i + offset] = '\0';
	return (write(1, buffer, i + offset));
}

/**
 * print_reverse - Prints a given string reversed
 * @types: the list which contains the given string
 * @buffer: a buffer to handle print
 * @flags:  to handle flag chars
 * @width: to handle the field width for some specifiers
 * @precision: to handle precision for some specifiers
 * @size: to handle the size
 * Return: the number of printed chars
 */

int print_reverse(va_list types, char buffer[],
				  int flags, int width, int precision, int size)
{
	char *str;
	int i = 0;
	int count = 0;
	char c;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	str = va_arg(types, char *);
	if (str == NULL)
	{
		UNUSED(precision);
		str = "(null)";
	}
	for (i = i - 1; i >= 0; i--)
	{
		c = str[i];
		write(1, &c, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Prints a rot13ed string
 * @types: the list which contains the given string
 * @buffer: a buffer to handle print
 * @flags:  to handle flag chars
 * @width: to handle the field width for some specifiers
 * @precision: to handle precision for some specifiers
 * @size: to handle the size
 * Return: the number of printed chars
 */
int print_rot13string(va_list types, char buffer[],
					  int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

