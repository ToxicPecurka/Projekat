#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char tabla[3][3];
const char IGRAC = 'X';
const char COMPUTER = 'O';

void reset_tabla();
void print_tabla();
int main()
{
   char pobednik = ' ';

   reset_tabla();
   print_tabla();

   return 0;
}
void reset_tabla()
{
   int i, j;
   for(i = 0; i < 3; i++)
   {
      for(j = 0; j < 3; j++)
      {
         tabla[i][j] = ' ';
      }
   }
}
void print_tabla()
{
   printf(" %c | %c | %c ", tabla[0][0], tabla[0][1], tabla[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", tabla[1][0], tabla[1][1], tabla[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", tabla[2][0], tabla[2][1], tabla[2][2]);
   printf("\n");
}
