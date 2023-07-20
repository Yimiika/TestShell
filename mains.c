#include "main.h"

/**
 * main - Entry Point for shell
 * @argc: number of argumenta
 * @argv: array of command line arguments
 * @envir: array of environment variables
 * Return: 0
 */
int main(int argc __attribute__((unused)), char **argv, char **envir)
{
    struct alx_cmd _cmd;
    void (*b_cmd)(struct alx_cmd *_cmd);
    int status = 0;

    init_cmd(&_cmd, envir);
    if (isatty(fileno(stdin)) == 1)
        init_shell(&_cmd);
    signal(SIGINT, shell_signal);
    while (1)
    {
        read_command(&_cmd);
        if (_cmd.buffer_size > 1)
        {
            _cmd.args = parse_str(_cmd.input_line, " \n");
            b_cmd = get_builtin_cmd(_cmd.args[0]);
            if (b_cmd != NULL)
                b_cmd(&_cmd);
            else
            {
                sys_cmd_exec(&_cmd);
                if (_cmd.status_code != SYS_CMD_NOTFOUND_CODE)
                    free(_cmd.cmd_path);
            }
            free(_cmd.args);
        }
        status = handle_status_codes(&_cmd, argv[0], _cmd.input_line);
        if (status == EXIT_STATUS_CODE)
        {
            exit(_cmd.exit_code);
        }
        if (_cmd.input_type == INPUT_FROM_TERMINAL)
            alx_prompt();
    }
    return (0);
}
