#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H

int putout(char c);
int _printf(const char *format, ...);
int (*get_func(const char *symbol))(va_list);

typedef struct {
	char *specifier;
	int (*function)(va_list);
} print_spec;

int print_string (va_list args);
int print_char (va_list args);
int print_percent (va_list args);
int print_int (va_list args);

#endif
