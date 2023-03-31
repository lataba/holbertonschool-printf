#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Function that prints formatted data on the stdoutput
 * @format: String of characters containing the information to be printed
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0, i = 0;
	char symbol = '\0';
	va_list args;

	va_start(args, format); /*Initializing the argument list*/

	if (!format)
		return (-1);
	while (format[i] != '\0') /*Traversing the format string*/
	{
		if (format[i] == '%') /*Checking the format specifier*/
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			symbol = format[i];
			count = count + get_func(symbol)(args);
		}
		else /*Printing if the specifier is not matched*/
		{
			count = count + putout(format[i]);
		}
		i++;
	}
		va_end(args); /*Finalization of the list*/
		return (count);
}
