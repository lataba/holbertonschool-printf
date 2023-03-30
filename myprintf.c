#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
	int count = 0, i = 0;
	char symbol = '\0';
	va_list args;
	va_start (args, format);

	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			symbol = format[i];
			count = count + (get_func(symbol)(args));
		}
		else
		{
			putout(format[i]);
			count++;
		}
		i++;
	}
		va_end (args);
		return (count);
}
