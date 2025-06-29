#include <stdio.h>
#include <stdlib.h>
#include "pingpong.h"
#include "chess.h"
void choice();
void buttons(int i);
void LoadingScreen();

int main()
{
    int key,k,i;
    system("cls");
    for (int j = 0;; j++)
    {
        choice();
        buttons(i);
        key = getch();
        if (key == 224)
        {
            key = getch();
            if(key==75)
            {
                if(i%2==1)
                {
                    i++;
                }
            }
            else if(key==77)
            {
                if(i%2==0)
                {
                    i++;
                }
            }
        }
        else if(key==13)
        {
            if(i%2==0)
            {
                k=1;
                break;
            }
            else
            {
                k=0;
                break;
            }
        }
    }
    system("cls");
    LoadingScreen();
    if(k==1)
    {
        gotoxy(0,0);
        chess();
    }
    else
    {
        gotoxy(0,0);
        pingpong();
    }
    return 0;
}

void LoadingScreen() {
	MoveCursorToXY(33, 19);
	printf("Loading...");
	MoveCursorToXY(30, 20);
	unsigned short i;
	for(i=1;i<=100;i++) {
		Sleep(100);
		printf("%c", 178);
	}
    sleep(1);
	system("cls");
}

void choice()
{
    hidecursor();
    gotoxy(0,0);
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
    printf("Welcome to Our Project!!!");
    for (int i = 0; i < 21; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < 50; i++)
    {
        printf("*");
    }
    printf("\n\n\n");
    printf("%c IN this project,we created two Games using c wthout graphics.\n", 26);
    printf("%c You can access the games by selecting on the buttons under the display of the respective boards.\n", 26);
    printf("%c You can change the selction using arrow keys in your keyboard.\n", 26);
    printf("%c After selecting the game,press enter to enter the game.\n", 26);
    printf("\n\n\n\n");
    printf("\n");
    printf("\t\t\t");
    for (int i = 0; i < 46; i++)
    {
        printf("%c", 220);
    }
    printf("\t\t\t\t\t");
    for (int i = 0; i < 69; i++)
    {
        printf("%c", 219);
    }
    printf("\n");
    printf("\t\t\t");
    printf("%c%c", 219, 219);
    for (int i = 0; i < 42; i++)
    {
        printf("%c", 223);
    }
    printf("%c%c", 219, 219);
    printf("\t\t\t\t\t");
    printf("%c%c", 219, 219);
    for (int i = 0; i < 65; i++)
    {
        if (i == 33)
        {
            printf(greenbg "%c" reset, 254);
        }
        else
        {
            printf(greenbg " " reset);
        }
    }
    printf("%c%c", 219, 219);
    printf("\n");
    for (int k = 0; k < 4; k++)
    {
        if (k == 1)
        {
            printf("\t\t\t");
            printf("%c%c ", 219, 219);
            for (int i = 0; i < 4; i++)
            {
                printf("%c%c%c%c%c     ", 219, 219, 219, 219, 219);
            }
            printf(" %c%c", 219, 219);
            printf("\t\t\t\t\t");
            printf("%c%c", 219, 219);
            for (int i = 0; i < 65; i++)
            {
                if (i == 33)
                {
                    printf(greenbg "%c" reset, 254);
                }
                else
                {
                    printf(greenbg " " reset);
                }
            }
            printf("%c%c", 219, 219);
            printf("\n");
            printf("\t\t\t");
            printf("%c%c ", 219, 219);
            for (int i = 0; i < 4; i++)
            {
                printf("%c%c%c%c%c     ", 219, 219, 219, 219, 219);
            }
            printf(" %c%c", 219, 219);
            printf("\t\t\t\t\t");
            printf("%c%c", 219, 219);
            for (int i = 0; i < 65; i++)
            {
                if (i == 33)
                {
                    printf(greenbg "%c" reset, 254);
                }
                else
                {
                    printf(greenbg " " reset);
                }
            }
            printf("%c%c", 219, 219);
            printf("\n");
            printf("\t\t\t");
            printf("%c%c ", 219, 219);
            for (int i = 0; i < 4; i++)
            {
                printf("     %c%c%c%c%c", 219, 219, 219, 219, 219);
            }
            printf(" %c%c", 219, 219);
            printf("\t\t\t\t\t");
            printf(greenbg "%c%c " reset, 219, 219);
            printf(redbg "  " reset);
            for (int i = 0; i < 59; i++)
            {
                if (i == 30)
                {
                    printf(greenbg "%c" reset, 254);
                }
                else
                {
                    printf(greenbg " " reset);
                }
            }
            printf(bluebg "  " reset);
            printf(greenbg " %c%c" reset, 219, 219);
            printf("\n");
            printf("\t\t\t");
            printf("%c%c ", 219, 219);
            for (int i = 0; i < 4; i++)
            {
                printf("     %c%c%c%c%c", 219, 219, 219, 219, 219);
            }
            printf(" %c%c", 219, 219);
            printf("\t\t\t\t\t");
            printf(greenbg "%c%c " reset, 219, 219);
            printf(redbg "  " reset);
            for (int i = 0; i < 59; i++)
            {
                if (i == 30)
                {
                    printf(greenbg "%c" reset, 254);
                }
                else
                {
                    printf(greenbg " " reset);
                }
            }
            printf(bluebg "  " reset);
            printf(greenbg " %c%c" reset, 219, 219);
            printf("\n");
        }
        else if (k == 2)
        {
            printf("\t\t\t");
            printf("%c%c ", 219, 219);
            for (int i = 0; i < 4; i++)
            {
                printf("%c%c%c%c%c     ", 219, 219, 219, 219, 219);
            }
            printf(" %c%c", 219, 219);
            printf("\t\t\t\t\t");
            printf(greenbg "%c%c " reset, 219, 219);
            printf(redbg "  " reset);
            for (int i = 0; i < 59; i++)
            {
                if (i == 30)
                {
                    printf(greenbg "%c" reset, 254);
                }
                else
                {
                    printf(greenbg " " reset);
                }
            }
            printf(bluebg "  " reset);
            printf(greenbg " %c%c" reset, 219, 219);
            printf("\n");
            printf("\t\t\t");
            printf("%c%c ", 219, 219);
            for (int i = 0; i < 4; i++)
            {
                printf("%c%c%c%c%c     ", 219, 219, 219, 219, 219);
            }
            printf(" %c%c", 219, 219);
            printf("\t\t\t\t\t");
            printf(greenbg "%c%c " reset, 219, 219);
            printf(redbg "  " reset);
            for (int i = 0; i < 59; i++)
            {
                if (i == 30)
                {
                    printf(greenbg "%c" reset, 254);
                }
                else
                {
                    printf(greenbg " " reset);
                }
            }
            printf(bluebg "  " reset);
            printf(greenbg " %c%c" reset, 219, 219);
            printf("\n");
            printf("\t\t\t");
            printf("%c%c ", 219, 219);
            for (int i = 0; i < 4; i++)
            {
                printf("     %c%c%c%c%c", 219, 219, 219, 219, 219);
            }
            printf(" %c%c", 219, 219);
            printf("\t\t\t\t\t");
            printf("%c%c", 219, 219);
            for (int i = 0; i < 65; i++)
            {
                if (i == 33)
                {
                    printf(greenbg "%c" reset, 254);
                }
                else
                {
                    printf(greenbg " " reset);
                }
            }
            printf("%c%c", 219, 219);
            printf("\n");
            printf("\t\t\t");
            printf("%c%c ", 219, 219);
            for (int i = 0; i < 4; i++)
            {
                printf("     %c%c%c%c%c", 219, 219, 219, 219, 219);
            }
            printf(" %c%c", 219, 219);
            printf("\t\t\t\t\t");
            printf("%c%c", 219, 219);
            for (int i = 0; i < 65; i++)
            {
                if (i == 33)
                {
                    printf(greenbg "%c" reset, 254);
                }
                else
                {
                    printf(greenbg " " reset);
                }
            }
            printf("%c%c", 219, 219);
            printf("\n");
        }
        else
        {
            printf("\t\t\t");
            printf("%c%c ", 219, 219);
            for (int i = 0; i < 4; i++)
            {
                printf("%c%c%c%c%c     ", 219, 219, 219, 219, 219);
            }
            printf(" %c%c", 219, 219);
            printf("\t\t\t\t\t");
            printf("%c%c", 219, 219);
            for (int i = 0; i < 65; i++)
            {
                if (i == 33)
                {
                    printf(greenbg "%c" reset, 254);
                }
                else
                {
                    printf(greenbg " " reset);
                }
            }
            printf("%c%c", 219, 219);
            printf("\n");
            printf("\t\t\t");
            printf("%c%c ", 219, 219);
            for (int i = 0; i < 4; i++)
            {
                printf("%c%c%c%c%c     ", 219, 219, 219, 219, 219);
            }
            printf(" %c%c", 219, 219);
            printf("\t\t\t\t\t");
            printf("%c%c", 219, 219);
            for (int i = 0; i < 65; i++)
            {
                if (i == 33)
                {
                    printf(greenbg "%c" reset, 254);
                }
                else
                {
                    printf(greenbg " " reset);
                }
            }
            printf("%c%c", 219, 219);
            printf("\n");
            printf("\t\t\t");
            printf("%c%c ", 219, 219);
            for (int i = 0; i < 4; i++)
            {
                printf("     %c%c%c%c%c", 219, 219, 219, 219, 219);
            }
            printf(" %c%c", 219, 219);
            printf("\t\t\t\t\t");
            printf("%c%c", 219, 219);
            for (int i = 0; i < 65; i++)
            {
                if (i == 33)
                {
                    printf(greenbg "%c" reset, 254);
                }
                else
                {
                    printf(greenbg " " reset);
                }
            }
            printf("%c%c", 219, 219);
            printf("\n");
            printf("\t\t\t");
            printf("%c%c ", 219, 219);
            for (int i = 0; i < 4; i++)
            {
                printf("     %c%c%c%c%c", 219, 219, 219, 219, 219);
            }
            printf(" %c%c", 219, 219);
            printf("\t\t\t\t\t");
            printf("%c%c", 219, 219);
            for (int i = 0; i < 65; i++)
            {
                if (i == 33)
                {
                    printf(greenbg "%c" reset, 254);
                }
                else
                {
                    printf(greenbg " " reset);
                }
            }
            printf("%c%c", 219, 219);
            printf("\n");
        }
    }
    printf("\t\t\t");
    printf("%c%c", 219, 219);
    for (int i = 0; i < 42; i++)
    {
        printf("%c", 220);
    }
    printf("%c%c", 219, 219);
    printf("\t\t\t\t\t");
    printf("%c%c", 219, 219);
    for (int i = 0; i < 65; i++)
    {
        if (i == 33)
        {
            printf(greenbg "%c" reset, 254);
        }
        else
        {
            printf(greenbg " " reset);
        }
    }
    printf("%c%c", 219, 219);
    printf("\n");
    printf("\t\t\t");
    for (int i = 0; i < 46; i++)
    {
        printf("%c", 223);
    }
    printf("\t\t\t\t\t");
    for (int i = 0; i < 69; i++)
    {
        printf("%c", 219);
    }
}

void buttons(int i)
{
    printf("\n\n\n");
    if (i % 2 == 0)
    {
        printf("\t\t\t\t\t  ");
        printf(greenbg "           " reset);
        printf("\t\t\t\t\t\t\t\t\t\t\t");
        printf(whitebg "            " reset);
        printf("\n");
        printf("\t\t\t\t\t  ");
        printf(greenbg bw "   Chess   " reset);
        printf("\t\t\t\t\t\t\t\t\t\t\t");
        printf(whitebg bw " Ping-Pong  " reset);
        printf("\n");
        printf("\t\t\t\t\t  ");
        printf(greenbg "           " reset);
        printf("\t\t\t\t\t\t\t\t\t\t\t");
        printf(whitebg "            " reset);
        printf("\n");
    }
    else
    {
        printf("\t\t\t\t\t  ");
        printf(whitebg "           " reset);
        printf("\t\t\t\t\t\t\t\t\t\t\t");
        printf(greenbg "            " reset);
        printf("\n");
        printf("\t\t\t\t\t  ");
        printf(whitebg bw "   Chess   " reset);
        printf("\t\t\t\t\t\t\t\t\t\t\t");
        printf(greenbg bw " Ping-Pong  " reset);
        printf("\n");
        printf("\t\t\t\t\t  ");
        printf(whitebg "           " reset);
        printf("\t\t\t\t\t\t\t\t\t\t\t");
        printf(greenbg "            " reset);
        printf("\n");
    }
}