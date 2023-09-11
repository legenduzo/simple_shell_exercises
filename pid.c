#include <unistd.h>
#include <stdio.h>

/**
 * main - entry point
 * Description: pid and ppid represent the process id in unix-like systems
 * Return: 0
 */

int main()
{
	printf("PID: %u\n", getpid());
	printf("PID: %u\n", getppid());

	return (0);
}
