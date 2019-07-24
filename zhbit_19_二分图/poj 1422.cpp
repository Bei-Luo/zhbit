/*
    最小路径覆盖=点数-匹配数
    自己画图理解
 */
#include <cstdio>
#include <map>
#include<string.h>
using namespace std;
const int maxn = 150;
bool a[maxn][maxn], used[maxn];
int b[maxn];
int m, n;
bool pipei(int x) {
	for (int i = 1; i <= n; i++) {
		if (a[x][i] && !used[i]) {
			used[i] = true;
			if (!b[i] || pipei(b[i])) {
				b[i] = x;
				return true;
			}
		}
	}
	return false;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(a, false, sizeof a);
		memset(b, 0, sizeof b);
		scanf("%d", &n);
		scanf("%d", &m);
		int tc1, tc2;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &tc1, &tc2);
			a[tc1][tc2] = true;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			memset(used, false, sizeof used);
			if (pipei(i))
				ans++;
		}
		printf("%d\n", n - ans);//这里的人和道路是分开匹配的 所以不用除二
	}
	return 0;
}
