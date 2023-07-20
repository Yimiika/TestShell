#include "main.h"

/**
 * set_builtin_env - this is the function
 * Description: this function is used to create or edit an environment variable
 * @alx_cmd: this is the argument of the function
 */

void set_builtin_env(struct shell_command *alx_cmd)
{
	int replace = 0;
	char *name = NULL;
	char *input = NULL;

	if (alx_cmd->args[1] != NULL)
		name = alx_cmd->args[1];
	if (alx_cmd->args[2] != NULL)
		name = alx_cmd->args[2];
	if (alx_cmd->args[3] != NULL)
		replace = shell_atoi(alx_cmd->args[3]);
	set_shell_env(name, input, replace);
}



/**
 * unset_builtin_env - this is the function
 * Description: this function is used to delete an environment variable
 * @alx_cmd: this is the argument of the function
 */


void unset_builtin_env(struct shell_command *alx_cmd)
{
	char *name = NULL;

	if (alx_cmd->args[1] != NULL)
		name = alx_cmd->args[1];
	unset_shell_env(name);
}
