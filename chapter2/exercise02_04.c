#include <stdio.h>
#define MAXLINETOPRINT 1000   // max input line size

long getLine(char line[], long maxline);
void squeeze(char s[], char c[]);
void squeezeChar(char s[], int c);


main()
{
    long len;                   // current line length
    long max;                   // max length seen so far
    char inputLine[MAXLINETOPRINT];         // current input line
    char excludeCharsLine[MAXLINETOPRINT];  // line of chars to exclude
    long inputLineLength;
    long excludeCharsLineLength;
    
    max = 0;
    printf("Enter line of text:\n");
    inputLineLength = getLine(inputLine, MAXLINETOPRINT);
    //printf("%s\n", inputLine);   
    printf("Enter string of chars to remove:\n");
    excludeCharsLineLength = getLine(excludeCharsLine, MAXLINETOPRINT);
    //printf("%s\n", excludeCharsLine);   
    squeeze(inputLine, excludeCharsLine);
    printf("%s\n", inputLine);
}

// returns line length
long getLine(char s[], long lim)
{
    long c, i;
    
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (i < lim - 1)
        {
            s[i] = c;
        }
    }
    if (c == '\n') 
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

// squeeze: delete all c from s
void squeeze(char s[], char c[])
{
    int i;
    i = 0;
    while (1)
    {
        if (c[i] == '\0')
        {
            break;
        }
        else
        {
            squeezeChar(s, c[i]);
            i++;
        }
    }
}

void squeezeChar(char s[], int c)
{
    int i, j, k;
    
    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}