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
const int maxn = 1005;
int bcj[maxn];
void inic() {
	for (int i = 0; i < maxn; ++i) bcj[i] = i;
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
int main() {
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		inic();
		int a, b;
		while (m--) {
			scanf("%d %d", &a, &b);
			int x = find(a), y = find(b);
			if (x != y) {
				bcj[x] = y;
			}
		}
		int sum = 0;
		for (int i = 1; i <= n; ++i)
			if (bcj[i] == i)
				sum++;
		printf("%d\n", sum);
	}
	return 0;
}