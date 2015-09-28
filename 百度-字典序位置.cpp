//my ans
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include<memory>
#include<map>
#include<queue>
#include <sstream>
#include <set>
#include <list>
using namespace std;
vector<long long> jiecheng(12);
long long compute(string s){
    long long ans=0;
    int rc = 0;
    for(int i=0;i<s.length();i++){
        rc=0;
        for(int j=i+1;j<s.length();j++){
            if(s[j]<s[i]){
                rc++;
            }
        }
        ans += rc*jiecheng[11-i];
    }
    return ans;
}
int main(){
    int n=0;
    cin >> n;
    string s;
    jiecheng[1]=1;
    for(int i=2;i<=11;i++){
        jiecheng[i]=i*jiecheng[i-1];
    }
    for(int i=0;i<n;i++){
        cin >> s;
        cout << compute(s)+1 << endl;
    }
        
    return 0;
}

//end of my ans









