/*
此题参考了正解。
关键：
  （1）枚举出所有两两匹配的情况。
    eg: 1 2 3 4 
      1）1-2 3-4
      2）1-3 2-4
      3）1-4 2-3
      所以共三种情况。
    解决办法：搜索（题目样例的搜索过程：参考示意图Wormholes.png）
  （2）判断匹配后的情况，是否会出现死循环。

*/
/*
ID: Jming
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAX_N = 15;
int N;
int Pair[MAX_N];
int nextNd[MAX_N];

typedef struct Node {
  int x;
  int y;
} Node;

vector<Node> wormhole;

// 判断是否有死循环
bool isCycle() {
  for (int i = 0; i < N; ++i) {
    // 枚举每一个点作为出发点
    int pos = i;
    for (int j = 0; j < N; ++j) {
      if (pos == -1 || Pair[pos] == -1) continue;
      pos = nextNd[Pair[pos]];
    }
    if (pos != -1) return true;
  }
  return false;
}

// 枚举所有情况
int Solve() {
  int i = 0;
  int ans = 0;
  // 找到第一个尚未匹配的点
  for (; i < N; ++i) {
    if (Pair[i] == -1) break;
  }
  // 所有点都有了匹配的点？
  if (i == N) {
    if (isCycle()) return 1;
    else return 0;
  }
  // 枚举所有可能与 i 匹配的点 nd
  for (int nd = i + 1; nd < N; ++nd) {
    if (Pair[nd] == -1) {
      // 匹配点i 和 点nd，继续匹配
      Pair[i] = nd;
      Pair[nd] = i;
      ans += Solve();
      // 释放，枚举其他情况
      Pair[nd] = -1;
      Pair[i] = -1;
    }
  }
  return ans;
}

int main() {
  ifstream fin("wormhole.in");
  ofstream fout("wormhole.out");
  fin >> N;
  Node ndTmp;
  for (int i = 0; i < N; ++i) {
    fin >> ndTmp.x >> ndTmp.y;
    wormhole.push_back(ndTmp);
  }
  fin.close();
  int xxx = sizeof(nextNd);
  fill(nextNd, nextNd + MAX_N, -1);
  fill(Pair, Pair + MAX_N, -1);
  // 将(每个点)和(其右边最近的点)对应起来,保存于nextNd[]
  // 用于判断是否陷入死循环
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (wormhole[i].y == wormhole[j].y && wormhole[i].x < wormhole[j].x) {
        if ((nextNd[i] == -1) ||
          (wormhole[j].x - wormhole[i].x < wormhole[nextNd[i]].x - wormhole[i].x)) {
          nextNd[i] = j;
        }
      }
    }
  }
  fout << Solve() << endl;
  fout.close();
  return 0;
}