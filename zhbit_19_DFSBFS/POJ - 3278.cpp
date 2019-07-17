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
typedef pair<int, int>zc;
int main() {
	int N, K;
	while (cin >> N >> K) {
		queue<int> a;
		int vis[100001] = { 0 };
		a.push(N);
		while (!a.empty()) {
			int temp = a.front();
			a.pop();
			if (temp == K) {
				cout << vis[temp] << endl;
				break;
			}
			if (temp + 1 <= 100000 && !vis[temp + 1]) {
				a.push(temp + 1);
				vis[temp + 1] = vis[temp] + 1;
			}
			if (temp * 2 <= 100000 && !vis[temp * 2]) {
				a.push(temp * 2);
				vis[temp * 2] = vis[temp] + 1;
			}
			if (temp - 1 >= 0 && !vis[temp - 1]) {
				a.push(temp - 1);
				vis[temp - 1] = vis[temp] + 1;
			}
		}
	}
	return 0;
}
