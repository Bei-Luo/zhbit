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
int id[1005][1005][2];
int dis[1005][2];
bool vis[1005];
int main() {
	int n, m;
	while (1) {
		scanf("%d %d", &n, &m);
		if (n + m == 0)
			break;
		memset(id, INF, sizeof(id));
		memset(dis, INF, sizeof(dis));
		memset(vis, false, sizeof(vis));
		int s, t;
		while(m--){
			int a, b, d, p;
			scanf("%d %d %d %d", &a, &b, &d, &p);
			if (id[a][b][0] > d) {
				id[a][b][0]= id[b][a][0] = d;//长度 
				id[a][b][1]= id[b][a][1] = p;//花费 
			}
			else if (id[a][b][0] == d)
				if (id[a][b][1] > p)
					id[a][b][1]=id[b][a][1] = p;//花费 
		}
		scanf("%d %d", &s, &t);
		dis[s][0] = 0; dis[s][1] = 0;
		for (int i = 1; i <= n; ++i) {
			int minx = INF;
			int minmark;
			for (int j = 1; j <= n; ++j)
				if (dis[j][0] <= minx && !vis[j]) {
					minx = dis[j][0];
					minmark = j;
				}
			vis[minmark] = true;
			for (int j = 1; j <= n; ++j) {
				if (!vis[j] && dis[j][0] > dis[minmark][0] + id[minmark][j][0]) {
					dis[j][0] = dis[minmark][0] + id[minmark][j][0];
					dis[j][1] = dis[minmark][1] + id[minmark][j][1];
				}
				if (!vis[j] && dis[j][0] == dis[minmark][0] + id[minmark][j][0] && dis[j][1] > dis[minmark][1] + id[minmark][j][1]) {
					dis[j][0] = dis[minmark][0] + id[minmark][j][0];
					dis[j][1] = dis[minmark][1] + id[minmark][j][1];
				}
			}
		}
		printf("%d %d\n", dis[t][0], dis[t][1]);
	}
}

