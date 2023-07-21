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
    alx_cmd alx_cmd; /* Change struct alx_cmd to alx_cmd */
    void (*alx_builtins)(struct shell_command *alx_cmd); /* Change struct alx_cmd to alx_cmd */
    int status = 0;

    initialize(&alx_cmd, envir);
    if (isatty(fileno(stdin)) == 1)
        load_alxshell(&alx_cmd);
    signal(SIGINT, signal_ctrl);
    while (1)
    {
        take_userinput(&alx_cmd);
        if (alx_cmd.buffer_size > 1)
        {
            alx_cmd.args = string_parse(alx_cmd.input_line, " \n");
            alx_builtins = functions_cmd(alx_cmd.args[0]);
            if (alx_builtins != NULL)
                alx_builtins(&alx_cmd);
            else
            {
                perform_command(&alx_cmd);
                if (alx_cmd.status != SYS_CMD_NOTFOUND_CODE)
                    free(alx_cmd.cmd_path);
            }
            free(alx_cmd.args);
        }
        status = check_return_codes(&alx_cmd, argv[0], alx_cmd.input_line);
        if (status == EXIT_STATUS_CODE)
        {
            exit(alx_cmd.exit_code);
        }
        if (alx_cmd.input_type == INPUT_FROM_TERMINAL)
            alx_prompt();
    }
    return (0);
}
