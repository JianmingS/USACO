/*
	完全背包变形：(每个硬币都有无限个可用)
		dp[i][j] := 前i种硬币，恰构造出j的方案数
		dp[i][j] = dp[i-1][j] + dp[i][j-coin[i]]
*/
/*
ID: Jming
PROG: money
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
#include <bitset>
#include <functional>
#include <cassert>
using namespace std;
typedef pair<int, int> PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const int modPrime = 3046721;
const double eps = 1e-9;
const int MaxN = 10010;
const int MaxM = 110;

int V, N;
vector<int> availableCoins;
long long dp[MaxN];

void Solve()
{
	dp[0] = 1;
	for (int i = 0; i < V; ++i)
	{
		for (int j = availableCoins[i]; j <= N; ++j)
		{
			dp[j] = dp[j] + dp[j - availableCoins[i]];
		}
		/*
		// 01背包写法
		for (int j = N; j >= availableCoins[i]; --j)
		{
			for (int k = 1; k <= (j / availableCoins[i]); ++k)
			{
				dp[j] = dp[j] + dp[j - k*availableCoins[i]];
			}
		}
		*/
	}
	cout << dp[N] << endl;
}

int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);

	cin >> V >> N;
	int coin;
	for (int i = 0; i < V; ++i)
	{
		cin >> coin;
		availableCoins.push_back(coin);
	}
	Solve();

#ifdef HOME
	std::cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << "s" << endl;
#endif
	return 0;
}
