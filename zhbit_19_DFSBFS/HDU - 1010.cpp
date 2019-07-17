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
char id_map[9][9];
typedef pair<int, int>zb;
zb ck;
int t;
bool ok;
int idv[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
void DFS(zb a, int k) {
	int s = abs(a.first - ck.first) + abs(a.second - ck.second);
	if (a == ck && k == t) {
		ok = true;
		return;
	}
	if (t - k < s || (t - k - s) % 2 || k >= t|| ok)
		return;
	for (int i = 0; i < 4; ++i) {
		zb temp;
		temp.first = a.first + idv[i][0];
		temp.second = a.second + idv[i][1];
		if (id_map[temp.first][temp.second] == '.') {
			id_map[temp.first][temp.second] = 'X';
			DFS(temp, k + 1);
			id_map[temp.first][temp.second] = '.';
		}
		if (id_map[temp.first][temp.second] == 'D')
			DFS(temp, k + 1);
	}
}
int main() {
	int n, m;
	zb rk;
	while (scanf("%d %d %d", &n, &m, &t) != EOF && n + m + t) {
		memset(id_map, 'X', sizeof(id_map));
		ok = false;
		getchar();
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				char temp;
				temp = getchar();
				id_map[i][j] = temp;
				if (temp == 'X') sum++;
				if (temp == 'S') {
					rk.first = i;
					rk.second = j;
				}
				if (temp == 'D') {
					ck.first = i;
					ck.second = j;
				}
			}
			getchar();
		}
		if (!(n*m-sum < t))
			DFS(rk, 0);
		if (ok)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
