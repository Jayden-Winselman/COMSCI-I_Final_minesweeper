#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
int i = 0, j = 0, x = 0, y = 0;
int solutionboard[30][16];
char gameboard[30][16];
for (y = 0; y < 16; y++) {
                for (x = 0; x < 30; x++) {
                        gameboard[x][y] = 219;
                }
        }
int openspace[30][16]; //score counter
for (y = 0; y < 16; y++) {
                for (x = 0; x < 30; x++) {
                        openspace[x][y] = 0;
                }
        }
int dif, score = 0, playerx = 0, playery = 0;  
int boardXsize, boardYsize, minecount, minesplaced = 0;
char Move;

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
        }while (i == 0);
    
i=0;
//print print solotion board for testing
/* */
    printf("solution board\n");
    for(y = 0; y < boardYsize; y++){
            for(x = 0; x < boardXsize; x++){
                    printf("%i ", solutionboard[x][y]);
                }
            printf("\n");
            }
while(score < (boardXsize * boardYsize - minecount)){
  openspace[playerx-1][playery-1] = 1;
  do
  { 
    i = 0;
     for(y = 0; y < boardYsize; y++){
            for(x = 0; x < boardXsize; x++){
            
            if (openspace[x][y] == 1 && solutionboard[x][y] == 0)
            {             
                if(openspace[x-1][y-1]  == 0){openspace[x-1][y-1] = 1; i++;} 
                if(openspace[x][y-1]    == 0){openspace[x][y-1] = 1; i++; } 
                if(openspace[x+1][y-1]  == 0){openspace[x+1][y-1] = 1; i++; } 
                
                if(openspace[x-1][y]    == 0){openspace[x-1][y] = 1; i++; } 
                if(openspace[x+1][y]    == 0){openspace[x+1][y] = 1; i++; } 
                        
                if(openspace[x-1][y+1]  == 0){openspace[x-1][y+1] = 1; i++; } 
                if(openspace[x][y+1]    == 0){openspace[x][y+1] = 1; i++; } 
                if(openspace[x+1][y+1]  == 0){openspace[x+1][y+1] = 1; i++; }
                
                
            }
            
        }
     }
  } while (i != 0);
  
  
  
  //print spaces dugged
    printf("open space board\n");
    for(y = 0; y < boardYsize; y++){
            for(x = 0; x < boardXsize; x++){
                    printf("%i ", openspace[x][y]);
                }
            printf("\n");
            }/* */    
    printf("game board\n");  
    for(int y = 0; y < boardYsize; y++){
        for(int x = 0; x < boardXsize; x++){
            if (openspace[x][y] == 1)
            {
                gameboard[x][y] = solutionboard[x][y] + 48;
            }}}
    for(int y = 0; y < boardYsize; y++){
        for(int x = 0; x < boardXsize; x++){
                printf("%c ",gameboard[x][y]);
            }
        printf("\n");
        }
    while (i == 0)
    {
      printf("Enter your move.\nd. dig  f. flag/unflag : ");
      scanf(" %c", &Move);
        if ((Move == 'f') || (Move == 'F') || (Move == 'd') || (Move == 'D'))
        {
            i = 1;
        }
        
    }
    i = 0;

    printf("enter x-cordnate value: ");

    score += 10000;

    }

if(score == boardXsize * boardYsize - minecount){printf("congrats you win\n");}
else{printf("sorry you lost try again\n");}
    
    return 0;
}