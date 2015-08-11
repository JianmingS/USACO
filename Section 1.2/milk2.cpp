/*
ID: Jming
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 5005;
int N;
struct node {
    int a, b;
};

node Time[MAX_N];

bool Cmp(const node &n1, const node &n2) {
    if (n1.a == n2.a) return n1.b < n2.b;
    else return n1.a < n2.a;
}

int main()
{
	freopen("milk2.in", "r", stdin);
    	freopen("milk2.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
        scanf("%d %d", &Time[i].a, &Time[i].b);
	}
	sort(Time, Time+N, Cmp);
	int mybegin = Time[0].a, myend = Time[0].b;
	int work = myend - mybegin, no_work = 0;
	for (int i = 1; i < N; ++i) {
        if (Time[i].a <= myend) {
            myend = max(myend, Time[i].b);
        }else {
            work = max(work, myend - mybegin);
            no_work = max(no_work, Time[i].a - myend);
            mybegin = Time[i].a, myend = Time[i].b;
        }
	}
	work = max(work, myend - mybegin);
	printf("%d %d\n", work, no_work);
	return 0;
}

