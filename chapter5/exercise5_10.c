#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArgs(int argc, char *argv[])
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%d: %s\n", i, argv[i]);
    }
}

void expr(int argc, char *argv[])
{
    int i;
    int j;
    float result;
    char resultString[50];
    
    if (argc == 1)
    {
        printf("answer is %s\n", argv[0]);
        return;
    }    
    printf("expr\n");
    printArgs(argc, argv);
    for (i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "+") == 0)
        {
            result = atof(argv[i - 2]) + atof(argv[i - 1]);
            sprintf(resultString, "%f", result);
            strcpy(argv[i - 2], resultString);
            //printf("new index %d = %s\n", i-2, argv[i-2]);
            
            // move all the rest of the args down by 2
            for (j = i - 1; j + i < argc; j++)
            {
                //printf("moving...\n");
                //printf("new index %d from old index %d\n", j, j + i);
                strcpy(argv[j], argv[j + i]);
            }
            //printf("new args\n");
            //printArgs(argc - 2, argv);
            expr(argc - 2, argv);
            return;
        }
        else if (strcmp(argv[i], "-") == 0)
        {
            result = atof(argv[i - 2]) - atof(argv[i - 1]);
            sprintf(resultString, "%f", result);
            strcpy(argv[i - 2], resultString);
            //printf("new index %d = %s\n", i-2, argv[i-2]);
            
            // move all the rest of the args down by 2
            for (j = i - 1; j + i < argc; j++)
            {
                //printf("moving...\n");
                //printf("new index %d from old index %d\n", j, j + i);
                strcpy(argv[j], argv[j + i]);
            }
            //printf("new args\n");
            //printArgs(argc - 2, argv);
            expr(argc - 2, argv);
            return;
        }
        else if (strcmp(argv[i], "x") == 0)
        {
            result = (float) ((float) (atof(argv[i - 2])) * (float) (atof(argv[i - 1])));
            sprintf(resultString, "%f", result);
            strcpy(argv[i - 2], resultString);
            //printf("new index %d = %s\n", i-2, argv[i-2]);
            
            // move all the rest of the args down by 2
            for (j = i - 1; j + i < argc; j++)
            {
                //printf("moving...\n");
                //printf("new index %d from old index %d\n", j, j + i);
                strcpy(argv[j], argv[j + i]);
            }
            //printf("new args\n");
            //printArgs(argc - 2, argv);
            expr(argc - 2, argv);
            return;
        }
        else if (strcmp(argv[i], "/") == 0)
        {
            result = atof(argv[i - 2]) / atof(argv[i - 1]);
            sprintf(resultString, "%f", result);
            strcpy(argv[i - 2], resultString);
            //printf("new index %d = %s\n", i-2, argv[i-2]);
            
            // move all the rest of the args down by 2
            for (j = i - 1; j + i < argc; j++)
            {
                //printf("moving...\n");
                //printf("new index %d from old index %d\n", j, j + i);
                strcpy(argv[j], argv[j + i]);
            }
            //printf("new args\n");
            //printArgs(argc - 2, argv);
            expr(argc - 2, argv);
            return;
        }
    }
}

float main (int argc, char *argv[])
{
    int i;
    
    if (argc <= 3)
    {
        // need at least 2 numbers and an operation
        printf ("invalid input\n");
        return -1.0f;
    }
    printf("argc = %d\n", argc);
    printArgs(argc, argv);
    expr(argc - 1, &argv[1]);       // skip the command string
}