/*
	dp[i][j] := 在层数小于等于i，节点数恰为j的情况下，家谱树的个数。
	dp[i][j] = ∑(dp[i-1][n] * dp[i-1][j-1-n])
		即：∑（左子树*右子树）
	初始化：dp[i][0] = 1
	答案：
		ans := 层数恰为K，节点数恰为N的情况下，家谱树的个数。
		ans = dp[K][N] - dp[K-1][N]
*/
/*
ID: Jming
PROG: nocows
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
const int MaxN = 210;
const int MaxK = 110;
const int Mod = 9901;

int N, K;
int dp[MaxK][MaxN];

void Solve()
{
	for (int i = 0; i <= K; ++i)
	{
		dp[i][0] = 1;
	}
	for (int i = 1; i <= K; ++i)
	{
		for (int j = 1; j <= N; j += 2)
		{
			for (int n = 0; n <= (j - 1); ++n)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][n] * dp[i - 1][j - 1 - n]) % Mod;
				//cout << i << "层" << j << "个节点" << " ---> " << dp[i][j] << endl;
			}
		}
	}
	// 由于dp[K][N]取余之后，可能小于dp[K-1][N]，所以先加Mod再取余。
	cout << (dp[K][N] - dp[K - 1][N] + Mod)%Mod << endl;
}


int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);

	cin >> N >> K;
	Solve();


#ifdef HOME
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << "s" << endl;
#endif
	return 0;
}
