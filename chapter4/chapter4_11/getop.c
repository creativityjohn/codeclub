#include <ctype.h>
#include <stdio.h>
#include "calc.h"

int getch(void);
void ungetch(int);

// getop: get next operator or numerand
int getop(char s[])
{
    int i, c;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t')
    {
        // do nothing
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
    {
        return c;       // not a number
    }
    i = 0;
    if (isdigit(c))     // collect integer part
    {
        while (isdigit(s[++i] = c = getch()))
        {
            // do nothing
        }
    }
    if (c == '.')       // collect fraction part
    {
        while (isdigit(s[++i] = c = getch()))
        {
            // do nothing
        }
    }
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }
    return NUMBER;
}
