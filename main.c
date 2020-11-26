#include <stdio.h>
#include <ctype.h>
#define SIZE 6

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//�Լ� ���� 
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
  printf("\n ���͸� ������ ������ �����մϴ�.\n"); //���� ���� ȭ�� 
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
             printf("Player 1 �࿭�� �Է��Ͽ� �������ּ���. : ");
             scanf("%d%c", &x, &y); //player1�� ��� �ޱ�  
             y = tolower(y) - 'a';
             x--;
             if( x>=0 && y>=0 && x<SIZE && y<SIZE && moves[x][y])
             {
               make_move(board, x, y, 'O');
               no_of_moves++;
               break;
             }
             else
               printf("������ �� �����ϴ�. �ٽ� �õ��ϼ���.\n"); //��� �ٽ� ����� �� ��� 
           }
         }
         else
           if(++invalid_moves<2)
           {
             fflush(stdin);
             printf("\n����� �� ���� �����ϴ�.");
             scanf("%c", &again);
           }
           else
             printf("\n�Ѵ� ������ �� �����ϴ�. ������ �����մϴ�.\n"); //�Ѵ� ������ �� ���� �� ��  
       }
       else
       {
           if(valid_moves(board, moves, 'X'))
           {
             for(;;)
             {
               fflush(stdin);
               printf("Player 2 �࿭�� �Է��Ͽ� �������ּ���. : ");
               scanf("%d%c", &x, &y); //player2�� ��� �ޱ�  
               y = tolower(y) - 'a';
               x--;
               if( x>=0 && y>=0 && x<SIZE && y<SIZE && moves[x][y])
               {
                 make_move(board, x, y, 'X');
                 no_of_moves++;
                 break;
               }
               else
                 printf("������ �� �����ϴ�. �ٽ� �õ��ϼ���.\n"); //��� �ٽ� ����� �� ���
             }
           }
           else
             if(++invalid_moves<2)
             {
               fflush(stdin);
               printf("\n����� �� ���� �����ϴ�.");
               scanf("%c", &again);
             }
             else
               printf("\n�Ѵ� ������ �� �����ϴ�. ������ �����մϴ�.\n"); //�Ѵ� ������ �� ���� �� ��
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








