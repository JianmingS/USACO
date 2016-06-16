/*
ID: Jming
PROG: maze1
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
const int step[4][2] = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 } };

int W, H;
int ans = 0;
vector<string> maze;
int exit_x1 = -1, exit_y1 = -1;
int exit_x2, exit_y2;
int dis[202][80];

// 找到两个出口
void getExit()
{
	for (int i = 0; i != H; ++i)
	{
		for (int j = 0; j != W; ++j)
		{
			dis[i][j] = INF;	// 初始化距离 INF
			if (' ' == maze[i][j])
			{
				if (i == 0 || i + 1 == H || j == 0 || j + 1 == W)
				{
					if (-1 == exit_x1)
					{
						exit_x1 = i;
						exit_y1 = j;
					}
					else
					{
						exit_x2 = i;
						exit_y2 = j;
					}
				}
			}
		}
	}
}

void Solve(int x1, int y1, int x2, int y2)
{
	dis[x1][y1] = 0;
	dis[x2][y2] = 0;
	queue<pair<int, int> > toVisPos;
	toVisPos.push(make_pair(x1, y1));
	toVisPos.push(make_pair(x2, y2));
	while (!toVisPos.empty())
	{
		pair<int, int> pos = toVisPos.front();
		toVisPos.pop();
		int x = pos.first, y = pos.second;
		for (int i = 0; i != 4; ++i)
		{
			int xTmp = x + step[i][0];
			int yTmp = y + step[i][1];

			if ((xTmp >= 0) && (xTmp < H) && (yTmp >= 0) && (yTmp < W)
				&& (' ' == maze[xTmp][yTmp]))
			{
				if (dis[x][y] + 1 < dis[xTmp][yTmp])
				{
					toVisPos.push(make_pair(xTmp, yTmp));
					/*
						只有坐标(x, y)中，x和y均为奇数才是路；
						若x和y中任意一个或同时为偶数，则为栅栏。
					*/
					if ((xTmp&1) && (yTmp&1))
					{
						dis[xTmp][yTmp] = dis[x][y] + 1;
					}else
					{
						dis[xTmp][yTmp] = dis[x][y];
					}

				}
			}
		}
	}
}

int main()
{
#ifdef HOME
	time_t startTime, endTime;
	startTime = clock();
	std::freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);


	cin >> W >> H;
	W = (W << 1) + 1;
	H = (H << 1) + 1;
	getchar();
	for (int i = 0; i != H; ++i)
	{
		string strTmp;
		getline(cin, strTmp);
		maze.push_back(strTmp);
	}
	getExit();
	Solve(exit_x1, exit_y1, exit_x2, exit_y2);

	for (int i = 0; i != H; ++i)
	{
		for (int j = 0; j != W; ++j)
		{
			if (dis[i][j] != INF)
			{
				ans = max(ans, dis[i][j]);
			}
		}
	}

	cout << ans << endl;


#ifdef HOME
	endTime = clock();
	cout << "Time elapsed: " << (endTime - startTime) << "ms" << endl;
	std::cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << "s" << endl;
#endif
	return 0;
}
