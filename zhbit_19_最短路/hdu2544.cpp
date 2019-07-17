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
int id[200][200];
int dis[200];
bool vis[200];
int N, M;
int main() {
	while (cin >> N >> M, N, M) {
		memset(id, INF, sizeof(id));
		memset(dis, INF, sizeof(dis));
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < M; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			if (id[a][b] > c) {
				id[a][b] = c;
				id[b][a] = c;
			}
		}
		dis[1] = 0;
		for (int i = 1; i <= N; ++i) {
			int minx = INF;
			int minmark;
			for (int j = 1; j <= N; ++j) {
				if (dis[j] <= minx && !vis[j]) {
					minx = dis[j];
					minmark = j;
				}
			}
			vis[minmark] = true;
			for (int j = 1; j <= N; ++j) {
				if (!vis[j] && dis[j] > dis[minmark] + id[minmark][j])
					dis[j] = dis[minmark] + id[minmark][j];
			}
		}
		cout << dis[N]<< endl;
	}
}

