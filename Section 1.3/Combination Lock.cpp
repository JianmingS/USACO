/*
Combination Lock��
˼·��
��1������ N ���������
		1��ũ��Լ���ĺ���������ܲ����Ĳ�ͬ�Ŀ���������ϵ���Ŀ S1��
		2��Ԥ�����������ܲ����Ĳ�ͬ�Ŀ���������ϵ���Ŀ S2��
��2�����������1����2����ͬ�ĺ������ S3��
��3���Ƴ��𰸣� S1 + S2 - S3

ע�⣺ ���ϱ��Ϊ N �ĺ����ڳ������� 0 ��ʾ
*/

/*
ID: Jming
PROG: combo
LANG: C++
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
#define eps 1e-8
int N, Sum;
vector<int> arr0[3], arr1[3];

int Ini(vector<int> arr[3]) {
	int cnt = 1;
	int tmp;
	for (int i = 0; i < 3; ++i) {
		scanf("%d", &tmp);
		int pos = 0;
		for (int j = -2; j <= 2; ++j) {
			int mytmp = (tmp + j + N) % N;   
			if (find(arr[i].begin(), arr[i].end(), mytmp) == arr[i].end()) {
				arr[i].push_back(mytmp);
			}
		}
		cnt *= arr[i].size();
	}
	return cnt;
}

void Solve() {
	int mycount = 1;
	for (int i = 0; i < 3; ++i) {
		int tmp = 0;
		for (int j = 0; j < arr0[i].size(); ++j) {
			if (find(arr1[i].begin(), arr1[i].end(), arr0[i][j]) != arr1[i].end()) {
				++tmp;
			}
		}
		mycount *= tmp;
	}
	printf("%d\n", Sum - mycount);
}

int main()
{
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);
	scanf("%d", &N); 
	Sum = 0;
	Sum += Ini(arr0);
	Sum += Ini(arr1);
	Solve();
	return 0;
}