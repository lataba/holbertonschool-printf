#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/*The principal function*/
int _printf(const char *format, ...);

/*Auxiliar functions to print char and to call the another auxiliar functions*/
int putout(char c);
int (*get_func(const char symbol))(va_list);

/**
 * struct specifiers - Asociates an specifier format with a function
 * @specifier: Specifier format
 * @function: Pointer to the function that prints the corresponding variable
 */
typedef struct specifiers
{
	char specifier;
	int (*function)(va_list);
} print_spec;

/*Auxiliar functions to print arguments*/
int print_string(va_list args);
int print_char(va_list args);
int print_percent(va_list args);
int print_nopercent(va_list args);
int print_int(va_list args);

#endif
