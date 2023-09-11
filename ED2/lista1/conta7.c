#include <stdio.h>

int Count_Of_Digits (long int); 

int main()
{
  long int Number, Count = 0;

  scanf("%ld", &Number);

  Count = Count_Of_Digits (Number);

  printf("%ld\n", Count);
  return 0;
}

int Count_Of_Digits (long int Number)
{
  static int Count = 0;

  if(Number > 0)
  {
    long int aux = Number % 10;
    if(aux == 7){
        Count = Count + 1; 
    }
    Count_Of_Digits (Number / 10);
  }

 return Count;
}