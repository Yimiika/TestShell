#include "main.h"

/**
 * exit_function - exit shell, sets exit code and flag value
 * @_cmd: main data struct
 * Return: none
 */

void exit_function(struct alx_cmd *_cmd)
{
	_cmd->status_code = EXIT_STATUS_CODE;
	if (_cmd->args[1] != NULL)
		_cmd->exit_code = atoi(_cmd->args[1]);
}

/**
 * clear_screen - function to clear the screen
 * @_cmd: main data struct
 * Return: nothing
 */

void clear_screen(struct alx_cmd *_cmd)
{
	(void)_cmd;
	CLEAR_SCREEN();
}

/**
 * direc_change - funtion to change directory
 * @_cmd: main data struct
 * Return: nothing
 */

void direc_change(struct alx_cmd *_cmd)
{
	char *new_dir, *old_dir, *curr_dir;
	struct stat _stat;
	int free_mem = 0;

	old_dir = _getenv("OLDPWD");
	curr_dir = _getenv("PWD");

	if (_cmd->args[1] == NULL)
	{
		new_dir = _getenv("HOME");
	}
	else if (strncmp(_cmd->args[1], "-", 1) == 0)
	{
		new_dir = old_dir;
		printf("%s\n", new_dir);
	}
	else
	{
		new_dir = get_dir_pathname(_cmd->args[1], curr_dir);
		free_mem = 1;
	}

	if (stat(new_dir, &_stat) == 0 && S_ISDIR(_stat.st_mode))
	{
		_setenv("OLDPWD", curr_dir, 1);
		chdir(new_dir);
		_setenv("PWD", new_dir, 1);
	}
	else
		_cmd->status_code = DIR_NOTFOUND_CODE;

	if (free_mem == 1)
		free(new_dir);
}

/**
 * environ - print current environment
 * @_cmd: main data struct
 * Return: none - void function
 */
void environ(struct alx_cmd *_cmd)
{
	unsigned int j = 0;

	for (j = 0; (_cmd->env_vars[j]) != NULL; j++)
		printf("%s\n", _cmd->env_vars[j]);
}
