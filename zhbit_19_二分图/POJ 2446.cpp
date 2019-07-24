/*
    奇偶匹配 奇偶的意思类似奇偶剪枝
    建图 给与所有的1关系
    然后匹配；
    题不难 坐标的转换 有点烦 
 */
#include <cstdio>
#include <map>
#include<string.h>
using namespace std;
const int maxn = 1100;
bool a[maxn][maxn], used[maxn];
int b[maxn];
int m, n, k;
int di[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int id[maxn][maxn];
bool pipei(int x) {
	for (int i = 2; i <= m * n; i++) {
		if (a[x][i] && !used[i]) {
			used[i] = true;
			if (!b[i] || pipei(b[i])) {
				b[i] = x;
				return true;
			}
		}
	}
	return false;
}
int main() {
	while (~scanf("%d %d %d", &m, &n, &k)) {
		memset(a, false, sizeof a);
		memset(b, 0, sizeof b);
		int tc1, tc2, sum = 0;
		for (int j = 1, h = 1; j <= m; ++j)
			for (int i = 1; i <= n; ++i)
				id[i][j] = h++;
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &tc1, &tc2);
			id[tc1][tc2] = -1;
			sum++;
		}
		if ((n * m - sum) % 2) {
			printf("NO\n");
			continue;
		}
		for (int j = 1; j <= m; ++j)
			for (int i = 1; i <= n; ++i)
				if ((i % 2 == j % 2) && id[i][j] != -1) {
					for (int h = 0; h < 4; ++h) {
						int x, y, i1, i2;
						x = i + di[h][0];
						y = j + di[h][1];
						i1 = id[i][j];
						i2 = id[x][y];
						if (x<1 || y<1 || x>n || y>m || i2 == -1)
							continue;
						a[i1][i2] = true;
					}
				}
		int ans = 0;
		for (int i = 1; i <= n * m; i++) {
			memset(used, false, sizeof used);
			if (pipei(i))
				ans++;
		}
		if (n * m - sum - ans * 2)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}