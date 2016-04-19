
/*
	两个步骤：
		（1）添加 company A owning p% of company B
		（2）添加 company A controls company B
*/

/*
ID: Jming
PROG: concom
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
const int MaxN = 110;
const int MaxM = 110;

int N;
bool controlling[MaxN][MaxN];
int own[MaxN][MaxN];

// 添加 company A controls company B
void addControl(int a, int b)
{
	if (controlling[a][b])
	{
		return;
	}
	controlling[a][b] = true;

	for (int i = 0; i < MaxN; ++i)
	{
		own[a][i] += own[b][i];
	}

	// 控制A的公司，也可以控制公司B了
	for (int i = 1; i < MaxN; ++i)
	{
		if (controlling[i][a])
		{
			addControl(i, b);
		}
	}

	// A控制更多的公司
	for (int i = 1; i < MaxN; ++i)
	{
		if (own[a][i] > 50)
		{
			addControl(a, i);
		}
	}
}

// 添加 company A owning p% of company B
void addOwn(int a, int b, int p)
{
	//  添加 company 控制A owning p% of company B
	for (int i = 1; i < MaxN; ++i)
	{
		if (controlling[i][a])
		{
			own[i][b] += p;
		}
	}
	for (int i = 1; i < MaxN; ++i)
	{
		if (own[i][b] > 50)
		{
			addControl(i, b);
		}
	}
}

int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);

	memset(controlling, false, sizeof(controlling));

	// Company A = Company B
	for (int i = 0; i < MaxN; ++i)
	{
		controlling[i][i] = true;
	}
	cin >> N;
	int a, b, p;
	for (int i = 0; i < N; ++i)
	{
		cin >> a >> b >> p;
		addOwn(a, b, p);
	}

	for (int i = 1; i < MaxN; ++i)
	{
		for (int j = 1; j < MaxN; ++j)
		{
			if ((i != j) && controlling[i][j])
			{
				cout << i << " " << j << endl;
			}
		}
	}

#ifdef HOME
	std::cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << "s" << endl;
#endif
	return 0;
}
