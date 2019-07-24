/*
    求相互都认识的人的最大数
    总人数 减去最大独立集
    建图 然后  求补图
    将相互都不认识的人建立关系 匹配
    
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
const int maxn = 410;
bool a[maxn][maxn], used[maxn];
int b[maxn];
int G,B, M;
bool pipei(int x) {
	for (int i = 1; i <= G + B; ++i) {
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
	int h = 1;
	while (~scanf("%d %d %d", &G, &B, &M),G+B+M) {
		memset(a, true, sizeof a);
		memset(b, 0, sizeof b);
		int tc1, tc2;
		for (int i = 1; i <= G; ++i)
			for (int j = 1; j <= G; ++j)
				a[i][j] = false;
		for (int i = G+1; i <= B+G; ++i)
			for (int j = G+1; j <= B+G; ++j)
				a[i][j] = false;
		for (int i = 1; i <= M; i++) {
			scanf("%d %d", &tc1, &tc2);
			a[tc1][tc2+G] = false;
			a[tc2+G][tc1] = false;
		}
		int sum = 0;
		for (int i = 1; i <= G + B; ++i) {
			memset(used, false, sizeof used);
			if (pipei(i))
				sum++;
		}
		printf("Case %d: %d\n",h++, G+B-sum/2);
	}
	return 0;
}