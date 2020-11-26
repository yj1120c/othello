#include <stdio.h>
#include <ctype.h>
#define SIZE 6

int valid_moves(char board[][SIZE], int moves[][SIZE], char player)
{
   int rowdelta = 0;
   int coldelta = 0;
   int row = 0;
   int col = 0;
   int x = 0;
   int y = 0;
   int no_of_moves = 0;

   char opponent = (player == 'O')? 'X' : 'O';

   for(row = 0; row < SIZE; row++)
     for(col = 0; col < SIZE; col++)
       moves[row][col] = 0;

   for(row = 0; row < SIZE; row++)
     for(col = 0; col < SIZE; col++)
     {
       if(board[row][col] != ' ')
         continue;
       for(rowdelta = -1; rowdelta <= 1; rowdelta++)
         for(coldelta = -1; coldelta <= 1; coldelta++)
         {
           if(row + rowdelta < 0 || row + rowdelta >= SIZE ||
              col + coldelta < 0 || col + coldelta >= SIZE ||
                                       (rowdelta==0 && coldelta==0))
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
                 moves[row][col] = 1;
                 no_of_moves++;
                 break;
               }
             }
           }
         }
     }
   return no_of_moves;
}
