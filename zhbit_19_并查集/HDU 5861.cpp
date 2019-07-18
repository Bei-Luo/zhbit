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
const int maxn = 2e5 + 20;
int v[maxn], bcj[maxn];
pair<int, int> I[maxn];
vector<int> st[maxn], en[maxn];
void inic() {
	memset(v, 0, sizeof(v));
	for (int i = 0; i < maxn; ++i) {
		st[i].clear();
		en[i].clear();
		bcj[i] = i;
	}
}
int find(int root) {
	int son, tmp;
	son = root;
	while (root != bcj[root])
		root = bcj[root];
	while (son != root) {
		tmp = bcj[son];
		bcj[son] = root;
		son = tmp;
	}
	return root;
}
void same(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx > fy)bcj[fy] = fx;
	else if(fx < fy) bcj[fx] = fy;
}
int main() {
	int n, m;
	while (~scanf("%d%d", &n, &m)) {
		inic();
		for (int i = 1; i < n; ++i)
			scanf("%d", &v[i]);
		for (int i = 1; i <= m; ++i) {
			scanf("%d %d", &I[i].first, &I[i].second);
			if (I[i].first > I[i].second) swap(I[i].first, I[i].second);
			int r = I[i].first;
			while (1) {
				r = find(r);
				if (r >= I[i].second) break;
				same(r, r + 1);
				st[i].push_back(r);
			}
		}
		for (int i = 0; i < maxn; ++i) bcj[i] = i;
		for (int i = m; i >= 1; --i) {
			int r = I[i].first;
			while (1) {
				r = find(r);
				if (r >= I[i].second) break;
				same(r, r + 1);
				en[i].push_back(r);
			}
		}
		int ans = 0;
		for (int i = 1; i <= m; ++i) {
			for (int j = 0; j < st[i].size(); ++j)
				ans += v[st[i][j]];
			printf("%d\n", ans);
			if (i == m)
				break;
			for (int j = 0; j < en[i].size(); ++j)
				ans -= v[en[i][j]];
		}
	}
	return 0;
}