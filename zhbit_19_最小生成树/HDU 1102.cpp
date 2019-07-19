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
	for (int i = 1; i <= n; ++i) {
		lowcost[i] = id[u][i];
		mst[i] = u;
	}
	mst[u] = 0;
	for (int i = 1; i < n; ++i) {
		int minn = INF, tmp = -1;
		for (int j = 1; j <= n; ++j)
			if (mst[j] && lowcost[j] < minn) {
				tmp = j;
				minn = lowcost[j];
			}
		if (tmp == -1)
			return -1;
		mst[tmp] = 0;
		ans += lowcost[tmp];
		for (int j = 1; j <= n; ++j)
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
	while (cin>>n) {
		inic();
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				int a;
				scanf("%d", &a);
				id[i][j] = a;
			}
		int c;
		scanf("%d", &c);
		for (int i = 0; i < c; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			id[a][b] = 0;
			id[b][a] = 0;
		}
		int sum = prim(1);
		printf("%d\n", sum);
	}
	return 0;
}