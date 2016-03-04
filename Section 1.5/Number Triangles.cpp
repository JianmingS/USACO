/*

DP 题

dp[j] = max(dp[j - 1] + tgl[i-1][j], dp[j] + tgl[i-1][j]);

*/

#define _CRT_SECURE_NO_WARNINGS
#define HOME
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

/*
ID: Jming
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cstddef>
#include <iterator>
#include <algorithm>
#include <string>
#include <locale>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <functional>
using namespace std;
typedef pair<int, int> PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const int modPrime = 3046721;
const double eps = 1e-9;
const int MaxN = 510000;
const int MaxM = 10010;


int N;
int dp[MaxN];
vector<vector<int> > tgl;


void Solve()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = i; j >= 1; --j)
		{
			dp[j] = max(dp[j - 1] + tgl[i-1][j], dp[j] + tgl[i-1][j]);
		}
	}
	cout << *max_element(dp, dp + MaxN) << endl;
}

int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);

	fill(dp, dp + MaxN, 0);
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		vector<int> row;
		row.push_back(0);
		int tmp;
		for (int j = 0; j < i; ++j)
		{
			scanf("%d", &tmp);
			row.push_back(tmp);
		}
		tgl.push_back(row);
	}

	Solve();

#ifdef HOME
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << " ms" << endl;
	_CrtDumpMemoryLeaks();
#endif
	return 0;
}
