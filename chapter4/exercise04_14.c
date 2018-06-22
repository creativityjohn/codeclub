#include <stdio.h>

// don't need pointers because this is not a function and is inserted "inline"
#define swap(t, x, y) { t z; z = x; x = y; y = z; } 

void main()
{
    int x, y;
    
    x = 1;
    y = 2;
    printf("x = %d, y = %d\n", x, y);
    // don't need pointers because this is not a function and is inserted "inline"
    // note that I don't think our cc65 compiler allows declarations that are not at the top of a function
    swap(int, x, y);
    printf("x = %d, y = %d\n", x, y);
}