/*
ID: Jming
PROG: beads
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
#define MAX(a, b) ((a)>(b)?(a):(b))
#define MIN(a, b) ((a)<(b)?(a):(b))

int N;
string str;
const int MAX_N = 705;
int myleft[MAX_N][2], myright[MAX_N][2];

void Solve() {
    // 0: b 1:r
    myleft[0][0] = myleft[0][1] = 0;
    for (int i = 1; i <= N; ++i) {
        if ('b' == str[i-1]) {
            myleft[i][0] = myleft[i-1][0] + 1;
            myleft[i][1] = 0;
        }
        else if ('r' == str[i-1]) {
            myleft[i][1] = myleft[i-1][1] + 1;
            myleft[i][0] = 0;
        }
        else {
            myleft[i][0] = myleft[i-1][0] + 1;
            myleft[i][1] = myleft[i-1][1] + 1;
        }
    }

    myright[N][0] = myright[N][1] = 0;
    for (int i = N-1; i >= 0; --i) {
        if ('b' == str[i]) {
            myright[i][0] = myright[i+1][0] + 1;
            myright[i][1] = 0;
        }else if ('r' == str[i]) {
            myright[i][1] = myright[i+1][1] + 1;
            myright[i][0] = 0;
        }else {
            myright[i][0] = myright[i+1][0] + 1;
            myright[i][1] = myright[i+1][1] + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = MAX(ans, MAX(myleft[i][0], myleft[i][1])+ MAX(myright[i][0], myright[i][1]));
    }
    ans = MIN(ans, N>>1);
    printf("%d\n", ans);
}

int main()
{
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    scanf("%d", &N);
    cin >> str;
    str = str+str;
    N = N<<1;
    Solve();
    return 0;
}














