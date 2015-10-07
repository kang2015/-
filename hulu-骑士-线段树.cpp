/**
 * 输入m*n的棋盘和l个攻击，定义棋盘格的合格数为：从该棋盘格出发进行攻击，l个攻击中不超出棋盘界限的攻击数；
 * 输出合格数正好等于k的棋盘格的个数
 * ［例子］
 * 输入：
 * （m n l k 
 * l个攻击）
 * 3 3 4 2
 * -1 -1
 * -1 1
 * 1 -1
 * 1 1
 * 
 * 输出：
 * 4
 * */

//“非线段树解法”，时间复杂度:O(l^3)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct A{
	int x1, y1, x2, y2, num;
	A():num(0){}
};

int main (){
	int n, m, L, K;
	while (cin >> n >> m >> L >> K){
		vector<pair<int, int> > ttt;
		vector<int> x, y;
		x.push_back (0), x.push_back (n);
		y.push_back (0), y.push_back (m);
		for (int i = 0; i < L; i ++){
			int tx, ty;
			cin >> tx >> ty;
			ttt.push_back (make_pair (tx, ty));
			if (tx < 0){
				tx = -tx;
			}else{
				tx = n-tx;
			}
			if (ty < 0){
				ty = -ty;
			}else{
				ty = m - ty;
			}
			if (tx >= 0 && tx <= n && ty >= 0 && ty <= m){
				x.push_back (tx), y.push_back (ty);
			}
		}
		sort (x.begin (), x.end ());
		sort (y.begin (), y.end ());
		vector<A> vec;
		for (int i = 0; i < (int)x.size()-1; i ++){
			for (int j = 0; j < (int)y.size()-1; j ++){
				A t;
				t.x1 = x[i], t.x2 = x[i+1];
				t.y1 = y[j], t.y2 = y[j+1];
				t.num = 0;
				vec.push_back (t);
			}
		}
		for (int i = 0; i < (int)ttt.size (); i ++){
			for (int j = 0; j < (int)vec.size (); j ++){
				int tx = vec[j].x1, ty = vec[j].y1;
				int dx = ttt[i].first, dy = ttt[i].second;
				if (tx + dx >= 0 && tx + dx < n && ty + dy >= 0 && ty + dy < m){
					vec[j].num ++;
				}
			}
		}
		long long ans = 0;
		for (int i = 0; i < (int)vec.size (); i ++){
			if (vec[i].num == K){
				ans += (long long)(vec[i].x2 - vec[i].x1)*(vec[i].y2 - vec[i].y1);
			}
		}
		cout << ans << endl;
	}
}
//end of “非线段树解法”
