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
const int maxn = 1010;
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
	int n, m;
	while (~scanf("%d", &n),n) {
		scanf("%d", &m);
		inic();
		while (m--) {
			int a, b;
			scanf("%d %d", &a, &b);
			if (bcj[a] == -1 && bcj[b] == -1) {
				bcj[a] = a;
				bcj[b] = b;
			}
			else if (bcj[a] != -1 && bcj[b] != -1) {
				a = find(a), b = find(b);
				if (a != b)
					bcj[a] = b;
			}
			else if (bcj[a] == -1) 
				bcj[a] = find(b);
			else if (bcj[b] == -1)
				bcj[b] = find(a);
		}
		int sum = 0;
		for (int i = 1; i <= n; ++i)
			if (bcj[i] == i)
				sum++;
		printf("%d\n", sum - 1);
	}
	return 0;
}