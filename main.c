//  Index Number - AS2016461
//  NAME - Sivantha Madusha Paranavithana
//  Course - CSC 107 2.0 Introduction to the Computer Programming
//  Faculty - Faculty of Applied Sciences
//  University - University of Sri Jayewardenepura

#include <stdio.h>
#include <stdlib.h>

//function to print the board
void printBoard(char board[10], char ans2);

//function to read the players' move
void readMove(char board[10], char ans2, int arrPreResponsePly[5], int arrPreResponseCom[5], int countP);

//function to calculate the computers' move
void calculateMove(char board[10], char ans2, int arrPreResponseCom[5], int arrPreResponsePly[5], int countC, int countP);

//function to decide whether the game is ended or not
void checkStatus(char board[10], char ans2, int *end, int *count, int *winner);

//function to print results
void printResults(char board[10], char ans2, int winner);

int main(void)
{
    char ans3;
    do
    {

        // string for the board
        char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

        //Clear The screen
        system("cls");

        //ADDING COLORS TO BACKGROUND AND FOREGROUND
        system("COLOR F4");

        //The variable to identify whether the game is ended or not
        int end = 0;

        //array for record the moves done by the player
        int arrPreResponsePly[5] = {0, 0, 0, 0, 0};

        //array for record the moves done by the computer
        int arrPreResponseCom[5] = {0, 0, 0, 0, 0};

        //The variable to identify the winner
        int winner = 0;

        //The variable to count the moves done by the player
        int countP = 0;

        //The variable to count the moves done by the computer
        int countC = 0;

        //The variables to store the responses by the user
        char ans1, ans2;

        printf("\n\t\t\t================================================\n");
        printf("\t\t\t_____ ___  __   _____      __   _____  __   ___\n");
        printf("\t\t\t  |    |  |       |   /\\  |       |   |  | |___\n");
        printf("\t\t\t  |   _|_ |__     |  /--\\ |__     |   |__| |___\n");
        printf("\n\t\t\t================================================\n\n");

        // Asking the player whether he want to play first or not
        int error1 = 0;
        do
        {
            if (error1 == 1)
            {
                printf("Invalid response! Please enter again!\n");
            }
            printf("Do you want to play first[Y/N]?");
            scanf(" %c", &ans1);
            error1 = 1;
        } while (!(ans1 == 'Y' || ans1 == 'y' || ans1 == 'N' || ans1 == 'n'));

        // Asking the player to choose a mark
        int error2 = 0;
        do
        {
            if (error2 == 1)
            {
                printf("Invalid response! Please enter again!\n");
            }
            printf("Choose your mark[X/O]");
            scanf(" %c", &ans2);
            error2 = 1;
        } while (!(ans2 == 'X' || ans2 == 'x' || ans2 == 'O' || ans2 == 'o'));

        //If the player want to play first
        if (ans1 == 'Y' || ans1 == 'y')
        {
            while (end == 0)
            {
                readMove(board, ans2, arrPreResponsePly, arrPreResponseCom, countP);
                checkStatus(board, ans2, &end, &countP, &winner);
                if (end == 1)
                {
                    break;
                }
                calculateMove(board, ans2, arrPreResponseCom, arrPreResponsePly, countC, countP);
                checkStatus(board, ans2, &end, &countC, &winner);
            }
        }

        //If the player does not want to plat first
        else
        {
            while (end == 0)
            {
                calculateMove(board, ans2, arrPreResponseCom, arrPreResponsePly, countC, countP);
                checkStatus(board, ans2, &end, &countC, &winner);
                if (end == 1)
                {
                    break;
                }
                readMove(board, ans2, arrPreResponsePly, arrPreResponseCom, countP);
                checkStatus(board, ans2, &end, &countP, &winner);
            }
        }
        printResults(board, ans2, winner);

        int error4 = 0;
        do
        {
            if (error4 == 1)
            {
                printf("Invalid response! Please enter again!\n");
            }
            printf("Do you want to play again[Y/N]?");
            scanf(" %c", &ans3);
            error4 = 1;
        } while (!(ans3 == 'Y' || ans3 == 'y' || ans3 == 'N' || ans3 == 'n'));
    } while (ans3 == 'Y' || ans3 == 'y');

    return 0;
}

void readMove(char board[10], char ans2, int arrPreResponsePly[5], int arrPreResponseCom[5], int countP)
{
    int numEntered = 0;
    printBoard(board, ans2);
    int error3 = 0;
    do
    {
        if (error3 == 1)
        {
            printf("Invald Response! Enter again!\n");
        }
        printf("Enter a number..");
        scanf("%d", &numEntered);
        if ((numEntered == 1 || numEntered == 2 || numEntered == 3 || numEntered == 4 || numEntered == 5 || numEntered == 6 || numEntered == 7 || numEntered == 8 || numEntered == 9) && !((numEntered == arrPreResponsePly[0]) || (numEntered == arrPreResponsePly[1]) || (numEntered == arrPreResponsePly[2]) || (numEntered == arrPreResponsePly[3]) || (numEntered == arrPreResponsePly[4])) && !((numEntered == arrPreResponseCom[0]) || (numEntered == arrPreResponseCom[1]) || (numEntered == arrPreResponseCom[2]) || (numEntered == arrPreResponseCom[3]) || (numEntered == arrPreResponseCom[4])))
        {
            error3 = 0;
            arrPreResponsePly[countP] = numEntered;
        }
        else
        {
            error3 = 1;
        }
    } while (error3 == 1);

    //If player chose the 'X' mark
    if (ans2 == 'X' || ans2 == 'x')
    {
        switch (numEntered)
        {
        case 1:
            board[1] = 'X';
            break;
        case 2:
            board[2] = 'X';
            break;
        case 3:
            board[3] = 'X';
            break;
        case 4:
            board[4] = 'X';
            break;
        case 5:
            board[5] = 'X';
            break;
        case 6:
            board[6] = 'X';
            break;
        case 7:
            board[7] = 'X';
            break;
        case 8:
            board[8] = 'X';
            break;
        case 9:
            board[9] = 'X';
            break;
        }
    }
    //If player chose the 'O' mark
    else
    {
        switch (numEntered)
        {
        case 1:
            board[1] = 'O';
            break;
        case 2:
            board[2] = 'O';
            break;
        case 3:
            board[3] = 'O';
            break;
        case 4:
            board[4] = 'O';
            break;
        case 5:
            board[5] = 'O';
            break;
        case 6:
            board[6] = 'O';
            break;
        case 7:
            board[7] = 'O';
            break;
        case 8:
            board[8] = 'O';
            break;
        case 9:
            board[9] = 'O';
            break;
        }
    }
}

void calculateMove(char board[10], char ans2, int arrPreResponseCom[5], int arrPreResponsePly[5], int countC, int countP)
{
    //Array to record the values of the rows
    int arrRow[4] = {0, 0, 0, 0};

    //Array to record the values of the columns
    int arrCol[4] = {0, 0, 0, 0};

    //Array to record the values for the diagonals
    int arrDia[3] = {0, 0, 0};

    //Array to record the values for the positions in the board
    int arrPos[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    //If player chose the 'X' mark
    if (ans2 == 'X' || ans2 == 'x')
    {
        //assign values to rows
        if (((board[1] == 'X') && (board[2] == 'X') && (board[3] == 'O')) || ((board[1] == 'X') && (board[2] == 'O') && (board[3] == 'X')) || ((board[1] == 'O') && (board[2] == 'X') && (board[3] == 'X')) || ((board[1] == 'X') && (board[2] == 'O') && (board[3] == '3')) || ((board[1] == '1') && (board[2] == 'X') && (board[3] == 'O')) || ((board[1] == 'X') && (board[2] == '2') && (board[3] == 'O')) || ((board[1] == 'O') && (board[2] == 'X') && (board[3] == '3')) || ((board[1] == '1') && (board[2] == 'O') && (board[3] == 'X')) || ((board[1] == 'O') && (board[2] == '2') && (board[3] == 'X')) || ((board[1] == 'O') && (board[2] == 'O') && (board[3] == 'X')) || ((board[1] == 'O') && (board[2] == 'X') && (board[3] == 'O')) || ((board[1] == 'X') && (board[2] == 'O') && (board[3] == 'O')))
            arrRow[1] = 0;
        else
        {
            if ((board[1] == '1') && (board[2] == '2') && (board[3] == '3'))
                arrRow[1] = 1;
            else if (((board[1] == 'X') && (board[2] == '2') && (board[3] == '3')) || ((board[1] == '1') && (board[2] == 'X') && (board[3] == '3')) || ((board[1] == '1') && (board[2] == '2') && (board[3] == 'X')))
                arrRow[1] = 9;
            else if (((board[1] == 'O') && (board[2] == '2') && (board[3] == '3')) || ((board[1] == '1') && (board[2] == 'O') && (board[3] == '3')) || ((board[1] == '1') && (board[2] == '2') && (board[3] == 'O')))
                arrRow[1] = 10;
            else if (((board[1] == 'X') && (board[2] == 'X') && (board[3] == '3')) || ((board[1] == 'X') && (board[2] == '2') && (board[3] == 'X')) || ((board[1] == '1') && (board[2] == 'X') && (board[3] == 'X')))
                arrRow[1] = 100;
            else if (((board[1] == 'O') && (board[2] == 'O') && (board[3] == '3')) || ((board[1] == 'O') && (board[2] == '2') && (board[3] == 'O')) || ((board[1] == '1') && (board[2] == 'O') && (board[3] == 'O')))
                arrRow[1] = 1000;
        }

        if (((board[4] == 'X') && (board[5] == 'X') && (board[6] == 'O')) || ((board[4] == 'X') && (board[5] == 'O') && (board[6] == 'X')) || ((board[4] == 'O') && (board[5] == 'X') && (board[6] == 'X')) || ((board[4] == 'X') && (board[5] == 'O') && (board[6] == '6')) || ((board[4] == '4') && (board[5] == 'X') && (board[6] == 'O')) || ((board[4] == 'X') && (board[5] == '5') && (board[6] == 'O')) || ((board[4] == 'O') && (board[5] == 'X') && (board[6] == '6')) || ((board[4] == '4') && (board[5] == 'O') && (board[6] == 'X')) || ((board[4] == 'O') && (board[5] == '5') && (board[6] == 'X')) || ((board[4] == 'O') && (board[5] == 'O') && (board[6] == 'X')) || ((board[4] == 'O') && (board[5] == 'X') && (board[6] == 'O')) || ((board[4] == 'X') && (board[5] == 'O') && (board[6] == 'O')))
            arrRow[2] = 0;
        else
        {
            if ((board[4] == '4') && (board[5] == '5') && (board[6] == '6'))
                arrRow[2] = 1;
            else if (((board[4] == 'X') && (board[5] == '5') && (board[6] == '6')) || ((board[4] == '4') && (board[5] == 'X') && (board[6] == '6')) || ((board[4] == '4') && (board[5] == '5') && (board[6] == 'X')))
                arrRow[2] = 9;
            else if (((board[4] == 'O') && (board[5] == '5') && (board[6] == '6')) || ((board[4] == '4') && (board[5] == 'O') && (board[6] == '6')) || ((board[4] == '4') && (board[5] == '5') && (board[6] == 'O')))
                arrRow[2] = 10;
            else if (((board[4] == 'X') && (board[5] == 'X') && (board[6] == '6')) || ((board[4] == 'X') && (board[5] == '5') && (board[6] == 'X')) || ((board[4] == '4') && (board[5] == 'X') && (board[6] == 'X')))
                arrRow[2] = 100;
            else if (((board[4] == 'O') && (board[5] == 'O') && (board[6] == '6')) || ((board[4] == 'O') && (board[5] == '5') && (board[6] == 'O')) || ((board[4] == '4') && (board[5] == 'O') && (board[6] == 'O')))
                arrRow[2] = 1000;
        }

        if (((board[7] == 'X') && (board[8] == 'X') && (board[9] == 'O')) || ((board[7] == 'X') && (board[8] == 'O') && (board[9] == 'X')) || ((board[7] == 'O') && (board[8] == 'X') && (board[9] == 'X')) || ((board[7] == 'X') && (board[8] == 'O') && (board[9] == '9')) || ((board[7] == '7') && (board[8] == 'X') && (board[9] == 'O')) || ((board[7] == 'X') && (board[8] == '8') && (board[9] == 'O')) || ((board[7] == 'O') && (board[8] == 'X') && (board[9] == '9')) || ((board[7] == '7') && (board[8] == 'O') && (board[9] == 'X')) || ((board[7] == 'O') && (board[8] == '8') && (board[9] == 'X')) || ((board[7] == 'O') && (board[8] == 'O') && (board[9] == 'X')) || ((board[7] == 'O') && (board[8] == 'X') && (board[9] == 'O')) || ((board[7] == 'X') && (board[8] == 'O') && (board[9] == 'O')))
            arrRow[3] = 0;
        else
        {
            if ((board[7] == '7') && (board[8] == '8') && (board[9] == '9'))
                arrRow[3] = 1;
            else if (((board[7] == 'X') && (board[8] == '8') && (board[9] == '9')) || ((board[7] == '7') && (board[8] == 'X') && (board[9] == '9')) || ((board[7] == '7') && (board[8] == '8') && (board[9] == 'X')))
                arrRow[3] = 9;
            else if (((board[7] == 'O') && (board[8] == '8') && (board[9] == '9')) || ((board[7] == '7') && (board[8] == 'O') && (board[9] == '9')) || ((board[7] == '7') && (board[8] == '8') && (board[9] == 'O')))
                arrRow[3] = 10;
            else if (((board[7] == 'X') && (board[8] == 'X') && (board[9] == '9')) || ((board[7] == 'X') && (board[8] == '8') && (board[9] == 'X')) || ((board[7] == '7') && (board[8] == 'X') && (board[9] == 'X')))
                arrRow[3] = 100;
            else if (((board[7] == 'O') && (board[8] == 'O') && (board[9] == '9')) || ((board[7] == 'O') && (board[8] == '8') && (board[9] == 'O')) || ((board[7] == '7') && (board[8] == 'O') && (board[9] == 'O')))
                arrRow[3] = 1000;
        }

        //assign values to columns
        if ((board[1] == 'X' && board[4] == 'X' && board[7] == 'O') || (board[1] == 'X' && board[4] == 'O' && board[7] == 'X') || (board[1] == 'O' && board[4] == 'X' && board[7] == 'X') || (board[1] == 'X' && board[4] == 'O' && board[7] == '7') || (board[1] == '1' && board[4] == 'X' && board[7] == 'O') || (board[1] == 'X' && board[4] == '4' && board[7] == 'O') || (board[1] == 'O' && board[4] == 'X' && board[7] == '7') || (board[1] == '1' && board[4] == 'O' && board[7] == 'X') || (board[1] == 'O' && board[4] == '4' && board[7] == 'X') || (board[1] == 'O' && board[4] == 'O' && board[7] == 'X') || (board[1] == 'O' && board[4] == 'X' && board[7] == 'O') || (board[1] == 'X' && board[4] == 'O' && board[7] == 'O'))
            arrCol[1] = 0;
        else if (board[1] == '1' && board[4] == '4' && board[7] == '7')
            arrCol[1] = 1;
        else if ((board[1] == 'X' && board[4] == '4' && board[7] == '7') || (board[1] == '1' && board[4] == 'X' && board[7] == '7') || (board[1] == '1' && board[4] == '4' && board[7] == 'X'))
            arrCol[1] = 9;
        else if ((board[1] == 'O' && board[4] == '4' && board[7] == '7') || (board[1] == '1' && board[4] == 'O' && board[7] == '7') || (board[1] == '1' && board[4] == '4' && board[7] == 'O'))
            arrCol[1] = 10;
        else if ((board[1] == 'X' && board[4] == 'X' && board[7] == '7') || (board[1] == 'X' && board[4] == '4' && board[7] == 'X') || (board[1] == '1' && board[4] == 'X' && board[7] == 'X'))
            arrCol[1] = 100;
        else if ((board[1] == 'O' && board[4] == 'O' && board[7] == '7') || (board[1] == 'O' && board[4] == '4' && board[7] == 'O') || (board[1] == '1' && board[4] == 'O' && board[7] == 'O'))
            arrCol[1] = 1000;

        if ((board[2] == 'X' && board[5] == 'X' && board[8] == 'O') || (board[2] == 'X' && board[5] == 'O' && board[8] == 'X') || (board[2] == 'O' && board[5] == 'X' && board[8] == 'X') || (board[2] == 'X' && board[5] == 'O' && board[8] == '8') || (board[2] == '2' && board[5] == 'X' && board[8] == 'O') || (board[2] == 'X' && board[5] == '5' && board[8] == 'O') || (board[2] == 'O' && board[5] == 'X' && board[8] == '8') || (board[2] == '2' && board[5] == 'O' && board[8] == 'X') || (board[2] == 'O' && board[5] == '5' && board[8] == 'X') || (board[2] == 'O' && board[5] == 'O' && board[8] == 'X') || (board[2] == 'O' && board[5] == 'X' && board[8] == 'O') || (board[2] == 'X' && board[5] == 'O' && board[8] == 'O'))
            arrCol[2] = 0;
        else if (board[2] == '2' && board[5] == '5' && board[8] == '8')
            arrCol[2] = 1;
        else if ((board[2] == 'X' && board[5] == '5' && board[8] == '8') || (board[2] == '2' && board[5] == 'X' && board[8] == '8') || (board[2] == '2' && board[5] == '5' && board[8] == 'X'))
            arrCol[2] = 9;
        else if ((board[2] == 'O' && board[5] == '5' && board[8] == '8') || (board[2] == '2' && board[5] == 'O' && board[8] == '8') || (board[2] == '2' && board[5] == '5' && board[8] == 'O'))
            arrCol[2] = 10;
        else if ((board[2] == 'X' && board[5] == 'X' && board[8] == '8') || (board[2] == 'X' && board[5] == '5' && board[8] == 'X') || (board[2] == '2' && board[5] == 'X' && board[8] == 'X'))
            arrCol[2] = 100;
        else if ((board[2] == 'O' && board[5] == 'O' && board[8] == '8') || (board[2] == 'O' && board[5] == '5' && board[8] == 'O') || (board[2] == '2' && board[5] == 'O' && board[8] == 'O'))
            arrCol[2] = 1000;

        if ((board[3] == 'X' && board[6] == 'X' && board[9] == 'O') || (board[3] == 'X' && board[6] == 'O' && board[9] == 'X') || (board[3] == 'O' && board[6] == 'X' && board[9] == 'X') || (board[3] == 'X' && board[6] == 'O' && board[9] == '9') || (board[3] == '3' && board[6] == 'X' && board[9] == 'O') || (board[3] == 'X' && board[6] == '6' && board[9] == 'O') || (board[3] == 'O' && board[6] == 'X' && board[9] == '9') || (board[3] == '3' && board[6] == 'O' && board[9] == 'X') || (board[3] == 'O' && board[6] == '6' && board[9] == 'X') || (board[3] == 'O' && board[6] == 'O' && board[9] == 'X') || (board[3] == 'O' && board[6] == 'X' && board[9] == 'O') || (board[3] == 'X' && board[6] == 'O' && board[9] == 'O'))
            arrCol[3] = 0;
        else if (board[3] == '3' && board[6] == '6' && board[9] == '9')
            arrCol[3] = 1;
        else if ((board[3] == 'X' && board[6] == '6' && board[9] == '9') || (board[3] == '3' && board[6] == 'X' && board[9] == '9') || (board[3] == '3' && board[6] == '6' && board[9] == 'X'))
            arrCol[3] = 9;
        else if ((board[3] == 'O' && board[6] == '6' && board[9] == '9') || (board[3] == '3' && board[6] == 'O' && board[9] == '9') || (board[3] == '3' && board[6] == '6' && board[9] == 'O'))
            arrCol[3] = 10;
        else if ((board[3] == 'X' && board[6] == 'X' && board[9] == '9') || (board[3] == 'X' && board[6] == '6' && board[9] == 'X') || (board[3] == '3' && board[6] == 'X' && board[9] == 'X'))
            arrCol[3] = 100;
        else if ((board[3] == 'O' && board[6] == 'O' && board[9] == '9') || (board[3] == 'O' && board[6] == '6' && board[9] == 'O') || (board[3] == '3' && board[6] == 'O' && board[9] == 'O'))
            arrCol[3] = 1000;

        //assign values to diagonals
        if ((board[1] == 'X' && board[5] == 'X' && board[9] == 'O') || (board[1] == 'X' && board[5] == 'O' && board[9] == 'X') || (board[1] == 'O' && board[5] == 'X' && board[9] == 'X') || (board[1] == 'X' && board[5] == 'O' && board[9] == '9') || (board[1] == '1' && board[5] == 'X' && board[9] == 'O') || (board[1] == 'X' && board[5] == '5' && board[9] == 'O') || (board[1] == 'O' && board[5] == 'X' && board[9] == '9') || (board[1] == '1' && board[5] == 'O' && board[9] == 'X') || (board[1] == 'O' && board[5] == '5' && board[9] == 'X') || (board[1] == 'O' && board[5] == 'O' && board[9] == 'X') || (board[1] == 'O' && board[5] == 'X' && board[9] == 'O') || (board[1] == 'X' && board[5] == 'O' && board[9] == 'O'))
            arrDia[1] = 0;
        else if (board[1] == '1' && board[5] == '5' && board[9] == '9')
            arrDia[1] = 1;
        else if ((board[1] == 'X' && board[5] == '5' && board[9] == '9') || (board[1] == '1' && board[5] == 'X' && board[9] == '9') || (board[1] == '1' && board[5] == '5' && board[9] == 'X'))
            arrDia[1] = 9;
        else if ((board[1] == 'O' && board[5] == '5' && board[9] == '9') || (board[1] == '1' && board[5] == 'O' && board[9] == '9') || (board[1] == '1' && board[5] == '5' && board[9] == 'O'))
            arrDia[1] = 10;
        else if ((board[1] == 'X' && board[5] == 'X' && board[9] == '9') || (board[1] == 'X' && board[5] == '5' && board[9] == 'X') || (board[1] == '1' && board[5] == 'X' && board[9] == 'X'))
            arrDia[1] = 100;
        else if ((board[1] == 'O' && board[5] == 'O' && board[9] == '9') || (board[1] == 'O' && board[5] == '5' && board[9] == 'O') || (board[1] == '1' && board[5] == 'O' && board[9] == 'O'))
            arrDia[1] = 1000;

        if ((board[3] == 'X' && board[5] == 'X' && board[7] == 'O') || (board[3] == 'X' && board[5] == 'O' && board[7] == 'X') || (board[3] == 'O' && board[5] == 'X' && board[7] == 'X') || (board[3] == 'X' && board[5] == 'O' && board[7] == '7') || (board[3] == '3' && board[5] == 'X' && board[7] == 'O') || (board[3] == 'X' && board[5] == '5' && board[7] == 'O') || (board[3] == 'O' && board[5] == 'X' && board[7] == '7') || (board[3] == '3' && board[5] == 'O' && board[7] == 'X') || (board[3] == 'O' && board[5] == '5' && board[7] == 'X') || (board[3] == 'O' && board[5] == 'O' && board[7] == 'X') || (board[3] == 'O' && board[5] == 'X' && board[7] == 'O') || (board[3] == 'X' && board[5] == 'O' && board[7] == 'O'))
            arrDia[2] = 0;
        else if (board[3] == '3' && board[5] == '5' && board[7] == '7')
            arrDia[2] = 1;
        else if ((board[3] == 'X' && board[5] == '5' && board[7] == '7') || (board[3] == '3' && board[5] == 'X' && board[7] == '7') || (board[3] == '3' && board[5] == '5' && board[7] == 'X'))
            arrDia[2] = 9;
        else if ((board[3] == 'O' && board[5] == '5' && board[7] == '7') || (board[3] == '3' && board[5] == 'O' && board[7] == '7') || (board[3] == '3' && board[5] == '5' && board[7] == 'O'))
            arrDia[2] = 10;
        else if ((board[3] == 'X' && board[5] == 'X' && board[7] == '7') || (board[3] == 'X' && board[5] == '5' && board[7] == 'X') || (board[3] == '3' && board[5] == 'X' && board[7] == 'X'))
            arrDia[2] = 100;
        else if ((board[3] == 'O' && board[5] == 'O' && board[7] == '7') || (board[3] == 'O' && board[5] == '5' && board[7] == 'O') || (board[3] == '3' && board[5] == 'O' && board[7] == 'O'))
            arrDia[2] = 1000;

        //assign values to positions
        arrPos[1] = arrRow[1] + arrCol[1] + arrDia[1];
        arrPos[2] = arrRow[1] + arrCol[2];
        arrPos[3] = arrRow[1] + arrCol[3] + arrDia[2];
        arrPos[4] = arrRow[2] + arrCol[1];
        arrPos[5] = arrRow[2] + arrCol[2] + arrDia[1] + arrDia[2];
        arrPos[6] = arrRow[2] + arrCol[3];
        arrPos[7] = arrRow[3] + arrCol[1] + arrDia[2];
        arrPos[8] = arrRow[3] + arrCol[2];
        arrPos[9] = arrRow[3] + arrCol[3] + arrDia[1];

        //WHEN No. of moves that computer played=0 || No. of moves that player played=0
        if (countC == 0 && countP == 0)
        {
            int arr[9] = {1, 8, 5, 2, 9, 4, 6, 3, 7};
            int randNum = (rand() % 9);
            int randPos = arr[randNum];
            board[randPos] = 'O';
            arrPreResponseCom[countC] = randPos;
        }

        //otherwise
        else
        {
            int i = 1;
            int maximum = 0;
            for (i = 1; i < 10; i++)
            {
                if (arrPos[i] > maximum)
                {
                    if (!((i == arrPreResponsePly[0]) || (i == arrPreResponsePly[1]) || (i == arrPreResponsePly[2]) || (i == arrPreResponsePly[3]) || (i == arrPreResponsePly[4])) && !((i == arrPreResponseCom[0]) || (i == arrPreResponseCom[1]) || (i == arrPreResponseCom[2]) || (i == arrPreResponseCom[3]) || (i == arrPreResponseCom[4])))
                        maximum = arrPos[i];
                }
            }
            printf("%d\n", maximum);
            int j = 1;
            int k = 0;
            int arrMax[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (j = 1; j < 10; j++)
            {
                if (arrPos[j] == maximum)
                {
                    arrMax[k] = j;
                    k = k + 1;
                }
            }
            if (k == 1)
            {
                int randPos = arrMax[0];
                board[randPos] = 'O';
                arrPreResponseCom[countC] = randPos;
            }
            else
            {
                int l = 0;
                for (l = 0; l < 100; l++)
                {
                    int randNum = rand() % k;
                    int randPos = arrMax[randNum];
                    if (!((randPos == arrPreResponsePly[0]) || (randPos == arrPreResponsePly[1]) || (randPos == arrPreResponsePly[2]) || (randPos == arrPreResponsePly[3]) || (randPos == arrPreResponsePly[4])) && !((randPos == arrPreResponseCom[0]) || (randPos == arrPreResponseCom[1]) || (randPos == arrPreResponseCom[2]) || (randPos == arrPreResponseCom[3]) || (randPos == arrPreResponseCom[4])))
                    {
                        board[randPos] = 'O';
                        arrPreResponseCom[countC] = randPos;
                        break;
                    }
                }
            }
        }
    }

    //If player chose the 'O' mark
    else
    {
        //assign values to rows
        if (((board[1] == 'X') && (board[2] == 'X') && (board[3] == 'O')) || ((board[1] == 'X') && (board[2] == 'O') && (board[3] == 'X')) || ((board[1] == 'O') && (board[2] == 'X') && (board[3] == 'X')) || ((board[1] == 'X') && (board[2] == 'O') && (board[3] == '3')) || ((board[1] == '1') && (board[2] == 'X') && (board[3] == 'O')) || ((board[1] == 'X') && (board[2] == '2') && (board[3] == 'O')) || ((board[1] == 'O') && (board[2] == 'X') && (board[3] == '3')) || ((board[1] == '1') && (board[2] == 'O') && (board[3] == 'X')) || ((board[1] == 'O') && (board[2] == '2') && (board[3] == 'X')) || ((board[1] == 'O') && (board[2] == 'O') && (board[3] == 'X')) || ((board[1] == 'O') && (board[2] == 'X') && (board[3] == 'O')) || ((board[1] == 'X') && (board[2] == 'O') && (board[3] == 'O')))
            arrRow[1] = 0;
        else
        {
            if ((board[1] == '1') && (board[2] == '2') && (board[3] == '3'))
                arrRow[1] = 1;
            else if (((board[1] == 'X') && (board[2] == '2') && (board[3] == '3')) || ((board[1] == '1') && (board[2] == 'X') && (board[3] == '3')) || ((board[1] == '1') && (board[2] == '2') && (board[3] == 'X')))
                arrRow[1] = 10;
            else if (((board[1] == 'O') && (board[2] == '2') && (board[3] == '3')) || ((board[1] == '1') && (board[2] == 'O') && (board[3] == '3')) || ((board[1] == '1') && (board[2] == '2') && (board[3] == 'O')))
                arrRow[1] = 9;
            else if (((board[1] == 'X') && (board[2] == 'X') && (board[3] == '3')) || ((board[1] == 'X') && (board[2] == '2') && (board[3] == 'X')) || ((board[1] == '1') && (board[2] == 'X') && (board[3] == 'X')))
                arrRow[1] = 1000;
            else if (((board[1] == 'O') && (board[2] == 'O') && (board[3] == '3')) || ((board[1] == 'O') && (board[2] == '2') && (board[3] == 'O')) || ((board[1] == '1') && (board[2] == 'O') && (board[3] == 'O')))
                arrRow[1] = 100;
        }

        if (((board[4] == 'X') && (board[5] == 'X') && (board[6] == 'O')) || ((board[4] == 'X') && (board[5] == 'O') && (board[6] == 'X')) || ((board[4] == 'O') && (board[5] == 'X') && (board[6] == 'X')) || ((board[4] == 'X') && (board[5] == 'O') && (board[6] == '6')) || ((board[4] == '4') && (board[5] == 'X') && (board[6] == 'O')) || ((board[4] == 'X') && (board[5] == '5') && (board[6] == 'O')) || ((board[4] == 'O') && (board[5] == 'X') && (board[6] == '6')) || ((board[4] == '4') && (board[5] == 'O') && (board[6] == 'X')) || ((board[4] == 'O') && (board[5] == '5') && (board[6] == 'X')) || ((board[4] == 'O') && (board[5] == 'O') && (board[6] == 'X')) || ((board[4] == 'O') && (board[5] == 'X') && (board[6] == 'O')) || ((board[4] == 'X') && (board[5] == 'O') && (board[6] == 'O')))
            arrRow[2] = 0;
        else
        {
            if ((board[4] == '4') && (board[5] == '5') && (board[6] == '6'))
                arrRow[2] = 1;
            else if (((board[4] == 'X') && (board[5] == '5') && (board[6] == '6')) || ((board[4] == '4') && (board[5] == 'X') && (board[6] == '6')) || ((board[4] == '4') && (board[5] == '5') && (board[6] == 'X')))
                arrRow[2] = 10;
            else if (((board[4] == 'O') && (board[5] == '5') && (board[6] == '6')) || ((board[4] == '4') && (board[5] == 'O') && (board[6] == '6')) || ((board[4] == '4') && (board[5] == '5') && (board[6] == 'O')))
                arrRow[2] = 9;
            else if (((board[4] == 'X') && (board[5] == 'X') && (board[6] == '6')) || ((board[4] == 'X') && (board[5] == '5') && (board[6] == 'X')) || ((board[4] == '4') && (board[5] == 'X') && (board[6] == 'X')))
                arrRow[2] = 1000;
            else if (((board[4] == 'O') && (board[5] == 'O') && (board[6] == '6')) || ((board[4] == 'O') && (board[5] == '5') && (board[6] == 'O')) || ((board[4] == '4') && (board[5] == 'O') && (board[6] == 'O')))
                arrRow[2] = 100;
        }

        if (((board[7] == 'X') && (board[8] == 'X') && (board[9] == 'O')) || ((board[7] == 'X') && (board[8] == 'O') && (board[9] == 'X')) || ((board[7] == 'O') && (board[8] == 'X') && (board[9] == 'X')) || ((board[7] == 'X') && (board[8] == 'O') && (board[9] == '9')) || ((board[7] == '7') && (board[8] == 'X') && (board[9] == 'O')) || ((board[7] == 'X') && (board[8] == '8') && (board[9] == 'O')) || ((board[7] == 'O') && (board[8] == 'X') && (board[9] == '9')) || ((board[7] == '7') && (board[8] == 'O') && (board[9] == 'X')) || ((board[7] == 'O') && (board[8] == '8') && (board[9] == 'X')) || ((board[7] == 'O') && (board[8] == 'O') && (board[9] == 'X')) || ((board[7] == 'O') && (board[8] == 'X') && (board[9] == 'O')) || ((board[7] == 'X') && (board[8] == 'O') && (board[9] == 'O')))
            arrRow[3] = 0;
        else
        {
            if ((board[7] == '7') && (board[8] == '8') && (board[9] == '9'))
                arrRow[3] = 1;
            else if (((board[7] == 'X') && (board[8] == '8') && (board[9] == '9')) || ((board[7] == '7') && (board[8] == 'X') && (board[9] == '9')) || ((board[7] == '7') && (board[8] == '8') && (board[9] == 'X')))
                arrRow[3] = 10;
            else if (((board[7] == 'O') && (board[8] == '8') && (board[9] == '9')) || ((board[7] == '7') && (board[8] == 'O') && (board[9] == '9')) || ((board[7] == '7') && (board[8] == '8') && (board[9] == 'O')))
                arrRow[3] = 9;
            else if (((board[7] == 'X') && (board[8] == 'X') && (board[9] == '9')) || ((board[7] == 'X') && (board[8] == '8') && (board[9] == 'X')) || ((board[7] == '7') && (board[8] == 'X') && (board[9] == 'X')))
                arrRow[3] = 1000;
            else if (((board[7] == 'O') && (board[8] == 'O') && (board[9] == '9')) || ((board[7] == 'O') && (board[8] == '8') && (board[9] == 'O')) || ((board[7] == '7') && (board[8] == 'O') && (board[9] == 'O')))
                arrRow[3] = 100;
        }

        //assign values to columns
        if ((board[1] == 'X' && board[4] == 'X' && board[7] == 'O') || (board[1] == 'X' && board[4] == 'O' && board[7] == 'X') || (board[1] == 'O' && board[4] == 'X' && board[7] == 'X') || (board[1] == 'X' && board[4] == 'O' && board[7] == '7') || (board[1] == '1' && board[4] == 'X' && board[7] == 'O') || (board[1] == 'X' && board[4] == '4' && board[7] == 'O') || (board[1] == 'O' && board[4] == 'X' && board[7] == '7') || (board[1] == '1' && board[4] == 'O' && board[7] == 'X') || (board[1] == 'O' && board[4] == '4' && board[7] == 'X') || (board[1] == 'O' && board[4] == 'O' && board[7] == 'X') || (board[1] == 'O' && board[4] == 'X' && board[7] == 'O') || (board[1] == 'X' && board[4] == 'O' && board[7] == 'O'))
            arrCol[1] = 0;
        else if (board[1] == '1' && board[4] == '4' && board[7] == '7')
            arrCol[1] = 1;
        else if ((board[1] == 'X' && board[4] == '4' && board[7] == '7') || (board[1] == '1' && board[4] == 'X' && board[7] == '7') || (board[1] == '1' && board[4] == '4' && board[7] == 'X'))
            arrCol[1] = 10;
        else if ((board[1] == 'O' && board[4] == '4' && board[7] == '7') || (board[1] == '1' && board[4] == 'O' && board[7] == '7') || (board[1] == '1' && board[4] == '4' && board[7] == 'O'))
            arrCol[1] = 9;
        else if ((board[1] == 'X' && board[4] == 'X' && board[7] == '7') || (board[1] == 'X' && board[4] == '4' && board[7] == 'X') || (board[1] == '1' && board[4] == 'X' && board[7] == 'X'))
            arrCol[1] = 1000;
        else if ((board[1] == 'O' && board[4] == 'O' && board[7] == '7') || (board[1] == 'O' && board[4] == '4' && board[7] == 'O') || (board[1] == '1' && board[4] == 'O' && board[7] == 'O'))
            arrCol[1] = 100;

        if ((board[2] == 'X' && board[5] == 'X' && board[8] == 'O') || (board[2] == 'X' && board[5] == 'O' && board[8] == 'X') || (board[2] == 'O' && board[5] == 'X' && board[8] == 'X') || (board[2] == 'X' && board[5] == 'O' && board[8] == '8') || (board[2] == '2' && board[5] == 'X' && board[8] == 'O') || (board[2] == 'X' && board[5] == '5' && board[8] == 'O') || (board[2] == 'O' && board[5] == 'X' && board[8] == '8') || (board[2] == '2' && board[5] == 'O' && board[8] == 'X') || (board[2] == 'O' && board[5] == '5' && board[8] == 'X') || (board[2] == 'O' && board[5] == 'O' && board[8] == 'X') || (board[2] == 'O' && board[5] == 'X' && board[8] == 'O') || (board[2] == 'X' && board[5] == 'O' && board[8] == 'O'))
            arrCol[2] = 0;
        else if (board[2] == '2' && board[5] == '5' && board[8] == '8')
            arrCol[2] = 1;
        else if ((board[2] == 'X' && board[5] == '5' && board[8] == '8') || (board[2] == '2' && board[5] == 'X' && board[8] == '8') || (board[2] == '2' && board[5] == '5' && board[8] == 'X'))
            arrCol[2] = 10;
        else if ((board[2] == 'O' && board[5] == '5' && board[8] == '8') || (board[2] == '2' && board[5] == 'O' && board[8] == '8') || (board[2] == '2' && board[5] == '5' && board[8] == 'O'))
            arrCol[2] = 9;
        else if ((board[2] == 'X' && board[5] == 'X' && board[8] == '8') || (board[2] == 'X' && board[5] == '5' && board[8] == 'X') || (board[2] == '2' && board[5] == 'X' && board[8] == 'X'))
            arrCol[2] = 1000;
        else if ((board[2] == 'O' && board[5] == 'O' && board[8] == '8') || (board[2] == 'O' && board[5] == '5' && board[8] == 'O') || (board[2] == '2' && board[5] == 'O' && board[8] == 'O'))
            arrCol[2] = 100;

        if ((board[3] == 'X' && board[6] == 'X' && board[9] == 'O') || (board[3] == 'X' && board[6] == 'O' && board[9] == 'X') || (board[3] == 'O' && board[6] == 'X' && board[9] == 'X') || (board[3] == 'X' && board[6] == 'O' && board[9] == '9') || (board[3] == '3' && board[6] == 'X' && board[9] == 'O') || (board[3] == 'X' && board[6] == '6' && board[9] == 'O') || (board[3] == 'O' && board[6] == 'X' && board[9] == '9') || (board[3] == '3' && board[6] == 'O' && board[9] == 'X') || (board[3] == 'O' && board[6] == '6' && board[9] == 'X') || (board[3] == 'O' && board[6] == 'O' && board[9] == 'X') || (board[3] == 'O' && board[6] == 'X' && board[9] == 'O') || (board[3] == 'X' && board[6] == 'O' && board[9] == 'O'))
            arrCol[3] = 0;
        else if (board[3] == '3' && board[6] == '6' && board[9] == '9')
            arrCol[3] = 1;
        else if ((board[3] == 'X' && board[6] == '6' && board[9] == '9') || (board[3] == '3' && board[6] == 'X' && board[9] == '9') || (board[3] == '3' && board[6] == '6' && board[9] == 'X'))
            arrCol[3] = 10;
        else if ((board[3] == 'O' && board[6] == '6' && board[9] == '9') || (board[3] == '3' && board[6] == 'O' && board[9] == '9') || (board[3] == '3' && board[6] == '6' && board[9] == 'O'))
            arrCol[3] = 9;
        else if ((board[3] == 'X' && board[6] == 'X' && board[9] == '9') || (board[3] == 'X' && board[6] == '6' && board[9] == 'X') || (board[3] == '3' && board[6] == 'X' && board[9] == 'X'))
            arrCol[3] = 1000;
        else if ((board[3] == 'O' && board[6] == 'O' && board[9] == '9') || (board[3] == 'O' && board[6] == '6' && board[9] == 'O') || (board[3] == '3' && board[6] == 'O' && board[9] == 'O'))
            arrCol[3] = 100;

        //assign values to diagonals
        if ((board[1] == 'X' && board[5] == 'X' && board[9] == 'O') || (board[1] == 'X' && board[5] == 'O' && board[9] == 'X') || (board[1] == 'O' && board[5] == 'X' && board[9] == 'X') || (board[1] == 'X' && board[5] == 'O' && board[9] == '9') || (board[1] == '1' && board[5] == 'X' && board[9] == 'O') || (board[1] == 'X' && board[5] == '5' && board[9] == 'O') || (board[1] == 'O' && board[5] == 'X' && board[9] == '9') || (board[1] == '1' && board[5] == 'O' && board[9] == 'X') || (board[1] == 'O' && board[5] == '5' && board[9] == 'X') || (board[1] == 'O' && board[5] == 'O' && board[9] == 'X') || (board[1] == 'O' && board[5] == 'X' && board[9] == 'O') || (board[1] == 'X' && board[5] == 'O' && board[9] == 'O'))
            arrDia[1] = 0;
        else if (board[1] == '1' && board[5] == '5' && board[9] == '9')
            arrDia[1] = 1;
        else if ((board[1] == 'X' && board[5] == '5' && board[9] == '9') || (board[1] == '1' && board[5] == 'X' && board[9] == '9') || (board[1] == '1' && board[5] == '5' && board[9] == 'X'))
            arrDia[1] = 10;
        else if ((board[1] == 'O' && board[5] == '5' && board[9] == '9') || (board[1] == '1' && board[5] == 'O' && board[9] == '9') || (board[1] == '1' && board[5] == '5' && board[9] == 'O'))
            arrDia[1] = 9;
        else if ((board[1] == 'X' && board[5] == 'X' && board[9] == '9') || (board[1] == 'X' && board[5] == '5' && board[9] == 'X') || (board[1] == '1' && board[5] == 'X' && board[9] == 'X'))
            arrDia[1] = 1000;
        else if ((board[1] == 'O' && board[5] == 'O' && board[9] == '9') || (board[1] == 'O' && board[5] == '5' && board[9] == 'O') || (board[1] == '1' && board[5] == 'O' && board[9] == 'O'))
            arrDia[1] = 100;

        if ((board[3] == 'X' && board[5] == 'X' && board[7] == 'O') || (board[3] == 'X' && board[5] == 'O' && board[7] == 'X') || (board[3] == 'O' && board[5] == 'X' && board[7] == 'X') || (board[3] == 'X' && board[5] == 'O' && board[7] == '7') || (board[3] == '3' && board[5] == 'X' && board[7] == 'O') || (board[3] == 'X' && board[5] == '5' && board[7] == 'O') || (board[3] == 'O' && board[5] == 'X' && board[7] == '7') || (board[3] == '3' && board[5] == 'O' && board[7] == 'X') || (board[3] == 'O' && board[5] == '5' && board[7] == 'X') || (board[3] == 'O' && board[5] == 'O' && board[7] == 'X') || (board[3] == 'O' && board[5] == 'X' && board[7] == 'O') || (board[3] == 'X' && board[5] == 'O' && board[7] == 'O'))
            arrDia[2] = 0;
        else if (board[3] == '3' && board[5] == '5' && board[7] == '7')
            arrDia[2] = 1;
        else if ((board[3] == 'X' && board[5] == '5' && board[7] == '7') || (board[3] == '3' && board[5] == 'X' && board[7] == '7') || (board[3] == '3' && board[5] == '5' && board[7] == 'X'))
            arrDia[2] = 10;
        else if ((board[3] == 'O' && board[5] == '5' && board[7] == '7') || (board[3] == '3' && board[5] == 'O' && board[7] == '7') || (board[3] == '3' && board[5] == '5' && board[7] == 'O'))
            arrDia[2] = 9;
        else if ((board[3] == 'X' && board[5] == 'X' && board[7] == '7') || (board[3] == 'X' && board[5] == '5' && board[7] == 'X') || (board[3] == '3' && board[5] == 'X' && board[7] == 'X'))
            arrDia[2] = 1000;
        else if ((board[3] == 'O' && board[5] == 'O' && board[7] == '7') || (board[3] == 'O' && board[5] == '5' && board[7] == 'O') || (board[3] == '3' && board[5] == 'O' && board[7] == 'O'))
            arrDia[2] = 100;

        //assign values to positions
        arrPos[1] = arrRow[1] + arrCol[1] + arrDia[1];
        arrPos[2] = arrRow[1] + arrCol[2];
        arrPos[3] = arrRow[1] + arrCol[3] + arrDia[2];
        arrPos[4] = arrRow[2] + arrCol[1];
        arrPos[5] = arrRow[2] + arrCol[2] + arrDia[1] + arrDia[2];
        arrPos[6] = arrRow[2] + arrCol[3];
        arrPos[7] = arrRow[3] + arrCol[1] + arrDia[2];
        arrPos[8] = arrRow[3] + arrCol[2];
        arrPos[9] = arrRow[3] + arrCol[3] + arrDia[1];

        //If No. of moves that computer played=0 || No. of moves that player played=0
        if (countC == 0 && countP == 0)
        {
            int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            int randNum = rand() % 9;
            int randPos = arr[randNum];
            board[randPos] = 'X';
            arrPreResponseCom[countC] = randPos;
        }

        //otherwise
        else
        {
            int i = 1;
            int maximum = 0;
            for (i = 1; i < 10; i++)
            {
                if (arrPos[i] > maximum)
                {
                    if (!((i == arrPreResponsePly[0]) || (i == arrPreResponsePly[1]) || (i == arrPreResponsePly[2]) || (i == arrPreResponsePly[3]) || (i == arrPreResponsePly[4])) && !((i == arrPreResponseCom[0]) || (i == arrPreResponseCom[1]) || (i == arrPreResponseCom[2]) || (i == arrPreResponseCom[3]) || (i == arrPreResponseCom[4])))
                        maximum = arrPos[i];
                }
            }
            printf("%d\n", maximum);
            int j = 1;
            int k = 0;
            int arrMax[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (j = 1; j < 10; j++)
            {
                if (arrPos[j] == maximum)
                {
                    arrMax[k] = j;
                    k = k + 1;
                }
            }
            if (k == 1)
            {
                int randPos = arrMax[0];
                board[randPos] = 'X';
                arrPreResponseCom[countC] = randPos;
            }
            else
            {
                int l = 0;
                for (l = 0; l < 100; l++)
                {
                    int randNum = rand() % k;
                    int randPos = arrMax[randNum];
                    if (!((randPos == arrPreResponsePly[0]) || (randPos == arrPreResponsePly[1]) || (randPos == arrPreResponsePly[2]) || (randPos == arrPreResponsePly[3]) || (randPos == arrPreResponsePly[4])) && !((randPos == arrPreResponseCom[0]) || (randPos == arrPreResponseCom[1]) || (randPos == arrPreResponseCom[2]) || (randPos == arrPreResponseCom[3]) || (randPos == arrPreResponseCom[4])))
                    {
                        board[randPos] = 'X';
                        arrPreResponseCom[countC] = randPos;
                        break;
                    }
                }
            }
        }
    }
}

void checkStatus(char board[10], char ans2, int *end, int *count, int *winner)
{
    //If the player chose the 'X' mark
    if (ans2 == 'X' || ans2 == 'x')
    {
        //Checking Rows
        int i = 0;
        for (i = 0; i < 3; i++)
        {
            if (board[1 + i * 3] == 'X' && board[2 + i * 3] == 'X' && board[3 + i * 3] == 'X')
            {
                *end = 1;
                *winner = 1;
            }
        }

        //Checking Columns
        int j = 0;
        for (j = 0; j < 3; j++)
        {
            if (board[1 + j] == 'X' && board[4 + j] == 'X' && board[7 + j] == 'X')
            {
                *end = 1;
                *winner = 1;
            }
        }

        //Checking diagonals
        int k = 0;
        for (k = 0; k < 2; k++)
        {
            if (board[1 + 2 * k] == 'X' && board[5] == 'X' && board[9 - 2 * k] == 'X')
            {
                *end = 1;
                *winner = 1;
            }
        }

        //Checking Rows
        int l = 0;
        for (l = 0; l < 3; l++)
        {
            if (board[1 + l * 3] == 'O' && board[2 + l * 3] == 'O' && board[3 + l * 3] == 'O')
            {
                *end = 1;
                *winner = 0;
            }
        }

        //Checking Columns
        int m = 0;
        for (m = 0; m < 3; m++)
        {
            if (board[1 + m] == 'O' && board[4 + m] == 'O' && board[7 + m] == 'O')
            {
                *end = 1;
                *winner = 0;
            }
        }

        //Checking Diagonals
        int n = 0;
        for (n = 0; n < 2; n++)
        {
            if (board[1 + 2 * n] == 'O' && board[5] == 'O' && board[9 - 2 * n] == 'O')
            {
                *end = 1;
                *winner = 0;
            }
        }
        *count = *count + 1;
    }
    //If player chose the 'O' mark
    else
    {
        //Checking Rows
        int i = 0;
        for (i = 0; i < 3; i++)
        {
            if (board[1 + i * 3] == 'O' && board[2 + i * 3] == 'O' && board[3 + i * 3] == 'O')
            {
                *end = 1;
                *winner = 1;
            }
        }

        //Checking Columns
        int j = 0;
        for (j = 0; j < 3; j++)
        {
            if (board[1 + j] == 'O' && board[4 + j] == 'O' && board[7 + j] == 'O')
            {
                *end = 1;
                *winner = 1;
            }
        }

        //Checking Diagonals
        int k = 0;
        for (k = 0; k < 2; k++)
        {
            if (board[1 + 2 * k] == 'O' && board[5] == 'O' && board[9 - 2 * k] == 'O')
            {
                *end = 1;
                *winner = 1;
            }
        }

        //Checking Rows
        int l = 0;
        for (l = 0; l < 3; l++)
        {
            if (board[1 + l * 3] == 'X' && board[2 + l * 3] == 'X' && board[3 + l * 3] == 'X')
            {
                *end = 1;
                *winner = 0;
            }
        }

        //Checking Columns
        int m = 0;
        for (m = 0; m < 3; m++)
        {
            if (board[1 + m] == 'X' && board[4 + m] == 'X' && board[7 + m] == 'X')
            {
                *end = 1;
                *winner = 0;
            }
        }

        //Checking Diagonals
        int n = 0;
        for (n = 0; n < 2; n++)
        {
            if (board[1 + 2 * n] == 'X' && board[5] == 'X' && board[9 - 2 * n] == 'X')
            {
                *end = 1;
                *winner = 0;
            }
        }
        *count = *count + 1;
    }

    //Checking the game is whether draw or not
    if (*count == 5)
    {
        *end = 1;
        *winner = 2;
    }
}

void printBoard(char board[10], char ans2)
{
    system("cls");
    printf("\n\t\t\t================================================\n");
    printf("\t\t\t_____ ___  __   _____      __   _____  __   ___\n");
    printf("\t\t\t  |    |  |       |   /\\  |       |   |  | |___\n");
    printf("\t\t\t  |   _|_ |__     |  /--\\ |__     |   |__| |___\n");
    printf("\n\t\t\t================================================\n");

    printf("\n\t\t\t\t  _________________________\n");
    printf("\t\t\t\t  |       |       |       |\n");
    printf("\t\t\t\t  |   %c   |   %c   |   %c   |\n", board[1], board[2], board[3]);
    printf("\t\t\t\t  |_______|_______|_______|\n");
    printf("\t\t\t\t  |       |       |       |\n");
    printf("\t\t\t\t  |   %c   |   %c   |   %c   |\n", board[4], board[5], board[6]);
    printf("\t\t\t\t  |_______|_______|_______|\n");
    printf("\t\t\t\t  |       |       |       |\n");
    printf("\t\t\t\t  |   %c   |   %c   |   %c   |\n", board[7], board[8], board[9]);
    printf("\t\t\t\t  |_______|_______|_______|\n\n");

    //Displaying the marks
    if (ans2 == 'x' || ans2 == 'X')
    {
        printf("\t\t\nYOUR MARK       = X");
        printf("\t\t\nCOMPUTER'S MARK = O\n\n");
    }
    else
    {
        printf("\t\t\nYOUR MARK       = O");
        printf("\t\t\nCOMPUTER'S MARK = X\n\n");
    }
}

void printResults(char board[10], char ans2, int winner)
{
    printBoard(board, ans2);
    printf("\n");
    if (winner == 0)
        printf("\t\t\t\t  ======== YOU LOST! ========\n\n");
    else if (winner == 1)
        printf("\t\t\t\t   ======== YOU WON! ========\n\n");
    else if (winner == 2)
        printf("\t\t\t\t   ======== Draw! ========\n\n");
}

//Created by Sivantha Paranavithana
//Faculty of applied sciences
//University of Sri Jayewardenepura
