#include <stdio.h>

float convertFahrToC(float fahr)
{
  return (5.0 / 9.0) * (fahr - 32.0);
}
main()
{
  float fahr, celsius;
  int lower, upper, step;
  
  lower = 0;
  upper = 300;
  step = 20;
  
  fahr = lower;
  printf("fahr\tcelsius\n");
  while (fahr <= upper)
  {
    celsius = convertFahrToC(fahr);
    printf("%4.0f\t%7.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
