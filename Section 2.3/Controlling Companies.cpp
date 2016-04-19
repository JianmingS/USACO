/*
	模拟控制公司的三个条件，逐渐更新公司之间控制的状态。
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
int stock[MaxN][MaxN];

void Solve()
{
	bool updated = true;
	while (updated)
	{
		updated = false;
		/*
			Company A controls K(K >= 1) companies denoted C1, ..., CK with
			each company Ci owning xi% of company B and x1 + .... + xK > 50%.
		*/
		for (int i = 1; i < MaxN; ++i)
		{
			for (int j = 1; j < MaxN; ++j)
			{
				if ((i != j) && !controlling[i][j])
				{
					int sum = 0;
					for (int k = 1; k < MaxN; ++k)
					{
						if (controlling[i][k])
						{
							sum += stock[k][j];
						}
					}
					if (sum > 50)
					{
						controlling[i][j] = true;
						if (!updated)
						{
							updated = true;
						}
					}
				}
			}
		}
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
	int a, b;
	for (int i = 0; i < N; ++i)
	{
		cin >> a >> b;
		cin >> stock[a][b];
		// Company A owns more than 50 % of Company B
		if (stock[a][b] > 50)
		{
			controlling[a][b] = true;
		}
	}
	Solve();

#ifdef HOME
	std::cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << "s" << endl;
#endif
	return 0;
}
