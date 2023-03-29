#include <stdio.h>

/**
 * print_string - prints a string
 * @str: the string to print
 * Return: void
 */
void print_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}
}
