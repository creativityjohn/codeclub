#include <stdio.h>

#define MAX_LINE_LENGTH      200

void escape(char s[], char t[])
{
    int i = 0;      // index for original string s
    int j = 0;      // index for new string t
    while (1)
    {
        switch (s[i])
        {
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            default:
                t[j++] = s[i];
                break;
        }
        i++;
        if (s[i] == '\0')
        {
            t[j] = '\0';
            break;
        }
    }
}

void reverse_escape(char t[], char u[])
{
    int i = 0;      // index for original string t
    int j = 0;      // index for new string u
    while (1)
    {
        switch (t[i])
        {
            case '\\':
                i++;
                switch (t[i])
                {
                    case 't':
                        u[j++] = '\t';
                        break;
                    case 'n':
                        u[j++] = '\n';
                        break;
                }
                break;
            default:
                u[j++] = t[i];
                break;
        }
        i++;
        if (t[i] == '\0')
        {
            u[j] = '\0';
            break;
        }
    }
}

void getLine(char s[])
{
    long i, c;
    
    for (i = 0; (c = getchar()) != EOF; i++)
    {
        if (i < MAX_LINE_LENGTH - 1)        // reserve space for terminating null
        {
            s[i] = c;
        }
        if (i == MAX_LINE_LENGTH - 1)
        {
            break;
        }
    }
    s[i] = '\0';
}

void main()
{
    char s[MAX_LINE_LENGTH];
    char t[MAX_LINE_LENGTH];
    char u[MAX_LINE_LENGTH];
    
    getLine(s);
    printf("original string:\n%s\n", s);
    escape(s, t);
    printf("new string:\n%s\n", t);
    reverse_escape(t, u);
    printf("reverse escape:\n%s\n", u);
}
