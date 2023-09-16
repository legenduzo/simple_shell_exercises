#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	int i, status;
	char *envp[] = {NULL};
	char *argv[] = {"ls", "-l", "/tmp", NULL};
	char *number[] = {"First", "Second", "Third", "Fourth", "Fifth"};

	printf("PID: %u\n", getpid());
	for (i = 0; i < 5; i++)
	{
		pid = fork();

		printf("%s Child PID: %u\n\n", number[i], getpid());
		if (pid == 0)
		{
			execve("/bin/ls", argv, envp);
			perror("execve");
			return (1);
		}
		else if (pid > 0)
			wait(&status);
		else
		{
			perror("Error:");
			return (1);
		}
	}

	return (0);
}
