#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#define SIZE 64

/**
 * main - entry point
 * Description: prints the max pid in a system
 *
 * Return: 0 on success, 1 on failure
 */

int main()
{
	int fd;
	char buffer[SIZE];
	ssize_t readCount;

	fd = open("/proc/sys/kernel/pid_max", O_RDONLY);
	if (!fd)
	{
		perror("Could not open pid_max");
		return (1);
	}

	readCount = read(fd, buffer, SIZE - 1);
	if (readCount < 0)
	{
		perror("Could not read from the file");
		return (1);
	}
	buffer[readCount] = '\0';

	printf("MAX PID: %s\n", buffer); /* pid_max file ends with a '\0' adding another creates an extra space */

	close(fd);
	return (0);
}
