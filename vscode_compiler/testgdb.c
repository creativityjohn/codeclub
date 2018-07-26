#include <stdio.h>

int main()
{
    int i, num, j;
    printf("Enter a number: ");
    scanf("%d", &num);
    j = 1;
    for (i = 1; i <= num; i++)
    {
        j = j * i;
    }
    printf("%d! = %d\n", num, j);
}