/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1363 - Binary Matrix (II) 
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
#define N 1010

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
int r, c, one;
char s[N][N];
int row[N], col[N];
int OR, OC, rr, cc;
bool check_r() {
    if (one % r != 0) return false;
    int e = one / r;
    for (int i=0;i<r;i++)
        if (e != row[i]) return false;
    return true;
}
bool check_c() {
    if (one % c != 0) return false;
    int e = one / c;
    for (int i=0;i<c;i++)
        if (e != col[i]) return false;
    return true;
}
void calr(int x) {
//    for (int i=0;i<r;i++) cout<<i<<" "<<x<<" "<<row[i]<<endl;
    for (int i=0;i<r;i++)
        if (row[i] > x) rr+=(row[i] - x);
}
void calc(int x) {
    int d;
    for (int i=0;i<c;i++) cout<<i<<" "<<x<<" "<<col[i]<<endl;
    for (int i=0;i<c;i++)
        if (col[i] > x) cc+=(col[i] - x);
}
void solve() {
    OR = OC = rr = cc = 0;
    if ( one % r == 0 ) {
        calr(one / r);
        OR = 1;
    }
    if ( one % c == 0 ) {
        calc(one / c);
        OC = 1;
    }
    if (OR && OC) printf("both %d\n",rr + cc);
    else
    if (OR) printf("row %d\n",rr);
    else printf("col %d\n",cc);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, f1, f2;
    scanf("%d",&cases);
    while (cases--) {
        scanf(" %d %d ",&r,&c);
        one = f1 = f2 = 0;
        for (int i=0;i<r;i++) row[i] = 0;
        for (int i=0;i<c;i++) col[i] = 0;
        for (int i=0;i<r;i++) gets(s[i]);
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++)
                if (s[i][j] == '1') {
                    row[i]++;
                    col[j]++;
                    one++;
                }
        printf("Case %d: ",++caseno);
        if (one % r != 0 && one % c != 0) puts("impossible");
        else {
            if ( check_r() ) f1 = 1;
            if ( check_c() ) f2 = 1;
            if (f1 && f2) puts("both 0");
            else
            if (f1) puts("row 0");
            else
            if (f2) puts("col 0");
            else solve();
        }
    }
}
