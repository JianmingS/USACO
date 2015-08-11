/*
Barn Repair: 
ע�⣺ţ���ڵ�ţ��ı��������ģ���Ҫ�ȴ�С��������
��������ۣ�
1��M == 1 �� ����ţ���� - ��С��ţ���� + 1
2��M >= C :  ֱ����� C ����
3) M < C  :  ���ݸ�ţ����֮��Ĳ�ֵ��̰�Ĵ�������ɾȥ��ֵ��ģ�ѡȡ��ֵС�ģ�
*/

/*
ID: Jming
PROG: barn1
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
#define MAX_C 205

int M, S, C;
int myArr[MAX_C];
vector<int> myVec;

struct myNode {
	int Pos;
	int Dis;
};
myNode node[MAX_C];

bool Cmp(const myNode n1, const myNode n2) {
	return n1.Dis > n2.Dis;
}

void Solve() {
	int myBegin = 0;
	int Sum = 0, tmp;
	myVec.push_back(C-1);
	for (int i = 0; i < myVec.size(); ++i) {
		tmp = myArr[myVec[i]] - myArr[myBegin] + 1;
		if (tmp) Sum += tmp;
		else ++Sum;
		myBegin = myVec[i] + 1;
	}
	printf("%d\n", Sum);
}

int main() {
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
	scanf("%d %d %d", &M, &S, &C);
	for (int i = 0; i < C; ++i) {
		scanf("%d", &myArr[i]);
	}
	sort(myArr, myArr + C);
	for (int i = 1; i < C; ++i) {
		node[i - 1].Pos = i - 1;
		node[i - 1].Dis = myArr[i] - myArr[i - 1];
	}
	if(M >= C) {
        printf("%d\n", C);
        return 0;
	}
	if (1 == M) {
        printf("%d\n", myArr[C - 1] - myArr[0] + 1);
        return 0;
	}
	sort(node, node + (C - 1), Cmp);
	for (int i = 0; i < (M - 1); ++i) {
		myVec.push_back(node[i].Pos);
	}
	sort(myVec.begin(), myVec.end());
	Solve();
	myVec.clear();
	return 0;
}