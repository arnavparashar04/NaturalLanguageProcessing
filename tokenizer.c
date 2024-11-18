#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Enter a string\n");
    char input[1024];
    fgets(input, 1023, stdin);
    int length = strlen(input);

    int wordcount = 1;
    for (int i = 0; i < length; i++)
    {
        if (input[i] == ' ')
        {
            wordcount++;
        }
    }

    char tokenizedwords[wordcount][50];
    char temp[50];
    int wordcount1 = 0;
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (input[i] == ' ' || input[i] == '\n')
        {
            if (j > 0)
            {
                temp[j] = '\0';
                strcpy(tokenizedwords[wordcount1], temp);
                wordcount1++;
                j = 0;
            }
        }
        else
        {
            temp[j] = input[i];
            j++;
        }
    }

    printf("Tokenized words:\n");
    for (int i = 0; i < wordcount1; i++)
    {
        printf("%s ", tokenizedwords[i]);
    }
    printf("\n");
    return 0;
}
