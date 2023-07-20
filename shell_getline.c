#include "main.h"

/**
 * shell_getline - this is the function
 * Description: this function is used to read an entire line
 * of string from a stream either from a file or stdin
 * @reserve: this is the first argument of the function
 * @reserve_size: this is the second argument of the function
 * @my_file: this is the third argument of the function
 * Return: the result
 */

int shell_getline(char **reserve, size_t *reserve_size, FILE *my_file)
{
	char buff[1024];
	int char_count = 0, result, my_fileid, num = 0;

	if (my_file == stdin)
		my_fileid = 0;
	else if (my_file == stdout)
		my_fileid = 1;
	else if (my_file == stderr)
		my_fileid = 2;
	else
		perror("Unknown source");
	*reserve_size = 1024;
	result = read(my_fileid, buff, *reserve_size);

	if (result == -1)
		return (-1);
	while (buff[char_count] != '\0')
		char_count++;
	while (num < char_count - 1)
	{
		reserve[0][num] = buff[num];
		num++
	}
	return (char_count - 1);
}
