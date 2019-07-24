/*
    这道题神仙配图
    题意 比如说冒泡排序时 的交换次数 说白了就是逆序数 
    应为 给的值的问题 空间会爆 需要离散化处理
    求逆序数的时候需要注意一个问题 我去出现问题的地方写注释
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
const int maxn = 500010;
int d[maxn],b[maxn];
map<int, int> id;
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
	int n;
	while (~scanf("%d", &n), n) {
		memset(d, 0, sizeof d);
		int k = 1;
		id.clear();
		long long int ans=0;
		for (int i = 1; i <= n; ++i) {
			int a;
			scanf("%d", &a);
			id[a] = n - i + 1;
		}
		for (map<int,int>::reverse_iterator i = id.rbegin(); i != id.rend(); ++i)
			b[k++] = i->second;
		for (int i = 1; i <= n; ++i) {
			updata(b[i], 1);
			ans += i-query(b[i]);//注意是i-自己的前缀合 如果只是求自己的前缀和的话就会出现 包含的状况 
		}                        //i就是现在有多少个数 自己的前缀和就是比自己小的数 减出来就是在前面比自己大的数
		printf("%lld\n", ans);
	}
	return 0;
}