#ifndef _CHESS_H_
#define _CHESS_H_

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define black "\e[1;30m"
#define red "\e[1;31m"
#define white "\e[0;37m"
#define redbg "\e[0;41m"
#define greenbg "\e[0;42m"
#define whitebg "\e[0;47m"
#define bw "\e[1;37m"
#define reset "\e[0;0m"

void rules1()
{
    for (int i = 0; i < 6; i++)
    {
        printf("\n");
    }
    for (int i = 0; i < 50; i++)
    {
        printf("*");
    }
    for (int i = 0; i < 21; i++)
    {
        printf(" ");
    }
    printf("Welcome to Chess!!!");
    for (int i = 0; i < 21; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < 50; i++)
    {
        printf("*");
    }
    printf("\n");
    for (int i = 0; i < 50; i++)
    {
        printf("*");
    }
    printf(" The rules are simply! and same as the original chess game. ");
    for (int i = 0; i < 50; i++)
    {
        printf("*");
    }
    printf("\n");
    sleep(1);
    printf("   Rules:\n");
    printf("%c It is a Two player game.\n", 26);
    printf("%c Every time the selection(which is in green colour) starts from th kings positons.\n", 26);
    printf("%c Press Left arrow in your keyboard to move the selection 1 step left side.\n", 26);
    printf("%c Press Right arrow in your keyboard to move the selection 1 step right side.\n", 26);
    printf("%c Press Down arrow in your keyboard to move the selection 1 step downwards.\n", 26);
    printf("%c Press Enter to select the piece to show the available moves.\n", 26);
    printf("%c Press Esc to deselect the piece.\n", 26);
    printf("%c If you pressed wrong box ,there will be no change in the board.\n", 26);
    printf("%c Checkmate,Stalemate,Pawn Promotion and Castling is made avaialable int he game .\n", 26);
    printf("%c After reading the rules,press any key to start the game.\n", 26);
    printf("%c Good luck!!!\n", 26);
    system("pause");
    printf("\e[1;1H\e[2J");
}

void chessboard(char array[8][8], char blackpieces[20], char whitepieces[20], int px, int py, int avilx[100], int avily[100], int bcm, int wcm, int wh)
{
    if (wcm == 1 && wh != 0)
    {
        gotoxy(0, 0);
        printf(red "\nwhite king is in check!\n" reset);
    }
    else if (bcm == 1 && wh != 1)
    {
        gotoxy(0, 0);
        printf(red "\nblack king is in check!\n" reset);
    }
    else
    {
        printf("\n");
    }
    printf("\n\t\t\t\t\t");
    printf("   Black pieces:");
    for (int i = 0; i < 16; i++)
    {
        printf(bw "%c " reset, blackpieces[i]);
    }
    printf("\n\t\t\t\t\t");
    for (int i = 0; i < 106; i++)
    {
        printf(white "%c" reset, 220);
    }
    printf("\n\t\t\t\t\t");
    printf(whitebg "     " reset);
    for (int i = 1; i <= 8; i++)
    {
        for (int i = 0; i < 12; i++)
        {
            printf(whitebg " " reset);
        }
    }
    printf(whitebg "     \n" reset);
    printf("\t\t\t\t\t");
    printf(whitebg "    " reset);
    for (int i = 0; i < 98; i++)
    {
        printf(white "%c" reset, 223);
    }
    printf(whitebg "    " reset);
    printf("\n");
    for (int i = 1; i <= 8; i++)
    {
        if (i % 2 == 1)
        {
            for (int j = 1; j <= 2; j++)
            {
                printf("\t\t\t\t\t");
                printf(whitebg "    " reset);
                printf(" ");
                for (int k = 1; k <= 8; k++)
                {
                    if (k % 2 != 0)
                    {
                        if (i == px && k == py)
                        {
                            for (int l = 0; l < 12; l++)
                            {
                                printf(greenbg "%c" reset, ' ');
                            }
                        }
                        else
                        {
                            for (int l = 0; l < 12; l++)
                            {
                                printf(whitebg "%c" reset, ' ');
                            }
                        }
                    }
                    else
                    {
                        if (i == px && k == py)
                        {
                            for (int l = 0; l < 12; l++)
                            {
                                printf(greenbg "%c" reset, ' ');
                            }
                        }
                        else
                        {
                            for (int l = 0; l < 12; l++)
                            {
                                printf("%c", ' ');
                            }
                        }
                    }
                }
                printf(" ");
                printf(whitebg "    " reset);
                printf(" \n");
            }
            printf("\t\t\t\t\t");
            printf(whitebg black "  %d " reset, 9 - i);
            printf(" ");
            for (int j = 1; j <= 8; j++)
            {
                if (j % 2 == 1)
                {
                    if (i == px && j == py)
                    {
                        for (int l = 1; l <= 12; l++)
                        {
                            int c = -1, d = -1;
                            if (l == 6)
                            {
                                for (int w = 0; w < 30; w++)
                                {
                                    if (avilx[w] == i - 1 && avily[w] == j - 1)
                                    {
                                        c = i - 1, d = j - 1;
                                    }
                                }
                                if (c == -1 && d == -1)
                                {
                                    printf(greenbg bw "%c" reset, array[i - 1][j - 1]);
                                }
                                else
                                {
                                    if (array[c][d] == ' ')
                                    {
                                        printf(greenbg "*" reset);
                                    }
                                    else
                                    {
                                        printf(greenbg red "%c" reset, array[c][d]);
                                    }
                                }
                            }
                            else
                            {
                                printf(greenbg "%c" reset, ' ');
                            }
                        }
                    }
                    else
                    {
                        for (int l = 1; l <= 12; l++)
                        {
                            int c = -1, d = -1;
                            if (l == 6)
                            {
                                for (int w = 0; w < 30; w++)
                                {
                                    if (avilx[w] == i - 1 && avily[w] == j - 1)
                                    {
                                        c = i - 1, d = j - 1;
                                    }
                                }
                                if (c == -1 && d == -1)
                                {
                                    printf(whitebg bw "%c" reset, array[i - 1][j - 1]);
                                }
                                else
                                {
                                    if (array[c][d] == ' ')
                                    {
                                        printf(whitebg "*" reset);
                                    }
                                    else
                                    {
                                        printf(whitebg red "%c" reset, array[c][d]);
                                    }
                                }
                            }
                            else
                            {
                                printf(whitebg "%c" reset, ' ');
                            }
                        }
                    }
                }
                else
                {
                    if (i == px && j == py)
                    {
                        for (int l = 1; l <= 12; l++)
                        {
                            int c = -1, d = -1;
                            if (l == 6)
                            {
                                for (int w = 0; w < 30; w++)
                                {
                                    if (avilx[w] == i - 1 && avily[w] == j - 1)
                                    {
                                        c = i - 1, d = j - 1;
                                    }
                                }
                                if (c == -1 && d == -1)
                                {
                                    printf(greenbg bw "%c" reset, array[i - 1][j - 1]);
                                }
                                else
                                {
                                    if (array[c][d] == ' ')
                                    {
                                        printf(greenbg "*" reset);
                                    }
                                    else
                                    {
                                        printf(greenbg red "%c" reset, array[c][d]);
                                    }
                                }
                            }
                            else
                            {
                                printf(greenbg "%c" reset, ' ');
                            }
                        }
                    }
                    else
                    {
                        for (int l = 1; l <= 12; l++)
                        {
                            int c = -1, d = -1;
                            if (l == 6)
                            {
                                for (int w = 0; w < 30; w++)
                                {
                                    if (avilx[w] == i - 1 && avily[w] == j - 1)
                                    {
                                        c = i - 1, d = j - 1;
                                    }
                                }
                                if (c == -1 && d == -1)
                                {
                                    printf("%c", array[i - 1][j - 1]);
                                }
                                else
                                {
                                    if (array[c][d] == ' ')
                                    {
                                        printf("*");
                                    }
                                    else
                                    {
                                        printf(red "%c" reset, array[c][d]);
                                    }
                                }
                            }
                            else
                            {
                                printf("%c", ' ');
                            }
                        }
                    }
                }
            }
            printf(" ");
            printf(whitebg "    " reset);
            printf("\n");
            for (int j = 1; j <= 2; j++)
            {
                printf("\t\t\t\t\t");
                printf(whitebg "    " reset);
                printf(" ");
                for (int k = 1; k <= 8; k++)
                {
                    if (k % 2 != 0)
                    {
                        if (i == px && k == py)
                        {
                            for (int l = 0; l < 12; l++)
                            {
                                printf(greenbg "%c" reset, ' ');
                            }
                        }
                        else
                        {
                            for (int l = 0; l < 12; l++)
                            {
                                printf(whitebg "%c" reset, ' ');
                            }
                        }
                    }
                    else
                    {
                        if (i == px && k == py)
                        {
                            for (int l = 0; l < 12; l++)
                            {
                                printf(greenbg "%c" reset, ' ');
                            }
                        }
                        else
                        {
                            for (int l = 0; l < 12; l++)
                            {
                                printf("%c", ' ');
                            }
                        }
                    }
                }
                printf(" ");
                printf(whitebg "    " reset);
                printf(" \n");
            }
        }
        else
        {
            for (int j = 1; j <= 2; j++)
            {
                printf("\t\t\t\t\t");
                printf(whitebg "    " reset);
                printf(" ");
                for (int k = 1; k <= 8; k++)
                {
                    if (k % 2 == 0)
                    {
                        if (i == px && k == py)
                        {
                            for (int l = 0; l < 12; l++)
                            {
                                printf(greenbg "%c" reset, ' ');
                            }
                        }
                        else
                        {
                            for (int l = 0; l < 12; l++)
                            {
                                printf(whitebg "%c" reset, ' ');
                            }
                        }
                    }
                    else
                    {
                        if (i == px && k == py)
                        {
                            for (int l = 0; l < 12; l++)
                            {
                                printf(greenbg "%c" reset, ' ');
                            }
                        }
                        else
                        {
                            for (int l = 0; l < 12; l++)
                            {
                                printf("%c", ' ');
                            }
                        }
                    }
                }
                printf(" ");
                printf(whitebg "    " reset);
                printf(" \n");
            }
            printf("\t\t\t\t\t");
            printf(whitebg black "  %d " reset, 9 - i);
            printf(" ");
            for (int j = 1; j <= 8; j++)
            {
                if (j % 2 == 0)
                {
                    if (i == px && j == py)
                    {
                        for (int l = 1; l <= 12; l++)
                        {
                            int c = -1, d = -1;
                            if (l == 6)
                            {
                                for (int w = 0; w < 30; w++)
                                {
                                    if (avilx[w] == i - 1 && avily[w] == j - 1)
                                    {
                                        c = i - 1, d = j - 1;
                                    }
                                }
                                if (c == -1 && d == -1)
                                {
                                    printf(greenbg bw "%c" reset, array[i - 1][j - 1]);
                                }
                                else
                                {
                                    if (array[c][d] == ' ')
                                    {
                                        printf(greenbg "*" reset);
                                    }
                                    else
                                    {
                                        printf(greenbg red "%c" reset, array[c][d]);
                                    }
                                }
                            }
                            else
                            {
                                printf(greenbg "%c" reset, ' ');
                            }
                        }
                    }
                    else
                    {
                        for (int l = 1; l <= 12; l++)
                        {
                            int c = -1, d = -1;
                            if (l == 6)
                            {
                                for (int w = 0; w < 30; w++)
                                {
                                    if (avilx[w] == i - 1 && avily[w] == j - 1)
                                    {
                                        c = i - 1, d = j - 1;
                                    }
                                }
                                if (c == -1 && d == -1)
                                {
                                    printf(whitebg bw "%c" reset, array[i - 1][j - 1]);
                                }
                                else
                                {
                                    if (array[c][d] == ' ')
                                    {
                                        printf(whitebg "*" reset);
                                    }
                                    else
                                    {
                                        printf(whitebg red "%c" reset, array[c][d]);
                                    }
                                }
                            }
                            else
                            {
                                printf(whitebg "%c" reset, ' ');
                            }
                        }
                    }
                }
                else
                {
                    if (i == px && j == py)
                    {
                        for (int l = 1; l <= 12; l++)
                        {
                            int c = -1, d = -1;
                            if (l == 6)
                            {
                                for (int w = 0; w < 30; w++)
                                {
                                    if (avilx[w] == i - 1 && avily[w] == j - 1)
                                    {
                                        c = i - 1, d = j - 1;
                                    }
                                }
                                if (c == -1 && d == -1)
                                {
                                    printf(greenbg bw "%c" reset, array[i - 1][j - 1]);
                                }
                                else
                                {
                                    if (array[c][d] == ' ')
                                    {
                                        printf(greenbg "*" reset);
                                    }
                                    else
                                    {
                                        printf(greenbg red "%c" reset, array[c][d]);
                                    }
                                }
                            }
                            else
                            {
                                printf(greenbg "%c" reset, ' ');
                            }
                        }
                    }
                    else
                    {
                        for (int l = 1; l <= 12; l++)
                        {
                            int c = -1, d = -1;
                            if (l == 6)
                            {
                                for (int w = 0; w < 30; w++)
                                {
                                    if (avilx[w] == i - 1 && avily[w] == j - 1)
                                    {
                                        c = i - 1, d = j - 1;
                                    }
                                }
                                if (c == -1 && d == -1)
                                {
                                    printf("%c", array[i - 1][j - 1]);
                                }
                                else
                                {
                                    if (array[c][d] == ' ')
                                    {
                                        printf("*");
                                    }
                                    else
                                    {
                                        printf(red "%c" reset, array[c][d]);
                                    }
                                }
                            }
                            else
                            {
                                printf("%c", ' ');
                            }
                        }
                    }
                }
            }
            printf(" ");
            printf(whitebg "    " reset);
            printf("\n");
            for (int j = 1; j <= 2; j++)
            {
                printf("\t\t\t\t\t");
                printf(whitebg "    " reset);
                printf(" ");
                for (int k = 1; k <= 8; k++)
                {
                    if (k % 2 == 0)
                    {
                        if (i == px && k == py)
                        {
                            for (int l = 0; l < 12; l++)
                            {
                                printf(greenbg "%c" reset, ' ');
                            }
                        }
                        else
                        {
                            for (int l = 0; l < 12; l++)
                            {
                                printf(whitebg "%c" reset, ' ');
                            }
                        }
                    }
                    else
                    {
                        if (i == px && k == py)
                        {
                            for (int l = 0; l < 12; l++)
                            {
                                printf(greenbg "%c" reset, ' ');
                            }
                        }
                        else
                        {
                            for (int l = 0; l < 12; l++)
                            {
                                printf("%c", ' ');
                            }
                        }
                    }
                }
                printf(" ");
                printf(whitebg "    " reset);
                printf(" \n");
            }
        }
    }
    +printf("\t\t\t\t\t");
    printf(whitebg "    " reset);
    for (int i = 0; i < 98; i++)
    {
        printf(white "%c" reset, 220);
    }
    printf(whitebg "    " reset);
    printf("\n\t\t\t\t\t");
    printf(whitebg "     " reset);
    for (int i = 1; i <= 8; i++)
    {
        for (int i = 0; i < 6; i++)
        {
            printf(whitebg " " reset);
        }
        printf(whitebg black "%c" reset, 64 + i);
        for (int i = 0; i < 5; i++)
        {
            printf(whitebg " " reset);
        }
    }
    printf(whitebg "     \n" reset);
    printf("\t\t\t\t\t");
    for (int i = 0; i < 106; i++)
    {
        printf(white "%c" reset, 223);
    }
    printf("\n\t\t\t\t\t   White pieces:");
    for (int i = 0; i < 16; i++)
    {
        printf(bw "%c " reset, whitepieces[i]);
    }
    printf(" \n");
}

int blackcheck(char array[8][8], int p, int q, int r, int s)
{
    char t[2];
    int i, j, a, b, digits = 0;
    t[0] = array[r - 1][s - 1];
    array[r - 1][s - 1] = array[p - 1][q - 1];
    array[p - 1][q - 1] = ' ';
    for (i = 0; i <= 7; i++)
    {
        for (j = 0; j <= 7; j++)
        {
            if (array[i][j] == 'k')
            {
                a = i;
                b = j;
            }
        }
    }
    if (array[a + 1][b + 1] == 'P' && (a + 1) < 8 && (b + 1) < 8)
    {
        digits++;
    }
    if (array[a + 1][b - 1] == 'P' && (a + 1) < 8 && (b - 1) >= 0)
    {
        digits++;
    }
    for (i = a, j = b; i <= 7 && j <= 7; i++, j++)
    {
        if (i == a || array[i][j] == ' ')
        {
            continue;
        }
        else if (array[i][j] == 'B' || array[i][j] == 'Q')
        {
            digits++;
        }
        else
        {
            break;
        }
    }
    for (i = a, j = b; i >= 0 && j <= 7; i--, j++)
    {
        if (i == a || array[i][j] == ' ')
        {
            continue;
        }
        else if (array[i][j] == 'B' || array[i][j] == 'Q')
        {
            digits++;
        }
        else
        {
            break;
        }
    }
    for (i = a, j = b; i >= 0 && j >= 0; i--, j--)
    {
        if (i == a || array[i][j] == ' ')
        {
            continue;
        }

        else if (array[i][j] == 'B' || array[i][j] == 'Q')
        {
            digits++;
        }
        else
        {
            break;
        }
    }
    for (i = a, j = b; i <= 7 && j >= 0; i++, j--)
    {
        if (i == a || array[i][j] == ' ')
        {
            continue;
        }
        else if (array[i][j] == 'B' || array[i][j] == 'Q')
        {
            digits++;
        }
        else
        {
            break;
        }
    }
    for (int j = b; j <= 7; j++)
    {
        if (j == b || array[a][j] == ' ')
        {
            continue;
        }
        else if (array[a][j] == 'R' || array[a][j] == 'Q')
        {
            digits++;
        }
        else
        {
            break;
        }
    }
    for (int j = b; j >= 0; j--)
    {
        if (j == b || array[a][j] == ' ')
        {
            continue;
        }
        else if (array[a][j] == 'R' || array[a][j] == 'Q')
        {
            digits++;
        }
        else
        {
            break;
        }
    }
    for (int i = a; i <= 7; i++)
    {
        if (i == a || array[i][b] == ' ')
        {
            continue;
        }
        else if (array[i][b] == 'R' || array[i][b] == 'Q')
        {
            digits++;
        }
        else
        {
            break;
        }
    }
    for (int i = a; i >= 0; i--)
    {
        if (i == a || array[i][b] == ' ')
        {
            continue;
        }
        else if (array[i][b] == 'R' || array[i][b] == 'Q')
        {
            digits++;
        }
        else
        {
            break;
        }
    }
    if ((array[a + 2][b + 1] == 'N' && (a + 2) < 8 && (b + 1) < 8) || (array[a + 2][b - 1] == 'N' && (a + 2) < 8 && (b - 1) >= 0) || (array[a - 2][b + 1] == 'N' && (a - 2) >= 0 && (b + 1) < 8) || (array[a - 2][b - 1] == 'N' && (a - 2) >= 0 && (b - 1) >= 0) || (array[a + 1][b - 2] == 'N' && (a + 1) < 8 && (b - 2) >= 0) || (array[a - 1][b - 2] == 'N' && (a - 1) >= 0 && (b - 2) >= 0) || (array[a + 1][b + 2] == 'N' && (a + 1) < 8 && (b + 2) < 8) || (array[a - 1][b + 2] == 'N' && (a - 1) >= 0 && (b + 2) < 8))
    {
        digits++;
    }
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            else
            {
                if ((array[a + i][b + j] == 'K') && (a + i) >= 0 && (a + i) < 8 && (b + j) >= 0 && (b + j) < 8)
                {
                    digits++;
                }
            }
        }
    }
    array[p - 1][q - 1] = array[r - 1][s - 1];
    array[r - 1][s - 1] = t[0];
    if (digits != 0)
    {
        return 1;
    }
    return 0;
}

int whitecheck(char array[8][8], int p, int q, int r, int s)
{
    char t[2];
    int i, j, a, b, digits = 0;
    t[0] = array[r - 1][s - 1];
    array[r - 1][s - 1] = array[p - 1][q - 1];
    array[p - 1][q - 1] = ' ';
    for (i = 0; i <= 7; i++)
    {
        for (j = 0; j <= 7; j++)
        {
            if (array[i][j] == 'K')
            {
                a = i;
                b = j;
            }
        }
    }
    if (array[a - 1][b + 1] == 'p' && (a - 1) >= 0 && (b + 1) < 8)
    {
        digits++;
    }
    if (array[a - 1][b - 1] == 'p' && (a - 1) >= 0 && (b - 1) >= 0)
    {
        digits++;
    }
    for (i = a, j = b; i <= 7 && j <= 7; i++, j++)
    {
        if (i == a || array[i][j] == ' ')
        {
            continue;
        }
        else if (array[i][j] == 'b' || array[i][j] == 'q')
        {
            digits++;
        }
        else
        {
            break;
        }
    }
    for (i = a, j = b; i >= 0 && j <= 7; i--, j++)
    {
        if (i == a || array[i][j] == ' ')
        {
            continue;
        }
        else if (array[i][j] == 'b' || array[i][j] == 'q')
        {
            digits++;
        }
        else
        {
            break;
        }
    }
    for (i = a, j = b; i >= 0 && j >= 0; i--, j--)
    {
        if (i == a || array[i][j] == ' ')
        {
            continue;
        }
        else if (array[i][j] == 'b' || array[i][j] == 'q')
        {
            digits++;
        }
        else
        {
            break;
        }
    }
    for (i = a, j = b; i <= 7 && j >= 0; i++, j--)
    {
        if (i == a || array[i][j] == ' ')
        {
            continue;
        }
        else if (array[i][j] == 'b' || array[i][j] == 'q')
        {
            digits++;
        }
        else
        {
            break;
        }
    }
    for (int j = b; j <= 7; j++)
    {
        if (j == b || array[a][j] == ' ')
        {
            continue;
        }
        else if (array[a][j] == 'r' || array[a][j] == 'q')
        {
            digits++;
        }
        else
        {
            break;
        }
    }
    for (int j = b; j >= 0; j--)
    {
        if (j == b || array[a][j] == ' ')
        {
            continue;
        }
        else if (array[a][j] == 'r' || array[a][j] == 'q')
        {
            digits++;
        }
        else
        {
            break;
        }
    }
    for (int i = a; i <= 7; i++)
    {
        if (i == a || array[i][b] == ' ')
        {
            continue;
        }
        else if (array[i][b] == 'r' || array[i][b] == 'q')
        {
            digits++;
        }
        else
        {
            break;
        }
    }
    for (int i = a; i >= 0; i--)
    {
        if (i == a || array[i][b] == ' ')
        {
            continue;
        }
        else if (array[i][b] == 'r' || array[i][b] == 'q')
        {
            digits++;
        }
        else
        {
            break;
        }
    }
    if ((array[a + 2][b + 1] == 'n' && (a + 2) < 8 && (b + 1) < 8) || (array[a + 2][b - 1] == 'n' && (a + 2) < 8 && (b - 1) >= 0) || (array[a - 2][b + 1] == 'n' && (a - 2) >= 0 && (b + 1) < 8) || (array[a - 2][b - 1] == 'n' && (a - 2) >= 0 && (b - 1) >= 0) || (array[a + 1][b - 2] == 'n' && (a + 1) < 8 && (b - 2) >= 0) || (array[a - 1][b - 2] == 'n' && (a - 1) >= 0 && (b - 2) >= 0) || (array[a + 1][b + 2] == 'n' && (a + 1) < 8 && (b + 2) < 8) || (array[a - 1][b + 2] == 'n' && (a - 1) >= 0 && (b + 2) < 8))
    {
        digits++;
    }
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            else
            {
                if ((array[a + i][b + j] == 'k') && (a + i) >= 0 && (a + i) < 8 && (b + j) >= 0 && (b + j) < 8)
                {
                    digits++;
                }
            }
        }
    }
    array[p - 1][q - 1] = array[r - 1][s - 1];
    array[r - 1][s - 1] = t[0];
    if (digits != 0)
    {
        return 1;
    }
    return 0;
}

void availble(char array[8][8], int ax, int ay, int avilx[100], int avily[100], int wc, int bc)
{
    int digits = 0;
    if (array[ax][ay] == 'P')
    {
        if (ax == 6)
        {
            if (array[ax - 1][ay] == ' ' && (whitecheck(array, ax + 1, ay + 1, ax, ay + 1) == 0))
            {
                avilx[digits] = ax - 1, avily[digits] = ay;
                digits++;
                if (array[ax - 2][ay] == ' ' && (whitecheck(array, ax + 1, ay + 1, ax - 1, ay + 1) == 0))
                {
                    avilx[digits] = ax - 2, avily[digits] = ay;
                    digits++;
                }
            }
            if ((array[ax - 1][ay - 1] > 96 && array[ax - 1][ay - 1] < 123 && (ay - 1) >= 0) && (whitecheck(array, ax + 1, ay + 1, ax, ay) == 0))
            {
                avilx[digits] = ax - 1, avily[digits] = ay - 1;
                digits++;
            }
            if (array[ax - 1][ay + 1] > 96 && array[ax - 1][ay + 1] < 123 && (ay + 1) < 8 && (whitecheck(array, ax + 1, ay + 1, ax, ay + 2) == 0))
            {
                avilx[digits] = ax - 1, avily[digits] = ay + 1;
                digits++;
            }
        }
        else
        {
            if (array[ax - 1][ay] == ' ' && (ax - 1) > 0 && (whitecheck(array, ax + 1, ay + 1, ax, ay + 1) == 0))
            {
                avilx[digits] = ax - 1, avily[digits] = ay;
                digits++;
            }
            if (array[ax - 1][ay - 1] > 96 && array[ax - 1][ay - 1] < 123 && (ay - 1) >= 0 && (ax - 1) >= 0 && (whitecheck(array, ax + 1, ay + 1, ax, ay) == 0))
            {
                avilx[digits] = ax - 1, avily[digits] = ay - 1;
                digits++;
            }
            if (array[ax - 1][ay + 1] > 96 && array[ax - 1][ay + 1] < 123 && (ay + 1) < 8 && (ax - 1) >= 0 && (whitecheck(array, ax + 1, ay + 1, ax, ay + 2) == 0))
            {
                avilx[digits] = ax - 1, avily[digits] = ay + 1;
                digits++;
            }
        }
    }
    else if (array[ax][ay] == 'B' || array[ax][ay] == 'Q' || array[ax][ay] == 'b' || array[ax][ay] == 'q')
    {
        for (int i = ax + 1, j = ay + 1; i <= 7 && j <= 7; i++, j++)
        {
            if (((array[i][j] == ' ') && (array[ax][ay] == 'B' || array[ax][ay] == 'Q') && (whitecheck(array, ax + 1, ay + 1, i + 1, j + 1) == 0)) || ((array[i][j] == ' ') && (array[ax][ay] == 'b' || array[ax][ay] == 'q') && (blackcheck(array, ax + 1, ay + 1, i + 1, j + 1) == 0)))
            {
                avilx[digits] = i, avily[digits] = j;
                digits++;
            }
            else if (((array[i][j] > 96 && array[i][j] < 123) && (array[ax][ay] == 'B' || array[ax][ay] == 'Q') && (whitecheck(array, ax + 1, ay + 1, i + 1, j + 1) == 0)) || (array[i][j] > 64 && array[i][j] < 91 && (array[ax][ay] == 'b' || array[ax][ay] == 'q') && (blackcheck(array, ax + 1, ay + 1, i + 1, j + 1) == 0)))
            {
                avilx[digits] = i, avily[digits] = j;
                digits++;
                break;
            }
            else
            {
                break;
            }
        }
        for (int i = ax - 1, j = ay + 1; i >= 0 && j <= 7; i--, j++)
        {
            if (((array[i][j] == ' ') && (array[ax][ay] == 'B' || array[ax][ay] == 'Q') && (whitecheck(array, ax + 1, ay + 1, i + 1, j + 1) == 0)) || ((array[i][j] == ' ') && (array[ax][ay] == 'b' || array[ax][ay] == 'q') && (blackcheck(array, ax + 1, ay + 1, i + 1, j + 1) == 0)))
            {
                avilx[digits] = i, avily[digits] = j;
                digits++;
            }
            else if (((array[i][j] > 96 && array[i][j] < 123) && (array[ax][ay] == 'B' || array[ax][ay] == 'Q') && (whitecheck(array, ax + 1, ay + 1, i + 1, j + 1) == 0)) || (array[i][j] > 64 && array[i][j] < 91 && (array[ax][ay] == 'b' || array[ax][ay] == 'q') && (blackcheck(array, ax + 1, ay + 1, i + 1, j + 1) == 0)))
            {
                avilx[digits] = i, avily[digits] = j;
                digits++;
                break;
            }
            else
            {
                break;
            }
        }
        for (int i = ax - 1, j = ay - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (((array[i][j] == ' ') && (array[ax][ay] == 'B' || array[ax][ay] == 'Q') && (whitecheck(array, ax + 1, ay + 1, i + 1, j + 1) == 0)) || ((array[i][j] == ' ') && (array[ax][ay] == 'b' || array[ax][ay] == 'q') && (blackcheck(array, ax + 1, ay + 1, i + 1, j + 1) == 0)))
            {
                avilx[digits] = i, avily[digits] = j;
                digits++;
            }
            else if (((array[i][j] > 96 && array[i][j] < 123) && (array[ax][ay] == 'B' || array[ax][ay] == 'Q') && (whitecheck(array, ax + 1, ay + 1, i + 1, j + 1) == 0)) || (array[i][j] > 64 && array[i][j] < 91 && (array[ax][ay] == 'b' || array[ax][ay] == 'q') && (blackcheck(array, ax + 1, ay + 1, i + 1, j + 1) == 0)))
            {
                avilx[digits] = i, avily[digits] = j;
                digits++;
                break;
            }
            else
            {
                break;
            }
        }
        for (int i = ax + 1, j = ay - 1; i <= 7 && j >= 0; i++, j--)
        {
            if (((array[i][j] == ' ') && (array[ax][ay] == 'B' || array[ax][ay] == 'Q') && (whitecheck(array, ax + 1, ay + 1, i + 1, j + 1) == 0)) || ((array[i][j] == ' ') && (array[ax][ay] == 'b' || array[ax][ay] == 'q') && (blackcheck(array, ax + 1, ay + 1, i + 1, j + 1) == 0)))
            {
                avilx[digits] = i, avily[digits] = j;
                digits++;
            }
            else if (((array[i][j] > 96 && array[i][j] < 123) && (array[ax][ay] == 'B' || array[ax][ay] == 'Q') && (whitecheck(array, ax + 1, ay + 1, i + 1, j + 1) == 0)) || (array[i][j] > 64 && array[i][j] < 91 && (array[ax][ay] == 'b' || array[ax][ay] == 'q') && (blackcheck(array, ax + 1, ay + 1, i + 1, j + 1) == 0)))
            {
                avilx[digits] = i, avily[digits] = j;
                digits++;
                break;
            }
            else
            {
                break;
            }
        }
        if (array[ax][ay] == 'Q' || array[ax][ay] == 'q')
        {
            goto label;
        }
    }
    else if (array[ax][ay] == 'R' || array[ax][ay] == 'Q' || array[ax][ay] == 'r' || array[ax][ay] == 'q')
    {
    label:
        for (int j = ay + 1; j <= 7; j++)
        {
            if (((array[ax][j] == ' ') && (array[ax][ay] == 'R' || array[ax][ay] == 'Q') && (whitecheck(array, ax + 1, ay + 1, ax + 1, j + 1) == 0)) || ((array[ax][j] == ' ') && (array[ax][ay] == 'r' || array[ax][ay] == 'q') && (blackcheck(array, ax + 1, ay + 1, ax + 1, j + 1) == 0)))
            {
                avilx[digits] = ax, avily[digits] = j;
                digits++;
            }
            else if (((array[ax][j] > 96 && array[ax][j] < 123) && (array[ax][ay] == 'R' || array[ax][ay] == 'Q') && (whitecheck(array, ax + 1, ay + 1, ax + 1, j + 1) == 0)) || ((array[ax][j] > 64 && array[ax][j] < 91) && (array[ax][ay] == 'r' || array[ax][ay] == 'q') && (blackcheck(array, ax + 1, ay + 1, ax + 1, j + 1) == 0)))
            {
                avilx[digits] = ax, avily[digits] = j;
                digits++;
                break;
            }
            else
            {
                break;
            }
        }
        for (int j = ay - 1; j >= 0; j--)
        {
            if (((array[ax][j] == ' ') && (array[ax][ay] == 'R' || array[ax][ay] == 'Q') && (whitecheck(array, ax + 1, ay + 1, ax + 1, j + 1) == 0)) || ((array[ax][j] == ' ') && (array[ax][ay] == 'r' || array[ax][ay] == 'q') && (blackcheck(array, ax + 1, ay + 1, ax + 1, j + 1) == 0)))
            {
                avilx[digits] = ax, avily[digits] = j;
                digits++;
            }
            else if (((array[ax][j] > 96 && array[ax][j] < 123) && (array[ax][ay] == 'R' || array[ax][ay] == 'Q') && (whitecheck(array, ax + 1, ay + 1, ax + 1, j + 1) == 0)) || (array[ax][j] > 64 && array[ax][j] < 91 && (array[ax][ay] == 'r' || array[ax][ay] == 'q') && (blackcheck(array, ax + 1, ay + 1, ax + 1, j + 1) == 0)))
            {
                avilx[digits] = ax, avily[digits] = j;
                digits++;
                break;
            }
            else
            {
                break;
            }
        }
        for (int i = ax + 1; i <= 7; i++)
        {
            if (((array[i][ay] == ' ') && (array[ax][ay] == 'R' || array[ax][ay] == 'Q') && (whitecheck(array, ax + 1, ay + 1, i + 1, ay + 1) == 0)) || ((array[i][ay] == ' ') && (array[ax][ay] == 'r' || array[ax][ay] == 'q') && (blackcheck(array, ax + 1, ay + 1, i + 1, ay + 1) == 0)))
            {
                avilx[digits] = i, avily[digits] = ay;
                digits++;
            }
            else if ((array[i][ay] > 96 && array[i][ay] < 123 && (array[ax][ay] == 'R' || array[ax][ay] == 'Q') && (whitecheck(array, ax + 1, ay + 1, i + 1, ay + 1) == 0)) || (array[i][ay] > 64 && array[i][ay] < 91 && (array[ax][ay] == 'r' || array[ax][ay] == 'q') && (blackcheck(array, ax + 1, ay + 1, i + 1, ay + 1) == 0)))
            {
                avilx[digits] = i, avily[digits] = ay;
                digits++;
                break;
            }
            else
            {
                break;
            }
        }
        for (int i = ax - 1; i >= 0; i--)
        {
            if (((array[i][ay] == ' ') && (array[ax][ay] == 'R' || array[ax][ay] == 'Q') && (whitecheck(array, ax + 1, ay + 1, i + 1, ay + 1) == 0)) || ((array[i][ay] == ' ') && (array[ax][ay] == 'r' || array[ax][ay] == 'q') && (blackcheck(array, ax + 1, ay + 1, i + 1, ay + 1) == 0)))
            {
                avilx[digits] = i, avily[digits] = ay;
                digits++;
            }
            else if ((array[i][ay] > 96 && array[i][ay] < 123 && (array[ax][ay] == 'R' || array[ax][ay] == 'Q') && (whitecheck(array, ax + 1, ay + 1, i + 1, ay + 1) == 0)) || (array[i][ay] > 64 && array[i][ay] < 91 && (array[ax][ay] == 'r' || array[ax][ay] == 'q') && (blackcheck(array, ax + 1, ay + 1, i + 1, ay + 1) == 0)))
            {
                avilx[digits] = i, avily[digits] = ay;
                digits++;
                break;
            }
            else
            {
                break;
            }
        }
    }
    else if (array[ax][ay] == 'N')
    {
        if (((array[ax + 2][ay + 1] == ' ' || (array[ax + 2][ay + 1] > 96 && array[ax + 2][ay + 1] < 123)) && ((ax + 2) < 8) && (ay + 1) < 8) && (whitecheck(array, ax + 1, ay + 1, ax + 3, ay + 2) == 0))
        {
            avilx[digits] = ax + 2, avily[digits] = ay + 1;
            digits++;
        }
        if (((array[ax + 2][ay - 1] == ' ' || (array[ax + 2][ay - 1] > 96 && array[ax + 2][ay - 1] < 123)) && ((ax + 2) < 8) && (ay - 1) >= 0) && (whitecheck(array, ax + 1, ay + 1, ax + 3, ay) == 0))
        {
            avilx[digits] = ax + 2, avily[digits] = ay - 1;
            digits++;
        }
        if (((array[ax - 2][ay + 1] == ' ' || (array[ax - 2][ay + 1] > 96 && array[ax - 2][ay + 1] < 123)) && ((ax - 2) >= 0) && (ay + 1) < 8) && (whitecheck(array, ax + 1, ay + 1, ax - 1, ay + 2) == 0))
        {
            avilx[digits] = ax - 2, avily[digits] = ay + 1;
            digits++;
        }
        if (((array[ax - 2][ay - 1] == ' ' || (array[ax - 2][ay - 1] > 96 && array[ax - 2][ay - 1] < 123)) && ((ax - 2) >= 0) && (ay - 1) >= 0) && (whitecheck(array, ax + 1, ay + 1, ax - 1, ay) == 0))
        {
            avilx[digits] = ax - 2, avily[digits] = ay - 1;
            digits++;
        }
        if (((array[ax + 1][ay - 2] == ' ' || (array[ax + 1][ay - 2] > 96 && array[ax + 1][ay - 2] < 123)) && ((ax + 1) < 8) && (ay - 2) >= 0) && (whitecheck(array, ax + 1, ay + 1, ax + 2, ay - 1) == 0))
        {
            avilx[digits] = ax + 1, avily[digits] = ay - 2;
            digits++;
        }
        if (((array[ax + 1][ay + 2] == ' ' || (array[ax + 1][ay + 2] > 96 && array[ax + 1][ay + 2] < 123)) && ((ax + 1) < 8) && (ay + 2) < 8) && (whitecheck(array, ax + 1, ay + 1, ax + 2, ay + 3) == 0))
        {
            avilx[digits] = ax + 1, avily[digits] = ay + 2;
            digits++;
        }
        if ((array[ax - 1][ay + 2] == ' ' || (array[ax - 1][ay + 2] > 96 && array[ax - 1][ay + 2] < 123)) && ((ax - 1) >= 0 && (ay + 2) < 8) && (whitecheck(array, ax + 1, ay + 1, ax, ay + 3) == 0))
        {
            avilx[digits] = ax - 1, avily[digits] = ay + 2;
            digits++;
        }
        if ((array[ax - 1][ay - 2] == ' ' || (array[ax - 1][ay - 2] > 96 && array[ax - 1][ay - 2] < 123)) && ((ax - 1) >= 0 && (ay - 2) >= 0) && (whitecheck(array, ax + 1, ay + 1, ax, ay - 1) == 0))
        {
            avilx[digits] = ax - 1, avily[digits] = ay - 2;
            digits++;
        }
    }
    else if (array[ax][ay] == 'p')
    {
        if (ax == 1)
        {
            if (array[ax + 1][ay] == ' ' && (blackcheck(array, ax + 1, ay + 1, ax + 2, ay + 1) == 0))
            {
                avilx[digits] = ax + 1, avily[digits] = ay;
                digits++;
                if (array[ax + 2][ay] == ' ')
                {
                    avilx[digits] = ax + 2, avily[digits] = ay;
                    digits++;
                }
            }
            if (array[ax + 1][ay - 1] > 64 && array[ax + 1][ay - 1] < 91 && (ay - 1) >= 0 && (blackcheck(array, ax + 1, ay + 1, ax + 2, ay) == 0))
            {
                avilx[digits] = ax + 1, avily[digits] = ay - 1;
                digits++;
            }
            if (array[ax + 1][ay + 1] > 64 && array[ax + 1][ay + 1] < 91 && (ay + 1) < 8 && (blackcheck(array, ax + 1, ay + 1, ax + 2, ay + 2) == 0))
            {
                avilx[digits] = ax + 1, avily[digits] = ay + 1;
                digits++;
            }
        }
        else
        {
            if (array[ax + 1][ay] == ' ' && (ax + 1) > 0 && (blackcheck(array, ax + 1, ay + 1, ax, ay + 1) == 0))
            {
                avilx[digits] = ax + 1, avily[digits] = ay;
                digits++;
            }
            if (array[ax + 1][ay - 1] > 64 && array[ax + 1][ay - 1] < 91 && (ay - 1) >= 0 && (ax + 1) < 8 && (blackcheck(array, ax + 1, ay + 1, ax + 2, ay) == 0))
            {
                avilx[digits] = ax + 1, avily[digits] = ay - 1;
                digits++;
            }
            if (array[ax + 1][ay + 1] > 64 && array[ax + 1][ay + 1] < 91 && (ay + 1) < 8 && (ax + 1) < 8 && (blackcheck(array, ax + 1, ay + 1, ax + 2, ay + 2) == 0))
            {
                avilx[digits] = ax + 1, avily[digits] = ay + 1;
                digits++;
            }
        }
    }
    else if (array[ax][ay] == 'n')
    {
        if (((array[ax + 2][ay + 1] == ' ' || (array[ax + 2][ay + 1] > 64 && array[ax + 2][ay + 1] < 91)) && (ax + 2) < 8 && (ay + 1) < 8) && (blackcheck(array, ax + 1, ay + 1, ax + 3, ay + 2) == 0))
        {
            avilx[digits] = ax + 2, avily[digits] = ay + 1;
            digits++;
        }
        if (((array[ax + 2][ay - 1] == ' ' || (array[ax + 2][ay - 1] > 64 && array[ax + 2][ay - 1] < 91)) && (ax + 2) < 8 && (ay - 1) >= 0) && (blackcheck(array, ax + 1, ay + 1, ax + 3, ay) == 0))
        {
            avilx[digits] = ax + 2, avily[digits] = ay - 1;
            digits++;
        }
        if (((array[ax - 2][ay + 1] == ' ' || (array[ax - 2][ay + 1] > 64 && array[ax - 2][ay + 1] < 91)) && (ax - 2) >= 0 && (ay + 1) < 8) && (blackcheck(array, ax + 1, ay + 1, ax - 1, ay + 2) == 0))
        {
            avilx[digits] = ax - 2, avily[digits] = ay + 1;
            digits++;
        }
        if (((array[ax - 2][ay - 1] == ' ' || (array[ax - 2][ay - 1] > 64 && array[ax - 2][ay - 1] < 91)) && (ax - 2) >= 0 && (ay - 1) >= 0) && (blackcheck(array, ax + 1, ay + 1, ax - 1, ay) == 0))
        {
            avilx[digits] = ax - 2, avily[digits] = ay - 1;
            digits++;
        }
        if (((array[ax + 1][ay - 2] == ' ' || (array[ax + 1][ay - 2] > 64 && array[ax + 1][ay - 2] < 91)) && (ax + 1) < 8 && (ay - 2) >= 0) && (blackcheck(array, ax + 1, ay + 1, ax + 2, ay - 1) == 0))
        {
            avilx[digits] = ax + 1, avily[digits] = ay - 2;
            digits++;
        }
        if (((array[ax + 1][ay + 2] == ' ' || (array[ax + 1][ay + 2] > 64 && array[ax + 1][ay + 2] < 91)) && (ax + 1) < 8 && (ay + 2) < 8) && (blackcheck(array, ax + 1, ay + 1, ax + 2, ay + 3) == 0))
        {
            avilx[digits] = ax + 1, avily[digits] = ay + 2;
            digits++;
        }
        if (((array[ax - 1][ay + 2] == ' ' || (array[ax - 1][ay + 2] > 64 && array[ax - 1][ay + 2] < 91)) && (ax - 1) >= 0 && (ay + 2) < 8) && (blackcheck(array, ax + 1, ay + 1, ax, ay + 3) == 0))
        {
            avilx[digits] = ax - 1, avily[digits] = ay + 2;
            digits++;
        }
        if (((array[ax - 1][ay - 2] == ' ' || (array[ax - 1][ay - 2] > 64 && array[ax - 1][ay - 2] < 91)) && (ax - 1) >= 0 && (ay - 2) >= 0) && (blackcheck(array, ax + 1, ay + 1, ax, ay - 1) == 0))
        {
            avilx[digits] = ax - 1, avily[digits] = ay - 2;
            digits++;
        }
    }
    else if (array[ax][ay] == 'K')
    {
        if (ax == 7 && ay == 4 && wc == 0)
        {
            if (array[ax][ay + 1] == ' ' && (array[ax][ay + 2] == ' ') && (array[ax][ay + 3] == 'R') && (whitecheck(array, ax + 1, ay + 1, ax + 1, ay + 2) == 0) && (whitecheck(array, ax + 1, ay + 1, ax + 1, ay + 3) == 0))
            {
                avilx[digits] = ax, avily[digits] = ay + 2;
                digits++;
            }
            if (array[ax][ay - 1] == ' ' && (array[ax][ay - 2] == ' ') && (array[ax][ay - 3] == ' ') && (array[ax][ay - 4] == 'R') && (whitecheck(array, ax + 1, ay + 1, ax + 1, ay) == 0) && (whitecheck(array, ax + 1, ay + 1, ax + 1, ay - 1) == 0))
            {
                avilx[digits] = ax, avily[digits] = ay - 2;
                digits++;
            }
        }
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }
                else
                {
                    if ((array[ax + i][ay + j] == ' ' || (array[ax + i][ay + j] > 96 && array[ax + i][ay + j] < 123)) && (ax + i) >= 0 && (ax + i) < 8 && (ay + j) >= 0 && (ay + j) < 8 && (whitecheck(array, ax + 1, ay + 1, ax + i + 1, ay + j + 1) == 0))
                    {
                        avilx[digits] = ax + i, avily[digits] = ay + j;
                        digits++;
                    }
                }
            }
        }
    }
    else if (array[ax][ay] == 'k')
    {
        if (ax == 0 && ay == 4 && bc == 0)
        {
            if (array[ax][ay + 1] == ' ' && (array[ax][ay + 2] == ' ') && (array[ax][ay + 3] == 'r') && (blackcheck(array, ax + 1, ay + 1, ax + 1, ay + 2) == 0) && (blackcheck(array, ax + 1, ay + 1, ax + 1, ay + 3) == 0))
            {
                avilx[digits] = ax, avily[digits] = ay + 2;
                digits++;
            }
            if (array[ax][ay - 1] == ' ' && (array[ax][ay - 2] == ' ') && (array[ax][ay - 3] == ' ') && (array[ax][ay - 4] == 'r') && (blackcheck(array, ax + 1, ay + 1, ax + 1, ay) == 0) && (blackcheck(array, ax + 1, ay + 1, ax + 1, ay - 1) == 0))
            {
                avilx[digits] = ax, avily[digits] = ay - 2;
                digits++;
            }
        }
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }
                else
                {
                    if ((array[ax + i][ay + j] == ' ' || (array[ax + i][ay + j] > 64 && array[ax + i][ay + j] < 91)) && (ax + i) >= 0 && (ax + i) < 8 && (ay + j) >= 0 && (ay + j) < 8 && (blackcheck(array, ax + 1, ay + 1, ax + i + 1, ay + j + 1) == 0))
                    {
                        avilx[digits] = ax + i, avily[digits] = ay + j;
                        digits++;
                    }
                }
            }
        }
    }
}

int whitecheckmate(char array[8][8], int p, int q, int r, int s, int avilx[100], int avily[100], int wc, int bc)
{
    char t[2];
    t[0] = array[r - 1][s - 1];
    array[r - 1][s - 1] = array[p - 1][q - 1];
    array[p - 1][q - 1] = ' ';
    int d = 1;
    for (int i = 0; i <= 7; i++)
    {
        for (int j = 0; j <= 7; j++)
        {
            if (array[i][j] > 64 && array[i][j] < 91)
            {
                availble(array, i, j, avilx, avily, wc, bc);
                if (avilx[0] != -1)
                {
                    d = 0;
                }
                for (int i = 0; i < 100; i++)
                {
                    avilx[i] = -1, avily[i] = -1;
                }
            }
        }
    }
    array[p - 1][q - 1] = array[r - 1][s - 1];
    array[r - 1][s - 1] = t[0];
    if (d == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int blackcheckmate(char array[8][8], int p, int q, int r, int s, int avilx[100], int avily[100], int wc, int bc)
{
    char t[2];
    t[0] = array[r - 1][s - 1];
    array[r - 1][s - 1] = array[p - 1][q - 1];
    array[p - 1][q - 1] = ' ';
    int d = 1;
    for (int i = 0; i <= 7; i++)
    {
        for (int j = 0; j <= 7; j++)
        {
            if (array[i][j] > 96 && array[i][j] < 123)
            {
                availble(array, i, j, avilx, avily, wc, bc);
                if (avilx[0] != -1)
                {
                    d = 0;
                }
                for (int i = 0; i < 100; i++)
                {
                    avilx[i] = -1, avily[i] = -1;
                }
            }
        }
    }
    array[p - 1][q - 1] = array[r - 1][s - 1];
    array[r - 1][s - 1] = t[0];
    if (d == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void cboard(char array[8][8], char blackpieces[20], char whitepieces[20], int px, int py, int avilx[100], int avily[100], int bcm, int wcm, int wh)
{
    chessboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
    if (wh == 1)
    {
        printf("\n\t\t\t\t\tWhite won!!!");
    }
    else if (wh == 0)
    {
        printf("\n\t\t\t\t\tBlack won!!!");
    }
    else if (wh == -1)
    {
        printf("\n\t\t\t\t\tDraw!");
    }
    gotoxy(0,0);
}

void chess()
{
    hidecursor();
    rules1();
    int p = 0, q = 0, r = 0, s = 0, wh = -2, px = 8, py = 5, ax, ay, key;
    char pawn;
    char blackpieces[20] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char whitepieces[20] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int wc = 0, bc = 0, wcm = 0, bcm = 0;
    int avilx[100], avily[100];
    for (int i = 0; i < 100; i++)
    {
        avilx[i] = -1, avily[i] = -1;
    }
    char array[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    system("cls");
    for (int x = 0;; x++)
    {
        if (x % 2 == 0)
        {
        move:
            if (wcm == 1 || bcm == 1)
            {
                system("cls");
            }
            px = 8, py = 5, bcm = 0;
        move4:
            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
            for (int z = 0;; z++)
            {
                if (kbhit())
                {
                    key = getch();
                    if (key == 224)
                    {
                        key = getch();
                        if (key == 72)
                        {
                            if (px >= 2)
                            {
                                px--;
                            }
                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                        }
                        else if (key == 75)
                        {
                            if (py >= 2)
                            {
                                py--;
                            }
                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                        }
                        else if (key == 80)
                        {
                            if (px <= 7)
                            {
                                px++;
                            }
                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                        }
                        else if (key == 77)
                        {
                            if (py <= 7)
                            {
                                py++;
                            }
                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                        }
                    }
                    else if (key == 13)
                    {
                        if (array[px - 1][py - 1] > 64 && array[px - 1][py - 1] < 91)
                        {
                            ax = px - 1, ay = py - 1;
                            availble(array, ax, ay, avilx, avily, wc, bc);
                            if (avilx[0] == -1)
                            {
                                goto move;
                            }
                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                            for (int y = 0;; y++)
                            {
                            move1:
                                if (kbhit())
                                {
                                    key = getch();
                                    if (key == 224)
                                    {
                                        key = getch();
                                        if (key == 72)
                                        {
                                            if (px >= 2)
                                            {
                                                px--;
                                            }
                                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                                        }
                                        else if (key == 75)
                                        {
                                            if (py >= 2)
                                            {
                                                py--;
                                            }
                                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                                        }
                                        else if (key == 80)
                                        {
                                            if (px <= 7)
                                            {
                                                px++;
                                            }
                                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                                        }
                                        else if (key == 77)
                                        {
                                            if (py <= 7)
                                            {
                                                py++;
                                            }
                                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                                        }
                                    }
                                    else if (key == 27)
                                    {
                                        for (int i = 0; i < 100; i++)
                                        {
                                            avilx[i] = -1, avily[i] = -1;
                                        }
                                        goto move4;
                                    }
                                    else if (key == 13)
                                    {
                                        for (int i = 0; i <= 30; i++)
                                        {
                                            if (i == 30)
                                            {
                                                goto move1;
                                            }
                                            else
                                            {
                                                if (avilx[i] == px - 1 && avily[i] == py - 1)
                                                {
                                                    p = ax, q = ay, r = px - 1, s = py - 1;
                                                    break;
                                                }
                                            }
                                        }
                                        for (int i = 0; i < 100; i++)
                                        {
                                            avilx[i] = -1, avily[i] = -1;
                                        }
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        else
                        {
                            goto move;
                        }
                    }
                }
            }
            if (blackcheck(array, p + 1, q + 1, r + 1, s + 1) == 1)
            {
                bc++, bcm++;
                if (blackcheckmate(array, p + 1, q + 1, r + 1, s + 1, avilx, avily, wc, bc) == 1)
                {
                    wh = 1;
                    goto end;
                }
            }
            if (blackcheck(array, p + 1, q + 1, r + 1, s + 1) == 0)
            {
                if (blackcheckmate(array, p + 1, q + 1, r + 1, s + 1, avilx, avily, wc, bc) == 1)
                {
                    wh = -1;
                    goto end;
                }
            }
            if (array[r][s] != ' ')
            {
                for (int w = 0; w < 16; w++)
                {
                    if (blackpieces[w] == ' ')
                    {
                        blackpieces[w] = array[r][s];
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            if (array[ax][ay] == 'P' && r == 0)
            {
                for (int w = 1;; w++)
                {
                    printf("choose a piece to be replaced with pawn : Q,B,N,R\n");
                    scanf(" %c", &pawn);
                    if (pawn == 'Q')
                    {
                        array[r][s] = 'Q';
                        break;
                    }
                    else if (pawn == 'B')
                    {
                        array[r][s] = 'B';
                        break;
                    }
                    else if (pawn == 'N')
                    {
                        array[r][s] = 'N';
                        break;
                    }
                    else if (pawn == 'R')
                    {
                        array[r][s] = 'R';
                        break;
                    }
                    else
                    {
                        printf("invalid piece\n");
                        continue;
                    }
                }
                array[p][q] = ' ';
                system("cls");
            }
            else if (array[ax][ay] == 'K' && (s - q == 2 || q - s == 2))
            {
                if (s - q == 2)
                {
                    array[r][s] = array[p][q];
                    array[r][s - 1] = 'R';
                    array[p][q] = ' ';
                    array[r][s + 1] = ' ';
                }
                else if (q - s == 2)
                {
                    array[r][s] = array[p][q];
                    array[r][s + 1] = 'R';
                    array[p][q] = ' ';
                    array[r][s - 2] = ' ';
                }
            }
            else
            {
                array[r][s] = array[p][q];
                array[p][q] = ' ';
            }
        }
        else
        {
        move2:
            if (wcm == 1 || bcm == 1)
            {
                system("cls");
            }
            px = 1, py = 5, wcm = 0;
        move5:
            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
            for (int z = 0;; z++)
            {
                if (kbhit())
                {
                    key = getch();
                    if (key == 224)
                    {
                        key = getch();
                        if (key == 72)
                        {
                            if (px >= 2)
                            {
                                px--;
                            }
                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                        }
                        else if (key == 75)
                        {
                            if (py >= 2)
                            {
                                py--;
                            }
                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                        }
                        else if (key == 80)
                        {
                            if (px <= 7)
                            {
                                px++;
                            }
                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                        }
                        else if (key == 77)
                        {
                            if (py <= 7)
                            {
                                py++;
                            }
                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                        }
                    }
                    else if (key == 13)
                    {
                        if (array[px - 1][py - 1] > 96 && array[px - 1][py - 1] < 123)
                        {
                            ax = px - 1, ay = py - 1;
                            availble(array, ax, ay, avilx, avily, wc, bc);
                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                            if (avilx[0] == -1)
                            {
                                goto move2;
                            }
                            for (int y = 0;; y++)
                            {
                            move3:
                                if (kbhit())
                                {
                                    key = getch();
                                    if (key == 224)
                                    {
                                        key = getch();
                                        if (key == 72)
                                        {
                                            if (px >= 2)
                                            {
                                                px--;
                                            }
                                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                                        }
                                        else if (key == 75)
                                        {
                                            if (py >= 2)
                                            {
                                                py--;
                                            }
                                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                                        }
                                        else if (key == 80)
                                        {
                                            if (px <= 7)
                                            {
                                                px++;
                                            }
                                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                                        }
                                        else if (key == 77)
                                        {
                                            if (py <= 7)
                                            {
                                                py++;
                                            }
                                            cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
                                        }
                                    }
                                    else if (key == 27)
                                    {
                                        for (int i = 0; i < 100; i++)
                                        {
                                            avilx[i] = -1, avily[i] = -1;
                                        }
                                        goto move5;
                                    }
                                    else if (key == 13)
                                    {
                                        for (int i = 0; i <= 30; i++)
                                        {
                                            if (i == 30)
                                            {
                                                goto move3;
                                            }
                                            else
                                            {
                                                if (avilx[i] == px - 1 && avily[i] == py - 1)
                                                {
                                                    p = ax, q = ay, r = px - 1, s = py - 1;
                                                    break;
                                                }
                                            }
                                        }
                                        for (int i = 0; i < 100; i++)
                                        {
                                            avilx[i] = -1, avily[i] = -1;
                                        }
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        else
                        {
                            goto move2;
                        }
                    }
                }
            }
            if (whitecheck(array, p + 1, q + 1, r + 1, s + 1) != 0)
            {
                wc++, wcm++;
                if (whitecheckmate(array, p + 1, q + 1, r + 1, s + 1, avilx, avily, wc, bc) == 1)
                {
                    wh = 0;
                    goto end;
                }
            }
            if (whitecheck(array, p + 1, q + 1, r + 1, s + 1) == 0)
            {
                if (whitecheckmate(array, p + 1, q + 1, r + 1, s + 1, avilx, avily, wc, bc) == 1)
                {
                    wh = -1;
                    goto end;
                }
            }
            if (array[r][s] != ' ')
            {
                for (int w = 0; w < 16; w++)
                {
                    if (whitepieces[w] == ' ')
                    {
                        whitepieces[w] = array[r][s];
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            if (array[ax][ay] == 'p' && r == 7)
            {
                for (int w = 1;; w++)
                {
                    printf("choose a piece to be replaced with pawn : q,b,n,r");
                    scanf(" %c", &pawn);
                    if (pawn == 'q')
                    {
                        array[r][s] = 'q';
                        break;
                    }
                    else if (pawn == 'b')
                    {
                        array[r][s] = 'b';
                        break;
                    }
                    else if (pawn == 'n')
                    {
                        array[r][s] = 'n';
                        break;
                    }
                    else if (pawn == 'r')
                    {
                        array[r][s] = 'r';
                        break;
                    }
                    else
                    {
                        printf("invalid piece\n");
                        continue;
                    }
                }
                array[p][q] = ' ';
                system("cls");
            }
            else if (array[ax][ay] == 'k' && (s - q == 2 || q - s == 2))
            {
                if (s - q == 2)
                {
                    array[r][s] = array[p][q];
                    array[r][s - 1] = 'r';
                    array[p][q] = ' ';
                    array[r][s + 1] = ' ';
                }
                else if (q - s == 2)
                {
                    array[r][s] = array[p][q];
                    array[r][s + 1] = 'r';
                    array[p][q] = ' ';
                    array[r][s - 2] = ' ';
                }
            }
            else
            {
                array[r][s] = array[p][q];
                array[p][q] = ' ';
            }
        }
    }
end:
    system("cls");
    cboard(array, blackpieces, whitepieces, px, py, avilx, avily, bcm, wcm, wh);
    sleep(1);
    system("cls");
    MoveCursorToXY(50, 20);
    printf(bw "Thank you for playing!!!!" reset);
    gotoxy(0, 0);
}

#endif