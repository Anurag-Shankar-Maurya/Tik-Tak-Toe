// program to create a game like tik tak toe
// 16/03/2023   09:26
// Anurag

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <math.h>
#include <string>

#define size 3
using namespace std;

void player(char[]);            // to take input names of payers
int tikTakToe(char[], char[]); // to take input from users to mark o and x
void input(int *, int *, int);  // to take input of o or x coordinates
void display(char[size][size]); // to display the out put
int writeOrNot(int, int, char[size][size]);
int winner(char[size][size]);                  // to find the winner or draw
void score(int, int *, int *, char[], char[]); // to get score board

int main()
{
    char player_1[20], player_2[20];
    char choice = 'Y';
    int i = 1;
    int win;
    int Play1=0, Play2=0;
    cout << "\t\t\t\t===========\n"
         << "\t\t\t\tTik Tak Toe\n"
         << "\t\t\t\t===========\n";

    cout << "\n\nInput names:\n"
         << "------------\n"
         << "Player 1  'O'= ";
    player(player_1);
    cout << "Player 2  'X'= ";
    player(player_2);

    cout << endl;
// tik tak toe now
again:
    cout << "\t\t\t\tG A M E : " << i << endl
         << endl;
    win=tikTakToe(player_1, player_2);
    i++;

    score(win, &Play1, &Play2, player_1, player_2);
    fflush(stdin);
    cout << "\n\nDo you want to play again (Y/N):\n\n";
    choice = getch();
    if (choice == 'Y' || choice == 'y')
        goto again;
    // cout << player_1<<endl <<player_2;
    getch();
    return 0;
}

void player(char name[20])
{
    fflush(stdin);
    gets(name);
}

// playing tik tak toe
int tikTakToe(char player_1[20], char player_2[20])
{
    int count = 0, win = -1;
    char box[size][size];
    int r1 = -1, c1 = -1, r2 = -1, c2 = -1;
    int P1 = 0, P2 = 1;

    // assigning each box a space ' ' as initilization
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            box[i][j] = ' ';
        }
    }
    display(box);

    // to input the 'O' and 'X'
    // not to over write
    // input till all boxes are filled or any player win
     
    while (count <= size * size)
    {
        if (count >= size * size)
            break;

        while (writeOrNot(r1, c1, box) || count > size * size)
        {
            cout << "chance of " << player_1 << " 'O': \n";
            input(&r1, &c1, P1);
        }
        count++;
        box[r1][c1] = 'O';

        display(box);
        win = winner(box);

        if (count >= size * size || win != 0)
            break;

        while (writeOrNot(r2, c2, box) || count > size * size)
        {
            cout << "chance of " << player_2 << " 'X': \n";
            input(&r2, &c2, P2);
        }
        count++;
        box[r2][c2] = 'X';

        display(box);
        win = winner(box);

        if (count >= size * size || win != 0)
            break;
    } // done now

    // display the winner
    {
        if (win == 1)
        {
            cout << "\n\t\t\t\t" << player_1 << " won this match";
        }
        else if (win == 2)
        {
            cout << "\n\t\t\t\t" << player_2 << " won this match";
        }
        else
        {
            cout << "\n\t\t\t\t"
                 << "D R A W";
        }
    }
    return win;
}

// to take input of row and column for 'O' and 'X'
void input(int *r, int *c, int P)
{
    cout << "\trow= ";
    cin >> *r;
    fflush(stdin);
    cout << "\tcolumn= ";
    cin >> *c;
    fflush(stdin);
}

// to display the boxes on screen
void display(char box[size][size])
{
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            if (j == 1)
                cout << "\t\t\t\t";

            cout << " " << box[i][j] << " ";

            if (j != 3)
                cout << "|";
        }
        if (i != 3)
            cout << "\n\t\t\t\t-----------\n";
        else
            cout << endl;
    }
}

// checking if a player is following the basic rules
int writeOrNot(int r, int c, char box[size][size])
{
    if (r < 1 || (r > size) || c < 1 || (c > size) || box[r][c] != ' ')
    {
        return 1;
    }
    else
        return 0;
}

int winner(char box[size][size])
{
    int temp = 0;
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            if ((box[1][1] == 'O' && box[1][2] == 'O' && box[1][3] == 'O') || (box[2][1] == 'O' && box[2][2] == 'O' && box[2][3] == 'O') || (box[3][1] == 'O' && box[3][2] == 'O' && box[3][3] == 'O'))
                temp = 1;
            else if ((box[1][1] == 'O' && box[2][1] == 'O' && box[3][1] == 'O') || (box[1][2] == 'O' && box[2][2] == 'O' && box[3][2] == 'O') || (box[1][3] == 'O' && box[2][3] == 'O' && box[3][3] == 'O'))
                temp = 1;
            else if (box[1][1] == 'O' && box[2][2] == 'O' && box[3][3] == 'O')
                temp = 1;
            else if (box[1][3] == 'O' && box[2][2] == 'O' && box[3][1] == 'O')
                temp = 1;

            else if ((box[1][1] == 'X' && box[1][2] == 'X' && box[1][3] == 'X') || (box[2][1] == 'X' && box[2][2] == 'X' && box[2][3] == 'X') || (box[3][1] == 'X' && box[3][2] == 'X' && box[3][3] == 'X'))
                temp = 2;
            else if ((box[1][1] == 'X' && box[2][1] == 'X' && box[3][1] == 'X') || (box[1][2] == 'X' && box[2][2] == 'X' && box[3][2] == 'X') || (box[1][3] == 'X' && box[2][3] == 'X' && box[3][3] == 'X'))
                temp = 2;
            else if (box[1][1] == 'X' && box[2][2] == 'X' && box[3][3] == 'X')
                temp = 2;
            else if (box[1][3] == 'X' && box[2][2] == 'X' && box[3][1] == 'X')
                temp = 2;
        }
    }
    return temp;
}

// to manage and print score on screen
void score(int win, int *Play1, int *Play2, char Player_1[20], char Player_2[20])
{
    if (win == 1)
    {
        *Play1=*Play1+1;
    }
    if (win == 2)
    {
        *Play2=*Play2+1;
    }

    cout << "\n\n\n\t"
        <<setw(12)
         << "S C O R E"
         << "\n\t"
         << setw(12)
         << "---------";
    cout << "\n"
         << setw(12)
         << Player_1
         << setw(12)
         << Player_2 << endl;
    cout << setw(12)
         << *Play1
         << setw(12)
         << *Play2 << endl;
}
