/***********************************************
* Author - LUONG VAN DO                        *
* Problem
* Algorithm
* Time Limit
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100111

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct Node {
      char grid[9][9];
      int c;
      void print() {
            for (int i = 0;i < 9;i++) {
                  for (int j = 0;j < 9;j++)
                        putchar(grid[i][j]);
                  puts("");
            }
      }
};
char rowCur[10];
bool valid(Node &curState, int r, int c, char ch) {
      for (int k = 0;k < 9;k++)
            if ( curState.grid[r][k] == ch || curState.grid[k][c] == ch) return false;
      int block_x = r / 3 * 3;
      int block_y = c / 3 * 3;
      for (int i = 0;i < 3;i++)
            for (int j = 0;j < 3;j++)
                  if ( curState.grid[i + block_x][j + block_y] == ch ) return false;
      return true;
}
void find_best_next(Node &curState, int &r, int &c) {
      int best = 10;
      for (int i = 0;i < 9;i++)
            for (int j = 0;j < 9;j++) {
                  if ( curState.grid[i][j] != '.' ) continue;
                  int cost = 0;
                  for (char k = '1';k <= '9';k++)
                        if ( valid(curState, i, j, k) ) cost++;
                  if ( cost < best ) best = cost, r = i, c = j;
            }
}
void run(Node &st, Node &solver) {
      queue <Node> q;
      st.c = 0;
      for (int i = 0;i < 9;i++) for (int j = 0;j < 9;j++)
            if ( st.grid[i][j] != '.' ) st.c++;
      q.push(st);
      while  ( !q.empty() ) {
            Node curState = q.front();
            q.pop();
            if ( curState.c == 81 ) {
                  solver = curState;
                  return;
            }
            int r, c;
            find_best_next(curState, r, c);
            for (char k = '1'; k <= '9';k++) {
                  if ( !valid(curState, r, c, k) ) continue;
                  Node temp = curState;
                  temp.grid[r][c] = k;
                  temp.c++;
                  q.push(temp);
            }
      }
}
int main() {
            freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
            int cases, caseno = 0;
            scanf("%d", &cases);
            while (cases--) {
                  Node st;
                  for (int i = 0;i < 9;i++) {
                        scanf("%s", rowCur);
                        strncpy(st.grid[i], rowCur, 9);
                  }
                  Node solver;
                  run(st, solver);
                  printf("Case %d:\n", ++caseno);
                  solver.print();
            }
            return 0;
}
