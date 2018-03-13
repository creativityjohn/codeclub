#include <stdio.h>

main()
{
  int c;
  int hasDisplayedBlank = 0;
  
  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
    {
      if (!hasDisplayedBlank)
      {
        hasDisplayedBlank = 1;
        putchar(c);
      }
    }
    else
    {
      putchar(c);
      hasDisplayedBlank = 0;
    }
  }
}