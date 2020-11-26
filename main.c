#include <stdio.h>
#include <ctype.h>
#define SIZE 6

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//함수 선언 
extern void display(char board[][SIZE]);
extern int valid_moves(char board[][SIZE], int moves[][SIZE], char player);
extern void make_move(char board[][SIZE], int row, int col, char player);
extern int get_score(char board[][SIZE], char player);

int main()
{
  char board [SIZE][SIZE] = { 0 };
  int moves[SIZE][SIZE] = { 0 };
  int row = 0;
  int col = 0;
  int no_of_games = 0;
  int no_of_moves = 0;
  int invalid_moves = 0;
  int comp_score = 0;
  int user_score = 0;
  char y = 0;
  int x = 0;
  char again = 0;
  int player = 0;

  printf("   Player1 - (O)\n   Player2  - (X).\n");
  printf("\n 엔터를 누르면 게임을 시작합니다.\n"); //게임 시작 화면 
  scanf("%c", &again);

   do
   {
     player = ++no_of_games % 2;
     no_of_moves = 4;

  
     for(row = 0; row < SIZE; row++)
       for(col = 0; col < SIZE; col++)
         board[row][col] = ' ';

     board[SIZE/2 - 1][SIZE/2 - 1] = board[SIZE/2][SIZE/2] = 'O';
     board[SIZE/2 - 1][SIZE/2] = board[SIZE/2][SIZE/2 - 1] = 'X';

     do
     {
       display(board);
       if(player++ % 2)
       {
         if(valid_moves(board, moves, 'O'))
         {
           for(;;)
           {
             fflush(stdin);
             printf("Player 1 행열을 입력하여 움직여주세요. : ");
             scanf("%d%c", &x, &y); //player1의 행렬 받기  
             y = tolower(y) - 'a';
             x--;
             if( x>=0 && y>=0 && x<SIZE && y<SIZE && moves[x][y])
             {
               make_move(board, x, y, 'O');
               no_of_moves++;
               break;
             }
             else
               printf("움직일 수 없습니다. 다시 시도하세요.\n"); //행렬 다시 적어야 할 경우 
           }
         }
         else
           if(++invalid_moves<2)
           {
             fflush(stdin);
             printf("\n당신이 둘 곳이 없습니다.");
             scanf("%c", &again);
           }
           else
             printf("\n둘다 움직일 수 없습니다. 게임을 종료합니다.\n"); //둘다 움직일 수 없을 경 우  
       }
       else
       {
           if(valid_moves(board, moves, 'X'))
           {
             for(;;)
             {
               fflush(stdin);
               printf("Player 2 행열을 입력하여 움직여주세요. : ");
               scanf("%d%c", &x, &y); //player2의 행렬 받기  
               y = tolower(y) - 'a';
               x--;
               if( x>=0 && y>=0 && x<SIZE && y<SIZE && moves[x][y])
               {
                 make_move(board, x, y, 'X');
                 no_of_moves++;
                 break;
               }
               else
                 printf("움직일 수 없습니다. 다시 시도하세요.\n"); //행렬 다시 적어야 할 경우
             }
           }
           else
             if(++invalid_moves<2)
             {
               fflush(stdin);
               printf("\n당신이 둘 곳이 없습니다.");
               scanf("%c", &again);
             }
             else
               printf("\n둘다 움직일 수 없습니다. 게임을 종료합니다.\n"); //둘다 움직일 수 없을 경 우
         }
     }while(no_of_moves < SIZE*SIZE && invalid_moves<2);

     display(board);

     comp_score = user_score = 0;
     for(row = 0; row < SIZE; row++)
       for(col = 0; col < SIZE; col++)
       {
         comp_score += board[row][col] == 'X';
         user_score += board[row][col] == 'O';
       }
     printf("The final score is:\n");
     printf("Player 2 %d\n    Plater 1 %d\n\n", comp_score, user_score);

     fflush(stdin);
     printf("Do you want to play again (y/n): ");
     scanf("%c", &again);
   }while(tolower(again) == 'y');

   printf("\nGoodbye\n");
}








