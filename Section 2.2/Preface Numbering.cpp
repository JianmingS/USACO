/*
发现规律，可生成出个、十、白、千的罗马数字。
然后，直接1~N枚举，统计字符出现次数。
*/
/*
ID: Jming
PROG: preface
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
const int MaxN = (1<<8) + 10;
const int MaxM = 20;

const string sig = "IVXLCDM";
vector<string> one;
vector<string> ten;
vector<string> hundred;
vector<string> thousand;

int N;
map<int, vector<string> > mapIS;

void ini(vector<string> &vecStr, string sign)
{
	vecStr.push_back("");
	string str;
	str = sign[0];
	for (int i = 0; i < 3; ++i)
	{
		vecStr.push_back(str);
		str += sign[0];
	}
	if (sign.size() == 1)
	{
		return;
	}
	str = sign[1];
	vecStr.push_back(sign[0] + str);
	for (int i = 0; i < 4; ++i)
	{
		vecStr.push_back(str);
		str += sign[0];
	}
	str = sign[2];
	vecStr.push_back(sign[0] + str);
}

void Solve()
{
	string str;
	for (int i = 1; i <= N; ++i)
	{
		int num = i;
		int cnt = 1;
		while (num)
		{
			int digit = num % 10;
			str = mapIS[cnt][digit] + str;
			num /= 10;
			++cnt;
		}
	}
	map<char, int> mapCI;
	for (int i = 0; i < str.size(); ++i)
	{
		if (mapCI.find(str[i]) == mapCI.end())
		{
			mapCI[str[i]] = 1;
		}
		else
		{
			++mapCI[str[i]];
		}
	}
	for (int i = 0; i < 7; ++i)
	{
		if (mapCI.find(sig[i]) != mapCI.end())
		{
			printf("%c %d\n", sig[i], mapCI[sig[i]]);
		}
	}
}

int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);
	ini(one, "IVX");
	ini(ten, "XLC");
	ini(hundred, "CDM");
	ini(thousand, "M");

	mapIS[1] = one;
	mapIS[2] = ten;
	mapIS[3] = hundred;
	mapIS[4] = thousand;
	scanf("%d", &N);
	Solve();


#ifdef HOME
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << " ms" << endl;
#endif
	return 0;
}
