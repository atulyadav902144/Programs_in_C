#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int choice, player;
int out;
int checkForWin();
void displayBoard();
void markBoard(char mark);

int main()
{
    int gameStatus;
    char mark;
    char player1[10];
    char player2[10];
 
    printf("\n Enter the 1st player Name:\n");
    scanf("%s",player1);

    printf("\n Enter the 2nd player Name:\n");
    scanf("%s",player2);

    player = 1;

   do
    {
      displayBoard();

      player = (player % 2) ? 1 : 2;

      printf("Player %d, Enter a Number: ", player);
      scanf("%d", &choice);

      mark = (player == 1) ? 'X' : 'O';

      markBoard(mark);

      gameStatus = checkForWin();

      player++;

    }while (gameStatus == -1);

    if (gameStatus == 1)
    {
        if(--player==1)
        {
	printf("\nCongratulations    ");
                 printf("\n  %s Win the Game \n\n",strupr(player1));
        }
        else
        {
	printf("\nCongratulations    ");
                 printf("\n %s Win the Game  \n\n",strupr(player2));
        }
        check();
    }
    else
    {
        printf("  Game Graw \n\n");
        check();
    }
    return 0;
}

int check()
{
     printf("Do uh Want to Play Again? Yes(1)/No(0)\n");
     scanf("%d",&out);
        if(out==1)
        {
          reset();
          main();
        }
        else
        {
            exit(0);
        }
}

int reset()
{

    square[0]='0';
    square[1]='1';
    square[2]='2';
    square[3]='3';
    square[4]='4';
    square[5]='5';
    square[6]='6';
    square[7]='7';
    square[8]='8';
    square[9]='9';

}
int checkForWin()
{
    int returnValue = 0;

    if (square[1] == square[2] && square[2] == square[3])
    {
        returnValue = 1;
    }
    else if (square[4] == square[5] && square[5] == square[6])
        returnValue = 1;

    else if (square[7] == square[8] && square[8] == square[9])
        returnValue = 1;

    else if (square[1] == square[4] && square[4] == square[7])
        returnValue = 1;

    else if (square[2] == square[5] && square[5] == square[8])
        returnValue = 1;

    else if (square[3] == square[6] && square[6] == square[9])
        returnValue = 1;

    else if (square[1] == square[5] && square[5] == square[9])
        returnValue = 1;

    else if (square[3] == square[5] && square[5] == square[7])
        returnValue = 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')
        returnValue = 0;
    else
        returnValue = -1;

    return returnValue;
}

void displayBoard()
{
    system("cls");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("      |      |     \n");
    printf("  %c   |  %c   |  %c \n", square[1], square[2], square[3]);

    printf("______|______|_____\n");
    printf("      |      |     \n");

    printf("  %c   |  %c   |  %c \n", square[4], square[5], square[6]);

    printf("______|______|_____\n");
    printf("      |      |     \n");

    printf("  %c   |  %c   |  %c \n", square[7], square[8], square[9]);

    printf("      |      |     \n\n");
}

void markBoard(char mark)
{
    if (choice == 1 && square[1] == '1')
        square[1] = mark;

    else if (choice == 2 && square[2] == '2')
        square[2] = mark;

    else if (choice == 3 && square[3] == '3')
        square[3] = mark;

    else if (choice == 4 && square[4] == '4')
        square[4] = mark;

    else if (choice == 5 && square[5] == '5')
        square[5] = mark;

    else if (choice == 6 && square[6] == '6')
        square[6] = mark;

    else if (choice == 7 && square[7] == '7')
        square[7] = mark;

    else if (choice == 8 && square[8] == '8')
        square[8] = mark;

    else if (choice == 9 && square[9] == '9')
        square[9] = mark;
    else
    {
        printf("Wrong Place selected ");
        player--;
    }
}

