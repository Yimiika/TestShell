#include "main.h"

/**
 * concat_string - concatenates two or more strings
 * @num_of_buffers: number of repeated args passed
 * @format: variadic function - strings buffers to concatenate
 * Return: pointer to a new string
 */
char *concat_string(size_t num_of_buffers, const char *const format, ...)
{
	va_list args;
	ssize_t total_len = 0;
	char **buffer;
	char *concat_buffer;
	int i, j, k;

	va_start(args, format);

	buffer = malloc(sizeof(char *) * num_of_buffers);
	if (buffer == NULL)
		return (NULL);
	for (i = 0; i < (int)num_of_buffers; i++)
		buffer[i] = NULL;

	buffer[0] = (char *)format;
	total_len = strlen(buffer[0]);

	for (i = 1; i < (int)num_of_buffers; i++)
	{
		buffer[i] = va_arg(args, char *);
		total_len += strlen(buffer[i]);
	}

	concat_buffer = malloc(sizeof(char) * (total_len + 1));
	if (concat_buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	concat_buffer[total_len] = '\0';
	for (j = 0, i = 0; total_len > 0; j++)
	{
		for (k = 0; buffer[j][k]; k++, i++)
			concat_buffer[i] = buffer[j][k];
		total_len -= k;
	}
	va_end(args);
	free(buffer);
	return (concat_buffer);
}

/**
 * replace_string - replaces a string with another one
 * @buffer: buffer with the string
 * @old_s: str to be replaced
 * @new_s: new str
 * @fpos: starting position of old str
 * Return: pointer to buffer
 */
char *replace_string(char *buffer, char *old_s, char *new_s, size_t fpos)
{
	size_t i, j, k;
	size_t old_len, new_len, total_len;
	char *temp;

	old_len = strlen(old_s);
	new_len = strlen(new_s);
	total_len = strlen(buffer) - old_len + new_len + 1;

	temp = malloc(sizeof(char) * total_len);
	memset(temp, 0, total_len);
	if (temp == NULL)
	{
        return (NULL);
    }
	for (i = 0, j = 0; buffer[i]; i++)
	{
		if (i < fpos || i > (fpos + old_len - 1))
		{
			temp[j] = buffer[i];
			j++;
		}
		if (i == fpos)
		{
			for (k = 0; new_s[k]; k++)
			{
				temp[j] = new_s[k];
				j++;
			}
			i += old_len - 1;
		}
	}
	temp[strlen(temp)] = '\0';
	return (temp);
}

/**
 * get_occurrence - function to count the number of occurence of a char
 * @c: char to look for
 * @str: string to look in
 * Return: size_t times
 */

size_t get_occurrence(char c, char *str)
{
	size_t len = 1, j;

	for (j = 1; str[j]; j++)
	{
		if (str[j] == c)
			len++;
	}
	return (len);
}

/**
 * find_subnstr - finds the first occurrence of a substring in a string
 * @str: string to look in
 * @sub: substring to look for
 * @n: number of chars to check
 * Return: position of char
 */
ssize_t find_subnstr(const char *str, const char *sub, size_t n)
{
	ssize_t post = -1;
	size_t count = 0, i, j;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == sub[0])
		{
			post = i;
			for (j = 0; j < n && str[i] == sub[j]; i++, j++)
				count++;
			if (count == n)
				return (post);
			i -= count;
			count = 0;
			post = -1;
		}
	}
	return (post);
}
