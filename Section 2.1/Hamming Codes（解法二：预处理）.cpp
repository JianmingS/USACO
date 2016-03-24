/*
枚举
预先处理出codewords间的Hamming distance，保存在数组中。
*/
/*
ID: Jming
PROG: hamming
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
const int MaxN = (1<<8) + 10;
const int MaxM = 20;

int N, B, D;
vector<int> ans;
int dis[MaxN][MaxN];

int hamDis(int x, int y)
{
	int z = x^y;
	int cnt = 0;
	while (z)
	{
		if (z & 1)
		{
			++cnt;
		}
		z >>= 1;
	}
	return cnt;
}

void ini()
{
	int maxVal = (1 << B);
	for (int i = 0; i < maxVal; ++i)
	{
		for (int j = i + 1; j < maxVal; ++j)
		{
			dis[i][j] = hamDis(i, j);
		}
	}
}

void Solve()
{
	ans.push_back(0);
	int cnt = 1;
	int val = 1;
	while (cnt != N)
	{
		bool judge = true;
		for (int i = 0; i < ans.size(); ++i)
		{
			if (dis[ans[i]][val] < D)
			{
				judge = false;
				break;
			}
		}
		if (judge)
		{
			++cnt;
			ans.push_back(val);
		}
		++val;
	}
}

void output()
{
	for (int i = 1; i <= ans.size(); ++i)
	{
		printf("%d", ans[i - 1]);
		if (i != ans.size())
		{
			if (i % 10)
			{
				printf(" ");
			}
			else
			{
				printf("\n");
			}
		}
	}
	printf("\n");
}


int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
	scanf("%d %d %d", &N, &B, &D);
	ini();
	Solve();
	output();

#ifdef HOME
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << " ms" << endl;
#endif
	return 0;
}
