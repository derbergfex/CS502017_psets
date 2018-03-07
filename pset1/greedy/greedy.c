#include <math.h>
#include <stdio.h>
#include <cs50.h>

int main(void)
{
   // Intitial prompt
   printf("O hai! How much change is owed?\n");
   float cash = get_float();

   while (cash < 0)
   {
     // Second recurrent prompt in case the condition isn't met
     printf("O hai! How much change is owed?\n");
     cash = get_float();
   }

   // Important: we convert everything to cents, and then we round to the closest integer
   int x = round(cash * 100);
   int numberOfCoins = 0;

   // What follows are loops that a) check if the current change is more than or equal to the value of the coin
   // b) if not, moves to the next loop (smaller value of coin), or if yes, subtracts the amount, then adds 1 to the number of coins used
   while (x >= 25)
   {
      x -= 25;
      numberOfCoins += 1;
   }

    while (x >= 10)
   {
      x -= 10;
      numberOfCoins += 1;
   }

    while (x >= 5)
   {
      x -= 5;
      numberOfCoins += 1;
   }

    while (x >= 1)
   {
      x -= 1;
      numberOfCoins += 1;
   }

   printf("%i\n", numberOfCoins);
}