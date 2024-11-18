#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
int main()
{
    FILE *file;
    char input[10000], word[50], db_word[50], sentiment;
    int positive_count = 0, negative_count = 0;

    printf("Enter a string:\n");
    fgets(input, sizeof(input), stdin);

    file = fopen("dataset/words_database.txt", "r");
    if (!file)
    {
        printf("Error: Could not open database file.\n");
        return 1;
    }

    char *token = strtok(input, " ");
    while (token != NULL)
    {
        int j = 0;
        for (int i = 0; token[i]; i++)
        {
            if (isalpha(token[i]))
            {
                word[j++] = token[i];
            }
        }
        word[j] = '\0';

        rewind(file);
        int found = 0;
        while (fscanf(file, "%s %c", db_word, &sentiment) != EOF)
        {
            if (strcmp(word, db_word) == 0)
            {
                found = 1;
                if (sentiment == 'T')
                {
                    positive_count++;
                }
                else if (sentiment == 'F')
                {
                    negative_count++;
                }
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    fclose(file);

    if (positive_count == 0 && negative_count == 0)
    {
        printf("Can't say.\n");
    }
    else if (positive_count > negative_count)
    {
        printf("The statement has a positive emotion.\n");
    }
    else if (negative_count > positive_count)
    {
        printf("The statement has a negative emotion.\n");
    }
    else
    {
        srand(time(0));
        if (rand() % 2 == 0)
        {
            printf("The statement is positive.\n");
        }
        else
        {
            printf("The statement is negative.\n");
        }
    }

    return 0;
}
