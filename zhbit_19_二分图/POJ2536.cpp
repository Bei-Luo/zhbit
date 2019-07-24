/*
    二分匹配模板题
    自己蠢wa了好几次 
 */
/************************************************
┆　　┏┓　　　┏┓
┆　┏┛┻━━━┛┻┓
┆　┃　　　　　　　┃
┆　┃　　　━　　　┃
┆　┃　┳┛　┗┳　┃
┆　┃　　　　　　　┃
┆　┃　　　┻　　　┃
┆　┃　　　　　　　┃
┆　┗━┓　　　┏━┛
┆　　┃　　　┃　　　　　　　
┆　　┃　　　┃
┆　　┃　　　┗━━━┓
┆　　┃　　　　　　　┣┓
┆　　┃　榜首刘N13 　┏┛
┆　　┗┓┓┏━┳┓┏┛
┆　　　┃┫┫　┃┫┫
┆　　　┗┻┛　┗┻┛　　
************************************************ */
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
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 200;
struct {
	double x;
	double y;
}ds[maxn], dsd[maxn];
bool a[maxn][maxn], used[maxn];
int b[maxn];
int n, m, s, v;
bool pipei(int x) {
	for (int i = 1; i <= m; ++i) {
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
	while (~scanf("%d %d %d %d", &n, &m, &s, &v)) {
		memset(a, false, sizeof a);
		memset(b, 0, sizeof b);
		for (int i = 1; i <= n; ++i)
			scanf("%lf %lf", &ds[i].x, &ds[i].y);
		for (int i = 1; i <= m; i++)
			scanf("%lf %lf", &dsd[i].x, &dsd[i].y);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; j++)
				if (sqrt(pow(ds[i].x - dsd[j].x, 2) + pow(ds[i].y - dsd[j].y, 2)) <= s * v)
					a[i][j] = true;
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			memset(used, false, sizeof used);
			if (!pipei(i))
				sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}