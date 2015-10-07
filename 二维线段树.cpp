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
