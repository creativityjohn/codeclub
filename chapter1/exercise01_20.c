#include <stdio.h>
#define MAX_LINE_TO_BUFFER          1000    // max input line size
#define NUM_LINES_TO_STORE          1000    // lines stored in array for printing later
#define TAB_SPACING                 5       // tabs every x spaces

int getaline(char line[], int maxline);
void copy(char to[], char from[]);
void detab(char line[]);

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
            detab(storedLines[index]);
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

void detab(char line[])
{
    int length = 0;
    int oldLinePosition = 0;        // original line with tabs is line[], track position with this
    int newLinePosition = 0;
    int i;
    int spacesToAdd;
    int numTabsToTabbedPosition;    // number of tabs to the tabbed position
    int positionOfNextTab;          // position of the next tab
    
    char newline[MAX_LINE_TO_BUFFER];
    while (1)
    {
        if (line[oldLinePosition] == '\t')
        {
            //printf("newline tab at position: %d\n", newLinePosition);
            numTabsToTabbedPosition = (int) ((newLinePosition / TAB_SPACING) + 1);
            //printf("numTabsToTabbedPosition: %d\n", numTabsToTabbedPosition);
            positionOfNextTab = numTabsToTabbedPosition * TAB_SPACING;
            //printf("positionOfNextTab: %d\n", positionOfNextTab);
            
            spacesToAdd = positionOfNextTab - newLinePosition;
            //printf("spacesToAdd: %d\n", spacesToAdd);
            for (i = 0; i < spacesToAdd; i++)
            {
                newline[newLinePosition] = ' ';
                newLinePosition++;
            }
            // final increment is below
            newLinePosition--;
        }
        // check for space in new line
        else if (newLinePosition > MAX_LINE_TO_BUFFER)
        {
            newline[newLinePosition] = '\0';
            break;
        }
        else if (line[oldLinePosition] == '\n')
        {
            newline[newLinePosition] = '\n';
            break;
        }
        else
        {
            //printf("newLinePosition: %d\n", newLinePosition);
            //printf("oldLinePosition: %d %c\n", oldLinePosition, line[oldLinePosition]);
            newline[newLinePosition] = line[oldLinePosition];
        }
        oldLinePosition++;
        newLinePosition++;
    }
    newline[newLinePosition] = '\0';
    copy(line, newline);
}
