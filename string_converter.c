#include "main.h"

/**
 * string_converter - this is the function
 * Description: this function is used to convert numbers to strings
 * @str_num: this is the argument passed into the function
 * Return: the result
 */

char *string_converter(int str_num)
{
	char *converted, *s;
	int new = str_num, countr = 0;

	while (new > 0)
	{
		countr++;
		new /= 10;
	}
	converted = malloc(sizeof(char) * (countr + 1));
	converted[countr] = '\0';
	s = &converted[countr];
	s--;
	while (str_num > 0)
	{
		*s = str_num % 10 + '0';
		str_num /= 10;
		s--;
	}
	return (converted);
}
