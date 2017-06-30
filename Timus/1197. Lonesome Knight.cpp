/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1197. Lonesome Knight ->AC
* Algorithm adhoc
* Time Limit 0.015s
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
#define N 100000

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
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool ok(int nx, int ny) {
    return (nx >=1 && nx <= 8 && ny>=1 && ny <= 8);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, ans, x, y;
    char s[3];
    scanf("%d",&cases);
    while (cases--) {
        scanf("%s",&s);
        x = s[0] - 'a' + 1;
        y = s[1] - '0'; ans = 0;
        for (int i=0;i<8;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (ok(nx, ny)) ans++;
        }
        cout << ans << endl;
    }
}
