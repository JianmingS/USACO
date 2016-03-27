/*
01背包变形：
dp[i][j] := 前i个数，组成和恰为j的方式最大数目
dp[i][j] = dp[i-1][j] + dp[i-1][j-i] (j>=i)
空间优化
*/

/*
ID: Jming
PROG: subset
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
const int MaxN = 40;
const int MaxM = 20;

int N;
int goal;
int ans = 0;
// 注意：需为long long类型
long long dp[(((1 + MaxN)*MaxN) >> 2) + 10];

void Solve()
{
	if ((((1 + N)*N) >> 1) % 2)
	{
		// 找不到 the sums of both subsets are identical
		cout << 0 << endl;
		return;
	}
	int goal = (((1 + N)*N) >> 2);

	dp[0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = goal; j >= i; --j)
		{
			dp[j] += dp[j - i];
		}
	}
	cout << (dp[goal] >> 1) << endl;
}

int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);

	cin >> N;
	Solve();

#ifdef HOME
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << " ms" << endl;
#endif
	return 0;
}
