/*
     生成回文数 + 判断是否为质数
备注：
    sprintf：整数转换为字符串
    atoi：字符串转换为int
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
const int MaxN = 10010;
const int MaxM = 10010;


int A, B;

// 判断是否为质数
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

void gen(int x, int isOdd)
{
	char buf[10];

	sprintf(buf, "%d", x);

	char *p, *q;

	p = buf + strlen(buf);
	
	q = p - isOdd;

	while (q > buf)
	{
		*(p++) = *(--q);
	}

	*p = '\0';

	int n = atoi(buf);

	if ((n >= A) && (n <= B) && (isPrime(n)))
	{
		printf("%d\n", n);
	}
}



void getPdm(int start, int end)
{
	for (int i = start; i <= end; ++i)
	{
        // 生成位数是奇数的回文数
		gen(i, 1);
	}
	for (int i = start; i <= end; ++i)
	{
        // 生成位数是偶数的回文数
		gen(i, 0);
	}
}

void Solve()
{
	getPdm(1, 9);
	getPdm(10, 99);
	getPdm(100, 999);
	getPdm(1000, 9999);
}

int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);

	scanf("%d %d", &A, &B);
	Solve();


#ifdef HOME
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << " ms" << endl;
	_CrtDumpMemoryLeaks();
#endif
	return 0;
}
