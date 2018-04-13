#include <stdio.h>
#define MAX_LINE_TO_BUFFER          1000    // max input line size
#define NUM_LINES_TO_STORE          1000    // lines stored in array for printing later

int getaline(char line[], int maxline);
void copy(char to[], char from[]);
void removeTrailingWhitespace(char line[], int lineLength);

// print longest input line
main()
{
    int i;                                                      // for loop index
    int len;                                                    // current line length
    char line[MAX_LINE_TO_BUFFER];                              // current input line
    char storedLines[NUM_LINES_TO_STORE][MAX_LINE_TO_BUFFER];   // stored lines (longer than min length that will be printed), waste of space though
    int index;                                                  // index of stored line
    
    index = 0;
    while (len = getaline(line, MAX_LINE_TO_BUFFER))
    {
        // remove empty lines
        if ((len > 0) && (line[0] != '\n'))
        {
            copy(storedLines[index], line);
            removeTrailingWhitespace(storedLines[index], len);
            index++;
        }
        // abort if we ran out of storage space
        if (index >= NUM_LINES_TO_STORE)
        {
            break;
        }
    }
    printf("\n");
    for (i = 0; i < index; i++)
    {
        printf("line %d: %s\n", i, storedLines[i]);
    }
    return 0;
}

// getaline, read a line into s, return length
int getaline(char s[], int lim)
{
    int c, i;
    
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
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}

void removeTrailingWhitespace(char line[], int lineLength)
{
    int position = lineLength - 1;  // skip null
    while (1)
    {
        if ((line[position] == '\t') || (line[position] == ' '))
        {
            position--;
        }
        else
        {
            break;
        }
    }
    // end line with a new null
    line[position] = '\0';
}

