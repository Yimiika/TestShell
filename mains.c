#include "main.h"

/**
 * main - Entry Point for shell
 * @argc: number of arguments
 * @argv: array of command line arguments
 * @envir: array of environment variables
 * Return: 0
 */
int main(int argc __attribute__((unused)), char **argv, char **envir)
{
    alx_cmd _cmd; // Change struct alx_cmd to alx_cmd
    void (*b_cmd)(alx_cmd *_cmd); // Change struct alx_cmd to alx_cmd
    int status = 0;

    initialize(&_cmd, envir);
    if (isatty(fileno(stdin)) == 1)
        load_alxshell(&_cmd);
    signal(SIGINT, signal_ctrl);
    while (1)
    {
        take_userinput(&_cmd);
        if (_cmd.buffer_size > 1)
        {
            _cmd.args = string_parse(_cmd.input_line, " \n");
            b_cmd = functions_cmd(_cmd.args[0]);
            if (b_cmd != NULL)
                b_cmd(&_cmd);
            else
            {
                perform_command(&_cmd);
                if (_cmd.status != SYS_CMD_NOTFOUND_CODE)
                    free(_cmd.cmd_path);
            }
            free(_cmd.args);
        }
        status = check_return_codes(&_cmd, argv[0], _cmd.input_line);
        if (status == EXIT_STATUS_CODE)
        {
            exit(_cmd.exit_code);
        }
        if (_cmd.input_type == INPUT_FROM_TERMINAL)
            alx_prompt();
    }
    return (0);
}
