/*
ID: Jming
PROG: frac1
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
const int MaxN = 55;
const int MaxM = 55;

struct Fraction
{
	int numerator;
	int denominator;
};

int N;

int Gcd(int a, int b)
{
	if (0 == b) return a;
	return Gcd(b, a%b);
}

// double 比较函数需要自己写，否则在USACO测试平台上，map无法滤掉相同的double键值
struct classcomp { 
	bool operator() (const double& lhs, const double& rhs) const
	{
		return (lhs < rhs);
	}
};

void Solve()
{
	map<double, Fraction, classcomp> ndMap;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			double val = static_cast<double>(j) / static_cast<double>(i);
			if (ndMap.find(val) == ndMap.end())
			{
				Fraction fc;
				int gcd = Gcd(i, j);
				fc.numerator = j/gcd;
				fc.denominator = i/gcd;
				ndMap[val] = fc;
			}
		}
	}
	for (map<double, Fraction>::const_iterator cnt_it = ndMap.begin(); cnt_it != ndMap.end(); ++cnt_it)
	{

		cout << (*cnt_it).second.numerator << "/" << (*cnt_it).second.denominator << endl;
	}
}

int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);

	scanf("%d", &N);
	Solve();

#ifdef HOME
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << " ms" << endl;
#endif
	return 0;
}
