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
#include<functional>
using namespace std;
int id[1010][1010];
bool vis[1010];
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m && n + m) {
		memset(id, 0, sizeof(id));
		memset(vis, 0, sizeof(vis));
		queue<int> d;
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			id[b][a] = 1;
		}
		for (int i = 0; i < n; ++i) {
			bool ok = true;
			for (int j = 0; j < n; ++j)
				if (id[j][i] == 1) {
					ok = false;
					break;
				}
			if (ok) {
				d.push(i);
				vis[i] = true;
			}
		}
		for (int h = 0; h < n - 1; ++h) {
			if (d.empty())
				break;
			int temp = d.front();
			d.pop(); vis[temp] = true;
			for (int i = 0; i < n; ++i)
				if (id[temp][i] == 1) {
					bool ok = true;
					id[temp][i] = 0;
					for (int j = 0; j < n; j++)
						if (id[j][i] == 1) {
							ok = false;
							break;
						}
					if (ok) {
						d.push(i);
						vis[i] = true;
					}
				}
		}
		bool ok = true;
		for (int i = 0; i < n; ++i)
			if (!vis[i])
				ok = false;
		if (ok)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

