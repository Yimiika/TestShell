#include "main.h"

/**
 * shell_puts - this is the function
 * Description: this function is used to print a string to the stdout
 * @e: this is the string taken as an argument for the function
 * Return: the result
 */

int shell_puts(const char *e)
{
	while (*e != '\0')
	{
		shell_putchar(*e);
		e++;
	}
	shell_putchar('\n');
	return (1);
}



/**
 * shell_putchar - this is the function
 * Description: this function is used to write a single character to stdout
 * @r: this is the character taken as an argument for the function
 */

void shell_putchar(char r)
{
	write(1, &r, 1);
}
