/***********************************************
* Author - LUONG VAN DO                        *
* SPOJ - VMDEGREE -->AC                        *
* Time Limit 3.000s                            *
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define FORX(i,x,n) for (int i=x;i<=n;i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 100005
using namespace std;
int64 a[maxN+5];
int64 S[maxN+5];
int64 n;
int Bainary(int64 key, int64 L, int64 R){
    while (L <= R){
        int64 mid = (L + R) >> 1;
        if ( a[mid] >= key ) L = mid + 1;
        else R = mid - 1;
    }
    return R;
}
bool cmp(int x, int y){
    return x>y;
}
void Cal(){
    int64 i,di,s,ok,pos,dau,cuoi;
    sort(a+1,a+1+n,cmp);
    S[0] = 0;
    for (int i=1;i<=n;i++) S[i] = S[i-1] + a[i];
    S[n+1] = 0;
    if (n==1 && S[n]>0){
        puts("NO");
        return;
    }
    ok = 1;
    for (i=1;i<n;i++){
        di = S[i];
        s = i * ( i - 1 );
        pos = Bainary(i,i+1,n);
        cuoi = S[n] - S[pos];
        dau = i * ( pos - i);
        if ( di <= s + dau + cuoi ) continue;
        else
        {
            ok = 0;
            break;            
        }
    }
    if ( ok ) puts("YES");
    else puts("NO");
}
main(){
//    FileIn("exam"); FileOut("exam");
    int64 t,Sum,no;
    scanf("%lld",&t);
    while (t--){
        scanf("%lld",&n);
        Sum = no = 0; S[0] = 0;
        FOR(i,1,n){
            scanf("%lld",&a[i]);
            if (a[i]<0 || a[i] >= n) no = 1;
            Sum+=a[i];
        }
        if (Sum%2 || no){
            puts("NO");
            continue;
        }
        else Cal();
    }
}

