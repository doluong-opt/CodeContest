/***********************************************
* Author - LUONG VAN DO                        *
* 1076 - Get the Containers ->AC
* Algorithm chat nhi phan
* Time Limit 0.018s
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
#define INF 10000000000000LL
#define maxN 50001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 L,R;
int64 ans, best,n,k;
int64 a[maxN];
int min(int a, int b) {
    return a > b ? b : a;
}
int max(int a, int b) {
    return a > b ? a : b;
}
bool check(int64 M){
    int64 sum, j;
    sum = j = best = 0;
    for (int i=1;i<=n;i++)
        if (sum + a[i] <= M ) sum+=a[i];
        else {
            if (sum == 0) best = max( best, a[i] );
            else best = max( best, sum );
            sum = a[i];
            j++;
        }
    best = max(best, sum);
    j++;
    return (j<=k);
}
void solve(){
    ans = INF;
    while (L<=R) {
        int64 mid = (L + R) >> 1;
        if ( check(mid) ){
            ans = min( ans, best );
            R = mid - 1;
        }
        else L = mid + 1;
    }
}
void Read_Input(){
    int test;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%lld %lld",&n,&k);
        R = 0; L = INF;
        for (int i=1;i<=n;i++) {
            scanf("%lld",&a[i]);
            R+=a[i];
            L = min(L, a[i]);
        }
        solve();
        printf("Case %d: ",t);
        cout<< ans <<endl;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}
