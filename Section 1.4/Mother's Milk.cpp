/*
题意关键： 
FJ pours milk from one bucket to another until 
the second bucket is filled or the first bucket is empty. 
（每一次倒牛奶都遵守这个原则）

深搜，判重
*/

#define _CRT_SECURE_NO_WARNINGS
#define HOME
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
/*
ID: Jming
PROG: milk3
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
const int MaxN = 25;
const int MaxM = 10010;

int A, B, C;
bool isVisited[25][25][25];
set<int> ansSet;

void Solve(int a, int b, int c)
{
	if (!isVisited[a][b][c])
	{
		isVisited[a][b][c] = true;
		if (0 == a)
		{
			ansSet.insert(c);
		}

		// C->A
		if (c >= (A - a))
		{
			Solve(A, b, c - (A - a));
		}
		else
		{
			Solve(a + c, b, 0);
		}

		// C->B
		if (c >= (B - b))
		{
			Solve(a, B, c - (B - b));
		}
		else
		{
			Solve(a, b + c, 0);
		}

		// B->A
		if (b >= (A - a))
		{
			Solve(A, b - (A - a), c);
		}
		else
		{
			Solve(a + b, 0, c);
		}

		// B->C
		if (b >= (C - c))
		{
			Solve(a, b - (C - c), C);
		}
		else
		{
			Solve(a, 0, c + b);
		}

		// A->B
		if (a >= (B - b))
		{
			Solve(a - (B - b), B, c);
		}
		else
		{
			Solve(0, b + a, c);
		}

		// A->C
		if (a >= (C - c))
		{
			Solve(a - (C - c), b, C);
		}
		else
		{
			Solve(0, b, c + a);
		}
	}
}


int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);

	scanf("%d %d %d", &A, &B, &C);
	memset(isVisited, false, sizeof(isVisited));
	Solve(0, 0, C);
	for (set<int>::iterator it = ansSet.begin(); it != ansSet.end(); )
	{
		printf("%d", *it);
		++it;
		if (it != ansSet.end())
		{
			printf(" ");
		}
	}
	printf("\n");

#ifdef HOME
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << " ms" << endl;
	_CrtDumpMemoryLeaks();
#endif
	return 0;
}