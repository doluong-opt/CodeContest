/***********************************************
* Author - LUONG VAN DO                        *
* 1035 - Intelligent Factorial Factorization ->AC
* Algorithm math
* Time Limit 0.000s
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
const int Prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n;
void solve(){
    int ind = 0;
    int cnt = 0;
    while (ind  < 25 && Prime[ind] <= n ) {
        cnt = 0;
        for (int i=Prime[ind];i<=n;i*=Prime[ind])
            cnt+=(n / i);
        if (ind == 0) printf(" %d (%d)",Prime[ind],cnt);
        else printf(" * %d (%d)",Prime[ind],cnt);
        ind++;
    }
    printf("\n");
}
void Read(){
    int test;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d",&n);
        printf("Case %d: %d =",t,n);
        solve();
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
