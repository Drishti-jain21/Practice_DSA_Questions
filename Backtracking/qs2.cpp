// Rat in maze question

#include<bits/stdc++.h>
using namespace std;
void printarray(int output[][18],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<output[i][j]<<" ";
		}
	}
	cout<<endl;
}
void domywork(int input[][18],int output[][18],int row, int col,int n){
	if(input[0][0]==0||input[n-1][n-1]==0){
		return;
	}
	if(row==n-1 && col==n-1){
		output[row][col]=1;
		printarray(output,n);
		output[row][col]=0;
		return;
	}
	output[row][col]=1;
	if((row-1)>=0){
		if(input[row-1][col]!=0 && output[row-1][col]!=1){
			domywork(input,output,row-1,col,n);
		}
	}
	if( (row+1)<=n-1){
		if(input[row+1][col]!=0  && output[row+1][col]!=1){
			domywork(input,output,row+1,col,n);
		}
	}
	if((col-1)>=0){
		if(input[row][col-1]!=0 && output[row][col-1]!=1){
			domywork(input,output,row,col-1,n);
		}
	}
	if((col+1)<=n-1){
		if(input[row][col+1]!=0 && output[row][col+1]!=1){
			domywork(input,output,row,col+1,n);
		}
	}
	output[row][col]=0;
	return;
}
int main() {
	int n;
	cin>>n;
	int input[18][18];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>input[i][j];
		}
	}
	int output[18][18];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			output[i][j]=0;
		}
	}
	domywork(input,output,0,0,n);
	// Write your code here
	return 0;
}
