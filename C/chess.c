#include <stdio.h>
#include <stdlib.h>

void executor (int** board, int row, int col);
void reset (int** board);
void printBoard(int** board);

int
main (){
    int** board = (int**)malloc(sizeof(int*)*8);
    int i, j;
    int row, col;

    row=col=0;
    for(i=0;i<8;i++)
        board[i] = (int*)malloc(sizeof(int)*8);
        
    reset(board);
    printBoard(board);
      
    printf("\n");
    executor(board, row, col);
}

void printBoard(int** board){
int i, j;

    for(i=0;i<8;i++){
         for(j=0;j<8;j++){
             printf("%d ", board[i][j]);
          }
         printf("\n");
      }
}

void reset (int** board){
     int i, j;

     for(i=0;i<8;i++){
         for(j=0;j<8;j++){
              board[i][j] = 1;
          }
      }
}


void executor (int** board, int row, int col){    int i, j;

    if(row==7 && col==7){
        printBoard(board);
         return;
      }
     

    if(board[row][col] == 1){

         for(i=0;i<8;i++)
             board[i][col]=0;

        for(i=0;i<8;i++)
             board[row][i]=0;

       for(i=row+1;i<8;i++){
          for(j=col+1;j<8;j++){
             if(i==j) board[i][j] =0;
          }
        }
        board[row][col] = 1;
        printBoard(board);
  //      executor(board, row+1, col+1);
    }
    else{
        executor(board, row, col+1);
    }
    
  // executor(board, row+1, col+1);

}
