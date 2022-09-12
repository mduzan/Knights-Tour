/**
 * This program utalizes recursion to solve the Knight's Tour.
 */ 

/*
TEST RUN 1:
Enter a x-coordinate between 0 and 5: 0
Enter a y-coordinate between 0 and 5: 0
  1  22  13  30  33  36 
 12  29   2  35  14  31 
 21   8  23  32   3  34
 28  11   4  17  24  15
  7  20   9  26   5  18
 10  27   6  19  16  25

TEST RUN 2:
Enter a x-coordinate between 0 and 5: 0 
Enter a y-coordinate between 0 and 5: 3
 26  13  24   1  28  11 
 21  36  27  12  23   2 
 14  25  22   3  10  29
 35  20  33  16   7   4
 32  15  18   5  30   9
 19  34  31   8  17   6

TEST RUN 3:
Enter a x-coordinate between 0 and 5: 5 
Enter a y-coordinate between 0 and 5: 5
  9  16  27  20  33  36 
 26  21  10  35  28  19 
 15   8  17  32  11  34
 22  25   4  29  18  31
  7  14  23   2   5  12
 24   3   6  13  30   1
*/

#include <iostream>
#include <iomanip>
using namespace std;
#define N 6
//All the ways a knight can move
static int xKnightMove[8] = {1,1,2,2,-1,-1,-2,-2};
static int yKnightMove[8] = {2,-2,1,-1,2,-2,1,-1};

bool limitsAndEmpty(int, int, int[N][N]);
void printBoard(int[N][N]);

bool recursiveKnightsTour(int chessBoard[N][N], int x, int y, int numTimesKnightMoved)
{
    /**
     * Performs variuos checks to solve the Knight's Tour recursivly.
     */
    if (numTimesKnightMoved == (N * N)+1)
    {
        return true;
    }
    //Cycles through all the possible moves a knight could take.
    for (int possibleKnightMoves = 0; possibleKnightMoves < 8; possibleKnightMoves++)
    {
        int xNext = x + xKnightMove[possibleKnightMoves];
        int yNext = y + yKnightMove[possibleKnightMoves];

        //checks if location is free to move to.
        if (limitsAndEmpty(xNext, yNext, chessBoard))
        {
            //moves knight to the location.
            chessBoard[xNext][yNext] = numTimesKnightMoved;
            if (recursiveKnightsTour(chessBoard, xNext, yNext, numTimesKnightMoved + 1) == true)
            {
                return true;
            }
            else
            {
                //backtracking
                chessBoard[xNext][yNext] = 0;
            }
        }
    }
    return false;
}

bool limitsAndEmpty(int x, int y, int chessBoard[N][N])
{
    /**
     * This function restricts the knight to the chess board checks if
     * the location is empty.
     * 
     */
    if (x >= 0 && x < N && y >= 0 && y < N && chessBoard[x][y] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool startKnightsTour(int xStart, int yStart)
{
    /**
     * Creates the chess board, initializes the starting location,
     * and informs whether the Knight's Tour can be created or not.
     */
    //Makes the board
    int chessBoard[N][N];
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            chessBoard[x][y] = 0;
        }
    }
    
    chessBoard[xStart][yStart] = 1;

    if(recursiveKnightsTour(chessBoard, xStart, yStart, 2) == false)
    {
        cout << "No solution Found" << endl;
        return false;
    }
    else 
    {
        printBoard(chessBoard);
    }
    return true;
}
void printBoard(int chessBoard[N][N])
{
    /**
     * Prints the board.
     */
    for (int x = 0; x < N; x++) 
    {
        for (int y = 0; y < N; y++)
        {
            cout << setw(3) << chessBoard[x][y] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int xCoord, yCoord;
    cout << "Enter a x-coordinate between 0 and 5: ";
    cin >> xCoord;
    cout << "Enter a y-coordinate between 0 and 5: ";
    cin >> yCoord;

    while (xCoord > 5 || xCoord < 0 || yCoord > 5 || yCoord < 0)
    {
        cout << "Enter an appropriate x-coordinate between 0 and 5: ";
        cin >> xCoord;
        cout << "Enter an appropriate y-coordinate between 0 and 5: ";
        cin >> yCoord;
    }

    startKnightsTour(xCoord, yCoord);
    
    return 0;
}
