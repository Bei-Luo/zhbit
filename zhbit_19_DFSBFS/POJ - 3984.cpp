#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <utility>
using namespace std;
typedef pair<int, int>zi;
typedef vector<zi>zj;
int main() {
	queue<zj> d;
	int vis[7][7];
	memset(vis, 0xFFFFFFFF, sizeof(vis));
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= 5; ) {
			int a;
			a = getchar();
			if (a == '0')
				vis[i][j++] = 0;
			if (a == '1')
				j++;
		}
	}
	d.push(zj(1, zi(1, 1)));
	while (!d.empty()) {
		zj temp = d.front();
		d.pop();
		int dj[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
		if (temp.back() == zi(5, 5)) {
			for (int i = 0; i<temp.size(); ++i)
				cout << "(" << temp.at(i).first - 1 << ", " << temp.at(i).second - 1 << ")" << endl;
		}
		for (int i = 0; i < 4; ++i) {
			int x, y;
			x = temp.back().first + dj[i][0];
			y = temp.back().second + dj[i][1];
			if (vis[x][y] == 0) {
				zj tc = temp;
				tc.push_back(zi(x, y));
				d.push(tc);
				vis[temp.back().first][temp.back().second] = -1;
			}
		}
	}
}