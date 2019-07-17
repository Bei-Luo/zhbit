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
using namespace std;
int main() {
	int N, A, B;
	while (cin >> N, N) {
		map<int, int> id;
		queue<int> b;
		int bj[205] = { 0 };
		cin >> A >> B;
		for (int i = 1; i <= N; ++i) {
			int temp;
			cin >> temp;
			id[i] = temp;
		}
		b.push(A);
		while (!b.empty()) {
			int temp=b.front();
			b.pop();
			if (temp == B) {
				cout << bj[B] << endl;
				break;
			}
			if (temp+id[temp]<=N&&!bj[temp + id[temp]]) {
				b.push(temp + id[temp]);
				bj[temp + id[temp]] = bj[temp] + 1;
			}
			if (temp - id[temp] >= 1&&!bj[temp - id[temp]]) {
				b.push(temp - id[temp]);
				bj[temp - id[temp]] = bj[temp] + 1;
			}
			if (b.empty())
				cout << -1 << endl;
		}
	}
	return 0;
}
