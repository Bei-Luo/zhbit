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
typedef struct {
	int x;
	int y;
	int s;
}zb;
const int INF = 0x3f3f3f3f;
char id_map[1500][1500];
int id_bj[1500][1500];
int sum[1500][2];
int n, m;
int idv[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int main() {
	while (cin >> n >> m) {
		map<pair<int, int>, int> kfc;
		zb Y, M;
		int k = 1;
		memset(id_map, '#', sizeof(id_map));
		memset(id_bj, 0, sizeof(id_bj));
		memset(sum, INF, sizeof(sum));
		getchar();
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				char temp;
				temp = getchar();
				id_map[i][j] = temp;
				if (temp == 'Y') {
					Y.x = i; Y.y = j; Y.s = 0;
				}
				if (temp == 'M') {
					M.x = i; M.y = j; M.s = 0;
				}
				if (temp == '@')
					kfc[pair<int, int>(i, j)] = k++;
			}
			getchar();
		}
		queue<zb> d;
		d.push(Y);
		int h = k - 1;
		while (!d.empty()) {
			zb temp = d.front();
			d.pop();
			if (id_map[temp.x][temp.y] == '@') {
				sum[kfc[pair<int, int>(temp.x, temp.y)]][0] = temp.s;
				h--;
			}
			if (!h)
				break;
			for (int i = 0; i < 4; ++i) {
				zb tc = temp;
				tc.x += idv[i][0];
				tc.y += idv[i][1];
				if (id_map[tc.x][tc.y] != '#' && !id_bj[tc.x][tc.y] && id_map[tc.x][tc.y] != 'Y'&&id_map[tc.x][tc.y] != 'M') {
					id_bj[tc.x][tc.y] = 1;
					tc.s++;
					d.push(tc);
				}
			}
		}
		while (!d.empty())d.pop();
		memset(id_bj, 0, sizeof(id_bj));
		d.push(M);
		h = k - 1;
		while (!d.empty()) {
			zb temp = d.front();
			d.pop();
			if (id_map[temp.x][temp.y] == '@') {
				sum[kfc[pair<int, int>(temp.x, temp.y)]][1] = temp.s;
				h--;
			}
			if (!h)
				break;
			for (int i = 0; i < 4; ++i) {
				zb tc = temp;
				tc.x += idv[i][0];
				tc.y += idv[i][1];
				if (id_map[tc.x][tc.y] != '#' && !id_bj[tc.x][tc.y] && id_map[tc.x][tc.y] != 'Y'&&id_map[tc.x][tc.y] != 'M') {
					id_bj[tc.x][tc.y] = 1;
					tc.s++;
					d.push(tc);
				}
			}
		}
		int min = INF;
		for (int i = 0; i < 1500; ++i)
			if (sum[i][0] + sum[i][1] < min)
				min = sum[i][0] + sum[i][1];
		printf("%d\n", min * 11);
	}
	return 0;
}

