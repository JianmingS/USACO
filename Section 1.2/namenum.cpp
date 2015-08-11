/*
ID: Jming
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
using namespace std;
const int MAX = 26;
map<int, string> myMap;
bool ansJudge;

struct Trie{
	bool Judge;
	Trie* next[MAX];
	Trie() {
		Judge = false;
		memset(next, NULL, sizeof(next));
	}
};

Trie* Root;

void CreTrie(string str) {
	int len = str.size();
	Trie* p = Root;
	for (int i = 0; i < len; ++i) {
		int pos = str[i] - 'A';
		if (!(p->next[pos])) {
			p->next[pos] = new Trie;
		}
		p = p->next[pos];
	}
	p->Judge = true;
}

void DelTrie(Trie* T) {
	for (int i = 0; i < MAX; ++i) {
		if (T->next[i]) {
			DelTrie(T->next[i]);
		}
	}
	delete[] T;
}

void Ini() {
	ifstream fcin("dict.txt");
	if (!fcin) {
        system("pause");
	}
	string str;
	while (fcin >> str) {
		CreTrie(str);
	}
	myMap[2] = "ABC"; myMap[3] = "DEF"; myMap[4] = "GHI"; myMap[5] = "JKL";
	myMap[6] = "MNO"; myMap[7] = "PRS"; myMap[8] = "TUV"; myMap[9] = "WXY";
}

void Dfs(string str, int pos, Trie* T, string ansStr) {
	for (int i = 0; i < 3; ++i) {
		Trie* t_Trie = T->next[myMap[str[pos] - '0'][i] - 'A'];
		if (t_Trie) {
			if ((t_Trie->Judge) && (pos == (str.size() - 1))) {
                if (!ansJudge) ansJudge = true;
				cout << ansStr + myMap[str[pos] - '0'][i] << endl;
			}
			else Dfs(str, pos + 1, t_Trie, ansStr + myMap[str[pos] - '0'][i]);
		}
	}
}

int main()
{
   Root = new Trie;
   ansJudge = false;
	Ini();
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);
	string str;
	cin >> str;
	Dfs(str, 0, Root, "");
	if (!ansJudge) {
        cout << "NONE" << endl;
	}
	DelTrie(Root);
	return 0;
}
