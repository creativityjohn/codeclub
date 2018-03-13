#include <stdio.h>

main()
{
  int c, lines, blanks, tabs;
  
  lines = blanks = tabs = 0;
  while ((c = getchar()) != EOF)
  {
    if (c == '\n')
    {
      lines++;
    }
    else if (c == '\t')
    {
      tabs++;
    }
    else if (c == ' ')
    {
      blanks++;
    }
  }
  printf("lines %d\n", lines);
  printf("tabs %d\n", tabs);
  printf("blanks %d\n", blanks);
}