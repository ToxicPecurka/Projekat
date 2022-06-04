#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char tabla[3][3];
const char IGRAC = 'O';
const char COMPUTER = 'x';

void reset_tabla();
void print_tabla();
int slobodna_mesta();
void igracev_potez();
void computer_potez();
char check_Pobednik();
void print_pobednik(char);
int main()
{
   char pobednik = ' ';

   reset_tabla();
   while(pobednik == ' ' && slobodna_mesta() != 0)
   {
      print_tabla();

      igracev_potez();
      pobednik = check_Pobednik();
      if(pobednik != ' ' || slobodna_mesta() == 0)
      {
         break;
      }
      computer_potez();
      pobednik = check_Pobednik();
      if(pobednik != ' ' || slobodna_mesta() == 0)
      {
         break;
      }
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
      printf("unesi vrstu (1 - 3):");
      scanf("%d",&vrsta);
      vrsta--;
      printf("unesi kolonu (1 - 3):");
      scanf("%d",&kolona);
      kolona--;
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
void computer_potez()
{
   srand(time(0));
   int x;
   int y;

   if(slobodna_mesta() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      }while(tabla[x][y] != ' ');
      
      tabla[x][y] = COMPUTER;
   }
   else
   {
      print_pobednik(' ');
   }
}
char check_Pobednik()
{
   //ispitivanje redova
   for(int i = 0; i < 3; i++ )
   {
      if(tabla[i][0] == tabla[i][1] && tabla[i][0] == tabla[i][2])
      {
         return tabla[i][0];
      }
   }
   //ispitivanje kolona
    for(int i = 0; i < 3; i++ )
   {
      if(tabla[0][i] == tabla[1][i] && tabla[0][i] == tabla[2][i])
      {
         return tabla[0][i];
      }
   }
   //ispitivanje dijagonala
   if(tabla[0][0] == tabla[1][1] && tabla[0][0] == tabla[2][2])
      {
         return tabla[0][0];
      }
   if(tabla[0][2] == tabla[1][1] && tabla[0][2] == tabla[2][0])
      {
         return tabla[0][2];
      }
   return ' ';
}
void print_pobednik(char pobednik)
{
   if(pobednik == IGRAC)
   {
      printf(" POBEDIO SI ! ");
   }
   else if (pobednik == COMPUTER)
   {
      printf(" IZGUBIO SI ! ");
   }
   else
   {
      printf(" NEREŠENO JE ! ");
   }
}