/*
具体参考图Sorting a Three-Valued Sequence.png：
（1）先把需要交换一次的全部找出来
（2）再把需要交换两次的全部找出来
两者次数之和即为答案
*/

/*
ID: Jming
PROG: sort3
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
const int MaxN = 1010;
const int MaxM = 55;

int seq[MaxN];
int ascOrder[MaxN];

int N;


void Solve()
{
	int onceCnt = 0;
	for (int i = 0; i < N; ++i)
	{
		if (seq[i] != ascOrder[i])
		{
			for (int j = i + 1; j < N; ++j)
			{
				if ((seq[j] == ascOrder[i]) &&
					(seq[i] == ascOrder[j]))
				{
					swap(seq[i], seq[j]);
					++onceCnt;
					break;
				}
			}
		}
	}
	int twiceCnt = 0;
	for (int i = 0; i < N; ++i)
	{
		if (seq[i] != ascOrder[i])
		{
			++twiceCnt;
		}
	}
	twiceCnt = ((twiceCnt/3)<<1);

	printf("%d\n", onceCnt + twiceCnt);
}

int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &seq[i]);
		ascOrder[i] = seq[i];
	}
	sort(ascOrder, ascOrder + N);
	Solve();


#ifdef HOME
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << " ms" << endl;
#endif
	return 0;
}
