#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_string(char *string, const char *delimiter) {
    char **result = 0;
    size_t count = 0;
    char* tmp = string;
    char* last_delim = 0;
    char delim[2];
    delim[0] = delimiter[0];
    delim[1] = 0;

    /* Count how many elements will be in the array */
    while (*tmp) {
        if (delim[0] == *tmp) {
            count++;
            last_delim = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token */
    count += last_delim < (string + strlen(string) - 1);

    /* Add space for terminating null string */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result) {
        size_t idx  = 0;
        char* token = strtok(string, delim);

        while (token) {
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        *(result + idx) = 0;
    }

    return result;
}

int main() {
    char string[] = "Hello, I am a string. I will be split into words!";
    char **words = split_string(string, " ");
    
    if (words) {
        int i;
        for (i = 0; *(words + i); i++) {
            printf("%s\n", *(words + i));
            free(*(words + i));
        }
        printf("\n");
        free(words);
    }

    return 0;
}
