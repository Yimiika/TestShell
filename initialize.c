/**
 * initialize - Initializes the main struct.
 * @_cmd: Pointer to the main struct.
 * @env_list: Environment variable list.
 * Return: Nothing. 
 */

void initialize(alx_cmd *_cmd, char **envir_list)
{
	_cmd->input = NULL;
	_cmd->lines_counter = 0;
    _cmd->flags = 0;
    _cmd->exit_code = 0;
    _cmd->size = 0;
	_cmd->env_list = env_list;
    _cmd->status_code = BASE_STATUS_CODE;
	_cmd->full_cmd_path = NULL;
}
