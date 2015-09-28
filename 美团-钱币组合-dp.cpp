#include <stdio.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<list>
using namespace std;

long getNumberOfCombinations(int N) {
    int cell[6] = {1,5,10,20,50,100};
    long dp[6][10001];
    for(int i=0;i<6;i++)
        for(int j=0;j<10001;j++)
            dp[i][j] = 1;
    //for(int i=0;i<N;i++) dp[0][i]=1;
    for(int i=1;i<6;i++){
        for(int j=1;j<=N;j++){
            dp[i][j] = dp[i-1][j];
            int pre = j-cell[i];
            if(pre>=0){
                dp[i][j] += dp[i][pre];
            }
        }
    }
    return dp[5][N];
}
int main(){
    int tc=0;
    cin >> tc;
    while(tc -- >0){
        int tmp = 0;
        cin >> tmp;
        cout << getNumberOfCombinations(tmp)<<endl;
    }
    
    return 0;
}
