#include <stdio.h>

#define MAX_LINE_LENGTH      200

void expand(char s1[], char s2[])
{
    int i = 0;      // index for original string s
    int j = 0;      // index for new string t
    while (1)
    {
        switch (s1[i])
        {
            case '-':
                while (1)
                {
                    s2[j] = s2[j - 1] + 1;
                    if (s2[j] == s1[i + 1])
                    {
                        break;
                    }
                    else
                    {
                        j++;
                    }
                }
                break;
            default:
                s2[j++] = s1[i];
                break;
        }
        i++;
        if (s1[i] == '\0')
        {
            s2[j] = '\0';
            break;
        }
    }
}

void getLine(char s[])
{
    long i, c;
    
    for (i = 0; (c = getchar()) != EOF; i++)
    {
        if (i < MAX_LINE_LENGTH - 1)        // reserve space for terminating null
        {
            s[i] = c;
        }
        if (i == MAX_LINE_LENGTH - 1)
        {
            break;
        }
    }
    s[i] = '\0';
}

void main()
{
    char s1[MAX_LINE_LENGTH];
    char s2[MAX_LINE_LENGTH];
    
    getLine(s1);
    printf("original string s1:\n%s\n", s1);
    expand(s1, s2);
    printf("new string s2:\n%s\n", s2);
}
