#ifndef _PONG_H_
#define _PONG_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include <string.h>

#define redl  "\e[0;31m"
#define greenl "\e[0;32m"
#define bluel "\e[0;34m"
#define yellowl "\e[0;33m"
#define whitel "\e[0;37m"
#define bw "\e[1;37m"
#define redbg "\e[0;41m"
#define greenbg "\e[0;42m"
#define yellowbg "\e[0;43m"
#define bluebg "\e[0;44m"
#define whitebg "\e[0;47m"
#define reset "\e[0;0m"

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void board(char array[89][21], int px, int py, int qx, int qy, int bx, int by, int pscore, int cscore, char player[11])
{
    for (int i = 0; i < 12; i++)
    {
        printf("\n");
    }
    for (int k = 0; k < 50; k++)
    {
        printf(" ");
    }
    for (int i = 0; i < 20; i++)
    {
        printf(redbg " " reset);
    }
    for (int i = 0; i < 20; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < 16; i++)
    {
        printf(yellowbg " " reset);
    }
    for (int i = 0; i < 20; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < 17; i++)
    {
        printf(bluebg " " reset);
    }
    printf("\n");
    for (int k = 0; k < 50; k++)
    {
        printf(" ");
    }
    printf(redbg "   %s : %d   " reset, player, pscore);
    for (int i = 0; i < 20; i++)
    {
        printf(" ");
    }
    printf(yellowbg "   Round - %d    " reset, pscore + cscore + 1);
    for (int i = 0; i < 20; i++)
    {
        printf(" ");
    }
    printf(bluebg "  computer : %d   " reset, cscore);
    printf("\n");
    for (int k = 0; k < 50; k++)
    {
        printf(" ");
    }
    for (int i = 0; i < 20; i++)
    {
        printf(redbg " " reset);
    }
    for (int i = 0; i < 20; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < 16; i++)
    {
        printf(yellowbg " " reset);
    }
    for (int i = 0; i < 20; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < 17; i++)
    {
        printf(bluebg " " reset);
    }
    printf("\n");
    for (int i = 0; i < 50; i++)
    {
        printf(" ");
    }
    printf(whitebg "  " reset);
    for (int i = 0; i <= 88; i++)
    {
        printf(whitebg " " reset);
    }
    printf(whitebg "  " reset);
    printf("\n");
    for (int i = 0; i < 21; i++)
    {
        for (int i = 0; i < 50; i++)
        {
            printf(" ");
        }
        printf(whitebg "  " reset);
        for (int j = 0; j <= 88; j++)
        {
            if ((j == px && i == py) || (j == px && i == py + 1) || (j == px && i == py + 2) || (j == px && i == py + 3) || (j == px && i == py + 4) || (j == px + 1 && i == py) || (j == px + 1 && i == py + 1) || (j == px + 1 && i == py + 2) || (j == px + 1 && i == py + 3) || (j == px + 1 && i == py + 4))
            {
                printf(redl "%c" reset, 219);
            }
            else if ((j == qx && i == qy) || (j == qx && i == qy + 1) || (j == qx && i == qy + 2) || (j == qx && i == qy + 3) || (j == qx && i == qy + 4) || (j == qx + 1 && i == qy) || (j == qx + 1 && i == qy + 1) || (j == qx + 1 && i == qy + 2) || (j == qx + 1 && i == qy + 3) || (j == qx + 1 && i == qy + 4))
            {
                printf(bluel "%c" reset, 219);
            }
            else if (j == bx && i == by)
            {
                printf(greenbg "0" reset);
            }
            else
            {
                printf(greenbg "%c" reset, array[j][i]);
            }
        }
        printf(whitebg "  " reset);
        printf("\n");
    }
    for (int i = 0; i < 50; i++)
    {
        printf(" ");
    }
    printf(whitebg "  " reset);
    for (int i = 0; i <= 88; i++)
    {
        printf(whitebg " " reset);
    }
    printf(whitebg "  " reset);
    printf("\n");
}

void arrayfill(char array[89][21])
{
    for (int i = 0; i < 21; i++)
    {
        if (i == 10)
        {
            for (int j = 0; j <= 88; j++)
            {
                if (j == 44)
                {
                    array[j][i] = 254;
                }
                else
                {
                    array[j][i] = '-';
                }
            }
        }
        else
        {
            for (int j = 0; j <= 88; j++)
            {
                if (j == 44)
                {
                    array[j][i] = 254;
                }
                else
                {
                    array[j][i] = ' ';
                }
            }
        }
    }
}

void com(char array[89][21], int px, int py, int qx, int qy, int bx, int by, int pscore, int cscore, char player[11])
{
    gotoxy(0, 0);
    board(array, px, py, qx, qy, bx, by, pscore, cscore, player);
}

int random()
{
    srand(time(0));
    int lower = 4, upper = 16;
    int i = (rand() % (upper - lower + 1)) + lower;
    return i;
}

void rules(char name[100], char player[11], int *toss)
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
    printf("Welcome to Ping-pong game!!!");
    for (int i = 0; i < 21; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < 50; i++)
    {
        printf("*");
    }
    printf("\n");
    sleep(1);
    printf("   Rules:\n");
    printf("%c It is a single player game.\n", 26);
    printf("%c The player is asked to enter their name(maximum of 10 letters).\n", 26);
    printf("%c The payer is asked to choose the toss.\n", 26);
    printf("%c Enter h or H to choose Heads.\n", 26);
    printf("%c Enter t or T to choose Tails.\n", 26);
    printf("%c In the game,the ball is represented by a 0.\n", 26);
    printf("%c Every time the ball appears at random positions on the screen.\n", 26);
    printf("%c Player has ", 26);
    printf(redl "red" reset);
    printf(" bat and computer has ");
    printf(bluel "blue" reset);
    printf(" bat.\n");
    printf("%c The bat is restricted to move only vertically to botth player and computer.\n", 26);
    printf("%c The bat of computer continuously moves up and downward directions.\n", 26);
    printf("%c This is a 5-pointer game,who reaches five points first wins the game.\n", 26);
    printf("%c Press Up arrow in your keyboard to move the bat upwards.\n", 26);
    printf("%c Press Down arrow in your keyboard to move the bat downwards.\n", 26);
    printf("%c Press Space to Pause/Resume the game.\n", 26);
    printf("%c Press E or e to end the game.\n", 26);
    printf("%c After pressing E or e,it asks for a confirmation(press Y or y to end the game) or (press any key to continue the game).\n", 26);
    printf("%c After ending the game,match result will be decided by the comparison of points.\n", 26);
    printf("%c Scores are displayed on each corner on the Board.\n", 26);
    printf("%c Round number is displayed at the center of the Board.\n", 26);
    printf("%c After reading the rules and entering the name,press any key to start the game.\n", 26);
    printf("%c Good luck,Try to beat the computer!!!\n", 26);
    sleep(1);
    move1:
    printf("\n\nEnter Player name:");
    gets(name);
    if(name[0]=='\0')
    {
        goto move1;
    }
    int l = strlen(name);
    for (int i = 0; i < 10; i++)
    {
        if (i >= l)
        {
            player[i] = ' ';
        }
        else
        {
            player[i] = name[i];
        }
    }
    player[10] = '\0';
    printf("\n");
    char a;
label2:
    printf("\nchoose Heads/Tails:");
    scanf("%c", &a);
    if (a == 'h' || a == 'H')
    {
        srand(time(0));
        int lower = 0, upper = 1;
        int i = (rand() % (upper - lower + 1)) + lower;
        if (i == 1)
        {
            printf(redl "%s won the toss!!\n\n" reset, name);
            *toss = 1;
        }
        else
        {
            printf(bluel "%s lost the toss!!\n\n" reset, name);
            *toss = 0;
        }
    }
    else if (a == 't' || a == 'T')
    {
        srand(time(0));
        int lower = 0, upper = 1;
        int i = (rand() % (upper - lower + 1)) + lower;
        if (i == 0)
        {
            printf(redl "%s won the toss!!\n\n" reset, player);
            *toss = 1;
        }
        else
        {
            printf(bluel "%s lost the toss!!\n\n" reset, player);
            *toss = 0;
        }
    }
    else
    {
        goto label2;
    }
    system("pause");
    printf("\e[1;1H\e[2J");
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void MoveCursorToXY(unsigned short x, unsigned short y) {
	COORD coord = (COORD){x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void pingpong()
{
    hidecursor();
    char array[89][21], name[100], player[11];
    int px = 1, py = 8, qx = 86, qy = 8, bx, by, h = 1, v = 0, c = 0, key, game, pscore = 0, cscore = 0, toss;
    arrayfill(array);
    rules(name, player, &toss);
    if (toss == 1)
    {
        bx = 4, by = random();
        h = 0, v = 0;
    }
    else
    {
        bx = 84;
        by = random();
        h = 1, v = 0;
    }
    board(array, px, py, qx, qy, bx, by, pscore, cscore, player);
    printf("\n");
    for (int k = 0; k < 50; k++)
    {
        printf(" ");
    }
    system("pause");
    system("cls");
    for (int i = 0;; i++)
    {
        px = 1, py = 8, qx = 86, qy = 8, c = 0;
        if (i != 0)
        {
            com(array, px, py, qx, qy, bx, by, pscore, cscore, player);
            printf("\n");
            for (int k = 0; k < 50; k++)
            {
                printf(" ");
            }
            system("pause");
            system("cls");
        }
        for (int j = 0;; j++)
        {
        label:
            if (h % 2 == 1 && v % 2 == 0)
            {
                bx--;
                by--;
            }
            else if (h % 2 == 1 && v % 2 == 1)
            {
                bx--;
                by++;
            }
            else if (h % 2 == 0 && v % 2 == 0)
            {
                bx++;
                by--;
            }
            else if (h % 2 == 0 && v % 2 == 1)
            {
                bx++;
                by++;
            }
            if (c % 2 == 0)
            {
                if (qy > 1)
                {
                    qy -= 2;
                }
                else
                {
                    c++;
                }
            }
            else
            {
                if (qy < 16)
                {
                    qy += 2;
                }
                else
                {
                    c++;
                }
            }
            if (kbhit())
            {
                key = getch();
                if (key == 224)
                {
                    key = getch();
                    if (key == 72)
                    {
                        if (py > 0)
                        {
                            py--;
                        }
                    }
                    else if (key == 80)
                    {
                        if (py < 16 )
                        {
                            py++;
                        }
                    }
                }
                else if (key == 32)
                {
                    for (int k = 0;; k++)
                    {
                        int play = getch();
                        if (play == 32)
                        {
                            goto label;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
                else if (key == 69 || key == 101)
                {
                    printf("\n");
                    for (int k = 0; k < 50; k++)
                    {
                        printf(" ");
                    }
                    printf("Do you really want to end the game?");
                    char end1 = getch();
                    if (end1 == 'y' || end1 == 'Y')
                    {
                        if (pscore > cscore)
                        {
                            game = 1;
                        }
                        else if (pscore == cscore)
                        {
                            game = (-1);
                        }
                        else
                        {
                            game = 0;
                        }
                        goto label1;
                    }
                    else
                    {
                        goto label;
                    }
                }
            }
            if (bx == 0)
            {
                cscore++;
                com(array, px, py, qx, qy, bx, by, pscore, cscore, player);
                printf("\n");
                for (int k = 0; k < 50; k++)
                {
                    printf(" ");
                }
                printf(bluel "computer won the round-%d" reset, cscore + pscore);
                printf("\n");
                printf("\n");
                if (cscore == 5)
                {
                    game = 0;
                    goto label1;
                }
                if (pscore == 5)
                {
                    game = 1;
                    goto label1;
                }
                for (int k = 0; k < 50; k++)
                {
                    printf(" ");
                }
                system("pause");
                system("cls");
                bx = 84, by = random();
                h = 1, v = 0;
                break;
            }
            else if (bx == 88)
            {
                pscore++;
                com(array, px, py, qx, qy, bx, by, pscore, cscore, player);
                printf("\n");
                for (int k = 0; k < 50; k++)
                {
                    printf(" ");
                }
                printf(redl "%s won the round-%d\n" reset, name, cscore + pscore);
                printf("\n");
                printf("\n");
                if (cscore == 5)
                {
                    game = 0;
                    goto label1;
                }
                if (pscore == 5)
                {
                    game = 1;
                    goto label1;
                }
                for (int k = 0; k < 50; k++)
                {
                    printf(" ");
                }
                system("pause");
                system("cls");
                bx = 4, by = random();
                h = 0, v = 0;
                break;
            }
            else if (((bx - 1 == px && by - 1 == py) || (bx - 1 == px && by - 1 == py + 1) || (bx - 1 == px && by - 1 == py + 2) || (bx - 1 == px && by - 1 == py + 3) || (bx - 1 == px && by - 1 == py + 4)) && h % 2 == 1 && v % 2 == 0)
            {
                h++;
            }
            else if (((bx - 1 == px && by + 1 == py) || (bx - 1 == px && by + 1 == py + 1) || (bx - 1 == px && by + 1 == py + 2) || (bx - 1 == px && by + 1 == py + 3) || (bx - 1 == px && by + 1 == py + 4)) && h % 2 == 1 && v % 2 == 1)
            {
                h++;
            }
            else if (((bx + 1 == qx && by - 1 == qy) || (bx + 1 == qx && by - 1 == qy + 1) || (bx + 1 == qx && by - 1 == qy + 2) || (bx + 1 == qx && by - 1 == qy + 3) || (bx + 1 == qx && by - 1 == qy + 4)) && h % 2 == 0 && v % 2 == 0)
            {
                h++;
            }
            else if (((bx + 1 == qx && by + 1 == qy) || (bx + 1 == qx && by + 1 == qy + 1) || (bx + 1 == qx && by + 1 == qy + 2) || (bx + 1 == qx && by + 1 == qy + 3) || (bx + 1 == qx && by + 1 == qy + 4)) && h % 2 == 0 && v % 2 == 1)
            {
                h++;
            }
            else if (by == 0 || by == 20)
            {
                v++;
            }
            com(array, px, py, qx, qy, bx, by, pscore, cscore, player);
        }
    }
label1:
    if (game == 1)
    {
        printf("\n");
        for (int k = 0; k < 50; k++)
        {
            printf(" ");
        }
        printf(redl "%s won!!" reset, name);
    }
    else if (game == 0)
    {
        printf("\n");
        for (int k = 0; k < 50; k++)
        {
            printf(" ");
        }
        printf(bluel "%s lost!!!" reset, name);
    }
    else
    {
        printf("\n");
        for (int k = 0; k < 50; k++)
        {
            printf(" ");
        }
        printf(yellowl "Draw!" reset);
    }
    sleep(1);
    system("cls");
    MoveCursorToXY(50, 20);
    printf(bw "Thank you for playing!!!!" reset);
}

#endif