#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char tabla[3][3];
char IGRAC;
char COMPUTER;  

void reset_tabla();
void print_tabla();
int slobodna_mesta();
void igracev_potez();
void computer_potez();
char check_Pobednik();
void print_pobednik(char);
void main()
{
   int izbor;
   printf("Koji znak zelis (X/O)?\n");
   scanf(" %c",&IGRAC);
   if(IGRAC == 'O')
   {
      COMPUTER = 'X';
   }
   else 
      COMPUTER = 'O';

   char pobednik = ' ';
   printf("ako hoces igrati prvi unesi (1/0)?\n");
   scanf("%d",&izbor);
   reset_tabla();
   if(izbor==1)
   {
         while(pobednik == ' ' && slobodna_mesta() != 0)
         {
            igracev_potez();
            print_tabla();
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
            computer_potez();
            pobednik = check_Pobednik();
            if(pobednik != ' ' || slobodna_mesta() == 0)
            {
               break;
            }
            igracev_potez();
            pobednik = check_Pobednik();
            if(pobednik != ' ' || slobodna_mesta() == 0)
            {
               break;
            }
         }
   }
   else
   {
      while(pobednik == ' ' && slobodna_mesta() != 0)
      {
         computer_potez();
         print_tabla();
         pobednik = check_Pobednik();
         if(pobednik != ' ' || slobodna_mesta() == 0)
         {
            break;
         }
         igracev_potez();
         pobednik = check_Pobednik();
         if(pobednik != ' ' || slobodna_mesta() == 0)
         {
            break;
         }
      }
   }
   

   print_tabla();
   print_pobednik(pobednik);
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
   int vrsta = 0;
   int kolona = 0;
   do 
   {
      p:
      vrsta=0;
      kolona=0;
      printf("unesi vrstu (1 - 3):");
      scanf("%d",&vrsta);
      vrsta--;
      printf("unesi kolonu (1 - 3):");
      scanf("%d",&kolona);
      kolona--;
      if((vrsta >= 0 && vrsta <= 2) && (kolona >= 0 && kolona <= 2))
      {
            if(tabla[vrsta][kolona] != ' ')
            {
               printf("pogresan korak\n");
               goto p;
            }
            printf("ispravan unos\n");            
            tabla[vrsta][kolona] = IGRAC;
            break; 
      }
      else
      {
            printf("pogresan unos\n");
            goto p;
      }
   }
   while(tabla[vrsta][kolona] != ' ');
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
      printf(" NERESENO JE ! ");
   }
}