#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char tabla[3][3];
const char IGRAC = 'X';
const char COMPUTER = 'O';

void reset_tabla();
void print_tabla();
int slobodna_mesta();
void igracev_potez();
int main()
{
   char pobednik = ' ';

   reset_tabla();
   while(pobednik == ' ' && slobodna_mesta() != 0)
   {
      print_tabla();

      igracev_potez();
   }
   

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
int slobodna_mesta()
{
   int slobodno_mesto = 9;
   int i, j;

   for( i = 0; i < 3; i++)
      {
         for(j = 0; j < 3; j++)
         {
            if(tabla[i][j] != ' ')
            {
               slobodno_mesto--;
            }
         }
      }
   return slobodno_mesto;
}
void igracev_potez()
{
   int vrsta;
   int kolona;

   do 
   {
      p:
      printf("unesi vrstu (1 - 3):");
      scanf("%d",&vrsta);
      vrsta--;
      printf("unesi kolonu (1 - 3):");
      scanf("%d",&kolona);
      kolona--;
      if(vrsta !=1,2,3 && kolona !=1,2,3 )
      {
         printf("pogresan unos\n");
         break;
      }
      if(tabla[vrsta][kolona] != ' ')
      {
         printf("pogresan korak\n");
      }
      else
      {
         tabla[vrsta][kolona] = IGRAC;
         break;
      }
   }while(tabla[vrsta][kolona] != ' ');
}