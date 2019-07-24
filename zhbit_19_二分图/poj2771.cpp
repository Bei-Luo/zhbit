/*
    注意a数组的i代表男生 j代表女生 含义不一样
    将陌生（有可能成为情侣）的建立关系匹配  求最大独立集
    因为要求的是大家都是相互认识的（相互不可能成为情侣的）
    所求即为总人数-最大独立集
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
int n, n1, n2;
struct {
	int h;
	string x;
	string y;
}xsm[maxn], xsf[maxn];
bool pipei(int x) {
	for (int i = 1; i <= n2; ++i) {
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
	cin >> t;
	while (t--) {
		memset(a, true, sizeof a);
		memset(b, 0, sizeof b);
		cin >> n;
		n1 = 1;
		n2 = 1;
		for (int i = 1; i <= n; ++i) {
			int h;
			char sex;
			cin >> h >> sex;
			if (sex == 'M') {
				xsm[n1].h = h;
				cin >> xsm[n1].x >> xsm[n1].y;
				n1++;
			}
			else {
				xsf[n2].h = h;
				cin >> xsf[n2].x >> xsf[n2].y;
				n2++;
			}
		}
		n1--, n2--;
		for (int i = 1; i <= n1; i++) 
			for (int j = 1; j <= n2; j++) 
				if (abs(xsm[i].h - xsf[j].h) > 40 || xsm[i].x != xsf[j].x || xsm[i].y == xsf[j].y)
				a[i][j] = false;
		int sum = 0;
		for (int i = 1; i <= n1; ++i) {
			memset(used, false, sizeof used);
			if (pipei(i))
				sum++;
		}
		cout << n - sum << endl;//这里不用除二 是因为男生和女生是分开匹配的
	}
	return 0;
}