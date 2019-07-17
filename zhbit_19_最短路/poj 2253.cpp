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
#include <cmath>
using namespace std;
const int INF = 99999999.9;
double id[250][205];
map<pair<int, int>, int> id_data;
map<int, pair<int, int>>id_rdata;
double dis[205];
bool vis[205];
int n,k;
int ID(pair<int, int> zb){
	if (id_data.count(zb))
		return id_data[zb];
	id_rdata[k] = zb;
	return id_data[zb] = k++;
}
void gengxin(pair<int, int> zb) {
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) {

			double temp = sqrt(pow((double)(id_rdata[i].first - zb.first), 2) + pow((double)(id_rdata[i].second - zb.second), 2));
			id[i][ID(zb)] = temp;
			id[ID(zb)][i] = temp;
		}
	}
	vis[ID(zb)] = true;
}
int main() {
	int h = 1;
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 0; i < 205; ++i) {
			dis[i] = INF;
			for (int j = 0; j < 205; ++j)
				id[i][j] = INF;
		}
		memset(vis, false, sizeof(vis));
		id_data.clear();
		id_rdata.clear();
		k = 1;
		for(int i=0;i<n;i++){
			int a, b;
			scanf("%d %d", &a, &b);
			gengxin(pair<int, int>(a, b));
		}
		memset(vis, false, sizeof(vis));
		dis[1] = 0; 
		for (int i = 1; i <= n; ++i) {
			int minx = INF;
			int minmark;
			for (int j = 1; j <= n; ++j)
				if (dis[j] <= minx && !vis[j]) {
					minx = dis[j];
					minmark = j;
				}
			vis[minmark] = true;
			for (int j = 1; j <= n; ++j) {
				if (!vis[j] && max(dis[minmark], id[minmark][j]) < dis[j])
					dis[j] = max(dis[minmark], id[minmark][j]);
			}
		}
		printf("Scenario #%d\n", h++);
		printf("Frog Distance = %.3lf\n\n", dis[2]);
	}
}
