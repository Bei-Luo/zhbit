/*
	给定单词中 找到一个单词 是由剩余单词中的两个组合而成的
	思路是将一个单词拆分 然后找在单词表中是否有 有就输出该单词 没有就过
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
int main() {
	string temp;
	set<string> a;
	while (cin >> temp)
		a.insert(temp);
	for (set<string>::iterator i = a.begin(); i != a.end(); ++i) {
		for (int j = 1; j < (*i).size(); ++j) {
			string front = (*i).substr(0, j);
			string rear = (*i).substr(j);
			if (a.count(front) && a.count(rear)) {
				cout << *i << endl;
				break;
			}
		}
	}
}
