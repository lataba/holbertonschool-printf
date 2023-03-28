#include <unistd.h>

/**
 * putout - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 */
int putout(char c)
{
	return (write(1, &c, 1));
}
