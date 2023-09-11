#include <stdio.h>

/**
 * main - entry point
 * Description: printargs - print all the arguments without ac
 * @av: argument vector
 * @ac: argument count
 *
 * Return: 0 on success
 */

/*
int main(int ac, char **av)
{
	int i, vc = 0;
	char **av_copy = av;

	while (av_copy[vc])
	{
		vc += 1;
	}

	for (i = 0; i < vc; i++)
	{
		printf("%s\n", av[i]);
	}

	return (0);
}
*/

int main(int ac, char **av)
{
	int i, cv = 0;

	while (av[cv])
	{
		for (i = 0; av[cv][i] != '\0'; i++)
		{
			putchar(av[cv][i]);
		}
		putchar('\n');
		cv++;
	}
	return (0);
}
