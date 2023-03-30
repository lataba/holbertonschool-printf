#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int (*get_func(const char symbol))(va_list args)
{
	int i = 0;
	print_spec specifiers[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'\0', NULL}
	};

	while (specifiers[i].specifier != '/0')
	{
		if (specifiers[i].specifier == symbol)
			return (specifiers[i].function);
		i++;
	}
	return (0);
}


/**
* putout - Writes the character c to stdout
* @c: The character to print
* Return: a char
*/
int putout(const char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - Writes a char variable on stdout
 * @args: Variadic argument to be pr'/0'd
 * Return: The number of characters that are printed
 */
int print_char (va_list args)
{
	const char c = va_arg(args, int);

	putout(c);
	return (1);
}

/**
 * print_string - Prints a string
 * @args: Variadic argument to be printed
 * Return: The number of characters that are printed
 */
int print_string(va_list args)
{
	int len = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		_printf("(null)");
		return(-6);
	}
	while (*str != '\0')
	{
		putout(*str);
		len++;
		str++;
	}
	return (len);
}

/**
 * print_percent - Write a percentage symbol on the stdoutput
 * @args: Variadic argument to be printed
 * Return: The number of characters that are printed
 */
int print_percent(va_list args)
{
	(void)args;
	putout('%');
	return (1);
}

/**
 * print_int - Prints an integer as a character string
 * @args: Variadic argument to be printed
 * Return: The number of characters that are printed
 */
int print_int (va_list args)
{
	int len = 0, div = 1;
	int num = va_arg(args, int);
	unsigned int unum = num;
	
	if (num < 0)
	{
		putout('-');
		unum = -num;
		len++;
	}
	while (unum / div > 9)
		div = div * 10;
	while (div != 0)
	{
		putout((unum / 10) + '0');
		len++;
		unum = unum % div;
		div = div /10;
	}
	return (len);
}
