/*
    树状数组的变式 区间最值 不太好理解 
    修改时 需要把包含自己的向下的修改了
    查找时  如果要查找的区间不在同一支 需要看y的值 并且递归y-- 很复杂 画图比较好理解一点
 */
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
const int INF = 0x3f3f3f3f;
const int maxn = 200010;
int d[maxn],a[maxn],n;
int lowbit(int x) {
	return x & (-x);
}
int query(int x,int y) {
	int ans = 0;
	while (y>=x) {
		ans = max(a[y], ans);
		y--;
		for (; y - lowbit(y) >= x; y -= lowbit(y))
			ans = max(d[y], ans);
	}
	return ans;
}
void updata(int x) {
	int lx;
	while (x <= n) {
		d[x] = a[x];
		lx = lowbit(x);
		for (int i = 1; i < lx; i <<= 1)
			d[x] = max(d[x], d[x - i]);
		x += lowbit(x);
	}
}
int main() {
	int m;
	while (~scanf("%d %d", &n, &m)) {
		memset(d, 0, sizeof d);
		int temp, tc1, tc2;
		char c;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			updata(i);
		}
		for (int i = 0; i < m; ++i) {
			getchar();
			scanf("%c %d %d", &c, &tc1, &tc2);
			if (c == 'Q')
				printf("%d\n", query(tc1, tc2));
			else
				a[tc1] = tc2, updata(tc1);
		}
	}
}