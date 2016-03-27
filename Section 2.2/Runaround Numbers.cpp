/*
仔细读题，利用hash思想，即可解决
*/
/*
ID: Jming
PROG: runround
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
const int MaxN = 40;
const int MaxM = 20;

unsigned long N;

bool isLegal(unsigned long num)
{
	char chStr[25];
	sprintf(chStr, "%d", num);
	string str = chStr;

	bool digit[10];
	fill(digit, digit + 10, false);
	digit[0] = true;	// none of which is zero
	// unique digits
	for (int i = 0; i < str.size(); ++i)
	{
		if (digit[str[i] - '0'])
		{
			return false;
		}
		digit[str[i] - '0'] = true;
	}

	bool isVisited[25];
	fill(isVisited, isVisited + 25, false);
	int start = 0, Flag = 0;
	// an interesting property
	do
	{
		int pos = (start + (str[start] - '0')) % str.size();
		if ((pos == start) || isVisited[pos])
		{
			return false;
		}
		isVisited[pos] = true;
		start = pos;
	} while (start != Flag);
	for (int i = 0; i < str.size(); ++i)
	{
		if (!isVisited[i])
		{
			return false;
		}
	}
	return true;
}

void Solve()
{
	unsigned long i = N + 1;
	while (!isLegal(i))
	{
		++i;
	}
	cout << i << endl;
}

int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);

	cin >> N;
	Solve();

#ifdef HOME
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << " ms" << endl;
#endif
	return 0;
}
