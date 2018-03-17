#include <stdio.h>

#define MAX_ASCII_CHAR_TO_TRACK   127

main()
{
  int curr_char;
  int asciiIndex[MAX_ASCII_CHAR_TO_TRACK];    // asciiIndex[0] will contain the number of times ascii char 0 has occurred
  int i, j;
  
  for (i = 0; i <= MAX_ASCII_CHAR_TO_TRACK; i++)
  {
      asciiIndex[i] = 0;
  }
  
  while ((curr_char = getchar()) != EOF)
  {
    if ((curr_char >= 0) && (curr_char <= 127))
    {
      asciiIndex[curr_char]++;
    }
  }
  
  for (i = 0; i <= MAX_ASCII_CHAR_TO_TRACK; i++)
  {
    printf ("%c\t%2d\n", i, asciiIndex[i]);
  }
}