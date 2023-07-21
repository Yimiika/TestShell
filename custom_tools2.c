#include "main.h"

/**
 * shell_strcpy - this is the function
 * Description: this function is used to copy a string
 * @a: this is the first argument
 * @b: this is the second function
 * Return: the result
 */

char *shell_strcpy(char *a, const char *b)
{
	char *main = a;

	while (*b != '\0')
	{
		*a = *b;
		a++;
		b++;
	}
	*a = '\0';
	return (main);
}



/**
 * shell_strncmp - this is the function
 * Description: this function is used to compare strings
 * @first_string: this is the first argument
 * @second_string: this is the second argument
 * @i: this is the third argument
 * Return: the result
 */

int shell_strncmp(const char *first_string, const char *second_string, size_t i)
{
	while (i > 0 && *first_string != '\0' && *second_string != '\0'
			&& *first_string == *second_string)
	{
		first_string++;
		second_string++;
		i--;
	}
	if (i == 0)
		return (0);
	else
		return *first_string - *second_string;
}



/**
 * shell_memset - this is the function
 * Description: this function is used to set a block of memory to a value
 * @ptr: this is the first argument
 * @rep: the second argument
 * @byt_num: the third argument
 */

void *shell_memset(void *ptr, int rep, size_t byt_num)
{
	size_t j;
	unsigned char *a = ptr;
	unsigned char r = (unsigned char)rep;

	for (j = 0; j < byt_num; j++)
		a[j] = r;
	return (ptr);
}
