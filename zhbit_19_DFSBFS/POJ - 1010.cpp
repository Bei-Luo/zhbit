#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
//#include <set>
//#include <queue>
//#include <map>
//#include <stack>
//#include <sstream>
//#include <utility>
using namespace std;
const int INF = 0x3f3f3f3f;
struct SOL{
	int types;
	int high;
	int num;
	int sum;
	int v[8];
}best, now,a;
int sum,ok,tie;
int vis[128];
vector<int> jz, n;
void gengxin() {
	if (now.types == best.types&&now.num == best.num&&now.high == best.high) {
		tie = 1;
		return;
	}
	if (now.types > best.types)
		best= now, tie = 0;
	else if(now.types == best.types&&now.num<best.num)
		best= now, tie = 0;
	else if (now.types == best.types&&now.num == now.num&&now.high > best.high) 
		best = now, tie = 0;
}
void solve() {
	if (!ok) {
		printf("---- none\n"); return;}
	if (tie) {
		printf("(%d): tie\n", best.types); return;}
	printf("(%d):", best.types);
	for (int i = 1; i <= best.num; ++i)
		printf(" %d", jz.at(best.v[i]));
	printf("\n");
}
void dfs(SOL temp) {
	if (temp.sum == sum) {
		if (!ok) {
			best = temp;
			ok = 1;
		}
		else {
			now = temp;
			gengxin();
		}
	}
	if (temp.num >= 4)
		return;
	for (int i = 0; i < jz.size(); ++i) {
		if (temp.v[temp.num] <= i&& temp.sum+ jz.at(i)<=sum) {
			SOL tc = temp;
			tc.v[++tc.num] = i;
			tc.high = tc.high > jz.at(i) ? tc.high : jz.at(i);
			tc.sum =tc.sum+ jz.at(i);
			memset(vis, 0, sizeof(vis));
			for (int j = 1; j <= tc.num; ++j)
				vis[tc.v[j]] = 1;
			int x=0;
			for (int j = 0; j < 128; ++j)
				x += vis[j];
			tc.types = x;
			dfs(tc);
		}
	}
}
int main() {
	//	freopen("in.txt", "r", stdin);
	//	freopen("out.txt", "w", stdout);
	int temp;
	while (cin>>temp) {
		jz.clear(); n.clear();
		if (temp != 0) {
			jz.push_back(temp);
			while (cin>>temp && temp)
				jz.push_back(temp);
		}
		sort(jz.begin(), jz.end());
		while (cin >> sum && sum) {
			ok = 0;
			tie = 0;
			printf("%d ", sum);
			dfs(a);
			solve();
		}
	}
	return 0;
}

