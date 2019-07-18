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
const int maxn = 100010;
int bcj[maxn];
void inic() {
	memset(bcj, -1, sizeof(bcj));
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
	while (scanf("%d%d", &n, &m)&&n!=-1&&m!=-1) {
		inic();
		int dnum=0, bnum=0;
		bool ok = false;
		if (n == 0 && m == 0) {
			cout << "Yes" << endl;
			continue;
		}
		bcj[n] = n;
		bcj[m] = n;
		dnum += 2; bnum++;
		while (scanf("%d%d", &n, &m) && n + m) {
			if (bcj[n] == -1 && bcj[m] == -1) {
				bcj[n] = n;
				bcj[m] = n;
				dnum += 2; bnum++;
			}
			else if (bcj[n] != -1 && bcj[m] != -1) {
				int a = find(n), b = find(m);
				if (a != b)
					bcj[a] = b;
					bnum++;
			}
			else if (bcj[n] == -1) {
				bcj[n] = find(m);
				dnum++; bnum++;
			}
			else if (bcj[m] == -1) {
				bcj[m] = find(n);
				dnum++; bnum++;
			}
		}
		if (dnum-1==bnum)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
