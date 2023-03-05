// n-queens problem

#include<iostream>
#include<vector>
using namespace std;

    char board[11][11];

    bool check(int n, int row, int column){
        for(int i=0;i<row;i++){
            if(board[i][column]=='Q'){
                return true;
            }
        }
        for(int i=row-1,j=column-1;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return true;
            }
        }
        for(int i=row-1,j=column+1;i>=0&&j<n;i--,j++){
            if(board[i][j]=='Q'){
                return true;
            }
        }
        return false;
    }
    void help(int n, int row){
        if(row==n){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<board[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            return;
        }
        for(int i=0;i<n;i++){
            if(!check(n,row,i)){
                board[row][i] = 'Q';
                help(n,row+1);
                board[row][i] = '.';
            }
        }
        return;

    }
    void solveNQueens(int n) {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i][j] = '.';
            }
        }
        help(n,0);
    }

    int main(){
        int n;
        cin>>n;
        solveNQueens(n);
    }