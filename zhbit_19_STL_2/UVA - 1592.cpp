/*
	题意让你找 相邻两行中有相邻两列相同 找到就输出no和位置
	找不到就输出yes
	思路正常暴力遍历 但是会爆 所以有些骚操作 
*/ 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <utility>
using namespace std;
int k = 0;
map<string, int>id_data;   //首先将字符串转为数字存储剩空间
map<pair<int, int>, int>id_cf; //相邻两列 捆绑到一起 然后比较
int id_num[10001][11];

int ID(string s) {
	if (id_data.count(s))
		return id_data[s];
	return id_data[s] = k++;
}

int main() {
	int n, m;
	while (cin>>n>>m) {
		k = 0;
		getchar();
		id_data.clear();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				string temp;
				char tc;
				while ((scanf("%c", &tc) != EOF) && tc != ','&&tc != '\n')
					temp.append(1, tc);
				id_num[i][j] = ID(temp);
			}
		bool ok = true;
		for (int i = 0; i < m - 1; ++i) {  //固定列
			for (int j = i + 1; j < m; ++j) { //比较列
				id_cf.clear();
				for (int k = 0; k < n; ++k) {  //比较每一行
					pair<int, int> temp;
					temp.first = id_num[k][j];
					temp.second = id_num[k][i];
					if (id_cf.count(temp)) {
						printf("NO\n");
						printf("%d %d\n", id_cf[temp] + 1, k + 1);
						printf("%d %d\n", i + 1, j + 1);
						ok = false;
						break;
					}
					else
						id_cf[temp] = i;
				}
				if (!ok)
					break;
			}
			if (!ok)
				break;
		}
		if (ok)
			printf("YES\n");
	}
	return 0;
 }
