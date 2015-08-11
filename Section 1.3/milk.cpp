/*
ID: Jming
PROG: milk
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
int N, M;

struct myNode {
    int P, A;
} node[5005];

bool Cmp(const myNode &n1, const myNode &n2){
    if (n1.A == n2.A) return n1.P < n2.P;
    else return n1.A < n2.A;
}

void Solve() {
    int myCost = 0;
    int myCount = 0;
    for (int i = 0; i < M; ++i) {
        if (myCount + node[i].P > N) {
            myCost += (N-myCount)*node[i].A;
            break;
        }else {
            myCount += node[i].P;
            myCost += node[i].A*node[i].P;
        }
    }
    printf("%d\n", myCost);
}

int main()
{
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i) {
        scanf("%d %d", &node[i].A, &node[i].P);
	}
	sort(node, node + M, Cmp);
	Solve();
	return 0;
}



