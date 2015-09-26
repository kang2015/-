// 葫芦娃打小怪兽题目
// 输入:n个小怪兽的攻击力和生命点，葫芦娃每次可以打一个小怪兽的一个生命点，
// 输出:葫芦娃至少受多少攻击才能打死所有小怪兽
// 超时或者wrong answer
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
int main(){
    int tc;
    cin >> tc;
    int n;
    while(tc -->0){
        cin >> n;
        long long ans=0;
        vector<int> l(n,-1);
        vector<int> d(n,-1);
        map<int,int,greater<int> > m;
        long long sum=0;
        //priority_queue<pair<int,int> > q;
        for(int i=0;i<n;i++){
            cin >> l[i] >> d[i];
            sum += d[i];
            map<int,int,greater<int> >::iterator it= m.find(d[i]);
            if(it!=m.end()){
                it->second += l[i];
            }else{
                m.insert(make_pair(d[i], l[i]));
            }
        }
        while(!m.empty()){
            /*for(map<int,int,greater<int> >::iterator it=m.begin();it!=m.end();it++){
                ans += it->first;
            }*/
            ans += sum;
            map<int,int,greater<int> >::iterator it = m.begin();
            sum -= it->first;
            it->second --;
            if(it->second ==0)
                m.erase(it);
        }
        cout << ans << endl;
    }
    return 0;
}

//end of my ans




