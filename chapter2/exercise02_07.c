#include <stdio.h>

// invert(x,p,n) returns x with the n bits that begin at position p inverted (1 changed into 0), leaving others unchanged

#define MAX_INDEX   15

unsigned setbits(int x, int p, int n);
void displayBinary(unsigned val);

main()
{
    unsigned inputVal;
    unsigned p, n;

    printf("Enter an unsigned int (0-65535): ");
    scanf("%d", &inputVal);
    printf("%d\n", inputVal);
    displayBinary(inputVal);
    printf("Enter the index to begin inverting (0-%d): ", MAX_INDEX);
    scanf("%d", &p);
    printf("Enter the number of bits to invert (0-%d): ", MAX_INDEX - p + 1);
    scanf("%d", &n);
    printf("setbits val = %d\n", setbits(inputVal, p, n));
    
}

void displayBinary(unsigned val)
{
    int i;
    
    for (i = MAX_INDEX; i >= 0; i--)
    {
        if (val & (1 << i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
}

unsigned setbits(int x, int p, int n)
{
    int i;
    unsigned retVal = 0;
    
    printf("x=%d\n", x);
    printf("p=%d\n", p);
    printf("n=%d\n", n);
    
    for (i = MAX_INDEX; i >= 0; i--)
    {
        if ((i >= p) && (i < p + n))
        {
            // invert
            if (x & (1 << i))
            {
                printf("0");
            }
            else
            {
                printf("1");
                retVal |= (1 << i);
            }
        }
        else
        {
            if (x & (1 << i))
            {
                printf("1");
                retVal |= (1 << i);
            }
            else
            {
                printf("0");
            }
        }
    }
    printf("\n");
    return retVal;
}
