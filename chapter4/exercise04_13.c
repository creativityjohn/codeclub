#include <string.h>
#include <stdio.h>

#define MAX_STR_LEN     100

void recursiveReverse(char s[], int firstPosToReverse, int lastPosToReverse)
{
    int c, i, j;
    
    c = s[firstPosToReverse];
    s[firstPosToReverse] = s[lastPosToReverse];
    s[lastPosToReverse] = c;
    
    if (firstPosToReverse >= lastPosToReverse)
    {
        return;
    }
    else
    {
        recursiveReverse(s, firstPosToReverse + 1, lastPosToReverse - 1);
    }
}

// reverse: reverse string s in place
void reverse (char s[])
{
    recursiveReverse(s, 0, strlen(s) - 1);
}

void getString(char s[])
{
    long i, c;
    
    for (i = 0; (c = getchar()) != EOF; i++)
    {
        if (i < MAX_STR_LEN - 1)        // reserve space for terminating null
        {
            s[i] = c;
        }
        if (i == MAX_STR_LEN - 1)
        {
            break;
        }
    }
    s[i] = '\0';
}

void main()
{
    char str[MAX_STR_LEN];
    
    printf("Enter string: ");
    getString(str);
    printf("\nString: %s\n", str);
    reverse(str);
    printf("Reversed: %s\n", str);
}