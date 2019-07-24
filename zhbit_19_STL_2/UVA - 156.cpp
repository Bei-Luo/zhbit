/*
	将出现相同字母的单词去除 不管顺序、大小写
	使用map将 单词与组成它的每个字母 配对 
	然后 两层for遍历 直接判断vector是否相等
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
void xx(string &c) {
	for (int i = 0; i < c.size(); ++i)
		c[i] = tolower(c[i]);
}
int main() {
	map<string, vector<char> > a;
	string b, c;
	while (cin >> b, b != "#") {
		for (int i = 0; i < b.length(); ++i)
			if (!isalpha(b[i]))
				b[i] = ' ';
		stringstream s(b);
		while (s >> c) {
			pair<string, vector<char> > temp;
			vector<char> tc;
			temp.first = c;
			xx(c);
			for (int i = 0; i < c.size(); ++i)
				tc.push_back(c[i]);
			sort(tc.begin(), tc.end());
			temp.second = tc;
			a.insert(temp);
		}
 	}
	for (map<string, vector<char> >::iterator i = a.begin(); i != a.end(); i++) {
		for (map<string, vector<char> >::iterator j = a.begin(); j != a.end(); j++) {
			if (i == j)
				continue;
			if (i->second == j->second) {
				vector<char>temp;
				temp=i->second;
				for (map<string, vector<char> >::iterator k = a.begin(); k != a.end(); k++)
					if (temp == k->second) {
						a.erase(k);
						k = a.begin();
					}
				i = a.begin();
				break;
			}
		}
	}
	for (map<string, vector<char> >::iterator i = a.begin(); i != a.end(); i++)
		cout << i->first << endl;
}
