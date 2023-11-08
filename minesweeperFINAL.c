#include <stdio.h>
int dif;

void gameboerd(dif){
    int boardXsize, boardYsize, gameXsize, gameYsize;

    switch (dif){
        case 1:
            boardXsize = 9;
            boardYsize = 9;
            gameXsize = 9;
            gameYsize = 9;
             break;
        case 2:
            boardXsize = 16;
            boardYsize = 16;
            gameXsize = 16;
            gameYsize = 16;
             break;
        case 3:
            boardXsize = 30;
            boardYsize = 16;
            gameXsize = 30;
            gameYsize = 16;
             break;
        }
    int Sboard[boardXsize][boardYsize] = 0 
    
    printf("enter board cordnet (X): \n");
    printf("enter board cordnet (y): \n");


    return 0;
}



int main(){
        printf("let's play minesweeper\nDifficultys\n");
        printf("1 - beginner     - 10 mines -  9 * 9  grid\n");
        printf("2 - Intermediate - 40 mines - 16 * 16 grid\n");
        printf("3 - Advanced     - 99 mines - 16 * 30 grid\n Enter dificulty (#) : ");
    scanf("%i", &dif);
        if (dif>0 && dif<4)
        {
            gameboerd(dif);
        }
        else
        {
        printf("Error - Invalid Input");
        }
    return 0;
}