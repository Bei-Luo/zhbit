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
	int x;
	int y;
	int z;
	int cs;
}ZB;
char id_num[32][32][32];
int main() {
	int L, R, C;
	while (cin >> L >> R >> C && L + R + C) {
		queue<ZB> d;
		memset(id_num, '#', sizeof(id_num));
		ZB rk;
		int dj[6][3] = { {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };
		rk.cs = 0;
		for (int i = 1; i <= L; ++i) {
			for (int j = 1; j <= R; ++j) {
				for (int k = 1; k <= C; ) {
					char temp;
					temp = getchar();
					if (temp == 'S') {
						rk.z = i; rk.x = j; rk.y = k;
						id_num[i][j][k++] = temp;
					}
					else if (temp == 'E') id_num[i][j][k++] = temp;
					else if (temp == '#') ++k;
					else if (temp == '.') id_num[i][j][k++] = temp;
				}
			}
		}
		d.push(rk);
		while (!d.empty()) {
			ZB zb = d.front();
			d.pop();
			if (id_num[zb.z][zb.x][zb.y] == 'E') {
				cout << "Escaped in " << zb.cs << " minute(s)." << endl;
				break;
			}
			for (int i = 0; i < 6; ++i) {
				ZB temp = zb;
				temp.z = zb.z + dj[i][0];
				temp.x = zb.x + dj[i][1];
				temp.y = zb.y + dj[i][2];
				if (id_num[temp.z][temp.x][temp.y] == '.') {
					temp.cs++;
					d.push(temp);
					id_num[temp.z][temp.x][temp.y] = '#';
				}
				else if (id_num[temp.z][temp.x][temp.y] == 'E') {
					temp.cs++;
					d.push(temp);
				}
			}
			if (d.empty())
				cout << "Trapped!" << endl;

		}
	}
	return 0;
}
