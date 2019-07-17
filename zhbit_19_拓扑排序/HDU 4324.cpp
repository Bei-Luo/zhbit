//#include <iostream>
#include <cstdio>
#include <algorithm>
//#include <cstring>
//#include <vector>
//#include <set>
//#include <queue>
//#include <map>
//#include <stack>
//#include <sstream>
//#include <utility>
//#include <cmath>
//#include<functional>
using namespace std;
int id[2010][2010];
int vis[2010];
char str[2010];
int main() {
	//ios::sync_with_stdio(false);
	int t, h = 1;
	scanf("%d", &t);
	while(t--){
		memset(id, 0, sizeof(id));
		memset(vis, 0, sizeof(vis));
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%s", str);
			for (int j = 0; j < n; ++j) {
				id[i][j] = str[j] - '0';
				if (id[i][j])
					vis[j]++;
			}
		}
		bool ok = false;
		for (int h = 0; h < n; ++h) {
			int top = -1;
			for (int i = 0; i < n; ++i)
				if (!vis[i]) {
					top = i;
					break;
				}
			if (top == -1) {
				ok = true;
				break;
			}
			else {
				vis[top] = -1;
				for (int i = 0; i < n; ++i)
					if (id[top][i])
						vis[i]--;
			}
		}
		printf("Case #%d: ", h++);
		if (!ok)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}

