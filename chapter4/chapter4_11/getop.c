// Instead of using ungetch(), use an internal static variable.
// ungetch() reverts the position of the last get so we can get it again the next go-round.
// For example, 5 2+ will unget the + so we can get the + the next time.
// Therefore, to replace ungetch(), we need to save the currentChar in a static variable.
// Whenever we normally call getch(), we need to use the value in currentChar instead and
// then check the value in getch() to initiate the next go-round.

#include <ctype.h>
#include <stdio.h>
#include "calc.h"

int getch(void);
// void ungetch(int);

// getop: get next operator or numerand
int getop(char s[])
{
    int i, c;
    static int currChar = -1;       // -1 is unitialized

    // Whenever we normally call getch(), we need to use the value in currentChar instead and
    // then check the value in getch() to initiate the next go-round.
    if (currChar == -1)
    {
        c = getch();
    }
    else
    {
        c = currChar;
        currChar = -1;
    }
    
    while ((s[0] = c) == ' ' || c == '\t')
    {
        c = getch();
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
        //ungetch(c);
        currChar = c;
    }
    return NUMBER;
}
