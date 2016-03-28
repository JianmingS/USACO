/*
首先N最大值100，C最大值为10000，有4个按钮。
第一思路，直接暴搜的话，(4^10000)，必然超时。
所以，关键在于找出规律。。。
*************************************************************************************************
关键：两个规律
（1）只要考虑6个灯的状态就好了，编号大于6的灯x与编号为(x%6)的状态是一样的。（即每6个灯的状态是一个循环）
	原因：
		只考虑Button 1：每1个灯的状态是一个循环
		只考虑Button 2：每2个灯的状态是一个循环
		只考虑Button 3：每2个灯的状态是一个循环
		只考虑Button 4：每3个灯的状态是一个循环
		=> 取(1, 2, 2, 3)的最小公倍数，即：6

（2）首先我们知道一个button按两下，其实和没按这个button的效果是一样的。所以：
	C=0：灯全亮（初始状态）
	C=1：可能按了4个button中的任意1个
	C=2：可能按了4个button中的任意2个 【或者】 相当于 C=0（存在有两下相互抵消）
	C=3：可能按了4个button中的任意3个 【或者】 相当于 C=1（存在有两下相互抵消）
	C=4：可能按了4个button中的任意4个 【或者】 相当于 C=2（存在有两下相互抵消）
	可以类推至C>4的情况：
		C=5：仅有4个开关，按了5下，必然至少有两下的作用相互抵消，所以：相当于 C=3
		C=6：仅有4个开关，按了6下，必然至少有两下的作用相互抵消，所以：相当于 C=4
		......
		C=n：仅有4个开关，按了n下，必然至少有两下的作用相互抵消，所以：相当于 C=(n-2)
	可递推知，对于C>4，分两种情况:
		1） C>4且奇数，相当于 C=3
		2） C>4且偶数，相当于 C=4
*************************************************************************************************

综合以上两个规律，只要求出C=0...4可能被按下的button即可（共2^4种按button的方式）。

*/


/*
ID: Jming
PROG: lamps
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
using namespace std;
typedef pair<int, int> PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const int modPrime = 3046721;
const double eps = 1e-9;
const int MaxN = 40;
const int MaxM = 20;

int N;
int C;
vector<int> vecInt[5];
vector<int> on;
vector<int> off;
set<string> setAns;

int button[4];

void generateCombination(int pos, int cnt, int val, const int lim)
{
	// 以val的第i位是否为1，记录在C=lim下，是否会按下按钮i
	if (cnt == lim)
	{
		vecInt[lim].push_back(val);
		return;
	}
	for (int i = pos; i < 4; ++i)
	{
		generateCombination(i + 1, cnt + 1, val|(1<<i), lim);
	}
}

// 按下按钮 <=> 与button进行异或运算
void getButton()
{
	// 1：When this button is pressed, all the lamps change their state.
	fill(button, button + 4, 0);
	button[0] = (1 << 6) - 1;
	// 2:Changes the state of all the odd numbered lamps.
	/*注：对应 二进制101010*/
	for (int i = 5; i >=0; i -= 2)
	{
		button[1] |= (1 << i);
	}
	// 3:Changes the state of all the even numbered lamps.
	/*注：对应 二进制010101*/
	for (int i = 4; i >= 0; i -= 2)
	{
		button[2] |= (1 << i);
	}
	// 4: Changes the state of the lamps whose number is of the form 3xK+1 (with K>=0)
	/*注：对应 二进制100100*/
	button[3] |= (1 << 2);
	button[3] |= (1 << 5);
}

void ini()
{
	getButton();

	// C=0...4时，可能被按下的button
	vecInt[0].push_back(0);
	for (int i = 1; i <= 4; ++i)
	{
		generateCombination(0, 0, 0, i);
	}
	vecInt[2].push_back(0);
	for (int i = 0; i < vecInt[1].size(); ++i)
	{
		vecInt[3].push_back(vecInt[1][i]);
	}
	vecInt[4].push_back(0);
	for (int i = 0; i < vecInt[2].size(); ++i)
	{
		vecInt[4].push_back(vecInt[2][i]);
	}
}

// 十进制转换成二进制 eg：2D => 000010B
string tenTotwo(int num)
{
	string str;
	while (num)
	{
		if (num & 1)
		{
			str = static_cast<char>('0' + 1) + str;
		}
		else
		{
			str = '0' + str;
		}
		num >>= 1;
	}
	while (str.size() < 6)
	{
		str = '0' + str;
	}
	return str;
}


// 判断生成的结果是否合法
bool isLegal(string str)
{
	for (int i = 0; i < on.size(); ++i)
	{
		if (str[(on[i] - 1)%6] != '1')
		{
			return false;
		}
	}
	for (int i = 0; i < off.size(); ++i)
	{
		if (str[(off[i] - 1)%6] != '0')
		{
			return false;
		}
	}
	return true;
}

void getAns(int c, int start)
{
	for (int i = 0; i < vecInt[c].size(); ++i)
	{
		int val = vecInt[c][i];
		int startNum = start;
		int cnt = 0;
		while (val)
		{
			if (val & 1)
			{
				startNum ^= button[cnt];
			}
			val >>= 1;
			++cnt;
		}
		string str = tenTotwo(startNum);
		if (isLegal(str))
		{
			setAns.insert(str);
		}
	}
}

void Solve()
{
	ini();

	int start = (1 << 6) - 1;
	if (C <= 4)
	{
		getAns(C, start);
	}
	else
	{
		if (C&1)
		{
			// C>4且奇数
			getAns(3, start);
		}
		else
		{
			// C>4且偶数
			getAns(4, start);
		}
	}

	if (setAns.empty())
	{
		printf("IMPOSSIBLE\n");
	}
	else
	{
		for (set<string>::iterator it = setAns.begin(); it != setAns.end(); ++it)
		{
			string str = *it;
			for (int i = 0; i < N; ++i)
			{
				printf("%c", str[i % 6]);
			}
			printf("\n");
		}
	}
}

int main()
{
#ifdef HOME
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);

	scanf("%d", &N);
	scanf("%d", &C);
	int num;
	while ((scanf("%d", &num)) && (num != -1))
	{
		on.push_back(num);
	}
	while ((scanf("%d", &num)) && (num != -1))
	{
		off.push_back(num);
	}
	Solve();

#ifdef HOME
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << " ms" << endl;
#endif
	return 0;
}
