#include "main.h"

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

    dup_path = shell_strdup(path);
    parsed_path = string_parse(dup_path, ":\n");
    if (parsed_path == NULL)
    {
        // Handle the case when PATH is not set or empty
        free(dup_path);
        return SYS_CMD_NOTFOUND_CODE;
    }

    while (parsed_path[i])
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
    free(parsed_path);
    free(dup_path);
    return SYS_CMD_NOTFOUND_CODE;
}
