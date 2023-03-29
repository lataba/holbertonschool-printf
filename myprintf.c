#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
	char symbol = "";
	int i = 0, count = 0;
	va_list args;

	va_start (args, format);

	print_spec specifiers[] = {
		{'c', print_char},
		{'s', print_string}
		{'%', print_percent}
		{'d', print_int}
		{'i', print_int}
		{NULL, NULL}
	};

	while (format && *format != '\0')
	{
		if (*format == %)
		{
			format++;
			symbol = *format;
			while (specifiers[i].specifier != NULL)
			{
				if (specifiers[i].specifier == symbol)
				{
					specifier[i].function(&args, count);
					break;
				}
				i++;
			}
		}
		else
		{
			putout(*format);
			count++;
		}
		format++;
	}
		va_end (args);
		return (count);
}
