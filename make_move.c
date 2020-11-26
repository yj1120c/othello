#include <stdio.h>
#include <ctype.h>
#define SIZE 6

void make_move(char board[][SIZE], int row, int col, char player)
{
   int rowdelta = 0;
   int coldelta = 0;
   int x = 0;
   int y = 0;
   char opponent = (player == 'O')? 'X' : 'O';

   board[row][col] = player;

   
  
   for(rowdelta = -1; rowdelta <= 1; rowdelta++)
     for(coldelta = -1; coldelta <= 1; coldelta++)
     {
      
       if(row + rowdelta < 0 || row + rowdelta >= SIZE ||
          col + coldelta < 0 || col + coldelta >= SIZE ||
                               (rowdelta==0 && coldelta== 0))
         continue;

       
       if(board[row + rowdelta][col + coldelta] == opponent)
       {
         
      
         x = row + rowdelta;
         y = col + coldelta;

         for(;;)
         {
           x += rowdelta;
           y += coldelta;

           if(x < 0 || x >= SIZE || y < 0 || y >= SIZE)
             break;
 
   
           if(board[x][y] == ' ')
             break;

  
           if(board[x][y] == player)
           {
             while(board[x-=rowdelta][y-=coldelta]==opponent)
               board[x][y] = player;
             break;
           }
         }
       }
     }
}
