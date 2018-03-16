#include <stdio.h>

#define MAX_CHARS_PER_WORD  30


// count lines, words, and characters in input
main()
{
  int curr_char;
  int curr_word_length;
  int word_length[MAX_CHARS_PER_WORD];
  int i;
  
  curr_word_length = 0;
  for (i = 0; i <= MAX_CHARS_PER_WORD; i++)
  {
      word_length[i] = 0;
  }
  
  while ((curr_char = getchar()) != EOF)
  {
    // only count numeric and alphabetic chars
    if (((curr_char >= '0') && (curr_char <= '9')) ||
        ((curr_char >= 'A') && (curr_char <= 'Z')) ||
        ((curr_char >= 'a') && (curr_char <= 'z')))
    {
      curr_word_length++;
    }
    else
    {
      word_length[curr_word_length]++;
      curr_word_length = 0;
    }
  }
  
  for (i = 1; i <= MAX_CHARS_PER_WORD; i++)
  {
    printf ("word length %d: %d\n", i, word_length[i]);
  }
}