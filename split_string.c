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
 * single_string - returns an array of a single string and null
 * @str: string to return
 * @i: number of char in the string
 * @words: pointer to strings
 *
 * Return: Array of strings on success, NULL on failure
 */

char **single_string(char *str, int i, char **words)
{
	int start = 0, n;

	while (str[start] == ' ')
		str[start] += 1;

	n = i - start;
	words[0] = malloc(n + 1);
	if (!words[0])
		return (NULL);

	strncpy(words[0], &str[start], n);
	words[0][n] = '\0';
	words[1] = NULL;

	return (words);
}

/**
 * many_strings - returns a null terminated array of strings
 * @str: string to split up
 * @words: pointer to strings
 *
 * Return: Array of strings or NULL;
 */

char **many_strings(char *str, char **words);

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

	if (i > 0 && word_count == 0)
		return (single_string(str, i, words));
	else
		return (many_strings(str, words));
}

/**
 * many_strings - returns a null terminated array of strings
 * @str: string to split up
 * @words: pointer to strings
 *
 * Return: Pointer to array of strings or NULL
 */

char **many_strings(char *str, char **words)
{
	int n, j = 0, i = 0;
	int start = 0;

	if (str[i] == ' ')
		i++;

	while (str[i] != '\0')
	{
		if (str[i] == ' ' && str[i - 1] != ' ')
		{
			while (str[start] == ' ')
				start += 1;

			n = i - start;
			words[j] = malloc(n + 1);
			if (!words[j])
				return (NULL);

			strncpy(words[j], &str[start], n);
			words[j][n] = '\0';
			j++;
			start = i;
		}
		i++;
	}
	if (str[i] == '\0' && str[i - 1] != ' ')
	{
		while (str[start] == ' ')
			start += 1;

		n = i - start;
		words[j] = malloc(n + 1);
		if (!words[j])
			return (NULL);

		strncpy(words[j], &str[start], n);
		words[j][n] = '\0';
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
 * main - test split_string and free words[i] and words
 *
 * Return: 0
 */

int main(void)
{
	int i = 0;
	char **str = split_string("   n   ");
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
