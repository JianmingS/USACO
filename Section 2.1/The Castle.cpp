/*
搜索 1A
*/

/*
ID: Jming
PROG: castle
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

int castle[MaxN][MaxM];
bool visited[MaxN][MaxM];
int N, M;
const int direction[4] = { 1, 2, 4, 8 }; // 西 北 东 南
const int step[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

struct Node
{
    // (x, y)代表房间坐标 
    // z代表拆的(x, y)房间哪面墙，z只会代表两种可能N,E
    int x, y, z;
};

bool Cmp(const Node &nd1, const Node &nd2)
{
	if (nd1.y == nd2.y)
	{
		if (nd1.x == nd2.x)
		{
			return (nd1.z < nd2.z);
		}
		else
		{
			return (nd1.x > nd2.x);
		}
	}
	else
	{
		return (nd1.y < nd2.y);
	}
}

void searchRoom(int x, int y, int &roomSize)
{
	if (!visited[x][y])
	{
		++roomSize;
		visited[x][y] = true;
		for (int i = 0; i < 4; ++i)
		{
			if (!(castle[x][y] & direction[i]))
			{
				int x1 = x + step[i][0];
				int y1 = y + step[i][1];
				if ((x1 >= 0) && (x1 < M) && (y1 >= 0) && (y1 < N))
				{
					//cout << x1 << "  " << y1 << endl;
					searchRoom(x1, y1, roomSize);
				}
			}
		}
	}
}

void removeWall()
{
	vector<Node> vecNd;
	int mergeRoomSize = 0;
	for (int x = 0; x < M; ++x)
	{
		for (int y = 0; y < N; ++y)
		{
            // 只要考虑去拆一个房间的北面、东面墙就好了
			for (int i = 1; i <= 2; ++i)
			{
				if (castle[x][y] & direction[i])
				{
					memset(visited, false, sizeof(visited));
					castle[x][y] ^= direction[i];
					int roomSize = 0;
					searchRoom(x, y, roomSize);
					if (roomSize >= mergeRoomSize)
					{
						if (roomSize > mergeRoomSize)
						{
							vecNd.clear();
							mergeRoomSize = roomSize;
						}
						Node nd;
						nd.x = x;
						nd.y = y;
						nd.z = i;
						vecNd.push_back(nd);
					}
					castle[x][y] ^= direction[i];
				}
			}
		}
	}
	printf("%d\n", mergeRoomSize);
	sort(vecNd.begin(), vecNd.end(), Cmp);
	printf("%d %d ", vecNd[0].x + 1, vecNd[0].y + 1);
	if (vecNd[0].z == 1)
	{
		printf("N\n");
	}
	else
	{
		printf("E\n");
	}
}

void Solve()
{
	int roomSum = 0;
	int roomMaxSize = 0;
	for (int x = 0; x < M; ++x)
	{
		for (int y = 0; y < N; ++y)
		{
			if (!visited[x][y])
			{
				//cout << endl << endl << x << "  " << y << endl;
				++roomSum;
				int roomSize = 0;
				searchRoom(x, y, roomSize);
				roomMaxSize = max(roomMaxSize, roomSize);
			}
		}
	}
	printf("%d\n", roomSum);
	printf("%d\n", roomMaxSize);

}

int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);

	scanf("%d %d", &N, &M);
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &castle[i][j]);
		}
	}
	Solve();
	removeWall();

#ifdef HOME
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << " ms" << endl;
#endif
	return 0;
}

