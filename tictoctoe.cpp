#include <stdio.h>
 
#define SIZE 3       
 
void print_game(void);
int check_status(void);
 
int a[SIZE][SIZE] = {0};
 
int main()
{
   int player, choice, i, j;
   int result;
 
   player = 1;
   while ((result = check_status()) == 0) {
      print_game();
      printf("oyuncu: %d, seçiminizi yapin: [%d-%d]", player, 1, SIZE * SIZE);
      do {
         scanf("%d", &choice);
         while (getchar() != '\n')   
            ;
         j = choice % SIZE - 1;
         i = (choice - j) / SIZE;
         if (choice > SIZE * SIZE || choice <= 0 || a[i][j] != 0) {
            printf("yanlis secim, oyuncu %d tekrar deneyin: ", player);
            continue;
         }
         else {
            a[i][j] = player;
            break;
         }
      } while(1);
        player = (player == 1) ? 2 : 1;
   }
   print_game();
   if (result == -1)
      printf("oyun bitti ,kazanan yok");
   else
      printf("oyuncu %d kazandi tebrikler", result);
   return 0;
}

void print_game()
{
   int i, j;
 
   printf("TÝC TAC TOE OYUNU\n");
   printf("-----------------------\n");
   for (i = 0; i < SIZE; i++) {
      for (j = 0; j < SIZE; j++)
         if (a[i][j] == 0)
            printf(" . ");
         else if (a[i][j] == 1)
            printf(" O ");
         else
            printf(" X ");
      putchar('\n');
   }
}

int check_status(void)
{
   int i, j, k;
   int count;
 
   for (k = 1; k < SIZE; k++) {
      for (i = 0; i < SIZE; i++) {         
         for (j = 0; j < SIZE; j++)
            if (a[i][j] != k)
               break;
         if (j == SIZE)
            return k;          
      }
      for (j = 0; j < SIZE; j++) {         
         for (i = 0; i < SIZE; i++)
            if (a[i][j] != k)
               break;
         if (i == SIZE)
            return k;         
      }
      for (i = 0; i < SIZE; i++)             
         if (a[i][i] != k)
            break;
      if (i == SIZE)
         return k;                
 
      for (i = 0, j = 2; i < SIZE; i++, j--)     
         if (a[i][j] != k)
            break;
      if (i == SIZE)
         return k;                               
   }
   count = 0;
   for (i = 0; i < SIZE; i++)
      for (j = 0; j < SIZE; j++)
         if(a[i][j] != 0)
            count++;
   if (count == SIZE * SIZE)
      return -1;
   return 0;
}
