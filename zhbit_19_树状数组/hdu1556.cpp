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
const int maxn = 1000010;
int d[maxn];
int lowbit(int x) {
	return x & (-x);
}
int query(int x) {
	int res = 0;
	while (x) {
		res += d[x];
		x -= lowbit(x);
	}
	return res;
}
void updata(int x, int v) {
	while (x <= maxn) {
		d[x] += v;
		x += lowbit(x);
	}
}
int main() {
	int n;
	while (~scanf("%d", &n), n) {
		memset(d, 0, sizeof d);
		for (int i = 1; i <= n; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			updata(a, 1);
			updata(b+1, -1);
		}
		for (int i = 1; i <= n; ++i) {
			if (i == n)
				printf("%d\n", query(i));
			else
				printf("%d ", query(i));
		}
	}
	return 0;
}