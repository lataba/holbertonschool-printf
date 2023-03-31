#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - Writes a char variable on stdout
 * @args: Variadic argument to be printed
 * Return: The number of characters that are printed
 */
int print_char (va_list args)
{
	const char c = (char)va_arg(args, int);

	putout(c);
	return (1);
}

/**
 * print_nopercent - Writes % followed by the symbol
 * when it not matches with any function
 * @args: variadic argument is not utilized here
 * Return: 2 (the number of characters that are printed)
 */

int print_nopercent(va_list args)
{
	const char c = (char)va_arg(args, int);

	putout('%');
	putout(c);
	return (2);
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
		return (6);
	}
	while (str[len] != '\0')
	{
		putout(str[len]);
		len++;
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
		div = div / 10;
	}
	return (len);
}
