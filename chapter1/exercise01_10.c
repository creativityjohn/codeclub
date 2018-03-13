#include <stdio.h>

main()
{
  int c, lines, blanks, tabs;
  
  lines = blanks = tabs = 0;
  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      printf("\\t");
    }
    else if ((c == 8) || (c == 127))   // backspace or delete, doesn't work
    {
      printf("\\b");
    }
    else if (c == 92)  // back slash
    {
      printf("\\\\");
    }
    else
    {
      putchar(c);
    }
  }
}