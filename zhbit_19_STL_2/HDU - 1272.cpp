#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <utility>
using namespace std;
int unionsearch(map<int, int> &a, int b) {
	int temp = b,tc;
	while (a[b] != b)
		b = a[b];
	while (temp != b) {
		tc = a[temp];
		a[temp]=b;
		temp = tc;
	}
	return b;
}
int main() {    //并查集思想  无向连通图 点数-1=边数  并且 并查集并点时发现两个点的父亲相同 说明出现了环
	int a, b;
	while (cin >> a >> b && a != -1 && b != -1) {
		map<int, int> c;
		int vexnum = 0, arcnum = 0;
		bool ok = true;
		if (a == 0 && b == 0) {     //坑人的小地方
			cout << "Yes" << endl;
			continue;
		}
		c[a] = a; c[b] = a;
		vexnum += 2; arcnum++;
		while (cin >> a >> b && a&&b) {
			if (a == 0 && b == 0)
				break;
			map<int, int>::iterator temp1, temp2;
			temp1 = c.find(a); temp2 = c.find(b);
			if (temp1 == c.end() && temp2 == c.end()) {
				c[a] = a; c[b] = a;
				vexnum += 2;
			}
			else if (temp1 != c.end() && temp2 != c.end()) {
				int tc1, tc2;
				tc1 = unionsearch(c, a);
				tc2 = unionsearch(c, b);
				if (tc1 != tc2)
					c[tc1] = tc2;
				else 
					ok = false;
			}
			else if (temp1 != c.end()) {
				c[b] = unionsearch(c, a);
				vexnum++;
			}
			else if (temp2 != c.end()) {
				c[a] = unionsearch(c, b);
				vexnum++;
			}
			arcnum++;
		}
		if (ok&&vexnum - arcnum == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}
	return 0;
}
