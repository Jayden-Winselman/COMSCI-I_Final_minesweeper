#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
int i = 0, x = 0, y = 0;
int solutionboard[30][16];
char gameboard[30][16], Move;
for (y = 0; y < 16; y++) {
                for (x = 0; x < 30; x++) {
                        gameboard[x][y] = '?';
                }
        }
int dif, score, playerx = 0, playery = 0;  
int boardXsize, boardYsize, minecount, minesplaced = 0;
        printf("let's play minesweeper\nDifficultys\n");
        printf("1 - beginner     - 10 mines -  9 * 9  grid\n");
        printf("2 - Intermediate - 40 mines - 16 * 16 grid\n");
        printf("3 - Advanced     - 99 mines - 30 * 16 grid\n Enter dificulty (#) : ");
    scanf("%i", &dif);
    
    switch (dif){
        case 1:
            boardXsize = 9;
            boardYsize = 9;
            minecount = 10;
            break;
        case 2:
            boardXsize = 16;
            boardYsize = 16;
            minecount = 40;
            break;
        case 3:
            boardXsize = 30;
            boardYsize = 16;
            minecount = 99;
            break;
        default:
            printf("Error - Invalid Input");
            return 0;
            };
   /**/ printf("enter first cordanents to dig\n");
        
        printf("enter x-cordnate value: ");
            scanf("%i", &playerx);

        printf("enter y-cordnate value: ");
            scanf("%i", &playery);
/**/
        do {
            for (y = 0; y < boardYsize; y++) {
                for (x = 0; x < boardXsize; x++) {
                    solutionboard[x][y] = 0;
                    }
                }

            while (minesplaced < minecount) {
                srand(time(0));
            x = rand() % boardXsize;
            y = rand() % boardYsize;
            if (solutionboard[x][y] == 0) {
                solutionboard[x][y] = 9;
                minesplaced++;
                }
            }
             for (y = 0; y < boardYsize; y++) {
            for (x = 0; x < boardXsize; x++) {
                if((solutionboard[x][y]) == 9) {}
                    
                    else{
                        if(solutionboard[x-1][y-1]  == 9){solutionboard[x][y]++;} 
                        if(solutionboard[x][y-1]    == 9){solutionboard[x][y]++;} 
                        if(solutionboard[x+1][y-1]  == 9){solutionboard[x][y]++;} 
                        
                        if(solutionboard[x-1][y]    == 9){solutionboard[x][y]++;} 
                        if(solutionboard[x+1][y]    == 9){solutionboard[x][y]++;} 
                        
                        if(solutionboard[x-1][y+1]  == 9){solutionboard[x][y]++;} 
                        if(solutionboard[x][y+1]    == 9){solutionboard[x][y]++;} 
                        if(solutionboard[x+1][y+1]  == 9){solutionboard[x][y]++;} 
                        } 
                    }
                }
            if((solutionboard[playerx-1][playery-1]) == 0){i++;}
        }while (i = 0);

//print print solotion board for testing
/* */for(y = 0; y < boardYsize; y++){
            for(x = 0; x < boardXsize; x++){
                    printf("%i ", solutionboard[x][y]);
                }
            printf("\n");
            }/**/
  /*  while(score != (boardXsize * boardYsize - minecount) || score < 999){
        for(int y = 1; y < boardYsize; y++){
            for(int x = 0; x < boardXsize; x++){
                    printf("%c ", gameboard[x][y]);
                }
            printf("\n");
            }
    printf("Enter your move.    d. dig  f. flag/unflag : ");
        scanf("%c", Move);
    printf("enter x-cordnate value: ");

        
    }

if(score = (boardXsize * boardYsize - minecount)){printf("congrats you win\n");}
else{printf("sorry you lost try again\n");}
 */   
    return 0;
}