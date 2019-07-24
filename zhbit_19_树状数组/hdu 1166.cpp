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
const int maxn = 50010;
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
	int T,cont=1;
	scanf("%d", &T);
	while (T--) {
		int N,temp;
		memset(d, 0, sizeof d);
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &temp);
			updata(i, temp);
		}
		while (1) {
			char str[100];
			int i, j;
			scanf("%s", str);
			if (str[0] == 'A') {
				scanf("%d %d", &i, &j);
				updata(i, j);
			}
			else if (str[0] == 'S') {
				scanf("%d %d", &i, &j);
				updata(i, -j);
			}
			else if (str[0] == 'Q') {
				scanf("%d %d", &i, &j);
				printf("%d\n", query(j) - query(i - 1));
			}
			else
				break;
		}
	}
	return 0;
}