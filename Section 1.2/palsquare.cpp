/*
ID: Jming
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
int base;

struct myNode {
	int number;
	int square;
}node[305];

void Init() {
	for (int i = 1; i <= 300; ++i) {
		node[i - 1].number = i;
		node[i - 1].square = i * i;
	}
}

char judgeChar(int tmp) {
	if (tmp >= 0 && tmp <= 9) return ('0' + tmp);
	else return ('A' + (tmp - 10));
}

string getNum(int x) {
	string str = "";
	while (x >= base) {
		int tmp = x%base;
		x /= base;
		str = judgeChar(tmp) + str;
	}
	return (judgeChar(x) + str);
}

bool judgePalindromic(string str) {
	int myBegin = 0, myEnd = str.size() - 1, myCount = str.size() >> 1;
	for (int i = 0; i < myCount; ++i) {
		if (str[myBegin + i] != str[myEnd - i]) {
			return false;
		}
	}
	return true;
}

void Solve() {
	for (int i = 0; i < 300; ++i) {
		string str = getNum(node[i].square);
		if (judgePalindromic(str)) {
			cout << (getNum(node[i].number)) << " " << str << endl;
		}
	}
}

int main()
{
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
	Init();
	scanf("%d", &base);
	Solve();
	return 0;
}