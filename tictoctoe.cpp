#include <stdio.h>
 
#define SIZE 3       
 
void oyun(void);
int kontrol(void);
 
int a [SIZE][SIZE] = {0};
 
int main()
{
   int oyuncu, secim, i, j;
   int sonuc;

 
   oyuncu = 1;
   while ((sonuc = kontrol()) == 0) {
      oyun();
      printf("oyuncu: %d, seciminizi yapin: [%d-%d]", oyuncu, 1, SIZE * SIZE);
      do {
         scanf("%d", &secim);
         while (getchar() != '\n')   
            ;
         j = secim % SIZE- 1;
         i = (secim - j) / SIZE;
         if (secim > SIZE * SIZE || secim <= 0 || a[i][j] != 0) {
            printf("yanlis secim, oyuncu %d tekrar deneyin: ", oyuncu);
            continue;
         }
         else {
            a[i][j] = oyuncu;
            break;
         }
      } while(1);
        oyuncu = (oyuncu == 1) ? 2 : 1;
   }
   oyun();
   if (sonuc == -1)
      printf("oyun bitti ,kazanan yok");
   else
      printf("oyuncu %d kazandi tebrikler", sonuc);
   return 0;
}

void oyun()
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

int kontrol(void)
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

