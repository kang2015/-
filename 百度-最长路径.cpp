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
class Node{
public:
    int vertex;
    int dist;
    
    Node(int _vertex, int _dist){
        vertex = _vertex;
        dist = _dist;
    }
};
int dijkstra(vector<list<Node> > &graph,int i,int num){
    vector<bool> vis(num,false);
    vector<int> dist(num,INT_MAX);
    dist[i] = 0;
    int ans=0;
    for(int i=0;i<num;i++){
        int mi = -1;
        for(int j=0;j<num;j++){
            if(!vis[j]){
                if(mi == -1 || dist[j] < dist[mi]){
                    mi=j;
                }
            }
        }
        vis[mi] = true;
        ans = dist[mi];
        //cout<< "min dist is : "<< dist[mi] << endl;
        for(list<Node>::iterator it = graph[mi].begin();it!=graph[mi].end();it++){
            if(dist[it->vertex] > dist[mi] + it->dist){
                dist[it->vertex] = dist[mi] + it->dist;
            }
        }
        
    }
    return ans;
}
long long sum(int n){
    return 11*n+(n-1)*n/2;
}
int main(){
    int n=0;
    cin >> n;
    vector<list<Node> > graph(n);
    for(int i=0;i<n-1;i++){
        int v1,v2,dist;
        cin >> v1 >> v2 >> dist;
        graph[v1-1].push_back(Node(v2-1,dist));
        graph[v2-1].push_back(Node(v1-1,dist));
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans = max(ans,dijkstra(graph,i,n));
    
    cout << sum(ans);
    return 0;
}

//end of my ans


