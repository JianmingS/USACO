/*
ID: Jming
PROG: ride
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

int Solve(string str)
{
    int sum = 1;
    for (int i = 0; i < str.size(); i++) {
        sum *= (str[i] - 'A' + 1);
        sum %= 47;
    }
    return sum;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string str;
    string str1;
    cin >> str >> str1;
    int tmp1, tmp2;
    tmp1 = Solve(str);
    tmp2 = Solve(str1);
    if (tmp1 == tmp2) {
        printf("GO\n");
    }else {
        printf("STAY\n");
    }
    return 0;
}
