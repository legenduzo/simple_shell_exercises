#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * check_char - checks to see if a string contains a - z
 * @str: string to check
 *
 * Return: number of characters
 */

int check_char(char *str)
{
	int i, n = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			n++;
	}
	return (n);
}
/**
 * get_string - returns an array of a single string and null
 * @str: string to return
 * @i: number of char in the string
 * @start: index to start from
 *
 * Return: Array of strings on success, NULL on failure
 */

char *get_string(char *str, int i, int start)
{
	int n;
	char *word;

	while (str[start] == ' ')
		start += 1;

	n = i - start;
	word = malloc(n + 1);
	if (!word)
		return (NULL);

	strncpy(word, &str[start], n);
	word[n] = '\0';

	return (word);
}

/**
 * strings - returns a null terminated array of strings
 * @str: string to split up
 * @words: pointer to strings
 *
 * Return: Array of strings or NULL;
 */

char **strings(char *str, char **words)
{
	int j = 0, i = 0;
	int start = 0;

	if (str[i] == ' ')
		i++;

	while (str[i] != '\0')
	{
		if (str[i] == ' ' && str[i - 1] != ' ')
		{
			words[j] = get_string(str, i, start);
			j++;
			start = i;
		}
		i++;
	}
	if (str[i] == '\0' && str[i - 1] != ' ')
	{
		words[j] = get_string(str, i, start);
		words[j + 1] = NULL;

		return (words);
	}
	else
	{
		words[j + 1] = NULL;

		return (words);
	}
}

/**
 * split_string - splits a string using ' ' as the delimiter.
 * @str: string to split
 *
 * Return: Array of strings on success, NULL on failure
 */

char **split_string(char *str)
{
	int i = 0;
	int word_count = 0;
	char **words;

	if (!str)
		return (NULL);

	if (check_char(str) == 0)
		return (NULL);

	if (str[i] == ' ')
		i++;

	while (str[i] != '\0')
	{
		if (str[i] == ' ' && str[i - 1] != ' ')
			word_count++;
		i++;
	}

	if (str[i] == '\0' && str[i - 1] == ' ')
		words = malloc((word_count + 1) * sizeof(char *));
	else
		words = malloc((word_count + 2) * sizeof(char *));

	if (!words)
		return (NULL);

	return (strings(str, words));
}

/**
 * main - test split_string and free words[i] and words
 *
 * Return: 0
 */

int main(void)
{
	int i = 0;
	char **str = split_string("n   ");
	char **words = split_string("  🙂    Hello World         Split String");


	if (str)
	{
		while (str[i])
		{
			printf("%s\n", str[i]);
			free(str[i]);
			i++;
		}
	free(str);
	}

	i = 0;

	if (words)
	{
		while (words[i])
		{
			printf("%s\n", words[i]);
			free(words[i]);
			i++;
		}
		free(words);
	}
	return (0);
}
