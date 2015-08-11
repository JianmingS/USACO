/*
ID: Jming
PROG: crypt1
LANG: C++
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
#define eps 1e-8
int myArr[15];
int N;

bool myJudge(int x) {
	while (x) {
		int tmp1 = x % 10;
		int i;
		for (i = 0; i < N; ++i) {
			if (tmp1 == myArr[i]) {
				break;
			}
		}
		if (i == N) {
			return false;
		}
		x /= 10;
	}
	return true;
}

void Solve() {
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				int mydata = myArr[i] * 100 + myArr[j] * 10 + myArr[k];

				for (int m = 0; m < N; ++m) {
					int data1 = mydata * myArr[m];
					if (!myJudge(data1)) continue;
					if (data1 >= 1000) continue;

					for (int n = 0; n < N; ++n) {
						int data2 = mydata * myArr[n];
						if (!myJudge(data2)) continue;
						if (data2 >= 1000) continue;
						int myMul = data1 + data2 * 10;
						if (!myJudge(myMul)) continue;
						if (myMul >= 10000) continue;
						++ans;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &myArr[i]);
	}
	Solve();
	return 0;
}