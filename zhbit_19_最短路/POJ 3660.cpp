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
int id[150][150];
int N, M;
int main() {
	int h = 1;
	while (cin >> N >> M && N + M) {
		memset(id, INF, sizeof(id));
		queue<int> n;
		int ans = 0;
		int sum[120];
		for (int i = 1; i < N; ++i)
			n.push(i);
		for (int i = 0; i < M; ++i) {
			int a, b;
			cin >> a >> b;
			id[a][b] = 1;
		}
		for (int h = 1; h <= N; ++h)
			for (int i = 1; i <= N; ++i)
				for (int j = 1; j <= N; ++j) {
					if (i == j)continue;
					if ((id[i][h] == 1 && id[h][j] == 1) || id[i][j] == 1)
						id[i][j] = 1;
				}
		for (int i = 1; i <= N; ++i) {
			int sum = 0;
			for (int j = 1; j <= N; ++j)
				if (id[i][j] == 1|| id[j][i] == 1)
					sum++;
			if (N - 1 == sum)
				ans++;
		}
		cout << ans << endl;
	}
}
