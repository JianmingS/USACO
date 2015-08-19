/*
需要注意：
change the height of a hill only once （一座山的高度只能改变一次）

（根据答案进行了优化） 
解法：枚举所有满足条件的高度区间
(0, 17), (1, 18), (2, 19), ..., (83, 100)
计算出使测试数据满足各个区间的花费，最小的即答案。
时间复杂度：O(M*N) 100*1000 = 10^5
*/
/*
ID: Jming
PROG: skidesign
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_N 1005

int hill[MAX_N];
int N;

int Solve() {
	int ans = INF;
	for (int lowest = 0; lowest <= 83; ++lowest) {
		int cost = 0, x;
		for (int i = 0; i < N; ++i) {
			if (hill[i] < lowest) {
				x = lowest - hill[i];
			}
			else {
				if (hill[i] > lowest + 17) {
					x = hill[i] - (lowest + 17);
				}
				else {
					x = 0;
				}
			}
			cost += x*x;
		}
		ans = min(ans, cost);
	}
	//cout << ans << endl;
	return ans;
}

int main() {
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");

	fin >> N;
	for (int i = 0; i < N; ++i) {
		fin >> hill[i];
	}
	fout << Solve() << endl;

	fin.close();
	fout.close();
	return 0;
}