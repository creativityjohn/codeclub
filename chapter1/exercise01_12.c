#include <stdio.h>

#define INSIDE_WORD   1
#define OUTSIDE_WORD  0

// count lines, words, and characters in input
main()
{
  int curr_char;
  
  while ((curr_char = getchar()) != EOF)
  {
    if ((curr_char == ' ') || (curr_char == '\n') || (curr_char == '\t'))
    {
      putchar('\n');
    }
    else
    {
      putchar(curr_char);
    }
  }
}