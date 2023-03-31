#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * get_func - Returns a function pointer to a corresponding identifier format
 * @symbol: Identifier format
 * Return: 0 if success
 */

int (*get_func(const char symbol))(va_list args)
{
	int i = 0;
	print_spec specifiers[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'\0', print_nopercent}
	};
	while (specifiers[i].specifier != '\0')
	{
		if (specifiers[i].specifier == symbol)
			return (specifiers[i].function);
		i++;
	}
	if (specifiers[i].specifier == '\0')
		return (print_nopercent);
	return (0);
}

/**
* putout - Writes a character on stdout
* @c: The character to be printed
* Return: Non
*/
int putout(const char c)
{
	return (write(1, &c, 1));
}
