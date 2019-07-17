//#include <iostream>
#include <cstdio>
#include <algorithm>
//#include <cstring>
//#include <vector>
//#include <set>
#include <queue>
//#include <map>
//#include <stack>
//#include <sstream>
//#include <utility>
//#include <cmath>
//#include<functional>
using namespace std;
const int maxn = 30010;
vector<int> id[maxn];
int vis[maxn];
int ai[maxn];
void init() {
	for (int i = 0; i < maxn; ++i) id[i].clear();
	memset(vis, 0, sizeof(vis));
}
int main() {
	//ios::sync_with_stdio(false);
	int T, n, m, a, b, tc;
	scanf("%d", &T);
	while (T--) {
		init();
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &a, &b);
			id[b].push_back(a);
			vis[a]++;
		}
		priority_queue<int> q;
		int len = n;
		for (int i = 1; i <= n; ++i)
			if (!vis[i])
				q.push(i);
		while (!q.empty()) {
			int top = q.top();
			q.pop();
			ai[len--] = top;
			for (int i = 0; i < id[top].size(); ++i) {
				vis[id[top][i]]--;
				if (!vis[id[top][i]])
					q.push(id[top][i]);
			}
		}
		for (int i = 1; i < n; ++i)
			printf("%d ", ai[i]);
		printf("%d\n",ai[n]);
	}
	return 0;
}
