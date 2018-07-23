#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES    2       // max # of input lines
#define MAXLEN      1000    // max length of input line
#define ALLOCSIZE   1000    // size of available space

// function prototypes
int readlines (char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int getaline(char *, int);
char *alloc(int);

static char allocbuf[ALLOCSIZE];        // storage for alloc
static char *allocp = allocbuf;         // next free position
char *lineptr[MAXLINES];

// return pointer to n characters
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        // it fits
        allocp += n;
        return allocp - n;      // old p
    }
    else
    {
        // not enough room
        return 0;
    }
}

// getaline: get line into s, return length
int getaline(char s[], int lim)
{
    int c,i;
    
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

// readlines: read input lines
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    
    nlines = 0;
    while ((len = getaline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
        {
            return -1;
        }
        else
        {
            line[len-1] = '\0';     // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

// writelines: write output lines
void writelines(char *lineptr[], int nlines)
{
    int i;
    
    for (i = 0; i < nlines; i++)
    {
        printf ("%s\n", lineptr[i]);
    }
}

// returns 1 if string t occurs at end of string s, 0 otherwise
int strend(char s[], char t[])
{
    int i;
    int length_s = strlen(s);
    int length_t = strlen(t);
    if (length_s < length_t)
    {
        return 0;
    }
    for (i = 0; i < length_t; i++)
    {
        if (s[length_s - i] != t[length_t - i])
        {
            return 0;
        }
    }
    return 1;
}

// sort input lines
main (int argc, char *argv[])
{
    int nlines;         // number of input lines read

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        // writelines(lineptr, nlines);
        printf("string 1: %s\n", lineptr[0]);
        printf("string 2: %s\n", lineptr[1]);
        printf("strend returns %d\n", strend(lineptr[0], lineptr[1]));
    }
    else
    {
        printf("Can only input 2 lines\n");
    }
}