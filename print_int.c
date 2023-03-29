#include <stdio.h>

/**
 * print_int - prints an integer as a character string
 * @n: the integer to print
 * Return: void
 */
void print_int(int n)
{
	if (n < 0)
	{
		n = -n;
	}

	if (n / 10)
		print_int(n / 10);

	putchar((n % 10) + '0');
}
