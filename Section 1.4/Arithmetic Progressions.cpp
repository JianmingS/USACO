/*
需要注意两个可以优化的地方：
1）预处理，找到all integers of the form p^2 + q^2 
	(where p and q are non-negative integers)
2）判断以a为等差数列的第一个值，b为等差数列的公差时，会不会超过(p^2 + q^2)的上界

代码中相应位置做了说明。

*/

#define _CRT_SECURE_NO_WARNINGS
#define HOME
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

/*
ID: Jming
PROG: ariprog
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
const int MaxA = 250 * 250 + 250 * 250 + 10;
const int MaxB = 10010;

int N, M;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pair_ans;
bool isLegal[MaxA];

int limVal;


void ini()
{
	/*
	预处理，找到all integers of the form p^2 + q^2 
	(where p and q are non-negative integers)
	*/
	fill(isLegal, isLegal + MaxA + 1, false);
	int doubleVal[255];
	for (int i = 0; i <= M; ++i)
	{
		doubleVal[i] = i*i;
	}
	for (int i = 0; i <= M; ++i)
	{
		for (int j = 0; j <= M; ++j)
		{
			isLegal[doubleVal[i] + doubleVal[j]] = true;
		}
	}

}


void Solve()
{
	for (int a = 0; a <= limVal; ++a)
	{
		for (int b = 1; b <= limVal; ++b)
		{
			if (a + (N - 1)*b > limVal)
			{
				/*
				判断以a为等差数列的第一个值，b为等差数列的公差时，
				会不会超过(p^2 + q^2)的上界
				*/
				break;
			}
			int nowVal = a;
			int cnt = 0;
			while (true)
			{
				if (isLegal[nowVal])
				{
					++cnt;
				}
				else
				{
					break;
				}
				if (cnt == N)
				{
					pair<int, int> pII;
					pII.first = b;
					pII.second = a;
					pair_ans.push(pII);
					break;
				}
				nowVal += b;
			}
		}
	}
}


void printAns()
{
	if (pair_ans.empty())
	{
		puts("NONE");
	}
	else
	{
		while (!pair_ans.empty())
		{
			printf("%d %d\n", pair_ans.top().second, pair_ans.top().first);
			pair_ans.pop();
		}
	}
}

int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);

	scanf("%d %d", &N, &M);
	limVal = M*M + M*M;
	ini();
	Solve();
	printAns();


#ifdef HOME
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << " ms" << endl;
	_CrtDumpMemoryLeaks();
#endif
	return 0;
}




