#include <stdio.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<list>
using namespace std;

int getMax(int *arr, int length, int limit){
    int ans = -2147483647;
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            if(arr[i]+arr[j]>ans && arr[i]+arr[j]<=limit){
                ans = arr[i]+arr[j];
            }
        }
    }
    return ans;
}
int main(){
    int tc=0;
    cin >> tc;
    int length = 0;
    int arr[100];
    int limit = 0;
    while(tc -- >0){
        cin >> length;
        for(int i=0;i<length;i++)
            cin>>arr[i];
        cin >> limit;
        cout << getMax(arr,length,limit)<<endl;
    }
    
    return 0;
}
