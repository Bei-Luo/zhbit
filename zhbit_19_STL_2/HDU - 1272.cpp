/*
上次Gardon的迷宫城堡小希玩了很久（见Problem B），现在她也想设计一个迷宫让Gardon来走。但是她设计迷宫的思路不一样，首先她认为所有的通道都应该是双向连通的，就是说如果有一个通道连通了房间A和B，那么既可以通过它从房间A走到房间B，也可以通过它从房间B走到房间A，为了提高难度，小希希望任意两个房间有且仅有一条路径可以相通（除非走了回头路）。小希现在把她的设计图给你，让你帮忙判断她的设计图是否符合她的设计思路。比如下面的例子，前两个是符合条件的，但是最后一个却有两种方法从5到达8。 
 
Input
输入包含多组数据，每组数据是一个以0 0结尾的整数对列表，表示了一条通道连接的两个房间的编号。房间的编号至少为1，且不超过100000。每两组数据之间有一个空行。 
整个文件以两个-1结尾。 
Output
对于输入的每一组数据，输出仅包括一行。如果该迷宫符合小希的思路，那么输出"Yes"，否则输出"No"。 
Sample Input
6 8  5 3  5 2  6 4
5 6  0 0

8 1  7 3  6 2  8 9  7 5
7 4  7 8  7 6  0 0

3 8  6 8  6 4
5 3  5 6  5 2  0 0

-1 -1
Sample Output
Yes
Yes
No
*/
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
int main() {
	int a, b;
	while (cin >> a >> b && a != -1 && b != -1) {
		map<int, int> c;
		int vexnum = 0, arcnum = 0;
		bool ok = true;
		if (a == 0 && b == 0) {
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
