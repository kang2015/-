//my ans
//输入：1）葫芦街上n个房子的坐标；2）m个统计数据，每个数据包括起始b，终点e，该坐标范围（［b，e］）的下雨量w；
//输出：每个房子的下雨量；
//我的解法通过30%数据
//线段树～
/*测试用例*
5
1 3 5 7 9
2
2 8 5
1 5 4
*/
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

//my ans of "线段树"方法
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
const int INFINITE = INT_MAX;
const int MAXNUM = 1000;
struct SegTreeNode
{
    int beginPos;
    int endPos;
    int addMark;//延迟标记
}segTree[MAXNUM];//定义线段树

/*
  功能：构建线段树
  root：当前线段树的根节点下标
  arr: 用来构造线段树的数组
  istart：数组的起始位置
  iend：数组的结束位置
  */
void build(int root,vector<int> &arr,int istart, int iend)
{
    segTree[root].addMark = 0;//----设置标延迟记域
    if(istart == iend){//叶子节点
        segTree[root].beginPos = arr[istart];
        segTree[root].endPos = arr[iend];
    }else
        {
            segTree[root].beginPos = arr[istart];
            segTree[root].endPos = arr[iend];
            int mid = (istart + iend) / 2;
            build(root*2+1, arr, istart, mid);//递归构造左子树
            build(root*2+2, arr, mid+1, iend);//递归构造右子树
            
        }
}

/*
  功能：当前节点的标志域向孩子节点传递
  root: 当前线段树的根节点下标
  */
void pushDown(int root)
{
    if(segTree[root].addMark != 0)
        {
            //设置左右孩子节点的标志域，因为孩子节点可能被多次延迟标记又没有向下传递
            //所以是 “+=”
            segTree[root*2+1].addMark += segTree[root].addMark;
            segTree[root*2+2].addMark += segTree[root].addMark;
            //传递后，当前节点标记域清空
            segTree[root].addMark = 0;
        }
}

/*
  功能：线段树的区间查询
  root：当前线段树的根节点下标
  [nstart, nend]: 当前节点所表示的区间
  [qstart, qend]: 此次查询的区间
  */
int query(int root, int qstart, int qend)
{
    //查询区间和当前节点区间没有交集
    if(qstart > segTree[root].endPos || qend < segTree[root].beginPos)
        return INFINITE;
    //当前节点区间包含在查询区间内
    if(qstart <= segTree[root].beginPos && qend >= segTree[root].endPos)
        return segTree[root].addMark;
    //分别从左右子树查询，返回两者查询结果的较小值
    pushDown(root); //----延迟标志域向下传递
    return min(query(root*2+1,qstart, qend),
                query(root*2+2, qstart, qend));
    
}

/*
  功能：更新线段树中某个区间内叶子节点的值
  root：当前线段树的根节点下标
  [nstart, nend]: 当前节点所表示的区间
  [ustart, uend]: 待更新的区间
  addVal: 更新的值（原来的值加上addVal）
  */
void update(int root,int ustart, int uend, int addVal)
{
    //更新区间和当前节点区间没有交集
    if(ustart > segTree[root].endPos || uend < segTree[root].beginPos)
        return ;
    //当前节点区间包含在更新区间内
    if(ustart <= segTree[root].beginPos && uend >= segTree[root].endPos){
            segTree[root].addMark += addVal;
            //segTree[root].val += addVal;
            return ;
    }
    pushDown(root); //延迟标记向下传递
    //更新左右孩子节点
    update(root*2+1,  ustart, uend, addVal);
    update(root*2+2,  ustart, uend, addVal);
    //根据左右子树的值回溯更新当前节点的值
    //segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
}
int main(){
    int n,m;
    cin >> n;
    vector<int> arr(n,-1);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    build(0, arr, 0, n-1);
    int left,right,w;
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> left >> right >> w;
        update(0, left, right, w);
    }
    for(int i=0;i<n;i++){
        cout << query(0, arr[i], arr[i])<<endl;
    }
    return 0;
}
//end of my ans of "线段树"方法

//yz li's ans java
package com.li.test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
public class Main {
    public static void main(String args[]) throws IOException {
    	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    	int N = Integer.parseInt(in.readLine());
    	int[] houses = new int[N];
    	String[] hc = in.readLine().split(" "); 
    	int hh = 0;
    	for (String ec : hc) {
    		houses[hh++] = Integer.valueOf(ec);
    	}
    	int[] mome = new int[N];
    	int M = Integer.parseInt(in.readLine());
    	for (int rc = 0; rc < M; rc++) {
    		String[] rains = in.readLine().split(" "); 
    		int Li = Integer.parseInt(rains[0]);
    		int Ri = Integer.parseInt(rains[1]);
    		int wei = Integer.parseInt(rains[2]);
    		int lIndex = binarySearchLeft(houses, Li);
    		int rIndex = binarySearchRight(houses, Ri);
    		for (int k = lIndex; k <= rIndex; k++) {
    			mome[k] += wei;
    		}
    	}
    	for (int e : mome) 
    		System.out.println(e);
    }
    private static int binarySearchLeft(int[] nums, int target) {
		if (nums == null || nums.length == 0) {
			return -1;
		}
		int start = 0;
		int end = nums.length - 1;
		int mid;
		while (start + 1 < end) {
			mid = start + ((end - start) >> 1);
			if (nums[mid] == target) {
				return mid;
			} else if (nums[mid] < target) {
				start = mid;
			} else if (nums[mid] > target) {
				end = mid;
			}
		}
		if (nums[start] >= target) {
			return start;
		}
		if (nums[end] >= target) {
			return end;
		} else {
			return end + 1;
		}
	}
    private static int binarySearchRight(int[] nums, int target) {
		if (nums == null || nums.length == 0) {
			return -1;
		}
		int start = 0;
		int end = nums.length - 1;
		int mid;
		while (start + 1 < end) {
			mid = start + ((end - start) >> 1);
			if (nums[mid] == target) {
				return mid;
			} else if (nums[mid] < target) {
				start = mid;
			} else if (nums[mid] > target) {
				end = mid;
			}
		}
		if (nums[end] <= target) {
			return end;
		}
		if (nums[start] <= target) {
			return start;
		} else {
			return start - 1;
		}
	}
}


