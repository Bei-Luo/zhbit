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
map<string, int> id_data;
int dis[200];
bool vis[200];
int k;
int ID(string s) {
	if (id_data.count(s))
		return id_data[s];
	return id_data[s] = k++;
}
int main() {
	int N;
	while (1) {
		scanf("%d", &N);
		if (N == -1)
			break;
		memset(id, INF, sizeof(id));
		memset(dis, INF, sizeof(dis));
		memset(vis, false, sizeof(vis));
		id_data.clear();
		k = 1;
		string rk, ck;
		cin >> rk >> ck;
		for (int i = 0; i < N; ++i) {
			string a, b;
			int  c;
			cin >> a >> b >> c;
			if (id[ID(a)][ID(b)] > c) {
				id[ID(a)][ID(b)] = c;
				id[ID(b)][ID(a)] = c;
			}
		}
		dis[ID(rk)] = 0;
		for (int i = 1; i <= 200; ++i) {
			int minx = INF;
			int minmark;
			for (int j = 1; j <= 200; ++j) {
				if (dis[j] <= minx && !vis[j]) {
					minx = dis[j];
					minmark = j;
				}
			}
			vis[minmark] = true;
			for (int j = 1; j <= 200; ++j) {
				if (!vis[j] && dis[j] > dis[minmark] + id[minmark][j])
					dis[j] = dis[minmark] + id[minmark][j];
			}
		}
		if (dis[ID(ck)] == INF)
			cout << "-1" << endl;
		else
			cout << dis[ID(ck)] << endl;
	}
	return 0;
}
