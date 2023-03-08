// sudoku solver

#include<bits/stdc++.h>
using namespace std;

bool check(int sudoku[9][9],int row,int column,int number){
    for(int i=0;i<9;i++){
        if(sudoku[row][i]==number){
            return false;
        }
        if(sudoku[i][column]==number){
            return false;
        }
    }
    int checkrow = (row/3)*3;
    int checkcol = (column/3)*3;
    for(int i=checkrow;i<checkrow+3;i++){
        for(int j=checkcol;j<checkcol+3;j++){
            if(sudoku[i][j]==number){
                return false;
            }
        }
    }
    return true;
}

bool help(int sudoku[9][9],int &row,int &col){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudoku[i][j]==0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool sudokusolver(int sudoku[9][9]){
    int row = 0;
    int col = 0;
    if(!help(sudoku,row,col)){
        return true;
    }
    else{
        for(int i=1;i<=9;i++){
            if(check(sudoku,row,col,i)){
                sudoku[row][col]=i;
                if(sudokusolver(sudoku)){
                    return true;
                }
                else{
                    sudoku[row][col]=0;
                }
            }
        }
        if(sudoku[row][col]==0){
            return false;
        }
    }
    return true;

}
int main(){
    int sudoku[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>sudoku[i][j];
        }
    }
    if(sudokusolver(sudoku)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false";
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
    // write your code here
    return 0;
}