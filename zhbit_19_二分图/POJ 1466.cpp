/*
      求最大独立集
      n-最大独立集 就是都相互认识的人数
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
const int maxn = 1010;
bool a[maxn][maxn], used[maxn];
int b[maxn];
int n;
bool pipei(int x) {
	for (int i = 1; i <= n; ++i) {
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
	while (~scanf("%d", &n)) {
		memset(a, false, sizeof a);
		memset(b, 0, sizeof b);
		int tc1,tc2;
		for (int i = 1; i <= n; ++i) {
			scanf("%*d: (%d)", &tc1);
			for (int j = 0; j < tc1; ++j) {
				scanf("%d", &tc2);
				a[i][tc2 + 1] = true;
			}
		}
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			memset(used, false, sizeof used);
			if (pipei(i))
				sum++;
		}
		printf("%d\n", n-sum/2);//应为没有分开匹配 所以匹配的次数为本来次数的两倍 故要除2
	}
	return 0;
}