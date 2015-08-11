/*
ID: Jming
PROG: friday
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int N, cnt[13] = { 0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int ans[7];

void Solve() {
    int end_year = 1900+N;
    int days, week = 1;
    for (int i = 1900; i < end_year; ++i) {
        for (int j = 1; j <= 12; ++j) {
            if (2 == j) {
                if (!(i%100)) {
                    if (!(i%400)) { days = 29; }
                    else { days = 28; }
                }else {
                    if (!(i%4)) { days = 29; }
                    else { days = 28; }
                }
            }else { days = cnt[j]; }
            ans[(week+5)%7]++;
            week = (week+days%7)%7;
        }
    }
    printf("%d ", ans[6]);
    for (int i = 0; i < 6; ++i) {
        printf("%d", ans[i]);
        if (i != 5) {
            printf(" ");
        }
    }
    printf("\n");
}

int main()
{
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    scanf("%d", &N);
    Solve();
    return 0;
}














