//my ans
//输入：1）葫芦街上n个房子的坐标；2）m个统计数据，每个数据包括起始b，终点e，该坐标范围（［b，e］）的下雨量w；
//输出：每个房子的下雨量；
//我的解法通过30%数据
//线段树～
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


