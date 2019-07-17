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
int id[1000][1000];
int main() {
	int N, M;
	while (cin>>N>>M) {
		priority_queue<int, vector<int>, greater<int> > d;
		memset(id, 0, sizeof(id));
		while (M--) {
			int a, b;
			scanf("%d %d", &a, &b);
			id[a][b] = 1;
		}
		for (int i = 1; i <= N; ++i) {
			bool ok = true;
			for (int j = 0; j <= N; ++j)
				if (id[j][i] == 1) {
					ok = false;
					break;
				}
			if (ok)
				d.push(i);
		}
		int tc = 1;
		while (!d.empty()) {
			int temp = d.top();
			d.pop();
			if (tc)
				printf("%d", temp);
			else
				printf(" %d", temp);
			tc = 0;
			for (int i = 1; i <= N; ++i)
				if (id[temp][i] == 1) {
					bool ok = true;
					id[temp][i] = 0;
					for (int j = 1; j <= N; j++)
						if (id[j][i] == 1) {
							ok = false;
							break;
						}
					if (ok)
						d.push(i);
				}
		}
		printf("\n");
	}
	return 0;
}
