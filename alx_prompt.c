#include "main.h"

/**
 * alx_prompt - this is the function
 * Description: This function is used to print a prompt message
 * which shows the user where and when to enter a command
 */

void alx_prompt(void)
{
	write(STDOUT_FILENO, "#alx$ ", 7);
}
