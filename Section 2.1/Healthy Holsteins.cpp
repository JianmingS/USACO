/*
枚举所有饲料种类能产生的组合，判断出满足条件的组合。
复杂度：N*(2^M)
注：
	N:the number of types of vitamins
	M:the number of types of feeds available
*/
/*
ID: Jming
PROG: holstein
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
const int MaxN = 30;
const int MaxM = 20;

int minReq[MaxN];
int feeds[MaxM][MaxN];
int N;
int M;
int ans[MaxN];
bool isRight = false;

bool check(const int numOftype)
{
	for (int i = 0; i < N; ++i)
	{
		int sum = 0;
		for (int j = 0; j < numOftype; ++j)
		{
			sum += feeds[ans[j]][i];
		}
		if (sum < minReq[i])
		{
			return false;
		}
	}
	return true;
}

void Dfs(int num, int pos, const int numOftype)
{
	if (num == numOftype)
	{
		isRight = check(numOftype);
		return;
	}
	for (int i = pos; i < M; ++i)
	{
		ans[num] = i;
		Dfs(num + 1, i + 1, numOftype);
		if (isRight)
		{
			return;
		}
	}
}


void Solve()
{
	for (int i = 1; i <= M; ++i)
	{
		Dfs(0, 0, i);
		if (isRight)
		{
			printf("%d ", i);
			sort(ans, ans + i);
			for (int j = 0; j < i; ++j)
			{
				printf("%d", ans[j] + 1);
				if (j != (i - 1))
				{
					printf(" ");
				}
			}
			printf("\n");
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

	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &minReq[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &feeds[i][j]);
		}
	}
	Solve();


#ifdef HOME
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << " ms" << endl;
#endif
	return 0;
}
