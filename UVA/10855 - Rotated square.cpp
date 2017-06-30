/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10855 - Rotated square ->AC
* Algorithm Adhoc
* Time Limit 0.08s
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
#define M 500

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
int n, m;
char s[M + 1][M + 1], p[M + 1][M + 1];
char temp[M + 1][M + 1];
int rotate(){
    int x, y, cnt, Ans;
    cnt = Ans = 0;
    for (int i=0;i<n-m+1;i++) {
        for (int h=0;h<n-m+1;h++) {
            x = y = cnt = 0;
            for (int j=i;j<=m+i-1;j++) {
                for (int k=h;k<=m+h-1;k++) {
                    if (s[j][k] == p[x][y]) cnt++;
                    if (y == m - 1) {
                        x++;
                        y = 0;
                    }
                    else y++;
                }
            }
            if (cnt == m * m) Ans++;
        }
    }
    return Ans;
}
int rotate_90(){
    int x, y, cnt, Ans;
    cnt = Ans = 0;
    REP(i, m)
        REP(j, m)
            temp[j][m-i-1] = p[i][j];
    
    for (int i=0;i<n-m+1;i++) {
        for (int h=0;h<n-m+1;h++) {
            x = y = cnt = 0;
            for (int j=i;j<=m+i-1;j++) {
                for (int k=h;k<=m+h-1;k++) {
                    if (s[j][k] == temp[x][y]) cnt++;
                    if (y == m - 1) {
                        x++;
                        y = 0;
                    }
                    else y++;
                }
            }
            if (cnt == m * m) Ans++;
        }
    }
    return Ans;
}
int rotate_180(){
    int x, y, cnt, Ans;
    cnt = Ans = 0;
    REP(i, m)
        REP(j, m)
            p[j][m-i-1] = temp[i][j];
    for (int i=0;i<n-m+1;i++) {
        for (int h=0;h<n-m+1;h++) {
            x = y = cnt = 0;
            for (int j=i;j<=m+i-1;j++) {
                for (int k=h;k<=m+h-1;k++) {
                    if (s[j][k] == p[x][y]) cnt++;
                    if (y == m - 1) {
                        x++;
                        y = 0;
                    }
                    else y++;
                }
            }
            if (cnt == m * m) Ans++;
        }
    }
    return Ans;
}
int rotate_270(){
    int x, y, cnt, Ans;
    cnt = Ans = 0;
    REP(i, m)
        REP(j, m)
            temp[j][m-i-1] = p[i][j];
    for (int i=0;i<n-m+1;i++) {
        for (int h=0;h<n-m+1;h++) {
            x = y = cnt = 0;
            for (int j=i;j<=m+i-1;j++) {
                for (int k=h;k<=m+h-1;k++) {
                    if (s[j][k] == temp[x][y]) cnt++;
                    if (y == m - 1) {
                        x++;
                        y = 0;
                    }
                    else y++;
                }
            }
            if (cnt == m * m) Ans++;
        }
    }
    return Ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    while ( scanf(" %d %d ",&n,&m) && (n + m)) {
        REP(i, n)
            gets(s[i]);
        REP(i, m)
            gets(p[i]);
        printf("%d",rotate());
        printf(" %d",rotate_90());
        printf(" %d",rotate_180());
        printf(" %d\n",rotate_270());
    }
}
