/*
�ϴ�Gardon���Թ��Ǳ�Сϣ���˺ܾã���Problem B����������Ҳ�����һ���Թ���Gardon���ߡ�����������Թ���˼·��һ������������Ϊ���е�ͨ����Ӧ����˫����ͨ�ģ�����˵�����һ��ͨ����ͨ�˷���A��B����ô�ȿ���ͨ�����ӷ���A�ߵ�����B��Ҳ����ͨ�����ӷ���B�ߵ�����A��Ϊ������Ѷȣ�Сϣϣ�����������������ҽ���һ��·��������ͨ���������˻�ͷ·����Сϣ���ڰ��������ͼ���㣬�����æ�ж��������ͼ�Ƿ�����������˼·��������������ӣ�ǰ�����Ƿ��������ģ��������һ��ȴ�����ַ�����5����8�� 
 
Input
��������������ݣ�ÿ��������һ����0 0��β���������б���ʾ��һ��ͨ�����ӵ���������ı�š�����ı������Ϊ1���Ҳ�����100000��ÿ��������֮����һ�����С� 
�����ļ�������-1��β�� 
Output
���������ÿһ�����ݣ����������һ�С�������Թ�����Сϣ��˼·����ô���"Yes"���������"No"�� 
Sample Input
6 8  5 3  5 2  6 4
5 6  0 0

8 1  7 3  6 2  8 9  7 5
7 4  7 8  7 6  0 0

3 8  6 8  6 4
5 3  5 6  5 2  0 0

-1 -1
Sample Output
Yes
Yes
No
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
int unionsearch(map<int, int> &a, int b) {
	int temp = b,tc;
	while (a[b] != b)
		b = a[b];
	while (temp != b) {
		tc = a[temp];
		a[temp]=b;
		temp = tc;
	}
	return b;
}
int main() {
	int a, b;
	while (cin >> a >> b && a != -1 && b != -1) {
		map<int, int> c;
		int vexnum = 0, arcnum = 0;
		bool ok = true;
		if (a == 0 && b == 0) {
			cout << "Yes" << endl;
			continue;
		}
		c[a] = a; c[b] = a;
		vexnum += 2; arcnum++;
		while (cin >> a >> b && a&&b) {
			if (a == 0 && b == 0)
				break;
			map<int, int>::iterator temp1, temp2;
			temp1 = c.find(a); temp2 = c.find(b);
			if (temp1 == c.end() && temp2 == c.end()) {
				c[a] = a; c[b] = a;
				vexnum += 2;
			}
			else if (temp1 != c.end() && temp2 != c.end()) {
				int tc1, tc2;
				tc1 = unionsearch(c, a);
				tc2 = unionsearch(c, b);
				if (tc1 != tc2)
					c[tc1] = tc2;
				else 
					ok = false;
			}
			else if (temp1 != c.end()) {
				c[b] = unionsearch(c, a);
				vexnum++;
			}
			else if (temp2 != c.end()) {
				c[a] = unionsearch(c, b);
				vexnum++;
			}
			arcnum++;
		}
		if (ok&&vexnum - arcnum == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}
	return 0;
}
