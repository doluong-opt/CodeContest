/***********************************************
* Author - LUONG VAN DO                        *
* 1235 - Coin Change (IV) ->AC
* Algorithm Divide
* Time Limit 0.126s
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
#define maxN 40

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int a[maxN];
int n, k, ok;
vector <int64> A;
vector <int64> B;
void TryA(int i, int n, int64 Sum) {
    if (ok) return;
    if (i > n) {
        if (Sum == k) {
            ok = 1;
            return;
        }
        A.pb( Sum );
        return;
    }
    TryA(i + 1, n, Sum);
    TryA(i + 1, n, Sum + a[i]);
    TryA(i + 1, n, Sum + 2 * a[i]);
}
void TryB(int i, int n, int64 Sum) {
    if (ok) return;
    if (i > n) {
        if (Sum == k) {
            ok = 1;
            return;
        }
        B.pb( Sum );
        return;
    }
    TryB(i + 1, n, Sum);
    TryB(i + 1, n, Sum + a[i]);
    TryB(i + 1, n, Sum + 2 * a[i]);
}
bool check(int64 x, int l, int r) {
    while (l<=r) {
        int mid = (l + r) >> 1;
        if ( A[mid] == x ) return true;
        if ( A[mid] > x ) r = mid - 1;
        else l = mid + 1;
    }
    return false;
}
void Read() {
    int test, aa;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&k);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        A.clear(); B.clear(); ok = 0;
        TryA(1, n / 2, 0);
        if ( ok ) {
            printf("Case %d: Yes\n",t);
            continue;
        }
        TryB(n / 2 + 1, n, 0);
        if ( ok ) {
            printf("Case %d: Yes\n",t);
            continue;
        }
        sort(A.begin(), A.end());
        aa = A.size();
        for (vector <int64> :: iterator it = B.begin(); it!=B.end();it++) {
            if ( check( k - (*it), 0, aa - 1) ) {
                ok = 1;
                break;
            }
        }
        if (ok) printf("Case %d: Yes\n",t);
        else printf("Case %d: No\n",t);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
