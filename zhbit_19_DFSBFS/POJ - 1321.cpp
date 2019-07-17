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
typedef pair<int, int>zj;
int id[10][10]; //-1  0?? 1??
int ok[10]; //???
int n, m, sum;
void DFS(int t, int k) {
	if (k == m) {
		sum++;
		return;
	}
	if (t > n)
		return;
	for (int i = 1; i <= n; ++i) {
		if (id[t][i] == 0 && ok[i] == 0) {
			ok[i] = 1;
			id[t][i] = 1;
			DFS(t + 1, k + 1);
			ok[i] = 0;
			id[t][i] = 0;
		}
	}
	DFS(t + 1, k);
}
int main() {
	while (scanf("%d %d", &n, &m) != EOF && n != -1 && m != -1) {
		memset(id, 0xFFFFFFFF, sizeof(id));
		memset(ok, 0, sizeof(ok));
		sum = 0;
		for (int i = 1; i <= n; ++i) {
			getchar();
			for (int j = 1; j <= n; ++j) {
				char tc;
				tc = getchar();
				if (tc == '\n')
					--j;
				if (tc == '#')
					id[i][j] = 0;
			}
		}
		DFS(1, 0);
		cout << sum << endl;
	}
	return 0;
}

