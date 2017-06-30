/***********************************************
* Author - LUONG VAN DO                        *
* 1166 - Old Sorting ->AC
* Algorithm Greedy
* Time Limit 0.001s
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

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int a[maxN];
bool gotInc(int n){
    FOR(i, 1, n)
        if (a[i]!=i) return false;
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, n, res, k, j;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        FOR(i, 1, n) scanf("%d",&a[i]);
        res = 0;
        while ( !gotInc( n ) ) {
            res++; k = 1;
            while (k < n && a[k]==k) ++k;
            j = k;
            ++k;
            while (k < n && a[k]!=j) ++k;
            swap(a[j], a[k]);
        }
        printf("Case %d: %d\n",t,res);
    }
    return 0;
}
