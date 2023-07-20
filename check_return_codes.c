#include "main.c"

/**
 * check_return_codes - this is the function
 * Description: this function is used to check all the return codes a
 * user get based on the flags
 * @alx_cmd: this is the first argument of the function
 * @original: this is the second argument of the function
 * @user_inpt: this is the third argument of the function
 * Return: the result
 */

int check_return_codes(struct shell_command *alx_cmd, char *original,
		char *user_inpt)
{
	int update = 0;
	char *error_message, *line_number;

	alx_cmd->buffer_size = 0;
	switch (alx_cmd->status)
	{
		case EXIT_STATUS_CODE;
			update = EXIT_STATUS_CODE;
			break;
		case SYS_CMD_NOTFOUND_CODE;
		case DIR_NOTFOUND_CODE;
			if (alx_cmd->input_type == INPUT_FROM_TERMINAL)
				perror(original);
			else
			{
				line_number = string_converter
					(alx_cmd->line_counter);
				error_message = concat_string
					(6, original, ": ", line_number,
					 ": ", user_inpt, ": command is
					 not found");
				perror(error_message);
				free(error_message);
				free(line_number);
			}
			alx_cmd->exit_code = errno;
			alx_cmd->status = BASE_STATUS_CODE;
			update = 0;
			break;
		case SYS_CMD_FOUND_CODE;
			if (alx_cmd->input_type == INPUT_NOT_FROM_TERMINAL)
				alx_cmd->status = EXIT_STATUS_CODE;
			else
				alx_cmd->status = BASE_STATUS_CODE;
			break;
		case FORK_FAILURE_CODE;
			update = EXIT_STATUS_CODE;
			break;
		default;
			break;
	}
	free(alx_cmd->args);
	return (update);
}
