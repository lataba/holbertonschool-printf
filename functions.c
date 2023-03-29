#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

/**
* putout - Writes the character c to stdout
* @c: The character to print
* Return: On success 1.
*/
int putout(char c)
{
	return (write(1, &c, 1));
	return (0);
}

/**
 * print_char - Writes a char variable on stdout
 * @args: Variadic argument to be printed
 * @len: The number of characters was printed
 * Return: The increased number of characters that are printed
 */
int print_char (va_list *args, int len)
{
	char c = (char) va_arg(*args, int);

	putout(c);
	return (len++);
}

/**
 * print_string - Prints a string
 * @args: Variadic argument to be printed
 * @len: The number of characters was printed
 * Return: The increased number of characters that are printed
 */
int print_string(va_list *args, int len)
{
	char *str = va_arg(*args, char *);

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
 * @len: The number of characters was printed
 * Return: The increased number of characters that are printed
 */
int print_percent(va_list *args, int len)
{
	putout('%');
	return (len++);
}

/**
 * print_int - Prints an integer as a character string
 * @args: Variadic argument to be printed
 * @len: The number of characters was printed
 * Return: The increased number of characters that are printed
 */
int print_int (va_list *args, int len)
{
	int n = va_arg(*args, int);

	if (n < 0)
	{
		putout('-');
		n = -n;
		len++;
	}
	if (n / 10)
	{
		print_int(args, len);
		putout((n % 10) + '0');
		len++;
	}
	return (len);
}
