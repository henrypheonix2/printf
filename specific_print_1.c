#include "main.h"

/**
 * print_char - Prints a char which is given in the argument list
 * @types: the list which contains the given char
 * @buffer: a buffer to handle print
 * @flags:  to handle flag chars
 * @width: to handle the field width for some specifiers
 * @precision: to handle precision for some specifiers
 * @size: to handle the size
 * Return: the number of printed chars
 */
int print_char(va_list types, char buffer[],
			   int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - Prints a string which is given in the argument list
 * @types: the list which contains the given char
 * @buffer: a buffer to handle print
 * @flags:  to handle flag chars
 * @width: to handle the field width for some specifiers
 * @precision: to handle precision for some specifiers
 * @size: to handle the size
 * Return: the number of printed chars
 */
int print_string(va_list types, char buffer[],
				 int flags, int width, int precision, int size)
{
	int length = 0;
	int i = 0;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 5)
			str = "     ";
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/**
 * print_percent - Prints a percent sign
 * @types: the list which contains the given char
 * @buffer: a buffer to handle print
 * @flags:  to handle flag chars
 * @width: to handle the field width for some specifiers
 * @precision: to handle precision for some specifiers
 * @size: to handle the size
 * Return: the number of printed chars
 */
int print_percent(va_list types, char buffer[],
				  int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - Prints a given integer
 * @types: the list which contains the given char
 * @buffer: a buffer to handle print
 * @flags:  to handle flag chars
 * @width: to handle the field width for some specifiers
 * @precision: to handle precision for some specifiers
 * @size: to handle the size
 * Return: the number of printed chars
 */
int print_int(va_list types, char buffer[],
			  int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prints a given integer in binary
 * @types: the list which contains the given char
 * @buffer: a buffer to handle print
 * @flags:  to handle flag chars
 * @width: to handle the field width for some specifiers
 * @precision: to handle precision for some specifiers
 * @size: to handle the size
 * Return: the number of printed chars
 */
int print_binary(va_list types, char buffer[],
				 int flags, int width, int precision, int size)
{
	unsigned int n = 0;
	unsigned int m = 0;
	unsigned int i = 0;
	unsigned int sum = 0;
	unsigned int a[32];
	int counter = 0;
	char c;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			c = '0' + a[i];

			write(1, &c, 1);
			counter++;
		}
	}
	return (counter);
}

