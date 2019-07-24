/*
    二分匹配模板题
    全匹配就是yes 否则no
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
const int maxn = 310;
bool a[maxn][maxn],used[maxn];
int b[maxn];
int n, m;
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
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d %d", &n, &m);
		int tc1,tc2;
		memset(a, false, sizeof a);
		memset(b, 0, sizeof b);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &tc1);
			for (int j = 0; j < tc1; j++){
				scanf("%d", &tc2);
				a[i][tc2] = true;
			}
		}
		int ok=true;
		for (int i = 1; i <= n; ++i) {
			memset(used, false, sizeof used);
			if (!pipei(i))
				ok = false;
		}
		if (ok)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
