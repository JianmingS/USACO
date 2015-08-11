/*
ID: Jming
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
int base, N, S;

string getNum(int x) {
	string str = "";
	while (x >= base) {
		int tmp = x%base;
		x /= base;
		str = (char)('0' + tmp) + str;
	}
	return ((char)('0' + x) + str);
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
    int myCount = 1;
    while (myCount <= N) {
        ++S;
        int sum = 0;
        for (base = 2; base <= 10; ++base) {
            string str = getNum(S);
            if (judgePalindromic(str)) {
                ++sum;
                if (sum >= 2) break;
            }
        }
        if (sum >= 2) {
            printf("%d\n", S);
            ++myCount;
        }
    }
}

int main()
{
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);
	scanf("%d %d", &N, &S);
	Solve();
	return 0;
}



