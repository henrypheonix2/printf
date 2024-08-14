#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int handle_percent(const char *format, int idx, va_list ap);
int print_integer(int num);
int print_binary(int num);
int _strlen(const char *str);

#endif
