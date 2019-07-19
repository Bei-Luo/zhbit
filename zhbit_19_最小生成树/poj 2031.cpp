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
const double INF = 0x3f3f3f3f;
const int maxn = 1e2 + 20;
struct {
	double x;
	double y;
	double z;
	double r;
}zb[maxn];
double id[maxn][maxn];
double lowcost[maxn], mst[maxn];
int n;
double prim(int u) {
	double ans = 0;
	for (int i = 1; i <= n; ++i) {
		lowcost[i] = id[u][i];
		mst[i] = u;
	}
	mst[u] = 0;
	for (int i = 1; i < n; ++i) {
		double minn = INF;
		int tmp = -1;
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
	while (scanf("%d", &n), n) {
		inic();
		for (int i = 1; i <= n; ++i)
			scanf("%lf %lf %lf %lf", &zb[i].x, &zb[i].y, &zb[i].z, &zb[i].r);
		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j) {
				double temp = sqrt(pow(zb[i].x - zb[j].x, 2) + pow(zb[i].y - zb[j].y, 2) + pow(zb[i].z - zb[j].z, 2)) - zb[i].r - zb[j].r;
				if (temp <= 0) {
					id[i][j] = 0;
					id[j][i] = 0;
				}
				else {
					id[i][j] = temp;
					id[j][i] = temp;
				}
			}
		double sum = prim(1);
		printf("%.3lf\n", sum);
	}
	return 0;
}