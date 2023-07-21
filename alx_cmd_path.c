#include "main.h"

/**
 * alx_cmd_path - Get the full path of a system command.
 * @alx_cmd: Main data struct.
 * Return: SYS_CMD_FOUND_CODE if succeeded
 */

int alx_cmd_path(struct shell_command *alx_cmd)
{
	struct stat _stat;
	int func_stat, n = 0;
	char *c_path, *my_path = get_shell_env("PATH"), *duplicated_path;
	char **entered_path;

	func_stat = stat(alx_cmd->args[0], &_stat);
	if (func_stat == 0)
	{
		alx_cmd->cmd_path = concat_string(2, alx_cmd->args[0], "");
		return (SYS_CMD_FOUND_CODE);
	}
	duplicated_path = shell_strdup(my_path);
	entered_path = string_parse(duplicated_path, ":\n");
	while (my_path[n])
	{
		c_path = concat_string(3, entered_path[n], "/",alx_cmd->args[0]);
		func_stat = stat(c_path, &_stat);
		if (func_stat == 0)
		{
			alx_cmd->cmd_path = c_path;
			free(entered_path);
			free(duplicated_path);
			return (SYS_CMD_FOUND_CODE);
		}
		free(c_path);
		n++;
	}
	free(duplicated_path);
	return (SYS_CMD_NOTFOUND_CODE);
}
