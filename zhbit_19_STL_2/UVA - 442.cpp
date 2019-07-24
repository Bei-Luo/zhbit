/*
	计算矩阵相乘使的次数 
	两个矩阵可以相乘的条件 1矩阵的列 要和2矩阵的行相等 例如 50*10 和 10*20
	那他们的次数就是 50*10*20
	需要解决的问题的是 括号改变了运算顺序 采用栈来操作
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
int main() {
	map<char, pair<int, int>> a;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		pair<char, pair<int, int>> temp;
		pair<int, int>temp1;
		cin >> temp.first >> temp1.first >> temp1.second;
		temp.second = temp1;
		a.insert(temp);
	}
	string temp1;
	while (cin >> temp1) {
		stack<pair<int, int>> s;  //?
		bool ok = true;
		if (temp1.size() == 1 && temp1[0] != '('&&temp1[0] != ')') {
			cout << "0" << endl;
			continue;
		}
		stringstream ss(temp1);
		int sum = 0;
		char temp;
		stack<char> fg;
		while (ss >> temp) {
			if (temp == '(') continue;
			if (temp == ')') {
				pair<int, int> d2= s.top();
				s.pop();
				pair<int, int> d1 = s.top();
				s.pop();
				if (d1.second != d2.first) {
					ok = false;
					cout << "error" << endl;
					break;
				}
				sum += d1.first*d1.second*d2.second;
				pair<int, int> d3;
				d3.first = d1.first; d3.second = d2.second;
				s.push(d3);
			}
			else s.push(a.find(temp)->second);
		}
		if (ok)
			cout << sum << endl;
	}
}
