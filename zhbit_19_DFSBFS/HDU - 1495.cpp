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
typedef struct {
	int a;  //可乐杯量
	int b;	//第一个杯子的量
	int c;  //第二个杯子的量
}ZL;
int vis[102][102][102];
int main() {
	int S, N, M;
	while (cin >> S >> N >> M && S + N + M) {
		queue<ZL> d;
		d.push(ZL{ S,0,0 });
		memset(vis, 0, sizeof(vis));
		while (!d.empty()) {
			ZL temp = d.front();
			d.pop();
			if ((temp.a == temp.b && !temp.c) || (temp.a == temp.c && !temp.b) || (temp.c == temp.b && !temp.a)) {
				cout << vis[temp.a][temp.b][temp.c] << endl;
				break;
			}
			for (int i = 0; i < 6; ++i) {
				int a=temp.a, b=temp.b,c=temp.c;
				if (i == 0 && temp.a != 0 && temp.b != N) {
					a = temp.a > N - temp.b ? temp.a - N + temp.b : 0;
					b = temp.a > N - temp.b ? N : temp.a+temp.b;
					c = temp.c;
				}
				if (i == 1 && temp.a != 0 && temp.c != M) {
					a = temp.a > M - temp.c ? temp.a - M + temp.c : 0;
					c = temp.a > M - temp.c ? M : temp.a+temp.c;
					b = temp.b;
				}
				if (i == 2 && temp.b != 0 && temp.a != S) {
					b = temp.b > S - temp.a ? temp.b - S + temp.a : 0;
					a = temp.b > S - temp.a ? S : temp.b+temp.a;
					c = temp.c;
				}
				if (i == 3 && temp.b != 0 && temp.c != M) {
					b = temp.b > M - temp.c ? temp.b - M + temp.c : 0;
					c = temp.b > M - temp.c ? M : temp.b+temp.c;
					a = temp.a;
				}
				if (i == 4 && temp.c != 0 && temp.a != S) {
					c = temp.c > S - temp.a ? temp.c - S + temp.a : 0;
					a = temp.c > S - temp.a ? S : temp.c+temp.a;
					b = temp.b;
				}
				if (i == 5 && temp.c != 0 && temp.b != N) {
					c = temp.c > N - temp.b ? temp.c - N + temp.b : 0;
					b = temp.c > N - temp.b ? N : temp.c+temp.b;
					a = temp.a;
				}
				if (!vis[a][b][c]) {
					d.push(ZL{ a,b,c });
					vis[a][b][c] = vis[temp.a][temp.b][temp.c] + 1;
				}
			}
			if (d.empty())
				cout << "NO" << endl;
		}
	}
}