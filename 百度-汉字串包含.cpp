//my ans
/**
 * 汉字占两个字符，判断是否为汉字：高位字符的符号位为1
 * 使用short（两个字节）作为key统计串a和串b中的字符数；
 * */
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
int is_include(string& a,string& b){
    map<short,int> ma,mb;
    short key;
    for(int i=0;i<a.length();i++){
        if((a[i]&0x80) != 0 && i+1<a.length()){
            key = (a[i]<<8)+a[i+1];
            i++;
        }else{
            key = a[i];
        }
        map<short,int>::iterator it = ma.find(key);
        if(it != ma.end()){
            it->second++;
        }else{
            ma.insert(make_pair(key, 1));
        }
    }
    for(int i=0;i<b.length();i++){
        if((b[i]&0x80) != 0 && i+1<b.length()){
            key = (b[i]<<8)+b[i+1];
            i++;
        }else{
            key = b[i];
        }
        map<short,int>::iterator it = mb.find(key);
        if(it != mb.end()){
            it->second++;
        }else{
            mb.insert(make_pair(key, 1));
        }
    }
    if(ma.size() < mb.size()){
        return 0;
    }
    for(map<short,int>::iterator it=mb.begin();it!=mb.end();it++){
        if(it->second > ma[it->first]){
            return 0;
        }
    }
    return 1;
}
int main(){
    string a,b;
    cin>>a>>b;
    cout << is_include(a,b);
    return 0;
}

//end of my ans









