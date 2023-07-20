#include "main.h"

/**
 * load_alxshell - this is the function
 * Description: this function is used to start the shell,
 * ready to accept command
 * @alx_cmd: this is the argument passed into the function
 */

void load_alxshell(struct shell_command *alx_cmd)
{
	alx_cmd->input_type = INPUT_FROM_TERMINAL;
	alx_prompt();
}
