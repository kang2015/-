//my ans
//输入：1）葫芦街上n个房子的坐标；2）m个统计数据，每个数据包括起始b，终点e，该坐标范围（［b，e］）的下雨量w；
//输出：每个房子的下雨量；
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
int main(){
    int n,m;
    cin >> n;
    //vector<int> pos(n,-1);
    map<int,long long> mp;
    int tmp;
    for(int i=0;i<n;i++){
        cin >> tmp;
        mp.insert(make_pair(tmp, 0));
    }
    cin >> m;
    int b,e;
    long long w;
    for(int i=0;i<m;i++){
        cin >>b>>e>>w;
        map<int,long long>::iterator it1=mp.lower_bound(b);
        map<int,long long>::iterator it2=mp.upper_bound(e);
        for(map<int,long long>::iterator it=it1;it!=it2;it++){
            it->second += w;
        }
    }
    for(map<int,long long>::iterator it=mp.begin();it!=mp.end();it++){
        cout << it->second << endl;
    }
    return 0;
}

//end of my ans




