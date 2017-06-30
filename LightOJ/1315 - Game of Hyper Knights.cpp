/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1315 - Game of Hyper Knights ->AC
* Algorithm gundy function
* Time Limit 0.161s
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
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 510

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
char s[N];
int id;
int f[N][N];
int dx[] = {-2, -2, -3, -1, -1, 1};
int dy[] = {1, -1, -1, -2, -3, -2};
int mark[N], C[N];
int valid(int x, int y) {
    return (x>=0 && x<=500 && y>=0 && y<=500);
}
int getInt(int m) {
    int v = 0;
    while (id < m && s[id] !=' ') v = v * 10 + s[id++] - '0';
    ++id;
    return v;
}
void reset() {
    for (int i=0;i<N;i++) mark[i] = 0;
}
void build(int n) {
        int r,c,l,ll,i,p;
        l = 2;
        C[0] = C[1] = 2;
        while( 1 ) {
            r = l;
            if(C[r]==2 && r!=n) {
                l++;
                r=l;
            }
            if(C[r] > n) break;
            while(r>=0) {
                reset();
                c=C[r];
                if( C[r] > n ) break;
                for(i=0;i<6;i++) {
                    int nx = r + dx[i];
                    int ny = c + dy[i];
                    if (valid(nx, ny)) mark[f[nx][ny]] = 1;
                }
                C[r]++;
                ll = p = 0;
                while( mark[ll] ) ll++;
                f[r][c]=ll;
                r--;
            }
        }
    }
    
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, caseno = 0, nim, x, y;
    gets(s); id = 0; cases = getInt(strlen(s));
    build(500);
    while (cases--) {
        gets(s); id = 0; n = getInt(strlen(s));
        nim = 0;
        for (int i=0;i<n;i++) {
            gets(s); id = 0;
            x = getInt(strlen(s));
            y = getInt(strlen(s));
            nim^=f[x][y];
        }
        printf("Case %d: ",++caseno);
        if (nim) puts("Alice");
        else puts("Bob");
    }
}
