/***********************************************
* Author - LUONG VAN DO                        *
* 1328 - A Gift from the Setter ->AC
* Algorithm Greedy
* Time Limit 0.574s
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
#define maxN 100005

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
long long a[maxN];
void Read() {
    int test;
    long long res, v, K, C, p, n;
    scanf("%d",&test);
    FOR(t, 1, test) {
        res = v = 0;
        scanf("%lld %lld %lld %lld",&K,&C,&n,&a[0]);
        FOR(i, 1, n - 1)
            a[i] = (long long)(a[i-1] * K + C) % 1000007;
        sort(a, a + n);
        v = a[n-1]; p = 1;
        res = 0;
        for (int i=n-2;i>=0;i--) {
            res+=abs((long long)(p * a[i]) - v);
            v+=a[i];
            p++;
        }
        printf("Case %d: %lld\n",t,res);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
