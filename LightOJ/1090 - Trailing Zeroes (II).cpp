/***********************************************
* Author - LUONG VAN DO                        *
* 1090 - Trailing Zeroes (II) ->AC
* Algorithm math
* Time Limit 0.02s
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
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 50001
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 C1(int64 n, int64 r){
    int64 a,b,c;
    a = b = c = 0;
    for (int i=5;i<=n;i*=5)
        a+=(n/i);
    for (int i=5;i<=r;i*=5)
        b+=(r/i);
    for (int i=5;i<=n-r;i*=5)
        c+=((n-r)/i);
    return a - (b + c);
}
int64 M1(int64 p, int64 q){
    int64 a = 0;
    while (p % 5 == 0) {
        ++a;
        p/=5;
    }
    return a * q;
}
int64 C2(int64 n, int64 r){
    int64 a,b,c;
    a = b = c = 0;
    for (int i=2;i<=n;i*=2)
        a+=(n/i);
    for (int i=2;i<=r;i*=2)
        b+=(r/i);
    for (int i=2;i<=n-r;i*=2)
        c+=((n-r)/i);
    return a - (b + c);
}
int64 M2(int64 p, int64 q){
    int64 a = 0;
    while (p % 2 == 0) {
        ++a;
        p/=2;
    }
    return a * q;
}
void Read_Input(){
    int test,n,r,p,q;
    scanf("%d",&test);
    for (int t=1;t<=test;t++){
        scanf("%d %d %d %d",&n,&r,&p,&q);
        int64 nam = C1(n,r) + M1(p,q);
        int64 hai = C2(n,r) + M2(p,q);
        printf("Case %d: %lld\n",t,min(nam,hai));
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}
