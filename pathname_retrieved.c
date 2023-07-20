#include "main.h"

/**
 * pathname_retrieved - this is the function
 * Description: this function is used to get the pathname of a directory
 * @dest_path: this is the first argument of the function
 * @initial_path: this is the second argument of the function
 * Return: the pathname
 */

char *pathname_retrieved(char *dest_path, char *initial_path)
{
	char *is_pathname;

	if (find_string(dest_path, "/", 1) == 0)
		is_pathname = concat_string(2, dest_path, "/");
	else
		is_pathname = concat_string(3, initial_path, "/", dest_path);
	return (is_pathname);
}
