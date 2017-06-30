/***********************************************
* Author - LUONG VAN DO                        *
* 1127 - Funny Knapsack ->AC
* Algorithm Divide
* Time Limit 0.027s
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
#define maxN 35

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, w;
int a[maxN];
vector <int64> A;
vector <int64> B;
void TryA(int i, int n, int64 sum){
    if (i > n) return;
    for (int j=0;j<=1;j++) {
        sum += a[i] * j;
        if (i < n) TryA(i+1, n, sum);
    }
    if (sum<=w) A.pb( sum );
}
void TryB(int i, int n, int64 sum){
    if (i > n) return;
    for (int j=0;j<=1;j++) {
        sum += a[i] * j;
        if (i < n) TryB(i + 1, n, sum);
    }
    if (sum<=w) B.pb( sum );
}
int frx(int64 x, int l, int r) {
    while (l<=r) {
        int mid = (l + r) >> 1;
        if ( A[mid] <=x ) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
void Read() {
    int test, ans, aa, pos;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&w);
        FOR(i, 1, n) scanf("%d",&a[i]);
        A.clear(); B.clear();
        ans = 1;
        TryA(1, n/2, 0);
        TryB(n/2 + 1, n, 0);
        ans+=(int)A.size() + (int)B.size();
        aa = A.size();
        sort(A.begin(), A.end());
        for (vector <int64> :: iterator it = B.begin(); it!=B.end(); it++) {
            pos = frx(w - (*it), 0, aa - 1);
            if (pos!=-1) ans+=(pos + 1);
        }
        printf("Case %d: %d\n",t,ans);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
