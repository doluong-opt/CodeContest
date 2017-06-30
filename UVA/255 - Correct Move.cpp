/***********************************************
* Author - LUONG VAN DO                        *
* Problem 255 - Correct Move ->AC
* Algorithm Adhoc
* Time Limit 0.076s
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
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 100000

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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char board[10][10];
bool valid(int x, int y) {
    return (x>=0 && y>=0 && x < 8 && y < 8);
}
void put(int x, int y) {
    board[x / 8][x % 8] = 'K';
    board[y / 8][y % 8] = 'Q';
}
void cal(int x, int y) {
    int kx, ky;
    int qx, qy;
    kx = x / 8; ky = x % 8;
    qx = y / 8; qy = y % 8;
    for (int i=0;i<4;i++) {
        int nx = kx + dx[i];
        int ny = ky + dy[i];
        if (valid(nx, ny) && board[nx][ny] !='Q') board[nx][ny] = 'k';
    }
    for (int i=0;i<4;i++)
        for (int j=1;; ++j) {
            int nx = qx + dx[i] * j;
            int ny = qy + dy[i] * j;
            if (valid(nx, ny) && board[nx][ny] !='K') {
                if ( board[nx][ny] == 'k') board[nx][ny] = '*';
                else board[nx][ny] = 'q';
            }
            else break;
        }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int a, b, c;
    while ( scanf("%d %d %d",&a,&b,&c) != EOF) {
        memset(board, 0, sizeof(board));
        if (a == b) {
            puts("Illegal state");
            continue;
        }
        put(a, b);
        cal(a, b);
        if (board[c / 8][c % 8] == '*') puts("Move not allowed");
        else if ( board[c / 8][c % 8] !='q' ) puts("Illegal move");
        else {
            memset(board, 0, sizeof(board));
            put(a, c);
            cal(a, c);
            int king_move = 0;
            for (int i=0;i<8;i++)
                for (int j=0;j<8;j++)
                    if (board[i][j] == 'k') king_move++;
            if (king_move > 0) puts("Continue");
            else puts("Stop");
        }
    }
}
