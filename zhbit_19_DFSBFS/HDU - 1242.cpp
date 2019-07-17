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
int id[202][202]; //-1 ???? 0??? 1??? 2?? 3?? 4??
int sum = 100000;
void DFS(zj temp, int t) {
	int idv[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
	if (id[temp.first][temp.second] == 3) {
		if (t < sum)
			sum = t;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int x, y;
		x = temp.first + idv[i][0];
		y = temp.second + idv[i][1];
		if (id[x][y] == 0) {
			id[x][y] = 1;
			DFS(zj(x, y), t + 1);
			id[x][y] = 0;
		}
		else if (id[x][y] == 3) {
			DFS(zj(x, y), t + 1);
		}
		else if (id[x][y] == 4) {
			id[x][y] = 1;
			DFS(zj(x, y), t + 2);
			id[x][y] = 4;
		}
	}
}
int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF && n&&m) {
		memset(id, 0xFFFFFFFF, sizeof(id));
		sum = 100000;
		zj a;
		for (int i = 1; i <= n; ++i) {
			getchar();
			for (int j = 1; j <= m; ++j) {
				char tc;
				tc = getchar();
				if (tc == '\n')
					--j;
				if (tc == '.')
					id[i][j] = 0;
				else if (tc == 'x')
					id[i][j] = 4;
				else if (tc == 'r')
					id[i][j] = 3;
				else if (tc == 'a') {
					a.first = i;
					a.second = j;
				}
			}
		}
		DFS(a, 0);
		if (sum != 100000)
			printf("%d\n", sum);
		else
			printf("Poor ANGEL has to stay in the prison all his life.\n");
	}
	return 0;
}
