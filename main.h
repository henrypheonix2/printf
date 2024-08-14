#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

int _printf(const char *format, ...);
int handle_percent(const char *format, int idx, va_list ap);
int print_integer(va_list ap);
int print_binary(va_list ap);
int print_char(va_list ap);
int print_string(va_list ap);
int _strlen(const char *str);

#endif
