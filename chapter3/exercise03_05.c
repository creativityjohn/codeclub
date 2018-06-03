#include <stdio.h>
#include "string.h"

#define MAX_STRING_LENGTH 50

char* reverse_string(char s[])
{
    int i = 0;
    char copy[MAX_STRING_LENGTH];
    int len = strlen(s);
    
    for (i = 0; i <= len; i++)
    {
        copy[i] = s[i];
    }
    
    for (i = 0; i < len; i++)
    {
        s[len - i - 1] = copy[i];
    }
    s[len] = '\0';
}

void itob(int n, char s[], int b)
{
    int i = 0;          // position
    char digit;

    while (1)
    {
        digit = n % b;
        if (digit < 10)
        {
            s[i] = digit + '0';
        }
        else
        {
            s[i] = digit - 10 + 'a';
        }
        i++;
        n = n / b;
        if (n == 0)
        {
            break;
        }
    }
    s[i] = '\0';
    reverse_string(s);
}

void main()
{
    int n;
    int b;
    char s[MAX_STRING_LENGTH];
    
    printf("enter integer n: ");
    scanf("%d", &n);

    printf("enter base b: ");
    scanf("%d", &b);

    itob(n, s, b);
    printf("%d in base %d = %s\n", n, b, s);
}
