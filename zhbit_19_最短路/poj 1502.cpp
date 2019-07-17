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
int id[110][110];
int dis[110];
bool vis[110];
int main() {
	int n;
	while (cin >> n) {
		memset(id, INF, sizeof(id));
		memset(dis, INF, sizeof(dis));
		memset(vis, false, sizeof(vis));
		for (int i = 0; i <= n; ++i)
			id[i][i] = 0;
		for (int i = 2; i <=n; ++i)
			for (int j = 1; j <= i-1; ++j) {
				string temp;
				char *end;
				cin >> temp;
				if (temp.at(0) == 'x') {
					id[j][i] = INF;
					id[i][j] = INF;
				}
				else {
					id[i][j] = static_cast<int>(strtol(temp.c_str(), &end, 10));
					id[j][i] = id[i][j];
				}
			}

		dis[1] = 0;
		for (int i = 1; i <= n; ++i) {
			int minx = INF;
			int minmark;
			for (int j = 1; j <= n; ++j) {
				if (dis[j] <= minx && !vis[j]) {
					minx = dis[j];
					minmark = j;
				}
			}
			vis[minmark] = true;
			for (int j = 1; j <= n; ++j) {
				if (!vis[j] && dis[j] > dis[minmark] + id[minmark][j])
					dis[j] = dis[minmark] + id[minmark][j];
			}
		}
		cout << *max_element(dis+1,dis+1+n) << endl;
	}
}
