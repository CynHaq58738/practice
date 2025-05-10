#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/****************************************************************************************************
 * This program creates a simple tic toe game.
 * 
 * @name Cynthia Haque
 * @date 8-31-2024
 * @version 2024 
 *************************************************************************************************** */
//global variables
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

//prototypes
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);


int main()
{
    char winner = ' ';
    char response;
    
    do
    {
        //reset winner & response
        winner = ' ';
        response = ' ';

        resetBoard();
        while (winner = ' ' && checkFreeSpaces() != 0)
        {
            printBoard();

            playerMove();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }

            computerMove();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }
        } 
    
        printBoard();
        printWinner(winner);

        printf("Do you want to play again? (y/n): \n");
        scanf("%*c");
        scanf("%c", &response);
    } while (response == 'y');
    
    printf("Thanks for playing!\n");

    return 0;
}

void resetBoard()
{
    int i,j;
    for(i=0; i<3; i++)
    {
        for(j = 0; j<3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}   

int checkFreeSpaces()
{
    int freeSpaces = 9;
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
              freeSpaces--;
            }
        }
        
    }
    return freeSpaces;
}

void playerMove()
{
    int x;
    int y;

    do
    {
        printf("Enter row number (1-3): ");
        scanf("%d", &x);
        x--;

        printf("Enter column number (1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' ')
        {
            printf("Invalid move!\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
}

void computerMove()
{
    //seed the current time
    srand(time(0));
    int x;
    int y;

    if(checkFreeSpaces()> 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ' );
        board[x][y] = COMPUTER;
    }
    else
    {
        //draw
        printWinner(' ');
    }
}

char checkWinner()
{
    int i;
    //check rows
    for ( i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    //check columns
    for ( i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    //check diagnals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }
    //no winner
    return ' ';
}

void printWinner(char winner)
{
    if(winner == PLAYER)
    {
        printf("YOU WIN!\n");
    }
    else if(winner == COMPUTER)
    {
        printf("YOU LOSE!\n");
    }
    else
    {
        printf("ITS A TIE!\n");
    }
}