#include "main.h"

/**
 * set_shell_env - Initializes a new environment variable
 * @variable: The variable to initialize or modify.
 * @value: The value to assign.
 * @overwrite: 0 to preserve existing values, non-zero to overwrite.
 * Return: None (void function).
 */
void set_shell_env(const char *variable, const char *value, int overwrite)
{
    if (setenv(variable, value, overwrite) != 0)
    {
        perror("Failed to set or modify env variable");
    }
}

/**
 * unset_shell_env - Removes an environment variable.
 * @variable: The variable to remove.
 * Return: None (void function).
 */
void unset_shell_env(const char *variable)
{
    if (unsetenv(variable) != 0)
    {
        perror("Failed to delete env variable\n");
    }
}


/**
 * get_shell_env - Gets the value of an environment variable.
 * @local_cmd: The name of the environment variable to get.
 * Return: Pointer to the value of the environment variable if found, otherwise NULL.
 */
char *get_shell_env(char *local_cmd)
{
    return (getenv(local_cmd));
}
