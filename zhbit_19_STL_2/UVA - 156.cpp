/*
Most crossword puzzle fans are used to anagrams ?a groups of words with the same letters in different
orders ?a for example OPTS, SPOT, STOP, POTS and POST. Some words however do not have this
attribute, no matter how you rearrange their letters, you cannot form another word. Such words are
called ananagrams, an example is QUIZ.
Obviously such definitions depend on the domain within which we are working; you might think
that ATHENE is an ananagram, whereas any chemist would quickly produce ETHANE. One possible
domain would be the entire English language, but this could lead to some problems. One could restrict
the domain to, say, Music, in which case SCALE becomes a relative ananagram (LACES is not in the
same domain) but NOTE is not since it can produce TONE.
Write a program that will read in the dictionary of a restricted domain and determine the relative
ananagrams. Note that single letter words are, ipso facto, relative ananagrams since they cannot be
?¡ãrearranged?¡À at all. The dictionary will contain no more than 1000 words.
Input
Input will consist of a series of lines. No line will be more than 80 characters long, but may contain any
number of words. Words consist of up to 20 upper and/or lower case letters, and will not be broken
across lines. Spaces may appear freely around words, and at least one space separates multiple words
on the same line. Note that words that contain the same letters but of differing case are considered to
be anagrams of each other, thus ??tIeD?¡¥ and ??EdiT?¡¥ are anagrams. The file will be terminated by a line
consisting of a single ??#?¡¥.
Output
Output will consist of a series of lines. Each line will consist of a single word that is a relative ananagram
in the input dictionary. Words must be output in lexicographic (case-sensitive) order. There will always
be at least one relative ananagram.
Sample Input
ladder came tape soon leader acme RIDE lone Dreis peat
ScAlE orb eye Rides dealer NotE derail LaCeS drIed
noel dire Disk mace Rob dries
#
Sample Output
Disk
NotE
derail
drIed
eye
ladder
soon
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
void xx(string &c) {
	for (int i = 0; i < c.size(); ++i)
		c[i] = tolower(c[i]);
}
int main() {
	map<string, vector<char> > a;
	string b, c;
	while (cin >> b, b != "#") {
		for (int i = 0; i < b.length(); ++i)
			if (!isalpha(b[i]))
				b[i] = ' ';
		stringstream s(b);
		while (s >> c) {
			pair<string, vector<char> > temp;
			vector<char> tc;
			temp.first = c;
			xx(c);
			for (int i = 0; i < c.size(); ++i)
				tc.push_back(c[i]);
			sort(tc.begin(), tc.end());
			temp.second = tc;
			a.insert(temp);
		}
 	};
	for (map<string, vector<char> >::iterator i = a.begin(); i != a.end(); i++) {
		for (map<string, vector<char> >::iterator j = a.begin(); j != a.end(); j++) {
			if (i == j)
				continue;
			if (i->second == j->second) {
				vector<char>temp;
				temp=i->second;
				for (map<string, vector<char> >::iterator k = a.begin(); k != a.end(); k++)
					if (temp == k->second) {
						a.erase(k);
						k = a.begin();
					}
				i = a.begin();
				break;
			}
		}
	}
	for (map<string, vector<char> >::iterator i = a.begin(); i != a.end(); i++)
		cout << i->first << endl;
}
