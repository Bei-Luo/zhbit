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
typedef pair<int, int>zb;
typedef pair<zb, int>info;
const int INF = 0x3f3f3f3f;
char id_map[1002][1002];
int id_h[1002][1002];
int n, m, ok;
int idv[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
queue<zb> h;
queue<info>r;
void BFSH() {
	while (!h.empty()) {
		zb temp = h.front();
		h.pop();
		for (int i = 0; i < 4; ++i) {
			zb tc = temp;
			tc.first += idv[i][0];
			tc.second += idv[i][1];
			if (id_h[tc.first][tc.second] > id_h[temp.first][temp.second] + 1 && id_map[tc.first][tc.second] == '.') {
				h.push(tc);
				id_h[tc.first][tc.second] = id_h[temp.first][temp.second] + 1;
			}
		}
	}
}
void BFS() {
	while (!r.empty()) {
		info tc = r.front();
		r.pop();
		if (id_map[tc.first.first][tc.first.second] == '*') {
			ok = tc.second;
			break;
		}
		for (int i = 0; i < 4; ++i) {
			zb temp;
			temp.first = tc.first.first + idv[i][0];
			temp.second = tc.first.second + idv[i][1];
			if (id_h[temp.first][temp.second]>tc.second+1) {
				if (id_map[temp.first][temp.second] == '.') {
					r.push(info(temp, tc.second + 1));
					id_map[temp.first][temp.second] = ',';
				}
				if (id_map[temp.first][temp.second] == '*')
					r.push(info(temp, tc.second + 1));
			}
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		memset(id_map, '*', sizeof(id_map));
		memset(id_h, INF, sizeof(id_h));
		while (!r.empty()) r.pop();
		getchar();
		zb qd;
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				char temp;
				temp = getchar();
				id_map[i][j] = temp;
				if (temp == 'J')
					r.push(info(zb(i, j),0));
				if (temp == 'F') {
					h.push(zb(i, j));
					id_h[i][j] = 0;
				}
			}
			getchar();
		}
		ok = 0;
		BFSH();
		BFS();
		if (ok)
			printf("%d\n", ok);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
