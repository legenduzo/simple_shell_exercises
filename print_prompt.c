#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - entry point
 * Description: print_prompt prints $ then the user's input.
 * Alternatively, call getline() in the while loop if you want it to keep running.
 *
 * Return: 0 on success, 1 on failure
 */

int main()
{
	char *input = NULL;
	size_t strlen = 0;
	ssize_t result;

	printf("$ ");

	result = getline(&input, &strlen, stdin);

	if (result != -1)
	{
		printf("%s\n", input);
	}
	printf("PROCESS ID: %u\n", getpid());
	printf("PARENT PROCESS ID: %u\n", getppid());
	free(input);
	return(0);
}
