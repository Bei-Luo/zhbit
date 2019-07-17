/*
Peter studies the theory of relational databases. Table in the relational database consists of values that
are arranged in rows and columns.
There are different normal forms that database may adhere to. Normal forms are designed to
minimize the redundancy of data in the database. For example, a database table for a library might
have a row for each book and columns for book name, book author, and author’s email.
If the same author wrote several books, then this representation is clearly redundant. To formally
define this kind of redundancy Peter has introduced his own normal form. A table is in Peter’s Normal
Form (PNF) if and only if there is no pair of rows and a pair of columns such that the values in the
corresponding columns are the same for both rows.
How to compete in ACM ICPC Peter peter@neerc.ifmo.ru
How to win ACM ICPC Michael michael@neerc.ifmo.ru
Notes from ACM ICPC champion Michael michael@neerc.ifmo.ru
The above table is clearly not in PNF, since values for 2rd and 3rd columns repeat in 2nd and
3rd rows. However, if we introduce unique author identifier and split this table into two tables — one
containing book name and author id, and the other containing book id, author name, and author email,
then both resulting tables will be in PNF.
How to compete in ACM ICPC 1
How to win ACM ICPC 2
Notes from ACM ICPC champion 2
1 Peter peter@neerc.ifmo.ru
2 Michael michael@neerc.ifmo.ru
Given a table your task is to figure out whether it is in PNF or not.
Input
Input contains several datasets. The first line of each dataset contains two integer numbers n and m
(1 = n = 10000, 1 = m = 10), the number of rows and columns in the table. The following n lines
contain table rows. Each row has m column values separated by commas. Column values consist of
ASCII characters from space (ASCII code 32) to tilde (ASCII code 126) with the exception of comma
(ASCII code 44). Values are not empty and have no leading and trailing spaces. Each row has at most
80 characters (including separating commas).
Output
For each dataset, if the table is in PNF write to the output file a single word “YES” (without quotes).
If the table is not in PNF, then write three lines. On the first line write a single word “NO” (without
quotes). On the second line write two integer row numbers r1 and r2 (1 = r1, r2 = n, r1 ?= r2), on
the third line write two integer column numbers c1 and c2 (1 = c1, c2 = m, c1 ?= c2), so that values in
columns c1 and c2 are the same in rows r1 and r2.
Sample Input
3 3
How to compete in ACM ICPC,Peter,peter@neerc.ifmo.ru
How to win ACM ICPC,Michael,michael@neerc.ifmo.ru
Notes from ACM ICPC champion,Michael,michael@neerc.ifmo.ru
2 3
1,Peter,peter@neerc.ifmo.ru
2,Michael,michael@neerc.ifmo.ru
Sample Output
NO
2 3
2 3
YES
*/ 
#include <iostream>
#include <cstdio>
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
int k = 0;
map<string, int>id_data;
map<pair<int, int>, int>id_cf;
int id_num[10001][11];

int ID(string s) {
	if (id_data.count(s))
		return id_data[s];
	return id_data[s] = k++;
}

int main() {
	int n, m;
	while (cin>>n>>m) {
		k = 0;
		getchar();
		id_data.clear();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				string temp;
				char tc;
				while ((scanf("%c", &tc) != EOF) && tc != ','&&tc != '\n')
					temp.append(1, tc);
				id_num[i][j] = ID(temp);
			}
		bool ok = true;
		for (int i = 0; i < m - 1; ++i) {  //固定列
			for (int j = i + 1; j < m; ++j) { //比较列
				id_cf.clear();
				for (int k = 0; k < n; ++k) {  //比较每一行
					pair<int, int> temp;
					temp.first = id_num[k][j];
					temp.second = id_num[k][i];
					if (id_cf.count(temp)) {
						printf("NO\n");
						printf("%d %d\n", id_cf[temp] + 1, k + 1);
						printf("%d %d\n", i + 1, j + 1);
						ok = false;
						break;
					}
					else
						id_cf[temp] = i;
				}
				if (!ok)
					break;
			}
			if (!ok)
				break;
		}
		if (ok)
			printf("YES\n");
	}
	return 0;
 }
