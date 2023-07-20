#include "main.h"

/**
 * signal_ctrl -this is the function
 * Description: this function is used to control all signals received
 * @num: this is the argument passed into the function
 */

void signal_ctrl(int num)
{
	(void)num;
	write(STDOUT_FILENO, "\n:*** ", 6);
}
