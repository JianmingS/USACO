/*
ID: Jming
PROG: beads
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int N;
string str;

void Solve() {
    int sum1, sum2;
    int ans = -1;
    for (int i = 0; i < N; ++i) {
        char ch;
        sum1 = 1;
        if ('w' == str[i]) {
            for (int j = i+1; j != i; j = (j+1)%N) {
                if ('w' != str[j]) {
                    ch = str[j];
                    break;
                }
            }
        }else { ch = str[i]; }

        int r = (i + 1)%N;
        while (r != i) {
            if (('w' == str[r]) || (str[i] == str[r])) {
                ++sum1;
                r = (r+1)%N;
            }
            else break;
        }
        r = (r-1 + N)%N;

        int l = (i-1+N)%N;

        int sum2 = 0;
        if (l != r) {
            if ('w' == str[l]) {
                for (int j = l; j != r; j = (j-1+N)%N) {
                    if ('w' != str[j]) {
                        ch = str[j];
                        break;
                    }
                }
            }else { ch = str[l]; }
        }
        while (l != r) {
            if (('w' == str[l]) || (ch == str[l])) {
                ++sum2;
                l = (l-1+N)%N;
            }
            else break;
        }
        ans = max(ans, sum1+sum2);
    }
    printf("%d\n", ans);
}

int main()
{
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    scanf("%d", &N);
    cin >> str;
    Solve();
    return 0;
}














