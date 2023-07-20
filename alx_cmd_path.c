#include "main.h"

/**
 * alx_cmd_path - Get the full path of a system command.
 * @_cmd: Main data struct.
 * Return: SYS_CMD_FOUND_CODE if succeeded
 */

int alx_cmd_path(alx_cmd *_cmd)
{
    struct stat _stat;
    int f_stat, i = 0;
    char *conc_path, *path = get_shell_env("PATH"), *dup_path;
    char **parsed_path;

    f_stat = stat(_cmd->args[0], &_stat);
    if (f_stat == 0)
    {
        _cmd->cmd_path = concat_string(2, _cmd->args[0], "");
        return SYS_CMD_FOUND_CODE;
    }

    dup_path = strdup(path);
    parsed_path = parse_str(dup_path, ":\n");
    /* check if file exists pre appending path */
    while (path[i])
    {
        conc_path = concat_string(3, parsed_path[i], "/", _cmd->args[0]);
        f_stat = stat(conc_path, &_stat);
        if (f_stat == 0)
        {
            _cmd->cmd_path = conc_path;
            free(parsed_path);
            free(dup_path);
            return SYS_CMD_FOUND_CODE;
        }
        free(conc_path);
        i++;
    }
    free(dup_path);
    return SYS_CMD_NOTFOUND_CODE;
}
