/*
     生成回文数 + 判断是否为质数
*/
/*
ID: Jming
PROG: pprime
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
const int MaxN = 100000010;
const int MaxM = 10010;


vector<int> legal;


// 判断是否为质数
bool isPrime(int x)
{
	for (int i = 2; i*i <= x; ++i)
	{
		if (x%i == 0)
		{
			return false;
		}
	}
	return true;
}

// 保存答案
void getAns(int x)
{
	if (isPrime(x))
	{
		legal.push_back(x);
	}
}

// 生成回文数
void getPdm()
{
	int palindrome;

	for (int i1 = 1; i1 <= 9; i1 += 2)
	{
		// 1
		palindrome = i1;
		getAns(palindrome);
		// 2
		palindrome = i1 * 10 + i1;
		getAns(palindrome);
	}

	for (int i1 = 1; i1 <= 9; i1 += 2)
	{
		for (int i2 = 0; i2 <= 9; ++i2)
		{
			// 3
			palindrome = i1 * 100 + i2 * 10 + i1;
			getAns(palindrome);
			// 4
			palindrome = i1 * 1000 + i2 * 100 + i2 * 10 + i1;
			getAns(palindrome);
		}
	}

	for (int i1 = 1; i1 <= 9; i1 += 2)
	{
		for (int i2 = 0; i2 <= 9; ++i2)
		{
			for (int i3 = 0; i3 <= 9; ++i3)
			{
				// 5
				palindrome =
					i1 * 10000 + i2 * 1000 + i3 * 100 +
					i2 * 10 + i1;
				getAns(palindrome);
				// 6
				palindrome =
					i1 * 100000 + i2 * 10000 + i3 * 1000 +
					i3 * 100 + i2 * 10 + i1;
				getAns(palindrome);
			}
		}
	}

	for (int i1 = 1; i1 <= 9; i1 += 2)
	{
		for (int i2 = 0; i2 <= 9; ++i2)
		{
			for (int i3 = 0; i3 <= 9; ++i3)
			{
				for (int i4 = 0; i4 <= 9; ++i4)
				{
					// 7
					palindrome =
						i1 * 1000000 + i2 * 100000 + i3 * 10000 + i4 * 1000 +
						i3 * 100 + i2 * 10 + i1;
					getAns(palindrome);
					// 8
					palindrome =
						i1 * 10000000 + i2 * 1000000 + i3 * 100000 + i4 * 10000 +
						i4 * 1000 + i3 * 100 + i2 * 10 + i1;
					getAns(palindrome);
				}
			}
		}
	}
}



int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);

	

	getPdm();
	sort(legal.begin(), legal.end());
	int a, b;
	scanf("%d %d", &a, &b);
	int i = 0;
	while (legal[i] < a) ++i;
	while ((i<legal.size()) && legal[i] <= b)
	{
		printf("%d\n", legal[i]);
		++i;
	}



#ifdef HOME
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << " ms" << endl;
	_CrtDumpMemoryLeaks();
#endif
	return 0;
}
