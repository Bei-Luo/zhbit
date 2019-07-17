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
int id[1200][1200];
int dis[1200];
bool vis[1200];
map<string, int> id_data;
int N, C, R, k;
int ID(string s) {
	if (id_data.count(s))
		return id_data[s];
	return id_data[s] = k++;
}
int main() {
	int h = 1;
	while (cin >> N >> C >> R && N + C + R) {
		memset(id, INF, sizeof(id));
		id_data.clear();
		k = 1;
		int sum = 0;
		string cheku;
		queue<string> hc;
		cin >> cheku;
		for (int i = 0; i < C; ++i) {
			string temp;
			cin >> temp;
			hc.push(temp);
		}
		for (int i = 0; i < R; ++i) {
			string a, b, c, temp;
			int d;
			cin >> a >> b >> c;
			for (int j = 0; j < b.size(); ++j)
				if (isdigit(b.at(j)))
					temp.push_back(b.at(j));
			stringstream ss;
			ss << temp;
			ss >> d;
			if (b.at(b.size() - 1) == '>')
				if (id[ID(a)][ID(c)] > d)
					id[ID(a)][ID(c)] = d;
			if (b.at(0) == '<')
				if (id[ID(c)][ID(a)] > d)
					id[ID(c)][ID(a)] = d;
		}
		while (!hc.empty()) {
			string huaiche = hc.front();
			hc.pop();
			memset(dis, INF, sizeof(dis));
			memset(vis, false, sizeof(vis));
			dis[ID(cheku)] = 0;
			for (int i = 1; i <= N; ++i) {
				int minx = INF;
				int minmark;
				for (int j = 1; j <= N; ++j) {
					if (dis[j] <= minx && !vis[j]) {
						minx = dis[j];
						minmark = j;
					}
				}
				vis[minmark] = true;
				for (int j = 1; j <= N; ++j) {
					if (!vis[j] && dis[j] > dis[minmark] + id[minmark][j])
						dis[j] = dis[minmark] + id[minmark][j];
				}
			}
			sum += dis[ID(huaiche)];
			memset(dis, INF, sizeof(dis));
			memset(vis, false, sizeof(vis));
			dis[ID(huaiche)] = 0;
			for (int i = 1; i <= N; ++i) {
				int minx = INF;
				int minmark;
				for (int j = 1; j <= N; ++j) {
					if (dis[j] <= minx && !vis[j]) {
						minx = dis[j];
						minmark = j;
					}
				}
				vis[minmark] = true;
				for (int j = 1; j <= N; ++j) {
					if (!vis[j] && dis[j] > dis[minmark] + id[minmark][j])
						dis[j] = dis[minmark] + id[minmark][j];
				}
			}
			sum += dis[ID(cheku)];
		}
		cout << h++ << ". " << sum << endl;
	}
}
