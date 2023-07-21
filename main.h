#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#define CLEAR_PROMPT() write(STDOUT_FILENO, " \033[1;1H\033[2J", 12)
#define MAX_COMMAND_SIZE 1024
#define DEBUG_MODE_ENABLED 1
#define BASE_STATUS_CODE 0
#define EXIT_STATUS_CODE -1
#define SYS_CMD_FOUND_CODE 2
#define SYS_CMD_NOTFOUND_CODE -2
#define FORK_FAILURE_CODE -3
#define DIR_NOTFOUND_CODE -4
#define INPUT_FROM_TERMINAL 0
#define INPUT_NOT_FROM_TERMINAL 1

/**
 * struct shell_command  - data structure
 * @args: Array of command arguments
 * @env_vars: Array of environment variables
 * @input_line: Raw input command line
 * @cmd_path: Full path of the command executable
 * @status: Status code for shell operations
 * @exit_code: Exit code used for the exit command
 * @input_type: Input type (terminal or not terminal)
 * @line_counter: To keep track of multiple errors (if necessary)
 * @flags: Flags to keep track of the current shell state
 * @buffer_size: Current size of the command buffer
 */
typedef struct shell_command {
    char **args;
    char **env_vars;
    char *input_line;
    char *cmd_path;
    int status;
    int exit_code;
    int input_type;
    int line_counter;
    int flags;
    ssize_t buffer_size;
} alx_cmd;

/**
 * struct shell_builtin_command - choose functions
 *
 * @key: Key for the builtin command
 * @function: Pointer to the function implementing the builtin command
 */
typedef struct shell_builtin_command {
    char *key;
    void (*function)(struct shell_command *); // Update the function pointer type
} alx_builtins;


void load_alxshell(alx_cmd *_cmd);
int shell_getline(char **buff, size_t *size, FILE *file);
void alx_prompt(void);
void perform_command(alx_cmd *_cmd);
char *pathname_retrieved(char *target_dir, char *current_dir);
void take_userinput(alx_cmd *_cmd);
void exit_function(alx_cmd *_cmd);
void clear_prompt(alx_cmd *_cmd);
char *replace_string(char *buffer, char *old_s, char *new_s, size_t fpos);
char *concat_string(size_t num_of_buffers, const char *const format, ...);
size_t get_occurrence(char c, char *str);
ssize_t find_string(const char *str, const char *sub, size_t n);
void environ(alx_cmd *_cmd);
void direc_change(alx_cmd *_cmd);
int alx_cmd_path(struct shell_command *alx_cmd);
void initialize(alx_cmd *_cmd, char **envir_list);
void set_shell_env(const char *variable, const char *value, int overwrite);
void unset_shell_env(const char *variable);
char *get_shell_env(char *local_cmd);
int check_return_codes(struct shell_command *alx_cmd, char *original, char *user_inpt);
char *string_converter(int str_num);
void signal_ctrl(int num);
char **string_parse(char *str, char *del);
void (*functions_cmd(const char *key))(alx_cmd *_cmd);
void set_builtin_env(struct shell_command *alx_cmd);
void unset_builtin_env(struct shell_command *alx_cmd);

#endif
