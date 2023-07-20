#include "main.h"

/**
 * perform_command - this is the function
 * Description: this function is used to execute a system command
 * @alx_cmd: this is the argument passed into the function
 */

void perform_command(struct shell_command *alx_cmd)
{
	pid_t pid;
	int mode = -1;

	if (alx_cmd->input_line == NULL ||
			alx_cmd->input_line[0] == NULL)
		return;
	mode = alx_cmd_path(alx_cmd);
	if (mode == SYS_CMD_FOUND_CODE)
	{
		pid = fork();
		if (pid == -1)
		{
			shell_puts("ERROR:: could not create child process\n");
			alx_cmd->status = FORK_FAILURE_CODE;
			return;
		}
		else if (pid == 0)
		{
			execve(alx_cmd->cmd_path, alx_cmd->input_line,
					alx_cmd->env_vars);
			free(alx_cmd->cmd_path);
		}
		else
			wait(&mode);
	}
	else
	{
		if (alx_cmd->status == BASE_STATUS_CODE)
			alx_cmd->status = SYS_CMD_NOTFOUND_CODE;
	}
}
