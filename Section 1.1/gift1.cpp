/*
ID: Jming
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
const int MAX_N = 15;
string arr_str[MAX_N];

int N;

struct node {
    int rec, giv;
    node() {
        rec = 0;
        giv = 0;
    }
};
node myrecord[MAX_N];
map<string, node> str_no_map;

void Solve() {
    string str, t_str;
    int amount, number;
    while (cin >> str) {
        scanf("%d %d", &amount, &number);
        if (0 == number) {
            continue;
        }
        str_no_map[str].giv += (amount / number) * number;
        for (int i = 0; i < number; ++i) {
            cin >> t_str;
            str_no_map[t_str].rec += (amount / number);
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << arr_str[i] << " " << str_no_map[arr_str[i]].rec - str_no_map[arr_str[i]].giv << endl;
    }
}

int main()
{
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        cin >> arr_str[i];
        str_no_map[arr_str[i]] = myrecord[i];
    }
    Solve();
	return 0;
}



