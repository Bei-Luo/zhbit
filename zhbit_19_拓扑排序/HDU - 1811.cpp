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
const int INF = 0x3f3f3f3f;
const int maxn = 10010;
vector<int> id[maxn];
struct {
	int x;
	int y;
	char c;
}temp[maxn];
int vir[maxn];
int bcj[maxn];
int cnt;
void inic() {
	memset(vir, 0, sizeof(vir));
	for (int i = 0; i < maxn; ++i) bcj[i] = i, id[i].clear();
}
int find(int root) {
	int son, tmp;
	son = root;
	while (root != bcj[root])
		root = bcj[root];
	while (son != root) {
		tmp = bcj[son];
		bcj[son] = root;
		son = tmp;
	}
	return root;
}
void unite(int a, int b) {
	a = find(a); b = find(b);
	if (a != b) bcj[a] = b, cnt--;
}
int main() {
	int N, M;
	while (~scanf("%d%d", &N, &M)) {
		inic();
		cnt = N;
		for (int i = 0; i < M; ++i) {
			scanf("%d %c %d", &temp[i].x, &temp[i].c, &temp[i].y);
			if (temp[i].c == '=') {
				unite(temp[i].x, temp[i].y);
			}
		}
		for (int i = 0; i < M; ++i) {
			if (temp[i].c == '=') continue;
			int x = find(temp[i].x), y = find(temp[i].y);
			if (temp[i].c == '>') {
				id[y].push_back(x);
				vir[x]++;
			}
			else {
				id[x].push_back(y);
				vir[y]++;
			}
		}
		bool ok = false; //³åÍ» 
		queue<int> q;
		for (int i = 0; i < N; ++i)
			if (!vir[i] && bcj[i] == i) q.push(i);
		while(!q.empty()){
			if (q.size() > 1) ok = true;
			int top = find(q.front());
				q.pop();
				cnt--;
			vir[top] = -1;
			for (int i = 0; i < id[top].size(); ++i) {
				vir[id[top][i]]--;
				if (vir[id[top][i]] == 0) q.push(id[top][i]);
			}
		}
		if (cnt>0)
			printf("CONFLICT\n");
		else if (ok)
			printf("UNCERTAIN\n");
		else
			printf("OK\n");
	}
	return 0;
}
