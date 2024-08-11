#include <stdio.h>
#include "main.h"


/**
 * _strlen - Computes the size of a given string.
 * @str: the given string.
 *
 * Returns: The size of the string.
 */

int _strlen(const char *str)
{
	unsigned int i = 0;
	int len = 0;

	while (str[i] !='\0')
	{
		len++;
		i++;
	}
	return (len);
}
