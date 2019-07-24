/*
	说白了就是 让计算给定一个入栈序列 例如12345 求它的不可能出栈序列 上过数据结构课的应该很清楚
	比如 34512 就是不可能的 因为 3都出栈了 那12必须是以21出栈才可以所以只能是 34521
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
#include <utility>
using namespace std;
int asd(vector<int> a) {
	int tc = 1;
	for (int i = 1; i < a.size(); ++i)
		if (a.at(i) > a.at(i - 1))
			tc = 0;
	return tc;

}
int main() {
	int N;
	while (cin >> N, N) {
		while (1) {
			int temp, tc = 1;
			vector<int> a;
			cin >> temp;
			if (temp == 0)
				break;
			a.push_back(temp);
			for (int i = 0; i < N - 1; ++i) {
				cin >> temp;
				a.push_back(temp);
			}
			for (vector<int>::iterator i = a.begin(); i != a.end(); ++i) {
				temp = *i;
				vector<int> b;
				for (vector<int>::iterator j = i + 1; j != a.end(); ++j)
					if (temp > *j)
						b.push_back(*j);
				if (b.size() >= 2 && !asd(b)) {
					tc = 0;
					break;
				}
			}
			if (tc)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		cout << endl;
	}
}

