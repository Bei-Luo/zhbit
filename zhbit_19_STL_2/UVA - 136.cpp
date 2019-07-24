/*
	求丑数（只能被2，3，5整除的数） 8也可以 8=4*2=2*2*2 要拆的剩素数
	正常暴力思想太慢了  我们可以从  要是只能被2，3，5整除的数 说明是
	2 3 5 的倍数 从这点入手 每发现一个新丑数 就让它乘以 2 3 5 一直往上推
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <map>
#include <utility>
using namespace std;
int main() {
	set<long long int> a;
	vector<long long int> b;
	a.insert(1);
	int t = 1500;
	while (t--) {
		a.insert(*a.begin() * 2);
		a.insert(*a.begin() * 3);
		a.insert(*a.begin() * 5);
		b.push_back(*a.begin());
		a.erase(a.begin());
	}
	cout <<"The 1500'th ugly number is "<< b.at(1500-1)<<"."<< endl;
}
