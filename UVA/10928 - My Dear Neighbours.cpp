/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10928 - My Dear Neighbours ->AC
* Algorithm adhoc
* Time Limit 0.02s
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
#define N 10010

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
int d[N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, x, mini, y, m, n, p;
    char s[N];
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d",&n); mini = INF;
        for (int i=1;i<=n;i++) d[i] = 0; p = 1;
        gets(s); if (strlen(s)) p = 2;
        x = y = 0; m = strlen(s);
        while (x < m) {
            y = y * 10 + (s[x] - '0');
            if (s[x] == ' ') {
                d[1]++;
                y = 0;
            }
            x++;
        }
        for (int i=p;i<=n;i++) {
            gets(s); m = strlen(s); x = y = 0;
            while (x < m) {
                y = y * 10 + (s[x] - '0');
                if (s[x] == ' ') {
                    d[i]++;
                    y = 0;
                }
                x++;
            }
            if (m != 0 && y!=0) d[i]++;
            mini = min(mini, d[i]);
        }
        gets(s);
        x = 0;
        for (int i=1;i<=n;i++) {
            if (mini == d[i]) {
                if (x) printf(" ");
                x = 1;
                printf("%d",i);
            }
        }
        printf("\n");
    }
}
