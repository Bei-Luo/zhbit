/*
Suppose you have to evaluate an expression like A*B*C*D*E where A,B,C,D and E are matrices.
Since matrix multiplication is associative, the order in which multiplications are performed is arbitrary.
However, the number of elementary multiplications needed strongly depends on the evaluation order
you choose.
For example, let A be a 50*10 matrix, B a 10*20 matrix and C a 20*5 matrix. There are two
different strategies to compute A*B*C, namely (A*B)*C and A*(B*C).
The first one takes 15000 elementary multiplications, but the second one only 3500.
Your job is to write a program that determines the number of elementary multiplications needed
for a given evaluation strategy.
Input
Input consists of two parts: a list of matrices and a list of expressions.
The first line of the input file contains one integer n (1 = n = 26), representing the number of
matrices in the first part. The next n lines each contain one capital letter, specifying the name of the
matrix, and two integers, specifying the number of rows and columns of the matrix.
The second part of the input file strictly adheres to the following syntax (given in EBNF):
SecondPart = Line { Line } <EOF>
Line = Expression <CR>
Expression = Matrix | "(" Expression Expression ")"
Matrix = "A" | "B" | "C" | ... | "X" | "Y" | "Z"
Output
For each expression found in the second part of the input file, print one line containing the word ¡®error¡¯
if evaluation of the expression leads to an error due to non-matching matrices. Otherwise print one
line containing the number of elementary multiplications needed to evaluate the expression in the way
specified by the parentheses.
Sample Input
9
A 50 10
B 10 20
C 20 5
D 30 35
E 35 15
F 15 5
G 5 10
H 10 20
I 20 25
A
B
C
(AA)
(AB)
(AC)
(A(BC))
((AB)C)
(((((DE)F)G)H)I)
(D(E(F(G(HI)))))
((D(EF))((GH)I))
Sample Output
0
0
0
error
10000
error
3500
15000
40500
47500
15125
*/ 
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <map>
#include<stack>
#include <utility>
using namespace std;
int main() {
	map<char, pair<int, int>> a;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		pair<char, pair<int, int>> temp;
		pair<int, int>temp1;
		cin >> temp.first >> temp1.first >> temp1.second;
		temp.second = temp1;
		a.insert(temp);
	}
	string temp1;
	while (cin >> temp1) {
		stack<pair<int, int>> s;  //?
		bool ok = true;
		if (temp1.size() == 1 && temp1[0] != '('&&temp1[0] != ')') {
			cout << "0" << endl;
			continue;
		}
		stringstream ss(temp1);
		int sum = 0;
		char temp;
		stack<char> fg;
		while (ss >> temp) {
			if (temp == '(') continue;
			if (temp == ')') {
				pair<int, int> d2= s.top();
				s.pop();
				pair<int, int> d1 = s.top();
				s.pop();
				if (d1.second != d2.first) {
					ok = false;
					cout << "error" << endl;
					break;
				}
				sum += d1.first*d1.second*d2.second;
				pair<int, int> d3;
				d3.first = d1.first; d3.second = d2.second;
				s.push(d3);
			}
			else s.push(a.find(temp)->second);
		}
		if (ok)
			cout << sum << endl;
	}
}
