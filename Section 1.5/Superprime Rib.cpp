/*

此题可利用 “当前生成位数为n的数是否为质数” 进行剪枝

递归，详见代码
*/

/*
ID: Jming
PROG: sprime
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
const int MaxN = 10010;
const int MaxM = 10010;

int N;

bool isPrime(int x)
{
	if (x < 2)
	{
		return false;
	}
	for (int i = 2; i*i <= x; ++i)
	{
		if (x%i == 0)
		{
			return false;
		}
	}
	return true;
}


void Solve(int val, int n)
{
	if (n == N)
	{
		printf("%d\n", val);
		return;
	}
	for (int i = 1; i <= 9; ++i)
	{
		int tmp = val * 10 + i;
		// 剪枝
		if (isPrime(tmp))
		{
			Solve(tmp, n + 1);
		}
	}
}

int main()
{
#ifdef HOME
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);

	while (~scanf("%d", &N))
	{
		Solve(0, 0);
	}

#ifdef HOME
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << " ms" << endl;
	_CrtDumpMemoryLeaks();
#endif
	return 0;
}