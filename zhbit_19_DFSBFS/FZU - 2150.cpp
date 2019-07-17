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
typedef pair<int, int>ZB;
const int INF = 0x3f3f3f3f;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int T, n, m;
char id_map[13][13];
int vis[13][13];
int bfs(ZB a, ZB b) {
	memset(vis, INF, sizeof(vis));
	queue<ZB> c;
	c.push(a); c.push(b);
	vis[a.first][a.second] = 0;
	vis[b.first][b.second] = 0;
	while (!c.empty()) {
		ZB temp = c.front();
		c.pop();
		for (int i = 0; i < 4; ++i) {
			ZB tc;
			tc.first = temp.first + dir[i][0];
			tc.second = temp.second + dir[i][1];
			if (id_map[tc.first][tc.second] == '#'&&vis[tc.first][tc.second] > vis[temp.first][temp.second] + 1) {
				vis[tc.first][tc.second] = vis[temp.first][temp.second] + 1;
				c.push(tc);
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (id_map[i][j] == '#')
				max = max > vis[i][j] ? max : vis[i][j];
	return max;
}
int main() {
	//freopen("in.txt","r",stdin);
	scanf("%d", &T);
	for (int h = 0; h < T; ++h) {
		scanf("%d %d", &n, &m);
		memset(id_map, '.', sizeof(id_map));
		vector<ZB> a;
		getchar();
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				char temp;
				temp = getchar();
				id_map[i][j] = temp;
				if (temp == '#')
					a.push_back(ZB(i, j));
			}
			getchar();
		}
		printf("Case %d: ", h + 1);
		if (a.size() <= 2) {
			printf("0\n");
			continue;
		}
		int min = INF;
		for (int i = 0; i < a.size(); ++i)
			for (int j = i+1; j < a.size(); ++j) {
				int ans = bfs(a.at(i), a.at(j));
				min = min > ans ? ans : min;
			}
		if (min == INF)
			printf("-1\n");
		else
			printf("%d\n", min);
	}
}
