/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1418 - Trees on My Island ->AC
* Algorithm theory
* Time Limit 0.169s
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
inline int gcd(int a, int b) {if ( b == 0) return a; if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct point{
    int64 x, y;
    point(){}
    point(int64 xx, int64 yy){
        x = xx; y = yy;
    }
};
point p[N];
char s[N];
int ind;
int64 getInt(int m) {
    int64 v = 0, sign = 0;
    while (ind < m && s[ind] != ' ') {
        if ( s[ind] == '-') {
            sign = 1;
            ind++;
        }
        else v = v * 10 + s[ind++] - '0';
    }
    ++ind;
    if (sign) v*=-1;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int64 cases, caseno = 0;
    int64 cnt, x1, y1, x2, y2, n;
    int64 ans;
    double area;
    gets(s); ind = 0; cases = getInt(strlen(s));
    while (cases--) {
        gets(s); ind = 0; n = getInt(strlen(s));
        for (int i=0;i<n;i++) {
            gets(s); ind = 0;
            p[i].x = getInt(strlen(s));
            p[i].y = getInt(strlen(s));
        }
        area = 0.0; cnt = 0;
        for (int i=0;i<n;i++) {
            x1 = p[i].x; y1 = p[i].y;
            x2 = p[(i + 1) % n].x; y2 = p[(i + 1) % n].y;
            area+=(x1 * y2 - x2 * y1);
            cnt+=gcd(abs(x1 - x2), abs(y1 - y2));
        }
        area = fabs(area);
        ans = (int64)(area / 2) - (cnt / 2) + 1;
        printf("Case %lld: %lld\n",++caseno, ans);
    }
}
