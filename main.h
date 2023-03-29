#ifndef "MAIN_H"
#include "MAIN_H"

int putout(char c);
int _printf(const char *format, ...);

typedef void (*print_func)(va_list*, int);

typedef struct {
	char specifier;
	void (*function)(va_list*);
} print_spec;

int print_string (va_list *args, int len);
int print_char (va_list *args, int len);
int print_percet (va_list *args, int len);
int print_int (va_list *args, int len);

#endif
