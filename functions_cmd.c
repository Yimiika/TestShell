#include "main.h"

/**
 * functions_cmd - function to return pointer to function
 * @key: input formal
 * Return: pointer to function
 */

void (*functions_cmd(const char *key))(struct shell_command *)
{
    alx_builtins options[] = {
        {"exit", exit_function},
        {"env", environ},
        {"clear", clear_prompt},
        {"cd", direc_change},
        {"setenv", set_builtin_env},   // Update function pointer to match the correct signature
        {"unsetenv", unset_builtin_env}, // Update function pointer to match the correct signature
        {NULL, NULL}
    };

    size_t b_key_len;
    int i = 0;

    if (key == NULL)
        return NULL;

    while (options[i].key != NULL)
    {
        b_key_len = strlen(options[i].key);
        if (strncmp(key, options[i].key, b_key_len) == 0)
            return options[i].function;
        i++;
    }

    return NULL;
}
