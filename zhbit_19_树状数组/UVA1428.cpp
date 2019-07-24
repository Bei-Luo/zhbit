/*
    给定序列中 每一个数字左面比他小的个数乘以右边比他大的个数加上 左面比他的乘以右面比他小的
    注意最后int会爆 采用llint
    树状数组扫两边 第一遍从左到右 记录左边比他大的 和比他小的
    第二遍从右到左 记录右边比他小的 和比他大的
 */
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
const int maxn = 100010;
int d[maxn];
int long long ans1[maxn],ans2[maxn];
vector<int> f;
int lowbit(int x) {
	return x & (-x);
}
int query(int x) {
	int res = 0;
	while (x) {
		res += d[x];
		x -= lowbit(x);
	}
	return res;
}
void updata(int x, int v) {
	while (x <= maxn) {
		d[x] += v;
		x += lowbit(x);
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, temp;
		memset(ans1, 0, sizeof ans1);
		memset(ans2, 0, sizeof ans2);
		memset(d, 0, sizeof d);
		f.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &temp);
			f.push_back(temp);
			updata(temp, 1);
			ans1[i] += query(temp - 1);
			ans2[i] += query(maxn) - query(temp);
		}
		memset(d, 0, sizeof d);
		for (int i = n; i > 0; --i) {
			updata(f.at(i - 1), 1);
			ans1[i]*= query(maxn) - query(f.at(i - 1));
			ans2[i] *= query(f.at(i - 1)-1);
		}
		long long int sum = 0;
		for (int i = 1; i <= n; ++i)
			sum += ans1[i], sum += ans2[i];
		printf("%lld\n", sum);
	}
}