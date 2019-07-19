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
const int maxn = 1000000;
int bcj[maxn*2];
int n, m;
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
void stam(int a, int b) {
	int x = find(a), y = find(b);
	if (x != y)
		bcj[x] = y;
}
int main() {
	int h = 1;
	while (scanf("%d %d",&n,&m)&&n+m) {
		//inic();
		int cont = 2*n;
		for (int i = 0; i < n; ++i)
			bcj[i] = i + n;
		for (int i = n; i < maxn; ++i)
			bcj[i] = i;
		while(m--){
			char c[10];
			scanf("%s", &c);
			if (c[0] == 'M') {
				int a, b;
				cin >> a >> b;
				stam(a, b);
			}
			else {
				int a;
				cin >> a;
				bcj[a] = cont++;
			}
		}
		set<int> tj;
		for (int i = 0; i < n; ++i)
			tj.insert(find(i));
		printf("Case #%d: ", h++);
		printf("%d\n", tj.size());
	}
	return 0;
}