/*
	搜索即可
*/
/*
ID: Jming
PROG: zerosum
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
const int MaxN = 210;
const int MaxK = 110;
const int Mod = 9901;

const char symbol[] = { '+', '-', ' ' };
int N;
char arr[20];
int arrLen;
vector<string> ans;

bool ZeroSum(string str)
{
	str = "0+" + str;
	int sum = str[0] - '0';
	int num = 0;
	for (size_t i = 2; i < str.size(); i += 2)
	{
		num = str[i] - '0';
		char syb = str[i - 1];
		while ((i + 1 < str.size()) && (' ' == str[i + 1]))
		{
			num = num * 10 + (str[i + 2] - '0');
			i += 2;
		}
		switch (syb)
		{
		case '+':
		{
			sum += num;
			break;
		}
		case '-':
		{
			sum -= num;
			break;
		}
		default:
			break;
		}
	}
	return (0 == sum);
}

void Dfs(int pos)
{
	if (pos == arrLen)
	{
		if (ZeroSum(arr))
		{
			ans.push_back(arr);
		}
		return;
	}
	for (size_t j = 0; j < strlen(symbol); ++j)
	{
		arr[pos] = symbol[j];
		Dfs(pos + 2);
	}
}


void Solve()
{
	arrLen = ((N << 1) - 1);
	int num = 1;
	for (size_t i = 0; i < arrLen; i += 2)
	{
		arr[i] = ('0' + num);
		++num;
	}
	Dfs(1);
	sort(ans.begin(), ans.end());
	for (size_t i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << endl;
	}
}


int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);

	cin >> N;
	Solve();


#ifdef HOME
	std::cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << "s" << endl;
#endif
	return 0;
}
