/*
You are to find all the two-word compound words in a dictionary. A two-word compound word is a
word in the dictionary that is the concatenation of exactly two other words in the dictionary.
Input
Standard input consists of a number of lowercase words, one per line, in alphabetical order. There will
be no more than 120,000 words.
Output
Your output should contain all the compound words, one per line, in alphabetical order.
Sample Input
a
alien
born
less
lien
never
nevertheless
new
newborn
the
zebra
Sample Output
alien
newborn
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
	string temp;
	set<string> a;
	while (cin >> temp)
		a.insert(temp);
	for (set<string>::iterator i = a.begin(); i != a.end(); ++i) {
		for (int j = 1; j < (*i).size(); ++j) {
			string front = (*i).substr(0, j);
			string rear = (*i).substr(j);
			if (a.count(front) && a.count(rear)) {
				cout << *i << endl;
				break;
			}
		}
	}
}
