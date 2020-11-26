#include <stdio.h>
#include <ctype.h>
#define SIZE 6

int get_score(char board[][SIZE], char player)
{
   int score = 0;
   int row = 0;
   int col = 0;
   char opponent = player == 'O' ? 'X' : 'O';

   for(row = 0; row < SIZE; row++)
     for(col = 0; col < SIZE; col++)
   {
     score -= board[row][col] == opponent;
     score += board[row][col] == player;
   }
   return score;
}
