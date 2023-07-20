#include "main.h"

/**
 * initialize - Initializes the main struct.
 * @_cmd: Pointer to the main struct.
 * @envir_list: Environment variable list.
 * Return: Nothing.
 */

void initialize(alx_cmd *_cmd, char **envir_list)
{
    _cmd->args = NULL;
    _cmd->env_vars = NULL;
    _cmd->input_line = NULL;
    _cmd->cmd_path = NULL;
    _cmd->status = BASE_STATUS_CODE;
    _cmd->exit_code = 0;
    _cmd->input_type = INPUT_FROM_TERMINAL;
    _cmd->line_counter = 0;
    _cmd->flags = 0;
    _cmd->buffer_size = 0;
    _cmd->env_vars = envir_list;
}
