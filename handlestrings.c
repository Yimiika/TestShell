#include "main.h"

/**
 * concat_string - concatenates two or more strings
 * @total_buffs: number of repeated args passed
 * @format: variadic function - strings buffers to concatenate
 * Return: pointer to a new string
 */
char *concat_string(size_t total_buffs, const char *const format, ...)
{
	va_list cmds;
	ssize_t length = 0;
	char **buff;
	char *join_buff;
	int a, b, c;

	va_start(cmds, format);

	buff = malloc(sizeof(char *) * total_buffs);
	if (buff == NULL)
		return (NULL);
	for (a = 0; a < (int)total_buffs; a++)
		buff[a] = NULL;

	buff[0] = (char *)format;
	length = shell_strlen(buff[0]);

	for (a = 1; a < (int)total_buffs; a++)
	{
		buff[a] = va_arg(cmds, char *);
		length += shell_strlen(buff[a]);
	}

	join_buff = malloc(sizeof(char) * (length + 1));
	if (join_buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	join_buff[length] = '\0';
	for (b = 0, a = 0; length > 0; b++)
	{
		for (c = 0; buff[b][c]; c++, a++)
			join_buff[a] = buff[b][c];
		length -= c;
	}
	va_end(cmds);
	free(buff);
	return (join_buff);
}

/**
 * replace_string - replaces a string with another one
 * @buffer: buffer with the string
 * @old_s: str to be replaced
 * @new_s: new str
 * @fpos: starting position of old str
 * Return: pointer to buffer
 */
char *replace_string(char *buff, char *s1, char *s2, size_t t)
{
	size_t a, b, c;
	size_t len1, len2, total_length;
	char *stor;

	len1 = shell_strlen(s1);
	len2 = shell_strlen(s2);
	total_length = shell_strlen(buff) - len1 + len2 + 1;

	stor = malloc(sizeof(char) * total_length);
	shell_memset(stor, 0, total_length);
	if (stor == NULL)
		return (NULL);
	for (a = 0, b = 0; buff[a]; a++)
	{
		if (a < t || a > (t + len1 - 1))
		{
			stor[b] = buff[a];
			b++;
		}
		if (a == t)
		{
			for (c = 0; s2[c]; c++)
			{
				stor[b] = s2[c];
				b++;
			}
			a += len1 - 1;
		}
	}
	stor[shell_strlen(stor)] = '\0';
	return (stor);
}

/**
 * get_occurrence - function to count the number of occurence of a char
 * @r: char to look for
 * @e: string to look in
 * Return: size_t times
 */

size_t get_occurrence(char r, char *e)
{
	size_t length = 1, b;

	for (b = 1; e[b]; b++)
	{
		if (e[b] == r)
			length++;
	}
	return (length);
}

/**
 * find_string - finds the substring in a string
 * @e: string to look in
 * @substr: substring to look for
 * @w: number of chars to check
 * Return: position of char
 */
ssize_t find_string(const char *e, const char *substr, size_t w)
{
	ssize_t post = -1;
	size_t count = 0, a, b;

	for (a = 0; e[a]; a++)
	{
		if (e[a] == substr[0])
		{
			post = a;
			for (b = 0; b < w && e[a] == substr[b]; a++, b++)
				count++;
			if (count == w)
				return (post);
			a -= count;
			count = 0;
			post = -1;
		}
	}
	return (post);
}
