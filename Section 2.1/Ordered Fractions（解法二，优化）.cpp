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
// 判断a和b是否互质
bool isCoprimes(int a, int b)
{
	int r = a%b;
	while (r)
	{
		a = b;
		b = r;
		r = a%b;
	}
	return (1 == b);
}

// 分数比较大小（从小到大排序）
bool Cmp(const Fraction& f1, const Fraction& f2)
{
	return (f1.numerator*f2.denominator - f1.denominator*f2.numerator < 0);
}

void Solve()
{
	vector<Fraction> vecFra;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (isCoprimes(j, i)) // 滤掉化简相等的分数（i和j的顺序不能变，否则出现除以0的情况）
			{
				Fraction fra;
				fra.numerator = j;
				fra.denominator = i;
				vecFra.push_back(fra);
			}
		}
	}
	sort(vecFra.begin(), vecFra.end(), Cmp);
	for (int i = 0; i < vecFra.size(); ++i)
	{
		printf("%d/%d\n", vecFra[i].numerator, vecFra[i].denominator);
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