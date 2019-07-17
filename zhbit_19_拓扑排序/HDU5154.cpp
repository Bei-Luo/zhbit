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
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n>>m&&n+m) {
		memset(id, 0, sizeof(id));
		queue<int> d;
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			id[b][a] = 1;
		}
		for (int i = 1; i <= n; ++i) {
			bool ok = true;
			for (int j = 0; j <= n; ++j)
				if (id[j][i] == 1) {
					ok = false;
					break;
				}
			if (ok)
				d.push(i);
		}
		int sum = 0;
		while (!d.empty()) {
			int temp = d.front();
			d.pop(); sum++;
			for (int i = 1; i <= n; ++i)
				if (id[temp][i] == 1) {
					bool ok = true;
					id[temp][i] = 0;
					for (int j = 1; j <= n; j++)
						if (id[j][i] == 1) {
							ok = false;
							break;
						}
					if (ok)
						d.push(i);
				}
		}
		if (sum==n)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

