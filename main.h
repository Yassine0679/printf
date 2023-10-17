#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int _putchar(int character);
int sPrinter(char *string);

int handleString(char specifier1, char stringEnd, va_list params);
int _printf(const char *format, ...);

#endif
