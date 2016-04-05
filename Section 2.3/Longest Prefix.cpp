/*
dp:
	dp[i] := 第i个位置是否继续可放集合里面的某一个元素（数组从0开始编号）
	dp[i + len(集合里面的元素)] = true

初始化：dp[0] = true

答案：dp数组从S.size()位置开始，向前遍历，如果dp[i] = true，i即为答案。
*/
/*
ID: Jming
PROG: prefix
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
const int MaxN = 200010;
const int MaxM = 20;

bool dp[MaxN];
vector<string> vecStr;
string S;

void Solve()
{
	fill(dp, dp + MaxN, false);
	dp[0] = true;
	for (int i = 0; i < S.size(); ++i)
	{
		if (dp[i])
		{
			for (int j = 0; j < vecStr.size(); ++j)
			{
				int k = 0;
				for (; k < vecStr[j].size(); ++k)
				{
					if (S[k + i] != vecStr[j][k])
					{
						break;
					}
				}
				if (vecStr[j].size() == k)
				{
					dp[i + vecStr[j].size()] = true;
					int a = 0;
				}
			}
		}
	}
	for (int i = S.size(); i >= 0; --i)
	{
		if (dp[i])
		{
			cout << i << endl;
			return;
		}
	}
}


int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);

	string inStr;
	while ((cin >> inStr) && ("." != inStr))
	{
		vecStr.push_back(inStr);
	}
	while (cin >> inStr)
	{
		S += inStr;
	}
	Solve();


#ifdef HOME
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << " ms" << endl;
#endif
	return 0;
}
