/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ...
shows the first 11 ugly numbers. By convention, 1 is included.
Write a program to find and print the 1500¡¯th ugly number.
Input
There is no input to this program.
Output
Output should consist of a single line as shown below, with ¡®<number>¡¯ replaced by the number
computed.
Sample Output
The 1500'th ugly number is <number>.
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
#include <utility>
using namespace std;
int main() {
	set<long long int> a;
	vector<long long int> b;
	a.insert(1);
	int t = 1500;
	while (t--) {
		a.insert(*a.begin() * 2);
		a.insert(*a.begin() * 3);
		a.insert(*a.begin() * 5);
		b.push_back(*a.begin());
		a.erase(a.begin());
	}
	cout <<"The 1500'th ugly number is "<< b.at(1500-1)<<"."<< endl;
}
