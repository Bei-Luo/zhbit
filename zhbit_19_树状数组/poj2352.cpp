/*
    树状数组经典题
    看着问题很大需要 二维树状数组 其实仔细想不需要
    跟前面的题一样 没进一个看一下比自己小的 就是自己的等级 
    但是要注意 等级不包含自己 所以先看 在入树状数组
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
const int maxn = 32010;
int d[maxn], a[maxn];
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
	while (~scanf("%d", &n)) {
		int x, y;
		memset(a, 0, sizeof a);
		memset(d, 0, sizeof d);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			x++;
			a[query(x)]++;
			updata(x, 1);
		}
		for (int i = 0; i < n; ++i)
			printf("%d\n", a[i]);
	}
	return 0;
}