/***********************************************
* Author - LUONG VAN DO                        *
* Problem
* Algorithm Hill Climbing
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
#include <time.h>

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
      void print() {
            for (int i = 0;i < 9;i++) {
                  for (int j = 0;j < 9;j++)
                        putchar(grid[i][j]);
                  puts("");
            }
      }
};
char digit[10];
char curRow[10];
int it;
Node start, curState;
bool exist(char digit[], char num) {
      for (int i = 0;i < 9;i++)
            if (digit[i] == num) return true;
      return false;
}
void genRandom() {
      char num;
      for (int i = 0;i < 9;i++) digit[i] = '.';
      for (int i = 0;i < 9;i++) {
            do {
                  int d = rand()%9 + 1;
                  num = d + 48;
            }while (  exist(digit, num) );
            digit[i] = num;
      }
}
Node initialState(Node start) {
      for (int i = 0;i < 9;i++) for (int j = 0;j < 9;j++)
            for (int k = 0;k < 9;k++)
                  if ( start.grid[i][j] == '.'  && !exist(start.grid[i], digit[k]) ) {
                        start.grid[i][j] = digit[k];
                        break;
                  }
      return start;
}
Node setInit(Node curState) {
      genRandom();
      return initialState(curState);
}
int g(Node state, int row, int col) {
      int nt = 0, cost = 0;
      char t[10];
      int block_x = row / 3 * 3;
      int block_y = col / 3 * 3;
      for (int i = 0;i < 3;i++)
            for (int j = 0;j < 3;j++)
                  t[nt++] = state.grid[i + block_x][j + block_y];

      for (int i = 0;i < 9;i++)
            for (int j = i + 1;j < 9;j++)
                  if (t[i] == t[j]) cost++;
      return cost;
}
int f(Node state) {
      int match = 0, cost = 0;
      for(int col = 0; col < 9; col++){
            for(int row = 0; row < 9; row++){
                  for(int i = 0; i < 9; i++){
                        if(state.grid[col][row] == state.grid[col][i])
                              match++;
                  }
                  if(match > 1) {
                        cost += (match - 1);
                        match = 0;
                  } else match = 0;
            }
      }
      for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                  for(int i = 0; i < 9; i++){
                        if(state.grid[col][row] == state.grid[i][row])
                              match++;
                  }
                  if(match > 1){
                        cost += (match - 1);
				match = 0;
                  } else match = 0;
            }
      }

      for (int row = 0;row < 9;row++)
            for (int col = 0;col < 9;col++)
                  cost += g(state, row, col);
      return cost;
}
Node Hill_Climbing(Node neighborState, int costCur) {
      int col[2];
      int costNeighbor;
      int row = rand() % 9;
      do {
            for (int i = 0;i < 2;i++) {
                  col[i] = rand() % 9;
            }
      }while (start.grid[row][col[0]] != '.' || start.grid[row][col[1]] != '.');
      Node curState = neighborState;
      char ch = neighborState.grid[row][col[0]];
      neighborState.grid[row][col[0]] = neighborState.grid[row][col[1]];
      neighborState.grid[row][col[1]] = ch;
      costNeighbor = f(neighborState);
      ++it;
      if (it == 1000) return curState;
      if ( costNeighbor == 0 ) return neighborState;
      if ( costNeighbor >= costCur )
            return Hill_Climbing(curState, costCur);
      else
            return Hill_Climbing(neighborState, costNeighbor);
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
      scanf("%d", &cases);
      while (cases--) {
            srand(time(NULL));
            Node solutionState;
            for (int i = 0;i < 9;i++) {
                  scanf("%s", curRow);
                  strncpy(start.grid[i], curRow, 9);
            }
            for (int i = 0;i < 9;i++)
                  for (int j = 0;j < 9;j++)
                        curState.grid[i][j] = start.grid[i][j];
            it = 0;
            do {
                  curState = setInit(curState);
                  //curState.print();
                  solutionState = Hill_Climbing(curState, f(curState));
                  for (int i = 0;i < 9;i++)
                        for (int j = 0;j < 9;j++)
                              curState.grid[i][j] = start.grid[i][j];
                  it++;
            }while ( it <= 1000 && f(solutionState) != 0);
            //cout << f(solutionState) << endl;
            printf("Case %d:\n", ++caseno);
            solutionState.print();
      }
	return 0;
}
