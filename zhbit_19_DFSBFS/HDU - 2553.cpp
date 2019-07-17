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
typedef pair<int, int>ZB;
const int INF = 0x3f3f3f3f;
int bj[13];
int N, sum;
bool pd(int h) {
	for (int i = 1; i < h; ++i)
		if (bj[i] == bj[h] || abs(h - i) == abs(bj[i] - bj[h]))
			return false;
		return true;
}
void DFS(int h) {
	if (h == N+1) {
		sum++;
	}
	else {
		for (int i = 1; i <= N; ++i) {
			bj[h] = i;
			if (pd(h))
				DFS(h + 1);
		}
	}
}
int main() {
	vector<int>a;
	for (N = 1; N <= 10; ++N) {
		memset(bj, 0, sizeof(bj));
		sum = 0;
		DFS(1);
		a.push_back(sum);
	}
	while (scanf("%d", &N) != EOF && N) {
		cout << a.at(N-1) << endl;
	}
}
