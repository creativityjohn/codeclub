#include <stdio.h>

main()
{
  float fahr, celsius;
  int lower, upper, step;
  
  lower = -20;
  upper = 140;
  step = 10;
  
  fahr = lower;
  printf("celsius\tfahr\n");
  while (celsius <= upper)
  {
    fahr = (9.0 / 5.0) * celsius + 32.0;
    printf("%7.0f\t%4.0f\n", celsius, fahr);
    celsius = celsius + step;
  }
}