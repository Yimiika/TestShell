#include "main.h"

/**
 * functions_cmd - function to return pointer to function
 * @my_key: input formal
 * Return: pointer to function
 */

void (*functions_cmd(const char *my_key))(struct shell_command *alx_cmd)
{
	alx_builtins options[] = {
		{"exit", exit_function},
		{"env", environ},
		{"clear", clear_prompt},
		{"cd", direc_change},
		{"setenv", set_builtin_env},   /* Update function pointer to match the correct signature */
		{"unsetenv", unset_builtin_env}, /* Update function pointer to match the correct signature */
		{NULL, NULL}
	};
	size_t key_length;
	int n = 0;

	if (my_key == NULL)
		return NULL;
	while (n < 6)
	{
		key_length = shell_strlen(options[n].key);
		if (shell_strncmp(my_key, options[n].key, key_length) == 0)
			return options[n].function;
		n++;
	}
	return (NULL);
}
