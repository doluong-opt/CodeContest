/***********************************************
* Author - LUONG VAN DO                        *
* 10827 - Maximum sum on a torus ->AC
* Algorithm dp
* Time Limit 1.092s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
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
#define maxN 76

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, m[2 * maxN + 1][2 * maxN + 1];
void solve() {
    int res = 0, ans;
    FOR(i, 1, 2 * n)
        FOR(j, 1, 2 * n) m[i][j]+= m[i-1][j];
       
    for (int i=1;i<=n;i++) {
        for (int j=i;j<i+n;j++) {
            for (int k=1;k<=n;k++) {
                ans = 0;
                for (int l=k;l<k+n;l++) {
                    ans+=m[j][l] - m[i-1][l];
                    if ( ans < 0 ) ans = 0;
                    else res = max(res, ans);
                }
            }
        }
    }
    printf("%d\n",res);
}
void Read() {
    int test, h;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        h = n + 1;
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                scanf("%d",&m[i][j]);
                m[i][j+n] = m[i][j];
                m[h][j] = m[i][j];
                m[h][j+n] = m[i][j];
            }
            ++h;
        }
        solve();
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
