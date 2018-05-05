#include <stdio.h>
#define MAX_LINE_TO_BUFFER          1000    // max input line size
#define NUM_LINES_TO_STORE          1000    // lines stored in array for printing later
#define TAB_SPACING                 5       // tabs every x spaces

int getaline(char line[], int maxline);
void copy(char to[], char from[]);
void detab(char line[]);
void entab(char line[]);

// print longest input line
main()
{
    int i;                                                      // for loop index
    int len;                                                    // current line length
    char line[MAX_LINE_TO_BUFFER];                              // current input line
    char storedLines[NUM_LINES_TO_STORE][MAX_LINE_TO_BUFFER];   // stored lines (longer than min length that will be printed), waste of space though
    int index;                                                  // index of stored line
    int j;
    
    index = 0;
    while (len = getaline(line, MAX_LINE_TO_BUFFER))
    {
        if (len > 0)
        {
            copy(storedLines[index], line);
            entab(storedLines[index]);
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
        to[i] = from[i];
        ++i;
    }
}

void entab(char line[])
{
    int length = 0;
    int oldLinePosition = 0;        // original line with tabs is line[], track position with this
    int newLinePosition = 0;
    char currChar;
    int i;
    int tabsToAdd;
    int spacesToAdd;
    int tabsBeforeSpacesStart;
    int numConsecutiveSpaces;
    int indexWhereSpacesStart = -1;
    char newline[MAX_LINE_TO_BUFFER];

    numConsecutiveSpaces = 0;
    while (1)
    {
        currChar = line[oldLinePosition];
        if (currChar == '\n')
        {
            indexWhereSpacesStart = -1;
            numConsecutiveSpaces = 0;
            break;
        }
        else if (currChar == ' ')
        {
            if (indexWhereSpacesStart == -1)
            {
                indexWhereSpacesStart = oldLinePosition;
            }
            numConsecutiveSpaces++;
            oldLinePosition++;
        }
        else
        {
            // only once space before a regular character
            if (numConsecutiveSpaces == 0)
            {
                // printf("currChar: %c", line[oldLinePosition]);
                newline[newLinePosition] = line[oldLinePosition];
                oldLinePosition++;
                newLinePosition++;
            }
            else if (numConsecutiveSpaces == 1)
            {
                newline[newLinePosition] = ' ';
                newLinePosition++;
                newline[newLinePosition] = line[oldLinePosition];
                oldLinePosition++;
                newLinePosition++;
                numConsecutiveSpaces = 0;
            }
            else if (numConsecutiveSpaces > 1)
            {
                tabsBeforeSpacesStart = (int) (indexWhereSpacesStart / TAB_SPACING);
                tabsToAdd = (oldLinePosition - (tabsBeforeSpacesStart * TAB_SPACING))/TAB_SPACING;
                spacesToAdd = oldLinePosition % TAB_SPACING;
                //for (i = 0; i < numConsecutiveSpaces; i++)
                //{
                //    newline[newLinePosition] = 't'; //'\t';
                //    //oldLinePosition++;
                //    newLinePosition++;
                //}
                for (i = 0; i < tabsToAdd; i++)
                {
                    newline[newLinePosition] = '\t';
                    newLinePosition++;
                }
                for (i = 0; i < spacesToAdd; i++)
                {
                    newline[newLinePosition] = ' ';
                    newLinePosition++;
                }
                newline[newLinePosition] = line[oldLinePosition];
                oldLinePosition++;
                newLinePosition++;
                numConsecutiveSpaces = 0;
            }
            indexWhereSpacesStart = -1;
        }
    }
    newline[newLinePosition] = '\0';
    copy(line, newline);
}
