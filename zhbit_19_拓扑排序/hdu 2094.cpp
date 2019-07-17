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
#include<functional>
using namespace std;
int id[1010][1010];
int main() {
	ios::sync_with_stdio(false);
	int N, M;
	while (cin >> N, N) {
		set<string> y, s;
		for (int i = 0; i < N; ++i) {
			string a, b;
			cin >> a >> b;
			y.insert(a);
			s.insert(b);
		}
		int sum = 0;
		for (auto i = y.begin(); i != y.end(); ++i) {
			bool ok = true;
			if (s.count(*i))
				ok = false;
			if (ok)
				sum++;
		}
		if (sum == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}

