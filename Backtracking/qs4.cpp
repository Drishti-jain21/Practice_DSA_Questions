// subset sum equal to K

#include<iostream>
using namespace std;

int subset(int* arr,int N,int K, int start){
    if(start==N){
        if(K==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    int count=0;
    if(K-arr[start]>=0){
        count+=subset(arr,N,K-arr[start],start+1);
    }
    count+=subset(arr,N,K,start+1);
    return count;
}

int main(){
    int N;
    int K;
    cin>>N>>K;
    int * arr = new int[N];
    for(int j=0;j<N;j++){
        cin>>arr[j];
    }
    cout<<subset(arr,N,K,0);
}