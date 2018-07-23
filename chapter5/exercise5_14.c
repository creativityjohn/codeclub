#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES    5000   // max lines to be sorted
#define MAXLEN      1000    // max length of input line
#define ALLOCSIZE   10000   // size of available space

// function prototypes
int readlines (char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int getaline(char *, int);
char *alloc(int);
int mystrcmp (char *s, char *t);
void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int isReverseSort);
int numcmp(char *, char *);

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

// mystrcmp: return <0 if s<t, 0 if s==t, >0 if s>6
int mystrcmp(char *s, char *t)
{
    int i;
    
    for (i = 0; s[i] == t[i]; i++)
    {
        if (s[i] == '\0')
        {
            return 0;
        }
    }
    return s[i] - t[i];
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
    {
        return -1;
    }
    else if (v1 > v2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


// myqsort: sort v[left]...v[right] into increasing order
void myqsort(void *v[], int left, int right, int (*comp)(void *, void *), int isReverseSort)
{
    int i, last;
    void swap(void *v[], int, int);
    
    if (left >= right)      // do nothing if array contains fewer than 2 elements
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
    {
        if (!isReverseSort)
        {
            if ((*comp)(v[i], v[left]) < 0)
            {
                swap(v, ++last, i);
            }
        }
        else
        {
            if ((*comp)(v[i], v[left]) > 0)
            {
                swap(v, ++last, i);
            }
        }
    }
    swap(v, left, last);
    myqsort(v, left, last-1, comp, isReverseSort);
    myqsort(v, last+1, right, comp, isReverseSort);
}

// sort input lines
main (int argc, char *argv[])
{
    int nlines;         // number of input lines read
    int numeric = 0;    // 1 if numeric sort
    int reverse = 0;    // 1 if reverse sort
    
    if (argc > 1 && (strcmp(argv[1], "-n") == 0))
    {
        printf ("-n flag used\n");
        numeric = 1;
    }
    else if (argc > 2 && (strcmp(argv[2], "-n") == 0))
    {
        printf ("-n flag used\n");
        numeric = 1;
    }
    if (argc > 1 && (strcmp(argv[1], "-r") == 0))
    {
        printf ("-r flag used\n");
        reverse = 1;
    }
    else if (argc > 2 && (strcmp(argv[2], "-r") == 0))
    {
        printf ("-r flag used\n");
        reverse = 1;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        myqsort((void **) lineptr, 0, nlines-1, (int (*)(void*,void*))(numeric ? numcmp : mystrcmp), reverse);
        printf("\n");
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}