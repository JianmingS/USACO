/*
ID: Jming
PROG: transform
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX_N = 15;
char arr_str[MAX_N][MAX_N], t_arr_str[MAX_N][MAX_N], to_arr_str[MAX_N][MAX_N];
int N;

bool Judge(char str1[][15], char str2[][15]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (str1[i][j] != str2[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void number1(char str1[][15], char str2[][15]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			str1[j][N - 1 - i] = str2[i][j];
		}
	}
}

void number2(char str1[][15], char str2[][15]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			str1[N - 1 - i][N - 1 - j] = str2[i][j];
		}
	}
}

void number3(char str1[][15], char str2[][15]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			str1[N - 1 - j][i] = str2[i][j];
		}
	}
}

void number4(char str1[][15], char str2[][15]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			str1[i][N - 1 - j] = str2[i][j];
		}
	}
}

void Solve() {
	number1(t_arr_str, arr_str);
	if (Judge(t_arr_str, to_arr_str)) {
		printf("1\n");
		return;
	}

	number2(t_arr_str, arr_str);
	if (Judge(t_arr_str, to_arr_str)) {
		printf("2\n");
		return;
	}

	number3(t_arr_str, arr_str);
	if (Judge(t_arr_str, to_arr_str)) {
		printf("3\n");
		return;
	}


	number4(t_arr_str, arr_str);
	if (Judge(t_arr_str, to_arr_str)) {
		printf("4\n");
		return;
	}


	char arr_str1[MAX_N][MAX_N];
	for (int i = 0; i < N; ++i) {
		strcpy(arr_str1[i], t_arr_str[i]);
	}

	number1(t_arr_str, arr_str1);
	if (Judge(t_arr_str, to_arr_str)) {
		printf("5\n");
		return;
	}

	number2(t_arr_str, arr_str1);
	if (Judge(t_arr_str, to_arr_str)) {
		printf("5\n");
		return;
	}

	number3(t_arr_str, arr_str1);
	if (Judge(t_arr_str, to_arr_str)) {
		printf("5\n");
		return;
	}
    if (Judge(t_arr_str, to_arr_str)) {
		printf("6\n");
		return;
	}
	printf("7\n");
}

int main()
{
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s", arr_str[i]);
		strcpy(t_arr_str[i], arr_str[i]);
	}
	for (int i = 0; i < N; ++i) {
		scanf("%s", to_arr_str[i]);
	}
	Solve();
	return 0;
}

