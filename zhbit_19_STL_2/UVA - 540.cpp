/*
	大队列里套着小队列 
	题意就是 排队 如果你有个认识的朋友在前面 那么你就可以直接插到他后面 （当然现实不要
	这么做） 然后题目就是模拟这样  解决方法 队列里套队列  
*/ 
#include <iostream>
#include <stdio.h>
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
int main() {
	int t, k = 1;
	while (cin >> t, t) {
		cout << "Scenario #" << k++ << endl;
		queue<int> q[1001];
		queue<int> qd;
		bool qf[1001] = { false };
		map<int, int>qp;
		for (int i = 0; i < t; ++i) {
			int n, temp;
			cin >> n;
			while (n--&&cin >> temp)
				qp[temp] = i;
		}
		string temp;
		while (cin>>temp) {
			if (temp == "ENQUEUE") {
				int tc;
				cin >> tc;
				q[qp[tc]].push(tc);
				if (!qf[qp[tc]]) {
					qf[qp[tc]] = true;
					qd.push(qp[tc]);
				}
			}
			else if (temp == "DEQUEUE") {
				cout << q[qd.front()].front()<<endl;
				q[qd.front()].pop();
				if (q[qd.front()].empty()) {
					qf[qd.front()] = false;
					qd.pop();
				}
			}
			else
				break;
		}
		cout << endl;
	}
}
