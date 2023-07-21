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



/**
 * shell_atoi - this is the function
 * Description: this function is used to convert a string of characters
 * representing an integer to an actual integer value
 * @e: this is the argument passed into the function
 * Return: the result
 */

int shell_atoi(const char *e)
{
	int y = 0;
	int a = 1;

	while (*e == ' ' || *e == '\t' || *e == '\n')
		e++;
	if (*e == '-')
	{
		a = -1;
		e++;
	}
	else if (*e == '+')
		e++;
	while (*e >= '0' && *e <= '9')
	{
		y = y * 10 + (*e - '0');
		e++;
	}
	return (a * y);
}


/**
 * shell_strdup - this is the function
 * Description: this function is used to duplicate strings
 * @e: the argument passed into the function
 * Return: the result
 */

char *shell_strdup(const char *e)
{
	size_t len;
	char *dup;

	if (e == NULL)
		return (NULL);
	len = shell_strlen(e);
	dup = (char*)malloc((len + 1) * sizeof(char));

	if (dup == NULL)
		return (NULL);
	shell_strcpy(dup, e);
	return (dup);
}


/**
 * shell_strlen - this is the function
 * Description: this is used to get the length of a string
 * @e: the argument passed into the function
 * Return: the result
 */

size_t shell_strlen(const char *e) {
    if (e == NULL) {
        return 0;
    }

    size_t length = 0;
    while (e[length] != '\0') {
        length++;
    }
    return length;
}
