#include "main.h"

/**
 * take_userinput - this is the function
 * Description: this function is used to read whatever command the
 * user enters into the terminal
 * @alx_cmd: this is the argument passed into the function
 */

void take_userinput(struct shell_command *alx_cmd)
{
    size_t reserve_size = 0;
    ssize_t outcome;

    alx_cmd->line_counter++;
    alx_cmd->input_line = NULL;

    // Allocate memory for input_line
    alx_cmd->input_line = malloc(1024 * sizeof(char));
    if (alx_cmd->input_line == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    // Call shell_getline with the proper arguments
    outcome = shell_getline(&(alx_cmd->input_line), &reserve_size, stdin);

    if (outcome == EOF)
    {
        alx_cmd->status = EXIT_STATUS_CODE;
        return;
    }

    alx_cmd->buffer_size = outcome;
}
