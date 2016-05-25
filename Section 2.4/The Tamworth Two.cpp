/*
	模拟
*/
/*
ID: Jming
PROG: ttwo
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
const int MaxN = 15;
const int MaxM = 110;

string Map[MaxN];
bool visited[MaxN][MaxN][4][MaxN][MaxN][4];

// 0:北，1：南，2：西，3：东
int step[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };


bool posLegal(int x)
{
	if (x >= 0 && x < 10)
	{
		return true;
	}
	return false;
}

void changeDit(int &dit)
{
	if (0 == dit)
	{
		dit = 3;
		return;
	}
	if (1 == dit)
	{
		dit = 2;
		return;
	}
	if (2 == dit)
	{
		dit = 0;
		return;
	}
	if (3 == dit)
	{
		dit = 1;
		return;
	}
}


void Solve(int fmX, int fmY, int cX, int cY, int ditF, int ditC, int time)
{
	if ((fmX == cX) && (fmY == cY))
	{
		cout << time << endl;
		return;
	}

	int fmX_tmp = fmX + step[ditF][0];
	int fmY_tmp = fmY + step[ditF][1];

	if (!posLegal(fmX_tmp) || !posLegal(fmY_tmp) || Map[fmX_tmp][fmY_tmp] == '*')
	{
		changeDit(ditF);
	}else
	{
		fmX = fmX_tmp;
		fmY = fmY_tmp;
	}

	int cX_tmp = cX + step[ditC][0];
	int cY_tmp = cY + step[ditC][1];

	if (!posLegal(cX_tmp) || !posLegal(cY_tmp) || Map[cX_tmp][cY_tmp] == '*')
	{
		changeDit(ditC);
	}else
	{
		cX = cX_tmp;
		cY = cY_tmp;
	}

	if (visited[fmX][fmY][ditF][cX][cY][ditC])
	{
		cout << 0 << endl;
		return;
	}
	visited[fmX][fmY][ditF][cX][cY][ditC] = true;
	//cout << fmX << " " << fmY << " " << ditF << " "
	//	<< cX << " " << cY << " " << ditC << endl;
	Solve(fmX, fmY, cX, cY, ditF, ditC, time + 1);
}

int main()
{
#ifdef HOME
	time_t startTime, endTime;
	startTime = clock();
	// std::freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);

	memset(visited, false, sizeof(visited));

	int fmX = 0, fmY = 0;
	int cX = 0, cY = 0;

	for (int i = 0; i != 11; ++i)
	{
		cin >> Map[i];
		for (int j = 0; j != Map[i].size(); ++j)
		{
			if ('F' == Map[i][j])
			{
				fmX = i;
				fmY = j;
			}else
			{
				if ('C' == Map[i][j])
				{
					cX = i;
					cY = j;
				}
			}
		}
	}
	Solve(fmX, fmY, cX, cY, 0, 0, 0);


#ifdef HOME
	endTime = clock();
	cout << "Time elapsed: " << (endTime - startTime) << "ms" << endl;
	std::cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << "s" << endl;
#endif
	return 0;
}
