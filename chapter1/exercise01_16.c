#include <stdio.h>
#define MAXLINETOPRINT 1000   // max input line size

long getaline(char line[], long maxline);
void copy(char to[], char from[]);

// print longest input line
main()
{
    long len;                   // current line length
    long max;                   // max length seen so far
    char line[MAXLINETOPRINT];         // current input line
    char longest[MAXLINETOPRINT];      // longest line saved here
    
    max = 0;
    while ((len = getaline(line, MAXLINETOPRINT)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)                // there was a line
    {
        printf("\n");
        printf("max line length including newline = %ld, printing up to the first %ld characters\n", max, (long) (MAXLINETOPRINT - 1));   // maxline includes null
        printf("%s\n", longest);
    }
    return 0;
}

// getaline, read a line into s, return length
long getaline(char s[], long lim)
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

// copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[])
{
    long i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}