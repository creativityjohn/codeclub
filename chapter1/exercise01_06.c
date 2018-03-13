#include <stdio.h>

main()
{
  int c;
  
  while (1)
  {
    c = (getchar() != EOF);
    // not sure why this only prints when EOF is read, and then it prints all the chars that were apparently buffered
    printf("%d\n", c);
    if (c != 1)
    {
      break;
    }
  }
  printf("EOF %d\n", c);
}