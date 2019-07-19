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
const int maxn = 1e2 + 20;
int id[maxn][maxn];
int lowcost[maxn], mst[maxn];
int n, m;
int prim(int u) {
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		lowcost[i] = id[u][i];
		mst[i] = u;
	}
	mst[u] = 0;
	for (int i = 1; i < m;++i) {
		int minn = INF,tmp = -1;
		for(int j=1;j<=m;++j)
			if (mst[j] && lowcost[j] < minn) {
				tmp = j;
				minn = lowcost[j];
			}
		if (tmp == -1)
			return -1;
		mst[tmp] = 0;
		ans += lowcost[tmp];
		for(int j=1;j<=m;++j)
			if (mst[j] && id[tmp][j] < lowcost[j]) {
				lowcost[j] = id[tmp][j];
				mst[j] = tmp;
			}
	}
	return ans;
}
void inic() {
	memset(id, INF, sizeof(id));
}
int main() {
	while (scanf("%d %d", &n, &m),n) {
		inic();
		for (int i = 0; i < n; ++i) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			id[a][b] = c;
			id[b][a] = c;
		}
		int sum = prim(1);
		if (sum==-1)
			printf("?\n");
		else
			printf("%d\n", sum);
	}
	return 0;
}
