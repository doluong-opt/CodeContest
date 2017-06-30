/***********************************************
* Author - LUONG VAN DO                        *
* 1282 - Leading and Trailing ->AC
* Algorithm math
* Time Limit 0.003s
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
#define MOD 1000
#define maxN 50001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int trailing, leading;
int64 power(int64 x, int y) {
    int64 res = 1;
    while ( y ) {
        if (y & 1) res = (res * x) % 1000;
        y>>=1;
        x = (x * x) % 1000;
    }
    return res;
}
void Read() {
    int test;
    int n,k;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d",&n,&k);
        leading = power(n, k) % 1000;
        trailing = (int)pow(10, 2 + fmod(k * log10(n), 1));
        printf("Case %d: %03d %03d\n",t,trailing,leading);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
