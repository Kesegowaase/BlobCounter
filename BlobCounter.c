#include <stdio.h>
#include <stdlib.h>
int rowBound,columnBound; 
int array[100];
int array_ = 0;
int counter = 0;

void searchBlob(char **board,int row,int column){
    board[row][column] = ' ';
    counter++;
    if(row !=0 ){//upperSearch
        if(board[row-1][column] == '*'){
            searchBlob(board,row-1,column);
        }
    }
    if(column != columnBound-1){//rightSearch
        if(board[row][column+1] == '*'){
            searchBlob(board,row,column+1);
        }
    }
    if(row != rowBound-1){//lowerSearch
        if(board[row+1][column] == '*'){
            searchBlob(board,row+1,column);
        }
    }
    if(column != 0){//leftSearch
        if(board[row][column-1] == '*'){
            searchBlob(board,row,column-1);
        }
    }
    if(column != 0 && row !=0){//upperLeftSearch
        if(board[row-1][column-1] == '*'){
            searchBlob(board,row-1,column-1);
        }
    }
    if(column != 0 && row != rowBound-1){//lowerLeftSearch
        if(board[row+1][column-1] == '*'){
            searchBlob(board,row+1,column-1);
        }
    }
    if(column != columnBound-1 && row !=0){//upperRightSearch
        if(board[row-1][column+1] == '*'){
            searchBlob(board,row-1,column+1);
        }
    }
    if(column != columnBound-1 && row != rowBound-1){//lowerRightSearch
        if(board[row+1][column+1] == '*'){
            searchBlob(board,row+1,column+1);
        }
    }
    
    
}

int main(){
    int r,c,starCounter=0;
    scanf("%d%d",&rowBound,&columnBound);
    
    char **board = (char**) malloc(sizeof(char*)*rowBound);
    
    for(int i=0;i<rowBound;i++)
        board[i] = (char*) malloc(sizeof(char)*columnBound);
    
    for(int i=0;i<rowBound;i++){
        for(int j=0;j<columnBound;j++){
            board[i][j] = ' ';
        }
    }
    
    while(1){
    
        scanf("%d%d",&r,&c);
        if(r == -1)
            break;
        board[r][c] = '*';
        
    }
    for(int i=0;i<rowBound;i++){
        for(int j=0;j<columnBound;j++){
            if(board[i][j] == '*'){
                searchBlob(board,i,j);
                starCounter++;
                array[array_++]=counter;
                counter = 0;
            }
        }
    }
    
    printf("%d ",starCounter);
    
    
    for(int i=0;i<starCounter;i++){//bedo sort
        for(int j=0;j<starCounter-1;j++){
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }    
    
    for(int i=0;i<starCounter;i++){
        printf("%d ",array[i]);
    }
    
}
