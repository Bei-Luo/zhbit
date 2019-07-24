/*
	题意 有一个序列 带有优先级 如果有比队头优先级高的 就让对头已到队尾 
	直到没有比当前队头高的 然后可以出队 每次出队都会耗时一分钟 问给定的目标 
	需要多长时间到它打印（算上他自己打印的时间）
*/ 
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <map>
#include<stack>
#include <utility>
using namespace std;
int max(vector<pair<int, int>> a, pair<int, int> b) {
	int ok = 1;
	for (int i = 1; i < a.size(); ++i)
		if (b.second < a.at(i).second)
			return 0;
	return 1;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		vector<pair<int, int>> a;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			pair<int, int> temp;
			int tc;
			cin >> tc;
			temp.first = i;
			temp.second = tc;
			a.push_back(temp);
		}
		int k = 0;
		while (1) {
			pair<int, int> temp = a.front();
			if (max(a,temp)) {
				a.erase(a.begin());
				k++;
				if (temp.first == m)
				break;	
			}
			else{
				a.push_back(temp);
				a.erase(a.begin());
			}
		}
		cout << k << endl;
	}
}
