#include <iostream>
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
const int maxn = 10010;
vector<pair<int,int>> id[maxn];
int vis[10010];
char str[10010];
int dingshiqi;
queue<int> d;
int gengxin(int n,int &t) {
	int sum = 0;
	for(int i=1;i<=n;++i)
		if (!vis[i]) {
			d.push(i);
			dingshiqi++;
			sum += t;
		}
	t++;
	return sum;
}
void init() {
	for (int i = 0; i < maxn; ++i) id[i].clear();
	memset(vis, 0, sizeof(vis));
}
int main() {
	ios::sync_with_stdio(false);
	int n, m, a, b;
	while (cin>>n>>m) {
		init();
		int  t = 888;
		while (!d.empty())d.pop();
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &a, &b);
			id[b].push_back(make_pair(a, 1));
			vis[a]++;
		}
		bool ok = false;
		int sum = 0;
		dingshiqi = 0;
		sum += gengxin(n, t);
		for (int h = 0; h < n; ++h) {
			int top = -1;
			if (!dingshiqi--)
				sum += gengxin(n, t);
			if (!d.empty()) {
				top = d.front();
				d.pop();
			}
			if (top == -1) {
				ok = true;
				break;
			}
			else {
				vis[top] = -1;
				for (int i = 0; i < id[top].size(); ++i)
						vis[id[top].at(i).first]--;
			}
		}
		if (ok)
			printf("-1\n");
		else
			printf("%d\n", sum);
	}
	return 0;
}

