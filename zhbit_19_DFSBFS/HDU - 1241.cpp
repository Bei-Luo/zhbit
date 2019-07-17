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
typedef pair<int, int>zj;
typedef struct {
	int id[102][102];
}TU;
void DFS(TU &tu, zj temp) {
	int idv[8][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1} };
	for (int i = 0; i < 8; ++i) {
		int x, y;
		x = temp.first + idv[i][0];
		y = temp.second + idv[i][1];
		if (tu.id[x][y] == 1) {
			tu.id[x][y] = -1;
			DFS(tu, zj(x, y));
		}
	}
}
int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF && n&&m) {
		TU tu;
		memset(tu.id, 0xFFFFFFFF, sizeof(tu.id));
		queue<zj> a;
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			getchar();
			for (int j = 1; j <= m; ++j) {
				char tc;
				tc = getchar();
				if (tc == '\n')
					--j;
				if (tc == '@') {
					tu.id[i][j] = 1;
					a.push(zj(i, j));
				}
			}
		}
		while (1) {
			if (a.empty())
				break;
			zj temp=a.front();
			a.pop();
			if (tu.id[temp.first][temp.second] == -1)
				continue;
			else {
				DFS(tu, temp);
				sum++;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
 }
