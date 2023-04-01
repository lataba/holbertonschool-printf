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
	(void)args;
	return (2);
}

/**
 * print_string - Prints a string
 * @args: Variadic argument to be printed
 * Return: The number of characters that are printed
 */
int print_string(va_list args)
{
	int count = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		_printf("(null)");
		return (6);
	}
	while (str[count] != '\0')
	{
		putout(str[count]);
		count++;
	}
	return (count);
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

int print_int(va_list args)
{
	int count = 0, div = 1;
	unsigned int num = 0, total = 0;
	int n = va_arg(args, int);

	if (n < 0)
	{
		putout('-');
		num = -n;
		count++;
	}
	else
		num = n;
	total = num;
	while (num / div > 9)
		div = div * 10;
	while (div != 0)
	{
		num = num / div;
		putout((num + '0'));
		count++;
		num = total % div;
		div = div / 10;
	}
	return (count);
}
