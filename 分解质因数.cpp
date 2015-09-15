#include <stdio.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<list>
using namespace std;
int main(){
    int n;
    int i;
    while(cin >> n){
        vector<vector<vector<char>>> shape(10,vector<vector<char>>(5,vector<char>(3,' ')));
        shape[0][0][1] = shape[2][0][1] = shape[3][0][1] = shape[5][0][1] = shape[6][0][1] = shape[7][0][1] = shape[8][0][1] = shape[9][0][1] ='-';
        
        shape[0][1][0] = shape[4][1][0] =shape[5][1][0] =shape[6][1][0] =shape[8][1][0] =shape[9][1][0] = '|';
        shape[0][1][2] = shape[1][1][2] = shape[2][1][2] = shape[3][1][2] = shape[4][1][2] = shape[7][1][2] = shape[8][1][2] = shape[9][1][2] ='|';
        
        shape [2][2][1] = shape [3][2][1] = shape [4][2][1] = shape [5][2][1] = shape [6][2][1] = shape [8][2][1] = shape [9][2][1] ='-';
        
        shape[0][3][0] = shape[2][3][0] = shape[6][3][0] = shape[8][3][0] = '|';
        shape[0][3][2] = shape[1][3][2] =shape[3][3][2] =shape[4][3][2] =shape[5][3][2] =shape[6][3][2] =shape[7][3][2] =shape[8][3][2] =shape[9][3][2] = '|';
        
        shape[0][4][1] = shape[2][4][1] = shape[3][4][1] = shape[5][4][1] = shape[6][4][1] = shape[8][4][1] = shape[9][4][1] = '-';
        vector<char> xing(5,' ');
        xing[2]='*';
        vector<vector<char>> ans(5);
        //cin >> n;
        for(i=2; i<=n; i++){
            while(n!=i){
                if(n%i==0){
                    //cout << i << "*";
                    int tmp = i,cur = -1,iFactor=1;
                    while(iFactor<tmp){
                        iFactor *= 10;
                    }
                    for(iFactor=iFactor/10;iFactor>0;iFactor/=10){
                        cur = tmp/iFactor;
                        tmp = tmp - cur;
                        for(int j=0;j<5;j++){
                            for(int k=0;k<3;k++)
                                ans[j].push_back(shape[cur][j][k]);
                        }
                    }
                    for(int j=0;j<5;j++){
                        ans[j].push_back(xing[j]);
                    }
                    n=n/i;
                }else
                    break;
            }
        }
        //cout << n << endl;
        int tmp = n,cur = -1,iFactor=1;
        while(iFactor<tmp){
            iFactor *= 10;
        }
        for(iFactor=iFactor/10;iFactor>0;iFactor/=10){
            cur = tmp/iFactor;
            tmp = tmp - cur;
            for(int j=0;j<5;j++){
                for(int k=0;k<3;k++)
                    ans[j].push_back(shape[cur][j][k]);
            }
        }
        
        for(int i=0;i<5;i++){
            //reverse(ans[i].begin(),ans[i].end());
            for(auto it = ans[i].begin();it!=ans[i].end();it++){
                cout << *it;
            }
            cout << endl;
        }
    }
    
    return 0;
}
