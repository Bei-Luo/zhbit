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
typedef pair<int, int>ZJ;
int main() {
	int n, m;
	while (scanf("%d %d", &m, &n) != EOF && n&&m) {
		int id[22][22];
		memset(id, 0xFFFFFFFF, sizeof(id));
		queue<ZJ> b;
		int sum = 1;
		for (int i = 0; i < n; ++i) {
			getchar();
			for (int j = 0; j < m; ++j) {
				char tc;
				tc = getchar();
				if (tc == '.') id[i][j] = 0;
				if (tc == '@') {
					id[i][j] = 1;
					b.push(ZJ(i, j));
				}
			}
		}
		while (1) {
			ZJ temp;
			if (b.empty())
				break;
			else
				temp = b.front();
			b.pop();
			if (id[temp.first][temp.second + 1] == 0&&temp.first >= 0 && temp.second+1 >= 0) {
				id[temp.first][temp.second + 1] = 1;
				b.push(ZJ(temp.first, temp.second + 1));
				sum++;
			}
			if (id[temp.first][temp.second - 1] == 0&&temp.first >= 0 && temp.second-1 >= 0) {
				id[temp.first][temp.second - 1] = 1;
				b.push(ZJ(temp.first, temp.second - 1));
				sum++;
			}
			if (id[temp.first + 1][temp.second] == 0 && temp.first+1 >= 0 && temp.second >= 0) {
				id[temp.first + 1][temp.second] = 1;
				b.push(ZJ(temp.first + 1, temp.second));
				sum++;
			}
			if (id[temp.first - 1][temp.second] == 0 && temp.first-1 >= 0 && temp.second >= 0) {
				id[temp.first - 1][temp.second] = 1;
				b.push(ZJ(temp.first - 1, temp.second));
				sum++;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
