#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE 256
#define WORD 30
#define MAX_LINES 250

int getLine(char s[])
{
    int numOfChars = 0;
    for (int i = 0; i < LINE; i++)
    {
        // submit the character in the char array
        scanf("%c", &s[i]);
        numOfChars++;
        // end of line
        if ((s[i] == '\n') || (s[i] == '\r'))
        {
            // declaration of end of a string
            s[i] = '\0';
            break;
        }
    }
    return numOfChars;
}

int getword(char w[])
{
    int numOfChars = 0;
    for (int i = 0; i < LINE; i++)
    {
        scanf("%c", &w[i]);
        numOfChars++;
        // end of word
        if ((w[i] == '\n') || (w[i] == '\t') || (w[i] == ' ') || (w[i] == '\r'))
        {
            // declaration of end of a string
            w[i] = '\0';
            break;
        }
    }
    return numOfChars;
}

int substring(char *str1, char *str2)
{
    int i, j;
    for (i = 0; i < strlen(str1); i++)
    {
        // strings start the same
        if (str1[i] == str2[0])
        {
            // check the rest, run until first string's end
            for (j = 1; j < strlen(str2) - 1 && (i + j) < strlen(str1); j++)
            {
                // if there is char not the same
                if (str1[i + j] != str2[j])
                {
                    break;
                }
            }
            // done for loop without break = same string (moreover, '\0' char not included)
            if (j == strlen(str2) - 1)
            {
                return 1;
            }
        }
    }
    return 0;
}

int similar(char *s, char *t, int n)
{
    int len1 = strlen(s);
    int len2 = strlen(t);
    int i = 0, j = 0;

    // cannot be substring if occurs
    if (len1 < len2)
    {
        return 0;
    }

    // run until first string ends
    while (i < len1)
    {
        // same characters, than forward both
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            // forward just the bigger and reduce from difference counter
            i++;
            n--;
        }
    }

    // difference was not out of bounds, than there is a way to get it
    if (n >= 0)
    {
        return 1;
    }
    return 0;
}

void print_lines(char *str)
{
    char line[LINE];
    int length;
    for (int i = 0; i < MAX_LINES; i++)
    {
        memset(line, 0, strlen(line));
        length = getLine(line);
        if (substring(line, str))
        {
            printf("%s\n", line);
        }
        if (length <= 0)
        {
            break;
        }
    }
}

void print_similar_words(char *str)
{
    char line[LINE];
    char word[WORD];
    int k;
    // get all the lines from input
    for (int i = 0; i < MAX_LINES; i++)
    {
        getLine(line);
        // get all the words from line
        for (int j = 0; j < strlen(line); j++)
        {
            k = 0;
            memset(word, 0, strlen(word));
            // get the word from the line without calling getline which scanf new word
            while ((j < strlen(line)) && (line[j] != '\n') && (line[j] != '\t') && (line[j] != ' ') && (line[j] != '\r'))
            {
                word[k++] = line[j++];
            }
            word[k] = '\0';
            if (similar(word, str, 1) == 1 || similar(word, str, 0))
            {
                printf("%s\n", word);
            }
        }
        memset(line, 0, strlen(line));
    }
}

int main()
{
    char str_search[WORD];
    char choice[WORD];
    getword(str_search);
    getLine(choice);

    if (choice[0] == 'a')
    {
        print_lines(str_search);
    }
    else if (choice[0] == 'b')
    {
        print_similar_words(str_search);
    }
    return 0;
}