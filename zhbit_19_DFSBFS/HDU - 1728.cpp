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
const int INF = 0x3f3f3f3f;
typedef pair<int, int>zj;
char id_map[110][110];
bool ok;
int bj[110][110];
int n, m, c;
zj a, b;
void dayin() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			printf("%c", id_map[i][j]);
		printf("\n");
	}
	printf("\n");
}
void DFS(zj a, int dir) {
	int idv[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
	if (a == b && bj[a.first][a.second] <= c) {
		ok = true;
		return;
	}
	if (bj[a.first][a.second] > c)
		return;
	if (a.first != b.first&&a.second != b.second&&bj[a.first][a.second] == c)
		return;
	for (int i = 0; i < 4; ++i) {
		zj temp;
		temp.first = a.first + idv[i][0];
		temp.second = a.second + idv[i][1];
		if (temp.first<1 || temp.second <1 || temp.first>m || temp.second>n || id_map[temp.first][temp.second] == '*' || id_map[temp.first][temp.second] == '#')
			continue;
		if (bj[temp.first][temp.second] < bj[a.first][a.second])
			continue;
		if (dir != -1 && i != dir && bj[temp.first][temp.second] < bj[a.first][a.second] + 1)
			continue;
		if (dir != -1 && i != dir)
			bj[temp.first][temp.second] = bj[a.first][a.second] + 1;
		else
			bj[temp.first][temp.second] = bj[a.first][a.second];
		id_map[temp.first][temp.second] = '#';
		//dayin();
		DFS(temp, i);
		id_map[temp.first][temp.second] = '.';
		if (ok)
			return;
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(bj, INF, sizeof(bj));
		scanf("%d %d", &m, &n);
		getchar();
		ok = false;
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				char temp;
				temp = getchar();
				id_map[i][j] = temp;
			}
			getchar();
		}
		scanf("%d", &c);
		scanf("%d %d", &a.second, &a.first);
		scanf("%d %d", &b.second, &b.first);
		bj[a.first][a.second] = 0;
		DFS(a, -1);
		if (ok)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
