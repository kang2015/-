/**
 * Input
本题有多个测试数据，第一个数字M，表示接下来有连续的M个操作，当M＝0时处理中止。
接下来是一个操作符C。
当操作符为‘I’时，表示有一个MM报名，后面接着一个整数，H表示身高，两个浮点数，A表示活泼度，L表示缘分值。 （100<=H<=200， 0.0<=A，L<=100.0）
当操作符为‘Q’时，后面接着四个浮点数，H1，H2表示身高区间，A1，A2表示活泼度区间，输出符合身高和活泼度要求的MM中的缘分最高值。 （100<=H1，H2<=200， 0.0<=A1，A2<=100.0）
所有输入的浮点数，均只有一位小数。
 

Output
对于每一次询问操作，在一行里面输出缘分最高值，保留一位小数。
对查找不到的询问，输出-1。
 

Sample Input
8
I 160 50.5 60.0
I 165 30.0 80.5
I 166 10.0 50.0
I 170 80.5 77.5
Q 150 166 10.0 60.0
Q 166 177 10.0 50.0
I 166 40.0 99.9
Q 166 177 10.0 50.0
0
 

Sample Output
80.5
50.0
99.9

 * */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 207
#define M 1007

using namespace std;

int n,h;
double a,b;
char s[5];

struct Node
{
    int l,r,maxn;
};

struct Tree
{
    int l,r;
    Node node[N<<2];
}tree[M<<2];

void build ( Node * node  , int u , int l , int r )
{
    node[u].l = l , node[u].r = r;
    node[u].maxn = -1;
    if ( l == r ) return;
    int mid = l + r >>1;
    build ( node , u<<1 , l , mid );
    build ( node , u<<1|1 , mid+1 , r ); 
}

void build ( int u , int l , int r )
{
    tree[u].l = l , tree[u].r = r;
    build ( tree[u].node , 1 , 1 , 200 );
    if ( l == r ) return;
    int mid = l + r >>1;
    build ( u<<1 , l , mid );
    build ( u<<1|1 , mid+1 , r );
}

void update ( Node * node , int u , int y , int v )
{
    int l = node[u].l , r = node[u].r;
    node[u].maxn = max ( node[u].maxn , v );
    if ( l == r ) return;
    int mid = l + r >> 1;
    if ( mid < y )
        update ( node , u<<1|1 , y , v );
    else update ( node , u<<1 , y , v );
}

void update ( int u , int x , int y ,  int  v )
{
    int l = tree[u].l , r = tree[u].r;
   // cout << u << " " << l << " " << r <<" " << x <<  endl;
    update ( tree[u].node , 1 , y , v  );
    if ( l == r ) return;
    int mid = l + r >> 1;
    if ( mid < x )
        update ( u<<1|1 , x , y ,  v );
    else update ( u<<1 , x , y ,  v );
}

int query ( Node *node , int u , int left , int right )
{
    int l = node[u].l , r = node[u].r;
    if ( left <= l && r <= right )
        return node[u].maxn;
    int ret = -1;
    int mid = l + r >> 1;
    if ( right >= l && left <= mid ) ret = max ( ret , query ( node , u<<1 , left , right ) );
    if ( right > mid && left <= r ) ret = max ( ret , query ( node , u<<1|1 , left , right ) );
    return ret;
}

int query ( int u , int left , int right , int up , int down )
{
    int l = tree[u].l , r = tree[u].r;
    if ( left <= l && r <= right )
        return query ( tree[u].node , 1 , up , down );
    int mid = l + r >> 1;
    int ret = -1;
    if ( right >= l && left <= mid ) ret = max ( ret , query ( u<<1 , left , right , up , down ) );
    if ( right > mid && left <= r ) ret = max ( ret , query ( u<<1|1 , left , right , up , down ) );
    return ret;
}


int main ( )
{
    int l , r;
    double u , v;
    while ( ~scanf ( "%d" , &n ) , n )
    {
        build ( 1 , 1 , 1005 );
        for ( int i = 0 ; i < n ; i++ )
        {
            scanf ( "%s" , s );
            if ( s[0] == 'I' )
            {
                scanf ( "%d" , &h );
                scanf ( "%lf%lf" , &a , &b );
                int c = (int)(a*10);
                int d = (int)(b*10);
                update ( 1 , c , h , d );
               // cout << query ( 1 , 1 , 1002 , 100 , 200 ) << endl;
            }
            else 
            {
               scanf ( "%d%d" , &l , &r );
               scanf ( "%lf%lf" , &u , &v );
               int tu = (int)(u*10);
               int tv = (int)(v*10);
               if ( tu > tv ) swap ( tu , tv );
               if ( l > r ) swap ( l , r );
               double ans = query ( 1 , tu , tv , l , r );
               if ( ans < 0 ) printf ( "-1\n" );
               else printf ( "%.1lf\n" , ans/10.0 );
            }
        }
    }
}
