#include "main.h"

/**
 * get_flags - Checks active flags
 * @format: the format string for printing
 * @i: the initial index in the format string
 * Return: the detected flag
 */
int get_flags(const char *format, int *i)
{
	int j = 0;
	int current_i = 0;
	int flags = 0;
	const char FLAGS_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		for (j = 0; FLAGS_CHARS[j] != '\0'; j++)
			if (format[current_i] == FLAGS_CHARS[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		if (FLAGS_CHARS[j] == 0)
			break;
	}
	*i = current_i - 1;
	return (flags);
}

