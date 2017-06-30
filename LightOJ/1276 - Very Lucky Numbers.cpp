/***********************************************
* Author - LUONG VAN DO                        *
* 1276 - Very Lucky Numbers ->AC
* Algorithm search
* Time Limit 0.167s
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
#define maxN 400005
#define N 1000000000000LL
using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
set <uint64> S;
uint64 lucky[maxN], num_lucky[maxN];
int n, nm;
void init(uint64 ss) {
    if (ss > N) return;
    if (ss) lucky[nm++] = ss;
    init(ss * 10 + 4);
    init(ss * 10 + 7);
}
void bt(uint64 k, int idx){
    if(k > 1){
        int sz = S.size();
        S.insert( k );
        if(S.size() == sz) return;
    }
    uint64 lim = N / k;
    for(int i = idx; lucky[i] <= lim && i < nm; ++i)
        bt(k * lucky[i], i);
}
int f(uint64 x){
    int L = 1, R = n;
    while (L<=R) {
        int mid = (L + R) >> 1;
        if (num_lucky[mid]<=x) L = mid + 1;
        else R = mid - 1;
    }
    return R;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    uint64 a, b, x, y;
    nm = n = 0;
    init( 0 );
    sort(lucky, lucky + nm);
    bt(1, 0);
    for (set <uint64> :: iterator it = S.begin(); it!=S.end(); it++)
        num_lucky[++n] = (*it);
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lld %lld",&a,&b);
        printf("Case %d: %d\n",t,f(b) - f(a - 1));
    }
    return 0;
}
