/***********************************************
* Author - LUONG VAN DO                        *
* 1163 - Bank Robbery ->AC
* Algorithm math
* Time Limit 0.009s
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
#define maxN 50001

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector <int64> res;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    uint64 value, x, y, B, tmp;
    
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lld",&value);
        res.clear();
        tmp = (value * 10) / 9;
        x = tmp - 1;
        y = tmp + 1;
        B = tmp / 10;
        if ( tmp - B  == value ) res.pb( tmp );
        B = x / 10;
        if ( x - B == value ) res.pb( x );
        B = y / 10;
        if ( y - B == value ) res.pb( y );
        sort(res.begin(), res.end());
        printf("Case %d:",t);
        REP(i, res.size())
            printf(" %lld",res[i]);
        printf("\n");
    }
    return 0;
}
