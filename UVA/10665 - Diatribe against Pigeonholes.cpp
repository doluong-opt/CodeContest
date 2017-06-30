/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10665 - Diatribe against Pigeonholes
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
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
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
char s[N];
int f[27], mark[N], n;
vector <ii> num;
ii ans[N];
bool cmp(ii a, ii b) {
    if (a.ff != b.ff) return a.ff > b.ff;
    return (a.ss < b.ss);
}
void solve(int i1, int i2, int x) {
    int c1, c2, p1, p2;
    //cout<<i1<<" "<<i2<<endl;
    printf("%c %c\n", num[i1].ss, num[i2].ss);
    if ( num[i1].ff != num[i2].ff ) {
        if ( num[i1].ss  > num[i2].ss ) {
            ans[x] = num[i2];
            ans[n - x - 1] = num[i1];
        }
        else {
            ans[x] = num[i1];
            ans[n - x - 1] = num[i2];
        }
        mark[i1] = mark[i2] = 1;
    }
    else {
        c1 = INF; c2 = -INF;
        for (int i=0;i<n;i++)
            if ( !mark[i] ) {
                if ( num[i].ff == num[i1].ff ) {
                    if ( c1 > num[i].ss) {
                        c1 = num[i].ss;
                        p1 = i;
                    }
                    if ( c2 < num[i].ss) {
                        c2 = num[i].ss;
                        p2 = i;
                    }
                }
            }
        //cout<<num[p2].ss<<" "<<num[p1].ss<<endl;
        ans[x] = num[p1];
        ans[n - x - 1] = num[p2];
        mark[p1] = mark[p2] = 1;
    }
//    cout<<ans[0].ff<<" "<<ans[0].ss<<endl;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, m, flag, xx;
    scanf("%d",&cases);
    while (cases--) {
        scanf(" %d ",&n);
        rep(i, n) mark[i] = 0;
        gets(s); num.clear();
        rep(i, 26) f[i] = 0;
        for (int i=0;s[i];i++)
            if (s[i] >='A' && s[i]<='Z') f[s[i]-'A']++;
        rep(i, n) num.pb(ii(f[i], i + 'A'));
        sort(num.begin(), num.end(), cmp);
        rep(i, n) printf("%d %d %c\n", i, num[i].ff, num[i].ss);
        xx = -1;
        while ( true ) {
            flag = 0;
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++)
                    if (i != j && !mark[i] && !mark[j] ) {
                        ++xx;
                        solve(i, j, xx);
                        flag = 1;
                        break;
                    }
                if ( flag ) break;
            }
            if (!flag) break;
            //for (int i=0;i<n;i++) cout<<mark[i]<<" ";
            //cout<<endl;
        }
        rep(i, n) {
            if (i) printf(" ");
            printf("%c", ans[i].ss);
        }
        puts("");
        rep(i, n) {
            if (i) printf(" ");
            printf("%d", ans[i].ff);
        }
        puts("");
    }
}
