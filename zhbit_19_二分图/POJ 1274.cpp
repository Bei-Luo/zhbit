/*
    基础的匈牙利算法 
    二分匹配    
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
const int maxn = 210;
bool a[maxn][maxn],used[maxn];//used 是用于递归时判断条件
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
	while (~scanf("%d %d",&n,&m)){
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
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			memset(used, false, sizeof used);
			if (pipei(i))
				sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}