#include <stdio.h>

#define swap(type, x, y) { type z; z = x; x = y; y = z; } 

void main()
{
    int x, y;
    
    x = 1;
    y = 2;
    printf("x = %d, y = %d\n", x, y);
    swap(int, x, y);
    printf("x = %d, y = %d\n", x, y);
}