#include "main.h"

/**
 * exit_function - exit shell, sets exit code and flag value
 * @_cmd: main data struct
 * Return: none
 */

void exit_function(struct shell_command *alx_cmd)
{
	alx_cmd->status = EXIT_STATUS_CODE;

	if (alx_cmd->args[1] != NULL)
		alx_cmd->exit_code = shell_atoi(alx_cmd->args[1]);
}

/**
 * clear_prompt - function to clear the prompt
 * @_cmd: main data struct
 * Return: nothing
 */

void clear_prompt(struct shell_command *alx_cmd)
{
	(void)alx_cmd;
	CLEAR_PROMPT();
}

/**
 * direc_change - funtion to change directory
 * @_cmd: main data struct
 * Return: nothing
 */

void direc_change(struct shell_command *alx_cmd)
{
	char *recent_dir, *previous_dir, *initial_dir;
	struct stat _stat;
	int space = 0;

	previous_dir = get_shell_env("OLDPWD");
	initial_dir = get_shell_env("PWD");

	if (alx_cmd->args[1] == NULL)
		recent_dir = get_shell_env("HOME");
	else if (shell_strncmp(alx_cmd->args[1], "-", 1) == 0)
	{
		recent_dir = previous_dir;
		shell_puts(recent_dir);
	}
	else
	{
		recent_dir = pathname_retrieved(alx_cmd->args[1], initial_dir);
		space = 1;
	}

	if (stat(recent_dir, &_stat) == 0 && S_ISDIR(_stat.st_mode))
	{
		set_shell_env("OLDPWD", initial_dir, 1);
		chdir(recent_dir);
		set_shell_env("PWD", recent_dir, 1);
	}
	else
		alx_cmd->status = DIR_NOTFOUND_CODE;

	if (space == 1)
		free(recent_dir);
}

/**
 * environ - print current environment
 * @_cmd: main data struct
 * Return: none - void function
 */
void environ(struct shell_command *alx_cmd)
{
	unsigned int j = 0;

	for (j = 0; (alx_cmd->env_vars[j]) != NULL; j++)
		shell_puts(alx_cmd->env_vars[j]);
}
