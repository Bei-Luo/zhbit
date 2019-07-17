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
char id_map[102][102];
void DFS(zj a) {
	int idv[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
	for (int i = 0; i < 4; ++i) {
		zj temp;
		temp.first = a.first + idv[i][0];
		temp.second = a.second + idv[i][1];
		if (id_map[temp.first][temp.second] == '#') {
			id_map[temp.first][temp.second] = '.';
			DFS(temp);
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		queue<zj> a;
		int n, m, sum = 0;
		memset(id_map, '.', sizeof(id_map));
		cin >> n >> m;
		getchar();
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				char temp;
				temp = getchar();
				id_map[i][j] = temp;
				if (temp == '#')
					a.push(zj(i, j));
			}
			getchar();
		}
		while (!a.empty()) {
			zj y = a.front();
			a.pop();
			if (id_map[y.first][y.second] == '.')
				continue;
			if (id_map[y.first][y.second] == '#') {
				DFS(y);
				sum++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
